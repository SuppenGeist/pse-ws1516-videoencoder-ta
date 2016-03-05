#include "testvideoloader.h"

void TestVideoLoader::init(){
    QString path_ = QFINDTESTDATA("blume.mp4");
    videoLoader_ = new Utility::VideoLoader(path_);
}

void TestVideoLoader::testgetCodec(){
    QVERIFY(videoLoader_->getCodec().compare("H.264"));
}

void TestVideoLoader::testgetAverageBitrate(){
    //QVERIFY(videoLoader_->getAverageBitrate()==306);
}

