#include "BorderFilterBox.h"

#include <QWidget>
#include <QSlider>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QColorDialog>
#include <QCheckBox>
#include <QLabel>
#include <QFrame>
#include <QDebug>

#include "FilterConfigurationBox.h"
#include "../../model/filters/BorderFilter.h"

GUI::BorderFilterBox::BorderFilterBox(QWidget* parent):FilterConfigurationBox(parent) {
	tempFilter_=std::make_unique<Model::BorderFilter>();

	createFilterOptions();

	connect(top_, SIGNAL(stateChanged(int)),this,SLOT(topchecked(int)));
	connect(bottom_, SIGNAL(stateChanged(int)),this,SLOT(bottomchecked(int)));
	connect(right_, SIGNAL(stateChanged(int)),this,SLOT(rightchecked(int)));
	connect(left_, SIGNAL(stateChanged(int)),this,SLOT(leftchecked(int)));
	connect(spinBox_,SIGNAL(valueChanged(int)),this,SLOT(spinBoxChanged(int)));
	connect(button_,SIGNAL(clicked()),this,SLOT(openColorDialog()));

}

void GUI::BorderFilterBox::updateUi() {
	updateTempFilter();
	auto top=static_cast<Model::BorderFilter*>(tempFilter_.get())->getTop();
	auto bottom=static_cast<Model::BorderFilter*>(tempFilter_.get())->getBottom();
	auto right=static_cast<Model::BorderFilter*>(tempFilter_.get())->getRight();
	auto left=static_cast<Model::BorderFilter*>(tempFilter_.get())->getLeft();
	auto value=static_cast<Model::BorderFilter*>(tempFilter_.get())->getThickness();
	auto color=static_cast<Model::BorderFilter*>(tempFilter_.get())->getColor();

	color_=color;
	top_->setChecked(top);
	bottom_->setChecked(bottom);
	right_->setChecked(right);
	left_->setChecked(left);
	spinBox_->setValue(value);

	updatePreview();
}

void GUI::BorderFilterBox::openColorDialog() {
	color_ = QColorDialog::getColor(color_,this);
	static_cast<Model::BorderFilter*>(tempFilter_.get())->setColor(color_);
	updatePreview();
}


void GUI::BorderFilterBox::spinBoxChanged(int value) {
	static_cast<Model::BorderFilter*>(tempFilter_.get())->setThickness(value);

	updatePreview();
}


void GUI::BorderFilterBox::topchecked(int check) {
	static_cast<Model::BorderFilter*>(tempFilter_.get())->setTop(check);
	top_->setChecked(check);

	updatePreview();
}

void GUI::BorderFilterBox::bottomchecked(int check) {
	static_cast<Model::BorderFilter*>(tempFilter_.get())->setBottom(check);
	bottom_->setChecked(check);

	updatePreview();
}

void GUI::BorderFilterBox::rightchecked(int check) {
	static_cast<Model::BorderFilter*>(tempFilter_.get())->setRight(check);
	right_->setChecked(check);

	updatePreview();
}

void GUI::BorderFilterBox::leftchecked(int check) {
	static_cast<Model::BorderFilter*>(tempFilter_.get())->setLeft(check);
	left_->setChecked(check);

	updatePreview();
}

void GUI::BorderFilterBox::createFilterOptions() {
	QLabel* l=new QLabel("Thickness:");
	QLabel* t=new QLabel("Top");
	QLabel* b=new QLabel("Bottom");
	QLabel* r=new QLabel("Right");
	QLabel* le=new QLabel("Left");
	top_= new QCheckBox;
	bottom_= new QCheckBox;
	right_= new QCheckBox;
	left_= new QCheckBox;

	spinBox_=new QSpinBox;
	spinBox_->setMinimum(0);
	spinBox_->setMaximum(100000);
	spinBox_->setFixedWidth(100);

	button_ = new QPushButton(tr("Color"));

	QVBoxLayout* h_content=new QVBoxLayout;
	QHBoxLayout* topLayout=new QHBoxLayout;
	QHBoxLayout* bottomLayout=new QHBoxLayout;
	QHBoxLayout* bottom2Layout= new QHBoxLayout;

	topLayout->addWidget(t);
	topLayout->addWidget(top_);
	QFrame* separator=new QFrame;
	separator->setFrameShape(QFrame::VLine);
	separator->setFrameShadow(QFrame::Sunken);
	topLayout->addWidget(separator);
	topLayout->addWidget(b);
	topLayout->addWidget(bottom_);
	QFrame* separator1=new QFrame;
	separator1->setFrameShape(QFrame::VLine);
	separator1->setFrameShadow(QFrame::Sunken);
	topLayout->addWidget(separator1);
	topLayout->addWidget(r);
	topLayout->addWidget(right_);
	QFrame* separator2=new QFrame;
	separator2->setFrameShape(QFrame::VLine);
	separator2->setFrameShadow(QFrame::Sunken);
	topLayout->addWidget(separator2);
	topLayout->addWidget(le);
	topLayout->addWidget(left_);
	bottomLayout->addWidget(l);
	bottomLayout->addWidget(spinBox_);
	bottom2Layout->addWidget(button_);

	h_content->addSpacing(5);
	h_content->addLayout(topLayout);
	QFrame* separator3=new QFrame;
	separator3->setFrameShape(QFrame::HLine);
	separator3->setFrameShadow(QFrame::Plain);
	separator3->setStyleSheet("background-color:black;");
	separator3->setFixedHeight(1);
	h_content->addSpacing(8);
	h_content->addWidget(separator3);
	h_content->addSpacing(5);
	h_content->addLayout(bottomLayout);
	QFrame* separator4=new QFrame;
	separator4->setFrameShape(QFrame::HLine);
	separator4->setFrameShadow(QFrame::Plain);
	separator4->setStyleSheet("background-color:black;");
	separator4->setFixedHeight(1);
	h_content->addSpacing(5);
	h_content->addWidget(separator4);
	h_content->addSpacing(5);
	h_content->addLayout(bottom2Layout);

	QFrame* frame=new QFrame;
	frame->setFixedWidth(330);
	frame->setLayout(h_content);
	filterOptionsArea_->setWidget(frame);
}
