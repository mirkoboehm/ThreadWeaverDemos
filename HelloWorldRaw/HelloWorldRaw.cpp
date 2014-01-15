#include <QtCore>
#include <threadweaver/ThreadWeaver>

int main(int argc, char** argv)
{
    using namespace ThreadWeaver;

    QCoreApplication app(argc, argv);
    // Allocate a Job as a local variable:
    Lambda<void(*)()> job( []() { qDebug() << "Hello World!"; } );
    // Queue the Job using the default Queue stream:
    stream() << job;
    // Wait for finish(), because job is destroyed before the global queue:
    Queue::instance()->finish();
}
