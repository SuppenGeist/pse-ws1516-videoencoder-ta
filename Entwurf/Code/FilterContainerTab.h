
#include <exception>
#include <string>
#include <vector>
using namespace std;

#ifndef __FilterContainerTab_h__
#define __FilterContainerTab_h__

#include "FilterTab.h"
#include "FilterView.h"
// #include "QWidget.h"
#include "Filter.h"

namespace GUI
{
	class FilterTab;
	class FilterView;
	class QWidget;
	class FilterContainerTab;
}
namespace Model
{
	class Filter;
}

namespace GUI
{
	/**
	 * This class shows all the selectable filters.
	 */
	class FilterContainerTab
	{
		private: GUI::FilterTab* parentTab;
		private: GUI::FilterTab* filterContainerTab;
		private: std::vector<GUI::FilterView*> filterViews;

		/// <summary>
		/// Constructor.
		/// </summary>
		public: FilterContainerTab(GUI::QWidget* parent);

		/// <summary>
		/// Adds a selectable filter.
		/// </summary>
		/// <param name="filter">The new filter.</param>
		public: void addFilter(Model::Filter filter);

		/// <summary>
		/// Sets the parent tab.
		/// </summary>
		/// <param name="parent">The parent tab.</param>
		public: void setParentTab(GUI::FilterTab& parent);

		/// <summary>
		/// Searches for the filterView with the filter filterName and unchecks it.
		/// </summary>
		/// <param name="filterName">The filter to uncheck.</param>
		public: void uncheck(string filterName);
	};
}

#endif
