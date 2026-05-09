#include <iostream>
using namespace std;

int main() {
    int n = 1;
    int p = 1;

    cout << "Prime 16 potenze di 2:" << endl;

    while (n <= 16) {
        p = p * 2;
        cout << "2^" << n << " = " << p << endl;
        n++;
    }

    return 0;
}
