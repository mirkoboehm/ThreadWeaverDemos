#ifndef LATESTUPDATERETRIEVER_H
#define LATESTUPDATERETRIEVER_H

#include <QObject>
#include <QByteArray>

#include <ThreadWeaver/Job>

class LatestUpdateRetriever : public ThreadWeaver::Job
{
public:
    explicit LatestUpdateRetriever();
    
    const QByteArray& data() const;

protected:
    void run(ThreadWeaver::JobPointer, ThreadWeaver::Thread*) Q_DECL_OVERRIDE;
    bool success() const Q_DECL_OVERRIDE;

private:
    QByteArray m_data;
    bool m_success;
};

#endif // LATESTUPDATERETRIEVER_H
