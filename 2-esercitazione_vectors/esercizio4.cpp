#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int N = 10;
    vector<double> numeri(N);

    cout << "Inserisci " << N << " numeri reali:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Numero " << (i + 1) << ": ";
        cin >> numeri[i];
    }


    double minimo = numeri[0];
    double massimo = numeri[0];

    for (int i = 1; i < N; i++) {
        if (numeri[i] < minimo) {
            minimo = numeri[i];  
        }
        if (numeri[i] > massimo) {
            massimo = numeri[i];  
        }
    }

    cout << "\nValore minimo: " << minimo << endl;
    cout << "Valore massimo: " << massimo << endl;

    return 0;
}
