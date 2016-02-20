#include <exception>

#include "Yuv411FileSaver.h"
#include "../model/Video.h"
#include "Compression.h"
#include "Yuv411Vector.h"
#include "YuvFileSaver.h"
#include <QDebug>
#include <QFileInfo>


Utility::Yuv411FileSaver::Yuv411FileSaver(QString filename, Model::Video& video,
        Utility::Compression compression, GUI::FilterTab *filterTab):YuvFileSaver(filename,video),
	compression_(compression),filterTab_(filterTab),isRunning_(false) {

}

Utility::Yuv411FileSaver::~Yuv411FileSaver() {
	isRunning_=false;
	if(safer_.joinable()) {
		safer_.join();
	}
}

void Utility::Yuv411FileSaver::save() {
	safer_=std::thread(&Yuv411FileSaver::saveP,this);
	safer_.detach();
}

void Utility::Yuv411FileSaver::savePacked() {
	for(std::size_t k=0; k<video_->getNumberOfFrames(); k++) {
		auto frame_=video_->getFrame(k);
		for(int i=0; i<width_*height_; i+=4) {
			int y1=i/width_;
			int x1=i%width_;
			int y2=(i+1)/width_;
			int x2=(i+1)%width_;
			int y3=(i+2)/width_;
			int x3=(i+2)%width_;
			int y4=(i+4)/width_;
			int x4=(i+4)%width_;

			if(!frame_->valid(x1,y1)||!frame_->valid(x2,y2)|!frame_->valid(x3,y3)||!frame_->valid(x4,y4)) {
				qDebug()<<"Wrong pixel coordinates";
				continue;
			}
			auto vec=Rgb888ToYuv411(frame_->pixel(x1,y1),frame_->pixel(x2,y2),frame_->pixel(x3,y3),
			                        frame_->pixel(x4,y4));
			dataStream_<<vec.getU()<<vec.getY1()<<vec.getY2()<<vec.getV()<<vec.getY3()<<vec.getY4();
		}
	}
}

void Utility::Yuv411FileSaver::savePlanar() {
	for(std::size_t k=0; k<video_->getNumberOfFrames(); k++) {
		QVector<unsigned char> uBuffer;
		QVector<unsigned char> vBuffer;
		auto frame_=video_->getFrame(k);

		for(int i=0; i<width_*height_; i+=4) {
			int y1=i/width_;
			int x1=i%width_;
			int y2=(i+1)/width_;
			int x2=(i+1)%width_;
			int y3=(i+2)/width_;
			int x3=(i+2)%width_;
			int y4=(i+4)/width_;
			int x4=(i+4)%width_;

			if(!frame_->valid(x1,y1)||!frame_->valid(x2,y2)|!frame_->valid(x3,y3)||!frame_->valid(x4,y4)) {
				qDebug()<<"Wrong pixel coordinates";
				continue;
			}
			auto vec=Rgb888ToYuv411(frame_->pixel(x1,y1),frame_->pixel(x2,y2),frame_->pixel(x3,y3),
			                        frame_->pixel(x4,y4));
			dataStream_<<vec.getY1()<<vec.getY2()<<vec.getY3()<<vec.getY4();
			uBuffer.push_back(vec.getV());
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

void Utility::Yuv411FileSaver::saveP() {
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

Utility::Yuv411Vector Utility::Yuv411FileSaver::Rgb888ToYuv411(QRgb pixel1, QRgb pixel2,
        QRgb pixel3, QRgb pixel4) {
	int u = RgbToU(pixel1);
	int y1= RgbToY(pixel1);
	int y2= RgbToY(pixel2);
	int v = RgbToV(pixel1);
	int y3= RgbToU(pixel3);
	int y4= RgbToU(pixel4);

	return Utility::Yuv411Vector(u,y1,y2,v,y3,y4);
}


