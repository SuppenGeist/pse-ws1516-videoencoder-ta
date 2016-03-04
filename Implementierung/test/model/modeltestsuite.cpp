#include "modeltestsuite.h"

#include <QtTest/QtTest>

#include "filters/filtertestsuite.h"
#include "testavvideo.h"
#include "testvideo.h"
#include "testgraphvideo.h"
#include "testproject.h"
#include "testfilterlist.h"
#include "testencodedvideo.h"
#include "testyuvvideo.h"
#include "testgraph.h"

ModelTestSuite::ModelTestSuite(int argc, char* argv[]):argc_(argc),argv_(argv) {

}

void ModelTestSuite::testModel() {
	FilterTestSuite filterTestSuite(argc_,argv_);
	filterTestSuite.testAllFilters();

	TestAVVideo testAVVideo;
	QTest::qExec(&testAVVideo);

	TestVideo testVideo;
	QTest::qExec(&testVideo);

	TestGraphVideo testGraphVideo;
	QTest::qExec(&testGraphVideo);

	TestProject testProject;
	QTest::qExec(&testProject);

	TestFilterList testFilterList;
	QTest::qExec(&testFilterList);

    //TestEncodedVideo testEncodedVideo;
    //QTest::qExec(&testEncodedVideo);

    //TestYuvVideo testYuvVideo;
    //QTest::qExec(&testYuvVideo);

    TestGraph testGraph;
    QTest::qExec(&testGraph);
}

