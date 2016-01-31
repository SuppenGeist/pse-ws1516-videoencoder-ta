#include <QString>

#include "BlackWhiteFilter.h"
//#include "../Filter.h"

Model::BlackWhiteFilter::BlackWhiteFilter() {

}

std::string Model::BlackWhiteFilter::getName() {
    return "BlackWhite";
}

std::string Model::BlackWhiteFilter::getFilterDescription() {
	throw "Not yet implemented";
}
void Model::BlackWhiteFilter::restoreFilter(QString description){
    throw "Not yet implemented";
}

QString Model::BlackWhiteFilter::getSaveString(){

}
