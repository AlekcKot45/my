#ifndef OBJECTS_H
#define OBJECTS_H
#include "class.h"
#include "mainwindow.h"
#include <string>
#include <vector>
#include <QStack>

class MainWindow;

extern std::vector<Entry> EntryVector;
extern std::vector<Note> NoteVector;
extern std::vector<Task> TaskVector;
extern std::vector<Event> EventVector;
extern MainWindow* w;
extern int idGlobal;
extern QStack<std::string> stackSaveMove;

#endif // OBJECTS_H
