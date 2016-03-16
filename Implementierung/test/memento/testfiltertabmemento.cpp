#include "testfiltertabmemento.h"

#include "../../src/utility/Compression.h"
#include "../../src/utility/YuvType.h"

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
	auto ptr=std::make_unique<Model::YuvVideo>("haha",Utility::YuvType::YUV411,
	         Utility::Compression::PACKED,10,10,1);
	Model::YuvVideo* vid=ptr.get();
	memento_.setRawVideo(vid);
	QVERIFY(memento_.getRawVideo() != nullptr);

}
