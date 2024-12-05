#include "mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_enterEntry_clicked()
{
    EnterEntryWindow enterEntryWindow;
    enterEntryWindow.setModal(true);
    enterEntryWindow.exec();
}

void MainWindow::on_enterEvent_clicked()
{
    EnterEventWindow enterEventWindow;
    enterEventWindow.setModal(true);
    enterEventWindow.exec();
}

void MainWindow::on_enterTask_clicked()
{
    EnterTaskWindow enterTaskWindow;
    enterTaskWindow.setModal(true);
    enterTaskWindow.exec();
}


void MainWindow::on_enterNote_clicked()
{
    EnterNoteWindow enterNoteWindow;
    enterNoteWindow.setModal(true);
    enterNoteWindow.exec();
}

void MainWindow::on_search_clicked()
{
    search search;
    search.setModal(true);
    search.exec();
}

void MainWindow::searchIdInVector(QHBoxLayout* newLayout){
    QWidget* widget = newLayout->takeAt(newLayout->count()-3)->widget();
    QLineEdit* lineEdit = qobject_cast<QLineEdit*>(widget);
    int id =(lineEdit->text()).toInt();
    for(size_t i=0; i!=EntryVector.size(); ++i)
        if(id==EntryVector[i].GetId()){
            EntryVector.erase(EntryVector.begin() + i);
            break;
        }
    for(size_t i=0; i!=TaskVector.size(); ++i)
        if(id==TaskVector[i].GetId()){
            TaskVector.erase(TaskVector.begin() + i);
            break;
        }
    for(size_t i=0; i!=NoteVector.size(); ++i)
        if(id==NoteVector[i].GetId()){
            NoteVector.erase(NoteVector.begin() + i);
            break;
        }
    for(size_t i=0; i!=EventVector.size(); ++i)
        if(id==EventVector[i].GetId()){
            EventVector.erase(EventVector.begin() + i);
            break;
        }
    widget->deleteLater();
}

void MainWindow::AddButtonDelete(QHBoxLayout* newLayout){
    QPushButton* deleteButton = new QPushButton("Delete");
    newLayout->addWidget(deleteButton, 0, Qt::AlignRight);

    // Подключаем сигнал нажатия кнопки к слоту удаления
    connect(deleteButton, &QPushButton::clicked, [newLayout, this]() {
        searchIdInVector(newLayout);
        // Очищаем содержимое макета
        while (QLayoutItem* item = newLayout->takeAt(0)) {
            if (QWidget* widget = item->widget()) {
                widget->deleteLater(); // Удаляем виджет
            }
            delete item; // Удаляем элемент макета
        }

        // Удаляем сам QHBoxLayout
        delete newLayout; // Удаляем макет

    });
}

void MainWindow::outDateTimeText(QHBoxLayout* newLayout, const Entry& other){
    QString date = QString("%1.%2.%3")
                                .arg(other.GetDate().year)
                                .arg(other.GetDate().month, 2, 10, QChar('0'))  // Форматируем месяц с ведущими нулями
                                .arg(other.GetDate().day, 2, 10, QChar('0'));   // Форматируем день с ведущими нулями

    QString time = QString("%1:%2")
                                .arg(other.GetTime().hour, 2, 10, QChar('0'))  // Форматируем час с ведущими нулями
                                .arg(other.GetTime().minute, 2, 10, QChar('0')); // Форматируем минуты с ведущими нулями
    QLineEdit* lineDate = new QLineEdit(date);
    QLineEdit* lineTime = new QLineEdit(time);
    QLineEdit* lineText = new QLineEdit(QString::fromStdString(other.GetText()));
    newLayout->addWidget(lineDate, 0, Qt::AlignLeft);
    newLayout->addWidget(lineTime, 0, Qt::AlignLeft);
    newLayout->addWidget(lineText, 0, Qt::AlignLeft);
}

