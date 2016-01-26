
#include <exception>
using namespace std;

#ifndef __PlainFilterBox_h__
#define __PlainFilterBox_h__

// #include "QWidget.h"
#include "FilterConfigurationBox.h"

namespace GUI
{
	class QWidget;
	// class FilterConfigurationBox;
	class PlainFilterBox;
}

namespace GUI
{
	/**
	 * This class contains no sliders to adjust filter options.
	 */
	class PlainFilterBox: public GUI::FilterConfigurationBox
	{

		/// <summary>
		/// Constructor.
		/// </summary>
		public: PlainFilterBox(GUI::QWidget* parent);
	};
}

#endif
