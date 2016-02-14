#include "MirrorFilterBox.h"

#include <QWidget>
#include <QComboBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QFrame>
#include <QDebug>

#include "FilterConfigurationBox.h"
#include "../../model/filters/MirrorFilter.h"
#include "../../model/MirrorMode.h"

GUI::MirrorFilterBox::MirrorFilterBox(QWidget* parent):FilterConfigurationBox(parent) {
	tempFilter_=std::make_unique<Model::MirrorFilter>();

	createFilterOptions();

	connect(mirror_, SIGNAL(currentIndexChanged(int)),this,SLOT( mirrorMode() ));
}

void GUI::MirrorFilterBox::updateUi() {
	updateTempFilter();
	auto mirrormode=static_cast<Model::MirrorFilter*>(tempFilter_.get())->getMode();

	if(mirrormode==Model::MirrorMode::HORIZONTAL) {
		mirror_->setCurrentIndex(0);
	} else if (mirrormode==Model::MirrorMode::VERTICAL) {
		mirror_->setCurrentIndex(1);
	}
	updatePreview();
}

void GUI::MirrorFilterBox::mirrorMode() {
	if(mirror_->currentText()=="HORIZONTAL") {
		static_cast<Model::MirrorFilter*>(tempFilter_.get())->setMode(Model::MirrorMode::HORIZONTAL);
	} else if(mirror_->currentText()=="VERTICAL") {
		static_cast<Model::MirrorFilter*>(tempFilter_.get())->setMode(Model::MirrorMode::VERTICAL);
	}
	updatePreview();
}


void GUI::MirrorFilterBox::createFilterOptions() {
	QLabel* m=new QLabel("Mode:");

	mirror_ = new QComboBox;
	mirror_->addItem("HORIZONTAL");
	mirror_->addItem("VERTICAL");

	QHBoxLayout* h_content=new QHBoxLayout;

	h_content->addWidget(m);
	h_content->addWidget(mirror_);

	QFrame* frame=new QFrame;
	frame->setFixedWidth(330);
	frame->setLayout(h_content);
	filterOptionsArea_->setWidget(frame);
}
