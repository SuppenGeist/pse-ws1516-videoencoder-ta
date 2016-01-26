
#include <exception>
using namespace std;

#ifndef __BlendingFilterBox_h__
#define __BlendingFilterBox_h__

// #include "QWidget.h"
#include "FilterConfigurationBox.h"

namespace GUI
{
	class QWidget;
	// class FilterConfigurationBox;
	class BlendingFilterBox;
}

namespace GUI
{
	/**
	 * This class contains the gui elements for changing the options of a blending filter.
	 */
	class BlendingFilterBox: public GUI::FilterConfigurationBox
	{

		/// <summary>
		/// Constructor.
		/// </summary>
		public: BlendingFilterBox(GUI::QWidget* parent);
	};
}

#endif
