#ifndef __Project_h__
#define __Project_h__

#include <memory>

#include <QString>

namespace GUI {
class MainWindow;
}
namespace Memento {
class MainWindowMemento;
}
namespace Model {
class Project;
}

namespace Model {

/** This class contains the different mementos.
*/
class Project {
  public:
    /**
     * @brief Project Constructor.
     * @param name Name of the project.
     */
    Project(QString name="");

    /**
     * @brief getName Returns the name of the project.
     * @return Name of the project.
     */
	QString getName();

    /**
     * @brief getMemento Returns the MainWindowMemento.
     * @return The MainWindowMemento.
     */
	Memento::MainWindowMemento& getMemento();

    /**
     * @brief setMemento Sets the MainWindowMemento.
     * @param memento The MainWindowMemento.
     */
    void setMemento(std::unique_ptr<Memento::MainWindowMemento> memento);

    /**
     * @brief setPath Sets the path at which the project is saved.
     * @param path The project save path.
     */
	void setPath(QString path);

    void setName(QString name);

    /**
     * @brief getPath Returns the project save path.
     * @return The project save path.
     */
	QString getPath();


private:
  QString name_;
  QString path_;
  std::unique_ptr<Memento::MainWindowMemento> memento_;
};
}

#endif

