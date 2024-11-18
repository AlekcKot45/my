#include "function.h"

bool checkTime(const std::string& time){
    for(char elem: time){
        if(elem==':')
            continue;
        if(elem>57 || elem <48)
            throw ExpInputData(time);      // return fause
    }
    if(time[2]!=':' || time.size()!=5)
        return false;
    if (std::stoi(time.substr(0, 2))<0 || std::stoi(time.substr(0, 2))>23 || std::stoi(time.substr(3, 2))<0 || std::stoi(time.substr(3, 2))>59)
        return false;
    return true;
}

bool checkDate(const std::string& date){
    for(char elem: date){
        if(elem=='.')
            continue;
        if(elem> 57 || elem<48)
            return false;
    }
    if(date[4]!='.' || date[7]!='.' || date.size()!=10)
        return false;
    if(std::stoi(date.substr(0, 4))<2024 || std::stoi(date.substr(0, 4))>2100 || std::stoi(date.substr(5, 2))<1 || std::stoi(date.substr(5, 2))>12 || std::stoi(date.substr(8, 2))<1 || std::stoi(date.substr(8, 2))>30){
        return false;
    }
    return true;
}

Time returnTime(const std::string& time){
    return {std::stoi(time.substr(0, 2)), std::stoi(time.substr(3, 2))};
}

Date returnDate(const std::string& date){
    return {std::stoi(date.substr(0, 4)), std::stoi(date.substr(5, 2)), std::stoi(date.substr(8, 2))};
}

void outEntryVectorInMainWindow(const std::vector<Entry>& vector){
    for(const Entry& elem:vector)
        w->outOneEntry(elem);
}

void outNoteVectorInMainWindow(const std::vector<Note>& vector){
    for(const Note& elem:vector)
        w->outOneNote(elem);
}

void outTaskVectorInMainWindow(const std::vector<Task>& vector){
    for(const Task& elem:vector)
        w->outOneTask(elem);
}

void outEventVectorInMainWindow(const std::vector<Event>& vector){
    for(const Event& elem:vector)
        w->outOneEvent(elem);
}

void enterEntryInVector(const Entry& newEntry){
    if(EntryVector.empty()){
        EntryVector.push_back(newEntry);
    } else{
        std::vector<Entry>::iterator iter=searchPlaceElemEntry(EntryVector.begin(), EntryVector.end(), newEntry);
        EntryVector.insert(iter, newEntry);
    }
}

void enterNoteInVector(const Note& newNote){
    if(NoteVector.empty()){
        NoteVector.push_back(newNote);
    } else{
        std::vector<Note>::iterator iter=searchPlaceElemNote(NoteVector.begin(), NoteVector.end(), newNote);
        NoteVector.insert(iter, newNote);
    }
}

void enterTaskInVector(const Task& newTask){
    if(TaskVector.empty()){
        TaskVector.push_back(newTask);
    } else{
        std::vector<Task>::iterator iter=searchPlaceElemTask(TaskVector.begin(), TaskVector.end(), newTask);
        TaskVector.insert(iter, newTask);
    }
}

void enterEventInVector(const Event& newEvent){
    if(EventVector.empty()){
        EventVector.push_back(newEvent);
    } else{
        std::vector<Event>::iterator iter=searchPlaceElemEvent(EventVector.begin(), EventVector.end(), newEvent);
        EventVector.insert(iter, newEvent);
    }
}

