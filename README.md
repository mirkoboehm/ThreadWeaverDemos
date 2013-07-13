ThreadWeaver examples
=====================

HelloWorld shows the most simple ThreadWeaver application. There are two versions, one that queues a raw pointer to a job that is held as a stack variable, and one that queues a JobPointer, which is a shared pointer.

SequenceDemo shows how sequences can be used to model program flows. It will retrieve the latest post and blog title from fickedinger.tumblr.org. On success, it will display data in the main window. If no network is available, the retriever job will fail, and the parser job will be dequeued (the abort-on-failure feature built into sequences).

ImageViewer contains a complete image viewer program that generates sequences to load, read and scale image files into thumbnails. It uses resource restrictions to limit the number of concurrent accesses to the file system.
