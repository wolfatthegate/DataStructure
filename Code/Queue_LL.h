//
// Created by KylinA1 on 2018/11/2.
//

#ifndef QUEUE_LL_QUEUE_LL_H
#define QUEUE_LL_QUEUE_LL_H

#include <iostream>
#include <cassert>
template<typename T>
class node{
public:
    T data;
    node<T> *next;

    node():next(nullptr){};
    node(const T& item):data(item),next(nullptr){};
};

template<typename T>
class Queue{
private:
    node<T> *front,*back;

public:
    Queue():front(nullptr),back(nullptr){};
    ~Queue(){
        node<T> *temp=front;
        while(front!= nullptr){
            delete temp;
            front=front->next;
            temp=front;
        }
    }
    Queue(const Queue<T>& actual){
        front= nullptr;
        node<T>* temp=actual.front;
        while(temp!= nullptr){
            if(front== nullptr){
                front=new node<T>(temp->data);
                back=front;
            }else{
                back->next=new node<T>(temp->data);
                back=back->next;
            }
            temp=temp->next;
        }
    }

    void swap(Queue<T>& actual){
        node<T>* temp=front;
        front=actual.front;
        actual.front=temp;

        temp=back;
        back=actual.back;
        actual.back=temp;
    }

    Queue<T>& operator=(Queue<T> rhs){
        swap(rhs);
        return *this;
    }

    void enqueue(const T& item){
        if(front== nullptr){
            front=new node<T>(item);
            back=front;
        }else{
            back->next=new node<T>(item);
            back=back->next;
        }
    }
    
    bool isEmpty(){ return(front== nullptr);}
    T dequeue(){
        assert(!isEmpty());
        T result=front->data;
        node<T>* temp=front;

        front=front->next;
        if(front== nullptr)// This is important
            back= nullptr;

        delete temp;
        return result;
    }

///////for test////////
    void print(){
        node<T> *temp=front;
        while(temp!= nullptr){
            std::cout<<temp->data<<' ';
            temp=temp->next;
        }
        std::cout<<std::endl;

    }
};

#endif //QUEUE_LL_QUEUE_LL_H
