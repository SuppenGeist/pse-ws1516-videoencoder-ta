#ifndef __FilterTab_h__
#define __FilterTab_h__

#include <QFrame>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QListView>
#include <QStringListModel>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QItemSelection>
#include <QTabWidget>

#include "FrameView.h"
#include "PlayerControlPanel.h"
#include "PreviewControlPanel.h"

namespace GUI {
class FilterTab: public QFrame {
    Q_OBJECT
public:
    FilterTab(QWidget* parent=0);

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

    QHBoxLayout*                        h_filterOptions_;
    QSpacerItem*                        spacer_filterOptions_;

    QTabWidget*                         tab_filtertabs_;

    void createUi();
    void createButtons();
    void createListView();
    void createVideoPlayer();
    void createFilterTabs();
    void connectAtions();
};

}

#endif


