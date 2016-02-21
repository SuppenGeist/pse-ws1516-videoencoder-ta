#include "AnalysisBoxContainer.h"

#include <vector>

#include <QWidget>
#include <QFrame>
#include <QVBoxLayout>
#include <QString>
#include <QSpacerItem>
#include <QPushButton>
#include <QHBoxLayout>
#include <QFileDialog>
#include <QFileInfo>
#include <QDebug>

#include "AnalysisBox.h"
#include "AnalysisTab.h"
#include "MainWindow.h"

#include "../undo_framework/UndoStack.h"
#include "../undo_framework/AddVideo.h"

GUI::AnalysisBoxContainer::AnalysisBoxContainer(QWidget* parent) : QFrame(parent),
	currentGraph_(AnalysisGraph::BITRATE),currentVideo_(AnalysisVideo::MACROBLOCK) {
	createUi();
	setContentsMargins(-10,-10,-10,-10);

	connect(button_addVideo_,SIGNAL(clicked(bool)),this,SLOT(addVideo()));

	setObjectName("anacontainer");
	setStyleSheet("QFrame#anacontainer {background-color:white;}");
}

std::unique_ptr<Memento::AnalysisBoxContainerMemento> GUI::AnalysisBoxContainer::getMemento() {
	auto memento=std::make_unique<Memento::AnalysisBoxContainerMemento>();

	for(auto box:boxes_) {
		memento->addMemento(std::move(box->getMemento()));
	}

	return std::move(memento);
}

void GUI::AnalysisBoxContainer::restore(Memento::AnalysisBoxContainerMemento *memento) {
	if(!memento)
		return;

	for(auto& mem:memento->getAnalysisBoxList()) {
		appendBox(new AnalysisBox)->restore(mem.get());
	}

	updateUi();
}

void GUI::AnalysisBoxContainer::setParentTab(GUI::AnalysisTab *parent) {
	parent_=parent;
}

GUI::AnalysisTab *GUI::AnalysisBoxContainer::getParentTab() {
	return parent_;
}

GUI::AnalysisBox *GUI::AnalysisBoxContainer::appendBox(GUI::AnalysisBox *box) {
	if(!box)
		return nullptr;

	insertBox(box,boxes_.size());

	return box;
}

int GUI::AnalysisBoxContainer::removeBox(AnalysisBox* box) {
	std::size_t i=0;
	for(; i<boxes_.size(); i++) {
		if(boxes_[i]==box) {
			auto b=boxes_[i];
			boxes_.erase(boxes_.begin()+i);
			v_boxes_->removeWidget(b);
			b->hide();
			delete b;
			break;
		}
	}

	updateUi();
	if(i==boxes_.size()+1)
		return -1;
	return i;
}

void GUI::AnalysisBoxContainer::clear() {
	std::size_t count=boxes_.size();
	for(std::size_t i=0; i<count; i++) {
		auto b=boxes_[0];
		boxes_.erase(boxes_.begin());
		v_boxes_->removeWidget(b);
		b->hide();
		delete b;
	}

	updateUi();
}

void GUI::AnalysisBoxContainer::setTimer(std::shared_ptr<GUI::Timer> timer) {
	timer_=timer;
}

void GUI::AnalysisBoxContainer::setControlPanel(std::shared_ptr<GlobalControlPanel> controlpanel) {
	controlPanel_=controlpanel;
}

void GUI::AnalysisBoxContainer::showGraph(GUI::AnalysisGraph graph) {
	for(auto box:boxes_) {
		box->showGraph(graph);
	}
	currentGraph_=graph;
}

void GUI::AnalysisBoxContainer::showAnalysisVideo(GUI::AnalysisVideo video) {
	for(auto box:boxes_) {
		box->showAnalysisVideo(video);
	}
	currentVideo_=video;
}

void GUI::AnalysisBoxContainer::showAttributes() {
	for(auto box:boxes_) {
		box->showAttributes();
	}
}

GUI::AnalysisBox *GUI::AnalysisBoxContainer::getAnalysisBox(unsigned int index) {
    if(index>boxes_.size())
		return nullptr;
	return boxes_[index];
}

int GUI::AnalysisBoxContainer::getIndex(GUI::AnalysisBox *box) {
    for(unsigned int i=0; i<boxes_.size(); i++) {
		if(boxes_[i]==box)
			return i;
	}
	return -1;
}

