#ifndef __FilterConfigurationSaver_h__
#define __FilterConfigurationSaver_h__

#include <exception>
#include <QFile>
#include "../model/FilterList.h"
namespace Model
{
	class FilterList;
}
namespace Utility
{
	class FilterConfigurationSaver;
}

namespace Utility
{
	/**
	 * This class can save a filterlist to a file.
    */
	class FilterConfigurationSaver
	{
        private: QFile fileout;
        private: Model::FilterList& filterList;

		/// <summary>
		/// Constructor.
		/// </summary>
		/// <param name="file">Absolute path to the file to save to.</param>
		/// <param name="filterList">The filterlist to save.</param>
        public: FilterConfigurationSaver(QString file, Model::FilterList& filterList_);

		/// <summary>
		/// Saves the filterlist.
		/// </summary>
		public: void save();
	};
}

#endif

