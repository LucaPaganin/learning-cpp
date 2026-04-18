#include <iostream>
using namespace std;

int main() {
    int p = 1;

    cout << "Prime 16 potenze di 2:" << endl;

    for (int n = 1; n <= 16; n++) {
        p = p * 2;
        cout << "2^" << n << " = " << p << endl;
    }

    return 0;
}
