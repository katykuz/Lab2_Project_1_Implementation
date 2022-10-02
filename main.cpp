#include <iostream>
#include "BookList.h"
#include "BookList.cpp"
#include <string>
using namespace std;

struct Book {
    int ISBN;
    string author;
    string title;
    int year;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
