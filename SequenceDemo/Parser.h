#ifndef PARSER_H
#define PARSER_H

#include <QByteArray>

#include <threadweaver/Job.h>
#include <LatestUpdateRetriever.h>

class Parser : public ThreadWeaver::Job
{
    Q_OBJECT
public:
    explicit Parser(LatestUpdateRetriever* retriever, QObject *parent = 0);
    
Q_SIGNALS:
    void title(QString);
    void caption(QString);

protected:
    void run() Q_DECL_OVERRIDE;

private:
    QByteArray m_data;
    LatestUpdateRetriever* m_retriever;
};

#endif // PARSER_H
