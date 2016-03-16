#include "testvideoloader.h"

void TestVideoLoader::init() {
	QString path_ = QFINDTESTDATA("blume.mp4");
	videoLoader_ = new Utility::VideoLoader(path_);
}

void TestVideoLoader::testgetCodec() {
	QVERIFY(videoLoader_->getCodec().compare("H.264"));
}

void TestVideoLoader::testgetAverageBitrate() {
	Model::AVVideo *avVideo_ = new Model::AVVideo();
	videoLoader_->loadVideo(avVideo_);
	while(!avVideo_->getNumberOfFrames());
	QVERIFY(videoLoader_->getAverageBitrate() / 1000 == 276); // average bitrate is in Bit/s not KBit/s
}

void TestVideoLoader::testloadVideo() {
	Model::AVVideo *avVideo_ = new Model::AVVideo();
	videoLoader_->loadVideo(avVideo_);
	while(!avVideo_->getNumberOfFrames());
	QVERIFY(avVideo_->getFrame(0)->height == 144);
	QVERIFY(avVideo_->getFps() == 25);
}
