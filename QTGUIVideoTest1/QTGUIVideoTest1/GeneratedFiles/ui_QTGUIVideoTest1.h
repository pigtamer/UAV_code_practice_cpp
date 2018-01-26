/********************************************************************************
** Form generated from reading UI file 'QTGUIVideoTest1.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGUIVIDEOTEST1_H
#define UI_QTGUIVIDEOTEST1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QTGUIVideoTest1Class
{
public:
    QAction *actionTool;
    QAction *actionHelp;
    QAction *actionOpen;
    QAction *actionClose;
    QAction *actionQuit;
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QPushButton *SelectModel;
    QPushButton *TrainModel;
    QPushButton *TargetShow;
    QPushButton *Settings;
    QPushButton *PAUSE;
    QPushButton *Camera;
    QLabel *label;
    QLabel *ModelPath;
    QMenuBar *menuBar;
    QMenu *menuMenuy;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QTGUIVideoTest1Class)
    {
        if (QTGUIVideoTest1Class->objectName().isEmpty())
            QTGUIVideoTest1Class->setObjectName(QStringLiteral("QTGUIVideoTest1Class"));
        QTGUIVideoTest1Class->resize(957, 669);
        QTGUIVideoTest1Class->setCursor(QCursor(Qt::ArrowCursor));
        actionTool = new QAction(QTGUIVideoTest1Class);
        actionTool->setObjectName(QStringLiteral("actionTool"));
        actionHelp = new QAction(QTGUIVideoTest1Class);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        actionOpen = new QAction(QTGUIVideoTest1Class);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionClose = new QAction(QTGUIVideoTest1Class);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionQuit = new QAction(QTGUIVideoTest1Class);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        centralWidget = new QWidget(QTGUIVideoTest1Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 921, 511));
        SelectModel = new QPushButton(centralWidget);
        SelectModel->setObjectName(QStringLiteral("SelectModel"));
        SelectModel->setGeometry(QRect(10, 530, 75, 23));
        SelectModel->setCursor(QCursor(Qt::PointingHandCursor));
        TrainModel = new QPushButton(centralWidget);
        TrainModel->setObjectName(QStringLiteral("TrainModel"));
        TrainModel->setGeometry(QRect(10, 560, 75, 23));
        TrainModel->setCursor(QCursor(Qt::PointingHandCursor));
        TargetShow = new QPushButton(centralWidget);
        TargetShow->setObjectName(QStringLiteral("TargetShow"));
        TargetShow->setGeometry(QRect(110, 530, 75, 23));
        Settings = new QPushButton(centralWidget);
        Settings->setObjectName(QStringLiteral("Settings"));
        Settings->setGeometry(QRect(210, 530, 75, 23));
        PAUSE = new QPushButton(centralWidget);
        PAUSE->setObjectName(QStringLiteral("PAUSE"));
        PAUSE->setGeometry(QRect(370, 530, 75, 23));
        Camera = new QPushButton(centralWidget);
        Camera->setObjectName(QStringLiteral("Camera"));
        Camera->setGeometry(QRect(530, 530, 75, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 590, 51, 16));
        ModelPath = new QLabel(centralWidget);
        ModelPath->setObjectName(QStringLiteral("ModelPath"));
        ModelPath->setGeometry(QRect(70, 590, 371, 16));
        QTGUIVideoTest1Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QTGUIVideoTest1Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 957, 23));
        menuMenuy = new QMenu(menuBar);
        menuMenuy->setObjectName(QStringLiteral("menuMenuy"));
        menuFile = new QMenu(menuMenuy);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        QTGUIVideoTest1Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QTGUIVideoTest1Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QTGUIVideoTest1Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QTGUIVideoTest1Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QTGUIVideoTest1Class->setStatusBar(statusBar);

        menuBar->addAction(menuMenuy->menuAction());
        menuMenuy->addAction(menuFile->menuAction());
        menuMenuy->addAction(actionTool);
        menuMenuy->addAction(actionHelp);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionClose);
        menuFile->addAction(actionQuit);

        retranslateUi(QTGUIVideoTest1Class);

        QMetaObject::connectSlotsByName(QTGUIVideoTest1Class);
    } // setupUi

    void retranslateUi(QMainWindow *QTGUIVideoTest1Class)
    {
        QTGUIVideoTest1Class->setWindowTitle(QApplication::translate("QTGUIVideoTest1Class", "QTGUIVideoTest1", Q_NULLPTR));
        actionTool->setText(QApplication::translate("QTGUIVideoTest1Class", "Tools", Q_NULLPTR));
        actionHelp->setText(QApplication::translate("QTGUIVideoTest1Class", "Help", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("QTGUIVideoTest1Class", "Open", Q_NULLPTR));
        actionClose->setText(QApplication::translate("QTGUIVideoTest1Class", "Close", Q_NULLPTR));
        actionQuit->setText(QApplication::translate("QTGUIVideoTest1Class", "Quit", Q_NULLPTR));
        SelectModel->setText(QApplication::translate("QTGUIVideoTest1Class", "SelectModel", Q_NULLPTR));
        TrainModel->setText(QApplication::translate("QTGUIVideoTest1Class", "TrainModel", Q_NULLPTR));
        TargetShow->setText(QApplication::translate("QTGUIVideoTest1Class", "TargetShow", Q_NULLPTR));
        Settings->setText(QApplication::translate("QTGUIVideoTest1Class", "Settings", Q_NULLPTR));
        PAUSE->setText(QApplication::translate("QTGUIVideoTest1Class", "PAUSE", Q_NULLPTR));
        Camera->setText(QApplication::translate("QTGUIVideoTest1Class", "Camera", Q_NULLPTR));
        label->setText(QApplication::translate("QTGUIVideoTest1Class", "\345\267\262\351\200\211\346\250\241\345\236\213:", Q_NULLPTR));
        ModelPath->setText(QApplication::translate("QTGUIVideoTest1Class", "TextLabel", Q_NULLPTR));
        menuMenuy->setTitle(QApplication::translate("QTGUIVideoTest1Class", "Menu", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("QTGUIVideoTest1Class", "File", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QTGUIVideoTest1Class: public Ui_QTGUIVideoTest1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGUIVIDEOTEST1_H
