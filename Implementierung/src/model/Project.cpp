#include "Project.h"

//#include "MainWindow.h"
#include "../memento/MainWindowMemento.h"

Model::Project::Project(QString name) {
}

QString Model::Project::getName() {
	return this->name;
}

Memento::MainWindowMemento& Model::Project::getMemento() {
	throw "Not yet implemented";
}

void Model::Project::setMemento(Memento::MainWindowMemento memento) {
	throw "Not yet implemented";
}

void Model::Project::setPath(QString path) {
	this->path = path;
}

QString Model::Project::getPath() {
	return this->path;
}

