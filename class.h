#ifndef CLASS_H
#define CLASS_H
#include <string>
#include <vector>
#include <iostream>
#include <iostream>
#include <memory>
#include "struct.h"
#include "objects.h"


#include <iostream>

class Entry{
protected:
    Date date;
    Time time;
    std::string text;
    int id=0;
public:
    Entry(Date d, Time t, const std::string& te, int i);
    Time GetTime() const;
    Date GetDate() const;
    std::string GetText() const;
    int GetId() const;
};

class Task:public Entry{
protected :
    bool completed=0;
public:
    Task(Date d, Time t, const std::string& te, int i);
    bool GetCompleted() const;
};

class Note: public Entry{
protected:
    std::string tag;
public:
    Note(Date d, Time t, const std::string& te, int i, const std::string& ta);
    std::string GetTag() const;
};

class Event: public Task{
private:
    std::string place;
public:
    Event(Date d, Time t, const std::string& te, int i, const std::string& p);
    std::string GetPlace() const;
};

class Exp{
private:
    std::string msg;
public:
    Exp(const std::string& msg);
    std::string GetMsg() const;
};

class ExpInputData:public Exp{
public:
    ExpInputData(const std::string& msg);
};

class ExpOpenFile:public Exp{
public:
    ExpOpenFile(const std::string& msg);
};

template <typename T>
class MyStack{
private:
    struct Node{
        T data;
        std::shared_ptr<Node> next;
        Node(const T& value): data(value), next(nullptr){};
    };
    std::shared_ptr<Node> topNode;
public:
    MyStack(): topNode(nullptr){}
    void push(const T& value){
        auto newNode= std::make_shared<Node>(value);
        newNode->next=topNode;
        topNode=newNode;
    }
    void pop(){
        if(isEmpty()){
            std::cout<<"Error";
            return;
        }
        topNode=topNode->next;
    }
    T peek() const {
        if (isEmpty()) {
            throw std::runtime_error("Stack is empty");
        }
        return topNode->data;
    }
    void print() const{
        auto current = topNode;
        while(current){
            std::cout<<current->data;
            current=current->next;
        }
        std::cout<<std::endl;
    }
    bool isEmpty() const{
        return topNode==nullptr;
    }
};

#endif // CLASS_H
