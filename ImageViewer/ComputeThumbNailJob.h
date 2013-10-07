/* -*- C++ -*-

   This file declares the ComputeThumbNailJob class. It scales images.

   $ Author: Mirko Boehm $
   $ Copyright: (C) 2005, Mirko Boehm $
   $ Contact: mirko@kde.org
         http://www.kde.org
         http://www.hackerbuero.org $
   $ License: LGPL with the following explicit clarification:
         This code may be linked against any version of the Qt toolkit
         from Trolltech, Norway. $

   $Id: ComputeThumbNailJob.h 30 2005-08-16 16:16:04Z mirko $
*/

#ifndef COMPUTETHUMBNAILJOB_H
#define COMPUTETHUMBNAILJOB_H

#include <QImage>

#include "Job.h"

#include "QImageLoaderJob.h"

namespace ThreadWeaver {

class ComputeThumbnailJob : public QObject, public Job
{
    Q_OBJECT
public:
    explicit ComputeThumbnailJob(QImageLoaderJob *imageLoader, QObject* parent = 0);
    /** Returns the rendered thumbnail. */
    QImage thumb();

    int priority() const Q_DECL_OVERRIDE;
protected:
    void run(ThreadWeaver::JobPointer, ThreadWeaver::Thread*) Q_DECL_OVERRIDE;

Q_SIGNALS:
    void thumbnailComplete();

private:
    QImage m_thumb;
    QImageLoaderJob *m_image;
};

}

#endif // COMPUTETHUMBNAILJOB_H
