﻿/* -*- C++ -*-

   This file declares the SMIV application class.

   $ Author: Mirko Boehm $
   $ Copyright: (C) 2005, Mirko Boehm $
   $ Contact: mirko@kde.org
         http://www.kde.org
         http://www.hackerbuero.org $
   $ License: LGPL with the following explicit clarification:
         This code may be linked against any version of the Qt toolkit
         from Trolltech, Norway. $

   $Id: SMIV.h 30 2005-08-16 16:16:04Z mirko $
*/

#ifndef SMIV_H
#define SMIV_H

#include <QDate>
#include <QList>
#include <QWidget>

#include <ThreadWeaver/ThreadWeaver>

#include "ui_SMIVBase.h"
#include "SMIVModel.h"
#include "SMIVItemDelegate.h"
#include "SMIVItem.h"

using namespace ThreadWeaver;

class SMIV : public QWidget
{
    Q_OBJECT
public:
    SMIV(Queue* queue);

private:
    SMIVModel model;
    SMIVItemDelegate del;
    Ui::SMIVBase ui;
    Queue* m_queue;
    int m_noOfJobs;
    bool m_quit;
    QTime m_startTime;
private Q_SLOTS:
    void on_pbSelectFiles_clicked();
    void on_pbCancel_clicked();
    void on_pbSuspend_clicked();
    void on_pbQuit_clicked();
    void slotJobDone(ThreadWeaver::JobPointer);
    void slotJobsDone();
    void weaverSuspended();
    void slotThumbReady(SMIVItem*);
};

#endif // SMIV_H
