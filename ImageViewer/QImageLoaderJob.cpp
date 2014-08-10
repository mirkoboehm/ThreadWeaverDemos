/* -*- C++ -*-

   This file implements the QImageLoader class.

   $ Author: Mirko Boehm $
   $ Copyright: (C) 2005, Mirko Boehm $
   $ Contact: mirko@kde.org
         http://www.kde.org
         http://www.hackerbuero.org $
   $ License: LGPL with the following explicit clarification:
         This code may be linked against any version of the Qt toolkit
         from Trolltech, Norway. $

   $Id: QImageLoader.cpp 30 2005-08-16 16:16:04Z mirko $
*/

#include "QImageLoaderJob.h"

#include <ThreadWeaver/DebuggingAids>

namespace ThreadWeaver {

QImageLoader::QImageLoader (FileLoaderJob* file)
    : m_file (file)
{
}

QImageLoader::~QImageLoader()
{
}

QImage QImageLoader::image() const
{
    //P_ASSERT(isFinished());
    return m_image;
}

QString QImageLoader::description() const
{
    return m_description;
}

int QImageLoader::priority() const
{
    return 1;
}

void QImageLoader::run(ThreadWeaver::JobPointer, ThreadWeaver::Thread *)
{
    //P_ASSERT(m_file->isFinished());

    if (m_file->data() == 0) {
        TWDEBUG (0, "QImageLoader::run: data array is empty.\n" );
    } else {
        if (m_image.loadFromData ( (const uchar*) m_file->data(), m_file->size())) {
            m_description = QObject::tr("%1x%2 Pixels").arg(m_image.size().width()).arg(m_image.size().height());
        } else {
            m_description = QObject::tr("Error loading image data from %1.").arg(m_file->filename());
        }
        // free the memory held by the file loader, it is now redundant:
        m_file->freeMemory();
    }
}

void QImageLoader::resetImageData()
{
    m_image = QImage();
}

}
