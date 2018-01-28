#include "iostream"
#include "stdlib.h"
#include "QTGUIVideoTest1.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include "QtCore"
#include "qfiledialog.h"
#include "QtCore"

#pragma execution_character_set("utf-8")
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

QString VIDEOPATH_TOTAL;

QTGUIVideoTest1::QTGUIVideoTest1(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.SelectModel,SIGNAL(clicked()),this,SLOT(ModelSelect()));
	connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(VideoSelect()));
	connect(ui.Camera, SIGNAL(clicked()), this, SLOT(CameraSelect()));
	connect(ui.REPLAY, SIGNAL(clicked()), this, SLOT(VideoReplay()));
}
int QTGUIVideoTest1::ModelSelect()
{
	QString MODELPATH = QFileDialog::getOpenFileName(0, "Open File", "", "", 0);
	ui.ModelPath->setText(MODELPATH.toLatin1().data());
	return 0;
}
int QTGUIVideoTest1::VideoSelect()
{
	QString VIDEOPATH = QFileDialog::getOpenFileName(0, "Open File", "", "*.avi", 0);
	VIDEOPATH_TOTAL = VIDEOPATH;
	ui.VideoPath->setText(VIDEOPATH.toLatin1().data());
	cv::VideoCapture capture(VIDEOPATH.toLatin1().data());
	//打开视频文件
	if (!capture.isOpened())
	{
		return 1;
	}
	// 取得帧速率
	double rate = capture.get(CV_CAP_PROP_FPS);
	bool stop = false;
	cv::Mat frame; // 当前视频帧
	cv::namedWindow("demo",0);
	cv::resizeWindow("demo",1,1);
	// 根据帧速率计算帧之间的等待时间，单位ms
	int delay = 1000 / rate;
	// 循环遍历视频中的全部帧
	while (!stop) {
		// 读取下一帧（如果有）
		if (!capture.read(frame))
			break;
		pixmapshow(frame);
		// 等待一段时间，或者通过按键停止
		if (cv::waitKey(delay) >= 0)
			stop = true;
	}
	// 关闭视频文件
	// 不是必需的，因为类的析构函数会调用
	capture.release();
	return 0;
}

int QTGUIVideoTest1::CameraSelect()
{
	cv::VideoCapture capture(0);
	while (1)
	{
		cv::Mat frame;
		capture >> frame;
		cv::namedWindow("demo", 0);
		cv::resizeWindow("demo", 1, 1);
		int delay = 30;
		int i = 0;
		while (!i)
		{
			// 读取下一帧（如果有）
			if (!capture.read(frame))
				break;
			pixmapshow(frame);
			// 等待一段时间，或者通过按键停止
			if (cv::waitKey(delay) >= 0)
				i = 1;
		}
	}
	return 0;
}

void QTGUIVideoTest1::pixmapshow(cv::Mat frame)
{
	//这里将Mat转为QPixmap
	scene.clear();
	QImage picQImage;
	QPixmap picQPixmap;
	cv::cvtColor(frame, frame, CV_BGR2RGB);//三通道图片需bgr翻转成rgb
	picQImage = QImage((uchar*)frame.data, frame.cols, frame.rows, QImage::Format_RGB888);
	picQPixmap = QPixmap::fromImage(picQImage);
	//scene.clear();
	scene.addPixmap(picQPixmap);
	ui.graphicsView->setScene(&scene);
	ui.graphicsView->show();
}

int QTGUIVideoTest1::VideoReplay()
{
	cv::VideoCapture capture(VIDEOPATH_TOTAL.toLatin1().data());
	//打开视频文件
	if (!capture.isOpened())
	{
		return 1;
	}
	// 取得帧速率
	double rate = capture.get(CV_CAP_PROP_FPS);
	bool stop = false;
	cv::Mat frame; // 当前视频帧
	cv::namedWindow("demo", 0);
	cv::resizeWindow("demo", 1, 1);
	// 根据帧速率计算帧之间的等待时间，单位ms
	int delay = 1000 / rate;
	// 循环遍历视频中的全部帧
	while (!stop) {
		// 读取下一帧（如果有）
		if (!capture.read(frame))
			break;
		pixmapshow(frame);
		// 等待一段时间，或者通过按键停止
		if (cv::waitKey(delay) >= 0)
			stop = true;
	}
	// 关闭视频文件
	// 不是必需的，因为类的析构函数会调用
	capture.release();
	return 0;
}