#include "enternotewindow.h"
#include "ui_enternotewindow.h"
#include "errorwindow.h"
#include "function.h"
#include "class.h"
#include "struct.h"
#include "objects.h"

EnterNoteWindow::EnterNoteWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EnterNoteWindow)
{
    ui->setupUi(this);
}

EnterNoteWindow::~EnterNoteWindow()
{
    delete ui;
}

void EnterNoteWindow::on_enterData_2_clicked()
{
    std::string enterTime = (ui->time->text()).toStdString();
    std::string enterDate = (ui->date->text()).toStdString();
    std::string enterText = (ui->text->text()).toStdString();
    std::string enterTag = (ui->tag->text()).toStdString();

    if(checkTime(enterTime) && checkDate(enterDate)){ //если все правильно надо создать обект этого класса и добавить его в вектор 1) написатт функции check 2) созтать куда вектор
        enterNoteInVector(Note(returnDate(enterDate), returnTime(enterTime), enterText, ++idGlobal, enterTag));
        w->clearLayout(w->GetUi()->verticalLayout->findChild<QVBoxLayout*>("verticalLayout_Note"));
        outNoteVectorInMainWindow(NoteVector);
        EnterNoteWindow::close();
    } else { //если нет то вывести окно с шибкой и все
        ErrorWindow errorWindow;
        errorWindow.setModal(true);
        errorWindow.exec();
    }
}

