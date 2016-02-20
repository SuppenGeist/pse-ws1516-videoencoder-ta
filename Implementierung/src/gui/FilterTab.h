#ifndef __FilterTab_h__
#define __FilterTab_h__

#include <memory>

#include <QFrame>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QListView>
#include <QStringListModel>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QItemSelection>
#include <QString>
#include <QTabWidget>

#include "FrameView.h"
#include "PlayerControlPanel.h"
#include "PreviewControlPanel.h"
#include "VideoPlayer.h"
#include "MainWindow.h"
#include "filter_boxes/FilterConfigurationBox.h"

#include "../memento/FilterTabMemento.h"

#include "../model/YuvVideo.h"
#include "../model/FilterList.h"
#include "../model/filters/Filter.h"
#include "../model/AVVideo.h"
#include "../model/Video.h"

#include "../utility/FilterApplier.h"
#include "../utility/YuvFileSaver.h"
#include "../utility/FilterApplier.h"

namespace GUI {
class FilterTab: public QFrame {
	Q_OBJECT
  public:
	FilterTab(QWidget* parent=0);

	std::unique_ptr<Memento::FilterTabMemento> getMemento();

	void restore(Memento::FilterTabMemento* memento);

	void setRawVideo(Model::YuvVideo* rawVideo);

	void showRawVideo();

	void showFilterPreview();

	void updateFilterPreview();

	void changeFilter(int index,QString newState);

	void insertFilter(std::unique_ptr<Model::Filter> filter,std::size_t index);

	Model::Filter* appendFilter(QString filtername);

	std::unique_ptr<Model::Filter> removeFilter(std::size_t index);

	void moveFilter(std::size_t oldIndex,std::size_t newIndex);

	Model::FilterList* getFilterList();

	void setFilterList(std::unique_ptr<Model::FilterList> filterlist);

	void resetFilters();

	void showFilteredVideo();

	void setMainWindow(GUI::MainWindow* mainwindow);

	MainWindow *getMainWindow();

  signals:
    void saveComplete(bool successful,QString filename,int width,int height);
	void applyComplete(bool successful);

  private slots:
	void up();
	void down();
	void remove();
	void load();
	void apply();
	void save();
	void saveConfiguration();
	void loadConfiguration();
	void reset();
	void listSelectionChanged(QItemSelection selection);
    void notifyOnSaveComplete(bool successful,QString filename,int width,int height);
	void notifyOnApplyComplete(bool successful);


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

	QListView*                          list_filterlist_;
	QStringListModel*                   model_filterlist_;

	FrameView*                          frameView_;
	PlayerControlPanel*                 playerControlPanel_;
	PreviewControlPanel*                PreviewControlPanel_;
	QVBoxLayout*                        v_player_;
	std::unique_ptr<VideoPlayer>        player_;

	QHBoxLayout*                        h_filterOptions_;
	QSpacerItem*                        spacer_filterOptions_;
	FilterConfigurationBox*             currentFilterOptionsBox_;

	QTabWidget*                         tab_filtertabs_;

	Model::YuvVideo*                    rawVideo_;
	std::unique_ptr<Model::FilterList>  filterlist_;
	std::unique_ptr<Model::AVVideo>     originalPreviewFrames_;
	std::unique_ptr<Model::Video>       filteredPreviewFrames_;
	std::unique_ptr<Utility::FilterApplier> previewCalculator_;
	std::unique_ptr<Utility::FilterApplier> filterApplier_;
	std::unique_ptr<Model::Video>       filteredVideo_;

	bool                                isFilteredVideoShown_;

	std::unique_ptr<Utility::YuvFileSaver> safer_;

	GUI::MainWindow*                    mainWindow_;

	void createUi();
	void createButtons();
	void createListView();
	void createVideoPlayer();
	void createFilterTabs();
	void connectAtions();
	void initPlayer();
	void initFilterList();
	void calculatePreviewFrames();
};

}

#endif


