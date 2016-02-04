#ifndef __FilterTab_h__
#define __FilterTab_h__

#include <memory>

#include <QPushButton>
#include <QWidget>
#include <QFrame>
#include <QListWidget>
#include <QStringListModel>
#include <QLabel>
#include <QTabWidget>

#include "../model/YuvVideo.h"
#include "VideoPlayer.h"

namespace GUI {
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
class Filter;
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
	void setRawVideo(std::unique_ptr<Model::YuvVideo> video);

	/**
	 * @brief releaseVideo releases the Video
	 * @return
	 */
	std::unique_ptr<Model::YuvVideo> releaseVideo();

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
	std::unique_ptr<Memento::FilterTabMemento> getMemento();

	/**
	 * @brief restore Restores the tab based on the memento.
	 * @param memento The memento which contains the state of the tab.
	 */
	void restore(Memento::FilterTabMemento& memento);

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
	QPushButton*                        button_up_;
	QPushButton*                        button_down_;
	QPushButton*                        button_remove_;
	QPushButton*                        button_load_;
	QPushButton*                        button_apply_;
	QPushButton*                        button_saveConf_;
	QPushButton*                        button_loadConf_;
	QPushButton*                        button_reset_;
	QPushButton*                        button_save_;
	QLabel*                             label_selectedFilters_;
	QListWidget*                        list_filterList_;
	QTabWidget*                         filterTabs_;
	QLabel*                             label_filterOptions_;
	QStringListModel*                   model_list_;
	std::vector<FilterContainerTab*>    filterContainerTab_;

	std::unique_ptr<VideoPlayer>        player_;
	PreviewControlPanel*                previewPanel_;
	FrameView*                          frameView_;
	PlayerControlPanel*                 playerPanel_;

	Model::FilterList*                  filterList_;
    std::unique_ptr<Model::YuvVideo>    rawVideo_;


	/**
	 * @brief connectAction sConnect the buttons to their slots in this class.
	 */
	void connectActions();

	/**
	 * @brief createUi Creates the user interface.
	 */
    void createUi();

};
}

#endif


