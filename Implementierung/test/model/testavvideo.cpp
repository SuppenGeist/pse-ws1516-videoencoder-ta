#include "testavvideo.h"

void TestAVVideo::init() {
	avvideo_=Model::AVVideo(10);
}

void TestAVVideo::testFPS() {
	const int testValue1=0;
	avvideo_.setFps(testValue1);
	QVERIFY(testValue1 == avvideo_.getFps());

	const int testValue2=100;
	avvideo_.setFps(testValue2);
	QVERIFY(testValue2 == avvideo_.getFps());

	const int testValue3=-10;
	avvideo_.setFps(testValue3);
	QVERIFY(testValue3 != avvideo_.getFps());
}

void TestAVVideo::TestAppendFrame() {
	AVFrame* frame = new AVFrame();
	QVERIFY(true == avvideo_.appendFrame(frame));
}

void TestAVVideo::TestInsertFrame() {
	AVFrame* frame = new AVFrame();
	QVERIFY(true == avvideo_.insertFrame(frame, 0));
}

void TestAVVideo::TestGetNumberOfFrames() {
	AVFrame* frame = new AVFrame();
	avvideo_.insertFrame(frame, 0);

	AVFrame* frame2 = new AVFrame();
	avvideo_.insertFrame(frame2, 1);

	QVERIFY(2 == avvideo_.getNumberOfFrames());
}


void TestAVVideo::TestGetFrame() {
	AVFrame* frame = new AVFrame();
	avvideo_.appendFrame(frame);

	QVERIFY(frame == avvideo_.getFrame(0));

	QVERIFY(nullptr == avvideo_.getFrame(1));

}

void TestAVVideo::TestRemoveFrame() {
	avvideo_.removeFrame(1);
	QVERIFY(0 == avvideo_.getHeight());

	AVFrame* frame = new AVFrame();
	avvideo_.insertFrame(frame, 0);

	AVFrame* frame2 = new AVFrame();
	avvideo_.insertFrame(frame2, 1);

	avvideo_.removeFrame(1);
	QVERIFY(frame2 != avvideo_.getFrame(1));

	QVERIFY(nullptr == avvideo_.getFrame(2));


}

void TestAVVideo::TestIsComplete() {

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

void TestAVVideo::TestHeight() {
	AVFrame* frame = new AVFrame();
	avvideo_.appendFrame(frame);

	QVERIFY(frame->height == avvideo_.getHeight());

}

void TestAVVideo::TestWidth() {
	AVFrame* frame = new AVFrame();
	avvideo_.appendFrame(frame);

	QVERIFY(frame->width == avvideo_.getWidth());

}
