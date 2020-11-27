// 
// Created by WolfAtTheGate on 11/26/2020
// https://github.com/wolfatthegate


#include <iostream>

class node{
public: 
	node *left, *middle, *right; 
	int key; 

	node(){
		left = middle = right = nullptr; 
	}

	node(int item){
		key = item; 
		left = middle = right = nullptr; 
	}
}

class ternary{
private: 

	node *m_root;

public: 

	ternary(){
		m_root = nullptr; 
	}

	ternary(const ternary& actual){
		m_root = copy(actual.m_root);
	}

	node* copy(node* root){
		if(root==nullptr)
			return nullptr;
		
		node *temp   = new node(root->key); 
		temp->left   = copy(root->left); 
		temp->middle = copy(root->middle); 
		temp->right  = copy(root->right); 
		return temp; 
	}

	~ternary(){
		destory(m_root); 
	}

	void destory(node*& root){
		if(root!=nullptr){
			destory(root->left);
			destory(root->middle); 
			destory(root->right);
			delete root; 
		}
	}

	void PreOrder(){
		visitPreOrder(m_root); 
	}

	void visitPreOrder(const node* root){
		if (root == nullptr) {
        	return;
    	}
    	std::cout<< root->key << " ";
    	visitPreOrder(root->left);
    	visitPreOrder(root->middle);
    	visitPreOrder(root->right);
    	std::cout<<std::endl; 
	}

	void InOrder(){
		visitInOrder(m_root); 
	}

	void visitInOrder(const node* root){
		if (root == nullptr){
			return; 
		}
		visitInOrder(root->left); 
		std::cout<<root->key<< " "; 
		visitInOrder(root->middle); 
		visitInOrder(root->right); 
		std::cout<<std::endl; 
	}
}

















