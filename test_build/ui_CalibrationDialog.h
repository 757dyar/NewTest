/********************************************************************************
** Form generated from reading UI file 'CalibrationDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALIBRATIONDIALOG_H
#define UI_CALIBRATIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include "VideoWidget.h"

QT_BEGIN_NAMESPACE

class Ui_CalibrationDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QSpinBox *colsSpinBox;
    VideoWidget *videoWidget;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QComboBox *patternComboBox;
    QPushButton *snapButton;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spacingSpinBox;
    QPushButton *calibrateButton;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *cancelButton;
    QPushButton *saveButton;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QSpinBox *rowsSpinBox;

    void setupUi(QDialog *CalibrationDialog)
    {
        if (CalibrationDialog->objectName().isEmpty())
            CalibrationDialog->setObjectName(QString::fromUtf8("CalibrationDialog"));
        CalibrationDialog->resize(890, 540);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CalibrationDialog->sizePolicy().hasHeightForWidth());
        CalibrationDialog->setSizePolicy(sizePolicy);
        CalibrationDialog->setMinimumSize(QSize(890, 540));
        CalibrationDialog->setMaximumSize(QSize(30000, 30000));
        CalibrationDialog->setSizeGripEnabled(false);
        gridLayout = new QGridLayout(CalibrationDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(CalibrationDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        colsSpinBox = new QSpinBox(CalibrationDialog);
        colsSpinBox->setObjectName(QString::fromUtf8("colsSpinBox"));

        horizontalLayout_3->addWidget(colsSpinBox);


        gridLayout->addLayout(horizontalLayout_3, 3, 1, 1, 1);

        videoWidget = new VideoWidget(CalibrationDialog);
        videoWidget->setObjectName(QString::fromUtf8("videoWidget"));
        videoWidget->setEnabled(true);

        gridLayout->addWidget(videoWidget, 0, 0, 8, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, 0, -1, -1);
        label_2 = new QLabel(CalibrationDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_5->addWidget(label_2);

        patternComboBox = new QComboBox(CalibrationDialog);
        patternComboBox->addItem(QString());
        patternComboBox->addItem(QString());
        patternComboBox->setObjectName(QString::fromUtf8("patternComboBox"));

        horizontalLayout_5->addWidget(patternComboBox);


        gridLayout->addLayout(horizontalLayout_5, 6, 1, 1, 1);

        snapButton = new QPushButton(CalibrationDialog);
        snapButton->setObjectName(QString::fromUtf8("snapButton"));
        snapButton->setEnabled(true);

        gridLayout->addWidget(snapButton, 8, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(CalibrationDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        spacingSpinBox = new QSpinBox(CalibrationDialog);
        spacingSpinBox->setObjectName(QString::fromUtf8("spacingSpinBox"));
        spacingSpinBox->setValue(0);

        horizontalLayout->addWidget(spacingSpinBox);


        gridLayout->addLayout(horizontalLayout, 1, 1, 1, 1);

        calibrateButton = new QPushButton(CalibrationDialog);
        calibrateButton->setObjectName(QString::fromUtf8("calibrateButton"));
        calibrateButton->setEnabled(false);

        gridLayout->addWidget(calibrateButton, 7, 1, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        cancelButton = new QPushButton(CalibrationDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout_4->addWidget(cancelButton);

        saveButton = new QPushButton(CalibrationDialog);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setEnabled(false);

        horizontalLayout_4->addWidget(saveButton);


        gridLayout->addLayout(horizontalLayout_4, 8, 1, 1, 1);

        listWidget = new QListWidget(CalibrationDialog);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy1);
        listWidget->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(listWidget, 0, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(CalibrationDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        rowsSpinBox = new QSpinBox(CalibrationDialog);
        rowsSpinBox->setObjectName(QString::fromUtf8("rowsSpinBox"));

        horizontalLayout_2->addWidget(rowsSpinBox);


        gridLayout->addLayout(horizontalLayout_2, 2, 1, 1, 1);


        retranslateUi(CalibrationDialog);
        QObject::connect(cancelButton, SIGNAL(clicked()), CalibrationDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(CalibrationDialog);
    } // setupUi

    void retranslateUi(QDialog *CalibrationDialog)
    {
        CalibrationDialog->setWindowTitle(QCoreApplication::translate("CalibrationDialog", "SL Calibration", nullptr));
        label_4->setText(QCoreApplication::translate("CalibrationDialog", "Cols:", nullptr));
        label_2->setText(QCoreApplication::translate("CalibrationDialog", "Pattern:", nullptr));
        patternComboBox->setItemText(0, QCoreApplication::translate("CalibrationDialog", "circles", nullptr));
        patternComboBox->setItemText(1, QCoreApplication::translate("CalibrationDialog", "checkers", nullptr));

        snapButton->setText(QCoreApplication::translate("CalibrationDialog", "Snap", nullptr));
        label->setText(QCoreApplication::translate("CalibrationDialog", "Spacing (mm):", nullptr));
        calibrateButton->setText(QCoreApplication::translate("CalibrationDialog", "Calibrate", nullptr));
        cancelButton->setText(QCoreApplication::translate("CalibrationDialog", "&Cancel", nullptr));
        saveButton->setText(QCoreApplication::translate("CalibrationDialog", "&Save", nullptr));
        label_3->setText(QCoreApplication::translate("CalibrationDialog", "Rows:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CalibrationDialog: public Ui_CalibrationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALIBRATIONDIALOG_H
