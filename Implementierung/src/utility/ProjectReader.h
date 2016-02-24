#ifndef __ProjectReader_h__
#define __ProjectReader_h__

#include <memory>

#include <QString>
#include <QFile>
#include <QTextStream>

#include "../memento/FilterTabMemento.h"
#include "../memento/AnalysisTabMemento.h"

namespace Model {
class Project;
}
namespace Utility {
class ProjectReader;
}

namespace Utility {
/**
 * This class can read a project from a file.
*/
class ProjectReader {
  public:
	/**
	 * @brief ProjectReader Constructor.
	 * @param path The absolute path to the project file.
	 */
	ProjectReader(QString path);

	~ProjectReader();

	/**
	 * @brief readProject Reads a project from a file.
	 * @return The loaded project.
	 */
	std::unique_ptr<Model::Project> readProject();


  private:
	QString   path_;
	QFile     file_;
	QTextStream dataStream_;

	void parseFilterTab(Memento::FilterTabMemento* memento,QString line);
	void parseAnalysisTab(Memento::AnalysisTabMemento* memento,QString line);

};
}

#endif

