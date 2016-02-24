#ifndef __AnalysisTabMemento_h__
#define __AnalysisTabMemento_h__

#include <memory>

#include "../model/YuvVideo.h"
#include "../memento/AnalysisBoxContainerMemento.h"

namespace GUI {
enum class AnalysisGraph;
enum class AnalysisVideo;
}

namespace Memento {
/**
 * This class is the memento for the analysis tab.
 */
class AnalysisTabMemento {
  public:

	/**
	 * @brief AnalysisTabMemento Constructor.
	 */
	AnalysisTabMemento();

	void setRawVideo(Model::YuvVideo* video);

	void setRawVideo(std::unique_ptr<Model::YuvVideo> video);

	std::unique_ptr<Model::YuvVideo> releaseVideo();

	Model::YuvVideo* getRawVideo();

	void setAnalysisBoxContainerMemento(std::unique_ptr<Memento::AnalysisBoxContainerMemento>
	                                    analysisBoxMemento);

	Memento::AnalysisBoxContainerMemento* getAnalysisBoxContainerMemento();

	GUI::AnalysisGraph getAnalysisGraph();

	void setAnalysisGraph(GUI::AnalysisGraph graph);

	GUI::AnalysisVideo getAnalysisVideo();

	void setAnalysisVideo(GUI::AnalysisVideo video);

	int getPlayerPosition();

	void setPlayerPosition(int position);

  private:
	Model::YuvVideo*        rawVideo_;
	std::unique_ptr<Memento::AnalysisBoxContainerMemento> analysisBoxMemento_;
	std::unique_ptr<Model::YuvVideo> ownedVideo_;
	GUI::AnalysisGraph      graph_;
	GUI::AnalysisVideo      video_;
	int                     position_;
};
}

#endif

