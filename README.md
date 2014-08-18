# ThreadWeaver examples

## This repository has served it's purpose and is being merged into ThreadWeaver

While the CMake based build system of KDE Frameworks 5 was in development, there was no good way to add examples that are written
against an installed framework (as opposed to being part of the build of the framework itself). This problem has been solved, and
examples can now be added to KDE frameworks repositories and still be written in the same way a programmer using the framework would
use it. Because of that, the examples in this repository are being merged into the
[ThreadWeaver repository](https://projects.kde.org/projects/frameworks/threadweaver/repository).

## Examples
HelloWorld shows the most simple ThreadWeaver application. There are two versions, one that queues a raw pointer to a job that is
held as a stack variable, and one that queues a JobPointer, which is a shared pointer. The second HelloWorld example (HelloWorldRaw)
illustrates the use of member variables as jobs.

SequenceDemo shows how sequences can be used to model program flows. It will retrieve the latest post and blog title from
fickedinger.tumblr.org. On success, it will display data in the main window. If no network is available, the retriever job will
fail, and the parser job will be dequeued (the abort-on-failure feature built into sequences).

ImageViewer contains a complete image viewer program that generates sequences to load, read and scale image files into thumbnails.
It uses resource restrictions to limit the number of concurrent accesses to the file system.
