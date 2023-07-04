/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "PointCloudWidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QAction *actionStart;
    QAction *actionStop;
    QAction *actionCalibration;
    QAction *actionLoadCalibration;
    QAction *actionExportCalibration;
    QAction *actionPreferences;
    QAction *actionSavePointCloud;
    QAction *actionSaveScreenshot;
    QAction *actionTracking;
    QAction *actionAbout;
    QAction *actionTracker;
    QAction *actionUpdatePointClouds;
    QAction *actionUpload_Calibration_Patterns;
    QAction *actionUpload_Scan_Patterns;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    PointCloudWidget *pointCloudWidget;
    QMenuBar *menuBar;
    QMenu *menuCalibration;
    QMenu *menuSLStudio;
    QMenu *menuScan;
    QMenu *menuView;
    QMenu *menuProjector;
    QToolBar *toolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(824, 537);
        MainWindow->setAutoFillBackground(false);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionQuit->setMenuRole(QAction::QuitRole);
        actionStart = new QAction(MainWindow);
        actionStart->setObjectName(QString::fromUtf8("actionStart"));
        actionStop = new QAction(MainWindow);
        actionStop->setObjectName(QString::fromUtf8("actionStop"));
        actionStop->setEnabled(false);
        actionCalibration = new QAction(MainWindow);
        actionCalibration->setObjectName(QString::fromUtf8("actionCalibration"));
        actionLoadCalibration = new QAction(MainWindow);
        actionLoadCalibration->setObjectName(QString::fromUtf8("actionLoadCalibration"));
        actionExportCalibration = new QAction(MainWindow);
        actionExportCalibration->setObjectName(QString::fromUtf8("actionExportCalibration"));
        actionPreferences = new QAction(MainWindow);
        actionPreferences->setObjectName(QString::fromUtf8("actionPreferences"));
        actionSavePointCloud = new QAction(MainWindow);
        actionSavePointCloud->setObjectName(QString::fromUtf8("actionSavePointCloud"));
        actionSavePointCloud->setEnabled(false);
        actionSaveScreenshot = new QAction(MainWindow);
        actionSaveScreenshot->setObjectName(QString::fromUtf8("actionSaveScreenshot"));
        actionSaveScreenshot->setEnabled(false);
        actionTracking = new QAction(MainWindow);
        actionTracking->setObjectName(QString::fromUtf8("actionTracking"));
        actionTracking->setEnabled(false);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionAbout->setMenuRole(QAction::AboutRole);
        actionTracker = new QAction(MainWindow);
        actionTracker->setObjectName(QString::fromUtf8("actionTracker"));
        actionTracker->setCheckable(true);
        actionTracker->setChecked(true);
        actionUpdatePointClouds = new QAction(MainWindow);
        actionUpdatePointClouds->setObjectName(QString::fromUtf8("actionUpdatePointClouds"));
        actionUpdatePointClouds->setCheckable(true);
        actionUpdatePointClouds->setChecked(true);
        actionUpload_Calibration_Patterns = new QAction(MainWindow);
        actionUpload_Calibration_Patterns->setObjectName(QString::fromUtf8("actionUpload_Calibration_Patterns"));
        actionUpload_Scan_Patterns = new QAction(MainWindow);
        actionUpload_Scan_Patterns->setObjectName(QString::fromUtf8("actionUpload_Scan_Patterns"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setAcceptDrops(false);
        centralWidget->setLayoutDirection(Qt::LeftToRight);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pointCloudWidget = new PointCloudWidget(centralWidget);
        pointCloudWidget->setObjectName(QString::fromUtf8("pointCloudWidget"));
        pointCloudWidget->setEnabled(true);
        pointCloudWidget->setLayoutDirection(Qt::LeftToRight);
        pointCloudWidget->setAutoFillBackground(false);

        gridLayout->addWidget(pointCloudWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 824, 22));
        menuCalibration = new QMenu(menuBar);
        menuCalibration->setObjectName(QString::fromUtf8("menuCalibration"));
        menuSLStudio = new QMenu(menuBar);
        menuSLStudio->setObjectName(QString::fromUtf8("menuSLStudio"));
        menuScan = new QMenu(menuBar);
        menuScan->setObjectName(QString::fromUtf8("menuScan"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuProjector = new QMenu(menuBar);
        menuProjector->setObjectName(QString::fromUtf8("menuProjector"));
        MainWindow->setMenuBar(menuBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setEnabled(true);
        QFont font;
        font.setItalic(false);
        font.setStrikeOut(false);
        toolBar->setFont(font);
        toolBar->setMovable(false);
        toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuSLStudio->menuAction());
        menuBar->addAction(menuScan->menuAction());
        menuBar->addAction(menuCalibration->menuAction());
        menuBar->addAction(menuProjector->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuCalibration->addAction(actionLoadCalibration);
        menuCalibration->addAction(actionExportCalibration);
        menuCalibration->addAction(actionCalibration);
        menuSLStudio->addAction(actionPreferences);
        menuSLStudio->addAction(actionQuit);
        menuSLStudio->addAction(actionAbout);
        menuScan->addAction(actionStart);
        menuScan->addAction(actionStop);
        menuScan->addAction(actionSavePointCloud);
        menuScan->addAction(actionSaveScreenshot);
        menuView->addAction(actionUpdatePointClouds);
        menuProjector->addAction(actionUpload_Scan_Patterns);
        menuProjector->addAction(actionUpload_Calibration_Patterns);
        toolBar->addAction(actionStart);
        toolBar->addAction(actionStop);
        toolBar->addSeparator();
        toolBar->addAction(actionSavePointCloud);
        toolBar->addAction(actionSaveScreenshot);
        toolBar->addAction(actionCalibration);
        toolBar->addSeparator();

        retranslateUi(MainWindow);
        QObject::connect(actionStart, SIGNAL(triggered()), MainWindow, SLOT(onActionStart()));
        QObject::connect(actionStop, SIGNAL(triggered()), MainWindow, SLOT(onActionStop()));
        QObject::connect(actionQuit, SIGNAL(triggered()), MainWindow, SLOT(close()));
        QObject::connect(actionCalibration, SIGNAL(triggered()), MainWindow, SLOT(onActionCalibration()));
        QObject::connect(actionPreferences, SIGNAL(triggered()), MainWindow, SLOT(onActionPreferences()));
        QObject::connect(actionExportCalibration, SIGNAL(triggered()), MainWindow, SLOT(onActionExportCalibration()));
        QObject::connect(actionSaveScreenshot, SIGNAL(triggered()), pointCloudWidget, SLOT(saveScreenShot()));
        QObject::connect(actionSavePointCloud, SIGNAL(triggered()), pointCloudWidget, SLOT(savePointCloud()));
        QObject::connect(actionLoadCalibration, SIGNAL(triggered()), MainWindow, SLOT(onActionLoadCalibration()));
        QObject::connect(actionAbout, SIGNAL(triggered()), MainWindow, SLOT(onActionAbout()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "SLStudio", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainWindow", "&Quit", nullptr));
        actionStart->setText(QCoreApplication::translate("MainWindow", "Start Scan", nullptr));
        actionStop->setText(QCoreApplication::translate("MainWindow", "Stop Scan", nullptr));
        actionCalibration->setText(QCoreApplication::translate("MainWindow", "Perform Calibration", nullptr));
        actionLoadCalibration->setText(QCoreApplication::translate("MainWindow", "Load Calibration", nullptr));
        actionExportCalibration->setText(QCoreApplication::translate("MainWindow", "Export Calibration", nullptr));
        actionPreferences->setText(QCoreApplication::translate("MainWindow", "&Preferences", nullptr));
        actionSavePointCloud->setText(QCoreApplication::translate("MainWindow", "Save Point Cloud", nullptr));
        actionSaveScreenshot->setText(QCoreApplication::translate("MainWindow", "Save Screenshot", nullptr));
        actionTracking->setText(QCoreApplication::translate("MainWindow", "Start Tracking", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        actionTracker->setText(QCoreApplication::translate("MainWindow", "Tracker", nullptr));
        actionUpdatePointClouds->setText(QCoreApplication::translate("MainWindow", "Update Point Clouds", nullptr));
        actionUpload_Calibration_Patterns->setText(QCoreApplication::translate("MainWindow", "Upload Calibration Patterns", nullptr));
        actionUpload_Scan_Patterns->setText(QCoreApplication::translate("MainWindow", "Upload Scan Patterns", nullptr));
        menuCalibration->setTitle(QCoreApplication::translate("MainWindow", "Calibration", nullptr));
        menuSLStudio->setTitle(QCoreApplication::translate("MainWindow", "SLStudio", nullptr));
        menuScan->setTitle(QCoreApplication::translate("MainWindow", "Scan", nullptr));
        menuView->setTitle(QCoreApplication::translate("MainWindow", "View", nullptr));
        menuProjector->setTitle(QCoreApplication::translate("MainWindow", "Projector", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
