#ifndef PARSER_H
#define PARSER_H

#include <QByteArray>

#include <threadweaver/Job.h>

class Parser : public ThreadWeaver::Job
{
    Q_OBJECT
public:
    explicit Parser(QObject *parent = 0);
    
public Q_SLOTS:
    void setData(QByteArray);

Q_SIGNALS:
    void title(QString);
    void caption(QString);

protected:
    void run() Q_DECL_OVERRIDE;
    bool success() const Q_DECL_OVERRIDE;

private:
    QByteArray m_data;
};

#endif // PARSER_H
