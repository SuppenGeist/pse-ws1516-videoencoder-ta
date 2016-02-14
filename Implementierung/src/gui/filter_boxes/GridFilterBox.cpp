#include "GridFilterBox.h"
#include <QWidget>
#include <QSlider>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QFrame>
#include <QDebug>
#include <QColorDialog>

#include "FilterConfigurationBox.h"
#include "../../model/filters/GridFilter.h"

GUI::GridFilterBox::GridFilterBox(QWidget* parent):FilterConfigurationBox(parent) {
	tempFilter_=std::make_unique<Model::GridFilter>();

	createFilterOptions();

	connect(spinBox_,SIGNAL(valueChanged(int)),this,SLOT(spinBoxChanged(int)));
	connect(slider2_,SIGNAL(valueChanged(int)),this,SLOT(slider2Changed(int)));
	connect(spinBox2_,SIGNAL(valueChanged(int)),this,SLOT(spinBox2Changed(int)));
	connect(spinBox3_,SIGNAL(valueChanged(int)),this,SLOT(spinBox3Changed(int)));
	connect(spinBox4_,SIGNAL(valueChanged(int)),this,SLOT(spinBox4Changed(int)));
	connect(button_,SIGNAL(clicked()),this,SLOT(openColorDialog()));
}

void GUI::GridFilterBox::updateUi() {
	updateTempFilter();
	auto t=static_cast<Model::GridFilter*>(tempFilter_.get())->getThickness();
	auto o=static_cast<Model::GridFilter*>(tempFilter_.get())->getOpacity();
	auto hl=static_cast<Model::GridFilter*>(tempFilter_.get())->getHorizontalCells();
	auto vl=static_cast<Model::GridFilter*>(tempFilter_.get())->getVerticalCells();
	auto color=static_cast<Model::GridFilter*>(tempFilter_.get())->getColor();

	color_=color;
	spinBox_->setValue(t);
	slider2_->setValue(o);
	spinBox2_->setValue(o);
	spinBox3_->setValue(hl);
	spinBox4_->setValue(vl);

	updatePreview();
}

void GUI::GridFilterBox::openColorDialog() {
	color_ = QColorDialog::getColor(color_,this);
	static_cast<Model::GridFilter*>(tempFilter_.get())->setColor(color_);
	updatePreview();
}

void GUI::GridFilterBox::spinBoxChanged(int value) {
	static_cast<Model::GridFilter*>(tempFilter_.get())->setThickness(value);

	updatePreview();
}

void GUI::GridFilterBox::slider2Changed(int value2) {
	static_cast<Model::GridFilter*>(tempFilter_.get())->setOpacity(value2);
	spinBox2_->setValue(value2);
}

void GUI::GridFilterBox::spinBox2Changed(int value2) {
	static_cast<Model::GridFilter*>(tempFilter_.get())->setOpacity(value2);
	slider2_->setValue(value2);

	updatePreview();
}

void GUI::GridFilterBox::spinBox3Changed(int value3) {
	static_cast<Model::GridFilter*>(tempFilter_.get())->setHorizontalCells(value3);

	updatePreview();
}

void GUI::GridFilterBox::spinBox4Changed(int value4) {
	static_cast<Model::GridFilter*>(tempFilter_.get())->setVerticalCells(value4);

	updatePreview();
}

void GUI::GridFilterBox::createFilterOptions() {
	QLabel* t=new QLabel("Thickness:");
	QLabel* o=new QLabel("Opacity:");
	QLabel* h=new QLabel("Horizontal cells:");
	QLabel* v=new QLabel("Vertical cells:");

	QColor color_;

	spinBox_=new QSpinBox;
	spinBox_->setMinimum(0);
	spinBox_->setMaximum(100000);
	spinBox_->setFixedWidth(100);

	slider2_=new QSlider(Qt::Horizontal);
	slider2_->setMaximum(255);
	slider2_->setMinimum(0);

	spinBox2_=new QSpinBox;
	spinBox2_->setMaximum(255);
	spinBox2_->setMinimum(0);

	spinBox3_=new QSpinBox;
	spinBox3_->setMaximum(100000);
	spinBox3_->setMinimum(1);
	spinBox3_->setFixedWidth(100);

	spinBox4_=new QSpinBox;
	spinBox4_->setMaximum(100000);
	spinBox4_->setMinimum(1);
	spinBox4_->setFixedWidth(100);

	button_ = new QPushButton(tr("Color"));

	QVBoxLayout* h_content=new QVBoxLayout;
	QHBoxLayout* thickness=new QHBoxLayout;
	QHBoxLayout* opacity=new QHBoxLayout;
	QHBoxLayout* cells=new QHBoxLayout;
	QHBoxLayout* cells1=new QHBoxLayout;
	QHBoxLayout* color=new QHBoxLayout;

	thickness->addWidget(t);
	thickness->addWidget(spinBox_);
	thickness->addSpacing(15);
	opacity->addWidget(o);
	opacity->addWidget(slider2_);
	opacity->addWidget(spinBox2_);
	opacity->addSpacing(15);
	cells->addWidget(h);
	cells->addWidget(spinBox3_);
	cells->addSpacing(15);
	cells1->addWidget(v);
	cells1->addWidget(spinBox4_);
	cells1->addSpacing(15);
	color->addWidget(button_);
	color->addSpacing(15);

	h_content->addLayout(thickness);
	QFrame* separator=new QFrame;
	separator->setFrameShape(QFrame::HLine);
	separator->setFrameShadow(QFrame::Plain);
	separator->setStyleSheet("background-color:black;");
	separator->setFixedHeight(1);
	h_content->addSpacing(5);
	h_content->addWidget(separator);
	h_content->addSpacing(5);
	h_content->addLayout(opacity);
	QFrame* separator1=new QFrame;
	separator1->setFrameShape(QFrame::HLine);
	separator1->setFrameShadow(QFrame::Plain);
	separator1->setStyleSheet("background-color:black;");
	separator1->setFixedHeight(1);
	h_content->addSpacing(5);
	h_content->addWidget(separator1);
	h_content->addSpacing(5);
	h_content->addLayout(cells);
	QFrame* separator2=new QFrame;
	separator2->setFrameShape(QFrame::HLine);
	separator2->setFrameShadow(QFrame::Plain);
	separator2->setStyleSheet("background-color:black;");
	separator2->setFixedHeight(1);
	h_content->addSpacing(5);
	h_content->addWidget(separator2);
	h_content->addSpacing(5);
	h_content->addLayout(cells1);
	QFrame* separator3=new QFrame;
	separator3->setFrameShape(QFrame::HLine);
	separator3->setFrameShadow(QFrame::Plain);
	separator3->setStyleSheet("background-color:black;");
	separator3->setFixedHeight(1);
	h_content->addSpacing(5);
	h_content->addWidget(separator3);
	h_content->addSpacing(5);
	h_content->addLayout(color);

	QFrame* frame=new QFrame;
	frame->setFixedWidth(330);
	frame->setLayout(h_content);
	filterOptionsArea_->setWidget(frame);
}
