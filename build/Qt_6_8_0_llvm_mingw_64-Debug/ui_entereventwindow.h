/********************************************************************************
** Form generated from reading UI file 'entereventwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTEREVENTWINDOW_H
#define UI_ENTEREVENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_EnterEventWindow
{
public:
    QLabel *label_6;
    QLabel *label_8;
    QLineEdit *date;
    QLineEdit *text;
    QPushButton *enterData;
    QLabel *label_4;
    QLineEdit *place;
    QLabel *label_7;
    QLineEdit *time;

    void setupUi(QDialog *EnterEventWindow)
    {
        if (EnterEventWindow->objectName().isEmpty())
            EnterEventWindow->setObjectName("EnterEventWindow");
        EnterEventWindow->resize(400, 300);
        label_6 = new QLabel(EnterEventWindow);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(100, 170, 63, 20));
        label_8 = new QLabel(EnterEventWindow);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(100, 90, 63, 20));
        date = new QLineEdit(EnterEventWindow);
        date->setObjectName("date");
        date->setGeometry(QRect(180, 50, 113, 28));
        text = new QLineEdit(EnterEventWindow);
        text->setObjectName("text");
        text->setGeometry(QRect(180, 130, 113, 28));
        enterData = new QPushButton(EnterEventWindow);
        enterData->setObjectName("enterData");
        enterData->setGeometry(QRect(150, 240, 83, 29));
        label_4 = new QLabel(EnterEventWindow);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(100, 50, 63, 20));
        place = new QLineEdit(EnterEventWindow);
        place->setObjectName("place");
        place->setGeometry(QRect(180, 170, 113, 28));
        label_7 = new QLabel(EnterEventWindow);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(100, 130, 63, 20));
        time = new QLineEdit(EnterEventWindow);
        time->setObjectName("time");
        time->setGeometry(QRect(180, 90, 113, 28));

        retranslateUi(EnterEventWindow);

        QMetaObject::connectSlotsByName(EnterEventWindow);
    } // setupUi

    void retranslateUi(QDialog *EnterEventWindow)
    {
        EnterEventWindow->setWindowTitle(QCoreApplication::translate("EnterEventWindow", "Dialog", nullptr));
        label_6->setText(QCoreApplication::translate("EnterEventWindow", "place", nullptr));
        label_8->setText(QCoreApplication::translate("EnterEventWindow", "time", nullptr));
        date->setText(QString());
        date->setPlaceholderText(QCoreApplication::translate("EnterEventWindow", "yyyy.mm.dd", nullptr));
        text->setText(QString());
        enterData->setText(QCoreApplication::translate("EnterEventWindow", "PushButton", nullptr));
        label_4->setText(QCoreApplication::translate("EnterEventWindow", "date", nullptr));
        place->setText(QString());
        label_7->setText(QCoreApplication::translate("EnterEventWindow", "text", nullptr));
        time->setText(QString());
        time->setPlaceholderText(QCoreApplication::translate("EnterEventWindow", "hh:mm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EnterEventWindow: public Ui_EnterEventWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTEREVENTWINDOW_H
