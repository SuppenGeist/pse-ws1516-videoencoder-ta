#include "YuvVideo.h"

#include <QString>

#include "../utility/YuvType.h"
#include "../utility/Compression.h"

Model::YuvVideo::YuvVideo(QString path, Utility::YuvType type, Utility::Compression compression, int width, int height, int fps) {
}

QString Model::YuvVideo::getPath() {
	return this->path;
}

Utility::Compression Model::YuvVideo::getCompression() {
	throw "Not yet implemented";
}

Utility::YuvType Model::YuvVideo::getYuvType() {
	throw "Not yet implemented";
}

Model::AVVideo& Model::YuvVideo::getAvVideo() {
	throw "Not yet implemented";
}

GUI::Video& Model::YuvVideo::getVideo() {
	throw "Not yet implemented";
}

void Model::YuvVideo::loadVideo() {
	throw "Not yet implemented";
}
