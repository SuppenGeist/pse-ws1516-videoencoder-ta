#include <exception>
#include <string>

#include "NegativeFilter.h"
#include "Filter.h"

Model::NegativeFilter::NegativeFilter() {
}

string Model::NegativeFilter::getFilterDescription() {
	throw "Not yet implemented";
}

string Model::NegativeFilter::getName() {
    return "Negative";
}

void Model::NegativeFilter::restoreFilter(QString description){
    throw "Not yet implemented";
}

QString Model::NegativeFilter::getSaveString(){

}
