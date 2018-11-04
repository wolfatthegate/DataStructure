//
// Created by KylinA1 on 2018/11/2.
//

#ifndef LEXICON_LEX_H
#define LEXICON_LEX_H



#include <iostream>
#include <string.h>




bool isReducible (std::string &word, const Lexicon &l){
    if (l.contains(word)){
        if(word.length()==1){
            std::cout<<word<<std::endl;
            return true;
        }
        else{
            int i=0;
            while(i<word.length()){
                std::string copy_word=word;
                copy_word.erase(i,1);
                if(isReducible(copy_word,l)){
                    std::cout<<word<<std::endl;
                    return true;
                }
                ++i;
            }
            return false;
        }
    }else{
        return false;
    }
}


/*------------ test code-------Not need to write the following part--


class Lexicon{
private:
    std::string m_str[7]={"c","a","t","s","cat","at","cats"};
public:
    bool contains (const std::string &str) const{
        int i=0;
        while(i<7){
            if (str==m_str[i])
                return true;
            i++;
        }
        return false;
    }
};

int main() {
    Lexicon l;
    std::string s1="cats";
    std::cout<<isReducible(s1,l)<<std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

 ------------------*/
#endif //LEXICON_LEX_H
