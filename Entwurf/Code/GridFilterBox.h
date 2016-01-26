
#include <exception>
using namespace std;

#ifndef __GridFilterBox_h__
#define __GridFilterBox_h__

// #include "QWidget.h"
#include "FilterConfigurationBox.h"

namespace GUI
{
	class QWidget;
	// class FilterConfigurationBox;
	class GridFilterBox;
}

namespace GUI
{
	/**
	 * This class contains the gui elements for changing the options of a grid filter.
	 */
	class GridFilterBox: public GUI::FilterConfigurationBox
	{

		/// <summary>
		/// Constructor.
		/// </summary>
		public: GridFilterBox(GUI::QWidget* parent);
	};
}

#endif
