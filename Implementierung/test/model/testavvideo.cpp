#include "testavvideo.h"

void TestAVVideo::init()
{
    avvideo_=Model::AVVideo(10);
}

void TestAVVideo::testFPS() {
    const int testValue1=0;
    avvideo_.setFps(testValue1);
    QVERIFY(testValue1 == avvideo_.getFps());

    const int testValue2=30;
    avvideo_.setFps(testValue2);
    QVERIFY(testValue2 == avvideo_.getFps());

    const int testValue3=60;
    avvideo_.setFps(testValue3);
    QVERIFY(testValue3 == avvideo_.getFps());

    const int testValue4=100;
    avvideo_.setFps(testValue4);
    QVERIFY(testValue4 == avvideo_.getFps());
}

void TestAVVideo::TestInsertFrame() {
    AVFrame* frame = new AVFrame();
    avvideo_.insertFrame(frame, 0);
    QVERIFY(frame == avvideo_.getFrame(0));

    AVFrame* frame2 = new AVFrame();
    avvideo_.insertFrame(frame2, 1);
    QVERIFY(frame2 == avvideo_.getFrame(1));

    QVERIFY(2 == avvideo_.getNumberOfFrames());
}

void TestAVVideo::TestAppendFrame() {
    AVFrame* frame = new AVFrame();
    avvideo_.appendFrame(frame);
    QVERIFY(frame == avvideo_.getFrame(0));

    QVERIFY(frame->width == avvideo_.getWidth());
    QVERIFY(frame->height == avvideo_.getHeight());

}

void TestAVVideo::TestRemoveFrame() {
    AVFrame* frame = new AVFrame();
    avvideo_.insertFrame(frame, 0);
    QVERIFY(frame == avvideo_.getFrame(0));

    AVFrame* frame2 = new AVFrame();
    avvideo_.insertFrame(frame2, 1);
    QVERIFY(frame2 == avvideo_.getFrame(1));

    avvideo_.removeFrame(1);
    QVERIFY(frame2 != avvideo_.getFrame(1));

    QVERIFY(nullptr == avvideo_.getFrame(2));

}

void TestAVVideo::TestIsComplete(){

    avvideo_.setIsComplete(true);
    QVERIFY(true == avvideo_.isComplete());

    avvideo_.setIsComplete(false);
    QVERIFY(false == avvideo_.isComplete());
}

void TestAVVideo::TestInsertFrames() {
    std::vector<AVFrame*> frames;
    QVERIFY(true == avvideo_.insertFrames(frames, 0));

    std::vector<AVFrame*> frames2;
    QVERIFY(false == avvideo_.insertFrames(frames2, 10));

}

void TestAVVideo::TestHeightWidth() {
    AVFrame* frame = new AVFrame();
    avvideo_.appendFrame(frame);
    QVERIFY(frame == avvideo_.getFrame(0));

    QVERIFY(frame->width == avvideo_.getWidth());
    QVERIFY(frame->height == avvideo_.getHeight());

}
