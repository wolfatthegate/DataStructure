//
// Created by KylinA1 on 2018/11/8.
//

#ifndef ALL_STRING_2016_H
#define ALL_STRING_2016_H

#include <iostream>
const int SIZE=128;

class string{
private:
    int length;
    int capacity;
    char* str;

public:
    string(){
        length=0;
        capacity=SIZE;
        str=new char[SIZE+1];
        str[0]='\0';
    }

    string(const int x){
        length=0;
        capacity=x;
        str=new char[x+1];
        str[0]='\0';
    }
    int Length()const{return length;};
    int Capacity()const{return capacity;};

    string(const char* cstr){
        int i=0;
        while(cstr[i]!='\0'){
            ++i;
        }
        length=i;
        str=new char[length+1];
        capacity=length;
        int j=0;
        while(j<length){
            str[j]=cstr[j];
            ++j;
        }
        str[j]='\0';
    }

    string(const string& actual){
        length=actual.length;
        capacity=actual.capacity;
        str=new char[capacity+1];
        int i=0;
        while(i<length){
            str[i]=actual.str[i];
            ++i;
        }
        str[i]='\0';
    }

    ~string(){
        delete[] str;
        length=0;
        capacity=0;
    }

    void Swap(string& rhs){
        int temp_length=length;
        length=rhs.length;
        rhs.length=temp_length;

        int temp_capacity=capacity;
        capacity=rhs.capacity;
        rhs.capacity=temp_capacity;

        char* temp_str=str;
        str=rhs.str;
        rhs.str=temp_str;
    }

    string& operator=(string rhs){
        Swap(rhs);
        return *this;
    }

    string operator+(const string & rhs)const{
        int temp_length=length+rhs.length;
        string result(temp_length+1);
        result.length=temp_length;
        int i=0;
        int j=0;
        while(i<length){
            result.str[i]=str[i];
            ++i;
        }
        while(j<rhs.length){
            result.str[i]=str[j];
            ++i;
            ++j;
        }
        result.str[i]='\0';

        return result;
    }

    void Print(){
        int i=0;
        while(str[i]!='\0'){
            std::cout<<str[i];
            ++i;
        }
        std::cout<<std::endl;
    }
};
#endif //ALL_STRING_2016_H
