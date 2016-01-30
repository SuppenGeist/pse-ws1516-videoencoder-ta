#include "FilterList.h"

#include <string>
#include <vector>
#include <algorithm>

#include "filters/Filter.h"
#include "filters/BlackWhiteFilter.h"



Model::FilterList::FilterList() {
    filters = * new std::vector<Model::Filter*>;
}

Model::Filter* Model::FilterList::getFilterByName(std::string name) {
    for(unsigned int i=0; i < filters.size(); i++){
        if(filters.at(i)->getName().compare(name) == 0){
        return filters.at(i);
        }
    }

    return 0;
}

void Model::FilterList::removeFilter(std::string name) {
    filters.erase(std::remove(filters.begin(), filters.end(), getFilterByName(name)), filters.end());
}

void Model::FilterList::moveFilter(int oldPosition, int newPosition) {
    iter_swap(filters.begin() + oldPosition, filters.begin() + newPosition);
}

void Model::FilterList::removeFilter(int position) {
    filters.erase(filters.begin()+ position);
}

void Model::FilterList::addFilter(std::string name) {
    if(name.compare("BlackWhiteFilter") == 0){
        Model::BlackWhiteFilter* filter = new Model::BlackWhiteFilter();
        filters.push_back(filter);
    }/* else if(name.compare("BlendingFilter") == 0){
        filter = new BlendingFilter();
    } else if(name.compare("BlurFilter") == 0){
        filter = new BlurFilter();
    } else if(name.compare("BorderFilter") == 0){
        filter = new BorderFilter();
    } else if(name.compare("BrightnessFilter") == 0){
        filter = new BrightnessFilter();
    } else if(name.compare("ColorbalanceFilter") == 0){
        filter = new ColorbalanceFilter();
    } else if(name.compare("ContrastFilter") == 0){
        filter = new ContrastFilter();
    } else if(name.compare("GridFilter") == 0){
        filter = new GridFilter();
    } else if(name.compare("MirrorFilter") == 0){
        filter = new MirrorFilter();
    } else if(name.compare("NegativeFilter") == 0){
        filter = new NegativeFilter();
    } else if(name.compare("NoiseFilter") == 0){
        filter = new NoiseFilter();
    } else if(name.compare("PosterFilter") == 0){
        filter = new PosterFilter();
    } else if(name.compare("RGBFilter") == 0){
        filter = new RGBFilter();
    } else if(name.compare("PosterFilter") == 0){
        filter = new PosterFilter();
    } else if(name.compare("RotationFilter") == 0){
        filter = new RotationFilter();
    } else if(name.compare("SaturationFilter") == 0){
        filter = new SaturationFilter();
    } else if(name.compare("ScaleFilter") == 0){
        filter = new ScaleFilter();
    } else if(name.compare("SepiaFilter") == 0){
        filter = new SepiaFilter();
    } else if(name.compare("SharpnessFilter") == 0){
        filter = new SharpnessFilter();
    } else if(name.compare("VintageFilter") == 0){
        filter = new VintageFilter();
    } else if(name.compare("ZoomFilter") == 0){
        filter = new ZoomFilter();
    }*/

}

Model::Filter* Model::FilterList::getFilterByIndex(int index) {
    return filters.at(index);
}

int Model::FilterList::getIndex(std::string name) {
    unsigned int pos = std::find(filters.begin(), filters.end(), getFilterByName(name)) - filters.begin();
    if(pos >= filters.size()) {
        return -1;
    }
    return pos;
}
