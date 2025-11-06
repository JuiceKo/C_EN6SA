#ifndef MYCLASS_H
#define MYCLASS_H
#include <string>
using namespace std;

class MyClass {
private:
    string element;

public:
    MyClass();
    MyClass(string value);
    void print_my_element();
};

#endif
