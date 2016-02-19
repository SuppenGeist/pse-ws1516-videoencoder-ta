#ifndef UTILITYTESTSUITE_H
#define UTILITYTESTSUITE_H


class UtilityTestSuite {
  public:
	explicit UtilityTestSuite(int argc, char *argv[]);


	void testUtility();

  private:
	int argc_;
	char** argv_;
};

#endif // UTILITYTESTSUITE_H
