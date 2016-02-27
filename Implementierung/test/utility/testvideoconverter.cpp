#include "testvideoconverter.h"

#include <memory>

#include "../../src/utility/VideoConverter.h"

void TestVideoConverter::init() {
    int width = 32;
    int height = 32;
    image_ = new QImage(height,width,QImage::Format_RGB888);
    frame_ = av_frame_alloc();
    frame_->width=width;
    frame_->height=height;
    frame_->format=AV_PIX_FMT_RGB24;

    int size=avpicture_get_size(AV_PIX_FMT_RGB24,width,height);
    uint8_t* data=(uint8_t*)av_malloc(size);

    for(int y=0;y<height;y++) {
        for(int x=0;x<width;x++) {
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
}
void TestVideoConverter::testConvertAVFrameToQImage() {
    std::unique_ptr<QImage> tmpImage = Utility::VideoConverter::convertAVFrameToQImage(*frame_);
    QVERIFY(tmpImage->height()==image_->height());
    QVERIFY(tmpImage->width()==image_->width());
    for(int y = 0; y < image_->height(); y++) {
        for(int x = 0; x < image_->width(); x++) {
            QVERIFY(image_->pixel(y,x) == tmpImage->pixel(y,x));
        }
    }
    tmpImage.release();
}
void TestVideoConverter::testConvertQImageToAVFrame() {
    AVFrame* tmpFrame = Utility::VideoConverter::convertQImageToAVFrame(*image_);
    QVERIFY(tmpFrame->height==image_->height());
    QVERIFY(tmpFrame->width==image_->width());
    for (int y = 0; y < tmpFrame->height; y++) {
        for (int x = 0; x < tmpFrame->width; x++) {
            QVERIFY(tmpFrame->data[0][y * tmpFrame->linesize[0] + x] == frame_->data[0][y * frame_->linesize[0] + x]);
        }
    }
    for (int y = 0; y < tmpFrame->height/2; y++) {
        for (int x = 0; x < tmpFrame->width/2; x++) {
           // QVERIFY((int) tmpFrame->data[1][y * tmpFrame->linesize[1] + x] == (int) frame_->data[1][y * frame_->linesize[1] + x]);
           // QVERIFY((int) tmpFrame->data[2][y * tmpFrame->linesize[2] + x] == (int) frame_->data[2][y * frame_->linesize[2] + x]);
        }
    }
}
