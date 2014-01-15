/* -*- C++ -*-

   This file implements the SMIV class.

   $ Author: Mirko Boehm $
   $ Copyright: (C) 2005, Mirko Boehm $
   $ Contact: mirko@kde.org
         http://www.kde.org
         http://www.hackerbuero.org $
   $ License: LGPL with the following explicit clarification:
         This code may be linked against any version of the Qt toolkit
         from Trolltech, Norway. $

   $Id: SMIV.cpp 30 2005-08-16 16:16:04Z mirko $
*/

#include "SMIV.h"
#include "SMIVItem.h"

#include <QtCore/QDebug>
#include <QFileDialog>
#include <QApplication>

//#include <threadweaver/State>
#include <ThreadWeaver.h>
#include <threadweaver/DebuggingAids>

using namespace ThreadWeaver;

SMIV::SMIV(Queue* q)
    : QWidget()
    , m_queue(q)
    , m_noOfJobs(0)
    , m_quit(false)
{
    ui.setupUi(this);
    connect(m_queue, SIGNAL (finished()), SLOT(slotJobsDone()));
    connect(m_queue, SIGNAL (jobDone(ThreadWeaver::JobPointer)), SLOT(slotJobDone(ThreadWeaver::JobPointer)));
    connect(m_queue, SIGNAL (suspended()), SLOT(weaverSuspended()));
    ui.listView->setModel(&model);
    ui.listView->setItemDelegate(&del);
}

void SMIV::on_pbSelectFiles_clicked()
{
    ui.pbSelectFiles->setEnabled(false);
    // listWidget->clear();

    QStringList files = QFileDialog::getOpenFileNames(this, "Select Images to display", QDir::homePath(),
                                                      "Images (*.png *.xpm *.jpg)");

    if (!files.isEmpty()) {
        m_noOfJobs = 3 * files.size(); // for progress display
        ui.progressBar->setEnabled (true);
        ui.progressBar->setRange (1, m_noOfJobs);
        ui.progressBar->reset();

        m_queue->suspend();
        for (int index = 0; index < files.size(); ++index) {
            SMIVItem *item = new SMIVItem(m_queue, files.at(index ), this);
            connect(item,  SIGNAL(thumbReady(SMIVItem*)), SLOT (slotThumbReady(SMIVItem*)));
        }
        m_startTime.start();
        m_queue->resume();

        ui.pbSelectFiles->setEnabled(false);
        ui.pbCancel->setEnabled(true);
        ui.pbSuspend->setEnabled(true);
        ui.pbSuspend->setText("Suspend");
    } else {
        QApplication::beep();
        on_pbCancel_clicked();
    }
}

void SMIV::on_pbCancel_clicked()
{
    m_queue->dequeue();
    m_queue->requestAbort();
    ui.pbSelectFiles->setEnabled(true);
    ui.pbCancel->setEnabled(false);
    ui.pbSuspend->setEnabled(false);

    ui.progressBar->reset();
    ui.progressBar->setEnabled(false);
}

void SMIV::on_pbSuspend_clicked()
{
    if (m_queue->state()->stateId() == Suspended) {
        ui.pbSuspend->setText("Suspend");
        m_queue->resume();
    } else {
        m_queue->suspend();
        ui.pbSuspend->setEnabled(false);
    }
}

void SMIV::on_pbQuit_clicked()
{
    // @TODO: suspend weaver and remove remaining jobs
    setEnabled(false);
    if ( m_queue->isIdle() || m_queue->state()->stateId() == Suspended ) {
        QApplication::instance()->quit();
    } else {
        m_quit = true;
        m_queue->dequeue(); // on Weaver::finished() we exit
        m_queue->resume();
    }
}

void SMIV::slotJobDone (JobPointer )
{
    ui.progressBar->setValue(ui.progressBar->value() + 1);
}

void SMIV::slotJobsDone ()
{
    if (!m_startTime.isNull() ) {
        qDebug() << "SMIV::slotJobsDone: elapsed time: " << m_startTime.elapsed() << " msecs";
    }

    if (m_quit) {
        QApplication::instance()->quit();
    } else {
        ui.pbSelectFiles->setEnabled(true);
        ui.pbCancel->setEnabled(false);
        ui.pbSuspend->setEnabled(false);

        ui.progressBar->reset();
        ui.progressBar->setEnabled(false);
    }
}

void SMIV::weaverSuspended()
{
    ui.pbSuspend->setText("Resume");
    ui.pbSuspend->setEnabled(true);
}


void SMIV::slotThumbReady(SMIVItem *item)
{
    model.insert(item);
    ui.listView->scrollTo(model.index(model.rowCount()-1,  0), QAbstractItemView::PositionAtBottom);
}

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    ThreadWeaver::setDebugLevel(true, 1);
    ThreadWeaver::Queue queue;
    queue.setMaximumNumberOfThreads(4);
    SMIV smiv(&queue);
    smiv.show();
    return app.exec();
}
