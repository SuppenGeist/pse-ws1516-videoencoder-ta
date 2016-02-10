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
		auto frame_=video_->getFrame(k);
		unsigned char frameBuffer_[width_*height_*2];
		for(int i=0; i<width_*height_; i++) {
			int y1=i/width_;
			int x1=i%width_;
			if(!frame_->valid(x1,y1)) {
				qDebug()<<"Wrong pixel coordinates";
				continue;
			}
			auto pixel1 = frame_->pixel(x1,y1);

			int y = RgbToY(pixel1);
			int u = RgbToU(pixel1);
			int v = RgbToV(pixel1);

			int offset1=(y1/2)*(width_/2)+(x1/2)+width_*height_;
			frameBuffer_[i] = y;
			frameBuffer_[offset1] = u;
			frameBuffer_[offset1+(width_*height_*1/4)] = v;
		}
		for(int j=0; j<width_*height_*1.5; j++) {
			dataStream_<<frameBuffer_[j];
		}
	}
}

/*void Utility::Yuv420FileSaver::saveFrame(int index) {

}
*/

