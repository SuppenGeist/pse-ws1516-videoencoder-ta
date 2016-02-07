#ifndef __MainWindow_h__
#define __MainWindow_h__

#include <QStatusBar>
#include <QAction>
#include <QMenuBar>
#include <QTabWidget>
#include <QMainWindow>

namespace GUI {
class FilterTab;
class AnalysisTab;
}
namespace Memento {
class MainWindowMemento;
}
namespace Model {
class Project;
}
namespace Ui {
class MainWindow;
}

namespace GUI {
/**
 * This class is the main window that is shown.
 */
class MainWindow : public QMainWindow {
	Q_OBJECT

  public:
	/**
	 * @brief MainWindow Constructor.
	 * @param parent
	 */
	MainWindow(QWidget* parent = 0);

	/**
	 * @brief getMemento Creates a memento which contains the state of the window.
	 * @return The created memento.
	 */
	Memento::MainWindowMemento getMemento();

	/**
	 * @brief restore Restores the window based on the memento.
	 * @param memento The memento which contains the state of the window.
	 */
	void restore(Memento::MainWindowMemento memento);

  private slots:
	/**
	 * @brief newProject creates new project.
	 */
	void newProject();

	/**
	 * @brief undo undo last action if possible
	 */
	void undo();

	/**
	 * @brief saveAs Opens QFileDialog and saves project in selected file.
	 */
	void saveAs();

	/**
	 * @brief loadProject opens QFileDialog and opens project in the selected file if possible.
	 */
	void loadProject();

	/**
	 * @brief saveProject opens QFileDialog and saves project in selected file.
	 */
	void saveProject();

	/**
	 * @brief redo redo action if undo has been used.
	 */
	void redo();

	/**
	 * @brief getProject Returns the current loaded Project.
	 * @return the current project
	 */
	Model::Project* getProject();

  private:

    QStatusBar* statusbar_;
    QAction* action_newProject_;
    QAction* action_undo_;
    QAction* action_saveAs_;
    QAction* action_loadProject_;
    QAction* action_saveProject_;
    QAction* action_redo_;
    QTabWidget* tab_tabs_;
    FilterTab* filterTab_;
    AnalysisTab* analysisTab_;
    Ui::MainWindow *ui_;
    Model::Project* loadedProject_;

	/**
	 * @brief createUi creates the UI.
	 */
	void createUi();

	/**
	 * @brief connectActions connect actions in the menuBars to the slots in this class.
	 */
	void connectActions();
};
}

#endif

