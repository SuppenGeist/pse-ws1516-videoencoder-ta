#include "Filter.h"

#include <QString>

#include <string>
#include <memory>
#include <stdexcept>

#include "BlackWhiteFilter.h"

Model::Filter::Filter()
{

}

Model::Filter::~Filter()
{

}

std::unique_ptr<Model::Filter> Model::Filter::createFilter(QString filtername) {
    if(filtername==BlackWhiteFilter::FILTERNAME) {
        return std::make_unique<BlackWhiteFilter>();
    }
    throw std::invalid_argument("Filter is not known");
}

