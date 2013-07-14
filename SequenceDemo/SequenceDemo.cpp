#include <QSharedPointer>
#include <QThread>

#include <threadweaver/ThreadWeaver.h>
#include <threadweaver/JobSequence.h>
#include <threadweaver/Lambda.h>
#include <JobPointer.h>

#include "SequenceDemo.h"

using namespace ThreadWeaver;

SequenceDemo::SequenceDemo(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SequenceDemo)
    , m_parser(&m_retriever)
{
    ui->setupUi(this);
    //communicate results:
    connect(&m_parser, SIGNAL(title(QString)), ui->title, SLOT(setText(QString)));
    connect(&m_parser, SIGNAL(caption(QString)), ui->caption, SLOT(setText(QString)));
    //set up sequence, add a little delay at the beginning:
    QSharedPointer<JobSequence> sequence(new JobSequence());
    sequence->addJob(JobPointer(new Lambda( []() { QThread::sleep(1); } )));
    sequence->addRawJob(&m_retriever);
    sequence->addRawJob(&m_parser);
    //go:
    Weaver::instance()->enqueue(sequence);
}
