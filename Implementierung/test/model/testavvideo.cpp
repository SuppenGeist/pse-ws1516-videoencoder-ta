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
