#include <iostream>

using namespace std;

int main(){
    int num_planets = 9;
    double G = 6.674e-11;
    double c = 2.998e8;
    string myname = "1234";
    string yourname = "11";

    cout << "number of planets: " << num_planets << endl;
    cout << "G: " << G << endl;
    cout << "c: " << c << endl;
    cout << "My name is " << (myname + " " + yourname) << endl; 

    return 0;
}