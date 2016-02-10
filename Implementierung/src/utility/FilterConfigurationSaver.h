#ifndef __FilterConfigurationSaver_h__
#define __FilterConfigurationSaver_h__

#include <QFile>

namespace Model {
class FilterList;
}

namespace Utility {
/**
 * This class can save a filterlist to a file.
*/
class FilterConfigurationSaver {
  public:
	/**
	 * @brief FilterConfigurationSaver Constructor.
	 * @param file Absolute path to the file to save to.
	 * @param filterList_ The filterlist to save.
	 */
	FilterConfigurationSaver(QString file, Model::FilterList& filterList);

	/**
	 * @brief save Saves the filterlist.
	 */
	void save();

  private:
	QFile               fileout_;
	Model::FilterList*  filterList_;
};
}

#endif

