#include <iostream>
#include <string>
#include "MyClass.h"
using namespace std;

int main() {
    MyClass x1;               
    x1.print_my_element();

    MyClass x2("Hello World !");
    x2.print_my_element();

    return 0;
}
