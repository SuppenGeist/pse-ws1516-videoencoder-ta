#ifndef __FilterConfigurationBox_h__
#define __FilterConfigurationBox_h__

#include <QWidget>
#include <QFrame>
#include <QImage>
#include <QVBoxLayout>
#include <QLabel>
#include <QScrollArea>
#include <QPushButton>

#include <memory>

namespace Model {
class Filter;
}

namespace GUI {
class FrameView;
class FilterTab;
}

namespace GUI
{
	/**
	 * This class is the base class for the configuration boxes for the filters.
     */
    class FilterConfigurationBox:public QFrame
    {
        Q_OBJECT
        public:
        static std::unique_ptr<FilterConfigurationBox> CreateConfigurationBox(FilterTab& filterTab,Model::Filter& filter);

        /**
         * @brief FilterConfigurationBox Constructor.
         * @param parent
         */
        FilterConfigurationBox(QWidget* parent=0);

        virtual ~FilterConfigurationBox();

        /**
         * @brief setFilter Sets the filter the filterbox is responsible for.
         * @param filter The filter to show the options for.
         */
        void setFilter(Model::Filter& filter);

        /**
         * @brief getFilter Returns the filter the filterbox is responsible for.
         * @return The filter the filterbox shows the options for.
         */
        Model::Filter* getFilter();

        void setFilterTab(FilterTab& filterTab);




        protected:
            std::unique_ptr<Model::Filter>  tempFilter_;
            QScrollArea*                    filterOptionsArea_;

            void updatePreview();
            virtual void updateUi()=0;

    private slots:
            void applyFilter();

    private:
            static std::unique_ptr<QImage>  defaultImage_;
            std::unique_ptr<QImage>         filteredImage_;
            FrameView*                      filterPreview_;
            QLabel*                         label_filter_;
            Model::Filter* filter_;
            QPushButton*                    button_apply_;
            FilterTab* filterTab_;
            static QImage &getDefaultImage();
            void createUi();




	};
}

#endif

