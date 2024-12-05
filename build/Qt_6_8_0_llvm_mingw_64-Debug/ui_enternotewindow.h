/********************************************************************************
** Form generated from reading UI file 'enternotewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTERNOTEWINDOW_H
#define UI_ENTERNOTEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_EnterNoteWindow
{
public:
    QLineEdit *tag;
    QLabel *label_4;
    QLabel *label_7;
    QLineEdit *time;
    QPushButton *enterData_2;
    QLineEdit *date;
    QLabel *label_6;
    QLineEdit *text;
    QLabel *label_8;

    void setupUi(QDialog *EnterNoteWindow)
    {
        if (EnterNoteWindow->objectName().isEmpty())
            EnterNoteWindow->setObjectName("EnterNoteWindow");
        EnterNoteWindow->resize(400, 300);
        tag = new QLineEdit(EnterNoteWindow);
        tag->setObjectName("tag");
        tag->setGeometry(QRect(180, 170, 113, 28));
        label_4 = new QLabel(EnterNoteWindow);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(100, 50, 63, 20));
        label_7 = new QLabel(EnterNoteWindow);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(100, 130, 63, 20));
        time = new QLineEdit(EnterNoteWindow);
        time->setObjectName("time");
        time->setGeometry(QRect(180, 90, 113, 28));
        enterData_2 = new QPushButton(EnterNoteWindow);
        enterData_2->setObjectName("enterData_2");
        enterData_2->setGeometry(QRect(150, 240, 83, 29));
        date = new QLineEdit(EnterNoteWindow);
        date->setObjectName("date");
        date->setGeometry(QRect(180, 50, 113, 28));
        label_6 = new QLabel(EnterNoteWindow);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(100, 170, 63, 20));
        text = new QLineEdit(EnterNoteWindow);
        text->setObjectName("text");
        text->setGeometry(QRect(180, 130, 113, 28));
        label_8 = new QLabel(EnterNoteWindow);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(100, 90, 63, 20));

        retranslateUi(EnterNoteWindow);

        QMetaObject::connectSlotsByName(EnterNoteWindow);
    } // setupUi

    void retranslateUi(QDialog *EnterNoteWindow)
    {
        EnterNoteWindow->setWindowTitle(QCoreApplication::translate("EnterNoteWindow", "Dialog", nullptr));
        label_4->setText(QCoreApplication::translate("EnterNoteWindow", "date", nullptr));
        label_7->setText(QCoreApplication::translate("EnterNoteWindow", "text", nullptr));
        time->setPlaceholderText(QCoreApplication::translate("EnterNoteWindow", "hh:mm", nullptr));
        enterData_2->setText(QCoreApplication::translate("EnterNoteWindow", "PushButton", nullptr));
        date->setPlaceholderText(QCoreApplication::translate("EnterNoteWindow", "yyyy.mm.dd", nullptr));
        label_6->setText(QCoreApplication::translate("EnterNoteWindow", "tag", nullptr));
        label_8->setText(QCoreApplication::translate("EnterNoteWindow", "time", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EnterNoteWindow: public Ui_EnterNoteWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTERNOTEWINDOW_H
