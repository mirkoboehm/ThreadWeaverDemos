#include <QSharedPointer>

#include <threadweaver/ThreadWeaver.h>
#include <threadweaver/JobSequence.h>
#include <JobPointer.h>

#include "SequenceDemo.h"
#include "ui_SequenceDemo.h"


SequenceDemo::SequenceDemo(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SequenceDemo)
{
    using namespace ThreadWeaver;
    ui->setupUi(this);
    connect(&m_retriever, SIGNAL(dataRetrieved(QByteArray)), &m_parser, SLOT(setData(QByteArray)));
    connect(&m_parser, SIGNAL(title(QString)), ui->title, SLOT(setText(QString)));
    connect(&m_parser, SIGNAL(caption(QString)), ui->caption, SLOT(setText(QString)));
    QSharedPointer<JobSequence> sequence(new JobSequence());
    sequence->addRawJob(&m_retriever);
    sequence->addRawJob(&m_parser);

    Weaver::instance()->enqueue(sequence);
}

SequenceDemo::~SequenceDemo()
{
    delete ui;
}
