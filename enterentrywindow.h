#ifndef ENTERENTRYWINDOW_H
#define ENTERENTRYWINDOW_H

#include <QDialog>
#include <iostream>
#include "ui_enterentrywindow.h"
#include "errorwindow.h"
#include "function.h"
#include "class.h"
#include "struct.h"
#include "mainwindow.h"
#include "objects.h"

namespace Ui {
class EnterEntryWindow;
}

class EnterEntryWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EnterEntryWindow(QWidget *parent = nullptr);
    ~EnterEntryWindow();

private slots:
    void on_enterData_clicked();

private:
    Ui::EnterEntryWindow *ui;
};

#endif // ENTERENTRYWINDOW_H
