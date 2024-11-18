#ifndef ENTEREVENTWINDOW_H
#define ENTEREVENTWINDOW_H

#include <QDialog>

namespace Ui {
class EnterEventWindow;
}

class EnterEventWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EnterEventWindow(QWidget *parent = nullptr);
    ~EnterEventWindow();

private slots:
    void on_enterData_clicked();

private:
    Ui::EnterEventWindow *ui;
};

#endif // ENTEREVENTWINDOW_H
