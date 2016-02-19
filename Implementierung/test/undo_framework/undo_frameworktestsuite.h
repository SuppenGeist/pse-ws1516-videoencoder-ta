#ifndef UNDO_FRAMEWORKTESTSUITE_H
#define UNDO_FRAMEWORKTESTSUITE_H


class Undo_FrameworkTestSuite {
  public:
	explicit Undo_FrameworkTestSuite(int argc, char *argv[]);


	void testUndo();

  private:
	int argc_;
	char** argv_;
};

#endif // UNDO_FRAMEWORKTESTSUITE_H
