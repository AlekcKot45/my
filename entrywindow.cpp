#include "entrywindow.h"
#include "errorwindow.h"
#include "ui_entrywindow.h"
#include "function.h"
#include "class.h"
#include "struct.h"
#include "objects.h"

EntryWindow::EntryWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EntryWindow)
{
    ui->setupUi(this);
}

EntryWindow::~EntryWindow()
{
    delete ui;
}

void EntryWindow::on_enterData_clicked()
{
    std::string enterTime = (ui->time->text()).toStdString();
    std::string enterDate = (ui->date->text()).toStdString();
    std::string enterText = (ui->text->text()).toStdString();

    if(checkTime(enterTime) && checkDate(enterDate)){ //если все правильно надо создать обект этого класса и добавить его в вектор 1) написатт функции check 2) созтать куда вектор
        EntryVector.push_back(Entry(returnTime(enterTime), returnDate(enterDate), enterText));
        EntryWindow::close();
    } else { //если нет то вывести окно с шибкой и все
        ErrorWindow errorWindow;
        errorWindow.setModal(true);
        errorWindow.exec();
    }
}

