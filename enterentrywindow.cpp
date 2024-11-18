#include "enterentrywindow.h"

EnterEntryWindow::EnterEntryWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EnterEntryWindow)
{
    ui->setupUi(this);
}

EnterEntryWindow::~EnterEntryWindow()
{
    delete ui;
}

void EnterEntryWindow::on_enterData_clicked()
{
    std::string enterTime = (ui->time->text()).toStdString();
    std::string enterDate = (ui->date->text()).toStdString();
    std::string enterText = (ui->text->text()).toStdString();
    try{
        checkTime(enterTime);
        checkDate(enterDate);
    }
    catch(ExpInputData expInputData){
        std::cout<<"you enter uncorrect data: "<<expInputData.GetMsg()<<". try again\n";
        EnterEntryWindow::close();
        ErrorWindow errorWindow;
        errorWindow.setModal(true);
        errorWindow.exec();
        return;
    }
    if(checkTime(enterTime) && checkDate(enterDate)){ //если все правильно надо создать обект этого класса и добавить его в вектор 1) написатт функции check 2) созтать куда вектор
        enterEntryInVector(Entry(returnDate(enterDate), returnTime(enterTime), enterText, ++idGlobal));
        w->clearLayout(w->GetUi()->verticalLayout->findChild<QVBoxLayout*>("verticalLayout_Entry"));
        outEntryVectorInMainWindow(EntryVector);
        EnterEntryWindow::close();
    } else { //если нет то вывести окно с шибкой и все
        ErrorWindow errorWindow;
        errorWindow.setModal(true);
        errorWindow.exec();
    }
}

