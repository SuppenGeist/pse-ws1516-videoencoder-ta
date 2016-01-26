/********************************************************************************
** Form generated from reading UI file 'videoplayeroverview.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOPLAYEROVERVIEW_H
#define UI_VIDEOPLAYEROVERVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VideoPlayerOverview
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QComboBox *comboBox;
    QSlider *horizontalSlider;

    void setupUi(QFrame *VideoPlayerOverview)
    {
        if (VideoPlayerOverview->objectName().isEmpty())
            VideoPlayerOverview->setObjectName(QStringLiteral("VideoPlayerOverview"));
        VideoPlayerOverview->resize(401, 111);
        VideoPlayerOverview->setStyleSheet(QStringLiteral("background: rgb(175, 175, 175)"));
        VideoPlayerOverview->setFrameShape(QFrame::StyledPanel);
        VideoPlayerOverview->setFrameShadow(QFrame::Raised);
        horizontalLayoutWidget = new QWidget(VideoPlayerOverview);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 381, 61));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_5 = new QPushButton(horizontalLayoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButton_5);

        pushButton_4 = new QPushButton(horizontalLayoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(horizontalLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(horizontalLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        comboBox = new QComboBox(horizontalLayoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout->addWidget(comboBox);

        horizontalSlider = new QSlider(VideoPlayerOverview);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(10, 80, 381, 19));
        horizontalSlider->setOrientation(Qt::Horizontal);

        retranslateUi(VideoPlayerOverview);

        QMetaObject::connectSlotsByName(VideoPlayerOverview);
    } // setupUi

    void retranslateUi(QFrame *VideoPlayerOverview)
    {
        VideoPlayerOverview->setWindowTitle(QApplication::translate("VideoPlayerOverview", "Frame", 0));
        pushButton_5->setText(QApplication::translate("VideoPlayerOverview", "Play", 0));
        pushButton_4->setText(QApplication::translate("VideoPlayerOverview", "Stop", 0));
        pushButton_3->setText(QApplication::translate("VideoPlayerOverview", "Reset", 0));
        pushButton_2->setText(QApplication::translate("VideoPlayerOverview", "<", 0));
        pushButton->setText(QApplication::translate("VideoPlayerOverview", ">", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("VideoPlayerOverview", "1.0x", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class VideoPlayerOverview: public Ui_VideoPlayerOverview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOPLAYEROVERVIEW_H
