#include "FilterList.h"

#include <string>
#include <vector>
#include <algorithm>

#include "filters/Filter.h"
#include "filters/BlackWhiteFilter.h"
#include "filters/BlendingFilter.h"
#include "filters/BlurFilter.h"
#include "filters/BorderFilter.h"
#include "filters/BrightnessFilter.h"
#include "filters/ColorbalanceFilter.h"
#include "filters/ContrastFilter.h"
#include "filters/EdgeFilter.h"
#include "filters/GridFilter.h"
#include "filters/MirrorFilter.h"
#include "filters/NegativeFilter.h"
#include "filters/NoiseFilter.h"
#include "filters/PosterFilter.h"
#include "filters/RectangleFilter.h"
#include "filters/RGBFilter.h"
#include "filters/RotationFilter.h"
#include "filters/SaturationFilter.h"
#include "filters/ScaleFilter.h"
#include "filters/SepiaFilter.h"
#include "filters/SharpnessFilter.h"
#include "filters/VintageFilter.h"
#include "filters/ZoomFilter.h"

Model::FilterList::FilterList() {
	filters = * new std::vector<Model::Filter*>;
}

Model::Filter* Model::FilterList::getFilterByName(std::string name) {
	for(unsigned int i=0; i < filters.size(); i++) {
		if(filters.at(i)->getName().compare(name) == 0) {
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
	if(name.compare("BlackWhite") == 0) {
		Model::BlackWhiteFilter* filter = new Model::BlackWhiteFilter();
		filters.push_back(filter);
	} else if(name.compare("Blending") == 0) {
		Model::BlendingFilter* filter = new Model::BlendingFilter();
		filters.push_back(filter);
	} else if(name.compare("Blur") == 0) {
		Model::BlurFilter* filter = new Model::BlurFilter();
		filters.push_back(filter);
	} else if(name.compare("Border") == 0) {
		Model::BorderFilter* filter = new Model::BorderFilter();
		filters.push_back(filter);
	} else if(name.compare("Brightness") == 0) {
		Model::BrightnessFilter* filter = new Model::BrightnessFilter();
		filters.push_back(filter);
	} else if(name.compare("Colorbalance") == 0) {
		Model::ColorbalanceFilter* filter = new Model::ColorbalanceFilter();
		filters.push_back(filter);
	} else if(name.compare("Contrast") == 0) {
		Model::ContrastFilter* filter = new Model::ContrastFilter();
		filters.push_back(filter);
	} else if(name.compare("Grid") == 0) {
		Model::GridFilter* filter = new Model::GridFilter();
		filters.push_back(filter);
	} else if(name.compare("Mirror") == 0) {
		Model::MirrorFilter* filter = new Model::MirrorFilter();
		filters.push_back(filter);
	} else if(name.compare("Negative") == 0) {
		Model::NegativeFilter* filter = new Model::NegativeFilter();
		filters.push_back(filter);
	} else if(name.compare("Noise") == 0) {
		Model::NoiseFilter* filter = new Model::NoiseFilter();
		filters.push_back(filter);
	} else if(name.compare("Poster") == 0) {
		Model::PosterFilter* filter = new Model::PosterFilter();
		filters.push_back(filter);
	} else if(name.compare("RGB") == 0) {
		Model::RGBFilter* filter = new Model::RGBFilter();
		filters.push_back(filter);
	} else if(name.compare("Poster") == 0) {
		Model::PosterFilter* filter = new Model::PosterFilter();
		filters.push_back(filter);
	} else if(name.compare("Rotation") == 0) {
		Model::RotationFilter* filter = new Model::RotationFilter();
		filters.push_back(filter);
	} else if(name.compare("Saturation") == 0) {
		Model::SaturationFilter* filter = new Model::SaturationFilter();
		filters.push_back(filter);
	} else if(name.compare("Scale") == 0) {
		Model::ScaleFilter* filter = new Model::ScaleFilter();
		filters.push_back(filter);
	} else if(name.compare("Sepia") == 0) {
		Model::SepiaFilter* filter = new Model::SepiaFilter();
		filters.push_back(filter);
	} else if(name.compare("Sharpness") == 0) {
		Model::SharpnessFilter* filter = new Model::SharpnessFilter();
		filters.push_back(filter);
	} else if(name.compare("Vintage") == 0) {
		Model::VintageFilter* filter = new Model::VintageFilter();
		filters.push_back(filter);
	} else if(name.compare("Zoom") == 0) {
		Model::ZoomFilter* filter = new Model::ZoomFilter();
		filters.push_back(filter);
	}

}

Model::Filter* Model::FilterList::getFilterByIndex(int index) {
	return filters.at(index);
}

int Model::FilterList::getIndex(std::string name) {
	unsigned int pos = std::find(filters.begin(), filters.end(),
	                             getFilterByName(name)) - filters.begin();
	if(pos >= filters.size()) {
		return -1;
	}
	return pos;
}
