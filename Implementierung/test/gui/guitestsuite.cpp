#include "guitestsuite.h"

#include "filter_boxes/filterboxtestsuite.h"

GUITestSuite::GUITestSuite(int argc, char *argv[]):argc_(argc),argv_(argv) {

}

void GUITestSuite::testGUI() {
	FilterBoxTestSuite filterBoxTestSuite(argc_,argv_);
	filterBoxTestSuite.testAllFilterBoxes();
}
