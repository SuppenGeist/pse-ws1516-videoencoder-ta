#ifndef __FilterConfigurationLoader_h__
#define __FilterConfigurationLoader_h__

#include <memory>

#include <QFile>

namespace Model {
class FilterList;
}

namespace Utility {
/**
 * This class can load a Filterlist from a file.
*/
class FilterConfigurationLoader {
  public:
	/**
	 * @brief FilterConfigurationLoader Constructor.
	 * @param path The path to the filerlist to load.
	 */
	FilterConfigurationLoader(QString path);

	/**
	 * @brief getConfiguration Loads the filterlist.
	 * @return The loaded filterlist.
	 */
	std::unique_ptr<Model::FilterList> getConfiguration();

  private:
	QFile   file_;
};
}

#endif

