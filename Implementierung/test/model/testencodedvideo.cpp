#include "testencodedvideo.h"

void TestEncodedVideo::init() {
	QString path_ = QFINDTESTDATA("blume.mp4");
	encodedVideo_ = new Model::EncodedVideo(path_);
}

void TestEncodedVideo::testgetCodec() {
	//QVERIFY(encodedVideo_->getCodec().compare("H.264"));
}


void TestEncodedVideo::testgetAverageBitrate() {
	//QVERIFY(encodedVideo_->getAverageBitrate()==306);
}
