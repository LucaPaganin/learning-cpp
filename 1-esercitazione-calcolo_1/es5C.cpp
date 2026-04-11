#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int threshold = 12419; // threshold = soglia

    // cin >> threshold;

    int i;

    // versione con while
    i = 1;
    while (i*i < threshold) {
        i++;
    }

    // // versione con sqrt + ceil
    // double root = sqrt(threshold);
    // i = ceil(root);

    cout << "Il primo numero naturale con quadrato maggiore di " << threshold << " e' " << i << endl;

    return 0;
}
