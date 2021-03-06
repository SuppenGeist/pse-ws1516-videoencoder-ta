#include "testanalysistabmemento.h"
#include "../../src/gui/AnalysisTab.h"
#include "../../src/utility/YuvType.h"
#include "../../src/utility/Compression.h"

void TestAnalysisTabMemento::init() {

	memento_ = Memento::AnalysisTabMemento();

}

void TestAnalysisTabMemento::testSetAnalysisBoxContainerMemento() {
	std::unique_ptr<Memento::AnalysisBoxContainerMemento> container (new
	        Memento::AnalysisBoxContainerMemento());

	QVERIFY(memento_.getAnalysisBoxContainerMemento() == nullptr);
	memento_.setAnalysisBoxContainerMemento(std::move(container));
	QVERIFY(memento_.getAnalysisBoxContainerMemento() != nullptr);

}

void TestAnalysisTabMemento::testSetAnalysisGraph() {
	GUI::AnalysisGraph value = GUI::AnalysisGraph::PSNR;
	memento_.setAnalysisGraph(value);
	QVERIFY(memento_.getAnalysisGraph() == value);


}

void TestAnalysisTabMemento::testSetAnalysisVideo() {
	GUI::AnalysisVideo value = GUI::AnalysisVideo::RGB_DIFFERENCE;
	memento_.setAnalysisVideo(value);
	QVERIFY(memento_.getAnalysisVideo() == value);
}

void TestAnalysisTabMemento::testSetPlayerPosition() {
	int value = 1;
	memento_.setPlayerPosition(value);
	QVERIFY(memento_.getPlayerPosition() == value);

}

void TestAnalysisTabMemento::testSetRawVideo() {
	auto ptr=std::make_unique<Model::YuvVideo>("haha",Utility::YuvType::YUV411,
	         Utility::Compression::PACKED,10,10,1);
	Model::YuvVideo* vid=ptr.get();
	memento_.setRawVideo(vid);
	QVERIFY(memento_.getRawVideo() != nullptr);

}

