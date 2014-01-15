#include <QtCore>
#include <threadweaver/ThreadWeaver>

int main(int argc, char** argv)
{
    ThreadWeaver::Lambda<void(*)()> job( []() { qDebug() << "Hello World!"; } );
    QCoreApplication app(argc, argv);
    ThreadWeaver::stream() << job;
}
