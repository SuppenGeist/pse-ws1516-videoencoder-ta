
#include <exception>
using namespace std;

#ifndef __FilterView_h__
#define __FilterView_h__

#include "FilterTab.h"
#include "QWidget.h"
#include "Filter.h"
#include <QCheckBox>

namespace GUI
{
	class FilterTab;
	class QWidget;
	class FilterView;
}
namespace Model
{
	class Filter;
}

namespace GUI
{
	/**
	 * Represents a selectable filter in the gui. Shows a example of the filter and  a checkbox as well as its name.
    */
	class FilterView
	{
		private: QCheckBox* checkbox;
		private: QLabel* preview;
		private: GUI::FilterTab* filterTab;
		private: Model::Filter* filter;

		/// <summary>
		/// Constructor.
		/// </summary>
		public: FilterView(GUI::QWidget* parent);

		/// <summary>
		/// Slot: connected with checkbox.stateChanged(state : int)
		/// does filterTab.addFilter(filter)
		/// or filterTab.removeFilter(filter.getName())
		/// </summary>
		private: void checkBoxStateChanged(int state);

		/// <summary>
		/// Sets the filter this view represents.
		/// </summary>
		/// <param name="filter">The filter for this view.</param>
		public: void setFilter(Model::Filter filter);

		/// <summary>
		/// Sets the tab this view is contained in.
		/// </summary>
		/// <param name="filtertab">The parent filtertab.</param>
		public: void setFilterTab(GUI::FilterTab* filtertab);

		/// <summary>
		/// Returns the default image on which the filter is applied as a preview.
		/// </summary>
		/// <returns>The default image.</returns>
		private: static QImage getDefaultImage() {
			throw "Not yet implemented";
		}
	};
}

#endif
