#include<iostream>
#include "Tree.hpp"
//https://www.cprogramming.com/tutorial/lesson18.html
//https://github.com/mdbaal/BinaryTree/blob/master/BinTree.cpp
//https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/
using std::cout, std::endl;
using namespace ariel;

/**
* Default Constructor
* \r is root
*/
node::node(){
	node* r = NULL;
	this->data=0;
    this->left = NULL;  
    this->right = NULL;
	size = 0;
}

/**
* Constructor gets a key and inserts it to the nodes data
* \r is root
*/
node::node(int key){
	node* r =NULL;
	this->data=key;	
    this->left = NULL;  
    this->right = NULL; 
	size = 0;
}

/**
* Tree Constructor connect to the root
*/	
ariel::Tree t;
Tree::Tree()
{
	this->r = new node();
}

/**
* This function inserts a new node for the tree.
* It calls "Search" & "insert1" functions
* \key is the data of the new node
* \*temp is a temporary node pointer
*/
void Tree::insert(int key){
	if((r!=NULL) && (this->r->size!=0)){
		node * temp = search(key, this->r);
		if(temp != NULL){
			return throw std::invalid_argument( "expception" );
		}
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

/**
* This function responsible for insert the new node which created at the "insert" function
* \r is the root
* \key is the data of the new node
*/
void Tree::insert1(int key, node *r)
{
	if(key< r->data)
	{
    if(r->left!=NULL)
     insert1(key, r->left);
    else
    {
      r->left=new node;
      r->left->data=key;
      r->left->left=NULL;    
      r->left->right=NULL;
    }  
  }
  else if(key>r->data)
  {
    if(r->right!=NULL)
      insert1(key, r->right);
    else
    {
      r->right=new node;
      r->right->data=key;
      r->right->left=NULL;  
      r->right->right=NULL; 
    }
  }
  else{
	  //throw std::invalid_argument("The number is already there");
  }
}

/**
* This function checks if the tree contains a certain key
* This functions also calls "Serach" function  
* \r is root
* \key is the data of the node 
* \return true if the tree contains the key
*/
bool Tree::contains(int key){
	if(this->r!=NULL){
		node * temp = search(key, this->r);
		if(temp!=NULL){
			return true;
		}
		else{
			return false;
		}	
	}
	else{
		return false;
	}
}	

/**
* This function searchs the tree for a certain node
* \key is a node that we are searching for
* \leaf is a node in the tree which we start the search from
* \return the node we searched for or NULL if does not exist
*/
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

/**
* This function returns the root data
* \r is root
* \return the data of the root
*/
int Tree::root(){
	if(this->r!=NULL)return this->r->data;
	else{ 	 
		throw std::invalid_argument( "expception" );	
		return NULL;
	}
}	

/**
* This function checks if the key is the root
* This function calls "Parent1" function
* \r is root
* \key is the data of the node which parent is needed to be returned at "Parent1" function
* \*p is the parent of the node we are searching for
* \return NULL if the node is the root (has no parent) 
*/
int Tree::parent(int key){
	if(this->r!=NULL){
		if (this->r->data==key){
			return NULL;
		}
	node *p = NULL;
	return parent1(key, this->r, p);
	}
	else{
		//throw std::invalid_argument( "expception" );
		return NULL;
	}
}

/**
* This function returns the parent of the node with the exact key
* \r is root
* \*leaf is "this" node
* \*p is the parent of the node we are searching for
* \return the parent 
*/
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

/**
* This function uses "Search" function to find the left node of the certain key
* \key is the nodes data
* \*temp is a temp node which needed for the search function
* \return the left node or NULL if does not exist and throw an exception
*/
int Tree::left(int key){
	node * temp = search(key, this->r);
	if (temp != NULL){
		if(temp->left != NULL)return temp->left->data;
		else{
			throw std::invalid_argument("NULL exception");
			return -1;	
		}
	}	
	else{
		throw std::invalid_argument( "expception" );
		return -1;
	}
}	

/**
* This function uses "Search" function to find the right node of the certain key
* \key is the nodes data
* \*temp is a temp node which needed for the search function
* \return the right node or NULL if does not exist and throw an exception
*/
int Tree::right(int key){
	node * temp = search(key, this->r);
	if(temp != NULL){
		if(temp->right != NULL)return temp->right->data;
		else{
			throw std::invalid_argument("NULL exception");
			return -1;	
		}
	}
	else{
		throw std::invalid_argument( "expception" );
		return -1;
	}
}	

/**
* This function uses "Print1" to print the tree
*/

void Tree::print(){ 
	print1(this->r);
    
}	

/**
* This function prints the tree in a coloum starting from the maximum, ends up in minimum key
* \*leaf is "this" node
*/
void Tree::print1(node * leaf){ 
    if (leaf != NULL) {  
		print1(leaf->right);   
		cout<<endl;  
		for (int i = 0; i < 1; i++)  
			cout<<" ";  
	 	cout<<leaf->data<<"\n";   
		print1(leaf->left);  
	}  
}

/**
* This function searches the specific key in the tree with "Search" function and than remove this node with "deleteNode" function
* \r is the root
* \key is the data of the node we wish to remove from the tree
* \*n is the node needed for the return from search function
*/
void Tree::remove(int key){
	if(this->r!=NULL){
		node* n = search(key, this->r);
		if(n != NULL){
			this-> r = deleteNode(this->r,key);
			if(this->r != NULL) this->r->size = this->r->size - 1;
		}
		else throw std::invalid_argument( "expception" );
	}
	else throw std::invalid_argument( "expception" );
}

/**
* This function responsiblefor deleting the node 
* \*root is the root of the tree
* \key is the data of the node we wish to remove
* \*temp,temp2,temp3 are temporary nodes
* \return the new root after the changes 
*/
node* Tree::deleteNode(node* root, int key) 
{ 
    if (root == NULL) 
        return root; 
    if (root->data > key) { 
        root->left = deleteNode(root->left, key); 
        return root; 
    } 
    else if (root->data < key) { 
        root->right = deleteNode(root->right, key); 
        return root; 
    } 
    if (root->left == NULL) { 
        node* temp = root->right; 
        delete root; 
        return temp; 
    } 
    else if (root->right == NULL) { 
        node* temp = root->left; 
        delete root; 
        return temp; 
    } 
    else { 
  
        node* temp2 = root->right; 
        node *temp3 = root->right; 
        while (temp3->left != NULL) { 
            temp2 = temp3; 
            temp3 = temp3->left; 
        } 
        temp2->left = temp3->right; 
        root->data = temp3->data; 
        delete temp3;          
        return root; 
    } 
}	

/**
* This function returns the size of the tree
* \return the size of the tree
*/	
int Tree::size(){
	if(this->r!=NULL)return this->r->size;
	else return 0;
}

void Tree::deleteTree(node* n)  
{  
	if (n != NULL){
		if(n->left != NULL) deleteTree(n->left);  
		if(n->right != NULL)deleteTree(n->right);  
		delete(n);
	}
	else return;	  
}

node* Tree::getNode(){
	if(this->r!=NULL)
		return this->r;
	else
		return NULL;
}