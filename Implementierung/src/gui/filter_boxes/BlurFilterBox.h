
#include <exception>
using namespace std;

#ifndef __BlurFilterBox_h__
#define __BlurFilterBox_h__

// #include "QWidget.h"
#include "FilterConfigurationBox.h"

namespace GUI
{
	class QWidget;
	// class FilterConfigurationBox;
	class BlurFilterBox;
}

namespace GUI
{
	/**
	 * This class contains the gui elements for changing the options of a blurring filter.
	 */
	class BlurFilterBox: public GUI::FilterConfigurationBox
	{

		/// <summary>
		/// Constructor.
		/// </summary>
		public: BlurFilterBox(GUI::QWidget* parent);
	};
}

#endif
