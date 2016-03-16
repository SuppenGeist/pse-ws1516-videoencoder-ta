#include "YuvFileOpenDialog.h"

#include <memory>

#include <QWidget>
#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QListView>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>
#include <QLineEdit>
#include <QStringListModel>
#include <QFile>
#include <QTextStream>
#include <QFileInfo>
#include <QStringList>
#include <QFileDialog>
#include <QRegExp>
#include <QFrame>

#include "../utility/Compression.h"
#include "../utility/YuvType.h"

#include "YuvInfoDialog.h"

QStringListModel* GUI::YuvFileOpenDialog::model_recentlyUsed_=nullptr;
std::vector<QString> GUI::YuvFileOpenDialog::attributes_;
const QString GUI::YuvFileOpenDialog::SAVE_FILENAME="yuv_recently_used.data";

GUI::YuvFileOpenDialog::YuvFileOpenDialog(QWidget* parent):QDialog(parent) {
	createUi();
	connectActions();


}

QString GUI::YuvFileOpenDialog::getFilename() {
	QFileInfo fileToCheck(lineEdit_selectedFile_->text());

	if(fileToCheck.exists()&&fileToCheck.isFile()) {
		return lineEdit_selectedFile_->text();
	}
	return tr("");
}

int GUI::YuvFileOpenDialog::getFps() {
	return fps_;
}

int GUI::YuvFileOpenDialog::getWidth() {
	return width_;
}

int GUI::YuvFileOpenDialog::getHeight() {
	return height_;
}

Utility::Compression GUI::YuvFileOpenDialog::getCompression() {
	return compression_;
}

Utility::YuvType GUI::YuvFileOpenDialog::getPixelSheme() {
	return type_;
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
	listView_recentlyUsed_->setModel(getListModel());
}

void GUI::YuvFileOpenDialog::connectActions() {
	connect(button_ok_,SIGNAL(clicked()),this,SLOT(accept()));
	connect(button_cancel_,SIGNAL(clicked()),this,SLOT(reject()));
	connect(button_chooseFile_,SIGNAL(clicked()),this,SLOT(chooseFile()));
	connect(listView_recentlyUsed_->selectionModel(),SIGNAL(selectionChanged(QItemSelection,
	        QItemSelection)),this,SLOT(selectionChanged(QItemSelection)));
	connect(this,SIGNAL(finished(int)),this,SLOT(hasFinished(int)));

}

bool GUI::YuvFileOpenDialog::parseAttributes(QString attributes) {
	QStringList attrs=attributes.split(",");

	if(attrs.size()!=5)
		return false;

	bool succesful=true;
	width_=attrs[1].toInt(&succesful);
	if(!succesful)
		return false;
	height_=attrs[2].toInt(&succesful);
	if(!succesful)
		return false;
	fps_=attrs[0].toInt(&succesful);
	if(!succesful)
		return false;

	if(attrs[3]=="packed") {
		compression_=Utility::Compression::PACKED;
	} else if(attrs[3]=="planar") {
		compression_=Utility::Compression::PLANAR;
	} else {
		return false;
	}

	if(attrs[4]=="411") {
		type_=Utility::YuvType::YUV411;
	} else if(attrs[4]=="420") {
		type_=Utility::YuvType::YUV420;
	} else if(attrs[4]=="422") {
		type_=Utility::YuvType::YUV422;
	} else if(attrs[4]=="444") {
		type_=Utility::YuvType::YUV444;
	} else {
		return false;
	}

	return true;
}

QString GUI::YuvFileOpenDialog::askAttributes() {
	int result;

	std::unique_ptr<YuvInfoDialog> infoDialog;

	bool inputIsValid=true;
	do {
		infoDialog=std::make_unique<YuvInfoDialog>(dynamic_cast<QWidget*>(parent()));

		inputIsValid=true;

		result=infoDialog->exec();

		if(result!=QDialog::Accepted)
			return "";

		if(infoDialog->getFps()<=0||infoDialog->getHeight()<=0||infoDialog->getWidth()<=0) {
			inputIsValid=false;
		}

	} while(!inputIsValid);

	if(result==QDialog::Accepted) {
		QString attrs=QString::number(infoDialog->getFps())+","+QString::number(
		                  infoDialog->getWidth())+","+QString::number(infoDialog->getHeight())+",";
		switch(infoDialog->getCompression()) {
		case Utility::Compression::PACKED:
			attrs+="packed";
			break;
		case Utility::Compression::PLANAR:
			attrs+="planar";
			break;
		}
		attrs+=",";
		switch (infoDialog->getPixelSheme()) {
		case Utility::YuvType::YUV411:
			attrs+="411";
			break;
		case Utility::YuvType::YUV422:
			attrs+="42";
			break;
		case Utility::YuvType::YUV420:
			attrs+="420";
			break;
		case Utility::YuvType::YUV444:
			attrs+="444";
			break;
		}

		return attrs;
	} else {
		return "";
	}
	return "";
}

void GUI::YuvFileOpenDialog::hasFinished(int result) {
	if(result==QDialog::Accepted) {
		int selectedindex=-1;
		if(!listView_recentlyUsed_->selectionModel()->selectedIndexes().isEmpty()) {
			selectedindex=listView_recentlyUsed_->selectionModel()->selectedIndexes().first().row();
		}

		QString fileattributes;
		if(selectedindex!=-1&&getFilename()==getListModel()->stringList().at(selectedindex)) {
			bool res=parseAttributes(attributes_[selectedindex]);

			if(!res) {
				if((fileattributes=askAttributes()).isEmpty()) {
					setResult(QDialog::Rejected);
					return;
				}
			} else {
				fileattributes=attributes_[selectedindex];
			}
		} else {
			if(getFilename().isEmpty()||(fileattributes=askAttributes()).isEmpty()) {
				setResult(QDialog::Rejected);
				return;
			}
		}
		parseAttributes(fileattributes);
		saveListModel(getFilename(),fileattributes);
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

void GUI::YuvFileOpenDialog::saveListModel(QString selectedFile,QString attributes) {
	QStringList recentlyUsedFiles=model_recentlyUsed_->stringList();

	if(!selectedFile.isEmpty()) {
		if(recentlyUsedFiles.contains(selectedFile)) {
			int index=recentlyUsedFiles.indexOf(QRegExp(selectedFile));
			recentlyUsedFiles.removeAt(index);
			attributes_.erase(attributes_.begin()+index);
		}
		recentlyUsedFiles.prepend(selectedFile);
		attributes_.insert(attributes_.begin(),attributes);

		model_recentlyUsed_->setStringList(recentlyUsedFiles);
	}

	QFile outputFile(SAVE_FILENAME);
	if(outputFile.open(QIODevice::ReadWrite)) {
		QTextStream stream(&outputFile);

		int i=0;
		for(auto& line:recentlyUsedFiles) {
			stream<<line<<";"<<attributes_[i]<<"\n";

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
			QStringList linearr=line.split(";");
			if(linearr.size()!=2) {
				continue;
			}
			QFileInfo fileToCheck(linearr[0]);

			if(fileToCheck.exists()&&fileToCheck.isFile()&&linearr[1].split(",").size()==5) {
				validFiles.append(linearr[0]);
				attributes_.push_back(linearr[1]);
			}
		}
		model_recentlyUsed_->setStringList(validFiles);
		recentlyUsedFile.close();
	}

	return model_recentlyUsed_;
}
