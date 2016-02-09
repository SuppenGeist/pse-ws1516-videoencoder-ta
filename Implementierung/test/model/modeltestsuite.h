#ifndef MODELTESTSUITE_H
#define MODELTESTSUITE_H

class ModelTestSuite
{
public:
    explicit ModelTestSuite(int argc, char *argv[]);

    void testModel();

private:
    int argc_;
    char** argv_;
};

#endif // MODELTESTSUITE_H
