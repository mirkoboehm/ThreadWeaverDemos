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

    auto textOfFirst = [&doc](const char* name) {
        auto elements = doc.elementsByTagName(name);
        if (elements.isEmpty()) return QString();
        return elements.at(0).toElement().text();
    };

    emit title(textOfFirst("tumblelog"));
    emit caption(textOfFirst("photo-caption"));
}

bool Parser::success() const
{
    return !m_data.isEmpty();
}
