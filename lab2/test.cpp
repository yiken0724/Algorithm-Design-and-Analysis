#include <iostream>
using namespace std;

int main() {
    string firstName = "Choo";
    string *ptr = &firstName;

    cout << firstName << "\n";
    cout << ptr << "\n"; 
    cout << &firstName << "\n"; //address of firstName
    cout << &ptr << "\n"; //address of pointer
    cout << *ptr << "\n"; //dereferencing pointer
}