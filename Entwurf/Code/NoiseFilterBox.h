
#include <exception>
using namespace std;

#ifndef __NoiseFilterBox_h__
#define __NoiseFilterBox_h__

// #include "QWidget.h"
#include "FilterConfigurationBox.h"

namespace GUI
{
	class QWidget;
	// class FilterConfigurationBox;
	class NoiseFilterBox;
}

namespace GUI
{
	/**
	 * This class contains the gui elements for changing the options of a noise filter.
	 */
	class NoiseFilterBox: public GUI::FilterConfigurationBox
	{

		/// <summary>
		/// Constructor.
		/// </summary>
		public: NoiseFilterBox(GUI::QWidget* parent);
	};
}

#endif
