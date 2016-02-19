#include "Project.h"

#include "../memento/MainWindowMemento.h"

Model::Project::Project(QString name):name_(name) {
}

QString Model::Project::getName() {
	return name_;
}

Memento::MainWindowMemento& Model::Project::getMemento() {
	return *memento_;
}

void Model::Project::setMemento(std::unique_ptr<Memento::MainWindowMemento> memento) {
	memento_=std::move(memento);
}

void Model::Project::setPath(QString path) {
	path_ = path;
}

void Model::Project::setName(QString name) {
	name_=name;
}

QString Model::Project::getPath() {
	return path_;
}

