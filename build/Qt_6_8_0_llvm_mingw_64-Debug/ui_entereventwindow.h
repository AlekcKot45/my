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
    QPushButton *enterData;
    QLineEdit *date;
    QLineEdit *time;
    QLineEdit *text;
    QLineEdit *place;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;

    void setupUi(QDialog *EnterEventWindow)
    {
        if (EnterEventWindow->objectName().isEmpty())
            EnterEventWindow->setObjectName("EnterEventWindow");
        EnterEventWindow->resize(400, 300);
        enterData = new QPushButton(EnterEventWindow);
        enterData->setObjectName("enterData");
        enterData->setGeometry(QRect(130, 240, 83, 29));
        date = new QLineEdit(EnterEventWindow);
        date->setObjectName("date");
        date->setGeometry(QRect(210, 40, 113, 28));
        time = new QLineEdit(EnterEventWindow);
        time->setObjectName("time");
        time->setGeometry(QRect(210, 80, 113, 28));
        text = new QLineEdit(EnterEventWindow);
        text->setObjectName("text");
        text->setGeometry(QRect(210, 120, 113, 28));
        place = new QLineEdit(EnterEventWindow);
        place->setObjectName("place");
        place->setGeometry(QRect(210, 200, 113, 28));
        label = new QLabel(EnterEventWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 80, 63, 20));
        label_2 = new QLabel(EnterEventWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(90, 50, 63, 20));
        label_3 = new QLabel(EnterEventWindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(100, 130, 63, 20));
        label_5 = new QLabel(EnterEventWindow);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(100, 200, 63, 20));

        retranslateUi(EnterEventWindow);

        QMetaObject::connectSlotsByName(EnterEventWindow);
    } // setupUi

    void retranslateUi(QDialog *EnterEventWindow)
    {
        EnterEventWindow->setWindowTitle(QCoreApplication::translate("EnterEventWindow", "Dialog", nullptr));
        enterData->setText(QCoreApplication::translate("EnterEventWindow", "PushButton", nullptr));
        label->setText(QCoreApplication::translate("EnterEventWindow", "time", nullptr));
        label_2->setText(QCoreApplication::translate("EnterEventWindow", "date", nullptr));
        label_3->setText(QCoreApplication::translate("EnterEventWindow", "text", nullptr));
        label_5->setText(QCoreApplication::translate("EnterEventWindow", "place", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EnterEventWindow: public Ui_EnterEventWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTEREVENTWINDOW_H
