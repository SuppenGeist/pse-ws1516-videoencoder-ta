#include "MainWindow.h"

#include <QWidget>
#include <QMainWindow>

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

}

Memento::MainWindowMemento GUI::MainWindow::getMemento() {
    Memento::MainWindowMemento memo;
    memo.setAnalysisTabMemento(analysisTab_->getMemento());
    memo.setFilterTabMemento(filterTab_->getMemento());
    memo.setSelectedTab(ui_->tab_tabs->currentIndex());
    return memo;
}

void GUI::MainWindow::restore(Memento::MainWindowMemento memento) {
    analysisTab_->restore(memento.getAnalysisTabMemento());
    filterTab_->restore(memento.getFilterTabMemento());
    ui_->tab_tabs->setCurrentIndex(memento.getSelectedTab());
}

void GUI::MainWindow::newProject() {
    loadedProject_ = new Model::Project(QString("new_Project"));
    loadedProject_->setPath(QString(""));
    createUi();
    UndoRedo::UndoStack::getUndoStack().clear();
}

void GUI::MainWindow::undo() {
    UndoRedo::UndoStack::getUndoStack().undo();
}

void GUI::MainWindow::saveAs() {
    if (loadedProject_->getPath().size()==0) {
        saveProject();
    } else {
       // Utility::
    }
}

void GUI::MainWindow::loadProject() {
	throw "Not yet implemented";
}

void GUI::MainWindow::saveProject() {
	throw "Not yet implemented";
}

void GUI::MainWindow::redo() {
	UndoRedo::UndoStack::getUndoStack().redo();
}

void GUI::MainWindow::createUi() {
    ui_ = new Ui::MainWindow;

    ui_->setupUi(this);

    statusbar_=ui_->statusbar;
    action_newProject_=ui_->actionNew;
    action_loadProject_=ui_->actionLoad;
    action_saveAs_=ui_->actionSaveAs;
    action_saveProject_=ui_->actionSave;
    action_redo_=ui_->actionRedo;
    action_undo_=ui_->actionUndo;
    filterTab_ = new GUI::FilterTab(ui_->filterTab);
    analysisTab_ = new GUI::AnalysisTab(ui_->analysisTab);
}

void GUI::MainWindow::connectActions() {
    connect(action_loadProject_,SIGNAL(triggered()),this,SLOT(loadProject()));
    connect(action_newProject_, SIGNAL(triggered()),this,SLOT(newProject()));
    connect(action_saveProject_,SIGNAL(triggered()),this, SLOT(saveProject()));
    connect(action_redo_,SIGNAL(triggered()),this, SLOT(redo()));
    connect(action_saveAs_,SIGNAL(triggered()),this, SLOT(saveAs()));
    connect(action_undo_,SIGNAL(triggered()),this, SLOT(undo()));


}

Model::Project* GUI::MainWindow::getProject() {
    return loadedProject_;
}


