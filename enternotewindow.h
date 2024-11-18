#ifndef ENTERNOTEWINDOW_H
#define ENTERNOTEWINDOW_H

#include <QDialog>

namespace Ui {
class EnterNoteWindow;
}

class EnterNoteWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EnterNoteWindow(QWidget *parent = nullptr);
    ~EnterNoteWindow();

private slots:
    void on_enterData_2_clicked();

private:
    Ui::EnterNoteWindow *ui;
};

#endif // ENTERNOTEWINDOW_H
