#ifndef TESTANALYSISBOXCONTAINERMEMENTO_H
#define TESTANALYSISBOXCONTAINERMEMENTO_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../src/memento/AnalysisBoxContainerMemento.h"

class TestAnalysisBoxContainerMemento : public QObject {
    Q_OBJECT

  private slots:
    void init();

    void testAddMemento();

  private:
    Memento::AnalysisBoxContainerMemento memento_;

};

#endif // TESTANALYSISBOXCONTAINERMEMENTO_H
