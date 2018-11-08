//
// Created by KylinA1 on 2018/11/7.
//

#ifndef ALL_INFIXTOPOST_H
#define ALL_INFIXTOPOST_H
#include<cassert>
#include <string.h>
const int SIZE=100;
template<typename T>
class stack{
private:
    T s[SIZE];
    int tos;
public:
    stack():tos(-1){};

    bool isEmpty(){return tos==-1;};
    bool isFull(){return tos>=SIZE-1;};

    void push(const T& item){
        assert(!isFull());
        s[++tos]=item;
    }

    T pop(){
        assert(!isEmpty());
        return s[tos--];
    }

    T top()const{
        assert(!isEmpty());
        return s[tos];
    }
};


std::string InfxToPostfix(std::string exp){
    stack<char> s;
    std::string result;
    char op;
    for(int i=0;i<exp.length();++i){
        if(isdigit(exp[i]))
            result+=exp[i];
        else{
            if(exp[i]==')'){
                op=s.pop();//operator
                s.pop();//'('
                result+=op;
            }else{
                s.push(exp[i]);
            }
        }
    }
    return result;
}

/*----test for exp-----

    char expr1[] = "(2*((3+7)-10))";
    std::string expr2 = "(16*((4+23)-7))";

    std::cout<<InfxToPostfix(expr1)<<std::endl;

*/



#endif //ALL_INFIXTOPOST_H
