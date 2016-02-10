#include "ScaleFilterBox.h"
#include <QWidget>
#include <QSlider>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QFrame>
#include <QDebug>
#include <QCheckBox>

#include "FilterConfigurationBox.h"
#include "../../model/filters/ScaleFilter.h"

GUI::ScaleFilterBox::ScaleFilterBox(QWidget* parent) {
	tempFilter_=std::make_unique<Model::ScaleFilter>();

	createFilterOptions();

	connect(keepRatio_, SIGNAL(stateChanged(int)),this,SLOT(keepRatio(int)));
	connect(height_,SIGNAL(valueChanged(int)),this,SLOT(heightChanged(int)));
	connect(width_,SIGNAL(valueChanged(int)),this,SLOT(widthChanged(int)));
	connect(ratio_,SIGNAL(valueChanged(int)),this,SLOT(ratioChanged(int)));
}

void GUI::ScaleFilterBox::updateUi() {
	auto value=static_cast<Model::ScaleFilter*>(tempFilter_.get())->getHeight();
	auto value2=static_cast<Model::ScaleFilter*>(tempFilter_.get())->getWidth();
	auto value3=static_cast<Model::ScaleFilter*>(tempFilter_.get())->getRatio();

	height_->setValue(value);
	width_->setValue(value2);
	ratio_->setValue(value3);
}

void GUI::ScaleFilterBox::keepRatio(int check) {
	static_cast<Model::ScaleFilter*>(tempFilter_.get())->setKeepRatio(check);
	keepRatio_->setChecked(check);

	updatePreview();
}

void GUI::ScaleFilterBox::heightChanged(int value) {
	static_cast<Model::ScaleFilter*>(tempFilter_.get())->setHeight(value);
	height_->setValue(value);

	updatePreview();
}

void GUI::ScaleFilterBox::widthChanged(int value) {
	static_cast<Model::ScaleFilter*>(tempFilter_.get())->setWidth(value);
	width_->setValue(value);

	updatePreview();
}

void GUI::ScaleFilterBox::ratioChanged(int value) {
	static_cast<Model::ScaleFilter*>(tempFilter_.get())->setRatio(value);
	ratio_->setValue(value);

	updatePreview();
}

void GUI::ScaleFilterBox::createFilterOptions() {
	QLabel* h=new QLabel("Height:");
	QLabel* w=new QLabel("Width:");
	QLabel* r=new QLabel("Ratio:");

	keepRatio_= new QCheckBox(tr("Keep ratio"));

	height_=new QSpinBox();
	height_->setMaximum(4800);
	height_->setMinimum(0);

	width_=new QSpinBox;
	width_->setMaximum(7680);
	width_->setMinimum(0);

	ratio_=new QSpinBox;
	ratio_->setMaximum(5);
	ratio_->setMinimum(0);

	QVBoxLayout* h_content=new QVBoxLayout;
	QHBoxLayout* keepRatio=new QHBoxLayout;
	QHBoxLayout* wh=new QHBoxLayout;
	QHBoxLayout* ratio=new QHBoxLayout;

	keepRatio->addWidget(keepRatio_);

	wh->addWidget(h);
	wh->addWidget(height_);
	wh->addWidget(w);
	wh->addWidget(width_);

	ratio->addWidget(r);
	ratio->addWidget(ratio_);

	h_content->addLayout(keepRatio);
	h_content->addSpacing(10);
	h_content->addLayout(wh);
	h_content->addSpacing(10);
	h_content->addLayout(ratio);

	QFrame* frame=new QFrame;
	frame->setFixedWidth(330);
	frame->setLayout(h_content);
	filterOptionsArea_->setWidget(frame);
}


