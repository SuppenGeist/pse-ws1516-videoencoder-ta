#ifndef TESTANALYSISTABMEMENTO_H
#define TESTANALYSISTABMEMENTO_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../src/memento/AnalysisTabMemento.h"

class TestAnalysisTabMemento : public QObject {
    Q_OBJECT

  private slots:
    void init();

    void testSetRawVideo();

    void testSetAnalysisBoxContainerMemento();

    void testSetAnalysisGraph();

    void testSetAnalysisVideo();

    void testSetPlayerPosition();


  private:
    Memento::AnalysisTabMemento memento_;

};

#endif // TESTANALYSISTABMEMENTO_H