std::vector<Entry>::iterator searchPlaceElemEntry(std::vector<Entry>::iterator iter1, std::vector<Entry>::iterator iter2, const Entry& object) {
    // Поиск по годам
    while (iter1 != iter2 && object.GetDate().year > iter1->GetDate().year) {
        ++iter1;
    }

    // Если год совпадает, сравниваем месяцы
    if (iter1 != iter2 && object.GetDate().year == iter1->GetDate().year) {
        while (iter1 != iter2 && object.GetDate().month > iter1->GetDate().month) {
            ++iter1;
        }

        // Если месяц совпадает, сравниваем дни
        if (iter1 != iter2 && object.GetDate().month == iter1->GetDate().month) {
            while (iter1 != iter2 && object.GetDate().day > iter1->GetDate().day) {
                ++iter1;
            }

            // Если день совпадает, сравниваем часы
            if (iter1 != iter2 && object.GetDate().day == iter1->GetDate().day) {
                while (iter1 != iter2 && object.GetTime().hour > iter1->GetTime().hour) {
                    ++iter1;
                }

                // Если час совпадает, сравниваем минуты
                if (iter1 != iter2 && object.GetTime().hour == iter1->GetTime().hour) {
                    while (iter1 != iter2 && object.GetTime().minute > iter1->GetTime().minute) {
                        ++iter1;
                    }
                }
            }
        }
    }

    return iter1;
}
std::vector<Note>::iterator searchPlaceElemNote(std::vector<Note>::iterator iter1, std::vector<Note>::iterator iter2, const Note& object){
    // Поиск по годам
    while (iter1 != iter2 && object.GetDate().year > iter1->GetDate().year) {
        ++iter1;
    }

    // Если год совпадает, сравниваем месяцы
    if (iter1 != iter2 && object.GetDate().year == iter1->GetDate().year) {
        while (iter1 != iter2 && object.GetDate().month > iter1->GetDate().month) {
            ++iter1;
        }

        // Если месяц совпадает, сравниваем дни
        if (iter1 != iter2 && object.GetDate().month == iter1->GetDate().month) {
            while (iter1 != iter2 && object.GetDate().day > iter1->GetDate().day) {
                ++iter1;
            }

            // Если день совпадает, сравниваем часы
            if (iter1 != iter2 && object.GetDate().day == iter1->GetDate().day) {
                while (iter1 != iter2 && object.GetTime().hour > iter1->GetTime().hour) {
                    ++iter1;
                }

                // Если час совпадает, сравниваем минуты
                if (iter1 != iter2 && object.GetTime().hour == iter1->GetTime().hour) {
                    while (iter1 != iter2 && object.GetTime().minute > iter1->GetTime().minute) {
                        ++iter1;
                    }
                }
            }
        }
    }

    return iter1;
}
std::vector<Task>::iterator searchPlaceElemTask(std::vector<Task>::iterator iter1, std::vector<Task>::iterator iter2, const Task& object){
    // Поиск по годам
    while (iter1 != iter2 && object.GetDate().year > iter1->GetDate().year) {
        ++iter1;
    }

    // Если год совпадает, сравниваем месяцы
    if (iter1 != iter2 && object.GetDate().year == iter1->GetDate().year) {
        while (iter1 != iter2 && object.GetDate().month > iter1->GetDate().month) {
            ++iter1;
        }

        // Если месяц совпадает, сравниваем дни
        if (iter1 != iter2 && object.GetDate().month == iter1->GetDate().month) {
            while (iter1 != iter2 && object.GetDate().day > iter1->GetDate().day) {
                ++iter1;
            }

            // Если день совпадает, сравниваем часы
            if (iter1 != iter2 && object.GetDate().day == iter1->GetDate().day) {
                while (iter1 != iter2 && object.GetTime().hour > iter1->GetTime().hour) {
                    ++iter1;
                }

                // Если час совпадает, сравниваем минуты
                if (iter1 != iter2 && object.GetTime().hour == iter1->GetTime().hour) {
                    while (iter1 != iter2 && object.GetTime().minute > iter1->GetTime().minute) {
                        ++iter1;
                    }
                }
            }
        }
    }

    return iter1;
}
std::vector<Event>::iterator searchPlaceElemEvent(std::vector<Event>::iterator iter1, std::vector<Event>::iterator iter2, const Event& object){
    // Поиск по годам
    while (iter1 != iter2 && object.GetDate().year > iter1->GetDate().year) {
        ++iter1;
    }

    // Если год совпадает, сравниваем месяцы
    if (iter1 != iter2 && object.GetDate().year == iter1->GetDate().year) {
        while (iter1 != iter2 && object.GetDate().month > iter1->GetDate().month) {
            ++iter1;
        }

        // Если месяц совпадает, сравниваем дни
        if (iter1 != iter2 && object.GetDate().month == iter1->GetDate().month) {
            while (iter1 != iter2 && object.GetDate().day > iter1->GetDate().day) {
                ++iter1;
            }

            // Если день совпадает, сравниваем часы
            if (iter1 != iter2 && object.GetDate().day == iter1->GetDate().day) {
                while (iter1 != iter2 && object.GetTime().hour > iter1->GetTime().hour) {
                    ++iter1;
                }

                // Если час совпадает, сравниваем минуты
                if (iter1 != iter2 && object.GetTime().hour == iter1->GetTime().hour) {
                    while (iter1 != iter2 && object.GetTime().minute > iter1->GetTime().minute) {
                        ++iter1;
                    }
                }
            }
        }
    }

    return iter1;
}
