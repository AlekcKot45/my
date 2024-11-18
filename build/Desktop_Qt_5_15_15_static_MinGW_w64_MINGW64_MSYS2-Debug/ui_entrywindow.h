/********************************************************************************
** Form generated from reading UI file 'entrywindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.15
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTRYWINDOW_H
#define UI_ENTRYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SecondWindow
{
public:
    QPushButton *enterData;
    QLineEdit *date;
    QLineEdit *text;
    QLineEdit *time;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *SecondWindow)
    {
        if (SecondWindow->objectName().isEmpty())
            SecondWindow->setObjectName(QString::fromUtf8("SecondWindow"));
        SecondWindow->resize(400, 300);
        enterData = new QPushButton(SecondWindow);
        enterData->setObjectName(QString::fromUtf8("enterData"));
        enterData->setGeometry(QRect(130, 230, 83, 29));
        date = new QLineEdit(SecondWindow);
        date->setObjectName(QString::fromUtf8("date"));
        date->setGeometry(QRect(110, 130, 113, 28));
        text = new QLineEdit(SecondWindow);
        text->setObjectName(QString::fromUtf8("text"));
        text->setGeometry(QRect(110, 180, 113, 28));
        time = new QLineEdit(SecondWindow);
        time->setObjectName(QString::fromUtf8("time"));
        time->setGeometry(QRect(110, 90, 113, 28));
        label = new QLabel(SecondWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 90, 63, 20));
        label_2 = new QLabel(SecondWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 130, 63, 20));
        label_3 = new QLabel(SecondWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 180, 63, 20));

        retranslateUi(SecondWindow);

        QMetaObject::connectSlotsByName(SecondWindow);
    } // setupUi

    void retranslateUi(QDialog *SecondWindow)
    {
        SecondWindow->setWindowTitle(QCoreApplication::translate("SecondWindow", "Dialog", nullptr));
        enterData->setText(QCoreApplication::translate("SecondWindow", "PushButton", nullptr));
        date->setText(QString());
        label->setText(QCoreApplication::translate("SecondWindow", "time", nullptr));
        label_2->setText(QCoreApplication::translate("SecondWindow", "date", nullptr));
        label_3->setText(QCoreApplication::translate("SecondWindow", "text", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SecondWindow: public Ui_SecondWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTRYWINDOW_H
