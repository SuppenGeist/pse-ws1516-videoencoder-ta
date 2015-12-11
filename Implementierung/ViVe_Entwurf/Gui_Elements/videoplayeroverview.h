#ifndef VIDEOPLAYEROVERVIEW_H
#define VIDEOPLAYEROVERVIEW_H

#include <QFrame>

namespace Ui {
class VideoPlayerOverview;
}

class VideoPlayerOverview : public QFrame
{
    Q_OBJECT

public:
    explicit VideoPlayerOverview(QWidget *parent = 0);
    ~VideoPlayerOverview();

private:
    Ui::VideoPlayerOverview *ui;
};

#endif // VIDEOPLAYEROVERVIEW_H
