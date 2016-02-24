#ifndef TESTPROJECT_H
#define TESTPROJECT_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../src/model/Project.h"

class TestProject : public QObject {
	Q_OBJECT
  private slots:
	void init();
	void testGetSetName();
	void testGetSetPath();
	void testGetSetMemento();
  private:
	Model::Project* project_;
};

#endif // TESTPROJECT_H
