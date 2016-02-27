#include "testyuvvideo.h"
#include "../../src/utility/YuvType.h"
#include "../../src/utility/Compression.h"

void TestYuvVideo::init() {
    QString path_ = QFINDTESTDATA("akiyo_cif.y4m");
    Utility::YuvType yuvType_ = Utility::YuvType::YUV420;
    Utility::Compression compression_ =  Utility::Compression::PACKED;
    yuvVideo_ = new Model::YuvVideo(path_,yuvType_,compression_,352,288,30);

}

void TestYuvVideo::testgetCompression(){
QVERIFY(yuvVideo_->getCompression()==Utility::Compression::PACKED);
}

void TestYuvVideo::testgetYuvType(){
QVERIFY(yuvVideo_->getYuvType()==Utility::YuvType::YUV420);
}

void TestYuvVideo::testgetWidth(){
QVERIFY(yuvVideo_->getWidth()==352);
}

void TestYuvVideo::testgetHeight(){
QVERIFY(yuvVideo_->getHeight()==288);
}

void TestYuvVideo::tesgetFps(){
QVERIFY(yuvVideo_->getFps()==30);
}
