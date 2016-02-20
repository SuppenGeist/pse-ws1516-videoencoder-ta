#ifndef __ProjectWriter_h__
#define __ProjectWriter_h__

#include <thread>

#include <QFile>
#include <QTextStream>

namespace Model {
class Project;
}

namespace Utility {
/**
 * This class can write the project files and the results.
*/
class ProjectWriter {
  public:
	/**
	 * @brief ProjectWriter Constructor.
	 * @param p The project to save.
	 */
	ProjectWriter(Model::Project* project);

	~ProjectWriter();

	/**
	 * @brief saveProject Saves the whole project.
	 */
    void saveProject();

  private:
	Model::Project*     project_;

	std::unique_ptr<QFile> file_;
	QTextStream         dataStream_;
};
}

#endif
