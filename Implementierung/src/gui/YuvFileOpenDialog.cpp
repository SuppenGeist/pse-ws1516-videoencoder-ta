#include "YuvFileOpenDialog.h"

#include <QWidget>
#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QListView>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QStringListModel>
#include <QFile>
#include <QTextStream>
#include <QFileInfo>
#include <QStringList>
#include <QFileDialog>
#include <QRegExp>
#include <QFrame>

QStringListModel* GUI::YuvFileOpenDialog::model_recentlyUsed_=nullptr;
const QString GUI::YuvFileOpenDialog::SAVE_FILENAME="yuv_recently_used.data";

GUI::YuvFileOpenDialog::YuvFileOpenDialog(QWidget* parent):QDialog(parent) {
	createUi();

	listView_recentlyUsed_->setModel(getListModel());

	connect(button_ok_,SIGNAL(clicked()),this,SLOT(accept()));
	connect(button_cancel_,SIGNAL(clicked()),this,SLOT(reject()));
	connect(button_chooseFile_,SIGNAL(clicked()),this,SLOT(chooseFile()));
	connect(listView_recentlyUsed_->selectionModel(),SIGNAL(selectionChanged(QItemSelection,
	        QItemSelection)),this,SLOT(selectionChanged(QItemSelection)));
	connect(this,SIGNAL(finished(int)),this,SLOT(hasFinished(int)));


}

QString GUI::YuvFileOpenDialog::getFilename() {
	QFileInfo fileToCheck(lineEdit_selectedFile_->text());

	if(fileToCheck.exists()&&fileToCheck.isFile()) {
		return lineEdit_selectedFile_->text();
	}
	return tr("");
}

void GUI::YuvFileOpenDialog::createUi() {
	button_cancel_=new QPushButton(tr("Cancel"));
	button_ok_=new QPushButton(tr("OK"));
	button_chooseFile_=new QPushButton(tr("..."));

	label_recentlyUsed_=new QLabel(tr("Recently opened files:"));
	label_selectedFile_=new QLabel(tr("File:"));

	listView_recentlyUsed_=new QListView;

	lineEdit_selectedFile_=new QLineEdit;

	lineEdit_selectedFile_->setStyleSheet("QLineEdit { background: rgb(255, 255, 255); }");
	listView_recentlyUsed_->setEditTriggers(QAbstractItemView::NoEditTriggers);

	QVBoxLayout* v_content=new QVBoxLayout;

	QVBoxLayout* v_recentlyUsed=new QVBoxLayout;
	v_recentlyUsed->addWidget(label_recentlyUsed_);
	v_recentlyUsed->addWidget(listView_recentlyUsed_);

	QHBoxLayout* h_chooseFile=new QHBoxLayout;
	h_chooseFile->addWidget(label_selectedFile_);
	h_chooseFile->addWidget(lineEdit_selectedFile_);
	h_chooseFile->addWidget(button_chooseFile_);

	QFrame* line=new QFrame;
	line->setFrameShape(QFrame::HLine);
	line->setFrameShadow(QFrame::Sunken);
	line->setGeometry(QRect(0,0,500,2));

	QHBoxLayout* h_buttons=new QHBoxLayout;
	h_buttons->addSpacing(300);
	h_buttons->addWidget(button_cancel_);
	h_buttons->addWidget(button_ok_);

	v_content->addLayout(v_recentlyUsed);
	v_content->addSpacing(20);
	v_content->addLayout(h_chooseFile);
	v_content->addSpacing(10);
	v_content->addWidget(line);
	v_content->addLayout(h_buttons);
	setLayout(v_content);

	setWindowTitle("Load YUV file");
	setMinimumWidth(500);
}

void GUI::YuvFileOpenDialog::hasFinished(int result) {
	if(result==QDialog::Accepted) {
		saveListModel(getFilename());
	}
}

void GUI::YuvFileOpenDialog::chooseFile() {
    auto filename=QFileDialog::getOpenFileName(this,tr("OpenYUV File"),QDir::homePath());
    if(!filename.isEmpty())
        lineEdit_selectedFile_->setText(filename);
}

void GUI::YuvFileOpenDialog::selectionChanged(const QItemSelection& selection) {
	if(selection.indexes().isEmpty())
		return;
	auto selectedFile=getListModel()->stringList().at(selection.indexes().first().row());
	lineEdit_selectedFile_->setText(selectedFile);

}

void GUI::YuvFileOpenDialog::saveListModel(QString selectedFile) {
	QStringList recentlyUsedFiles=model_recentlyUsed_->stringList();

	if(!selectedFile.isEmpty()) {
		if(recentlyUsedFiles.contains(selectedFile)) {
			recentlyUsedFiles.removeAt(recentlyUsedFiles.indexOf(QRegExp(selectedFile)));
		}
		recentlyUsedFiles.prepend(selectedFile);

		model_recentlyUsed_->setStringList(recentlyUsedFiles);
	}

	QFile outputFile(SAVE_FILENAME);
	if(outputFile.open(QIODevice::ReadWrite)) {
		QTextStream stream(&outputFile);

		int i=0;
		for(auto& line:recentlyUsedFiles) {
			stream<<line<<"\n";

			i++;
			if(i>=MAX_SAVED_ENTRIES)
				break;
		}
		outputFile.close();
	}

}

QStringListModel* GUI::YuvFileOpenDialog::getListModel() {
	if(model_recentlyUsed_)
		return model_recentlyUsed_;

	model_recentlyUsed_=new QStringListModel;

	QFile recentlyUsedFile(SAVE_FILENAME);
	if(recentlyUsedFile.open(QIODevice::ReadOnly)) {
		QTextStream input(&recentlyUsedFile);

		QStringList validFiles;
		for(int i=0; i<10&&!input.atEnd(); i++) {
			QString line=input.readLine();
			QFileInfo fileToCheck(line);

			if(fileToCheck.exists()&&fileToCheck.isFile()) {
				validFiles.append(line);
			}
		}
		model_recentlyUsed_->setStringList(validFiles);
		recentlyUsedFile.close();
	}

	return model_recentlyUsed_;
}
