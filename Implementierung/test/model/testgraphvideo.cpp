#include "testgraphvideo.h"

#include "../../src/model/Graph.h"

void TestGraphVideo::init() {
    graphvideo_=Model::GraphVideo();
}

void TestGraphVideo::getGraph() {

    QVERIFY(nullptr == graphvideo_.getGraph(0));

    std::unique_ptr<Model::Graph> graph_(new Model::Graph);
    Model::Graph* graph1_=graph_.get();
    graphvideo_.appendGraph(std::move(graph_));

    QVERIFY(graph1_ == graphvideo_.getGraph(0));

    QVERIFY(nullptr == graphvideo_.getGraph(1));
}

void TestGraphVideo::getNumberOfGraphs() {

    QVERIFY(0 == graphvideo_.getNumberOfGraphs());

    std::unique_ptr<Model::Graph> graph_(new Model::Graph);
    graphvideo_.appendGraph(std::move(graph_));

    QVERIFY(1 == graphvideo_.getNumberOfGraphs());
}
