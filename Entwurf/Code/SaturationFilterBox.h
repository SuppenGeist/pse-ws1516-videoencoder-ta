
#include <exception>
using namespace std;

#ifndef __SaturationFilterBox_h__
#define __SaturationFilterBox_h__

// #include "QWidget.h"
#include "FilterConfigurationBox.h"

namespace GUI
{
	class QWidget;
	// class FilterConfigurationBox;
	class SaturationFilterBox;
}

namespace GUI
{
	/**
	 * This class contains the gui elements for changing the options of a saturation filter.
	 */
	class SaturationFilterBox: public GUI::FilterConfigurationBox
	{

		/// <summary>
		/// Constructor.
		/// </summary>
		public: SaturationFilterBox(GUI::QWidget* parent);
	};
}

#endif
