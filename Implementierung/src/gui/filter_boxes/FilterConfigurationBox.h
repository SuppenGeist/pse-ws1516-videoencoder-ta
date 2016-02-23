#ifndef __FilterConfigurationBox_h__
#define __FilterConfigurationBox_h__

#include <memory>

#include <QWidget>
#include <QFrame>
#include <QImage>
#include <QVBoxLayout>
#include <QLabel>
#include <QScrollArea>
#include <QPushButton>


namespace Model {
class Filter;
}

namespace GUI {
class FrameView;
class FilterTab;
}

namespace GUI {
/**
 * This class is the base class for the configuration boxes for the filters.
 */
class FilterConfigurationBox:public QFrame {
	Q_OBJECT
  public:
	static std::unique_ptr<FilterConfigurationBox> CreateConfigurationBox(FilterTab& filterTab,
	        Model::Filter& filter);

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

	virtual void updateUi()=0;

    void setFilterIndex(std::size_t index);



  protected:
	std::unique_ptr<Model::Filter>  tempFilter_;
	QScrollArea*                    filterOptionsArea_;

	void updatePreview();
	void updateTempFilter();

  private slots:
	void applyFilter();
	void resetFilter();

  private:
	static std::unique_ptr<QImage>  defaultImage_;
	std::unique_ptr<QImage>         filteredImage_;
	FrameView*                      filterPreview_;
	QLabel*                         label_filter_;
	Model::Filter* filter_;
	QPushButton*                    button_apply_;
	QPushButton*                    button_reset_;
	FilterTab* filterTab_;
    std::size_t index_;
	static QImage &getDefaultImage();
	void createUi();




};
}

#endif

