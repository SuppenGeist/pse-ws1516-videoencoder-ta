#ifndef FILEEXPLORER_H
#define FILEEXPLORER_H

#include <QDialog>
#include <QFileSystemModel>

namespace Ui {
class FileExplorer;
}

class FileExplorer : public QDialog
{
    Q_OBJECT

public:
    explicit FileExplorer(QWidget *parent = 0);
    ~FileExplorer();

private:
    Ui::FileExplorer *ui;
    QFileSystemModel *dirmodel;
    QFileSystemModel *filemodel;
};

#endif // FILEEXPLORER_H
