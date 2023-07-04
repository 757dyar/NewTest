/********************************************************************************
** Form generated from reading UI file 'PreferenceDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREFERENCEDIALOG_H
#define UI_PREFERENCEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_PreferenceDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *patternModeLayout;
    QCheckBox *patternHorizontalCheckBox;
    QCheckBox *patternVerticalCheckBox;
    QLabel *projectorLabel;
    QComboBox *patternModeComboBox;
    QHBoxLayout *shutterLayout;
    QLabel *shutterLabel;
    QDoubleSpinBox *shutterDoubleSpinBox;
    QLabel *delayMsLabel_2;
    QFormLayout *formLayout;
    QCheckBox *framesCheckBox;
    QCheckBox *pointCloudsCheckBox;
    QLabel *cameraLabel;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QRadioButton *triggerSoftwareRadioButton;
    QRadioButton *triggerHardwareRadioButton;
    QComboBox *projectorComboBox;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QRadioButton *aquisitioncontinuousRadioButton;
    QRadioButton *aquisitionSingleRadioButton;
    QComboBox *cameraComboBox;
    QLabel *patternModeLabel;
    QDialogButtonBox *buttonBox;
    QLabel *writeToDiskLabel;
    QHBoxLayout *triggerLayout;
    QHBoxLayout *shiftLayout;
    QLabel *shiftLabel;
    QSpinBox *shiftSpinBox;
    QHBoxLayout *delayLayout;
    QLabel *delayLabel;
    QSpinBox *delaySpinBox;
    QLabel *delayMsLabel;

    void setupUi(QDialog *PreferenceDialog)
    {
        if (PreferenceDialog->objectName().isEmpty())
            PreferenceDialog->setObjectName(QString::fromUtf8("PreferenceDialog"));
        PreferenceDialog->resize(322, 633);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PreferenceDialog->sizePolicy().hasHeightForWidth());
        PreferenceDialog->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(PreferenceDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        patternModeLayout = new QHBoxLayout();
        patternModeLayout->setObjectName(QString::fromUtf8("patternModeLayout"));
        patternHorizontalCheckBox = new QCheckBox(PreferenceDialog);
        patternHorizontalCheckBox->setObjectName(QString::fromUtf8("patternHorizontalCheckBox"));
        patternHorizontalCheckBox->setChecked(true);

        patternModeLayout->addWidget(patternHorizontalCheckBox);

        patternVerticalCheckBox = new QCheckBox(PreferenceDialog);
        patternVerticalCheckBox->setObjectName(QString::fromUtf8("patternVerticalCheckBox"));

        patternModeLayout->addWidget(patternVerticalCheckBox);


        gridLayout->addLayout(patternModeLayout, 3, 0, 1, 1);

        projectorLabel = new QLabel(PreferenceDialog);
        projectorLabel->setObjectName(QString::fromUtf8("projectorLabel"));

        gridLayout->addWidget(projectorLabel, 4, 0, 1, 1);

        patternModeComboBox = new QComboBox(PreferenceDialog);
        patternModeComboBox->setObjectName(QString::fromUtf8("patternModeComboBox"));

        gridLayout->addWidget(patternModeComboBox, 2, 0, 1, 1);

        shutterLayout = new QHBoxLayout();
        shutterLayout->setObjectName(QString::fromUtf8("shutterLayout"));
        shutterLabel = new QLabel(PreferenceDialog);
        shutterLabel->setObjectName(QString::fromUtf8("shutterLabel"));
        shutterLabel->setEnabled(true);

        shutterLayout->addWidget(shutterLabel);

        shutterDoubleSpinBox = new QDoubleSpinBox(PreferenceDialog);
        shutterDoubleSpinBox->setObjectName(QString::fromUtf8("shutterDoubleSpinBox"));
        shutterDoubleSpinBox->setDecimals(3);
        shutterDoubleSpinBox->setMaximum(999.990000000000009);

        shutterLayout->addWidget(shutterDoubleSpinBox);

        delayMsLabel_2 = new QLabel(PreferenceDialog);
        delayMsLabel_2->setObjectName(QString::fromUtf8("delayMsLabel_2"));

        shutterLayout->addWidget(delayMsLabel_2);


        gridLayout->addLayout(shutterLayout, 8, 0, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        framesCheckBox = new QCheckBox(PreferenceDialog);
        framesCheckBox->setObjectName(QString::fromUtf8("framesCheckBox"));

        formLayout->setWidget(0, QFormLayout::LabelRole, framesCheckBox);

        pointCloudsCheckBox = new QCheckBox(PreferenceDialog);
        pointCloudsCheckBox->setObjectName(QString::fromUtf8("pointCloudsCheckBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, pointCloudsCheckBox);


        gridLayout->addLayout(formLayout, 12, 0, 1, 1);

        cameraLabel = new QLabel(PreferenceDialog);
        cameraLabel->setObjectName(QString::fromUtf8("cameraLabel"));

        gridLayout->addWidget(cameraLabel, 6, 0, 1, 1);

        groupBox = new QGroupBox(PreferenceDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        triggerSoftwareRadioButton = new QRadioButton(groupBox);
        triggerSoftwareRadioButton->setObjectName(QString::fromUtf8("triggerSoftwareRadioButton"));

        gridLayout_3->addWidget(triggerSoftwareRadioButton, 0, 1, 1, 1);

        triggerHardwareRadioButton = new QRadioButton(groupBox);
        triggerHardwareRadioButton->setObjectName(QString::fromUtf8("triggerHardwareRadioButton"));
        triggerHardwareRadioButton->setChecked(true);

        gridLayout_3->addWidget(triggerHardwareRadioButton, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox, 9, 0, 1, 1);

        projectorComboBox = new QComboBox(PreferenceDialog);
        projectorComboBox->setObjectName(QString::fromUtf8("projectorComboBox"));

        gridLayout->addWidget(projectorComboBox, 5, 0, 1, 1);

        groupBox_2 = new QGroupBox(PreferenceDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        aquisitioncontinuousRadioButton = new QRadioButton(groupBox_2);
        aquisitioncontinuousRadioButton->setObjectName(QString::fromUtf8("aquisitioncontinuousRadioButton"));
        aquisitioncontinuousRadioButton->setChecked(true);

        gridLayout_2->addWidget(aquisitioncontinuousRadioButton, 0, 0, 1, 1);

        aquisitionSingleRadioButton = new QRadioButton(groupBox_2);
        aquisitionSingleRadioButton->setObjectName(QString::fromUtf8("aquisitionSingleRadioButton"));

        gridLayout_2->addWidget(aquisitionSingleRadioButton, 0, 1, 1, 1);


        gridLayout->addWidget(groupBox_2, 0, 0, 1, 1);

        cameraComboBox = new QComboBox(PreferenceDialog);
        cameraComboBox->setObjectName(QString::fromUtf8("cameraComboBox"));

        gridLayout->addWidget(cameraComboBox, 7, 0, 1, 1);

        patternModeLabel = new QLabel(PreferenceDialog);
        patternModeLabel->setObjectName(QString::fromUtf8("patternModeLabel"));

        gridLayout->addWidget(patternModeLabel, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(PreferenceDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 13, 0, 1, 1);

        writeToDiskLabel = new QLabel(PreferenceDialog);
        writeToDiskLabel->setObjectName(QString::fromUtf8("writeToDiskLabel"));

        gridLayout->addWidget(writeToDiskLabel, 11, 0, 1, 1);

        triggerLayout = new QHBoxLayout();
        triggerLayout->setObjectName(QString::fromUtf8("triggerLayout"));
        shiftLayout = new QHBoxLayout();
        shiftLayout->setObjectName(QString::fromUtf8("shiftLayout"));
        shiftLabel = new QLabel(PreferenceDialog);
        shiftLabel->setObjectName(QString::fromUtf8("shiftLabel"));

        shiftLayout->addWidget(shiftLabel);

        shiftSpinBox = new QSpinBox(PreferenceDialog);
        shiftSpinBox->setObjectName(QString::fromUtf8("shiftSpinBox"));
        shiftSpinBox->setMinimum(0);

        shiftLayout->addWidget(shiftSpinBox);


        triggerLayout->addLayout(shiftLayout);

        delayLayout = new QHBoxLayout();
        delayLayout->setObjectName(QString::fromUtf8("delayLayout"));
        delayLabel = new QLabel(PreferenceDialog);
        delayLabel->setObjectName(QString::fromUtf8("delayLabel"));
        delayLabel->setEnabled(true);

        delayLayout->addWidget(delayLabel);

        delaySpinBox = new QSpinBox(PreferenceDialog);
        delaySpinBox->setObjectName(QString::fromUtf8("delaySpinBox"));
        delaySpinBox->setMaximum(9999);

        delayLayout->addWidget(delaySpinBox);

        delayMsLabel = new QLabel(PreferenceDialog);
        delayMsLabel->setObjectName(QString::fromUtf8("delayMsLabel"));

        delayLayout->addWidget(delayMsLabel);


        triggerLayout->addLayout(delayLayout);


        gridLayout->addLayout(triggerLayout, 10, 0, 1, 1);

        buttonBox->raise();
        cameraLabel->raise();
        projectorLabel->raise();
        cameraComboBox->raise();
        patternModeLabel->raise();
        patternModeComboBox->raise();
        projectorComboBox->raise();
        writeToDiskLabel->raise();
        groupBox->raise();
        groupBox_2->raise();

        retranslateUi(PreferenceDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), PreferenceDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PreferenceDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(PreferenceDialog);
    } // setupUi

    void retranslateUi(QDialog *PreferenceDialog)
    {
        PreferenceDialog->setWindowTitle(QCoreApplication::translate("PreferenceDialog", "Preferences", nullptr));
        patternHorizontalCheckBox->setText(QCoreApplication::translate("PreferenceDialog", "Horizontal", nullptr));
        patternVerticalCheckBox->setText(QCoreApplication::translate("PreferenceDialog", "Vertical", nullptr));
        projectorLabel->setText(QCoreApplication::translate("PreferenceDialog", "Projector:", nullptr));
        shutterLabel->setText(QCoreApplication::translate("PreferenceDialog", "Shutter:", nullptr));
        delayMsLabel_2->setText(QCoreApplication::translate("PreferenceDialog", "ms", nullptr));
        framesCheckBox->setText(QCoreApplication::translate("PreferenceDialog", "Captured Frames", nullptr));
        pointCloudsCheckBox->setText(QCoreApplication::translate("PreferenceDialog", "Point Clouds", nullptr));
        cameraLabel->setText(QCoreApplication::translate("PreferenceDialog", "Camera:", nullptr));
        groupBox->setTitle(QCoreApplication::translate("PreferenceDialog", "Trigger Mode:", nullptr));
        triggerSoftwareRadioButton->setText(QCoreApplication::translate("PreferenceDialog", "Software", nullptr));
        triggerHardwareRadioButton->setText(QCoreApplication::translate("PreferenceDialog", "Hardware", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("PreferenceDialog", "Aquisition:", nullptr));
        aquisitioncontinuousRadioButton->setText(QCoreApplication::translate("PreferenceDialog", "Continuous", nullptr));
        aquisitionSingleRadioButton->setText(QCoreApplication::translate("PreferenceDialog", "Single Point Cloud", nullptr));
        patternModeLabel->setText(QCoreApplication::translate("PreferenceDialog", "Pattern Mode:", nullptr));
        writeToDiskLabel->setText(QCoreApplication::translate("PreferenceDialog", "Write to disk:", nullptr));
        shiftLabel->setText(QCoreApplication::translate("PreferenceDialog", "Shift:", nullptr));
        delayLabel->setText(QCoreApplication::translate("PreferenceDialog", "Delay:", nullptr));
        delayMsLabel->setText(QCoreApplication::translate("PreferenceDialog", "ms", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PreferenceDialog: public Ui_PreferenceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREFERENCEDIALOG_H
