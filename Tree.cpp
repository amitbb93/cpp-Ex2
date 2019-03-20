#include<iostream>
#include "Tree.hpp"
//https://www.cprogramming.com/tutorial/lesson18.html
//https://github.com/mdbaal/BinaryTree/blob/master/BinTree.cpp
//
using std::cout, std::endl;

using namespace ariel;

node::node(){
	node* r = NULL; 
    this->left = NULL;  
    this->right = NULL;
	size = 0;
}

node::node(int key){
	node* r =NULL;
	this->data=key;	
    this->left = NULL;  
    this->right = NULL; 
	size = 0;
}
	
ariel::Tree t;
Tree::Tree()
{
	this->r = new node();
}

void Tree::insert(int key){
	if(r!=NULL){
		insert1(key, this->r);
		this->r->size=this->r->size+1;
	}
	else
	{
		this->r = new node();
		this->r->data=key;
		this->r->left=NULL;
		this->r->right=NULL;
		this->r->size=this->r->size+1;
	}
}	

void Tree::insert1(int key, node *leaf)
{
  if(key< leaf->data)
  {
    if(leaf->left!=NULL)
     insert1(key, leaf->left);
    else
    {
      leaf->left=new node;
      leaf->left->data=key;
      leaf->left->left=NULL;    //Sets the left child of the child node to null
      leaf->left->right=NULL;   //Sets the right child of the child node to null
    }  
  }
  else if(key>leaf->data)
  {
    if(leaf->right!=NULL)
      insert1(key, leaf->right);
    else
    {
      leaf->right=new node;
      leaf->right->data=key;
      leaf->right->left=NULL;  //Sets the left child of the child node to null
      leaf->right->right=NULL; //Sets the right child of the child node to null
    }
  }
  else{
	  //throw std::invalid_argument("The number is already there");
  }
}

bool Tree::contains(int key){
	node * temp = search(key, this->r);
	if(temp!=NULL){
		return true;
	}
	else{
		return false;
	}	
}	

node *Tree::search(int key, node *leaf)
{
  if(leaf!=NULL)
  {
    if(key==leaf->data)
      return leaf;
    if(key<leaf->data)
      return search(key, leaf->left);
    else
      return search(key, leaf->right);
  }
  else return NULL;
}
int Tree::root(){
	if(this->r==NULL)return -1;	
	else return this->r->data;
}	
int Tree::parent(int key){
	return parent1(key, this->r, NULL);
}
int Tree::parent1(int key, node *leaf, node* p){
	if(leaf!=NULL)
	{
		if(key==leaf->data)
			return p->data;
		if(key<leaf->data){
			p=leaf;
			return parent1(key, leaf->left,p);
		}
		else{
			p=leaf;
			return parent1(key, leaf->right,p);
		}
	}
  else return -1;
}	
int Tree::left(int key){
	node * temp = search(key, this->r);
	if (temp != NULL){
		if(temp->left != NULL)return temp->left->data;
		else return -1;	
	}	
	else return -1;
}	
int Tree::right(int key){
	node * temp = search(key, this->r);
	if(temp != NULL){
		if(temp->right != NULL)return temp->right->data;
		else return -1;
	}
	else return -1;
}	
void Tree::print(){ 
	print1(this->r);
    
}	
void Tree::print1(node * leaf){ 
	// Base case  
    if (leaf != NULL) { 
		
		// Process right child first  
		print1(leaf->right);  
	  
		// Print current node after space  
		// count  
		cout<<endl;  
		for (int i = 0; i < 1; i++)  
			cout<<" ";  
		cout<<leaf->data<<"\n";  
	  
		// Process left child  
		print1(leaf->left);  
	}  
}
void Tree::remove(int key){
	node* n = search(key, this->r);
	if (n == NULL) return;
	node*	tempChildLeft = NULL;
	node* tempChildRight = NULL;
	if(n->left != NULL) tempChildLeft = n->left;
	if(n->right != NULL) tempChildRight = n->right;

	 if(n->data < n->parent->data){
		 n->parent->left = NULL;
	 }else if(n->data > n->parent->data){
		 n->parent->right = NULL;
	 }

	delete n;
	n = NULL;
	this->r->size=this->r->size-1;
}
	
int Tree::size(){
	return this->r->size;
}