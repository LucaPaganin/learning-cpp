#include <iostream>

using namespace std;

void null_dereference(){
    int *p = NULL;
    cout << *p << endl;

}

int main(){
    int n;

    cout << "Inserisci la dimensione dell'array che vuoi creare: ";
    cin >> n;
    cout << endl;

    int *arr = new int[n];
    for (int i = 0; i < 2*n; i++){
        cout << "Elemento numero " << i << ": " << arr[i] << endl;
    }
    
    for (int i = 0; i < 1000000; i++){
        cout << "Scrivo '1' su elemento numero " << i << endl;
        arr[i] = 1;
    }

    delete[] arr;

    // null_dereference();

    return 0;

}