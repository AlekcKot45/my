#ifndef SEARCH_H
#define SEARCH_H

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLayout>
#include <QDialog>
#include "class.h"
#include "objects.h"

class Entry;

namespace Ui {
class search;
}

class search : public QDialog
{
    Q_OBJECT

public:
    explicit search(QWidget *parent = nullptr);
    void clearLayout(QLayout* layout);
    void addDateTimeTextSearchWindow(const Entry& other, QHBoxLayout* newLayout);
    ~search();

private slots:
    void on_search_2_clicked();

private:
    Ui::search *ui;
};

#endif // SEARCH_H
