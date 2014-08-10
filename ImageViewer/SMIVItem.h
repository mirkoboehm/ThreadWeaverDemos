/* -*- C++ -*-

   This file declares the SMIVItem class.

   $ Author: Mirko Boehm $
   $ Copyright: (C) 2005, Mirko Boehm $
   $ Contact: mirko@kde.org
         http://www.kde.org
         http://www.hackerbuero.org $
   $ License: LGPL with the following explicit clarification:
         This code may be linked against any version of the Qt toolkit
         from Trolltech, Norway. $

   $Id: SMIVItem.h 30 2005-08-16 16:16:04Z mirko $
*/

#ifndef SMIVItem_H
#define SMIVItem_H

#include <QObject>

#include <QImage>

#include <ThreadWeaver/ThreadWeaver>
#include <ThreadWeaver/Sequence>
#include <ThreadWeaver/QObjectDecorator>

#include "FileLoaderJob.h"
#include "QImageLoaderJob.h"
#include "ComputeThumbNailJob.h"

using namespace ThreadWeaver;

class SMIVItem : public QObject
{
    Q_OBJECT
public:
    explicit SMIVItem(Queue *weaver = 0, const QString& path  = QString(), QObject *parent = 0);
    QString name() const;
    QString desc1() const;
    QString desc2() const;
    QImage thumb() const;

Q_SIGNALS:
    void thumbReady(SMIVItem*);

private Q_SLOTS:
    void imageLoaderReady(ThreadWeaver::JobPointer);
    void computeThumbReady();

protected:
    QString m_path;
    QString m_name;
    QString m_desc1;
    QString m_desc2;
    Queue *m_queue;
    Sequence *m_sequence;
    QJobPointer m_fileloader;
    QImageLoaderJob* m_imageloader;
    ComputeThumbnailJob* m_thumb;
};

#endif // SMIVItem_H
