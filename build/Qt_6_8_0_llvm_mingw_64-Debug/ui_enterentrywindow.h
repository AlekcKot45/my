/********************************************************************************
** Form generated from reading UI file 'enterentrywindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTERENTRYWINDOW_H
#define UI_ENTERENTRYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_EnterEntryWindow
{
public:
    QLineEdit *date;
    QLineEdit *time;
    QLineEdit *text;
    QPushButton *enterData;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *EnterEntryWindow)
    {
        if (EnterEntryWindow->objectName().isEmpty())
            EnterEntryWindow->setObjectName("EnterEntryWindow");
        EnterEntryWindow->resize(400, 300);
        date = new QLineEdit(EnterEntryWindow);
        date->setObjectName("date");
        date->setGeometry(QRect(160, 80, 113, 28));
        time = new QLineEdit(EnterEntryWindow);
        time->setObjectName("time");
        time->setGeometry(QRect(160, 140, 113, 28));
        text = new QLineEdit(EnterEntryWindow);
        text->setObjectName("text");
        text->setGeometry(QRect(160, 210, 113, 28));
        enterData = new QPushButton(EnterEntryWindow);
        enterData->setObjectName("enterData");
        enterData->setGeometry(QRect(140, 250, 83, 29));
        label = new QLabel(EnterEntryWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 80, 63, 20));
        label_2 = new QLabel(EnterEntryWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 140, 63, 20));
        label_3 = new QLabel(EnterEntryWindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(50, 220, 63, 20));

        retranslateUi(EnterEntryWindow);

        QMetaObject::connectSlotsByName(EnterEntryWindow);
    } // setupUi

    void retranslateUi(QDialog *EnterEntryWindow)
    {
        EnterEntryWindow->setWindowTitle(QCoreApplication::translate("EnterEntryWindow", "Dialog", nullptr));
        enterData->setText(QCoreApplication::translate("EnterEntryWindow", "PushButton", nullptr));
        label->setText(QCoreApplication::translate("EnterEntryWindow", "date", nullptr));
        label_2->setText(QCoreApplication::translate("EnterEntryWindow", "time", nullptr));
        label_3->setText(QCoreApplication::translate("EnterEntryWindow", "text", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EnterEntryWindow: public Ui_EnterEntryWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTERENTRYWINDOW_H
