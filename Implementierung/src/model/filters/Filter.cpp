#include "Filter.h"

#include <QString>

#include <string>
#include <memory>
#include <stdexcept>

#include "GrayscaleFilter.h"
#include "BlurFilter.h"
#include "BorderFilter.h"
#include "BrightnessFilter.h"
#include "ColorbalanceFilter.h"
#include "ContrastFilter.h"
#include "EdgeFilter.h"
#include "GridFilter.h"
#include "MirrorFilter.h"
#include "NegativeFilter.h"
#include "NoiseFilter.h"
#include "PosterFilter.h"
#include "RectangleFilter.h"
#include "RGBFilter.h"
#include "RotationFilter.h"
#include "SaturationFilter.h"
#include "ScaleFilter.h"
#include "SepiaFilter.h"
#include "SharpnessFilter.h"
#include "VintageFilter.h"
#include "ZoomFilter.h"

Model::Filter::Filter() {

}

Model::Filter::~Filter() {

}

std::unique_ptr<Model::Filter> Model::Filter::CreateFilter(QString filtername) {
	if(filtername==GrayscaleFilter::FILTERNAME) {
		return std::make_unique<GrayscaleFilter>();
	}  else if(filtername==BlurFilter::FILTERNAME) {
		return std::make_unique<BlurFilter>();
	} else if(filtername==BorderFilter::FILTERNAME) {
		return std::make_unique<BorderFilter>();
	} else if(filtername==BrightnessFilter::FILTERNAME) {
		return std::make_unique<BrightnessFilter>();
	} else if(filtername==ColorbalanceFilter::FILTERNAME) {
		return std::make_unique<ColorbalanceFilter>();
	} else if(filtername==ContrastFilter::FILTERNAME) {
		return std::make_unique<ContrastFilter>();
	} else if(filtername==EdgeFilter::FILTERNAME) {
		return std::make_unique<EdgeFilter>();
	} else if(filtername==GridFilter::FILTERNAME) {
		return std::make_unique<GridFilter>();
	} else if(filtername==MirrorFilter::FILTERNAME) {
		return std::make_unique<MirrorFilter>();
	} else if(filtername==NegativeFilter::FILTERNAME) {
		return std::make_unique<NegativeFilter>();
	} else if(filtername==NoiseFilter::FILTERNAME) {
		return std::make_unique<NoiseFilter>();
	} else if(filtername==PosterFilter::FILTERNAME) {
		return std::make_unique<PosterFilter>();
	} else if(filtername==RectangleFilter::FILTERNAME) {
		return std::make_unique<RectangleFilter>();
	} else if(filtername==RGBFilter::FILTERNAME) {
		return std::make_unique<RGBFilter>();
	} else if(filtername==RotationFilter::FILTERNAME) {
		return std::make_unique<RotationFilter>();
	} else if(filtername==SaturationFilter::FILTERNAME) {
		return std::make_unique<SaturationFilter>();
	} else if(filtername==ScaleFilter::FILTERNAME) {
		return std::make_unique<ScaleFilter>();
	} else if(filtername==SepiaFilter::FILTERNAME) {
		return std::make_unique<SepiaFilter>();
	} else if(filtername==SharpnessFilter::FILTERNAME) {
		return std::make_unique<SharpnessFilter>();
	} else if(filtername==VintageFilter::FILTERNAME) {
		return std::make_unique<VintageFilter>();
	} else if(filtername==ZoomFilter::FILTERNAME) {
		return std::make_unique<ZoomFilter>();
	}
	throw std::invalid_argument("Filter is not known");
}

