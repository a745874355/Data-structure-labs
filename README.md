# Data Structure Labs
This git repository contains my data structure works in college courses. 

## Lab 1 - Basic functions 
Lab 1 contains 3 functions: Factorial, Power and Fibonacci
The Factorial function takes a parameter n and calculates n!(n factorial), n! is calculating by multiplying every number bewteen 1 and n.
The Power function takes 2 parameters base and n, then calculates base^n.
The Fibonacci function takes a parameter n and calculates the nth fibonacci number in the fibonacii sequence.

## Lab 2 - Basic functions(Recursive)
In lab 1, Factorial, Power, Fibonacci functions are implemented using **loop**. In this lab, all of those functions are implemented **recusively**

## Lab 3 - Container - Linked List.

Linked list is a data structure that does not require sequential space in the memory. Linked list are composed of nodes that is in random space in the memory(leap), every node has at least the memory address of next node so that every node of the list can be accessed. 
Linked list has advantages on inserting or deleting nodes between elements in the container because it does not have to move all the elements after the inserting or deleting nodes. Instead, the linked list only modify the previous node's next_ pointer of inserting position to the new node, and the new node store the memory address to next_ pointer.
Linked list are not good at random access. Instead of array, that is able to easily find the memory address of an element using the offest memory address, linked list has to iterate from the begining or end node and iterate every node if a linked list needs to perform a random access.


In lab 3, two classes are coded: Doubly Linked List(Dlist) and Sentinel Linked List.

In Dlist, Every node has the reference to the previous node and the reference to the next node. **push_front(), push_back(), pop_front(), pop_back()** member functions are impletemed in the Dlist class.

Sentinel Linked List is the Linked list that contains Sentinel nodes that store no data at the begining and end of the linked list. Sentinel Linked List can simplify the implementation. Also, **push_front(), push_back(), pop_front(), pop_back()** member functions are implemeted in the Sentinal Linked List class 

## Lab 4 - Container - Iterators

Iterators are objects that allows programmer to iterate different type of data structres with out understanding the details of the implementation and memory layout of the data structore. 

Based on the Linked list that is implemented in Lab 3, Lab 4 adds iterator and const_iterator to the Linked List.
The following functions are implemented:

```C++
bool operator==(const_iterator rhs); // returns true if rhs and current object refer to the same node
bool operator!=(const_iterator rhs); // returns true if rhs and current object does not refer to the same node
iterator operator++();           //prefix ++
iterator operator++(int);        //postfix ++
const_iterator operator++();     //prefix ++
const_iterator operator++(int);  //postfix ++
iterator operator--();           //prefix --
iterator operator--(int);        //postfix --
const_iterator operator--();     //prefix --
const_iterator operator--(int);  //postfix --
const T& operator*() const;   // returns a const reference to data in the node referred to by the iterator
T& operator*();  // returns a reference to data in the node referred to by the iterator.
```

## Lab 5 - Algorithm - Quck Sort

Code finished, instruction under construction

## Lab 6 - Algorithm - Quck Sort Cont'd

Code finished, instruction under construction



