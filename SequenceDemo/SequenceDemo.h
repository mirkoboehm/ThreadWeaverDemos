#ifndef SEQUENCEDEMO_H
#define SEQUENCEDEMO_H

#include <QDialog>
#include <LatestUpdateRetriever.h>
#include <Parser.h>

#include "ui_SequenceDemo.h"

class SequenceDemo : public QDialog
{
    Q_OBJECT
    
public:
    explicit SequenceDemo(QWidget *parent = 0);
    
private:
    QScopedPointer<Ui::SequenceDemo> ui;
    LatestUpdateRetriever m_retriever;
    Parser m_parser;
};

#endif // SEQUENCEDEMO_H
