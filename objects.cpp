#include "objects.h"

std::vector<Entry> EntryVector;
std::vector<Note> NoteVector;
std::vector<Task> TaskVector;
std::vector<Event> EventVector;
MainWindow* w=nullptr;
int idGlobal=0;
MyStack<std::string> stackSaveMove;
