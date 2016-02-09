#include "maintestsuite.h"

#include "model/modeltestsuite.h"

MainTestSuit::MainTestSuit(int argc,char* argv[]):argc_(argc),argv_(argv)
{

}

void MainTestSuit::runAllTests()
{
    ModelTestSuite modelTestSuite(argc_,argv_);
    modelTestSuite.testModel();
}

