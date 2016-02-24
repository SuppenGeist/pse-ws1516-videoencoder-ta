#ifndef TESTFILTERLIST_H
#define TESTFILTERLIST_H


#include <QObject>
#include <QtTest/QtTest>

#include "../../src/model/FilterList.h"
class TestFilterList : public QObject {
	Q_OBJECT
  private slots:
	void init();
	void testGetFilter();
	void testConstructor();
	void testMoveFilter();
	void testInsertFilter();
	void testAppendFilter();
	void testGetSize();
	void testRemoveFilter();
  private:
	Model::FilterList* filterList_;
};

#endif // TESTFILTERLIST_H
