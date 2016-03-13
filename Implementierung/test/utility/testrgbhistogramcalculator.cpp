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
    redHisto_=std::make_unique<Model::GraphVideo>();
    greenHisto_=std::make_unique<Model::GraphVideo>();
    blueHisto_=std::make_unique<Model::GraphVideo>();

    rgbHistoCalculator_=std::make_unique<Utility::RGBHistogramCalculator>(video_);
}

void TestRGBHistogramCalculator::testCalculate()
{
    //rgbHistoCalculator_->calculate(redHisto_.get(),greenHisto_.get(),blueHisto_.get());

    //QVERIFY(greenHisto_->getGraph(0)==);
}
