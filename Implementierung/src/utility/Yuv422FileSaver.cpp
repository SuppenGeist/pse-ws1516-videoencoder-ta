#include "Yuv422FileSaver.h"

#include <stdexcept>
#include <vector>

#include <QString>
#include <QDebug>

#include "../model/Video.h"
#include "Compression.h"
#include "Yuv422Vector.h"
#include "YuvFileSaver.h"

Utility::Yuv422FileSaver::Yuv422FileSaver(QString filename, Model::Video& video,
        Utility::Compression compression):YuvFileSaver(filename,video),compression_(compression) {

}

void Utility::Yuv422FileSaver::save() {
    safer_=std::thread(&Yuv422FileSaver::saveP,this);
    safer_.detach();
}

void Utility::Yuv422FileSaver::savePacked() {
	for(std::size_t k=0; k<video_->getNumberOfFrames(); k++) {
		auto frame=video_->getFrame(k);
		for(int i=0; i<width_*height_; i+=2) {
			int y1=i/width_;
			int x1=i%width_;
			int y2=(i+1)/width_;
			int x2=(i+1)%width_;

			if(!frame->valid(x1,y1)||!frame->valid(x2,y2)) {
				qDebug()<<"Wrong pixel coordinates";
				continue;
			}

			auto vec=Rgb888ToYuv422(frame->pixel(x1,y1),frame->pixel(x2,y2));
			dataStream_<<vec.getU()<<vec.getY1()<<vec.getV()<<vec.getY2();
		}
	}
}

void Utility::Yuv422FileSaver::savePlanar() {
	for(std::size_t k=0; k<video_->getNumberOfFrames(); k++) {
		QVector<unsigned char> uBuffer;
		QVector<unsigned char> vBuffer;
		auto frame=video_->getFrame(k);
		for(int i=0; i<width_*height_; i+=2) {
			int y1=i/width_;
			int x1=i%width_;
			int y2=(i+1)/width_;
			int x2=(i+1)%width_;

			if(!frame->valid(x1,y1)||!frame->valid(x2,y2)) {
				qDebug()<<"Wrong pixel coordinates";
				continue;
			}

			auto vec=Rgb888ToYuv422(frame->pixel(x1,y1),frame->pixel(x2,y2));
			dataStream_<<vec.getY1()<<vec.getY2();
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

void Utility::Yuv422FileSaver::saveP()
{
    if(compression_==Compression::PACKED) {
        savePacked();
    } else if(compression_==Compression::PLANAR) {
        savePlanar();
    } else {
        throw std::logic_error("Should not get here");
    }
}

Utility::Yuv422Vector Utility::Yuv422FileSaver::Rgb888ToYuv422(QRgb pixel1, QRgb pixel2) {
	int u = RgbToU(pixel1);
	int y1= RgbToY(pixel1);
	int v = RgbToV(pixel1);
	int y2= RgbToY(pixel2);

	return Utility::Yuv422Vector(u,y1,v,y2);
}
