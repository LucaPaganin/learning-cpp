#include <iostream>

using namespace std;

void part1(){
    int a = 4;

    cout << "value of a is " << a << endl;
    cout << "memory address of a is " << &a << endl;

    int *p_a = &a;

    cout << "value of a retrieved by its pointer dereference: " << *p_a << endl;

    *p_a = 10;

    cout << "value of a after change through pointer " << a << endl; 
}

void part2(){
    int a = 2;
    int b = 3;
    int *pa = &a;
    int *pb = &b;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    cout << "&a = " << &a << endl;
    cout << "&b = " << &b << endl;

    cout << "pa = " << pa << endl;
    cout << "pb = " << pb << endl;

    *pb = *pa;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

}

int main() {
    
    part2();

    return 0;

}