void MainWindow::outOneEntry(const Entry& other) {
    QHBoxLayout* newLayout = new QHBoxLayout();
    ui->verticalLayout_Entry->addLayout(newLayout);
    outDateTimeText(newLayout, other);
    QLineEdit* labelId = new QLineEdit(QString::fromStdString(std::to_string(other.GetId())));
    newLayout->addWidget(labelId, 0, Qt::AlignLeft);
    QPushButton* deleteButton = new QPushButton("Delete");
    newLayout->addWidget(deleteButton, 0, Qt::AlignRight);

    // Подключаем сигнал нажатия кнопки к слоту удаления
    connect(deleteButton, &QPushButton::clicked, [newLayout, this]() {
        searchIdInVector(newLayout);

        QString date, time, text;
        for (int i = 0; i < newLayout->count(); ++i) {
            QWidget* widget = newLayout->itemAt(i)->widget();
            QLineEdit* line = qobject_cast<QLineEdit*>(widget);
            if (line) {
                if (i == 0) date = line->text();
                else if (i == 1) time = line->text();
                else if (i == 2) text = line->text();
            }
        }
        std::string stringForStack("1D ");
        stringForStack+=enterDateTimeTextInString(date.toStdString(), time.toStdString(), text.toStdString());
        stackSaveMove.push(stringForStack);
        // Очищаем содержимое макета
        while (QLayoutItem* item = newLayout->takeAt(0)) {
            if (QWidget* widget = item->widget()) {
                widget->deleteLater(); // Удаляем виджет
            }
            delete item; // Удаляем элемент макета
        }

        // Удаляем сам QHBoxLayout
        delete newLayout; // Удаляем макет

    });
    QPushButton* editButton = new QPushButton("Edit");
    newLayout->addWidget(editButton, 0, Qt::AlignRight);
    connect(editButton, &QPushButton::clicked, [newLayout, this]() {
        QString date, time, text;
        for (int i = 0; i < newLayout->count(); ++i) {
            QWidget* widget = newLayout->itemAt(i)->widget();
            QLineEdit* line = qobject_cast<QLineEdit*>(widget);
            if (line) {
                if (i == 0) date = line->text();
                else if (i == 1) time = line->text();
                else if (i == 2) text = line->text();
            }
        }
        searchIdInVector(newLayout);
        EnterEntryWindow enterEntryWindow;
        if (QLineEdit* dateLineEdit = enterEntryWindow.findChild<QLineEdit*>("date")) {
            dateLineEdit->setText(date);
        }
        if (QLineEdit* timeLineEdit = enterEntryWindow.findChild<QLineEdit*>("time")) {
            timeLineEdit->setText(time);
        }
        if (QLineEdit* textLineEdit = enterEntryWindow.findChild<QLineEdit*>("text")) {
            textLineEdit->setText(text);
        }
        std::string stringForStack = "1E " + enterDateTimeTextInString(date.toStdString(), time.toStdString(), text.toStdString());
        stackSaveMove.push(stringForStack);
        enterEntryWindow.setModal(true);
        enterEntryWindow.exec();
    });
}

