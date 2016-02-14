#ifndef __AnalysisTabMemento_h__
#define __AnalysisTabMemento_h__

#include "../model/YuvVideo.h"

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

	Model::YuvVideo* getRawVideo();

  private:
	Model::YuvVideo*        rawVideo_;
};
}

#endif

