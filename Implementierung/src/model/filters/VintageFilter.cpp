#include <exception>
#include <string>

#include "VintageFilter.h"
#include "Filter.h"

Model::VintageFilter::VintageFilter() {
}

string Model::VintageFilter::getName() {
    return "Vintage";
}

string Model::VintageFilter::getFilterDescription() {
    string str = "curves=vintage";
    return str;
}

void Model::VintageFilter::restoreFilter(QString description){
//nothing to save
}

QString Model::VintageFilter::getSaveString(){
//nothing to save
}
