#ifndef __AddFilter_h__
#define __AddFilter_h__

#include <QUndoCommand>
#include <QString>

#include <memory>

namespace Model {
    class Filter;
}
namespace GUI {
    class FilterTab;
}

namespace UndoRedo
{
	/**
	 * This is the undo command for adding a filter to the filterlist on the filtertab.
     */
    class AddFilter: public QUndoCommand
    {
        public:
        /**
         * @brief AddFilter Constructor.
         * @param filterTab The filtertab to operate on.
         * @param filter The filter on which the operation is performed on.
         */
        AddFilter(GUI::FilterTab& filterTab, QString filtername);

        /**
         * @brief undo Removes the added filter from the filterlist.
         */
        void undo();

        /**
         * @brief redo Adds a filter to the filterlist.
         */
        void redo();

    private:

        GUI::FilterTab* filterTab_;
        QString         filtername_;
	};
}

#endif
