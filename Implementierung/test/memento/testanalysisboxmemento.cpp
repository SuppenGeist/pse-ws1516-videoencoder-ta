#include "testanalysisboxmemento.h"
#include <QString>

void TestAnalysisBoxMemento::init() {

	memento_ = Memento::AnalysisBoxMemento();

}

void TestAnalysisBoxMemento::testSetComment() {
	QString string = "test";
	memento_.setComment(string);
	QVERIFY(memento_.getComment() == string);

}

void TestAnalysisBoxMemento::testSetMacroBlockVideo()
{
    Model::Video video;
    memento_.setMacroBlockVideo(&video);
    QVERIFY(memento_.getMacroBlockVideo() == &video);
}

void TestAnalysisBoxMemento::testSetRGBDiffVideo()
{
    Model::Video video;
    memento_.setRgbDiffVideo(&video);
    QVERIFY(memento_.getRgbDiffVideo() == &video);
}

void TestAnalysisBoxMemento::testSetPsnrGraph()
{
    Model::Graph graph;
    memento_.setPsnrGraph(&graph);
    QVERIFY(memento_.getPsnrGraph() == &graph);
}

void TestAnalysisBoxMemento::testSetBitrateGraph()
{
    Model::Graph graph;
    memento_.setBitrateGraph(&graph);
    QVERIFY(memento_.getBitrateGraph() == &graph);
}

void TestAnalysisBoxMemento::testSetEncoder()
{
    QString string("test");
    memento_.setEncoder(string);
    QVERIFY(memento_.getEncoder() == string);

}

void TestAnalysisBoxMemento::testSetAverageBitrate()
{
    QString string("test");
    memento_.setAverageBitrate(string);
    QVERIFY(memento_.getAverageBitrate() == string);

}

void TestAnalysisBoxMemento::testSetFilename()
{
    QString string("test");
    memento_.setFilename(string);
    QVERIFY(memento_.getFilename() == string);

}

void TestAnalysisBoxMemento::testSetFilesize()
{
    QString string("test");
    memento_.setFilesize(string);
    QVERIFY(memento_.getFilesize() == string);

}

void TestAnalysisBoxMemento::testSetRedHistogram()
{
    Model::GraphVideo video;
    memento_.setRedHistogram(&video);
    QVERIFY(memento_.getRedHistogram() == &video);

}

void TestAnalysisBoxMemento::testSetGreenHistogram()
{
    Model::GraphVideo video;
    memento_.setGreenHistogram(&video);
    QVERIFY(memento_.getGreenHistogram() == &video);

}

void TestAnalysisBoxMemento::testSetBlueHistogram()
{
    Model::GraphVideo video;
    memento_.setBlueHistogram(&video);
    QVERIFY(memento_.getBlueHistogram() == &video);

}

void TestAnalysisBoxMemento::testSetPath() {
    QString string("test");
	memento_.setPath(string);
	QVERIFY(memento_.getPath() == string);

}
