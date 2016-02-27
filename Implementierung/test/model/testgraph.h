#ifndef TESTGRAPH_H
#define TESTGRAPH_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../src/model/Graph.h"

class TestGraph : public QObject
{
    Q_OBJECT
private slots:
  void init();
  void testSetGetValue();
  void testGetSize();
  void testGetBiggestValue();
  void testRemoveValue();
private:
  Model::Graph*  graph_;

};

#endif // TESTGRAPH_H
