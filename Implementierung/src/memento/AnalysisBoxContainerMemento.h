#include <exception>
#include <vector>
using namespace std;

#ifndef __AnalysisBoxContainerMemento_h__
#define __AnalysisBoxContainerMemento_h__

#include "AnalysisBoxMemento.h"

namespace Memento {
class AnalysisBoxMemento;
class AnalysisBoxContainerMemento;
}

namespace Memento {
/**
 * This class is the memento for the AnalysisBoxContainer.
 */
class AnalysisBoxContainerMemento {

public:
    /// <summary>
    /// Constructor.
    /// </summary>
    void analysisBoxMemento();

    /// <summary>
    /// Returns a list of AnalysisBox mementos.
    /// </summary>
    /// <returns>The list of AnalysisBoxMemento.</returns>
    vector<Memento::AnalysisBoxMemento*> getAnalysisBoxList();

    /// <summary>
    /// Sets the list of AnalysisBoxMemento
	/// </summary>
	/// <param name="analyseBoxList">The list of the mementos.</param>
    void setAnalysisBoxList(vector<Memento::AnalysisBoxMemento*> analysisBoxList);

private:
    std::vector<Memento::AnalysisBoxMemento*> mementoList_;
};
}

#endif
