//
// Created by KylinA1 on 2018/11/4.
//

#ifndef INC_2016F_STACK_LL_H
#define INC_2016F_STACK_LL_H
#include<cassert>

template <typename T>
class node{
public:
    T data;
    node<T> *next;

    node():next(nullptr){};
    node(const T& item):data(item),next(nullptr){};
};

template <typename T>
class Stack{
private:
    node<T> *tos;
public:
    Stack():tos(nullptr){};
    ~Stack(){
        node<T>* temp;
        while(tos!= nullptr){
            temp=tos;
            delete temp;
            tos=tos->next;
        }
    }

    Stack(const Stack<T>& actual){
        tos= nullptr;
        node<T>* temp=actual.tos;
        node<T>* bottom;
        while(temp!=nullptr){
            if(tos== nullptr){
                tos=new node<T>(temp->data);
                bottom=tos;
            }else{
                bottom->next=new node<T>(temp->data);
                bottom=bottom->next;
            }
            temp=temp->next;
        }
    }

    void Swap(Stack<T>& rhs){
        node<T>* temp=tos;
        tos=rhs.tos;
        rhs.tos=temp;
    }

    Stack<T>& operator=(Stack<T> rhs){
        Swap(rhs);
        return *this;
    }

    void push(const T& item){
        node<T>* temp=new node<T>(item);
        temp->next=tos;
        tos=temp;
    }

    bool isEmpty(){return tos== nullptr;};
    T pop(){
        assert(!isEmpty());
        T result=tos->data;
        node<T>* temp=tos;
        tos=tos->next;
        delete temp;
        return result;
    }
};

#endif //INC_2016F_STACK_LL_H
