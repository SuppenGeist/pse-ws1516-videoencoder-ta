#include <exception>

#include "Yuv444FileSaver.h"
#include "../model/Video.h"
#include "Compression.h"
#include "Yuv444Vector.h"
#include "YuvFileSaver.h"
#include <QDebug>
#include <QFileInfo>

Utility::Yuv444FileSaver::Yuv444FileSaver(QString filename, Model::Video& video,
        Compression compression, GUI::FilterTab *filterTab):YuvFileSaver(filename,video),
	compression_(compression),filterTab_(filterTab),isRunning_(false) {

}

Utility::Yuv444FileSaver::~Yuv444FileSaver() {
	isRunning_=false;
	if(safer_.joinable()) {
		safer_.join();
	}
}

void Utility::Yuv444FileSaver::save() {
	safer_=std::thread(&Yuv444FileSaver::saveP,this);
	safer_.detach();
}

void Utility::Yuv444FileSaver::savePacked() {
	for(std::size_t k=0; k<video_->getNumberOfFrames()&&isRunning_; k++) {
		auto frame_=video_->getFrame(k);
		for(int i=0; i<width_*height_; i++) {
			int y1=i/width_;
			int x1=i%width_;

			if(!frame_->valid(x1,y1)) {
				qDebug()<<"Wrong pixel coordinates";
				continue;
			}
			auto vec=Rgb888ToYuv444(frame_->pixel(x1,y1));
			dataStream_<<vec.getY()<<vec.getU()<<vec.getV();
		}
	}
}

void Utility::Yuv444FileSaver::savePlanar() {
	for(std::size_t k=0; k<video_->getNumberOfFrames()&&isRunning_; k++) {
		QVector<unsigned char> uBuffer;
		QVector<unsigned char> vBuffer;
		auto frame_=video_->getFrame(k);

		for(int i=0; i<width_*height_; i++) {
			int y1=i/width_;
			int x1=i%width_;

			if(!frame_->valid(x1,y1)) {
				qDebug()<<"Wrong pixel coordinates";
				continue;
			}
			auto vec=Rgb888ToYuv444(frame_->pixel(x1,y1));
			dataStream_<<vec.getY();
			uBuffer.push_back(vec.getU());
			vBuffer.push_back(vec.getV());
		}
		while (!uBuffer.isEmpty()) {
			dataStream_<<uBuffer.takeFirst();
		}
		while (!vBuffer.isEmpty()) {
			dataStream_<<vBuffer.takeFirst();
		}
	}

}

void Utility::Yuv444FileSaver::saveP() {
	isRunning_=true;
	if(compression_==Compression::PACKED) {
		savePacked();
	} else if(compression_==Compression::PLANAR) {
		savePlanar();
	} else {
		isRunning_=false;
		throw std::logic_error("Should not get here");
	}
	bool buffer=isRunning_;
    isRunning_=false;
    filterTab_->saveComplete(buffer,QFileInfo(file_).fileName(),video_->getWidth(),video_->getHeight());
}

Utility::Yuv444Vector Utility::Yuv444FileSaver::Rgb888ToYuv444(QRgb pixel1) {
	int y = RgbToY(pixel1);
	int u = RgbToU(pixel1);
	int v = RgbToV(pixel1);

	return Utility::Yuv444Vector(y,u,v);
}


