#ifndef __MainWindowMemento_h__
#define __MainWindowMemento_h__

#include "AnalysisTabMemento.h"
#include "FilterTabMemento.h"

namespace Memento {
class AnalysisTabMemento;
class FilterTabMemento;
class MainWindowMemento;
}

namespace Memento {
/**
 * This class is the memento for the MainWindow.
 */
class MainWindowMemento {

public:
	/// <summary>
	/// Constructor.
	/// </summary>
	MainWindowMemento();

	/// <summary>
	/// Returns the currently selected tab.
	/// </summary>
	/// <returns>The currently selected tab.</returns>
	int getSelectedTab();

	/// <summary>
	/// Sets the currently selected tab.
	/// </summary>
	/// <param name="selectedTab">The currently selected tab.</param>
	void setSelectedTab(int selectedTab);

	/// <summary>
	/// Returns the AnalysisTabMemento.
	/// </summary>
	/// <returns>The AnalysisTabMemento.</returns>
    Memento::AnalysisTabMemento* getAnalysisTabMemento();

	/// <summary>
	/// Sets the AnalysisTabMemento.
	/// </summary>
	/// <param name="analysisTabMeMento">The AnalysisTabMemento.</param>
    void setAnalysisTabMemento(AnalysisTabMemento* analysisTabMeMento);

	/// <summary>
	/// Returns the FilterTabMemento.
	/// </summary>
	/// <returns>The FilterTabMemento.</returns>
    Memento::FilterTabMemento* getFilterTabMemento();

	/// <summary>
	/// Sets the FilterTabMemento.
	/// </summary>
	/// <param name="filterTabMemento">The FilterTabMemento.</param>
    void setFilterTabMemento(FilterTabMemento* filterTabMemento);

    private:
        int selectedTab_;
        Memento::AnalysisTabMemento* analysisTab_;
        Memento::FilterTabMemento* filterTab_;
};
}

#endif
