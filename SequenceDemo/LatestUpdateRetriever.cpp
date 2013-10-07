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

const QByteArray& LatestUpdateRetriever::data() const
{
    return m_data;
}

void LatestUpdateRetriever::run()
{
    QNetworkAccessManager manager;
    QEventLoop loop;
    connect(&manager, SIGNAL(finished(QNetworkReply*)), &loop, SLOT(quit()));
    auto reply = manager.get(QNetworkRequest(QUrl("http://fickedinger.tumblr.com/api/read?start=0&num=1")));
    loop.exec();
    if (reply->error() == QNetworkReply::NoError) {
        m_success = true;
        m_data = reply->readAll();
    } else {
        m_success = false;
    }
}

bool LatestUpdateRetriever::success() const
{
    return m_success;
}
