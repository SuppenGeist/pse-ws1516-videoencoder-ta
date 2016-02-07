#ifndef __FilterConfigurationBox_h__
#define __FilterConfigurationBox_h__

#include <QWidget>
#include <QFrame>
#include <QImage>
#include <QVBoxLayout>
#include <QLabel>
#include <QScrollArea>

#include <memory>

namespace Model {
class Filter;
}

namespace GUI {
class FrameView;
}

namespace GUI
{
	/**
	 * This class is the base class for the configuration boxes for the filters.
     */
    class FilterConfigurationBox:public QFrame
    {
        public:
        static std::unique_ptr<FilterConfigurationBox> CreateConfigurationBox(Model::Filter& filter);
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


        void createUi();


        protected:
            std::unique_ptr<Model::Filter>  tempFilter_;
            QLabel*                         label_filter_;
            QVBoxLayout*    v_filterOptions_;
            QHBoxLayout*    h_content;

            void updatePreview();

            virtual void createFilterOptions();


    private:
            static std::unique_ptr<QImage>  defaultImage_;
            std::unique_ptr<QImage>         filteredImage_;
            FrameView*                      filterPreview_;
            Model::Filter* filter_;
            QScrollArea*                    filterOptionsArea_;

            static QImage &getDefaultImage();




	};
}

#endif

