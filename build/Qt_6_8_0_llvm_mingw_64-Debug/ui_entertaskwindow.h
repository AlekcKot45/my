/********************************************************************************
** Form generated from reading UI file 'entertaskwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTERTASKWINDOW_H
#define UI_ENTERTASKWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_EnterTaskWindow
{
public:
    QLineEdit *text;
    QPushButton *enterData;
    QLineEdit *date;
    QLabel *label_2;
    QLineEdit *time;
    QLabel *label_3;
    QLabel *label;

    void setupUi(QDialog *EnterTaskWindow)
    {
        if (EnterTaskWindow->objectName().isEmpty())
            EnterTaskWindow->setObjectName("EnterTaskWindow");
        EnterTaskWindow->resize(431, 303);
        text = new QLineEdit(EnterTaskWindow);
        text->setObjectName("text");
        text->setGeometry(QRect(200, 120, 113, 28));
        enterData = new QPushButton(EnterTaskWindow);
        enterData->setObjectName("enterData");
        enterData->setGeometry(QRect(140, 200, 83, 29));
        date = new QLineEdit(EnterTaskWindow);
        date->setObjectName("date");
        date->setGeometry(QRect(200, 40, 113, 28));
        label_2 = new QLabel(EnterTaskWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(90, 50, 63, 20));
        time = new QLineEdit(EnterTaskWindow);
        time->setObjectName("time");
        time->setGeometry(QRect(200, 80, 113, 28));
        label_3 = new QLabel(EnterTaskWindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(90, 130, 63, 20));
        label = new QLabel(EnterTaskWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(90, 90, 63, 20));

        retranslateUi(EnterTaskWindow);

        QMetaObject::connectSlotsByName(EnterTaskWindow);
    } // setupUi

    void retranslateUi(QDialog *EnterTaskWindow)
    {
        EnterTaskWindow->setWindowTitle(QCoreApplication::translate("EnterTaskWindow", "Dialog", nullptr));
        enterData->setText(QCoreApplication::translate("EnterTaskWindow", "PushButton", nullptr));
        label_2->setText(QCoreApplication::translate("EnterTaskWindow", "date", nullptr));
        label_3->setText(QCoreApplication::translate("EnterTaskWindow", "text", nullptr));
        label->setText(QCoreApplication::translate("EnterTaskWindow", "time", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EnterTaskWindow: public Ui_EnterTaskWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTERTASKWINDOW_H