void MainWindow::outOneNote(const Note& other) {
    QHBoxLayout* newLayout = new QHBoxLayout();
    ui->verticalLayout_Note->addLayout(newLayout);
    outDateTimeText(newLayout, other);

    QLineEdit* labelTag = new QLineEdit(QString::fromStdString(other.GetTag()));
    QLineEdit* labelId = new QLineEdit(QString::fromStdString(std::to_string(other.GetId())));

    newLayout->addWidget(labelTag, 0, Qt::AlignLeft);
    newLayout->addWidget(labelId, 0, Qt::AlignLeft);

    QPushButton* deleteButton = new QPushButton("Delete");
    newLayout->addWidget(deleteButton, 0, Qt::AlignRight);

    // Подключаем сигнал нажатия кнопки к слоту удаления
    connect(deleteButton, &QPushButton::clicked, [newLayout, this]() {
        QString date, time, text, tag;
        for (int i = 0; i < newLayout->count(); ++i) {
            QWidget* widget = newLayout->itemAt(i)->widget();
            QLineEdit* line = qobject_cast<QLineEdit*>(widget);
            if (line) {
                if (i == 0) date = line->text();
                else if (i == 1) time = line->text();
                else if (i == 2) text = line->text();
                else if (i == 3) tag = line->text();
            }
        }
        std::string stringForStack("4D ");
        stringForStack+=enterDateTimeTextInString(date.toStdString(), time.toStdString(), text.toStdString());
        stringForStack=stringForStack+" "+tag.toStdString();
        stackSaveMove.push(stringForStack);
        searchIdInVector(newLayout);
        // Очищаем содержимое макета
        while (QLayoutItem* item = newLayout->takeAt(0)) {
            if (QWidget* widget = item->widget()) {
                widget->deleteLater(); // Удаляем виджет
            }
            delete item; // Удаляем элемент макета
        }

        // Удаляем сам QHBoxLayout
        delete newLayout; // Удаляем макет

    });

    QPushButton* editButton = new QPushButton("Edit");
    newLayout->addWidget(editButton, 0, Qt::AlignRight);

    connect(editButton, &QPushButton::clicked, [newLayout, this]() {
        QString date, time, text, tag;

        // Извлечение данных из lineEdit
        for (int i = 0; i < newLayout->count(); ++i) {
            QWidget* widget = newLayout->itemAt(i)->widget();
            QLineEdit* line = qobject_cast<QLineEdit*>(widget);
            if (line) {
                if (i == 0) date = line->text();
                else if (i == 1) time = line->text();
                else if (i == 2) text = line->text();
                else if (i == 3) tag = line->text();
            }
        }

        // Открытие окна редактирования
        EnterNoteWindow* enterNoteWindow = new EnterNoteWindow();

        // Заполнение полей
        if (QLineEdit* dateLineEdit = enterNoteWindow->findChild<QLineEdit*>("date")) {
            dateLineEdit->setText(date);
        }
        if (QLineEdit* timeLineEdit = enterNoteWindow->findChild<QLineEdit*>("time")) {
            timeLineEdit->setText(time);
        }
        if (QLineEdit* textLineEdit = enterNoteWindow->findChild<QLineEdit*>("text")) {
            textLineEdit->setText(text);
        }
        if (QLineEdit* tagLineEdit = enterNoteWindow->findChild<QLineEdit*>("tag")) {
            tagLineEdit->setText(tag);
        }

        enterNoteWindow->setModal(true);

        // Проверка результата выполнения окна
        searchIdInVector(newLayout);
        enterNoteWindow->exec();
        delete enterNoteWindow; // Не забудьте освободить память
    });
}



void MainWindow::outOneTask(const Task& other) {
    QHBoxLayout* newLayout = new QHBoxLayout();
    ui->verticalLayout_Task->addLayout(newLayout);
    outDateTimeText(newLayout, other);
    std::string completed =std::to_string (other.GetCompleted());
    QLineEdit* labelCompleted = new QLineEdit(QString::fromStdString(completed));
    QLineEdit* labelId = new QLineEdit(QString::fromStdString(std::to_string(other.GetId())));
    newLayout->addWidget(labelCompleted, 0, Qt::AlignLeft);
    newLayout->addWidget(labelId, 0, Qt::AlignLeft);
    QPushButton* deleteButton = new QPushButton("Delete");
    newLayout->addWidget(deleteButton, 0, Qt::AlignRight);

    // Подключаем сигнал нажатия кнопки к слоту удаления
    connect(deleteButton, &QPushButton::clicked, [newLayout, this]() {
        QString date, time, text;
        for (int i = 0; i < newLayout->count(); ++i) {
            QWidget* widget = newLayout->itemAt(i)->widget();
            QLineEdit* line = qobject_cast<QLineEdit*>(widget);
            if (line) {
                if (i == 0) date = line->text();
                else if (i == 1) time = line->text();
                else if (i == 2) text = line->text();
            }
        }
        std::string stringForStack("3D ");
        stringForStack+=enterDateTimeTextInString(date.toStdString(), time.toStdString(), text.toStdString());
        stackSaveMove.push(stringForStack);
        searchIdInVector(newLayout);
        // Очищаем содержимое макета
        while (QLayoutItem* item = newLayout->takeAt(0)) {
            if (QWidget* widget = item->widget()) {
                widget->deleteLater(); // Удаляем виджет
            }
            delete item; // Удаляем элемент макета
        }

        // Удаляем сам QHBoxLayout
        delete newLayout; // Удаляем макет

    });
    QPushButton* editButton = new QPushButton("Edit");
    newLayout->addWidget(editButton, 0, Qt::AlignRight);
    connect(editButton, &QPushButton::clicked, [newLayout, this]() {
        QString date, time, text;
        for (int i = 0; i < newLayout->count(); ++i) {
            QWidget* widget = newLayout->itemAt(i)->widget();
            QLineEdit* line = qobject_cast<QLineEdit*>(widget);
            if (line) {
                if (i == 0) date = line->text();
                else if (i == 1) time = line->text();
                else if (i == 2) text = line->text();
            }
        }
        searchIdInVector(newLayout);
        EnterTaskWindow* enterTaskWindow = new EnterTaskWindow();
        if (QLineEdit* dateLineEdit = enterTaskWindow->findChild<QLineEdit*>("date")) {
            dateLineEdit->setText(date);
        }
        if (QLineEdit* timeLineEdit = enterTaskWindow->findChild<QLineEdit*>("time")) {
            timeLineEdit->setText(time);
        }
        if (QLineEdit* textLineEdit = enterTaskWindow->findChild<QLineEdit*>("text")) {
            textLineEdit->setText(text);
        }
        enterTaskWindow->setModal(true);
        enterTaskWindow->exec();
        delete enterTaskWindow;
    });
}

