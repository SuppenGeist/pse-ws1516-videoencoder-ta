#ifndef TESTGRAPHVIDEO_H
#define TESTGRAPHVIDEO_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../src/model/graphvideo.h"
#include "../../src/model/Graph.h"

class TestGraphVideo : public QObject {
	Q_OBJECT
  private slots:
	void init();
	void getGraph();
	void getNumberOfGraphs();
  private:
	Model::GraphVideo   graphvideo_;
};

#endif // TESTGRAPHVIDEO_H
