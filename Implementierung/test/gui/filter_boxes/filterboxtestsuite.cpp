#include "filterboxtestsuite.h"

#include <QtTest>

#include "testblurfilterbox.h"
#include "testborderfilterbox.h"
#include "testbrightnessfilterbox.h"
#include "testcolorbalancefilterbox.h"
#include "testcontrastfilterbox.h"
#include "testedgefilterbox.h"
#include "testgrayscalefilterbox.h"
#include "testgridfilterbox.h"
#include "testmirrorfilterbox.h"
#include "testnegativefilterbox.h"
#include "testnoisefilterbox.h"
#include "testposterfilterbox.h"
#include "testrectanglefilterbox.h"
#include "testrgbfilterbox.h"
#include "testrotationfilterbox.h"
#include "testsaturationfilterbox.h"
#include "testscalefilterbox.h"
#include "testsepiafilterbox.h"
#include "testsharpnessfilterbox.h"
#include "testvintagefilterbox.h"


FilterBoxTestSuite::FilterBoxTestSuite(int argc,char* argv[]):argc_(argc),argv_(argv)
{

}
void FilterBoxTestSuite::testAllFilterBoxes()
{
    //TestBlurFilterBox testBlurFilterBox();
    //QTest::qExec(&testBlurFilterBox,argc_,argv_);
}