void MainWindow::outOneEvent(const Event& other) {
    QHBoxLayout* newLayout = new QHBoxLayout();
    ui->verticalLayout_Event->addLayout(newLayout);
    outDateTimeText(newLayout, other);
    QLineEdit* labelPlace = new QLineEdit(QString::fromStdString(other.GetPlace()));
    QLineEdit* labelId = new QLineEdit(QString::fromStdString(std::to_string(other.GetId())));
    newLayout->addWidget(labelPlace, 0, Qt::AlignLeft);
    newLayout->addWidget(labelId, 0, Qt::AlignLeft);
    QPushButton* deleteButton = new QPushButton("Delete");
    newLayout->addWidget(deleteButton, 0, Qt::AlignRight);

    // Подключаем сигнал нажатия кнопки к слоту удаления
    connect(deleteButton, &QPushButton::clicked, [newLayout, this]() {
        QString date, time, text, place;
        for (int i = 0; i < newLayout->count(); ++i) {
            QWidget* widget = newLayout->itemAt(i)->widget();
            QLineEdit* line = qobject_cast<QLineEdit*>(widget);
            if (line) {
                if (i == 0) date = line->text();
                else if (i == 1) time = line->text();
                else if (i == 2) text = line->text();
                else if (i == 3) place = line->text();
            }
        }
        std::string stringForStack("2D ");
        stringForStack+=enterDateTimeTextInString(date.toStdString(), time.toStdString(), text.toStdString());
        stringForStack=stringForStack+" "+place.toStdString();
        stackSaveMove.push(stringForStack);
        searchIdInVector(newLayout);
        // Очищаем содержимое макета
        while (QLayoutItem* item = newLayout->takeAt(0)) {
            if (QWidget* widget = item->widget()) {
                widget->deleteLater(); // Удаляем виджет
            }
            delete item; // Удаляем элемент макета
        }

        // Удаляем сам QHBoxLayout
        delete newLayout; // Удаляем макет

    });
    QPushButton* editButton = new QPushButton("Edit");
    newLayout->addWidget(editButton, 0, Qt::AlignRight);
    connect(editButton, &QPushButton::clicked, [newLayout, this]() {
        QString date, time, text, place;
        for (int i = 0; i < newLayout->count(); ++i) {
            QWidget* widget = newLayout->itemAt(i)->widget();
            QLineEdit* line = qobject_cast<QLineEdit*>(widget);
            if (line) {
                if (i == 0) date = line->text();
                else if (i == 1) time = line->text();
                else if (i == 2) text = line->text();
                else if (i == 3) place = line->text();
            }
        }
        searchIdInVector(newLayout);
        EnterEventWindow* enterEventWindow = new EnterEventWindow();
        if (QLineEdit* dateLineEdit = enterEventWindow->findChild<QLineEdit*>("date")) {
            dateLineEdit->setText(date);
        }
        if (QLineEdit* timeLineEdit = enterEventWindow->findChild<QLineEdit*>("time")) {
            timeLineEdit->setText(time);
        }
        if (QLineEdit* textLineEdit = enterEventWindow->findChild<QLineEdit*>("text")) {
            textLineEdit->setText(text);
        }
        if (QLineEdit* placeLineEdit = enterEventWindow->findChild<QLineEdit*>("place")) {
            placeLineEdit->setText(place);
        }
        enterEventWindow->setModal(true);
        enterEventWindow->exec();
    });
}

