#include "function.h"

bool checkTime(const std::string& time){
    for(char elem: time){
        if(elem==':')
            continue;
        if(elem>57 || elem <48)
            return false;
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

Time returnTime(const std::string& time){  //hh:mm
    return {std::stoi(time.substr(0, 2)), std::stoi(time.substr(3, 2))};
}

Date returnDate(const std::string& date){ //yyyy.mm.dd
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
    EntryVector.push_back(newEntry);
    std::sort(EntryVector.begin(), EntryVector.end(), searchPlaceElem);
}

void enterNoteInVector(const Note& newNote){
    NoteVector.push_back(newNote);
    std::sort(NoteVector.begin(), NoteVector.end(), searchPlaceElem);
}

void enterTaskInVector(const Task& newTask){
    TaskVector.push_back(newTask);
    std::sort(TaskVector.begin(), TaskVector.end(), searchPlaceElem);
}

void enterEventInVector(const Event& newEvent){
    EventVector.push_back(newEvent);
    std::sort(EventVector.begin(), EventVector.end(), searchPlaceElem);
}

bool searchPlaceElem(const Entry& other_1, const Entry& other_2) {
    // Сравниваем по году
    if (other_1.GetDate().year != other_2.GetDate().year) {
        return other_1.GetDate().year < other_2.GetDate().year;
    }

    // Если года одинаковые, сравниваем по месяцу
    if (other_1.GetDate().month != other_2.GetDate().month) {
        return other_1.GetDate().month < other_2.GetDate().month;
    }

    // Если месяц одинаковый, сравниваем по дню
    if (other_1.GetDate().day != other_2.GetDate().day) {
        return other_1.GetDate().day < other_2.GetDate().day;
    }

    // Если день одинаковый, сравниваем по часу
    if (other_1.GetTime().hour != other_2.GetTime().hour) {
        return other_1.GetTime().hour < other_2.GetTime().hour;
    }

    // Если час одинаковый, сравниваем по минутам
    return other_1.GetTime().minute < other_2.GetTime().minute;
}

