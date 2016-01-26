#include <exception>
#include <string>
#include <vector>

#include "FilterList.h"
#include "FilterApplier.h"
#include "Filter.h"
#include "FilterReset.h"
#include "LoadFilterconfig.h"

FilterList::FilterList() {
}

Model::Filter* FilterList::getFilterByName(string name) {
	throw "Not yet implemented";
}

void FilterList::removeFilter(string name) {
	throw "Not yet implemented";
}

void FilterList::moveFilter(int oldPosition, int newPosition) {
	throw "Not yet implemented";
}

void FilterList::removeFilter(int position) {
	throw "Not yet implemented";
}

void FilterList::addFilter(string name, int index) {
	throw "Not yet implemented";
}

Model::Filter* FilterList::getFIlterByIndex(int index) {
	throw "Not yet implemented";
}

int FilterList::getIndex(string name) {
	throw "Not yet implemented";
}

