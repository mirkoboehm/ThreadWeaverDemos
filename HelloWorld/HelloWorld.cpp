#include <QtCore>
#include <threadweaver/ThreadWeaver.h>

int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);
    ThreadWeaver::Queueing::enqueue( []() { qDebug() << "Hello World!"; } );
}
