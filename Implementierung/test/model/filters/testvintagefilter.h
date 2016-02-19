#ifndef TESTVINTAGEFILTER_H
#define TESTVINTAGEFILTER_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../../src/model/filters/VintageFilter.h"

class TestVintageFilter : public QObject {
	Q_OBJECT

  private slots:
	void init();

	void testGetName();

	void testGetFilterDescription();

  private:
	Model::VintageFilter   filter_;
};

#endif // TESTVINTAGEFILTER_H
