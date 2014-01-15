#include <QSharedPointer>
#include <QThread>

#include <threadweaver/ThreadWeaver.h>

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
    auto sequence(new Sequence());
    *sequence << make_job( []() { QThread::sleep(1); } )
              << make_job_raw(&m_retriever)
              << make_job_raw(&m_parser);
    enqueue(sequence);
}
