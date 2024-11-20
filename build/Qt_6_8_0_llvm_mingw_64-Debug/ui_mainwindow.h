/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *enterEntry;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *enterTask;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *enterEvent;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *enterNote;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *cancelMove;
    QSpacerItem *horizontalSpacer_6;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QVBoxLayout *verticalLayout_Entry;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_Note;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_Task;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_Event;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(40, 460, 721, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        enterEntry = new QPushButton(horizontalLayoutWidget);
        enterEntry->setObjectName("enterEntry");

        horizontalLayout->addWidget(enterEntry);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        enterTask = new QPushButton(horizontalLayoutWidget);
        enterTask->setObjectName("enterTask");

        horizontalLayout->addWidget(enterTask);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        enterEvent = new QPushButton(horizontalLayoutWidget);
        enterEvent->setObjectName("enterEvent");

        horizontalLayout->addWidget(enterEvent);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        enterNote = new QPushButton(horizontalLayoutWidget);
        enterNote->setObjectName("enterNote");

        horizontalLayout->addWidget(enterNote);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        cancelMove = new QPushButton(horizontalLayoutWidget);
        cancelMove->setObjectName("cancelMove");

        horizontalLayout->addWidget(cancelMove);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(39, 19, 721, 441));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        verticalLayout_Entry = new QVBoxLayout();
        verticalLayout_Entry->setObjectName("verticalLayout_Entry");

        verticalLayout->addLayout(verticalLayout_Entry);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        verticalLayout_Note = new QVBoxLayout();
        verticalLayout_Note->setObjectName("verticalLayout_Note");

        verticalLayout->addLayout(verticalLayout_Note);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        verticalLayout_Task = new QVBoxLayout();
        verticalLayout_Task->setObjectName("verticalLayout_Task");

        verticalLayout->addLayout(verticalLayout_Task);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName("label_4");

        verticalLayout->addWidget(label_4);

        verticalLayout_Event = new QVBoxLayout();
        verticalLayout_Event->setObjectName("verticalLayout_Event");

        verticalLayout->addLayout(verticalLayout_Event);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        enterEntry->setText(QCoreApplication::translate("MainWindow", "enterEntry", nullptr));
        enterTask->setText(QCoreApplication::translate("MainWindow", "enterTask", nullptr));
        enterEvent->setText(QCoreApplication::translate("MainWindow", "enterEvent", nullptr));
        enterNote->setText(QCoreApplication::translate("MainWindow", "enterNote", nullptr));
        cancelMove->setText(QCoreApplication::translate("MainWindow", "cancelMove", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Entry", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Note", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Task", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Event", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
