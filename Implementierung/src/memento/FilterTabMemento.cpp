#include "FilterTabMemento.h"

#include <string>

#include "../model/FilterList.h"

Memento::FilterTabMemento::FilterTabMemento() {
}

Model::FilterList* Memento::FilterTabMemento::getFilterList() {
	return this->filterList;
}

void Memento::FilterTabMemento::setFilterList(Model::FilterList *filterList) {
	this->filterList = filterList;
}

bool Memento::FilterTabMemento::getWasApplied() {
	return this->wasApplied;
}

void Memento::FilterTabMemento::setWasApplied(bool wasApplied) {
	this->wasApplied = wasApplied;
}

int Memento::FilterTabMemento::getDisplayedFrame() {
	return this->displayedFrame;
}

void Memento::FilterTabMemento::setDisplayedFrame(int displayedFrame) {
	this->displayedFrame = displayedFrame;
}

std::string Memento::FilterTabMemento::getLoadedFile() {
	throw "Not yet implemented";
}

void Memento::FilterTabMemento::setLoadedFile(std::string loadedFile) {
	throw "Not yet implemented";
}
