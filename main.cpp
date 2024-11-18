#include <QApplication>
#include "function.h"
#include "class.h"
#include "mainwindow.h"
#include "objects.h"

#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    w=new MainWindow();
    w->show();
    return a.exec();
}

