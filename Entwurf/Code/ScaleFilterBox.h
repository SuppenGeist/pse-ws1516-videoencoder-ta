
#include <exception>
using namespace std;

#ifndef __ScaleFilterBox_h__
#define __ScaleFilterBox_h__

// #include "QWidget.h"
#include "FilterConfigurationBox.h"

namespace GUI
{
	class QWidget;
	// class FilterConfigurationBox;
	class ScaleFilterBox;
}

namespace GUI
{
	/**
	 * This class contains the gui elements for changing the options of a scale filter.
	 */
	class ScaleFilterBox: public GUI::FilterConfigurationBox
	{

		/// <summary>
		/// Constructor.
		/// </summary>
		public: ScaleFilterBox(GUI::QWidget* parent);
	};
}

#endif
