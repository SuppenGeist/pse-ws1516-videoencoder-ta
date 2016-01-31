#ifndef __FilterView_h__
#define __FilterView_h__

#include <QFrame>
#include <QWidget>
#include <QCheckBox>
#include <QLabel>
#include <QVBoxLayout>

#include "FilterTab.h"
#include "../model/filters/Filter.h"

namespace GUI
{
    class FilterTab;
	class FilterView;
}
namespace Model
{
	class Filter;
}

namespace GUI
{
	/**
	 * Represents a selectable filter in the gui. Shows a example of the filter and  a checkbox as well as its name.
    */
    class FilterView : public QFrame
	{
        Q_OBJECT

    public:
        /**
         * @brief FilterViewCcontructor
         * @param parent Parent of object
         */
        FilterView(QWidget* parent);

        /**
         * @brief setFilter Sets the filter this view represents.
         * @param filter The filter for this view.
         */
        void setFilter(Model::Filter* filter);

        /**
         * @brief setFilterTab Sets the tab this view is contained in.
         * @param filtertab The parent filtertab.
         */
        void setFilterTab(GUI::FilterTab* filtertab);

        /**
         * @brief uncheck Unchecks the checkbox
         */
        void uncheck();

        private:
        /**
         * @brief getDefaultImage Returns the default image on which the filter is applied as a preview.
         * @return The default image.
         */
        static QImage getDefaultImage() {
            throw "Not yet implemented";
        }

        /**
         * @brief checkBoxStateChanged Does filterTab.addFilter(filter) or filterTab.removeFilter(filter.getName())
         * @param state The state of the the checked checkbox
         */
        void checkBoxStateChanged(int state);




		/// <summary>
        ///
		/// </summary>
        /// <returns></returns>

        private:
            QCheckBox* checkbox;
            QLabel* preview;
            GUI::FilterTab* filterTab;
            Model::Filter* filter;
            QWidget* verticalLayoutWidget;
            QVBoxLayout* verticalLayout;

	};
}

#endif

