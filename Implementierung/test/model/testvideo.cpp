#include <memory>
#include "testvideo.h"

void TestVideo::init() {
	video_=Model::Video(10);
}

void TestVideo::TestFPS() {
	const int testValue1=0;
	video_.setFps(testValue1);
	QVERIFY(testValue1 == video_.getFps());

	const int testValue2=100;
	video_.setFps(testValue2);
	QVERIFY(testValue2 == video_.getFps());

	const int testValue3=-10;
	video_.setFps(testValue3);
	QVERIFY(testValue3 != video_.getFps());
}

void TestVideo::TestAppendFrame() {
	std::unique_ptr<QImage> frame(new QImage);
	QVERIFY(true == video_.appendFrame(std::move(frame)));
}

void TestVideo::TestInsertFrame() {
	std::unique_ptr<QImage> frame(new QImage);
	QVERIFY(true == video_.insertFrame(std::move(frame), 0));
}

void TestVideo::TestGetNumberOfFrames() {
	std::unique_ptr<QImage> frame(new QImage);
	video_.insertFrame(std::move(frame), 0);

	std::unique_ptr<QImage> frame2(new QImage);
	video_.insertFrame(std::move(frame2), 1);

	QVERIFY(2 == video_.getNumberOfFrames());
}


void TestVideo::TestGetFrame() {
	std::unique_ptr<QImage> frame(new QImage);
	QImage* tempframe = frame.get();
	video_.appendFrame(std::move(frame));
	QVERIFY(tempframe == video_.getFrame(0));

	QVERIFY(nullptr == video_.getFrame(1));
}

void TestVideo::TestRemoveFrame() {
	video_.removeFrame(1);
	QVERIFY(0 == video_.getHeight());

	std::unique_ptr<QImage> frame(new QImage);
	video_.insertFrame(std::move(frame), 0);

	std::unique_ptr<QImage> frame2(new QImage);
	QImage* tempframe2 = frame2.get();
	video_.insertFrame(move(std::move(frame2)), 1);


	video_.removeFrame(1);
	QVERIFY(tempframe2 != video_.getFrame(1));


	QVERIFY(nullptr == video_.getFrame(2));


}

void TestVideo::TestIsComplete() {

	video_.setIsComplete(true);
	QVERIFY(true == video_.isComplete());

	video_.setIsComplete(false);
	QVERIFY(false == video_.isComplete());
}

void TestVideo::TestInsertFrames() {
	std::vector<std::unique_ptr<QImage>> frames;
	QVERIFY(true == video_.insertFrames(frames, 0));

	std::vector<std::unique_ptr<QImage>> frames2;
	QVERIFY(false == video_.insertFrames(frames2, 10));

}

void TestVideo::TestHeight() {
	std::unique_ptr<QImage> frame(new QImage);
	int height_ = frame->height();
	video_.appendFrame(move(frame));

	QVERIFY(height_ == video_.getHeight());

}

void TestVideo::TestWidth() {
	std::unique_ptr<QImage> frame(new QImage);
	int width_ = frame->width();
	video_.appendFrame(move(frame));

	QVERIFY(width_ == video_.getWidth());

}
