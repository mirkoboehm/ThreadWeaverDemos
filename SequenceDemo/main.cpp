#include <QApplication>

#include <threadweaver/ThreadWeaver.h>
//#include <threadweaver/DebuggingAids.h>

#include "SequenceDemo.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //ThreadWeaver::setDebugLevel(true, 3);
    SequenceDemo w;
    w.show();
    a.exec();
    ThreadWeaver::Weaver::instance()->finish();
}
