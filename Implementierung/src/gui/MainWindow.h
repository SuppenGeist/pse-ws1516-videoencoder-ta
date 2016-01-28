/*#include <exception>
using namespace std;
#ifndef __MainWindow_h__
#define __MainWindow_h__

// #include "QWidget.h"
#include "memento/MainWindowMemento.h"
#include "model/Project.h"
#include <QStatusBar>
#include <QAction>
#include <QMenuBar>
#include <QTabWidget>
#include <QMainWindow>
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
namespace Ui {
class MainWindow;
}
namespace GUI
{
	/**
	 * This class is the main window that is shown.

    class MainWindow : public QMainWindow
    {
        Q_OBJECT
        private: QStatusBar* statusbar;
		private: QAction* action_newProject;
		private: QAction* action_undo;
		private: QAction* action_saveAs;
		private: QAction* action_loadProject;
		private: QAction* action_saveProject;
		private: QAction* action_redo;
		private: QTabWidget* tab_tabs;
        private: Ui::MainWindow *ui;
        public: Model::Project* loadedProject;
		/// <summary>
		/// Constructor.
		/// </summary>
    public: MainWindow(QWidget* parent = 0);

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
        /// creates the UI
        /// </summary>
        private: void createUi();

        /// <summary>
        /// connect actions in the menuBars to the slots in this class
        /// </summary>
        private: void connectActions();

        public slots:
		/// <summary>
		/// slot
		/// creates new project,
		/// removes existing one
		/// </summary>
            void newProject();

		/// <summary>
		/// Slot:connected with action_undo.triggered()
		/// undo last action if possible
		/// </summary>
        void undo();

		/// <summary>
		/// Slot:connected with action_saveAs.triggered()
		/// Opens QFileDialog and saves project in selected file
		/// </summary>
        void saveAs();

		/// <summary>
		/// Slot:connected with action_loadProject.triggered()
		/// opens QFileDialog and opens project in the selected file if possible
		/// </summary>
        void loadProject();

		/// <summary>
		/// Slot:connected with action_saveProject.triggered()
		/// opens QFileDialog and saves project in selected file
		/// </summary>
        void saveProject();

		/// <summary>
		/// Slot:connected with action_redo.triggered()
		/// redo action if undo has been used
		/// </summary>
        void redo();


		public: Model::Project& getProject();
	};
}

#endif
*/
