#include "MainWindow.h"

#include <memory>

#include <QWidget>
#include <QMainWindow>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QFile>
#include <QDebug>
#include <QFileInfo>
#include <QHBoxLayout>
#include <QMessageBox>

#include "ui_mainwindow.h"
#include "FilterTab.h"
#include "AnalysisTab.h"
#include "../memento/MainWindowMemento.h"
#include "../undo_framework/UndoStack.h"
#include "../utility/ProjectReader.h"
#include "../utility/ProjectWriter.h"
#include "../model/Project.h"


GUI::MainWindow::MainWindow(QWidget* parent):QMainWindow(parent) {
	createUi();
	connectActions();

	loadedProject_=std::make_unique<Model::Project>();
}

std::unique_ptr<Memento::MainWindowMemento> GUI::MainWindow::getMemento() {
	auto memento=std::make_unique<Memento::MainWindowMemento>();
	memento->setAnalysisTabMemento(analysisTab_->getMemento());
	memento->setFilterTabMemento(filterTab_->getMemento());
	memento->setSelectedTab(tab_tabs_->currentIndex());
	return memento;
}

void GUI::MainWindow::restore(Memento::MainWindowMemento *memento) {
	analysisTab_->restore(memento->getAnalysisTabMemento());
	filterTab_->restore(memento->getFilterTabMemento());

	if(memento->getSelectedTab()>=0&&memento->getSelectedTab()<=1) {
		tab_tabs_->setCurrentIndex(memento->getSelectedTab());
	}
}

void GUI::MainWindow::newProject() {
	filterTab_->resetFilters();
	filterTab_->setRawVideo(nullptr);

	analysisTab_->setRawVideo(nullptr);

	loadedProject_=std::make_unique<Model::Project>();

	UndoRedo::UndoStack::getUndoStack().clear();
}

void GUI::MainWindow::undo() {
	UndoRedo::UndoStack::getUndoStack().undo();
}

void GUI::MainWindow::saveAs() {

	auto name=QFileDialog::getSaveFileName(this,"Save project",QDir::homePath());
	if(name.isEmpty())
		return;

	if(!name.endsWith(".vive")) {
		name+=".vive";
	}

	QFile file(name);
	QFileInfo info(file);
	loadedProject_->setName(info.fileName());
	loadedProject_->setPath(name);


	loadedProject_->setMemento(getMemento());

	Utility::ProjectWriter writer(loadedProject_.get());
	writer.saveProject();

	QMessageBox::information(this,"Project saved",
	                         "The project was successfully saved.",QMessageBox::Ok);
	setWindowTitle("Vive ["+loadedProject_->getName()+"]");
}

void GUI::MainWindow::loadProject() {
	auto filename=QFileDialog::getOpenFileName(this,"Open project",QDir::homePath(),"*.vive");

	try {
		Utility::ProjectReader reader(filename);
		loadedProject_=reader.readProject();
	} catch(std::invalid_argument& e) {
		return;
	}

	restore(&loadedProject_->getMemento());

	setWindowTitle("Vive ["+loadedProject_->getName()+"]");
}

void GUI::MainWindow::saveProject() {
	if(loadedProject_->getName().isEmpty()) {
		auto name=QFileDialog::getSaveFileName(this,"Save project",QDir::homePath());
		if(name.isEmpty())
			return;

		if(!name.endsWith(".vive")) {
			name+=".vive";
		}

		QFile file(name);
		QFileInfo info(file);
		loadedProject_->setName(info.fileName());
		loadedProject_->setPath(name);
	}

	loadedProject_->setMemento(getMemento());

	Utility::ProjectWriter writer(loadedProject_.get());
	writer.saveProject();

	QMessageBox::information(this,"Project saved",
	                         "The project was successfully saved.",QMessageBox::Ok);
	setWindowTitle("Vive ["+loadedProject_->getName()+"]");
}

void GUI::MainWindow::redo() {
	UndoRedo::UndoStack::getUndoStack().redo();
}

void GUI::MainWindow::createUi() {
	ui_ = new Ui::MainWindow;

	ui_->setupUi(this);

	statusbar_=ui_->statusbar;
	action_newProject_=ui_->actionNew;
    action_newProject_->setIcon(QIcon(":/icons/resources/icons/newProject.png"));
	action_loadProject_=ui_->actionLoad;
    action_loadProject_->setIcon(QIcon(":/icons/resources/icons/loadProject.png"));
	action_saveAs_=ui_->actionSaveAs;
	action_saveProject_=ui_->actionSave;
    action_saveProject_->setIcon(QIcon(":/icons/resources/icons/saveProject.png"));
	action_redo_=ui_->actionRedo;
    action_redo_->setIcon(QIcon(":/icons/resources/icons/redo.png"));
	action_undo_=ui_->actionUndo;
    action_undo_->setIcon(QIcon(":/icons/resources/icons/undo.png"));

	QVBoxLayout* v_content=new QVBoxLayout;
	v_content->addSpacing(10);

	QHBoxLayout* h_tabs=new QHBoxLayout;
	h_tabs->addSpacing(5);

	tab_tabs_=new QTabWidget;

	QWidget* wrapper_filter=new QWidget;
	wrapper_filter->setObjectName("filterWrapper");
	wrapper_filter->setStyleSheet("QWidget#filterWrapper {"
	                              "background-color:rgb(235,235,235);"
	                              "}");
	QVBoxLayout* v_filterTab=new QVBoxLayout;
	filterTab_=new FilterTab;
	filterTab_->setMainWindow(this);
	v_filterTab->addWidget(filterTab_);
	wrapper_filter->setLayout(v_filterTab);

	tab_tabs_->addTab(wrapper_filter,"Filters and artefacts");

	QWidget* wrapper_analysis=new QWidget;
	wrapper_analysis->setObjectName("analysisWrapper");
	wrapper_analysis->setStyleSheet("QWidget#analysisWrapper {"
	                                "background-color:rgb(235,235,235);"
	                                "}");
	QVBoxLayout* v_analysisTab=new QVBoxLayout;
	analysisTab_=new AnalysisTab;
	v_analysisTab->addWidget(analysisTab_);
	analysisTab_->setParentWindow(this);
	wrapper_analysis->setLayout(v_analysisTab);

	tab_tabs_->addTab(wrapper_analysis,"Analysis");

	h_tabs->addWidget(tab_tabs_);
	h_tabs->addSpacing(5);

	v_content->addLayout(h_tabs);

	centralWidget()->setLayout(v_content);
}

void GUI::MainWindow::connectActions() {
	connect(action_loadProject_,SIGNAL(triggered()),this,SLOT(loadProject()));
	connect(action_newProject_, SIGNAL(triggered()),this,SLOT(newProject()));
	connect(action_saveProject_,SIGNAL(triggered()),this, SLOT(saveProject()));
	connect(action_redo_,SIGNAL(triggered()),this, SLOT(redo()));
	connect(action_saveAs_,SIGNAL(triggered()),this, SLOT(saveAs()));
	connect(action_undo_,SIGNAL(triggered()),this, SLOT(undo()));
}

QStatusBar *GUI::MainWindow::getStatusBar() {
	return statusbar_;
}


