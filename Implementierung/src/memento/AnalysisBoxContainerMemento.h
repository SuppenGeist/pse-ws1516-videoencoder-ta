#ifndef __AnalysisBoxContainerMemento_h__
#define __AnalysisBoxContainerMemento_h__

#include <vector>
#include <memory>

#include "AnalysisBoxMemento.h"

namespace Memento {
/**
 * This class is the memento for the AnalysisBoxContainer.
 */
class AnalysisBoxContainerMemento {

  public:
	/**
	 * @brief AnalysisBoxContainerMemento Constructor.
	 */
	AnalysisBoxContainerMemento();

	/**
	 * @brief getAnalysisBoxList Returns a list of AnalysisBox mementos.
	 * @return The list of AnalysisBoxMemento.
	 */
	std::vector<std::unique_ptr<Memento::AnalysisBoxMemento>>& getAnalysisBoxList();

	/**
	 * @brief addMemento Sets the list of AnalysisBoxMemento
	 * @param memento The list of the mementos.
	 */
	void addMemento(std::unique_ptr<AnalysisBoxMemento> memento);

  private:
	std::vector<std::unique_ptr<Memento::AnalysisBoxMemento>> mementoList_;
};
}

#endif
