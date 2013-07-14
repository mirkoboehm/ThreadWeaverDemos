#include <QDomDocument>
#include "Parser.h"

Parser::Parser(LatestUpdateRetriever *retriever, QObject *parent)
    : Job(parent)
    , m_retriever(retriever)
{
}

void Parser::run()
{
    if (m_retriever->data().isEmpty()) return;

    QDomDocument doc;
    if (!doc.setContent(m_retriever->data())) {
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
