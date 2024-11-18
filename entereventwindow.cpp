#include "entereventwindow.h"
#include "ui_entereventwindow.h"
#include "errorwindow.h"
#include "function.h"
#include "class.h"
#include "struct.h"
#include "objects.h"

EnterEventWindow::EnterEventWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EnterEventWindow)
{
    ui->setupUi(this);
}

EnterEventWindow::~EnterEventWindow()
{
    delete ui;
}

void EnterEventWindow::on_enterData_clicked()
{
    std::string enterTime = (ui->time->text()).toStdString();
    std::string enterDate = (ui->date->text()).toStdString();
    std::string enterText = (ui->text->text()).toStdString();
    std::string enterPlace = (ui->place->text()).toStdString();

    if(checkTime(enterTime) && checkDate(enterDate)){ //если все правильно надо создать обект этого класса и добавить его в вектор 1) написатт функции check 2) созтать куда вектор
        enterEventInVector(Event(returnDate(enterDate), returnTime(enterTime), enterText, ++idGlobal, enterPlace));
        w->clearLayout(w->GetUi()->verticalLayout->findChild<QVBoxLayout*>("verticalLayout_Event"));
        outEventVectorInMainWindow(EventVector);
        EnterEventWindow::close();
    } else { //если нет то вывести окно с шибкой и все
        ErrorWindow errorWindow;
        errorWindow.setModal(true);
        errorWindow.exec();
    }
}

