/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using std::cout, std::endl;
#include "badkan.hpp"
#include "Tree.hpp"

int main() {
	/*
  ariel::Tree emptytree;
  ariel::Tree threetree;  
  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3); 

  badkan::TestCase tc("Binary tree");
  tc
  .CHECK_EQUAL (emptytree.size(), 0)
  .CHECK_OK    (emptytree.insert(5))
  .CHECK_EQUAL (emptytree.size(), 1)
  .CHECK_EQUAL (emptytree.contains(5), true)
  .CHECK_OK    (emptytree.remove(5))
  .CHECK_EQUAL (emptytree.contains(5), false)
  .CHECK_THROWS(emptytree.remove(5))
  .CHECK_EQUAL (emptytree.size() ,0)
  
  .CHECK_EQUAL (threetree.size(), 3)
  .CHECK_EQUAL (threetree.root(), 5)
  .CHECK_EQUAL (threetree.parent(3), 5)
  .CHECK_EQUAL (threetree.parent(7), 5)
  .CHECK_EQUAL (threetree.left(5), 3)
  .CHECK_EQUAL (threetree.right(5), 7)
  .CHECK_THROWS(threetree.insert(3))
  .CHECK_THROWS(threetree.left(6))
  .CHECK_OK    (threetree.print())
  .print();

//////////////////////////////////////////////////////////////////////////////////


ariel::Tree lihistree;  

  badkan::TestCase tc6("Binary tree");
  tc6
.CHECK_OK (lihistree.insert(70))
.CHECK_OK (lihistree.insert(60))
.CHECK_OK (lihistree.insert(40))
.CHECK_OK (lihistree.insert(30))
.CHECK_OK (lihistree.insert(20))
.CHECK_THROWS (lihistree.insert(70))
.CHECK_THROWS (lihistree.insert(60))
.CHECK_THROWS (lihistree.insert(40))
.CHECK_THROWS (lihistree.insert(30))
.CHECK_THROWS (lihistree.insert(20))
.CHECK_OK (lihistree.remove(20))
.CHECK_OK (lihistree.insert(5))
.CHECK_OK (lihistree.remove(5));
lihistree.print();
	cout << "\nYou have " << tc6.right() << " right answers and " << tc6.wrong() << " wrong answers so your grade is " << tc6.grade() << ". Great!" << endl;






	cout << "\nYou have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
  
  /////////////////////////////////
  
  ariel::Tree mytree;  
  mytree.insert(1);
  mytree.insert(0);
  mytree.insert(16);
  badkan::TestCase t1("Binary tree");
  t1
  .CHECK_EQUAL (mytree.size(), 3)
  .CHECK_EQUAL (mytree.root(), 1)
  .CHECK_EQUAL (mytree.parent(16), 1)
  .CHECK_EQUAL (mytree.parent(0), 1)
  .CHECK_EQUAL (mytree.left(1), 0)
  .CHECK_EQUAL (mytree.right(1), 16)
  .CHECK_THROWS(mytree.insert(16))
  .CHECK_THROWS(mytree.left(6))
  .CHECK_OK    (mytree.print())
  .print();
  
  
	cout << "\nYou have " << t1.right() << " right answers and " << t1.wrong() << " wrong answers so your grade is " << t1.grade() << ". Great!" << endl;
  
  /////////////////////////////////
  
  ariel::Tree mytree2;  
  mytree2.insert(0);
  mytree2.insert(-1);
  mytree2.insert(10);
  mytree2.insert(1);
  mytree2.insert(2);
  mytree2.insert(-2);
  badkan::TestCase t2("Binary tree");
  t2
  .CHECK_EQUAL (mytree2.size(), 6)
  .CHECK_EQUAL (mytree2.root(), 0)
  .CHECK_EQUAL (mytree2.parent(1), 10)
  .CHECK_EQUAL (mytree2.parent(0), NULL)
  .CHECK_EQUAL (mytree2.left(-1), -2)
  .CHECK_EQUAL (mytree2.right(1), 2)
  .CHECK_OK(mytree2.insert(12))
  .CHECK_EQUAL (mytree2.size(), 7)
  .CHECK_THROWS(mytree2.left(-4))
  .CHECK_THROWS(mytree2.remove(3))
  .CHECK_OK    (mytree2.print())
  .print();
  
  
	cout << "\nYou have " << t2.right() << " right answers and " << t2.wrong() << " wrong answers so your grade is " << t2.grade() << ". Great!" << endl;
  
  ////////////////////////////////////
  
    ariel::Tree mytree3;  
	badkan::TestCase t3("Binary tree");
	int n=1;
	for(int i=1;i<=100;i++){
		
		t3
		.CHECK_OK(mytree3.insert(i))
		.CHECK_EQUAL (mytree3.size(), n)
		.CHECK_EQUAL (mytree3.root(), 1);
		n++;
	}
	n--;
	for(int i=1;i<=50;i++){
		n--;
		t3
		.CHECK_THROWS(mytree3.insert(i))
		.CHECK_EQUAL (mytree3.contains(i), true)
		.CHECK_EQUAL (mytree3.contains(i+1000), false)
		.CHECK_THROWS(mytree3.remove(i+1000))
		.CHECK_OK(mytree3.remove(i))
		.CHECK_EQUAL (mytree3.size(), n);
		
	}
	mytree3.print();

	for(int i=51;i<=100;i++){
		n--;
		t3
		.CHECK_OK(mytree3.remove(i))
		.CHECK_EQUAL (mytree3.size(), n);
	}
	
	
	cout << "\nYou have " << t3.right() << " right answers and " << t3.wrong() << " wrong answers so your grade is " << t3.grade() << ". Great!" << endl;
	*/
	/////////////////////////////////////////////////////
	
	ariel::Tree emptytree;
  ariel::Tree threetree;
  ariel::Tree seventree;
  ariel::Tree fourrighttree;  //diagonal line
  ariel::Tree fourlefttree;   //diagonal line
  ariel::Tree ninetree;
 
  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);
  
  seventree.insert(50);
  seventree.insert(30);
  seventree.insert(70);
  seventree.insert(20);
  seventree.insert(40);
  seventree.insert(60);
  seventree.insert(80);

  fourrighttree.insert(22);
  fourrighttree.insert(35);
  fourrighttree.insert(44);
  fourrighttree.insert(59);

  fourlefttree.insert(22);
  fourlefttree.insert(15);
  fourlefttree.insert(9);
  fourlefttree.insert(3);


  badkan::TestCase tc("Binary tree");
  tc
  .CHECK_EQUAL (emptytree.size(), 0) 
  .CHECK_OK    (emptytree.insert(5)) 
  .CHECK_EQUAL (emptytree.size(), 1) 
  .CHECK_EQUAL (emptytree.contains(5), true)
  .CHECK_OK    (emptytree.remove(5))
  .CHECK_THROWS(emptytree.remove(5))
  .CHECK_EQUAL (emptytree.size() ,0)
  

  .CHECK_EQUAL (threetree.size(), 3)
  .CHECK_EQUAL (threetree.root(), 5)
  .CHECK_EQUAL (threetree.parent(3), 5)
  .CHECK_EQUAL (threetree.parent(7), 5)
  .CHECK_EQUAL (threetree.left(5), 3)
  .CHECK_EQUAL (threetree.right(5), 7)
  .CHECK_THROWS(threetree.insert(3))
  .CHECK_OK    (threetree.print())

   .CHECK_EQUAL (seventree.size(),7)
   .CHECK_EQUAL (seventree.root(),50)
   .CHECK_EQUAL (seventree.contains(60),true)
   .CHECK_OK    (seventree.remove(80))
   .CHECK_THROWS(seventree.remove(80))
   .CHECK_THROWS (seventree.right(70))   
  .CHECK_EQUAL (seventree.parent(40),30)
  .CHECK_EQUAL (seventree.parent(60),70)
  .CHECK_THROWS(seventree.parent(50))
  .CHECK_THROWS (seventree.left(20))  
  .CHECK_EQUAL (seventree.left(50),30)
  .CHECK_OK    (seventree.remove(50))
  .CHECK_OK    (seventree.print())
  .CHECK_EQUAL (seventree.root(),60) 
  .CHECK_EQUAL (seventree.parent(70),60)
  .CHECK_THROWS(seventree.insert(40))   
  .CHECK_EQUAL (seventree.size(),5)
  .CHECK_OK    (seventree.print())

  .CHECK_EQUAL (fourrighttree.size(),4)
  .CHECK_EQUAL (fourrighttree.root(),22)
  .CHECK_EQUAL (fourrighttree.contains(44),true)
  .CHECK_EQUAL (fourrighttree.right(44),59)
  .CHECK_OK    (fourrighttree.remove(59))
  .CHECK_THROWS (fourrighttree.right(44))
  .CHECK_THROWS(fourrighttree.remove(59))
  .CHECK_EQUAL (fourrighttree.parent(35),22)
  .CHECK_THROWS(fourrighttree.parent(22))
  .CHECK_THROWS(fourrighttree.remove(29))  
  .CHECK_THROWS (fourrighttree.left(35))   
  .CHECK_OK     (fourrighttree.remove(22))
  .CHECK_OK(fourrighttree.print())
  .CHECK_EQUAL (fourrighttree.root(),35)
  .CHECK_EQUAL (fourrighttree.size(),2)
  .CHECK_OK    (fourrighttree.print())
  

  .CHECK_EQUAL (fourlefttree.size(),4)
  .CHECK_EQUAL (fourlefttree.root(),22)
  .CHECK_EQUAL (fourlefttree.contains(3),true)
  .CHECK_EQUAL (fourlefttree.left(15),9)
  .CHECK_OK    (fourlefttree.remove(9))
  .CHECK_EQUAL (fourlefttree.left(15),3)
  .CHECK_THROWS(fourlefttree.remove(9))
  .CHECK_EQUAL (fourlefttree.parent(3),15)
  .CHECK_THROWS(fourlefttree.parent(22))
  .CHECK_THROWS(fourlefttree.remove(73))  
  .CHECK_THROWS (fourlefttree.right(3))   
    .CHECK_OK  (fourlefttree.print())
  .CHECK_OK(fourlefttree.remove(22))
   .CHECK_OK  (fourlefttree.print())
  .CHECK_EQUAL (fourlefttree.root(),15)
    .CHECK_OK  (fourlefttree.print())
  .CHECK_EQUAL (fourlefttree.size(),2)
  .CHECK_OK    (fourlefttree.print())


  .CHECK_THROWS (ninetree.root())
  .CHECK_EQUAL (ninetree.size(),0)
  .CHECK_OK    (ninetree.insert(3))
  .CHECK_OK    (ninetree.insert(1))
  .CHECK_OK    (ninetree.insert(10))
  .CHECK_EQUAL (ninetree.contains(3),true)
  .CHECK_OK    (ninetree.insert(5))
  .CHECK_OK    (ninetree.insert(4))
  .CHECK_OK    (ninetree.insert(7))
  .CHECK_OK    (ninetree.insert(16))
  .CHECK_OK    (ninetree.insert(15))
  .CHECK_OK    (ninetree.insert(20))
  .CHECK_EQUAL (ninetree.root(),3)
  .CHECK_EQUAL (ninetree.parent(1),3)
   .CHECK_OK    (ninetree.remove(3))
  .CHECK_EQUAL (ninetree.contains(3),false)
  .CHECK_EQUAL (ninetree.root(),4)  
    .CHECK_OK    (ninetree.print())
  .CHECK_EQUAL (ninetree.parent(1),4) 
  .CHECK_EQUAL (ninetree.parent(16),10)
  .CHECK_EQUAL (ninetree.right(5),7)
  .CHECK_OK    (ninetree.remove(10))
  .CHECK_EQUAL (ninetree.size(),7)
  .CHECK_EQUAL (ninetree.parent(16),15)
  .CHECK_THROWS (ninetree.left(16)) 
  .CHECK_OK    (ninetree.remove(1))
  .CHECK_EQUAL (ninetree.root(),4) 
  .CHECK_EQUAL (ninetree.contains(30),false)
  .CHECK_THROWS(ninetree.remove(3))
  .CHECK_THROWS (ninetree.left(5)) 
  .CHECK_OK    (ninetree.remove(4))
  .CHECK_THROWS (ninetree.left(5))
  .CHECK_EQUAL (ninetree.size(),5)
  .CHECK_OK    (ninetree.print()) 
  
  
  .print();
  
  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
	
	
	
	
	
	
	
}