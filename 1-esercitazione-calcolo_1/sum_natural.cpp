#include <iostream>

using namespace std;

int main(){
    int n = 0;
    cout << "Inserisci n: " << endl;
    cin >> n;

    int sum = 0;
    for (int i = 1; i <= n; i++){
        sum = sum + i;
        cout << "Passo " << i << " la somma fino a qui e': " << sum << endl;
        // sum += i;  equivalente a quello sopra
    }

    // versione in linea
    // for (int i = 1; i <= n; i++) sum += i;
    
        
    cout << "Somma fino a n = " << n << " e' uguale a " << sum << endl;

    return 0;
}