Ui::MainWindow* MainWindow::GetUi(){
    return ui;
}

void MainWindow::clearLayout(QVBoxLayout* vLayout) {
    if (!vLayout) {
        return;
    }

    // Создаем список для хранения QHBoxLayout, которые нужно удалить
    QList<QHBoxLayout*> hLayoutsToDelete;

    // Сначала собираем все QHBoxLayout
    for (int i = 0; i < vLayout->count(); ++i) {
        QLayoutItem* item = vLayout->itemAt(i);
        if (item) {
            QHBoxLayout* hLayout = qobject_cast<QHBoxLayout*>(item->layout());
            if (hLayout) {
                hLayoutsToDelete.append(hLayout); // Добавляем в список для удаления
            }
        }
    }

    // Теперь очищаем все собранные QHBoxLayout
    for (QHBoxLayout* hLayout : hLayoutsToDelete) {
        while (QLayoutItem* hItem = hLayout->takeAt(0)) {
            if (QWidget* widget = hItem->widget()) {
                delete widget; // Удаляем виджет
            }
            delete hItem; // Удаляем элемент макета
        }
        delete hLayout; // Удаляем сам QHBoxLayout
    }
}

std::pair<QString, QString> enterDateAndTimeInFile(const Entry& entry){
    QString formattedDate = QString("%1.%2.%3")
    .arg(entry.GetDate().year)
        .arg(entry.GetDate().month, 2, 10, QChar('0'))  // Форматируем месяц с ведущими нулями
        .arg(entry.GetDate().day, 2, 10, QChar('0'));   // Форматируем день с ведущими нулями

    QString formattedTime = QString("%1:%2")
                                .arg(entry.GetTime().hour, 2, 10, QChar('0'))  // Форматируем час с ведущими нулями
                                .arg(entry.GetTime().minute, 2, 10, QChar('0')); // Форматируем минуты с ведущими нулями
    return {formattedDate, formattedTime};
}

void MainWindow::closeEvent(QCloseEvent*) {
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("postgres");
    db.setUserName("postgres");
    db.setPassword("20050906");

    if (!db.open()) {
        std::cout<<"database don't open";
        return;
    } std::cout << "connect database succesful" << std::endl;

    QSqlQuery queryEntry, queryEvent, queryTask, queryNote;

    // Подготовка SQL-запроса
    queryEntry.prepare("INSERT INTO entry (date, time, text) VALUES (:date, :time, :text)");
    queryEvent.prepare("INSERT INTO event (date, time, text, completed, place) VALUES (:date, :time, :text, :completed, :place)");
    queryTask.prepare("INSERT INTO task (date, time, text, completed) VALUES (:date, :time, :text, :completed)");
    queryNote.prepare("INSERT INTO note (date, time, text, tag) VALUES (:date, :time, :text, :tag)");

    // Цикл по всем записям
    for (const auto& entry : EntryVector) {
        QString formattedDate, formattedTime;
        std::tie(formattedDate, formattedTime) = enterDateAndTimeInFile(entry);
        queryEntry.bindValue(":date", formattedDate);
        queryEntry.bindValue(":time", formattedTime);
        queryEntry.bindValue(":text", QString::fromStdString(entry.GetText()));
        queryEntry.exec();
    }
    for (const auto& event : EventVector) {
        QString formattedDate, formattedTime;
        std::tie(formattedDate, formattedTime) = enterDateAndTimeInFile(event);
        queryEvent.bindValue(":date", formattedDate);
        queryEvent.bindValue(":time", formattedTime);
        queryEvent.bindValue(":text", QString::fromStdString(event.GetText()));
        queryEvent.bindValue(":completed", QString::number(event.GetCompleted()));
        queryEvent.bindValue(":place", QString::fromStdString(event.GetPlace()));
        queryEvent.exec();
    }
    for (const auto& task : TaskVector) {
        QString formattedDate, formattedTime;
        std::tie(formattedDate, formattedTime) = enterDateAndTimeInFile(task);
        queryTask.bindValue(":date", formattedDate);
        queryTask.bindValue(":time", formattedTime);
        queryTask.bindValue(":text", QString::fromStdString(task.GetText()));
        queryTask.bindValue(":completed", QString::number(task.GetCompleted()));
        queryTask.exec();
    }
    for (const auto& note : NoteVector) {
        QString formattedDate, formattedTime;
        std::tie(formattedDate, formattedTime) = enterDateAndTimeInFile(note);
        queryNote.bindValue(":date", formattedDate);
        queryNote.bindValue(":time", formattedTime);
        queryNote.bindValue(":text", QString::fromStdString(note.GetText()));
        queryNote.bindValue(":tag", QString::fromStdString(note.GetTag()));
        queryNote.exec();
    }

    return;
}


