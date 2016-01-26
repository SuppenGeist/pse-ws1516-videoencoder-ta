#include <exception>

#include "MainWindow.h"
#include "QWidget.h"
#include "MainWindowMemento.h"
#include "Project.h"

MainWindow::MainWindow(QWidget* parent) {
}

Memento::MainWindowMemento MainWindow::getMemento() {
	throw "Not yet implemented";
}

void MainWindow::restore(MainWindowMemento memento) {
	throw "Not yet implemented";
}

void MainWindow::newProject() {
	throw "Not yet implemented";
}

void MainWindow::undo() {
	throw "Not yet implemented";
}

void MainWindow::saveAs() {
	throw "Not yet implemented";
}

void MainWindow::loadProject() {
	throw "Not yet implemented";
}

void MainWindow::saveProject() {
	throw "Not yet implemented";
}

void MainWindow::redo() {
	throw "Not yet implemented";
}

void MainWindow::createUi() {
	throw "Not yet implemented";
}

void MainWindow::connectActions() {
	throw "Not yet implemented";
}

void MainWindow::createMenuBar() {
	throw "Not yet implemented";
}

Model::Project& MainWindow::getProject() {
	throw "Not yet implemented";
}

