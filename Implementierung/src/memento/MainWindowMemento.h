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
  private:
	int selectedTab;
  private:
	Memento::AnalysisTabMemento analysisTab;
  private:
	Memento::FilterTabMemento filterTab;

	/// <summary>
	/// Constructor.
	/// </summary>
  public:
	MainWindowMemento();

	/// <summary>
	/// Returns the currently selected tab.
	/// </summary>
	/// <returns>The currently selected tab.</returns>
  public:
	int getSelectedTab();

	/// <summary>
	/// Sets the currently selected tab.
	/// </summary>
	/// <param name="selectedTab">The currently selected tab.</param>
  public:
	void setSelectedTab(int selectedTab);

	/// <summary>
	/// Returns the AnalysisTabMemento.
	/// </summary>
	/// <returns>The AnalysisTabMemento.</returns>
  public:
	Memento::AnalysisTabMemento getAnalysisTabMemento();

	/// <summary>
	/// Sets the AnalysisTabMemento.
	/// </summary>
	/// <param name="analysisTabMeMento">The AnalysisTabMemento.</param>
  public:
	void setAnalysisTabMemento(Memento::AnalysisTabMemento analysisTabMeMento);

	/// <summary>
	/// Returns the FilterTabMemento.
	/// </summary>
	/// <returns>The FilterTabMemento.</returns>
  public:
	Memento::FilterTabMemento getFilterTabMemento();

	/// <summary>
	/// Sets the FilterTabMemento.
	/// </summary>
	/// <param name="filterTabMemento">The FilterTabMemento.</param>
  public:
	void setFilterTabMemento(FilterTabMemento filterTabMemento);
};
}

#endif
