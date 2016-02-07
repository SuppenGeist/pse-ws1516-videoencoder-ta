#include <exception>

#include "Yuv420FileSaver.h"
#include "../model/Video.h"
#include "YuvFileSaver.h"
#include <QDebug>

Utility::Yuv420FileSaver::Yuv420FileSaver(QString filename,
        Model::Video& video):YuvFileSaver(filename,video) {
}

void Utility::Yuv420FileSaver::save() {
	for(std::size_t k=0; k<video_->getNumberOfFrames(); k++) {
		QVector<unsigned char> uBuffer;
		QVector<unsigned char> vBuffer;
		auto frame_=video_->getFrame(k);

		for(int i=0; i<width_*height_; i+=4) {
			int y1=i/width_;
			int x1=i%width_;
			int y2=(i+1)/width_;
			int x2=(i+1)%width_;

			if(!frame_->valid(x1,y1)||!frame_->valid(x2,y2)) {
				qDebug()<<"Wrong pixel coordinates";
				continue;
			}


		}
	}
}

void Utility::Yuv420FileSaver::saveFrame(int index) {
	throw "Not yet implemented";
}


