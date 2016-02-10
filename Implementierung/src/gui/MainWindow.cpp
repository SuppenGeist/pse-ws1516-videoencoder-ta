#include "MainWindow.h"

#include <QWidget>
#include <QMainWindow>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QHBoxLayout>

#include "ui_mainwindow.h"
#include "FilterTab.h"
#include "AnalysisTab.h"
#include "../memento/MainWindowMemento.h"
#include "../undo_framework/UndoStack.h"
#include "../utility/ProjectReader.h"
#include "../utility/ProjectWriter.h"
#include "../model/Project.h"


GUI::MainWindow::MainWindow(QWidget* parent):QMainWindow(parent) {
	createUi();
	connectActions();
    loadedProject_ = new Model::Project(QString("new_Project"));
    analysisTab_->setProject(loadedProject_);
}

Memento::MainWindowMemento GUI::MainWindow::getMemento() {
    Memento::MainWindowMemento memo;
    memo.setAnalysisTabMemento(analysisTab_->getMemento());
    memo.setFilterTabMemento(filterTab_->getMemento());
    //memo.setSelectedTab(ui_->tab_tabs->currentIndex());
    return memo;
}

void GUI::MainWindow::restore(Memento::MainWindowMemento memento) {
    analysisTab_->restore(memento.getAnalysisTabMemento());
    filterTab_->restore(memento.getFilterTabMemento());
    //ui_->tab_tabs->setCurrentIndex(memento.getSelectedTab());
}

void GUI::MainWindow::newProject() {
    loadedProject_ = new Model::Project(QString("new_Project"));
    loadedProject_->setPath(QString(""));
    analysisTab_->setProject(loadedProject_);
    createUi();
    UndoRedo::UndoStack::getUndoStack().clear();
}

void GUI::MainWindow::undo() {
    UndoRedo::UndoStack::getUndoStack().undo();
}

void GUI::MainWindow::saveAs() {
    if (loadedProject_->getPath().size()==0) {
        saveProject();
    } else {
       Utility::ProjectWriter w = Utility::ProjectWriter(*loadedProject_);
       w.saveProject();
    }
}

void GUI::MainWindow::loadProject() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "/", tr("Text Files (*.txt)"));

    if(fileName.length() > 0) {
        Utility::ProjectReader w = Utility::ProjectReader(fileName);
        *loadedProject_ = w.readProject();
    }
    restore(loadedProject_->getMemento());
    analysisTab_->setProject(loadedProject_);
}

void GUI::MainWindow::saveProject() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "/", tr("Text Files (*.txt)"));
    if(fileName.length() > 0) {
        loadedProject_->setPath(fileName);
        Utility::ProjectWriter w = Utility::ProjectWriter(*loadedProject_);
        w.saveProject();
    }
}

void GUI::MainWindow::redo() {
	UndoRedo::UndoStack::getUndoStack().redo();
}

void GUI::MainWindow::createUi() {
    ui_ = new Ui::MainWindow;

    ui_->setupUi(this);

    statusbar_=ui_->statusbar;
    action_newProject_=ui_->actionNew;
    action_loadProject_=ui_->actionLoad;
    action_saveAs_=ui_->actionSaveAs;
    action_saveProject_=ui_->actionSave;
    action_redo_=ui_->actionRedo;
    action_undo_=ui_->actionUndo;

    QVBoxLayout* v_content=new QVBoxLayout;
    v_content->addSpacing(10);

    QHBoxLayout* h_tabs=new QHBoxLayout;
    h_tabs->addSpacing(5);

    tab_tabs_=new QTabWidget;

    QWidget* wrapper_filter=new QWidget;
    wrapper_filter->setObjectName("filterWrapper");
    wrapper_filter->setStyleSheet("QWidget#filterWrapper {"
                                  "background-color:rgb(235,235,235);"
                                  "}");
    QVBoxLayout* v_filterTab=new QVBoxLayout;
    filterTab_=new FilterTab;
    v_filterTab->addWidget(filterTab_);
    wrapper_filter->setLayout(v_filterTab);

    tab_tabs_->addTab(wrapper_filter,"Filters and artefacts");

    QWidget* wrapper_analysis=new QWidget;
    wrapper_analysis->setObjectName("analysisWrapper");
    wrapper_analysis->setStyleSheet("QWidget#analysisWrapper {"
                                  "background-color:rgb(235,235,235);"
                                  "}");
    QVBoxLayout* v_analysisTab=new QVBoxLayout;
    analysisTab_=new AnalysisTab;
    v_analysisTab->addWidget(analysisTab_);
    wrapper_analysis->setLayout(v_analysisTab);

    tab_tabs_->addTab(wrapper_analysis,"Analysis");

    h_tabs->addWidget(tab_tabs_);
    h_tabs->addSpacing(5);

    v_content->addLayout(h_tabs);

    centralWidget()->setLayout(v_content);
}

void GUI::MainWindow::connectActions() {
    connect(action_loadProject_,SIGNAL(triggered()),this,SLOT(loadProject()));
    connect(action_newProject_, SIGNAL(triggered()),this,SLOT(newProject()));
    connect(action_saveProject_,SIGNAL(triggered()),this, SLOT(saveProject()));
    connect(action_redo_,SIGNAL(triggered()),this, SLOT(redo()));
    connect(action_saveAs_,SIGNAL(triggered()),this, SLOT(saveAs()));
    connect(action_undo_,SIGNAL(triggered()),this, SLOT(undo()));
}

Model::Project* GUI::MainWindow::getProject() {
    return loadedProject_;
}


