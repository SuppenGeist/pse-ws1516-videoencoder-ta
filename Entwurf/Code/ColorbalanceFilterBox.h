
#include <exception>
using namespace std;

#ifndef __ColorbalanceFilterBox_h__
#define __ColorbalanceFilterBox_h__

// #include "QWidget.h"
#include "FilterConfigurationBox.h"

namespace GUI
{
	class QWidget;
	// class FilterConfigurationBox;
	class ColorbalanceFilterBox;
}

namespace GUI
{
	/**
	 * This class contains the gui elements for changing the options of a color balance filter.
	 */
	class ColorbalanceFilterBox: public GUI::FilterConfigurationBox
	{

		/// <summary>
		/// Constructor.
		/// </summary>
		public: ColorbalanceFilterBox(GUI::QWidget* parent);
	};
}

#endif
