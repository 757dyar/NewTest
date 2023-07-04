/********************************************************************************
** Form generated from reading UI file 'VideoDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEODIALOG_H
#define UI_VIDEODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include "VideoWidget.h"

QT_BEGIN_NAMESPACE

class Ui_VideoDialog
{
public:
    QGridLayout *gridLayout;
    VideoWidget *videoWidget;

    void setupUi(QDialog *VideoDialog)
    {
        if (VideoDialog->objectName().isEmpty())
            VideoDialog->setObjectName(QString::fromUtf8("VideoDialog"));
        VideoDialog->resize(310, 238);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(VideoDialog->sizePolicy().hasHeightForWidth());
        VideoDialog->setSizePolicy(sizePolicy);
        VideoDialog->setContextMenuPolicy(Qt::DefaultContextMenu);
        VideoDialog->setAutoFillBackground(false);
        VideoDialog->setSizeGripEnabled(true);
        VideoDialog->setModal(false);
        gridLayout = new QGridLayout(VideoDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        videoWidget = new VideoWidget(VideoDialog);
        videoWidget->setObjectName(QString::fromUtf8("videoWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(videoWidget->sizePolicy().hasHeightForWidth());
        videoWidget->setSizePolicy(sizePolicy1);
        videoWidget->setMinimumSize(QSize(100, 100));
        videoWidget->setAutoFillBackground(false);
        videoWidget->setProperty("scaledContents", QVariant(false));

        gridLayout->addWidget(videoWidget, 0, 0, 1, 1);


        retranslateUi(VideoDialog);

        QMetaObject::connectSlotsByName(VideoDialog);
    } // setupUi

    void retranslateUi(QDialog *VideoDialog)
    {
        VideoDialog->setWindowTitle(QCoreApplication::translate("VideoDialog", "SLVideoDialog", nullptr));
        videoWidget->setProperty("text", QVariant(QString()));
    } // retranslateUi

};

namespace Ui {
    class VideoDialog: public Ui_VideoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEODIALOG_H
