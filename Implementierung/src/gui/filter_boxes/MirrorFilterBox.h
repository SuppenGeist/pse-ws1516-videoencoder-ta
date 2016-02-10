#ifndef __MirrorFilterBox_h__
#define __MirrorFilterBox_h__

#include <QWidget>
#include <QRadioButton>

#include "FilterConfigurationBox.h"

namespace GUI
{
	/**
	 * This class contains the gui elements for changing the options of a mirror filter.
    */
class MirrorFilterBox: public FilterConfigurationBox
{
    Q_OBJECT
    public:
    /**
     * @brief MirrorFilterBox Constructor.
     * @param parent
    */
    MirrorFilterBox(QWidget* parent=0);

protected:
    void updateUi() override;

private slots:
    void vertical(bool);
    void horizontal(bool);
private:

    QRadioButton*    vertical_;
    QRadioButton*    horizontal_;

    virtual void createFilterOptions();
};
}

#endif

