#ifndef __ApplyFilter_h__
#define __ApplyFilter_h__

#include <QUndoCommand>

#include <memory>

#include "../gui/FilterTab.h"
#include "../model/Video.h"
#include "../model/FilterList.h"
#include "../utility/FilterApplier.h"
#include "../memento/FilterTabMemento.h"

namespace UndoRedo
{
	/**
	 * This class is the undo command for applying filters on the filtertab.
     */
    class ApplyFilter: public QUndoCommand
    {
        public:
        /**
         * @brief ApplyFilter Constuctor
         * @param filterTab
         */
        ApplyFilter(GUI::FilterTab& filterTab, Model::Video *origVideo, std::unique_ptr<Model::FilterList> filterlist);

        /**
         * @brief undo Shows the 5 frame preview.
         */
        void undo();

        /**
         * @brief redo Shows the complete video with applied filters.
         */
        void redo();

        private:
        GUI::FilterTab*                         filterTab_;
        Model::Video*                        originalVideo_;
        std::unique_ptr<Utility::FilterApplier> applier_;
        std::unique_ptr<Model::Video>           filteredVideo_;
        std::unique_ptr<Model::FilterList>      filterlist_;
        std::unique_ptr<Memento::FilterTabMemento>  memento_;
	};
}

#endif
