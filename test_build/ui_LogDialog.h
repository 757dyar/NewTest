/********************************************************************************
** Form generated from reading UI file 'LogDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGDIALOG_H
#define UI_LOGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPlainTextEdit>

QT_BEGIN_NAMESPACE

class Ui_LogDialog
{
public:
    QGridLayout *gridLayout;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QDialog *LogDialog)
    {
        if (LogDialog->objectName().isEmpty())
            LogDialog->setObjectName(QString::fromUtf8("LogDialog"));
        LogDialog->resize(732, 494);
        LogDialog->setSizeGripEnabled(true);
        gridLayout = new QGridLayout(LogDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        plainTextEdit = new QPlainTextEdit(LogDialog);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setUndoRedoEnabled(false);
        plainTextEdit->setReadOnly(true);

        gridLayout->addWidget(plainTextEdit, 0, 0, 1, 1);


        retranslateUi(LogDialog);

        QMetaObject::connectSlotsByName(LogDialog);
    } // setupUi

    void retranslateUi(QDialog *LogDialog)
    {
        LogDialog->setWindowTitle(QCoreApplication::translate("LogDialog", "Log", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LogDialog: public Ui_LogDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGDIALOG_H
