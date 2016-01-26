#include <exception>

#include "Project.h"
#include "MainWindow.h"
#include "MainWindowMemento.h"

Project::Project(QString name) {
}

QString Project::getName() {
	return this->name;
}

Memento::MainWindowMemento& Project::getMemento() {
	throw "Not yet implemented";
}

void Project::setMemento(MainWindowMemento memento) {
	throw "Not yet implemented";
}

void Project::setPath(QString path) {
	this->path = path;
}

QString Project::getPath() {
	return this->path;
}

