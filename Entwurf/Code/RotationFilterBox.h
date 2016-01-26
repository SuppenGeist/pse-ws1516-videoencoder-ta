
#include <exception>
using namespace std;

#ifndef __RotationFilterBox_h__
#define __RotationFilterBox_h__

// #include "QWidget.h"
#include "FilterConfigurationBox.h"

namespace GUI
{
	class QWidget;
	// class FilterConfigurationBox;
	class RotationFilterBox;
}

namespace GUI
{
	/**
	 * This class contains the gui elements for changing the options of a rotation filter.
	 */
	class RotationFilterBox: public GUI::FilterConfigurationBox
	{

		/// <summary>
		/// Constructor.
		/// </summary>
		public: RotationFilterBox(GUI::QWidget* parent);
	};
}

#endif
