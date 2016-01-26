
#include <exception>
using namespace std;

#ifndef __FilterConfigurationBox_h__
#define __FilterConfigurationBox_h__

// #include "QWidget.h"
#include "Filter.h"

namespace GUI
{
	class QWidget;
	class FilterConfigurationBox;
}
namespace Model
{
	class Filter;
}

namespace GUI
{
	/**
	 * This class is the base class for the configuration boxes for the filters.
	 */
	class FilterConfigurationBox
	{
		protected: Model::Filter* filter;

		/// <summary>
		/// Constructor.
		/// </summary>
		public: FilterConfigurationBox(GUI::QWidget* parent);

		/// <summary>
		/// Sets the filter the filterbox is responsible for.
		/// </summary>
		/// <param name="filter">The filter to show the options for.</param>
		public: void setFilter(Model::Filter& filter);

		/// <summary>
		/// Returns the filter the filterbox is responsible for.
		/// </summary>
		/// <returns>The filter the filterbox shows the options for.</returns>
		public: Model::Filter* getFilter();
	};
}

#endif
