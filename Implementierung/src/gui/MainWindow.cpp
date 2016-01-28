#include "MainWindow.h"
#include "QWidget.h"
#include "memento/MainWindowMemento.h"
#include "model/Project.h"
#include "ui_mainwindow.h"
GUI::MainWindow::MainWindow(QWidget* parent) {
    ui = new Ui::MainWindow;

    ui->setupUi(this);
    statusbar=ui->statusbar;
    action_newProject=ui->actionNew;
    action_loadProject=ui->actionLoad;
    action_saveAs=ui->actionSaveAs;
    action_saveProject=ui->actionSave;
    action_redo=ui->actionRedo;
    action_undo=ui->actionUndo;
    connectActions();

}

/*Memento::MainWindowMemento MainWindow::getMemento() {
	throw "Not yet implemented";

}

void GUI::MainWindow::restore(MainWindowMemento memento) {
	throw "Not yet implemented";
}
*/
void GUI::MainWindow::newProject() {
	throw "Not yet implemented";
}

void GUI::MainWindow::undo() {
	throw "Not yet implemented";
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
	throw "Not yet implemented";
}

void GUI::MainWindow::createUi() {
	throw "Not yet implemented";
}

void GUI::MainWindow::connectActions() {
    connect(action_loadProject,SIGNAL(triggered()),this,SLOT(loadProject()));
    connect(action_newProject, SIGNAL(triggered()),this,SLOT(newProject()));
    connect(action_saveProject,SIGNAL(triggered()),this, SLOT(saveProject()));
    connect(action_redo,SIGNAL(triggered()),this, SLOT(redo()));
    connect(action_saveAs,SIGNAL(triggered()),this, SLOT(saveAs()));
    connect(action_undo,SIGNAL(triggered()),this, SLOT(undo()));

}
/*
void MainWindow::createMenuBar() {
	throw "Not yet implemented";
}

Model::Project& MainWindow::getProject() {
	throw "Not yet implemented";
}

*/
