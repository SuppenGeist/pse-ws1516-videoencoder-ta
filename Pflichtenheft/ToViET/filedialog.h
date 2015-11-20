#ifndef EXPLORER_H
#define EXPLORER_H

#include <QWidget>
#include <QtCore>
#include <QtGui>

namespace Ui {
class FileDialog;
}

class FileDialog : public QWidget
{
    Q_OBJECT

public:
    explicit Explorer(QWidget *parent = 0);
    ~Explorer();

private:
    Ui::Explorer *ui;
    QFileSystemModel *dirmodel;
    QFileSystemModel *filemodel;
};


#endif // EXPLORER_H
