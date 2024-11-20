#include "entertaskwindow.h"
#include "ui_entertaskwindow.h"
#include "errorwindow.h"
#include "function.h"
#include "class.h"
#include "struct.h"
#include "objects.h"

EnterTaskWindow::EnterTaskWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EnterTaskWindow)
{
    ui->setupUi(this);
}

EnterTaskWindow::~EnterTaskWindow()
{
    delete ui;
}

void EnterTaskWindow::on_enterData_clicked()
{
    std::string enterTime = (ui->time->text()).toStdString();
    std::string enterDate = (ui->date->text()).toStdString();
    std::string enterText = (ui->text->text()).toStdString();

    if(checkTime(enterTime) && checkDate(enterDate)){ //если все правильно надо создать обект этого класса и добавить его в вектор 1) написатт функции check 2) созтать куда вектор
        enterTaskInVector(Task (returnDate(enterDate), returnTime(enterTime), enterText, ++idGlobal));
        w->clearLayout(w->GetUi()->verticalLayout->findChild<QVBoxLayout*>("verticalLayout_Task"));
        outTaskVectorInMainWindow(TaskVector);
        EnterTaskWindow::close();
        std::string stringForStack("3C ");
        stringForStack += w->enterDateTimeTextInString(returnDate(enterDate), returnTime(enterTime), enterText);
        stackSaveMove.push(stringForStack);
    } else { //если нет то вывести окно с шибкой и все
        ErrorWindow errorWindow;
        errorWindow.setModal(true);
        errorWindow.exec();
    }
}

