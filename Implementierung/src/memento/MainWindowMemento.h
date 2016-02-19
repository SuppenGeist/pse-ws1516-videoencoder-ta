#ifndef __MainWindowMemento_h__
#define __MainWindowMemento_h__

#include <memory>

#include "AnalysisTabMemento.h"
#include "FilterTabMemento.h"

namespace Memento {
/**
 * This class is the memento for the MainWindow.
 */
class MainWindowMemento {

public:
    /**
     * @brief MainWindowMemento Constructor.
     */
    MainWindowMemento();

    /**
     * @brief getSelectedTab Returns the currently selected tab.
     * @return The currently selected tab.
     */
    int getSelectedTab();

    /**
     * @brief setSelectedTab Sets the currently selected tab.
     * @param selectedTab The currently selected tab.
     */
    void setSelectedTab(int selectedTab);

    /**
     * @brief getAnalysisTabMemento Returns the AnalysisTabMemento.
     * @return The AnalysisTabMemento.
     */
    Memento::AnalysisTabMemento* getAnalysisTabMemento();

    /**
     * @brief setAnalysisTabMemento Sets the AnalysisTabMemento.
     * @param analysisTabMeMento The AnalysisTabMemento.
     */
    void setAnalysisTabMemento(std::unique_ptr<AnalysisTabMemento> analysisTabMeMento);

    /**
     * @brief getFilterTabMemento Returns the FilterTabMemento.
     * @return The FilterTabMemento.
     */
    Memento::FilterTabMemento* getFilterTabMemento();

    /**
     * @brief setFilterTabMemento Sets the FilterTabMemento.
     * @param filterTabMemento The FilterTabMemento.
     */
    void setFilterTabMemento(std::unique_ptr<FilterTabMemento> filterTabMemento);

    private:
        int selectedTab_;
        std::unique_ptr<AnalysisTabMemento> analysisTab_;
        std::unique_ptr<FilterTabMemento> filterTab_;
};
}

#endif
