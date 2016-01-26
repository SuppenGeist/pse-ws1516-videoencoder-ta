#include <exception>

#include "VideoLoader.h"
#include "AVVideo.h"

VideoLoader::VideoLoader(QString path) {
}

std::uinque_ptr<Model::AVVideo> VideoLoader::loadVideo() {
	throw "Not yet implemented";
}

