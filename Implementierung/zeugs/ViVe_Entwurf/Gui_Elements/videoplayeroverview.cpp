#include "videoplayeroverview.h"
#include "ui_videoplayeroverview.h"

VideoPlayerOverview::VideoPlayerOverview(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::VideoPlayerOverview)
{
    ui->setupUi(this);
}

VideoPlayerOverview::~VideoPlayerOverview()
{
    delete ui;
}
