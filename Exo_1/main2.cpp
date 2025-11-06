#include <iostream>
#include <string>
using namespace std;

void printCustom(string message);

int main() {
    printCustom("Hello World !");
    return 0;
}

void printCustom(string message) {
    cout << endl << message;
}
