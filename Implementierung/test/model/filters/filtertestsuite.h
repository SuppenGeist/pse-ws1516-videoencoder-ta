#ifndef FILTERTESTSUITE_H
#define FILTERTESTSUITE_H

class FilterTestSuite
{
public:
    explicit FilterTestSuite(int argc, char *argv[]);

    void testAllFilters();

private:
    int argc_;
    char** argv_;
};

#endif // FILTERTESTSUITE_H
