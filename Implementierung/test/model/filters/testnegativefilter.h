#ifndef TESTNEGATIVEFILTER_H
#define TESTNEGATIVEFILTER_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../../src/model/filters/NegativeFilter.h"

class TestNegativeFilter : public QObject {
	Q_OBJECT

  private slots:
	void init();

	void testGetName();

	void testGetFilterDescription();

	void testGetSaveString();

  private:
	Model::NegativeFilter   filter_;
};

#endif // TESTNEGATIVEFILTER_H
