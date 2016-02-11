#include "SharpnessFilterBox.h"

#include <QWidget>
#include <QSlider>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QFrame>
#include <QDebug>

#include "FilterConfigurationBox.h"
#include "../../model/filters/SharpnessFilter.h"

GUI::SharpnessFilterBox::SharpnessFilterBox(QWidget* parent):FilterConfigurationBox(parent) {
	tempFilter_=std::make_unique<Model::SharpnessFilter>();

	createFilterOptions();

	connect(slider_,SIGNAL(valueChanged(int)),this,SLOT(sliderChanged(int)));
	connect(spinBox_,SIGNAL(valueChanged(int)),this,SLOT(spinBoxChanged(int)));
}

void GUI::SharpnessFilterBox::updateUi() {
	auto value=static_cast<Model::SharpnessFilter*>(tempFilter_.get())->getIntensity();
	slider_->setValue(value);
	spinBox_->setValue(value);

    updatePreview();
}

void GUI::SharpnessFilterBox::sliderChanged(int value) {
	static_cast<Model::SharpnessFilter*>(tempFilter_.get())->setIntensity(value);
	spinBox_->setValue(value);
}

void GUI::SharpnessFilterBox::spinBoxChanged(int value) {
	static_cast<Model::SharpnessFilter*>(tempFilter_.get())->setIntensity(value);
	slider_->setValue(value);

	updatePreview();
}

void GUI::SharpnessFilterBox::createFilterOptions() {
	QLabel* l=new QLabel("Intensity:");

	slider_=new QSlider(Qt::Horizontal);
	slider_->setMaximum(100);
	slider_->setMinimum(-100);

	spinBox_=new QSpinBox;
	spinBox_->setMaximum(100);
	spinBox_->setMinimum(-100);


	QHBoxLayout* h_content=new QHBoxLayout;

	h_content->addWidget(l);
	h_content->addWidget(slider_);
	h_content->addWidget(spinBox_);

	QFrame* frame=new QFrame;
	frame->setFixedWidth(330);
	frame->setLayout(h_content);
	filterOptionsArea_->setWidget(frame);
}


