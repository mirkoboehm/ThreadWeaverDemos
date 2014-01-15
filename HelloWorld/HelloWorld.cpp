﻿#include <QtCore>
#include <threadweaver/ThreadWeaver>

using namespace ThreadWeaver;

int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);
    stream() << make_job( []() { qDebug() << "Hello World!"; } );
}
