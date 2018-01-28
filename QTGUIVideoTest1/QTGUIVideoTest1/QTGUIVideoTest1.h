#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QTGUIVideoTest1.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

class QTGUIVideoTest1 : public QMainWindow
{
	Q_OBJECT

public:
	QTGUIVideoTest1(QWidget *parent = Q_NULLPTR);

private:
	Ui::QTGUIVideoTest1Class ui;
	QGraphicsScene scene;
private slots:
int ModelSelect();
int VideoSelect();
int CameraSelect();
void pixmapshow(cv::Mat frame);
int VideoReplay();
};