void MainWindow::showEvent(QShowEvent*) {
    return;
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("postgres");
    db.setUserName("postgres");
    db.setPassword("20050906");

    if (!db.open()) {
        std::cout<<"database don't open";
        return;
    } std::cout << "connect database succesful" << std::endl;

    QSqlQuery queryEntry("SELECT date, time, text FROM entry");
    QSqlQuery queryEvent("SELECT date, time, text, completed, place FROM event");
    QSqlQuery queryTask("SELECT date, time, text FROM task");
    QSqlQuery queryNote("SELECT date, time, text, tag FROM note");

    while (queryEntry.next()) {
        std::string date = queryEntry.value(0).toString().toStdString();
        std::string time = queryEntry.value(1).toString().toStdString();
        std::string text = queryEntry.value(2).toString().toStdString();
        enterEntryInVector(Entry({ std::stoi(date.substr(0, 4)), std::stoi(date.substr(5, 2)), std::stoi(date.substr(8, 2)) },
                                 { std::stoi(time.substr(0, 2)), std::stoi(time.substr(3, 2)) }, text, ++idGlobal));
    }
    while (queryEvent.next()) {
        std::string date = queryEvent.value(0).toString().toStdString();
        std::string time = queryEvent.value(1).toString().toStdString();
        std::string text = queryEvent.value(2).toString().toStdString();
        std::string place = queryEvent.value(3).toString().toStdString();
        enterEventInVector(Event({ std::stoi(date.substr(0, 4)), std::stoi(date.substr(5, 2)), std::stoi(date.substr(8, 2)) },
                                 { std::stoi(time.substr(0, 2)), std::stoi(time.substr(3, 2)) }, text, ++idGlobal, place));
    }
    while (queryTask.next()) {
        std::string date = queryTask.value(0).toString().toStdString();
        std::string time = queryTask.value(1).toString().toStdString();
        std::string text = queryTask.value(2).toString().toStdString();
        enterTaskInVector(Task({ std::stoi(date.substr(0, 4)), std::stoi(date.substr(5, 2)), std::stoi(date.substr(8, 2)) },
                               { std::stoi(time.substr(0, 2)), std::stoi(time.substr(3, 2)) }, text, ++idGlobal));
    }
    while (queryNote.next()) {
        std::string date = queryNote.value(0).toString().toStdString();
        std::string time = queryNote.value(1).toString().toStdString();
        std::string text = queryNote.value(2).toString().toStdString();
        std::string tag = queryNote.value(3).toString().toStdString();
        enterNoteInVector(Note({ std::stoi(date.substr(0, 4)), std::stoi(date.substr(5, 2)), std::stoi(date.substr(8, 2)) },
                               { std::stoi(time.substr(0, 2)), std::stoi(time.substr(3, 2)) }, text, ++idGlobal, tag));
    }

    QSqlQuery query;
    QString clearQuery = "DELETE FROM entry;";
    query.exec(clearQuery);
    clearQuery = "DELETE FROM event";
    query.exec(clearQuery);
    clearQuery = "DELETE FROM note";
    query.exec(clearQuery);
    clearQuery = "DELETE FROM task";
    query.exec(clearQuery);


    db.close();
    outEntryVectorInMainWindow(EntryVector);
    outEventVectorInMainWindow(EventVector);
    outNoteVectorInMainWindow(NoteVector);
    outTaskVectorInMainWindow(TaskVector);
    std::cout << "connect with datadase clothe" << std::endl;


    return;
}

