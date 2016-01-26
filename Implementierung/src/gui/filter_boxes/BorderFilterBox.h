
#include <exception>
using namespace std;

#ifndef __BorderFilterBox_h__
#define __BorderFilterBox_h__

// #include "QWidget.h"
#include "FilterConfigurationBox.h"

namespace GUI
{
	class QWidget;
	// class FilterConfigurationBox;
	class BorderFilterBox;
}

namespace GUI
{
	/**
	 * This class contains the gui elements for changing the options of a border filter.
	 */
	class BorderFilterBox: public GUI::FilterConfigurationBox
	{

		/// <summary>
		/// Constructor.
		/// </summary>
		public: BorderFilterBox(GUI::QWidget* parent);
	};
}

#endif
