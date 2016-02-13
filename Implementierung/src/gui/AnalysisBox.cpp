#include "AnalysisBox.h"

#include <QFrame>
#include <QWidget>
#include <QHBoxLayout>
#include <QTabWidget>

#include "FrameView.h"
#include "GraphWidget.h"

GUI::AnalysisBox::AnalysisBox(QWidget* parent) : QFrame(parent) {
    createUi();
    setContentsMargins(0,0,0,0);
    setFixedHeight(220);
}

void GUI::AnalysisBox::createUi()
{
    origView_=new FrameView;
    origView_->setFixedSize(200,200);

    anaView_=new FrameView;
    anaView_->setFixedSize(200,200);

    graphWidget_=new GraphWidget;

    tabs_graphs_=new QTabWidget;
    tabs_graphs_->setTabPosition(QTabWidget::West);
    tabs_graphs_->addTab(graphWidget_,"Graphs");
    QWidget* attr=new QWidget;
    tabs_graphs_->addTab(attr,"Video");


    QHBoxLayout* h_content=new QHBoxLayout;

    h_content->addSpacing(2);
    h_content->addWidget(origView_);
    h_content->addSpacing(5);
    h_content->addWidget(tabs_graphs_);
    h_content->addSpacing(5);
    h_content->addWidget(anaView_);
    h_content->addSpacing(10);

    setLayout(h_content);
}
