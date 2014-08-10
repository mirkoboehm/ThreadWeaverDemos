/* -*- C++ -*-

   This file declares the QImageLoader class. It loads the content of the
   raw data into a QImage.

   $ Author: Mirko Boehm $
   $ Copyright: (C) 2005, Mirko Boehm $
   $ Contact: mirko@kde.org
         http://www.kde.org
         http://www.hackerbuero.org $
   $ License: LGPL with the following explicit clarification:
         This code may be linked against any version of the Qt toolkit
         from Trolltech, Norway. $

   $Id: QImageLoader.h 30 2005-08-16 16:16:04Z mirko $
*/

#ifndef QImageLoader_H
#define QImageLoader_H

#include <QImage>

#include <ThreadWeaver/Job>
#include <ThreadWeaver/QObjectDecorator>

#include "FileLoaderJob.h"

namespace ThreadWeaver {

/** This class loads raw data into a QImage.
 * The data will be taken from a FileLoaderJob object.
 */
class QImageLoader : public Job
{
public:
    /** Create a job to load an image from the data loaded into file.
            If file has not been finished at this point, it is considered a
            dependency.
        */
    explicit QImageLoader (FileLoaderJob* file);
    ~QImageLoader ();
    /** Return the image. If it is not completely created, null will be
            returned. If an error occurred (for example, the data in file is a
            corrupted image), null will be returned, too. */
    QImage image() const;
    /** A description of the image. */
    QString description() const;
    /** reimpl */
    int priority() const;

    /** Clear the image data. */
    void resetImageData();
protected:
    void run(ThreadWeaver::JobPointer, ThreadWeaver::Thread*);

    QImage m_image;
    FileLoaderJob *m_file;
    QString m_description;
};

class QImageLoaderJob : public QObjectDecorator {
public:
    QImageLoaderJob(FileLoaderJob* file, QObject* parent = 0)
        : QObjectDecorator(&loader, false, parent)
        , loader(file)
    {}
    QImageLoader* job() { return &loader; }
private:
    QImageLoader loader;
};

}

#endif // QImageLoader_H

