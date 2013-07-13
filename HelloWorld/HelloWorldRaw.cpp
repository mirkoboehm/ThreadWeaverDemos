#include <QtDebug>
#include <QCoreApplication>

#include <threadweaver/ThreadWeaver.h>
#include <threadweaver/Lambda.h>

using namespace ThreadWeaver;

int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);
    Lambda l( []() { qDebug() << "Hello World!"; } );
    Weaver::instance()->enqueueRaw(&l);
    Weaver::instance()->finish();
}

