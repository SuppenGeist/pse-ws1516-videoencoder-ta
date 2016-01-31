#include "FilterTab.h"

#include <string>
#include <vector>
#include <QFrame>
#include <QStringListModel>

#include "PreviewControlPanel.h"
#include "FrameView.h"
//#include "PlayerControlPanel.h"
#include "FilterContainerTab.h"
#include "ui_filtertab.h"
#include "../model/FilterList.h"

#include "../model/filters/BlackWhiteFilter.h"
#include "../model/filters/GridFilter.h"
#include "../model/filters/EdgeFilter.h"
#include "../model/filters/BlendingFilter.h"
#include "../model/filters/BlurFilter.h"
#include "../model/filters/BorderFilter.h"
#include "../model/filters/BrightnessFilter.h"
#include "../model/filters/ColorbalanceFilter.h"
#include "../model/filters/ContrastFilter.h"
#include "../model/filters/MirrorFilter.h"
#include "../model/filters/NegativeFilter.h"
#include "../model/filters/NoiseFilter.h"
#include "../model/filters/PosterFilter.h"
#include "../model/filters/RectangleFilter.h"
#include "../model/filters/RGBFilter.h"
#include "../model/filters/RotationFilter.h"
#include "../model/filters/SaturationFilter.h"
#include "../model/filters/ScaleFilter.h"
#include "../model/filters/SepiaFilter.h"
#include "../model/filters/SharpnessFilter.h"
#include "../model/filters/VintageFilter.h"
#include "../model/filters/ZoomFilter.h"

GUI::FilterTab::FilterTab(QWidget* parent):QFrame(parent) {
	GUI::FilterTab::createUi();
	GUI::FilterTab::connectActions();
}

/*
 Memento::FilterTabMemento GUI::FilterTab::getMemento() {
	throw "Not yet implemented";
}

void GUI::FilterTab::restore(FilterTabMemento memento) {
	throw "Not yet implemented";
}
*/

void GUI::FilterTab::connectActions() {
	connect(button_apply,SIGNAL(clicked()),this,SLOT(apply()));
	connect(button_down,SIGNAL(clicked()),this,SLOT(down()));
	connect(button_load,SIGNAL(clicked()),this,SLOT(load()));
	connect(button_loadConf,SIGNAL(clicked()),this,SLOT(loadConf()));
	connect(button_remove,SIGNAL(clicked()),this,SLOT(remove()));
	connect(button_reset,SIGNAL(clicked()),this,SLOT(reset()));
	connect(button_save,SIGNAL(clicked()),this,SLOT(save()));
	connect(button_saveConf,SIGNAL(clicked()),this,SLOT(saveConf()));
	connect(button_up,SIGNAL(clicked()),this,SLOT(up()));
}

void GUI::FilterTab::createUi() {
	ui = new Ui::FilterTab;
	ui->setupUi(this);

	button_apply = ui->apply;
	button_down = ui->down;
	button_load = ui->loadVideo;
	button_loadConf = ui->loadConfig;
	button_remove = ui->remove;
	button_reset = ui->reset;
	button_save = ui->saveVideo;
	button_saveConf = ui->saveConfig;
	button_up = ui->up;

	filterContainerTab.push_back(new FilterContainerTab(ui->scrollAreaFilters));
	filterContainerTab.push_back(new FilterContainerTab(ui->scrollAreaArtefacts));
	ui->scrollAreaArtefacts->setWidget(filterContainerTab[1]);
	ui->scrollAreaFilters->setWidget(filterContainerTab[0]);

	filterContainerTab[0]->addFilter(new Model::BlackWhiteFilter());
	filterContainerTab[0]->addFilter(new Model::BlendingFilter());
	filterContainerTab[0]->addFilter(new Model::BlurFilter());
	filterContainerTab[0]->addFilter(new Model::BorderFilter());
	filterContainerTab[0]->addFilter(new Model::BrightnessFilter());
	filterContainerTab[0]->addFilter(new Model::ColorbalanceFilter());
	filterContainerTab[0]->addFilter(new Model::ContrastFilter());
	filterContainerTab[0]->addFilter(new Model::MirrorFilter());
	filterContainerTab[0]->addFilter(new Model::NegativeFilter());
	filterContainerTab[0]->addFilter(new Model::NoiseFilter());
	filterContainerTab[0]->addFilter(new Model::PosterFilter());
	filterContainerTab[0]->addFilter(new Model::RectangleFilter());
	filterContainerTab[0]->addFilter(new Model::RGBFilter());
	filterContainerTab[0]->addFilter(new Model::RotationFilter());
	filterContainerTab[0]->addFilter(new Model::SaturationFilter());
	filterContainerTab[0]->addFilter(new Model::ScaleFilter());
	filterContainerTab[0]->addFilter(new Model::SepiaFilter());
	filterContainerTab[0]->addFilter(new Model::SharpnessFilter());
	filterContainerTab[0]->addFilter(new Model::VintageFilter());
	filterContainerTab[0]->addFilter(new Model::ZoomFilter());

	filterContainerTab[1]->addFilter(new Model::EdgeFilter());
	filterContainerTab[1]->addFilter(new Model::GridFilter());

	ui->panel = new PreviewControlPanel();

}

void GUI::FilterTab::up() {
	throw "Not yet implemented";
}

void GUI::FilterTab::down() {
	int index = list_filterList->currentIndex().row();
	filterList->moveFilter(index, index+1);
	ui->listWidget->insertItem(index+1,ui->listWidget->takeItem(index));

}

void GUI::FilterTab::remove() {
	throw "Not yet implemented";
}

void GUI::FilterTab::load() {
	throw "Not yet implemented";
}

void GUI::FilterTab::apply() {
	throw "Not yet implemented";
}

void GUI::FilterTab::saveConf() {
	throw "Not yet implemented";
}

void GUI::FilterTab::loadConf() {
	throw "Not yet implemented";
}

void GUI::FilterTab::reset() {
	throw "Not yet implemented";
}

void GUI::FilterTab::save() {
	throw "Not yet implemented";
}

/*void GUI::FilterTab::insertFilter(Filter filter, int index) {
	throw "Not yet implemented";
}
*/
void GUI::FilterTab::listSelectionChanged(QModelIndex* index) {
	throw "Not yet implemented";
}
/*
void GUI::FilterTab::removeFilter(string filterName) {
	throw "Not yet implemented";
}

void GUI::FilterTab::showVideo() {
	throw "Not yet implemented";
}

void GUI::FilterTab::showPreview() {
	throw "Not yet implemented";
}

void GUI::FilterTab::resetFilters() {
	throw "Not yet implemented";
}

void GUI::FilterTab::setFilterList(FilterList list) {
	throw "Not yet implemented";
}

/*void GUI::FilterTab::setRawVideo(YuvVideo video) {
	throw "Not yet implemented";
}

void GUI::FilterTab::moveFilter(int old, int new_3) {
	throw "Not yet implemented";
}

*/
