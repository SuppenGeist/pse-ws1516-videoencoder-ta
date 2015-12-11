#ifndef ANALYSISBOX_H
#define ANALYSISBOX_H

#include <QGroupBox>

namespace Ui {
class AnalysisBox;
}

class AnalysisBox : public QGroupBox
{
    Q_OBJECT

public:
    explicit AnalysisBox(QWidget *parent = 0);
    ~AnalysisBox();

private:
    Ui::AnalysisBox *ui;
};

#endif // ANALYSISBOX_H
