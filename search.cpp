#include "search.h"
#include "ui_search.h"

search::search(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::search)
{
    ui->setupUi(this);
}

search::~search()
{
    delete ui;
}

#include <iostream>

void search::clearLayout(QLayout* vLayout) {
    QList<QHBoxLayout*> hLayoutsToDelete;

    // Собираем все QHBoxLayout
    for (int i = 0; i < vLayout->count(); ++i) {
        QLayoutItem* item = vLayout->itemAt(i);
        if (item && item->layout()) {
            if (auto* hLayout = dynamic_cast<QHBoxLayout*>(item->layout())) {
                hLayoutsToDelete.append(hLayout);
            }
        }
    }

    // Очищаем все собранные QHBoxLayout
    for (QHBoxLayout* hItem : hLayoutsToDelete) {
        for (int i = hItem->count() - 1; i >= 0; --i) {
            QLayoutItem* item = hItem->takeAt(i);
            if (QWidget* widget = item->widget()) {
                delete widget;
            }
            delete item;
        }
        delete hItem;
    }
}


void search::addDateTimeTextSearchWindow(const Entry& other, QHBoxLayout* newLayout){
    QString formattedDate = QString("%1.%2.%3")
                                .arg(QString::number(other.GetDate().year))
                                .arg(QString::number(other.GetDate().month).rightJustified(2, '0'))
                                .arg(QString::number(other.GetDate().day).rightJustified(2, '0'));
    QString formattedTime = QString("%1:%2")
                                .arg(QString::number(other.GetTime().hour).rightJustified(2, '0'))
                                .arg(QString::number(other.GetTime().minute).rightJustified(2, '0'));
    QLineEdit* lineDate = new QLineEdit(formattedDate);
    QLineEdit* lineTime = new QLineEdit(formattedTime);
    QLineEdit* lineText = new QLineEdit(QString::fromStdString(other.GetText()));
    lineDate->setMaximumWidth(70);
    newLayout->addWidget(lineDate, 0, Qt::AlignLeft);
    lineTime->setMaximumWidth(70);
    newLayout->addWidget(lineTime, 0, Qt::AlignLeft);
    lineText->setMaximumWidth(70);
    newLayout->addWidget(lineText, 0, Qt::AlignLeft);
    return;
}

void search::on_search_2_clicked()
{
    QString year = ui->year->text(), month = ui->month->text(), day = ui->day->text(),
        hour = ui->hour->text(), minute = ui->minute->text();

    clearLayout(ui->verticalLayout);

    for(const Entry& entry : EntryVector){
        if((year.toInt()==0 || year.toInt()==entry.GetDate().year)&&(month.toInt()==0 || month.toInt()==entry.GetDate().month)&&(day.toInt()==0 ||
            day.toInt()==entry.GetDate().day)&&(hour.toInt()==0 || hour.toInt()==entry.GetTime().hour)&&(minute.toInt()==0 || minute.toInt()==entry.GetTime().minute)){
            QHBoxLayout* newLayout = new QHBoxLayout();
            ui->verticalLayout->addLayout(newLayout);
            QLineEdit* lineName = new QLineEdit("Entry");
            lineName->setMaximumWidth(70);
            newLayout->addWidget(lineName, 0, Qt::AlignLeft);
            addDateTimeTextSearchWindow(entry, newLayout);
        }
    }
    for(const Note& note : NoteVector){
        if((year.toInt()==0 || year.toInt()==note.GetDate().year)&&(month.toInt()==0 || month.toInt()==note.GetDate().month)&&(day.toInt()==0 ||
            day.toInt()==note.GetDate().day)&&(hour.toInt()==0 || hour.toInt()==note.GetTime().hour)&&(minute.toInt()==0 || minute.toInt()==note.GetTime().minute)){
            QHBoxLayout* newLayout = new QHBoxLayout();
            ui->verticalLayout->addLayout(newLayout);
            QLineEdit* lineName = new QLineEdit("Note");
            lineName->setMaximumWidth(70);
            newLayout->addWidget(lineName, 0, Qt::AlignLeft);
            addDateTimeTextSearchWindow(note, newLayout);
            QLineEdit* lineTag = new QLineEdit(QString::fromStdString(note.GetTag()));
            lineTag->setMaximumWidth(70);
            newLayout->addWidget(lineTag, 0, Qt::AlignLeft);
        }
    }
    for(const Event& event : EventVector){
        if((year.toInt()==0 || year.toInt()==event.GetDate().year)&&(month.toInt()==0 || month.toInt()==event.GetDate().month)&&(day.toInt()==0 ||
            day.toInt()==event.GetDate().day)&&(hour.toInt()==0 || hour.toInt()==event.GetTime().hour)&&(minute.toInt()==0 || minute.toInt()==event.GetTime().minute)){
            QHBoxLayout* newLayout = new QHBoxLayout();
            ui->verticalLayout->addLayout(newLayout);
            QLineEdit* lineName = new QLineEdit("Event");
            lineName->setMaximumWidth(70);
            newLayout->addWidget(lineName, 0, Qt::AlignLeft);
            addDateTimeTextSearchWindow(event, newLayout);
            //QLineEdit* lineCompleted = new QLineEdit(QString::number(event.GetCompleted()));
            QLineEdit* linePlace = new QLineEdit(QString::fromStdString(event.GetPlace()));
            //lineCompleted->setMaximumWidth(70);
            //newLayout->addWidget(lineCompleted, 0, Qt::AlignLeft);
            linePlace->setMaximumWidth(70);
            newLayout->addWidget(linePlace, 0, Qt::AlignLeft);
        }
    }
    for(const Task& task : TaskVector){
        if((year.toInt()==0 || year.toInt()==task.GetDate().year)&&(month.toInt()==0 || month.toInt()==task.GetDate().month)&&(day.toInt()==0 ||
            day.toInt()==task.GetDate().day)&&(hour.toInt()==0 || hour.toInt()==task.GetTime().hour)&&(minute.toInt()==0 || minute.toInt()==task.GetTime().minute)){
            QHBoxLayout* newLayout = new QHBoxLayout();
            ui->verticalLayout->addLayout(newLayout);
            QLineEdit* lineName = new QLineEdit("Task");
            lineName->setMaximumWidth(70);
            newLayout->addWidget(lineName, 0, Qt::AlignLeft);
            addDateTimeTextSearchWindow(task, newLayout);
            QLineEdit* lineCompleted = new QLineEdit(QString::number(task.GetCompleted()));
            lineCompleted->setMaximumWidth(70);
            newLayout->addWidget(lineCompleted, 0, Qt::AlignLeft);
        }
    }
}

