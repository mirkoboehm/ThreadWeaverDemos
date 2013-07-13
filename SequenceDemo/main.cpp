#include <QApplication>

#include <threadweaver/ThreadWeaver.h>

#include "SequenceDemo.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SequenceDemo w;
    w.show();
    
    a.exec();
    ThreadWeaver::Weaver::instance()->finish();
}
