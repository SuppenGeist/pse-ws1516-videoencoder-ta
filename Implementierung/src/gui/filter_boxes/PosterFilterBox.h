
#include <exception>
using namespace std;

#ifndef __PosterFilterBox_h__
#define __PosterFilterBox_h__

// #include "QWidget.h"
#include "FilterConfigurationBox.h"

namespace GUI
{
	class QWidget;
	// class FilterConfigurationBox;
	class PosterFilterBox;
}

namespace GUI
{
	/**
	 * This class contains the gui elements for changing the options of a poster filter.
	 */
	class PosterFilterBox: public GUI::FilterConfigurationBox
	{

		/// <summary>
		/// Constructor.
		/// </summary>
		public: PosterFilterBox(GUI::QWidget* parent);
	};
}

#endif
