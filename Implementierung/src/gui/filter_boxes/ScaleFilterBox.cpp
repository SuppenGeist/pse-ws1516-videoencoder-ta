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

GUI::ScaleFilterBox::ScaleFilterBox(QWidget* parent):FilterConfigurationBox(parent) {
	tempFilter_=std::make_unique<Model::ScaleFilter>();

	createFilterOptions();

	connect(keepRatio_, SIGNAL(stateChanged(int)),this,SLOT(keepRatio(int)));
	connect(height_,SIGNAL(valueChanged(int)),this,SLOT(heightChanged(int)));
	connect(width_,SIGNAL(valueChanged(int)),this,SLOT(widthChanged(int)));
	connect(ratio_,SIGNAL(valueChanged(int)),this,SLOT(ratioChanged(int)));
}

void GUI::ScaleFilterBox::updateUi() {
	updateTempFilter();
	auto value=static_cast<Model::ScaleFilter*>(tempFilter_.get())->getHeight();
	auto value2=static_cast<Model::ScaleFilter*>(tempFilter_.get())->getWidth();
	auto value3=static_cast<Model::ScaleFilter*>(tempFilter_.get())->getRatio();
	auto value4=static_cast<Model::ScaleFilter*>(tempFilter_.get())->getKeepRatio();

	if(value4) {
		height_->setEnabled(false);
		width_->setEnabled(false);
		ratio_->setEnabled(true);
	} else {
		height_->setEnabled(true);
		width_->setEnabled(true);
		ratio_->setEnabled(false);
	}

	height_->setValue(value);
	width_->setValue(value2);
	ratio_->setValue(value3);

	updatePreview();
}

void GUI::ScaleFilterBox::keepRatio(int check) {
	static_cast<Model::ScaleFilter*>(tempFilter_.get())->setKeepRatio(check);
	if(check) {
		height_->setEnabled(false);
		width_->setEnabled(false);
		ratio_->setEnabled(true);
	} else {
		height_->setEnabled(true);
		width_->setEnabled(true);
		ratio_->setEnabled(false);
	}

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
	QLabel* r=new QLabel("Multiplicator:");

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
	QFrame* separator=new QFrame;
	separator->setFrameShape(QFrame::VLine);
	separator->setFrameShadow(QFrame::Sunken);
	wh->addWidget(separator);
	wh->addWidget(w);
	wh->addWidget(width_);
	ratio->addWidget(keepRatio_);
	QFrame* separator2=new QFrame;
	separator2->setFrameShape(QFrame::VLine);
	separator2->setFrameShadow(QFrame::Sunken);
	ratio->addWidget(separator2);
	ratio->addWidget(r);
	ratio->addWidget(ratio_);

	h_content->addLayout(wh);
	QFrame* separator1=new QFrame;
	separator1->setFrameShape(QFrame::HLine);
	separator1->setFrameShadow(QFrame::Plain);
	separator1->setStyleSheet("background-color:black;");
	separator1->setFixedHeight(1);
	h_content->addSpacing(5);
	h_content->addWidget(separator1);
	h_content->addSpacing(5);
	h_content->addLayout(ratio);

	QFrame* frame=new QFrame;
	frame->setFixedWidth(330);
	frame->setLayout(h_content);
	filterOptionsArea_->setWidget(frame);
}


