#include "modeltestsuite.h"

#include "filters/filtertestsuite.h"

ModelTestSuite::ModelTestSuite(int argc, char* argv[]):argc_(argc),argv_(argv)
{

}

void ModelTestSuite::testModel()
{
    FilterTestSuite filterTestSuite(argc_,argv_);
    filterTestSuite.testAllFilters();
}

