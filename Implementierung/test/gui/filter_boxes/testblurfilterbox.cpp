/*#include "testblurfilterbox.h"

#include "../../../src/gui/filter_boxes/BlurFilterBox.h"

void TestBlurFilterBox::init()
{
    filterbox_ = GUI::BlurFilterBox();

}

void TestBlurFilterBox::testChangeIntensity()
{
    QSlider * slider = filterbox_.findChild<QSlider *>("slider_");
    QVERIFY(slider != nullptr);

    QSignalSpy spy(slider, SIGNAL(valueChanged(int)));
    QCOMPARE(spy.isValid(), true);

    slider->setValue(10);

    QCOMPARE(spy.count(), 1);
    QCOMPARE(spy.takeFirst().at(0).toInt(), 10);

    QVERIFY( false == QObject::connect(slider, SIGNAL(valueChanged(int)), &filterbox_, SLOT(sliderChanged(int)), Qt::UniqueConnection).operator RestrictedBool()  );

    QSpinBox * spinBox = filterbox_.findChild<QSpinBox *>("spinBox_");
    QVERIFY(spinBox != nullptr);

    QSignalSpy spy2(spinBox, SIGNAL(valueChanged(int)));
    QCOMPARE(spy2.isValid(), true);

    spinBox->setValue(70);

    QCOMPARE(spy2.count(), 1);
    QCOMPARE(spy2.takeFirst().at(0).toInt(), 70);

    QVERIFY( false == QObject::connect(spinBox,SIGNAL(valueChanged(int)),&filterbox_,SLOT(spinBoxChanged(int)), Qt::UniqueConnection).operator RestrictedBool() );
}
*/
