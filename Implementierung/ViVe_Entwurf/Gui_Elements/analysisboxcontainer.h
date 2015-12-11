#ifndef ANALYSISBOXCONTAINER_H
#define ANALYSISBOXCONTAINER_H

#include <QScrollArea>

namespace Ui {
class AnalysisBoxContainer;
}

class AnalysisBoxContainer : public QScrollArea
{
    Q_OBJECT

public:
    explicit AnalysisBoxContainer(QWidget *parent = 0);
    ~AnalysisBoxContainer();

private:
    Ui::AnalysisBoxContainer *ui;
};

#endif // ANALYSISBOXCONTAINER_H
