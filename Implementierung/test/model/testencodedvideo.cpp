#include "testencodedvideo.h"

void TestEncodedVideo::init() {
    QString path_ = QFINDTESTDATA("SampleVideo_360x240_2mb.mp4");
    encodedVideo_ = new Model::EncodedVideo(path_);
    videoLoader_ = new Utility::VideoLoader(path_);
}

void TestEncodedVideo::testgetCodec(){
    QVERIFY(encodedVideo_->getCodec().compare("H.264"));
}


void TestEncodedVideo::testgetAverageBitrate(){
    QVERIFY(encodedVideo_->getAverageBitrate()== videoLoader_->getAverageBitrate());
}