GUI::AnalysisGraph GUI::AnalysisBoxContainer::getShownGraph() {
	return currentGraph_;
}

GUI::AnalysisVideo GUI::AnalysisBoxContainer::getShownVideo() {
	return currentVideo_;
}

GUI::AnalysisBox *GUI::AnalysisBoxContainer::insertBox(GUI::AnalysisBox *box, unsigned int index) {
	if(index>boxes_.size())
		return nullptr;

	v_boxes_->insertWidget(index,box);
	box->setTimer(timer_);
	box->setControlPanel(controlPanel_);
	box->setParentContainer(this);
	boxes_.insert(boxes_.begin()+index,box);

	QString objname=QString("x%1").arg((quintptr)box,QT_POINTER_SIZE * 2, 16, QChar('0'));
	box->setObjectName(objname);

	updateUi();

	return box;
}

void GUI::AnalysisBoxContainer::addVideo() {
	if(!parent_)
		return;

	if(!parent_->isRawVideoLoaded())
		return;

	if(parent_->getParentWindow()) {
		parent_->getParentWindow()->getStatusBar()->showMessage("Loading encoded video...");
	}

	auto filename=QFileDialog::getOpenFileName(this,"Open encoded video",QDir::homePath());

	if(filename.isEmpty()) {
		if(parent_->getParentWindow()) {
			parent_->getParentWindow()->getStatusBar()->showMessage("Aborted!",2000);
		}
		return;
	}

	QFileInfo fileToCheck(filename);

	if(!fileToCheck.exists()&&fileToCheck.isFile())
		return;

	auto command=new UndoRedo::AddVideo(this,filename);
	UndoRedo::UndoStack::getUndoStack().push(command);

	if(parent_->getParentWindow()) {
		parent_->getParentWindow()->getStatusBar()->showMessage("Loading encoded video...",3000);
	}
}

void GUI::AnalysisBoxContainer::createUi() {
	QVBoxLayout* v_content=new QVBoxLayout;
	v_boxes_=new QVBoxLayout;
	spacer_=new QSpacerItem(0,0,QSizePolicy::Expanding,QSizePolicy::Expanding);
	v_boxes_->addSpacerItem(spacer_);
	v_boxes_->setSpacing(0);

	v_content->addLayout(v_boxes_);

	button_addVideo_=new QPushButton("Add video");

	QString stylesheet1("QPushButton {"
	                    "color: rgb(255, 255, 255);"
	                    "border-color: rgb(0, 0, 0);"
	                    "background: rgb(140, 140, 140);"
	                    "border-width: 1px;"
	                    "border-color:rgb(0, 0, 0);"
	                    "border-style: outset;"
	                    "border-radius: 7;"
	                    "padding: 3px;"
	                    "font-size: 18px;"
	                    "padding-left: 5px;"
	                    "padding-right: 5px;"
	                    "}"
	                    "QPushButton:pressed {"
	                    "background-color: rgb(69, 62, 62);"
	                    "border-style: inset;"
	                    "}"
	                   );
	button_addVideo_->setFlat(true);
	button_addVideo_->setStyleSheet(stylesheet1);
	v_content->addSpacing(10);

	QHBoxLayout* h_button=new QHBoxLayout;
	h_button->addSpacing(10);

	h_button->addWidget(button_addVideo_);
	h_button->addSpacing(20);

	v_content->addLayout(h_button);
	v_content->addSpacing(15);

	setLayout(v_content);
}

void GUI::AnalysisBoxContainer::updateUi() {
	for(std::size_t i=0; i<boxes_.size(); i++) {
		if(i%2==0) {
			boxes_[i]->setStyleSheet("QFrame#"+boxes_[i]->objectName()
			                         +" {background-color:rgb(240,240,240);border-bottom-style:outset;border-bottom-color: black;border-bottom-width:1px;}");
		} else {
			boxes_[i]->setStyleSheet("QFrame#"+boxes_[i]->objectName()
			                         +" {background-color:rgb(250,250,250);border-bottom-style:outset;border-bottom-color: black;border-bottom-width:1px;}");
		}
		boxes_[i]->showGraph(currentGraph_);
		boxes_[i]->showAnalysisVideo(currentVideo_);
	}
	if(boxes_.size()>0) {
		resize(width(),boxes_.size()*boxes_[0]->height()+65);
	} else {
		resize(width(),65);
	}
}


