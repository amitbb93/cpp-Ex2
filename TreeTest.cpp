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

/*
ariel::Tree lihistree;  

  badkan::TestCase tc6("Binary tree");
  tc6
.CHECK_OK (lihistree.insert(5))
.CHECK_OK (lihistree.remove(5))
.CHECK_OK (lihistree.insert(5))
.CHECK_OK (lihistree.remove(5));
//lihistree.print();
	cout << "\nYou have " << tc6.right() << " right answers and " << tc6.wrong() << " wrong answers so your grade is " << tc6.grade() << ". Great!" << endl;
*/





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
	
}