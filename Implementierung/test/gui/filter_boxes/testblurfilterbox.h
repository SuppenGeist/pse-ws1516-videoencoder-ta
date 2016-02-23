#ifndef TESTBLURFILTERBOX_H
#define TESTBLURFILTERBOX_H

#include <QObject>
#include <QtTest/QtTest>

#include "../../../src/gui/filter_boxes/BlurFilterBox.h"

class TestBlurFilterBox : public QObject {
	Q_OBJECT

  private slots:
	void init();

	void testChangeIntensity();

  private:
	std::unique_ptr<GUI::BlurFilterBox>   filterbox1_;
    GUI::BlurFilterBox* filterbox_;

};

#endif

