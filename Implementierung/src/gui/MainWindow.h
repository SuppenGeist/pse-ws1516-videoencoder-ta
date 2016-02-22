#ifndef __MainWindow_h__
#define __MainWindow_h__

#include <memory>

#include <QStatusBar>
#include <QAction>
#include <QMenuBar>
#include <QTabWidget>
#include <QMainWindow>
#include <QStatusBar>

#include "../model/Project.h"

#include "../memento/MainWindowMemento.h"

namespace GUI {
class FilterTab;
class AnalysisTab;
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
	std::unique_ptr<Memento::MainWindowMemento> getMemento();

	/**
	 * @brief restore Restores the window based on the memento.
	 * @param memento The memento which contains the state of the window.
	 */
	void restore(Memento::MainWindowMemento* memento);

	QStatusBar* getStatusBar();

  private slots:
	/**
         * @brief newProject Creates new project.
	 */
	void newProject();

	/**
         * @brief undo Undoes last action if possible
	 */
	void undo();

	/**
	 * @brief saveAs Opens QFileDialog and saves project in selected file.
	 */
	void saveAs();

	/**
         * @brief loadProject Opens QFileDialog and opens project in the selected file if possible.
	 */
	void loadProject();

	/**
         * @brief saveProject Opens QFileDialog and saves project in selected file.
	 */
	void saveProject();

	/**
         * @brief redo Redoes action if undo has been used.
	 */
	void redo();

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

	std::unique_ptr<Model::Project> loadedProject_;

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

