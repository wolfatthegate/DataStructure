//
// Created by KylinA1 on 2018/11/5.
//

#ifndef INC_2017F_DLL_H
#define INC_2017F_DLL_H

#include <iostream>
template <typename T>
class dnode{
public:
    T data;
    dnode<T> *prev,*next;

    dnode():prev(nullptr),next(nullptr){};
    dnode(const T& item):data(item),prev(nullptr),next(nullptr){};
};

template<typename T>
class Itr{
private:
    dnode<T> *current;

public:
    Itr():current(nullptr){};
    Itr(dnode<T>* ptr):current(ptr){};

    Itr<T>& operator++(){current=current->next; return *this;}//pre
    Itr<T> operator++(int){
        Itr<T> result(current);
        current=current->next;
        return result;
    }
    Itr<T>& operator--(){current=current->prev; return *this;}//pre
    Itr<T> operator--(int){
        Itr<T> result(current);
        current=current->prev;
        return result;
    }

    dnode<T>* operator->(){
        return current;
    }

    const dnode<T>* operator->()const{return current;}

    bool operator==(dnode<T>* ptr){return current==ptr;};
    bool operator!=(dnode<T>* ptr){return current!=ptr;};
};

template<typename T>
class List{
private:
    dnode<T> *beginning,*ending;

public:
    List():beginning(nullptr),ending(nullptr){};
    ~List(){
        dnode<T> *temp;
        while(beginning!= nullptr){
            temp=beginning;
            beginning=beginning->next;
            delete temp;
        }
    }

    List(const List<T>& actual){
        beginning= nullptr;
        dnode<T>* temp=actual.beginning;
        while(temp!= nullptr){
            if(beginning== nullptr){
                beginning=new dnode<T>(temp->data);
                ending=beginning;
            }else{
                ending->next=new dnode<T>(temp->data);
                ending->next->prev=ending;
                ending=ending->next;
            }
            temp=temp->next;
        }
    }

    void insertAfter(const T& item, Itr<T> ptr){
        dnode<T>* temp=new dnode<T>(item);
        if(beginning== nullptr){
            beginning=temp;
            ending=temp;
        }else{
            temp->next=ptr->next;
            temp->prev=ptr.operator->();// return current;

            if(ptr == ending){
                ending->next=temp;
                ending=temp;
            }else{
                ptr->next->prev=temp;
                ptr->next=temp;
            }
        }
    }


    Itr<T> begin(){
        Itr<T> result(beginning);
        return result;
    }

    const Itr<T> begin()const{
        Itr<T> result(beginning);
        return result;
    }

    Itr<T> end(){
        Itr<T> result(ending);
        return result;
    }

    const Itr<T> end()const{
        Itr<T> result(ending);
        return result;
    }

    void remove(Itr<T> ptr) {
        if (ptr == beginning) {
            beginning = beginning->next;
        } else {
            ptr->prev->next = ptr->next;
        }


        if (ptr == ending) {
            ending = ending->prev;
        } else {
            ptr->next->prev = ptr->prev;
        }

        delete ptr.operator->();
    }

   // --- for test---//

    void Print(){
        dnode<T>* temp=beginning;
        while(temp!= nullptr){
            std::cout<< temp->data<<" ";
            temp=temp->next;
        }
        std::cout<<std::endl;
    }
};


#endif //INC_2017F_DLL_H
