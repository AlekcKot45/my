#ifndef ENTERTASKWINDOW_H
#define ENTERTASKWINDOW_H

#include <QDialog>

namespace Ui {
class EnterTaskWindow;
}

class EnterTaskWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EnterTaskWindow(QWidget *parent = nullptr);
    ~EnterTaskWindow();

private slots:
    void on_enterData_clicked();

private:
    Ui::EnterTaskWindow *ui;
};

#endif // ENTERTASKWINDOW_H
