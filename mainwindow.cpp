#include "mainwindow.h"

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
    std::string date = { std::to_string(other.GetDate().year) + "." + std::to_string(other.GetDate().month) + "." + std::to_string(other.GetDate().day) };
    QLineEdit* lineDate = new QLineEdit(QString::fromStdString(date));
    std::string time = { std::to_string(other.GetTime().hour) + ":" + std::to_string(other.GetTime().minute) };
    QLineEdit* lineTime = new QLineEdit(QString::fromStdString(time));
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
    AddButtonDelete(newLayout);
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

    AddButtonDelete(newLayout);

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
    AddButtonDelete(newLayout);
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
    AddButtonDelete(newLayout);
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

void enterDateAndTimeInFile(const Entry& other,std::ofstream& objectsInFile){
    objectsInFile << std::to_string(other.GetDate().year) << ".";
    if (other.GetDate().month / 10 == 0)
        objectsInFile << "0";
    objectsInFile << std::to_string(other.GetDate().month) << ".";
    if (other.GetDate().day / 10 == 0)
        objectsInFile << "0";
    objectsInFile << std::to_string(other.GetDate().day) << " ";
    if (other.GetTime().hour / 10 == 0)
        objectsInFile << "0";
    objectsInFile << other.GetTime().hour << ":";
    if (other.GetTime().minute / 10 == 0)
        objectsInFile << "0";
    objectsInFile << other.GetTime().minute << " ";
}

void MainWindow::closeEvent(QCloseEvent* event) {
    std::ofstream objectsInFile;
    objectsInFile.open("data.txt");
    while (!EntryVector.empty()) {
        objectsInFile << "1: ";
        enterDateAndTimeInFile(EntryVector[0], objectsInFile);
        objectsInFile << EntryVector[0].GetText();
        objectsInFile << ";";
        EntryVector.erase(EntryVector.begin());
    }
    while (!TaskVector.empty()){
        objectsInFile << "2: ";
        enterDateAndTimeInFile(TaskVector[0], objectsInFile);
        objectsInFile << TaskVector[0].GetText();
        objectsInFile << ";";
        TaskVector.erase(TaskVector.begin());
    }
    while (!NoteVector.empty()) {
        objectsInFile << "3: ";
        enterDateAndTimeInFile(NoteVector[0], objectsInFile);
        if(NoteVector[0].GetText().size()/10==0)
            objectsInFile<<"0"<<NoteVector[0].GetText().size()<<" ";
        else objectsInFile<<NoteVector[0].GetText().size()<<" ";
        objectsInFile << NoteVector[0].GetText()<<" "<<NoteVector[0].GetTag();
        objectsInFile << ";";
        NoteVector.erase(NoteVector.begin());
    }
    while (!EventVector.empty()) {
        objectsInFile << "4: ";
        enterDateAndTimeInFile(EventVector[0], objectsInFile);
        if(EventVector[0].GetText().size()/10==0)
            objectsInFile<<"0"<<EventVector[0].GetText().size()<<" ";
        else objectsInFile<<EventVector[0].GetText().size()<<" ";
        objectsInFile << EventVector[0].GetText()<<" "<<EventVector[0].GetPlace();
        objectsInFile << ";";
        EventVector.erase(EventVector.begin());
    }
    objectsInFile.close();
}

void MainWindow::showEvent(QShowEvent* event) {
    std::ifstream objectsOutFile;
    objectsOutFile.open("data.txt");
    std::string object;
    while (std::getline(objectsOutFile, object, ';'))
    {
        switch (object[0]) {
        case '1':
            enterEntryInVector(Entry({ std::stoi(object.substr(3, 4)), std::stoi(object.substr(8, 2)), std::stoi(object.substr(11, 2)) },
                                     { std::stoi(object.substr(14, 2)), std::stoi(object.substr(17, 2)) }, object.substr(20), ++idGlobal));
            break;
        case '2':
            enterTaskInVector(Task({ std::stoi(object.substr(3, 4)), std::stoi(object.substr(8, 2)), std::stoi(object.substr(11, 2)) },
                                  { std::stoi(object.substr(14, 2)), std::stoi(object.substr(17, 2)) }, object.substr(20), ++idGlobal));
            break;
        case '3':
            enterNoteInVector(Note({ std::stoi(object.substr(3, 4)), std::stoi(object.substr(8, 2)), std::stoi(object.substr(11, 2)) },
                                   { std::stoi(object.substr(14, 2)), std::stoi(object.substr(17, 2)) }, object.substr(23, std::stoi(object.substr(20, 2))),
                                   ++idGlobal, object.substr(24+std::stoi(object.substr(20, 2)))));
            break;
        case '4':
            enterEventInVector(Event({ std::stoi(object.substr(3, 4)), std::stoi(object.substr(8, 2)), std::stoi(object.substr(11, 2)) },
                                   { std::stoi(object.substr(14, 2)), std::stoi(object.substr(17, 2)) }, object.substr(23, std::stoi(object.substr(20, 2))),
                                   ++idGlobal, object.substr(24+std::stoi(object.substr(20, 2)))));
            break;
        default:
            break;
        }
    }
    objectsOutFile.close();
    outEntryVectorInMainWindow(EntryVector);
    outEventVectorInMainWindow(EventVector);
    outNoteVectorInMainWindow(NoteVector);
    outTaskVectorInMainWindow(TaskVector);
}
