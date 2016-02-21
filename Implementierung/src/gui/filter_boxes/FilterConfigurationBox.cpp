#include "FilterConfigurationBox.h"

#include <memory>

#include <QWidget>
#include <QFrame>
#include <QImage>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFont>
#include <QPushButton>
#include <QScrollArea>
#include <QLabel>
#include <QDebug>

#include "../../model/filters/Filter.h"
#include "../FrameView.h"
#include "../../utility/FilterApplier.h"
#include "../../model/FilterList.h"
#include "../../utility/VideoConverter.h"
#include "../FilterTab.h"
#include "../../undo_framework/changefilter.h"
#include "../../undo_framework/UndoStack.h"

#include "BlurFilterBox.h"
#include "BorderFilterBox.h"
#include "BrightnessFilterBox.h"
#include "ColorbalanceFilterBox.h"
#include "ContrastFilterBox.h"
#include "GridFilterBox.h"
#include "MirrorFilterBox.h"
#include "NoiseFilterBox.h"
#include "PlainFilterBox.h"
#include "PosterFilterBox.h"
#include "RectangleFilterBox.h"
#include "RGBFilterBox.h"
#include "RotationFilterBox.h"
#include "SaturationFilterBox.h"
#include "ScaleFilterBox.h"
#include "SharpnessFilterBox.h"

#include "../../model/filters/BlurFilter.h"
#include "../../model/filters/BorderFilter.h"
#include "../../model/filters/BrightnessFilter.h"
#include "../../model/filters/ColorbalanceFilter.h"
#include "../../model/filters/ContrastFilter.h"
#include "../../model/filters/GridFilter.h"
#include "../../model/filters/MirrorFilter.h"
#include "../../model/filters/NoiseFilter.h"
#include "../../model/filters/PosterFilter.h"
#include "../../model/filters/RectangleFilter.h"
#include "../../model/filters/RGBFilter.h"
#include "../../model/filters/RotationFilter.h"
#include "../../model/filters/SaturationFilter.h"
#include "../../model/filters/ScaleFilter.h"
#include "../../model/filters/SharpnessFilter.h"

std::unique_ptr<QImage> GUI::FilterConfigurationBox::defaultImage_;

GUI::FilterConfigurationBox::FilterConfigurationBox(QWidget* parent):QFrame(parent) {
	setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Minimum);
	createUi();

	connect(button_apply_,SIGNAL(clicked()),this,SLOT(applyFilter()));
	connect(button_reset_,SIGNAL(clicked()),this,SLOT(resetFilter()));
}

GUI::FilterConfigurationBox::~FilterConfigurationBox() {

}

std::unique_ptr<GUI::FilterConfigurationBox> GUI::FilterConfigurationBox::CreateConfigurationBox(
    FilterTab &filterTab, Model::Filter &filter) {
	std::unique_ptr<FilterConfigurationBox> box;

	if(filter.getName()==Model::BlurFilter::FILTERNAME) {
		box=std::make_unique<BlurFilterBox>();
	} else if(filter.getName()==Model::BrightnessFilter::FILTERNAME) {
		box=std::make_unique<BrightnessFilterBox>();
	} else if(filter.getName()==Model::ContrastFilter::FILTERNAME) {
		box=std::make_unique<ContrastFilterBox>();
	} else if(filter.getName()==Model::SaturationFilter::FILTERNAME) {
		box=std::make_unique<SaturationFilterBox>();
	} else if(filter.getName()==Model::RotationFilter::FILTERNAME) {
		box=std::make_unique<RotationFilterBox>();
	} else if(filter.getName()==Model::SharpnessFilter::FILTERNAME) {
		box=std::make_unique<SharpnessFilterBox>();
	} else if(filter.getName()==Model::PosterFilter::FILTERNAME) {
		box=std::make_unique<PosterFilterBox>();
	} else if(filter.getName()==Model::BorderFilter::FILTERNAME) {
		box=std::make_unique<BorderFilterBox>();
	} else if(filter.getName()==Model::GridFilter::FILTERNAME) {
		box=std::make_unique<GridFilterBox>();
	} else if(filter.getName()==Model::MirrorFilter::FILTERNAME) {
		box=std::make_unique<MirrorFilterBox>();
	} else if(filter.getName()==Model::ScaleFilter::FILTERNAME) {
		box=std::make_unique<ScaleFilterBox>();
	} else if(filter.getName()==Model::NoiseFilter::FILTERNAME) {
		box=std::make_unique<NoiseFilterBox>();
	} else if(filter.getName()==Model::RGBFilter::FILTERNAME) {
		box=std::make_unique<RGBFilterBox>();
	} else if(filter.getName()==Model::ColorbalanceFilter::FILTERNAME) {
		box=std::make_unique<ColorbalanceFilterBox>();
	} else if(filter.getName()==Model::RectangleFilter::FILTERNAME) {
		box=std::make_unique<RectangleFilterBox>();
	} else {
		return std::make_unique<PlainFilterBox>();
	}

	box->setFilter(filter);
	box->setFilterTab(filterTab);

	return std::move(box);
}

