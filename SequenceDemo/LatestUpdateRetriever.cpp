#include <QtDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QEventLoop>
#include <QUrl>
#include "LatestUpdateRetriever.h"

LatestUpdateRetriever::LatestUpdateRetriever(QObject *parent)
    : Job(parent)
    , m_success(false)
{
}

void LatestUpdateRetriever::run()
{
    QNetworkAccessManager manager;
    QEventLoop loop;
    connect(&manager, SIGNAL(finished(QNetworkReply*)), &loop, SLOT(quit()));
    // http://fickedinger.tumblr.com/api/read?start=0&num=1
    // http://api.tumblr.com/v2/blog/fickedinger.tumblr.com/avatar
    QNetworkReply* reply = manager.get(QNetworkRequest(QUrl("http://fickedinger.tumblr.com/api/read?start=0&num=1")));
    loop.exec();
    if (reply->error() == QNetworkReply::NoError) {
        m_success = true;
        QByteArray data = reply->readAll();
        emit dataRetrieved(data);
    } else {
        m_success = false;
    }
}

bool LatestUpdateRetriever::success() const
{
    return m_success;
}
