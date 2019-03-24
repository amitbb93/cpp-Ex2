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
  
  
  /*threetree.deleteTree(threetree.getNode());
  emptytree.deleteTree(emptytree.getNode());
  mytree.deleteTree(mytree.getNode());
  mytree2.deleteTree(mytree2.getNode());*/

  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;

}