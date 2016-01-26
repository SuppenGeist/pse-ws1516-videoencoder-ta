
#include <exception>
using namespace std;

#ifndef __MainWindow_h__
#define __MainWindow_h__

// #include "QWidget.h"
#include "MainWindowMemento.h"
#include "Project.h"

namespace GUI
{
	class QWidget;
	class MainWindow;
}
namespace Memento
{
	class MainWindowMemento;
}
namespace Model
{
	class Project;
}

namespace GUI
{
	/**
	 * This class is the main window that is shown.
	 */
	class MainWindow
	{
		private: QStatusBar* statusbar;
		private: QMenuBar* menubar_project;
		private: QMenuBar* menubar_edit;
		private: QAction* action_newProject;
		private: QAction* action_undo;
		private: QAction* action_saveAs;
		private: QAction* action_loadProject;
		private: QAction* action_saveProject;
		private: QAction* action_redo;
		private: QTabWidget* tab_tabs;
		public: Model::Project* loadedProject;

		/// <summary>
		/// Constructor.
		/// </summary>
		public: MainWindow(GUI::QWidget* parent);

		/// <summary>
		/// Creates a memento which contains the state of the window.
		/// </summary>
		/// <returns>The created memento.</returns>
		public: Memento::MainWindowMemento getMemento();

		/// <summary>
		/// Restores the window based on the memento.
		/// </summary>
		/// <param name="memento">The memento which contains the state of the window.</param>
		public: void restore(Memento::MainWindowMemento memento);

		/// <summary>
		/// slot
		/// creates new project,
		/// removes existing one
		/// </summary>
		private: void newProject();

		/// <summary>
		/// Slot:connected with action_undo.triggered()
		/// undo last action if possible
		/// </summary>
		private: void undo();

		/// <summary>
		/// Slot:connected with action_saveAs.triggered()
		/// Opens QFileDialog and saves project in selected file
		/// </summary>
		private: void saveAs();

		/// <summary>
		/// Slot:connected with action_loadProject.triggered()
		/// opens QFileDialog and opens project in the selected file if possible
		/// </summary>
		private: void loadProject();

		/// <summary>
		/// Slot:connected with action_saveProject.triggered()
		/// opens QFileDialog and saves project in selected file
		/// </summary>
		private: void saveProject();

		/// <summary>
		/// Slot:connected with action_redo.triggered()
		/// redo action if undo has been used
		/// </summary>
		private: void redo();

		/// <summary>
		/// creates the UI
		/// </summary>
		private: void createUi();

		/// <summary>
		/// connect actions in the menuBars to the slots in this class
		/// </summary>
		private: void connectActions();

		private: void createMenuBar();

		/// <summary>
		/// Returns the project that is currently loaded.
		/// </summary>
		/// <returns>The currently loaded project.</returns>
		public: Model::Project& getProject();
	};
}

#endif
