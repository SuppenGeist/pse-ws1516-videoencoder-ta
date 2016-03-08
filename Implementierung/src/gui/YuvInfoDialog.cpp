#include "YuvInfoDialog.h"

#include <stdexcept>

#include <QWidget>
#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QStringList>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFrame>
#include <QString>

#include "../utility/Compression.h"
#include "../utility/YuvType.h"

GUI::YuvInfoDialog::YuvInfoDialog(QWidget* parent):QDialog(parent) {
	createUi();
    connectActions();
}

int GUI::YuvInfoDialog::getFps() {
	bool successful=false;
	int fps=lineEdit_fps_->text().toInt(&successful);

	if(successful) {
		return fps;
	}
	return 30;
}

int GUI::YuvInfoDialog::getWidth() {
	bool successful=false;
	int width=lineEdit_width_->text().toInt(&successful);

	if(successful) {
		return width;
	}
	return -1;
}

int GUI::YuvInfoDialog::getHeight() {
	bool successful=false;
	int height=lineEdit_height_->text().toInt(&successful);

	if(successful) {
		return height;
	}
	return -1;
}

Utility::Compression GUI::YuvInfoDialog::getCompression() {
	auto text=comboBox_compression_->currentText();
	if(text=="Packed") {
		return Utility::Compression::PACKED;
	} else if(text=="Planar") {
		return Utility::Compression::PLANAR;
	}
	throw std::logic_error("Should not get here");
}

Utility::YuvType GUI::YuvInfoDialog::getPixelSheme() {
	auto text=comboBox_pixelSheme_->currentText();
	if(text=="420") {
		return Utility::YuvType::YUV420;
	} else if(text=="411") {
		return Utility::YuvType::YUV411;
	} else if(text=="422") {
		return Utility::YuvType::YUV422;
	} else if(text=="444") {
		return Utility::YuvType::YUV444;
	}
	throw std::logic_error("Should not get here");
}

void GUI::YuvInfoDialog::createUi() {
	button_cancel_=new QPushButton(tr("Cancel"));
	button_ok_=new QPushButton(tr("OK"));

	label_compression_=new QLabel(tr("Compression:"));
	label_fps_=new QLabel(tr("Fps:"));
	label_pixelSheme_=new QLabel(tr("Pixel sheme:"));
	label_resolution_=new QLabel(tr("Resolution:"));
	label_x_=new QLabel(tr("x"));

	lineEdit_fps_=new QLineEdit;
    lineEdit_fps_->setObjectName("lineEdit_fps_");
	lineEdit_height_=new QLineEdit;
    lineEdit_height_->setObjectName("lineEdit_height_");
	lineEdit_width_=new QLineEdit;
    lineEdit_width_->setObjectName("lineEdit_width_");

	comboBox_compression_=new QComboBox;
	comboBox_pixelSheme_=new QComboBox;

    compressionList_<<tr("Packed")<<tr("Planar");
    comboBox_compression_->addItems(compressionList_);
	pixelShemeList_<<tr("420")<<tr("411")<<("422")<<tr("444");
	comboBox_pixelSheme_->addItems(pixelShemeList_);

	lineEdit_fps_->setStyleSheet("QLineEdit { background: rgb(255, 255, 255); }");
	lineEdit_height_->setStyleSheet("QLineEdit { background: rgb(255, 255, 255); }");
	lineEdit_width_->setStyleSheet("QLineEdit { background: rgb(255, 255, 255); }");
	lineEdit_width_->setAlignment(Qt::AlignRight);
	lineEdit_fps_->setText(tr("30"));

	QVBoxLayout* v_content=new QVBoxLayout;

	QHBoxLayout* h_resolution=new QHBoxLayout;
	h_resolution->addWidget(label_resolution_);
	h_resolution->addWidget(lineEdit_width_);
	h_resolution->addWidget(label_x_);
	h_resolution->addWidget(lineEdit_height_);

	QHBoxLayout* h_pixelSheme=new QHBoxLayout;
	h_pixelSheme->addWidget(label_pixelSheme_);
	h_pixelSheme->addWidget(comboBox_pixelSheme_);

	QHBoxLayout* h_compression=new QHBoxLayout;
	h_compression->addWidget(label_compression_);
	h_compression->addWidget(comboBox_compression_);

	QHBoxLayout* h_fps=new QHBoxLayout;
	h_fps->addWidget(label_fps_);
	h_fps->addSpacing(130);
	h_fps->addWidget(lineEdit_fps_);

	QHBoxLayout* h_buttons=new QHBoxLayout;
	h_buttons->addSpacing(300);
	h_buttons->addWidget(button_cancel_);
	h_buttons->addWidget(button_ok_);

	QFrame* line=new QFrame;
	line->setFrameShape(QFrame::HLine);
	line->setFrameShadow(QFrame::Sunken);
	line->setGeometry(QRect(0,0,250,2));

	v_content->addLayout(h_resolution);
	v_content->addSpacing(5);
	v_content->addLayout(h_pixelSheme);
	v_content->addSpacing(5);
	v_content->addLayout(h_compression);
	v_content->addSpacing(5);
	v_content->addLayout(h_fps);
	v_content->addSpacing(10);
	v_content->addWidget(line);
	v_content->addLayout(h_buttons);
	setLayout(v_content);

	if(comboBox_pixelSheme_->currentText()=="420") {
		comboBox_compression_->setEnabled(false);
		comboBox_compression_->setCurrentIndex(1);
	}

	setWindowTitle(tr("Fileinfo for the YUV video"));
	setFixedWidth(250);
    setFixedHeight(220);
}

void GUI::YuvInfoDialog::connectActions()
{
    connect(button_cancel_,SIGNAL(clicked()),this,SLOT(reject()));
    connect(button_ok_,SIGNAL(clicked()),this,SLOT(accept()));
    connect(comboBox_pixelSheme_,SIGNAL(currentIndexChanged(int)),this,
            SLOT(pixelShemeSelectionChanged(int)));
}

void GUI::YuvInfoDialog::pixelShemeSelectionChanged(int selection) {
    if(pixelShemeList_.at(selection)=="420") {
		comboBox_compression_->setEnabled(false);
		comboBox_compression_->setCurrentIndex(1);
	} else {
		comboBox_compression_->setEnabled(true);
	}
}
