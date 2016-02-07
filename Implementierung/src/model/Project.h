#include <QString>
#include <exception>
using namespace std;

#ifndef __Project_h__
#define __Project_h__

// #include "MainWindow.h"
// #include "MainWindowMemento.h"

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
class Project
{
	private: QString name;
	private: QString path;
	private: GUI::MainWindow* loadedProject;
	private: Memento::MainWindowMemento* mainWindowMemento;

	/// <summary>
	/// Constructor.
	/// </summary>
	/// <param name="name">Name of the project.</param>
	public: Project(QString name);

	/// <summary>
	/// Returns the name of the project.
	/// </summary>
	/// <returns>Name of the project.</returns>
	public: QString getName();

	/// <summary>
	/// Returns the MainWindowMemento.
	/// </summary>
	/// <returns>The MainWindowMemento.</returns>
	public: Memento::MainWindowMemento& getMemento();

	/// <summary>
	/// Sets the MainWindowMemento.
	/// </summary>
	/// <param name="memento">The MainWindowMemento.</param>
	public: void setMemento(Memento::MainWindowMemento memento);

	/// <summary>
	/// Sets the path at which the project is saved.
	/// </summary>
	/// <param name="path">The project save path.</param>
    public: void setPath(QString path);

	/// <summary>
	/// Returns the project save path.
	/// </summary>
	/// <returns>The project save path.</returns>
	public: QString getPath();
};
}

#endif

