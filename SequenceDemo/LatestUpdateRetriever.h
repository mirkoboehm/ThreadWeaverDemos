#ifndef LATESTUPDATERETRIEVER_H
#define LATESTUPDATERETRIEVER_H

#include <QByteArray>

#include <threadweaver/Job.h>

class LatestUpdateRetriever : public ThreadWeaver::Job
{
    Q_OBJECT
public:
    explicit LatestUpdateRetriever(QObject *parent = 0);
    
    const QByteArray& data() const;

protected:
    void run() Q_DECL_OVERRIDE;
    bool success() const Q_DECL_OVERRIDE;

private:
    QByteArray m_data;
    bool m_success;
};

#endif // LATESTUPDATERETRIEVER_H
