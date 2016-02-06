#ifndef __MoveFilterDown_h__
#define __MoveFilterDown_h__

#include <QUndoCommand>

namespace GUI {
class FilterTab;
}

namespace UndoRedo
{
	/**
	 * This class is the undo command for moving a filter down in the filterlist.
     */
    class MoveFilterDown: public QUndoCommand
    {
        public:
        /**
         * @brief MoveFilterDown Constructor.
         * @param filterTab The filtertab to operate on.
         * @param old The old index of the filter.
         * @param new_2 The new index of the filter.
         */
        MoveFilterDown(GUI::FilterTab &filterTab, int index);

        /**
         * @brief undo Moves the filter one position back up in the filterlist.
         */
        void undo();

        /**
         * @brief redo Moves selected filter one position down in the filterlist.
         */
        void redo();

    private:
        int             index_;
        GUI::FilterTab* filterTab_;
	};
}

#endif
