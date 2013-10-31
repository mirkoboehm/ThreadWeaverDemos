#include <QtCore>
#include <threadweaver/ThreadWeaver.h>

int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);
    ThreadWeaver::Lambda<void(*)()> l( []() { qDebug() << "Hello World!"; } );
    ThreadWeaver::Queueing::enqueue_raw(&l);
}
