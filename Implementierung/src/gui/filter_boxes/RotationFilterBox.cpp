#include "RotationFilterBox.h"

#include <QWidget>
#include <QSlider>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QFrame>
#include <QDebug>

#include "FilterConfigurationBox.h"
#include "../../model/filters/RotationFilter.h"

GUI::RotationFilterBox::RotationFilterBox(QWidget* parent):FilterConfigurationBox(parent) {
	tempFilter_=std::make_unique<Model::RotationFilter>();

	createFilterOptions();

	connect(slider_,SIGNAL(valueChanged(int)),this,SLOT(sliderChanged(int)));
	connect(spinBox_,SIGNAL(valueChanged(int)),this,SLOT(spinBoxChanged(int)));
}

void GUI::RotationFilterBox::updateUi() {
	updateTempFilter();
	auto value=static_cast<Model::RotationFilter*>(tempFilter_.get())->getAngle();
	slider_->setValue(value);
	spinBox_->setValue(value);

	updatePreview();
}

void GUI::RotationFilterBox::sliderChanged(int value) {
	static_cast<Model::RotationFilter*>(tempFilter_.get())->setAngle(value);
	spinBox_->setValue(value);
}

void GUI::RotationFilterBox::spinBoxChanged(int value) {
	static_cast<Model::RotationFilter*>(tempFilter_.get())->setAngle(value);
	slider_->setValue(value);

	updatePreview();
}

void GUI::RotationFilterBox::createFilterOptions() {
	QLabel* l=new QLabel("Angle:");

	slider_=new QSlider(Qt::Horizontal);
	slider_->setMaximum(360);
	slider_->setMinimum(0);

	spinBox_=new QSpinBox;
	spinBox_->setMaximum(360);
	spinBox_->setMinimum(0);


	QHBoxLayout* h_content=new QHBoxLayout;

	h_content->addWidget(l);
	h_content->addWidget(slider_);
	h_content->addWidget(spinBox_);

	QFrame* frame=new QFrame;
	frame->setFixedWidth(330);
	frame->setLayout(h_content);
	filterOptionsArea_->setWidget(frame);
}
