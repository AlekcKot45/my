/********************************************************************************
** Form generated from reading UI file 'search.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCH_H
#define UI_SEARCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_search
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *year;
    QLineEdit *month;
    QPushButton *search_2;
    QLineEdit *day;
    QLineEdit *hour;
    QLineEdit *minute;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QDialog *search)
    {
        if (search->objectName().isEmpty())
            search->setObjectName("search");
        search->resize(493, 383);
        verticalLayoutWidget = new QWidget(search);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(9, 159, 471, 211));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        year = new QLineEdit(search);
        year->setObjectName("year");
        year->setGeometry(QRect(80, 40, 91, 28));
        month = new QLineEdit(search);
        month->setObjectName("month");
        month->setGeometry(QRect(80, 80, 91, 28));
        search_2 = new QPushButton(search);
        search_2->setObjectName("search_2");
        search_2->setGeometry(QRect(260, 120, 83, 29));
        day = new QLineEdit(search);
        day->setObjectName("day");
        day->setGeometry(QRect(80, 120, 91, 28));
        hour = new QLineEdit(search);
        hour->setObjectName("hour");
        hour->setGeometry(QRect(260, 40, 91, 28));
        minute = new QLineEdit(search);
        minute->setObjectName("minute");
        minute->setGeometry(QRect(260, 80, 91, 28));
        label = new QLabel(search);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 40, 63, 20));
        label_2 = new QLabel(search);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 80, 63, 20));
        label_3 = new QLabel(search);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 120, 63, 20));
        label_4 = new QLabel(search);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(190, 40, 63, 20));
        label_5 = new QLabel(search);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(190, 80, 63, 20));

        retranslateUi(search);

        QMetaObject::connectSlotsByName(search);
    } // setupUi

    void retranslateUi(QDialog *search)
    {
        search->setWindowTitle(QCoreApplication::translate("search", "Dialog", nullptr));
        search_2->setText(QCoreApplication::translate("search", "search", nullptr));
        label->setText(QCoreApplication::translate("search", "year", nullptr));
        label_2->setText(QCoreApplication::translate("search", "month", nullptr));
        label_3->setText(QCoreApplication::translate("search", "day", nullptr));
        label_4->setText(QCoreApplication::translate("search", "hour", nullptr));
        label_5->setText(QCoreApplication::translate("search", "minute", nullptr));
    } // retranslateUi

};

namespace Ui {
    class search: public Ui_search {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCH_H
