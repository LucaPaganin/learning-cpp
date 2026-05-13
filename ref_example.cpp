#include <iostream>

using namespace std;

void f(int pippo){
    cout << "&pippo = " << &pippo << endl;
    pippo = 1;
}

void g(int &pluto){
    cout << "&pluto = " << &pluto << endl;
    pluto = 1;
}

int main(int argc, char **argv){
    int a = 0;

    cout << "&a = " << &a << endl;
    cout << "a = " << a << endl;

    f(a);
    
    cout << "a = " << a << endl;
    
    g(a);

    cout << "a = " << a << endl;
    
    return 0;
}