#include "testbitratecalculator.h"

#include <memory>

void TestBitrateCalculator::init() {
	int width = 32;
	int height = 32;
	QImage* image_ = new QImage(height,width,QImage::Format_RGB888);
	frame_ = av_frame_alloc();
	frame_->width=width;
	frame_->height=height;
	frame_->format=AV_PIX_FMT_RGB24;

	int size=avpicture_get_size(AV_PIX_FMT_RGB24,width,height);
	uint8_t* data=(uint8_t*)av_malloc(size);

	for(int y=0; y<height; y++) {
		for(int x=0; x<width; x++) {
			image_->setPixel(x,y, qRgb(x*x % 256,y*y % 256, x*y % 256));
			auto pixel=image_->pixel(x,y);
			data[y*3*width+3*x]=qRed(pixel);
			data[y*3*width+3*x+1]=qGreen(pixel);
			data[y*3*width+3*x+2]=qBlue(pixel);
		}
	}
	avpicture_fill((AVPicture*)frame_,data,AV_PIX_FMT_RGB24,width,height);

	avVideo_= new Model::AVVideo();
	avVideo_->appendFrame(frame_);
	graph_= new Model::Graph();
	bitrateCalculator_=std::make_unique<Utility::BitrateCalculator>(*avVideo_);
	bitrate_=std::make_unique<Model::Graph>();

}

void TestBitrateCalculator::testCalculate() {
	std::size_t i=0;
	for(; i<avVideo_->getNumberOfFrames(); i++) {
		graph_->setValue(i,avVideo_->getFrame(i)->pkt_size*8/(double)1000);
	}


	bitrateCalculator_->calculate(bitrate_.get());
	QVERIFY(graph_->getBiggestValue()==bitrate_->getBiggestValue());

}
