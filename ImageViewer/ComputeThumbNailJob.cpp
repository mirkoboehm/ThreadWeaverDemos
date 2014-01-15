/* -*- C++ -*-

   This file implements the ComputeThumbNNailJob class.

   $ Author: Mirko Boehm $
   $ Copyright: (C) 2005, Mirko Boehm $
   $ Contact: mirko@kde.org
         http://www.kde.org
         http://www.hackerbuero.org $
   $ License: LGPL with the following explicit clarification:
         This code may be linked against any version of the Qt toolkit
         from Trolltech, Norway. $

   $Id: ComputeThumbNailJob.cpp 30 2005-08-16 16:16:04Z mirko $
*/

#include "ComputeThumbNailJob.h"

#include <threadweaver/DebuggingAids>

#include "SMIVItemDelegate.h"

namespace ThreadWeaver {

ComputeThumbnailJob::ComputeThumbnailJob(QImageLoaderJob *imageLoader, QObject* parent)
    : QObject(parent)
    , m_image(imageLoader)
{
}

QImage ComputeThumbnailJob::thumb()
{
//    P_ASSERT(/*isFinished() &&*/  !m_thumb.isNull());
    return m_thumb;
}

int ComputeThumbnailJob::priority() const
{
  return 1;
}

void ComputeThumbnailJob::run(ThreadWeaver::JobPointer, ThreadWeaver::Thread*)
{
    //P_ASSERT(m_image->isFinished());

    QImage im = m_image->job()->image();
    if (!im.isNull()) {
        m_thumb = im.scaled(SMIVItemDelegate::ThumbWidth, SMIVItemDelegate::ThumbHeight,
                            Qt::KeepAspectRatio, Qt::SmoothTransformation );
        m_image->job()->resetImageData();
    } else {
        debug(0, "ComputeThumbNailJob::run: m_image returns a nil image.\n");
    }
    emit thumbnailComplete();
}

}
