#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QHBoxLayout>
#include <QLayout>
#include <QShowEvent>
#include <QCloseEvent>
#include <fstream>
#include "objects.h"
#include "class.h"
#include "ui_mainwindow.h"
#include "enterentrywindow.h"
#include "entereventwindow.h"
#include "entertaskwindow.h"
#include "enternotewindow.h"

class Entry;
class Note;
class Event;
class Task;

QT_BEGIN_NAMESPACE

namespace Ui {
class MainWindow;
}

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void outOneEntry(const Entry& other);
    void outOneNote(const Note& other);
    void outOneTask(const Task& other);
    void outOneEvent(const Event& other);
    void clearLayout(QVBoxLayout* vLayout);
    void AddButtonDelete(QHBoxLayout* newLayout);
    void outDateTimeText(QHBoxLayout* newLayout, const Entry& other);
    void searchIdInVector(QHBoxLayout* newLayout);
    Ui::MainWindow* GetUi();

private slots:

    void on_enterEntry_clicked();

    void on_enterEvent_clicked();

    void on_enterTask_clicked();

    void on_enterNote_clicked();

protected:
    void showEvent(QShowEvent *event) override;
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
