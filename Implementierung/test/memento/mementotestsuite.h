#ifndef MEMENTOTESTSUITE_H
#define MEMENTOTESTSUITE_H


class MementoTestSuite {
  public:
	explicit MementoTestSuite(int argc, char *argv[]);


	void testMemento();

  private:
	int argc_;
	char** argv_;
};

#endif // MEMENTOTESTSUITE_H
