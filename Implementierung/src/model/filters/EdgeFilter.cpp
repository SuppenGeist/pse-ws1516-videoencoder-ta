
#include <string>

#include "EdgeFilter.h"
#include "Filter.h"

Model::EdgeFilter::EdgeFilter() {
}

string Model::EdgeFilter::getFilterDescription() {
	throw "Not yet implemented";
}

string Model::EdgeFilter::getName() {
    return "Edge";
}

void Model::EdgeFilter::restoreFilter(QString description){
    throw "Not yet implemented";
}

QString Model::EdgeFilter::getSaveString(){

}
