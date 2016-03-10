#include "testrgbhistogramcalculator.h"

void TestRGBHistogramCalculator::init()
{
    int width = 32;
    int height = 32;
    std::unique_ptr<QImage> image_(new QImage(height,width,QImage::Format_RGB888));


    for(int y=0;y<height;y++) {
        for(int x=0;x<width;x++) {
            image_->setPixel(x,y, qRgb(x*x % 256,y*y % 256, x*y % 256));
        }
    }
    video_=Model::Video();
    video_.appendFrame(std::move(image_));
    red_= new Model::GraphVideo();
    green_= new Model::GraphVideo();
    blue_= new Model::GraphVideo();
    rgbHistogramCalculator_ = new Utility::RGBHistogramCalculator(video_);
}

void TestRGBHistogramCalculator::testCalculate()
{
    //rgbHistogramCalculator_->calculate(red_,green_,blue_);
}
