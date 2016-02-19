#ifndef TESTMIRRORFILTER_H
#define TESTMIRRORFILTER_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../../src/model/filters/MirrorFilter.h"

class TestMirrorFilter : public QObject {
	Q_OBJECT

  private slots:
	void init();

	void testGetFilterDescription();

	void testRestore();

	void testFilterCopy();

  private:
	Model::MirrorFilter   filter_;
};

#endif // TESTMIRRORFILTER_H