std::string MainWindow::enterDateTimeTextInString(const Date& date, const Time& time, const std::string& text){
    std::string answer;
    answer=answer+std::to_string(date.year) + ".";
    if (date.month / 10 == 0)
        answer += "0";
    answer=answer+std::to_string(date.month)+".";
    if (date.day / 10 == 0)
        answer += "0";
    answer= answer+ std::to_string(date.day) + " ";
    if (time.hour / 10 == 0)
        answer +="0";
    answer= answer+std::to_string(time.hour) + ":";
    if (time.minute / 10 == 0)
        answer += "0";
    answer= answer+ std::to_string(time.minute) + " ";
    if (text.size() / 10 == 0)
        answer += "0";
    answer= answer+ std::to_string(text.size()) + " ";
    answer+= text;
    return answer;
}

std::string MainWindow::enterDateTimeTextInString(const std::string& date, const std::string& time, const std::string& text){
    std::string answer;
    answer=date.substr(0, 4) + "." + date.substr(5, 2)+"." + date.substr(8, 2) + " " + time.substr(0, 2) + ":" +time.substr(3, 2) + " ";
    if (text.size() / 10 == 0)
        answer += "0";
    answer= answer+ std::to_string(text.size()) + " ";
    answer+= text;
    return answer;
}

bool MainWindow::searchElemForCancel(const Entry& other, const std::string& object){
    if (other.GetDate().year==std::stoi(object.substr(3, 4)) && other.GetDate().month==std::stoi(object.substr(8, 2)) && other.GetDate().day==std::stoi(object.substr(11, 2))
        && other.GetTime().hour==std::stoi(object.substr(14, 2)) && other.GetTime().minute==std::stoi(object.substr(17, 2)) && other.GetText()==object.substr(23, std::stoi(object.substr(20, 2))))
        return true;
    return false;
}

