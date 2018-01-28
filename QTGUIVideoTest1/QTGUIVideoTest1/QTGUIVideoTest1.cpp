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
	//����Ƶ�ļ�
	if (!capture.isOpened())
	{
		return 1;
	}
	// ȡ��֡����
	double rate = capture.get(CV_CAP_PROP_FPS);
	bool stop = false;
	cv::Mat frame; // ��ǰ��Ƶ֡
	cv::namedWindow("demo",0);
	cv::resizeWindow("demo",1,1);
	// ����֡���ʼ���֮֡��ĵȴ�ʱ�䣬��λms
	int delay = 1000 / rate;
	// ѭ��������Ƶ�е�ȫ��֡
	while (!stop) {
		// ��ȡ��һ֡������У�
		if (!capture.read(frame))
			break;
		pixmapshow(frame);
		// �ȴ�һ��ʱ�䣬����ͨ������ֹͣ
		if (cv::waitKey(delay) >= 0)
			stop = true;
	}
	// �ر���Ƶ�ļ�
	// ���Ǳ���ģ���Ϊ����������������
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
			// ��ȡ��һ֡������У�
			if (!capture.read(frame))
				break;
			pixmapshow(frame);
			// �ȴ�һ��ʱ�䣬����ͨ������ֹͣ
			if (cv::waitKey(delay) >= 0)
				i = 1;
		}
	}
	return 0;
}

void QTGUIVideoTest1::pixmapshow(cv::Mat frame)
{
	//���ｫMatתΪQPixmap
	scene.clear();
	QImage picQImage;
	QPixmap picQPixmap;
	cv::cvtColor(frame, frame, CV_BGR2RGB);//��ͨ��ͼƬ��bgr��ת��rgb
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
	//����Ƶ�ļ�
	if (!capture.isOpened())
	{
		return 1;
	}
	// ȡ��֡����
	double rate = capture.get(CV_CAP_PROP_FPS);
	bool stop = false;
	cv::Mat frame; // ��ǰ��Ƶ֡
	cv::namedWindow("demo", 0);
	cv::resizeWindow("demo", 1, 1);
	// ����֡���ʼ���֮֡��ĵȴ�ʱ�䣬��λms
	int delay = 1000 / rate;
	// ѭ��������Ƶ�е�ȫ��֡
	while (!stop) {
		// ��ȡ��һ֡������У�
		if (!capture.read(frame))
			break;
		pixmapshow(frame);
		// �ȴ�һ��ʱ�䣬����ͨ������ֹͣ
		if (cv::waitKey(delay) >= 0)
			stop = true;
	}
	// �ر���Ƶ�ļ�
	// ���Ǳ���ģ���Ϊ����������������
	capture.release();
	return 0;
}