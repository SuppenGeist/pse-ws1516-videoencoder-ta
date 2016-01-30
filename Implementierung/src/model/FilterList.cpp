#include "FilterList.h"

#include <string>
#include <vector>
#include <algorithm>

#include "Filter.h"

using namespace Model;

FilterList::FilterList() {
    filters = * new std::vector<Model::Filter*>;
}

Model::Filter* FilterList::getFilterByName(std::string name) {
    /*for(int i=0; i<filters.size; i++){
        if(filters.at(i).getName().compare(name) == 0){
        return actfilter;
        }
    }
    return 0;*/
}

void FilterList::removeFilter(std::string name) {
    //filters.erase(std::remove(filters.begin(), filters.end(), getFilterByName(name)), filters.end());
}

void FilterList::moveFilter(int oldPosition, int newPosition) {
    iter_swap(filters.begin() + oldPosition, filters.begin() + newPosition);
}

void FilterList::removeFilter(int position) {
    filters.erase(filters.begin()+ position);
}

void FilterList::addFilter(std::string name, int index) {
    /*if(name.compare("BlackWhiteFilter") == 0){
        filter = new BlackWhiteFilter();
    } else if(name.compare("BlendingFilter") == 0){
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
    }
    filters.insert(index, filter);*/
}

Model::Filter* FilterList::getFilterByIndex(int index) {
    return filters.at(index);
}

int FilterList::getIndex(std::string name) {
    /*int pos = std::find(filters.begin(), filters.end(), getFilterByName(name)) - filters.begin();
    if(pos >= filters.size()) {
        return "Filter not in list.";
    }
    return pos;*/
}