void MainWindow::on_cancelMove_clicked()
{
    try {
        std::string object = stackSaveMove.peek();
        stackSaveMove.pop();
        std::cout<<"\n"<<object<<"\n";
        switch(object[0]){
        case '1':                                  //Entry
            if(object[1]=='D'){
                enterEntryInVector(Entry({ std::stoi(object.substr(3, 4)), std::stoi(object.substr(8, 2)), std::stoi(object.substr(11, 2)) },
                                         { std::stoi(object.substr(14, 2)), std::stoi(object.substr(17, 2)) }, object.substr(23, std::stoi(object.substr(20, 2))), ++idGlobal));
                w->clearLayout(w->GetUi()->verticalLayout->findChild<QVBoxLayout*>("verticalLayout_Entry"));
                outEntryVectorInMainWindow(EntryVector);
                break;
            } else if(object[1]=='E'){
                for(size_t i=0; i!=EntryVector.size(); ++i){
                    if (EntryVector[i].GetDate().year==std::stoi(object.substr(23+std::stoi(object.substr(20, 2)), 4)) && EntryVector[i].GetDate().month==std::stoi(object.substr(28+std::stoi(object.substr(20, 2)), 2)) && EntryVector[i].GetDate().day==std::stoi(object.substr(31+std::stoi(object.substr(20, 2)), 2))
                        && EntryVector[i].GetTime().hour==std::stoi(object.substr(34+std::stoi(object.substr(20, 2)))) && EntryVector[i].GetTime().minute==std::stoi(object.substr(37+std::stoi(object.substr(20, 2)), 2)) && EntryVector[i].GetText()==object.substr(43+std::stoi(object.substr(20, 2)))){
                        EntryVector.erase(EntryVector.begin()+i);
                        enterEntryInVector(Entry({ std::stoi(object.substr(3, 4)), std::stoi(object.substr(8, 2)), std::stoi(object.substr(11, 2)) },
                                                 { std::stoi(object.substr(14, 2)), std::stoi(object.substr(17, 2)) }, object.substr(23, std::stoi(object.substr(20, 2))), ++idGlobal));
                        w->clearLayout(w->GetUi()->verticalLayout->findChild<QVBoxLayout*>("verticalLayout_Entry"));
                        outEntryVectorInMainWindow(EntryVector);
                        break;
                    }
                }
            } else if(object[1]=='C'){
                for(size_t i=0; i!=EntryVector.size(); ++i){
                    if(searchElemForCancel(EntryVector[i], object)){
                        EntryVector.erase(EntryVector.begin()+i);
                        w->clearLayout(w->GetUi()->verticalLayout->findChild<QVBoxLayout*>("verticalLayout_Entry"));
                        outEntryVectorInMainWindow(EntryVector);
                        break;
                    }
                }
            }
        case '2':                                 //Event
            if(object[1]=='D'){
                enterEventInVector(Event({ std::stoi(object.substr(3, 4)), std::stoi(object.substr(8, 2)), std::stoi(object.substr(11, 2)) },
                                         { std::stoi(object.substr(14, 2)), std::stoi(object.substr(17, 2)) }, object.substr(23, std::stoi(object.substr(20, 2))), ++idGlobal, object.substr(24+std::stoi(object.substr(20, 2)))));
                w->clearLayout(w->GetUi()->verticalLayout->findChild<QVBoxLayout*>("verticalLayout_Event"));
                outEventVectorInMainWindow(EventVector);
                break;
            } else if(object[1]=='C'){
                for(size_t i=0; i!=EventVector.size(); ++i){
                    if(searchElemForCancel(EventVector[i], object) && EventVector[i].GetPlace()==object.substr(24+std::stoi(object.substr(20, 2)))){
                        EventVector.erase(EventVector.begin()+i);
                        w->clearLayout(w->GetUi()->verticalLayout->findChild<QVBoxLayout*>("verticalLayout_Event"));
                        outEventVectorInMainWindow(EventVector);
                        break;
                    }
                }
            }
        case '3':                                  //Task
            if(object[1]=='D'){
                enterTaskInVector(Task({ std::stoi(object.substr(3, 4)), std::stoi(object.substr(8, 2)), std::stoi(object.substr(11, 2)) },
                                       { std::stoi(object.substr(14, 2)), std::stoi(object.substr(17, 2)) }, object.substr(23, std::stoi(object.substr(20, 2))), ++idGlobal));
                w->clearLayout(w->GetUi()->verticalLayout->findChild<QVBoxLayout*>("verticalLayout_Task"));
                outTaskVectorInMainWindow(TaskVector);
                break;
            }
            else if(object[1]=='C'){
                for(size_t i=0; i!=TaskVector.size(); ++i){
                    if(searchElemForCancel(TaskVector[i], object)){
                        TaskVector.erase(TaskVector.begin()+i);
                        w->clearLayout(w->GetUi()->verticalLayout->findChild<QVBoxLayout*>("verticalLayout_Task"));
                        outTaskVectorInMainWindow(TaskVector);
                        break;
                    }
                }
            }
        case '4':                                     //Note
            if(object[1]=='D'){
                enterNoteInVector(Note({ std::stoi(object.substr(3, 4)), std::stoi(object.substr(8, 2)), std::stoi(object.substr(11, 2)) },
                                       { std::stoi(object.substr(14, 2)), std::stoi(object.substr(17, 2)) }, object.substr(23, std::stoi(object.substr(20, 2))), ++idGlobal, object.substr(24+std::stoi(object.substr(20, 2)))));
                w->clearLayout(w->GetUi()->verticalLayout->findChild<QVBoxLayout*>("verticalLayout_Note"));
                outNoteVectorInMainWindow(NoteVector);
                break;
            } else if(object[1]=='C'){
                for(size_t i=0; i!=NoteVector.size(); ++i){
                    if(searchElemForCancel(NoteVector[i], object) && NoteVector[i].GetTag()==object.substr(24+std::stoi(object.substr(20, 2)))){
                        NoteVector.erase(NoteVector.begin()+i);
                        w->clearLayout(w->GetUi()->verticalLayout->findChild<QVBoxLayout*>("verticalLayout_Note"));
                        outNoteVectorInMainWindow(NoteVector);
                        break;
                    }
                }
            }
        }
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return;
}
