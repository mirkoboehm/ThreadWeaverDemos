﻿#include <QtDebug>
#include <QCoreApplication>

#include <threadweaver/ThreadWeaver.h>
#include <threadweaver/Lambda.h>

using namespace ThreadWeaver;

int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);
    Weaver::instance()->enqueue(JobPointer(new Lambda( []() { qDebug() << "Hello World!"; } )));
    Weaver::instance()->finish();
}