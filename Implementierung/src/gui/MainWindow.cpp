#include "MainWindow.h"

#include <QWidget>
#include <QMainWindow>

#include "ui_mainwindow.h"
#include "FilterTab.h"
#include "AnalysisTab.h"
#include "../memento/MainWindowMemento.h"
#include "../undo_framework/UndoStack.h"


GUI::MainWindow::MainWindow(QWidget* parent):QMainWindow(parent) {
	createUi();
	connectActions();

}

Memento::MainWindowMemento GUI::MainWindow::getMemento() {
	throw "Not yet implemented";
}

void GUI::MainWindow::restore(Memento::MainWindowMemento memento) {
	throw "Not yet implemented";
}

void GUI::MainWindow::newProject() {
	throw "Not yet implemented";
}

void GUI::MainWindow::undo() {
	UndoRedo::UndoStack::getUndoStack();
}

void GUI::MainWindow::saveAs() {
	throw "Not yet implemented";
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
	ui = new Ui::MainWindow;

	ui->setupUi(this);

	statusbar=ui->statusbar;
	action_newProject=ui->actionNew;
	action_loadProject=ui->actionLoad;
	action_saveAs=ui->actionSaveAs;
	action_saveProject=ui->actionSave;
	action_redo=ui->actionRedo;
	action_undo=ui->actionUndo;
    filterTab = new GUI::FilterTab(ui->filterTab);
    analysisTab = new GUI::AnalysisTab(ui->analysisTab);

}

void GUI::MainWindow::connectActions() {
	connect(action_loadProject,SIGNAL(triggered()),this,SLOT(loadProject()));
	connect(action_newProject, SIGNAL(triggered()),this,SLOT(newProject()));
	connect(action_saveProject,SIGNAL(triggered()),this, SLOT(saveProject()));
	connect(action_redo,SIGNAL(triggered()),this, SLOT(redo()));
	connect(action_saveAs,SIGNAL(triggered()),this, SLOT(saveAs()));
	connect(action_undo,SIGNAL(triggered()),this, SLOT(undo()));


}

Model::Project* GUI::MainWindow::getProject() {
	throw "Not yet implemented";
}


