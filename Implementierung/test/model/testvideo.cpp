#include "testvideo.h"

void TestVideo::init()
{
    video_=Model::Video(10);
}

void TestVideo::testFPS() {
    const int testValue1=0;
    video_.setFps(testValue1);
    QVERIFY(testValue1 == video_.getFps());

    const int testValue2=30;
    video_.setFps(testValue2);
    QVERIFY(testValue2 == video_.getFps());

    const int testValue3=60;
    video_.setFps(testValue3);
    QVERIFY(testValue3 == video_.getFps());

    const int testValue4=100;
    video_.setFps(testValue4);
    QVERIFY(testValue4 == video_.getFps());
}
