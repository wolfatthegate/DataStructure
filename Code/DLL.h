//
// Created by KylinA1 on 2018/11/7.
//

#ifndef ALL_DLL_H
#define ALL_DLL_H

#include <iostream>
template<typename T>
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
    Itr(dnode<T>* ptr):current(ptr){};// not const

    Itr<T>& operator++(){
        current=current->next;
        return *this;
    }//pre
    Itr<T> operator++(int){
        Itr<T> result(current);
        current=current->next;
        return result;
    }//post

    dnode<T>* operator->(){
        return current;
    }

    const dnode<T>* operator->()const{
        return current;
    }

    bool operator==(const dnode<T>* ptr){return current==ptr;};
    bool operator!=(const dnode<T>* ptr){return current!=ptr;};


};

template<typename T>
class List{
private:
    dnode<T> * beginning,*ending;

public:
    List():beginning(nullptr),ending(nullptr){};
    ~List(){
        dnode<T> *temp=beginning;
        while(beginning!= nullptr){
            beginning=beginning->next;
            delete temp;
            temp=beginning;
        }
    }
    List(const List<T>& actual){
        dnode<T>* temp=actual.beginning;
        beginning= nullptr;
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

    void insertAfter(const T& item,Itr<T> ptr){
      if(beginning== nullptr){
          beginning=new dnode<T>(item);
          ending=beginning;
      }else{
          if(ptr==ending){
              ending->next=new dnode<T>(item);
              ending->next->prev=ending;
              ending=ending->next;
          }else{
              dnode<T>* temp=new dnode<T>(item);
              ptr->next->prev=temp;
              temp->next=ptr->next;
              ptr->next=temp;
              temp->prev=ptr.operator->();
          }
      }
    }

    void insertBefore(const T& item, Itr<T> ptr){
        if(beginning== nullptr){
            beginning=new dnode<T>(item);
            ending=beginning;
        }else{
            if(ptr==beginning){
                beginning->prev=new dnode<T>(item);
                beginning->prev->next=beginning;
                beginning=beginning->next;
            }else{
                dnode<T>* temp=new dnode<T>(item);
                ptr->prev->next=temp;
                temp->prev=ptr->prev;
                temp->next=ptr.operator->();
                ptr->prev=temp;
            }

        }
    }



    void remove(Itr<T> ptr){
        if(ptr==beginning){
            beginning=beginning->next;
        }else{
            ptr->prev->next=ptr->next;
        }

        if(ptr==ending){
            ending=ending->prev;
        }else{
            ptr->next->prev=ptr->prev;
        }
        delete ptr.operator->();
    }

    Itr<T> begin(){
        return Itr<T>(beginning);
    }

    const Itr<T> begin()const{
        return Itr<T>(beginning);
    }

    Itr<T> end(){
        return Itr<T>(ending);
    }
    const Itr<T> end()const{
        return Itr<T>(ending);
    }

   /////for test//////////
    void PrintList(){
        dnode<T>* temp=beginning;
        while(temp!= nullptr){
            std::cout<<temp->data<<" ";
            temp=temp->next;
        }
        std::cout<<std::endl;
    }
//////SOME OTHER FUNCTION////


    List<T>& operator=(List<T> rhs){
        swap(rhs);
        return *this;
    }

    void swap(List<T>& rhs){
        dnode<T>* temp=beginning;
        beginning=rhs.beginning;
        rhs.beginning=temp;

        temp=ending;
        ending=rhs.ending;
        rhs.ending=temp;
    }

    Itr<T> find(const T& key){
        Itr<T> pos(beginning);
        while(pos->data!=key)
            ++pos;
        return pos;
    }
};





#endif //ALL_DLL_H
