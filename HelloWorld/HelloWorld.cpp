﻿﻿//@@snippet(sample-helloworld)
﻿#include <QtCore>
#include <ThreadWeaver/ThreadWeaver>

int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);

    using namespace ThreadWeaver;
    stream() << make_job( []() { qDebug() << "Hello World!"; } );
}
//@@end(sample-helloworld)
