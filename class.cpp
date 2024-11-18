#include "class.h"

Entry::Entry(Date d, Time t, const std::string& te, int i):
    date(d),
    time(t),
    text(te),
    id(i){
}

Task::Task(Date d, Time t, const std::string &te, int i):
    Entry(d, t, te, i){
}

Note::Note( Date d, Time t, const std::string &te, int i, const std::string &ta):
    Entry(d, t, te, i),
    tag(ta){
}

Event::Event (Date d, Time t, const std::string &te, int i, const std::string &p):
    Task(d, t, te, i),
    place(p){
}

Time Entry::GetTime() const{
    return time;
}

Date Entry::GetDate() const{
    return date;
}

std::string Entry::GetText() const{
    return text;
}

int Entry::GetId() const{
    return id;
}

std::string Note::GetTag() const{
    return tag;
}

bool Task::GetCompleted() const{
    return completed;
}

std::string Event::GetPlace() const{
    return place;
}

Exp::Exp(const std::string& msg):msg(msg){}

std::string Exp::GetMsg() const{
    return msg;
}

ExpInputData::ExpInputData(const std::string& msg):Exp(msg){}

ExpOpenFile::ExpOpenFile(const std::string& msg):Exp(msg){}

