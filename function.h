#ifndef FUNCTION_H
#define FUNCTION_H
#include <string>
#include <QHBoxLayout>
#include <QWidget>
#include "struct.h"
#include "class.h"
#include "mainwindow.h"
#include "objects.h"

class Entry;
class Note;
class Event;
class Task;

void outEntryVectorInMainWindow(const std::vector<Entry>& vector);
void outNoteVectorInMainWindow(const std::vector<Note>& vector);
void outTaskVectorInMainWindow(const std::vector<Task>& vector);
void outEventVectorInMainWindow(const std::vector<Event>& vector);
bool checkTime(const std::string& time);
bool checkDate(const std::string& date);
Time returnTime(const std::string& time);
Date returnDate(const std::string& date);
void outNewObjectInMainWindowEntry(const Entry& object);
void outNewObjectInMainWindowNote(const Note& object);
void outNewObjectInMainWindowTask(const Task& object);
void outNewObjectInMainWindowEvent(const Event& object);
void enterEntryInVector(const Entry& newEntry);
void enterNoteInVector(const Note& newNote);
void enterTaskInVector(const Task& newTask);
void enterEventInVector(const Event& newEvent);
std::vector<Entry>::iterator searchPlaceElemEntry(std::vector<Entry>::iterator iter1, std::vector<Entry>::iterator iter2, const Entry& object);
std::vector<Note>::iterator searchPlaceElemNote(std::vector<Note>::iterator iter1, std::vector<Note>::iterator iter2, const Note& object);
std::vector<Task>::iterator searchPlaceElemTask(std::vector<Task>::iterator iter1, std::vector<Task>::iterator iter2, const Task& object);
std::vector<Event>::iterator searchPlaceElemEvent(std::vector<Event>::iterator iter1, std::vector<Event>::iterator iter2, const Event& object);
void outNoteVectorInMainWindow();

#endif // FUNCTION_H
