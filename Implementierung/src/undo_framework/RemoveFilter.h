#ifndef __RemoveFilter_h__
#define __RemoveFilter_h__

#include <QUndoCommand>

#include <memory>

namespace GUI {
class FilterTab;
}

namespace Model {
class Filter;
}

namespace UndoRedo
{
	/**
	 * This class is the undo command for removing a filter in the filterlist on the filtertab.
     */
    class RemoveFilter: public QUndoCommand
    {
        public:
        /**
         * @brief RemoveFilter Constructor.
         * @param filterTab The filtertab to operate on.
         * @param index The current index of the filter to remove.
         */
        RemoveFilter(GUI::FilterTab& filterTab, int index);

        /**
         * @brief undo Adds the removed filter back into the filterlist.
         */
        void undo();

        /**
         * @brief redo Removes a filter from the filterlist.
         */
        void redo();

    private:
        int                             index_;
        GUI::FilterTab*                 filterTab_;
        std::unique_ptr<Model::Filter>  filter_;
	};
}

#endif