void GUI::FilterConfigurationBox::setFilter(Model::Filter& filter) {
	filter_=&filter;
	label_filter_->setText(filter_->getName()+" filter");
	updateUi();
}

Model::Filter* GUI::FilterConfigurationBox::getFilter() {
	return filter_;
}

void GUI::FilterConfigurationBox::setFilterTab(GUI::FilterTab &filterTab) {
	filterTab_=&filterTab;
}

void GUI::FilterConfigurationBox::setFilterIndex(int index) {
	index_=index;
}

void GUI::FilterConfigurationBox::updatePreview() {
	Model::FilterList filterList;
	filterList.appendFilter(tempFilter_->getName())->restore(tempFilter_->getSaveString());

	auto avframe=Utility::VideoConverter::convertQImageToAVFrame(getDefaultImage());

	Utility::FilterApplier applier(filterList,avframe->width,avframe->height,avframe->format);

	auto filteredFrame=applier.applyToFrame(*avframe);

	filteredImage_=Utility::VideoConverter::convertAVFrameToQImage(*filteredFrame);
	filterPreview_->setFrame(*filteredImage_);

    av_frame_unref(avframe);
    av_frame_unref(filteredFrame);
	av_frame_free(&avframe);
	av_frame_free(&filteredFrame);
}

void GUI::FilterConfigurationBox::updateTempFilter() {
	if(!filter_)
		return;

	tempFilter_->restore(filter_->getSaveString());
}

void GUI::FilterConfigurationBox::applyFilter() {
	auto command=new UndoRedo::ChangeFilter(*filterTab_,index_,filter_->getSaveString(),
	                                        tempFilter_->getSaveString());

	UndoRedo::UndoStack::getUndoStack().push(command);
}

void GUI::FilterConfigurationBox::resetFilter() {
	updateTempFilter();
	updateUi();
}

void GUI::FilterConfigurationBox::createUi() {
	filterPreview_=new FrameView;
	filterPreview_->setFixedSize(200,200);
	filterPreview_->setFrame(getDefaultImage());

	button_apply_=new QPushButton("Apply");
	QString stylesheet("QPushButton {"
	                   "color: rgb(0, 0, 0);"
	                   "background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #88d, stop: 0.1 #99e, stop: 0.49 #77c);"
	                   "background: rgb(220, 220, 220);"
	                   "border-width: 1px;"
	                   "border-color:rgb(0, 0, 0);"
	                   "border-style: outset;"
	                   "border-radius: 7px;"
	                   "font-size: 14px;"
	                   "}"
	                   "QPushButton:pressed {"
	                   "background-color: rgb(200, 200, 200);"
	                   "border-style: inset;"
	                   "}"
	                  );
	button_apply_->setStyleSheet(stylesheet);
	button_apply_->setFixedSize(70,25);

	button_reset_=new QPushButton("Reset");
	button_reset_->setStyleSheet(stylesheet);
	button_reset_->setFixedSize(70,25);

	label_filter_=new QLabel(tr("Filter options:"));
	QFont font("Arial",12,QFont::Bold);
	label_filter_->setFont(font);


	filterOptionsArea_=new QScrollArea;
	filterOptionsArea_->setFixedSize(330,160);
	filterOptionsArea_->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
	filterOptionsArea_->setObjectName("OptArea");
	filterOptionsArea_->setStyleSheet("QScrollArea#OptArea {"
	                                  "background-color:white;"
	                                  "}");

	QHBoxLayout* h_content=new QHBoxLayout;

	h_content->addWidget(filterPreview_);
	h_content->addSpacing(20);

	QVBoxLayout* v_caption_options=new QVBoxLayout;
	QHBoxLayout* h_label_butt=new QHBoxLayout;
	h_label_butt->addWidget(label_filter_);
	QSpacerItem* sp1=new QSpacerItem(0,0,QSizePolicy::Expanding,QSizePolicy::Minimum);
	h_label_butt->addSpacerItem(sp1);
	h_label_butt->addWidget(button_reset_);
	h_label_butt->addWidget(button_apply_);
	v_caption_options->addLayout(h_label_butt);
	QFrame* separator=new QFrame;
	separator->setFrameShape(QFrame::HLine);
	separator->setFrameShadow(QFrame::Sunken);
	v_caption_options->addWidget(separator);
	v_caption_options->addWidget(filterOptionsArea_);

	h_content->addLayout(v_caption_options);
	h_content->addSpacing(20);

	setLayout(h_content);
	setFixedWidth(600);
	setObjectName("BaseBox");
	setStyleSheet("QFrame#BaseBox {"
	              "border-width: 2px;"
	              "border-color:rgb(0, 0, 0);"
	              "border-style: outset;"
	              "border-radius:5px;"
	              "background-color:rgb(245,245,245);"
	              "}");
}

QImage& GUI::FilterConfigurationBox::getDefaultImage() {
	if(defaultImage_.get()) {
		return *defaultImage_;
	}
	defaultImage_=std::make_unique<QImage>(":/pictures/resources/flower_example.png");

	return *defaultImage_;
}
