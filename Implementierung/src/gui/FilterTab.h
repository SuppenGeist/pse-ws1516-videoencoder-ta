#ifndef __FilterTab_h__
#define __FilterTab_h__

#include <string>
#include <vector>
#include <QPushButton>
#include <QListWidget>
#include <QStringListModel>
#include <QLabel>
#include <QFrame>



namespace Ui {
class FilterTab;
}
namespace GUI {
class VideoPlayer;
class PreviewControlPanel;
class FrameView;
class PlayerControlPanel;
class FilterContainerTab;
}
namespace Memento {
class FilterTabMemento;
}
namespace Model {
class FilterList;
class YuvVideo;
class Filter;
}
namespace UndoRedo {
class LoadFilterVideo;
}
namespace GUI {
/**
 * This class is the tab to filter videos.
*/
class FilterTab : public QFrame {
	Q_OBJECT

  public:
	/**
	 *@brief Contructor
	 *
	*/
	FilterTab(QWidget* parent);



	/**
	 * @brief removeFilter removes teh given filter form the filterList
	 * @param filterName name of the filter
	 */
	void removeFilter(std::string filterName);


	/**
	 * @brief showVideo Shows the video with the applied filters.
	 */
	void showVideo();

	/**
	 * @brief showPreview Shows the 5 frame preview.
	 */
	void showPreview();

	/**
	 * @brief resetFilters Resets the filterlist.
	 */
	void resetFilters();

	/**
	 * @brief setFilterList Sets the filterlist.
	 * @param list The filterlist to use.
	 */
	void setFilterList(Model::FilterList list);

	/**
	 * @brief setRawVideo Sets the video the filters are applied to. This operation resets the whole filtertab.
	 * @param video The video to apply the filters on.
	 */
	void setRawVideo(Model::YuvVideo video);

	/**
	 * @brief moveFilter Moves a filter in the filterlist.
	 * @param old old  list index
	 * @param newIndex new  list index
	 */
	void moveFilter(int oldIndex, int newIndex);

	/**
	 * @brief getMemento Creates a memento which contains the state of this tab.
	 * @return the created memento
	 */
	Memento::FilterTabMemento getMemento();

	/**
	 * @brief restore Restores the tab based on the memento.
	 * @param memento The memento which contains the state of the tab.
	 */
	void restore(Memento::FilterTabMemento memento);

	/**
	 * @brief insertFilter Inserts a filter to the filterList. If index is -1 the the filter is added to the end.
	 * @param filter The filter to add.
	 * @param index The index to insert the filter at.
	 */
	void insertFilter(Model::Filter& filter, int index = -1);


  private slots :

	/**
	 * @brief up increases the index of selected filter in the list
	 */
	void up();

	/**
	 * @brief down decreases the index of a filter in the list
	 */
	void down();

	/**
	 * @brief remove removes a filter from the list
	 */
	void remove();

	/**
	 * @brief load opens QFileDialog and opens the video in the selected path
	 */
	void load();

	/**
	 * @brief apply applies the filter list on the video and shows it
	 */
	void apply();

	/**
	 * @brief saveConf opens QFileDialog and saves the filter configuration in the selected path
	 */
	void saveConf();

	/**
	 * @brief loadConf opens QFileDialog and loads the filter configuration in the selected path
	 */
	void loadConf();

	/**
	 * @brief reset resets the filter list
	 */
	void reset();

	/**
	 * @brief listSelectionChanged updates the filterConfigurationBox that is shown
	 * @param index Index of the selected item
	 */
	void listSelectionChanged(QModelIndex* index);

	/**
	 * @brief save opens QFileDialog and saves the video with the filters used on it.
	 */
	void save();

  private:
	/**
	 * @brief connectAction sConnect the buttons to their slots in this class.
	 */
	void connectActions();

	/**
	 * @brief createUi Creates the user interface.
	 */
	void createUi();
  private:
	QPushButton* button_up;
  private:
	QPushButton* button_down;
  private:
	QPushButton* button_remove;
  private:
	QPushButton* button_load;
  private:
	QPushButton* button_apply;
  private:
	QPushButton* button_saveConf;
  private:
	QPushButton* button_loadConf;
  private:
	QPushButton* button_reset;
  private:
	QPushButton* button_save;
  private:
	QListWidget* list_filterList;
  private:
	QTabWidget* tab_filterTabs;
  private:
	QLabel* label_filterOptions;
  private:
	QFrame* frame_filterContainer;
  private:
	QStringListModel* model_list;
  private:
	GUI::VideoPlayer* player;
  private:
	GUI::PreviewControlPanel* previewPanel;
  private:
	GUI::FrameView* frameView;
  private:
	GUI::PlayerControlPanel* playerPanel;
  private:
	Model::FilterList* filterList;
  private:
	Model::YuvVideo* rawVideo;
  private:
	std::vector<GUI::FilterContainerTab*> filterContainerTab;
  private:
	Ui::FilterTab *ui;
  public:
	UndoRedo::LoadFilterVideo* filterTab;
};
}

#endif


