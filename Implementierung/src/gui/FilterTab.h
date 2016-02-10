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

#include "../memento/FilterTabMemento.h"

#include "../model/YuvVideo.h"
#include "../model/FilterList.h"
#include "../model/filters/Filter.h"
#include "../model/AVVideo.h"
#include "../model/Video.h"

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

    Model::Filter* appendFilter(QString filtername);

    std::unique_ptr<Model::Filter> removeFilter(std::size_t index);

    Model::FilterList* getFilterList();

    void setFilterList(std::unique_ptr<Model::FilterList> filterlist);

    void resetFilters();

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

    QTabWidget*                         tab_filtertabs_;

    Model::YuvVideo*                    rawVideo_;
    std::unique_ptr<Model::FilterList>  filterlist_;
    std::unique_ptr<Model::AVVideo>     originalPreviewFrames_;
    std::unique_ptr<Model::Video>       filteredPreviewFrames_;

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


