#include <exception>
#include <string>

#include "Filter.h"
//#include "RemoveFilter.h"


string Model::Filter::getName() {
    return "Filter";
}

string Model::Filter::getFilterDescription(){
    throw "Not yet implemented";
}

void Model::Filter::restoreFilter(QString description){
    throw "Not yet implemented";
}

QString Model::Filter::getSaveString(){

}
