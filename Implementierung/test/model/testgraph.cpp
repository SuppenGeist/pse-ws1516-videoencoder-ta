#include "testgraph.h"


void TestGraph::init() {

	graph_= new Model::Graph();
	graph_->setValue(0,0.5);
	graph_->setValue(1,0.5);
	graph_->setValue(2,2.5);
	graph_->setValue(3,0.15);
	graph_->setValue(4,0.25);
}

void TestGraph::testSetGetValue() {
	QVERIFY( graph_->getValue(2)==2.5);
	graph_->setValue(5,1.5);
	QVERIFY( graph_->getValue(5)==1.5);
}

void TestGraph::testGetSize() {
	QVERIFY( graph_->getSize()==5);
	graph_->setValue(5,1.5);
	QVERIFY( graph_->getSize()==6);
}

void TestGraph::testGetBiggestValue() {
	graph_->setValue(5,1.5);
	QVERIFY( graph_->getBiggestValue()==2.5);
}

void TestGraph::testRemoveValue() {
	graph_->setValue(5,1.5);
	graph_->removeValue(5);
	QVERIFY( graph_->getSize()!=6);
	QVERIFY( graph_->getSize()==5);
}
