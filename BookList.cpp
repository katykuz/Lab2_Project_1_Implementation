//
// Created by evken on 9/30/2022.
//

#include <iostream>
#include "BookList.h"
#include <string>
using namespace std;

//constructor
BookList::BookList(int cap) {
    list = new Book[cap];
    capacity = cap;
    numElements = 0;
}

//destructor
BookList::~BookList() { //when an object goes out of scope, the destructor is
    // called and the object is deleted (automatically)
    delete [] list;
}

//copy constructor
BookList::BookList(const BookList &obj) {
    // assign numElements and capacity (from obj)
    capacity = obj.capacity;
    numElements = obj.numElements;

    // allocate memory based on new capacity
    list = new Book[capacity];

    // copy over elements (from obj)
    for (int i = 0; i < numElements; i++)
        list[i] = obj.list[i];
}

//equals operator
BookList& BookList::operator=(const BookList &obj) {
    if (this != &obj) {     //checking if this has the same memory address as
        // &obj because they would be the same thing
        // deallocate memory
        delete [] list; //this refers to the list that is calling the operator
        //this is list1 in this case: list1 = list2

        // assign numElements and capacity (from obj)
        capacity = obj.capacity;
        //^^ refers to list1's capacity
        numElements = obj.numElements;

        // allocate memory based on new capacity
        list = new BookList[capacity];

        // copy over elements (from obj)
        for (int i = 0; i < numElements; i++)
            list[i] = obj.list[i];
    }
    //dereferencing the pointer this
    return *this;   //returns the contents of the pointer - which is an IntList
}

void BookList::add(Book el) {
    if (numElements >= capacity) //check if the array is full
        resize();               // resize doubles the size of the array
    list[numElements] = el;
    numElements++;              //increment the counter
}

int BookList::get(Book el) const {                //want to get a certain
    // element
    for (int i = 0; i < numElements; i++) {     //sort through entire array
        if (list[i] == el)                      //if element is found, return i
            return i;
    }
    return -1;                                  // if not found, return -1
}

bool BookList::empty() const {          //returns true if array is element
    return numElements == 0;
}

int BookList::size() const {         //returns number of elements ina rray
    return numElements;
}

//it is bad practice to have cout statements in the class, therefore use
// to_string
string BookList::to_string() const {         //ss accepts any time of data
    //type (similar to string builder in java)
    stringstream ss;
    for (int i = 0; i < numElements; i++)   //go through array
        ss << list[i] << " ";               //push into ss
    return ss.str();
}

void BookList::resize() {
    // update capacity
    capacity *= 2;              //doubles the value of capacity

    // create new array based on updated capacity
    int * tempArr = new int[capacity];  //creates a temporary array with new
    // capacity

    // copy old array values to new array
    for (int i = 0; i < numElements; i++)       //loop through the current array
        tempArr[i] = list[i];

    // delete old array
    delete [] list;

    // reassign old array to new array
    list = tempArr;
}