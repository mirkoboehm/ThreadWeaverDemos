﻿/* -*- C++ -*-

   This file implements the SMIVItem class.

   $ Author: Mirko Boehm $
   $ Copyright: (C) 2005, Mirko Boehm $
   $ Contact: mirko@kde.org
         http://www.kde.org
         http://www.hackerbuero.org $
   $ License: LGPL with the following explicit clarification:
         This code may be linked against any version of the Qt toolkit
         from Trolltech, Norway. $

   $Id: SMIVItem.cpp 30 2005-08-16 16:16:04Z mirko $
*/

#include "SMIVItem.h"

#include <QtDebug>
#include <QtCore/QStringList>
#include <QImage>
#include <QtCore/QTimer>
#include <QtCore/QFileInfo>

#include <threadweaver/JobPointer.h>
#include <threadweaver/QObjectDecorator.h>
#include <DebuggingAids.h>
#include <ResourceRestrictionPolicy.h>

#include "SMIVItemDelegate.h"
#include "FileLoaderJob.h"
#include "QImageLoaderJob.h"

static QueuePolicy* resourceRestriction()
{
    static ResourceRestrictionPolicy policy(4);
    return &policy;
}

SMIVItem::SMIVItem(Weaver *weaver, const QString& path,  QObject *parent)
    : QObject(parent)
    , m_path(path)
    , m_weaver(weaver)
{
    using namespace ThreadWeaver;

    QFileInfo fi(path);
    if (fi.isFile() && fi.isReadable()) {
        m_sequence = new JobSequence();

        m_name = fi.baseName();
        m_desc2 = fi.absoluteFilePath();

        auto fileloader = new FileLoaderJob(fi.absoluteFilePath());
        m_fileloader = QJobPointer(new QObjectDecorator(fileloader));
        m_fileloader->setObjectName(tr("load file: ") + fi.baseName());
        m_fileloader->assignQueuePolicy(resourceRestriction());
        m_sequence->addJob(m_fileloader);


        m_imageloader = new QImageLoaderJob(fileloader, this);
        connect(m_imageloader, SIGNAL (done(ThreadWeaver::JobPointer)),
                SLOT (imageLoaderReady(ThreadWeaver::JobPointer)));
        m_imageloader->setObjectName(tr("load image: ") + fi.baseName());
        m_sequence->addRawJob(m_imageloader);


        m_thumb = new ComputeThumbnailJob(m_imageloader);
        connect(m_thumb, SIGNAL(thumbnailComplete()), SLOT(computeThumbReady()));
        m_thumb->setObjectName(tr("scale image: ") + fi.baseName());
        m_sequence->addRawJob(m_thumb);
        ThreadWeaver::Queueing::enqueue_raw(weaver, m_sequence);
    } else {
        // in this wee little program, we just ignore if we cannot access the file
    }
}

QString SMIVItem::name() const
{
    return m_name;
}

QString SMIVItem::desc1() const
{
    return m_desc1;
}

QString SMIVItem::desc2() const
{
    return m_desc2;
}

void SMIVItem::imageLoaderReady(JobPointer)
{
    debug(3, "SMIVItem::imageLoaderReady: %s processed.\n", qPrintable(m_name));
    m_desc1 = m_imageloader->job()->description();
}

void SMIVItem::computeThumbReady()
{
    debug(3, "SMIVItem::computeThumbReady: %s scaled.\n", qPrintable(m_name));
    emit thumbReady(this);
}

QImage SMIVItem::thumb() const
{
    return m_thumb->thumb();
}
