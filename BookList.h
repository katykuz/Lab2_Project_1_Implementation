//
// Created by evken on 9/30/2022.
//

#ifndef LAB2_BOOKLIST_H
#define LAB2_BOOKLIST_H

#include <iostream>
#include "main.cpp"
#include <string>
using namespace std;


class BookList {
public:
    BookList(int);             // Constructor
    ~BookList();                // Destructor
    BookList(const BookList &);               // Copy constructor
    BookList& operator=(const BookList &);    // Overloaded = operator
    void add(Book);             // add element to array
    int get(Book) const;        // find element in array; return index
    // where found or -1 if not found
    bool empty() const;         // determines if list is empty or not
    int size() const;           // number of elements in array
    string to_string() const;   // returns string representation of
                                // the BookList class

private:
    Book * list;             // Pointer to the array
    int capacity;            // capacity of array
    int numElements;         // Number of elements
    void resize();           // resize array (when full)
};


#endif //LAB2_BOOKLIST_H
