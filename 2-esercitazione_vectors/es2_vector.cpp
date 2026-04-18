#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n = 1;

    cout << "Quanti elementi vuoi inserire?" << endl;

    cin >> n;

    vector<double> v(n);

    for(int i = 0; i < v.size(); i++){
        cout << "Inserisci v[" << i << "]: ";
        cin >> v[i];
    }

    cout << "Il vettore ha " << v.size() << " elementi" << endl;

    for(int i = 0; i < v.size(); i++){
        cout << "v[" << i << "] vale " << v[i] << endl; 
    }

    int i = 0;
    double media = 0;
    while (i < v.size()){
        media = media + v[i];
        i++;
    }

    media = media / v.size();

    cout << "La media vale: " << media << endl;


    return 0;
}