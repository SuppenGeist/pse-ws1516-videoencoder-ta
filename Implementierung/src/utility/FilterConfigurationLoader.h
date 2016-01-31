#ifndef __FilterConfigurationLoader_h__
#define __FilterConfigurationLoader_h__

#include <exception>
#include <QFile>

namespace Model {
class FilterList;
}
namespace Utility {
class FilterConfigurationLoader;
}

namespace Utility {
/**
 * This class can load a Filterlist from a file.
*/
class FilterConfigurationLoader {
  private:
	QFile file;
  private:
	Model::FilterList* filterList;

	/// <summary>
	/// Constructor.
	/// </summary>
	/// <param name="path">The path to the filerlist to load.</param>
  public:
	FilterConfigurationLoader(QString path);

	/// <summary>
	/// Loads the filterlist.
	/// </summary>
	/// <returns>The loaded filterlist.</returns>
  public:
	Model::FilterList* getConfiguration();
};
}

#endif

