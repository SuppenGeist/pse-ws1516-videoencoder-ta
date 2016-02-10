#include "PosterFilterBox.h"

#include <QWidget>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QFrame>
#include <QDebug>

#include "FilterConfigurationBox.h"
#include "../../model/filters/PosterFilter.h"

GUI::PosterFilterBox::PosterFilterBox(QWidget* parent) {
	tempFilter_=std::make_unique<Model::PosterFilter>();

	createFilterOptions();

	connect(spinBox_,SIGNAL(valueChanged(int)),this,SLOT(spinBoxChanged(int)));
}

void GUI::PosterFilterBox::updateUi() {
	auto value=static_cast<Model::PosterFilter*>(tempFilter_.get())->getNumberOfColors();
	spinBox_->setValue(value);
}

void GUI::PosterFilterBox::spinBoxChanged(int value) {
	static_cast<Model::PosterFilter*>(tempFilter_.get())->setNumberOfColors(value);

	updatePreview();
}

void GUI::PosterFilterBox::createFilterOptions() {
	QLabel* l=new QLabel("Number of colors:");

	spinBox_=new QSpinBox;
	spinBox_->setMaximum(256);
	spinBox_->setMinimum(1);


	QHBoxLayout* h_content=new QHBoxLayout;

	h_content->addWidget(l);
	h_content->addWidget(spinBox_);

	QFrame* frame=new QFrame;
	frame->setFixedWidth(330);
	frame->setLayout(h_content);
	filterOptionsArea_->setWidget(frame);
}


