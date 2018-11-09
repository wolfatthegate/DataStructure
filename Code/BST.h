//
// Created by KylinA1 on 2018/11/3.
//

#ifndef INC_2017F_BST_H
#define INC_2017F_BST_H

#include <iostream>

class node{
public:
    int data;
    node *left,*right;

    node():left(nullptr),right(nullptr){};
    node(int item):left(nullptr),right(nullptr),data(item){};
};

class BST{
private:
    node *m_root;
public:
    BST():m_root(nullptr){};

    BST(const BST& actual){m_root=copy(actual.m_root);};
    node* copy(node* root){
        if(root== nullptr)
            return nullptr;
        node* temp=new node(root->data);
        temp->left=copy(root->left);
        temp->right=copy(root->right);
        return temp;
    }

    ~BST(){destory(m_root);};
    void destory(node*& root){
        if(root!= nullptr){
            destory(root->left);
            destory(root->right);
            delete root;
        }
    }

    void insert(int item){assign(m_root,item);};
    void assign(node*& root,int item){
        if(root== nullptr){
            root=new node(item);
            return;
        }else{
            if(root->data<item)
                assign(root->right,item);
            else
                assign(root->left,item);
        }
    }





    void InPrint(){visit(m_root);};//Inorder print gives sorted 
    void visit(const node* root){
        if(root== nullptr)
            return;
        else{
            visit(root->left);
            std::cout<<root->data<<std::endl;
            visit(root->right);
        }
    }
};




#endif //INC_2017F_BST_H
