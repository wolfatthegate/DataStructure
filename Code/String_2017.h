//
// Created by KylinA1 on 2018/11/4.
//

#ifndef INC_2017S_STRING_H
#define INC_2017S_STRING_H

#include <iostream>

class String{
public:
    String(){
        str=new char[1];
        str[0]='\0';
        length=0;
    }
    String(const char * cstr){
        int i=0;
        while(cstr[i]!='\0'){
            ++i;
        }
        length=i;
        str=new char[length+1];
        int j=0;
        while(j<length){
            str[j]=cstr[j];
            ++j;
        }
        str[j]='\0';// this is important
    }

    String(const String& actual){
        length=actual.length;
        str=new char[length+1];
        int i=0;
        while(i<length){
            str[i]=actual.str[i];
            ++i;
        }
        str[i]='\0';//this is important
    }
    ~String(){
        
        delete[] str;
        length=0;
    }

    void Swap(String& rhs){
        int temp=length;
        length=rhs.length;
        rhs.length=temp;

        char *temp_str=str;
        str=rhs.str;
        rhs.str=temp_str;
    }

    String& operator=(String rhs){
        Swap(rhs);
        return *this;
    }

    String operator+(const String& rhs)const{
        int temp_length=length+rhs.length;
        String result;
        delete[] result.str;
        result.length=temp_length;
        result.str=new char[temp_length+1];
        int i=0;
        int j=0;
        while(i<length){
            result.str[i]=str[i];
            ++i;
        }
        while(j<rhs.length){
            result.str[i]=rhs.str[j];
            ++i;
            ++j;
        }
        result.str[i]='\0';// important
        return result;
    }

/////////for test/////

    void Print(){
        int i=0;
        while(str[i]!='\0'){
            std::cout<<str[i++];
            //++i;
        }
        std::cout<<std::endl;
    }

    int Length(){return length;};

private:
    char *str;
    int length;
};


#endif //INC_2017S_STRING_H
