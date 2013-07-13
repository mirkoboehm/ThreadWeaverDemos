#include <QtDebug>
#include <QDomDocument>
#include "Parser.h"

Parser::Parser(QObject *parent) :
    Job(parent)
{
}

void Parser::setData(QByteArray data)
{
    m_data = data;
}

void Parser::run()
{
    if (m_data.isEmpty()) return;

    QDomDocument doc;
    if (!doc.setContent(m_data)) {
        m_data.clear(); //error condition
        return;
    }

    QDomNodeList tumblrs = doc.elementsByTagName("tumblelog");
    if (!tumblrs.isEmpty()) {
        QString titleText = tumblrs.at(0).toElement().text();
        emit title(titleText);
    }

    QDomNodeList captions = doc.elementsByTagName("photo-caption");
    if (!captions.isEmpty()) {
        QString captionText = captions.at(0).toElement().text();
        emit caption(captionText);
    }
}

bool Parser::success()
{
    return !m_data.isEmpty();
}
