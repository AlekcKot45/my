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
    QLabel *label_3;
    QLineEdit *time;
    QLineEdit *date;
    QLabel *label_2;
    QLabel *label;
    QPushButton *enterData;
    QLineEdit *text;

    void setupUi(QDialog *EnterEntryWindow)
    {
        if (EnterEntryWindow->objectName().isEmpty())
            EnterEntryWindow->setObjectName("EnterEntryWindow");
        EnterEntryWindow->resize(400, 300);
        label_3 = new QLabel(EnterEntryWindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(90, 150, 63, 20));
        time = new QLineEdit(EnterEntryWindow);
        time->setObjectName("time");
        time->setGeometry(QRect(200, 100, 113, 28));
        date = new QLineEdit(EnterEntryWindow);
        date->setObjectName("date");
        date->setGeometry(QRect(200, 60, 113, 28));
        label_2 = new QLabel(EnterEntryWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(90, 70, 63, 20));
        label = new QLabel(EnterEntryWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(90, 110, 63, 20));
        enterData = new QPushButton(EnterEntryWindow);
        enterData->setObjectName("enterData");
        enterData->setGeometry(QRect(140, 220, 83, 29));
        text = new QLineEdit(EnterEntryWindow);
        text->setObjectName("text");
        text->setGeometry(QRect(200, 140, 113, 28));

        retranslateUi(EnterEntryWindow);

        QMetaObject::connectSlotsByName(EnterEntryWindow);
    } // setupUi

    void retranslateUi(QDialog *EnterEntryWindow)
    {
        EnterEntryWindow->setWindowTitle(QCoreApplication::translate("EnterEntryWindow", "Dialog", nullptr));
        label_3->setText(QCoreApplication::translate("EnterEntryWindow", "text", nullptr));
        time->setPlaceholderText(QCoreApplication::translate("EnterEntryWindow", "hh:mm", nullptr));
        date->setPlaceholderText(QCoreApplication::translate("EnterEntryWindow", "yyyy.mm.dd", nullptr));
        label_2->setText(QCoreApplication::translate("EnterEntryWindow", "date", nullptr));
        label->setText(QCoreApplication::translate("EnterEntryWindow", "time", nullptr));
        enterData->setText(QCoreApplication::translate("EnterEntryWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EnterEntryWindow: public Ui_EnterEntryWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTERENTRYWINDOW_H
