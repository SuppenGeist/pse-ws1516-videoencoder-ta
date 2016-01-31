#include "FilterView.h"

#include <QWidget>


#include "FilterTab.h"
#include "../model/filters/Filter.h"
#include "../model/FilterList.h"

namespace GUI {
FilterView::FilterView(QWidget* parent):QFrame(parent) {
    resize(200,200);

    QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
            sizePolicy.setHorizontalStretch(0);
            sizePolicy.setVerticalStretch(0);
            setSizePolicy(sizePolicy);
            setMinimumSize(QSize(210, 170));
            setMaximumSize(QSize(210, 170));
            setFrameShape(QFrame::StyledPanel);
            setFrameShadow(QFrame::Raised);
            verticalLayoutWidget = new QWidget(this);
            verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
            verticalLayoutWidget->setGeometry(QRect(0, 0, 202, 171));
            verticalLayout = new QVBoxLayout(verticalLayoutWidget);
            verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
            verticalLayout->setContentsMargins(0, 0, 0, 0);
            preview = new QLabel(verticalLayoutWidget);
            QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Ignored);
            sizePolicy1.setHorizontalStretch(0);
            sizePolicy1.setVerticalStretch(0);
            preview->setSizePolicy(sizePolicy1);
            preview->setMinimumSize(QSize(200, 150));
            preview->setMaximumSize(QSize(200, 150));
            preview->setPixmap(QPixmap(QString::fromUtf8(":pictures/resources/flower_example.png")));
            preview->setScaledContents(true);
            checkbox = new QCheckBox(verticalLayoutWidget);
            checkbox->setText(QString("test"));
            verticalLayout->addWidget(preview);
            verticalLayout->addWidget(checkbox);
}

void GUI::FilterView::checkBoxStateChanged(int state) {
    /*if(state = 0) {
        filterTab->removeFilter(filter->getName());
    } else {
        filterTab->addFilter(filter);
    }*/
}

void GUI::FilterView::setFilter(Model::Filter* filter) {

    this->filter = filter;
    checkbox->setText(QString::fromStdString(filter->getName()));
    /*
    Model::FilterList *filterlist = new Model::FilterList();
    filterlist->addFilter(filter->getName());

    Utility::FilterApplier *filterApplier = new FilterApplier(filterlist);
    //magicalle confert png to av frame
    filterapplier->applyToFrame(magic);
    //convert av frame to QPixmap or string path (more magic)
    preview->setPixmap(magix);
    */



}


void GUI::FilterView::setFilterTab(FilterTab* filtertab) {
    Q_UNUSED(filtertab);
    //this->filterTab = filtertab;
}

}
