#include "testgraphvideo.h"


void TestGraphVideo::init() {
	graphvideo_=Model::GraphVideo();
}

void TestGraphVideo::testGetGraph() {

	QVERIFY(nullptr == graphvideo_.getGraph(0));

	std::unique_ptr<Model::Graph> graph_(new Model::Graph);
	Model::Graph* graph1_=graph_.get();
	graphvideo_.appendGraph(std::move(graph_));

	QVERIFY(graph1_ == graphvideo_.getGraph(0));

	QVERIFY(nullptr == graphvideo_.getGraph(1));
}

void TestGraphVideo::testGetNumberOfGraphs() {

	QVERIFY(0 == graphvideo_.getNumberOfGraphs());

	std::unique_ptr<Model::Graph> graph_(new Model::Graph);
	graphvideo_.appendGraph(std::move(graph_));

	QVERIFY(1 == graphvideo_.getNumberOfGraphs());
}

void TestGraphVideo::testIsComplete() {

    graphvideo_.setIsComplete(true);
    QVERIFY(true == graphvideo_.isComplete());

    graphvideo_.setIsComplete(false);
    QVERIFY(false == graphvideo_.isComplete());
}

void TestGraphVideo::testFPS() {
    const int testValue1=0;
    graphvideo_.setFps(testValue1);
    QVERIFY(testValue1 == graphvideo_.getFps());

    const int testValue2=100;
    graphvideo_.setFps(testValue2);
    QVERIFY(testValue2 == graphvideo_.getFps());

    const int testValue3=-10;
    graphvideo_.setFps(testValue3);
    QVERIFY(testValue3 != graphvideo_.getFps());
}
