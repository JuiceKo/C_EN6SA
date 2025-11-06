#include <iostream>
#include "MyClass.h"
using namespace std;

MyClass::MyClass() {
    element = "test";
}

MyClass::MyClass(string value) {
    element = value;
}

void MyClass::print_my_element() {
    cout << endl << element;
}
