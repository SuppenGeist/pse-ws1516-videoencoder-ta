#include "testfiltertabmemento.h"

void TestFilterTabMemento::init() {

	memento_ = Memento::FilterTabMemento();

}

void TestFilterTabMemento::testSetCurrentFrame() {
	int value = 5;
	memento_.setCurrentFrame(value);
	QVERIFY(memento_.getCurrentFrame() == value);

}

void TestFilterTabMemento::testSetCurrentlySelectedFilter() {
	int value = 2;
	memento_.setCurrentlySelectedFilter(value);
	QVERIFY(memento_.getCurrentlySelectedFilter()==value);
}

void TestFilterTabMemento::testSetFilterList() {
	auto oldList = memento_.getFilterList();
	std::unique_ptr<Model::FilterList> newList(new Model::FilterList);
	QVERIFY(memento_.getFilterList() != oldList);

}

void TestFilterTabMemento::testSetIsFilteredVideoShown() {
	bool value = true;
	memento_.setIsFilteredVideoShown(value);
	QVERIFY(memento_.isFilteredVideoShown() == value);

}

void TestFilterTabMemento::testSetIsPreviewShown() {
	bool value = true;
	memento_.setIsPreviewShown(value);
	QVERIFY(memento_.isPreviewShow() == value);

}

void TestFilterTabMemento::testSetRawVideo() {
	Model::YuvVideo* vid ;
	memento_.setRawVideo(vid);
	QVERIFY(memento_.getRawVideo() != nullptr);

}

void TestFilterTabMemento::testSetRawVideo2() {
	/*    std::unique_ptr<Model::YuvVideo> video;
	    QVERIFY(memento_.releaseVideo() == video);
	    auto old = memento_.releaseVideo();
	    memento_.setRawVideo(std::move(video));
	    QVERIFY(memento_.releaseVideo() == video);
	*/

}
