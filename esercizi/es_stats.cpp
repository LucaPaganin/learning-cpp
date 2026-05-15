#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/*
Scopo di questo codice e'
- leggere un file di dati con un numero decimale per riga
- salvarli in una struttura che li tenga tutti in memoria
- calcolarne:
    - media
    - varianza
    - deviazione standard
    - deviazione standard adattata
    - errore standard
*/

/*
Algoritmo somma
sum = 0                  prima del ciclo
sum = v[0]               dopo il primo passo   (i = 0)
sum = v[0] + v[1]        dopo il secondo passo (i = 1)
sum = v[0] + v[1] + v[2] dopo il terzo passo   (i = 2)
...
*/

double calcola_media(const vector<double> &v){
    double sum = 0;
    for(int i = 0; i < v.size(); i++){
        sum = sum + v[i];              // equivalentemente sum += v[i];
    }
    return sum / v.size();
}

int main(){
    string filename;

    cout << "Inserisci nome file: ";
    cin >> filename;

    ifstream file(filename);

    if (!file.good()){
        cout << "Impossibile aprire il file." << endl;
        return 1;
    }

    double x;
    vector<double> v;

    while (file >> x){
        v.push_back(x);
    }

    cout << "Letti " << v.size() << " elementi dal file " << filename << endl;

    double media = calcola_media(v);

    cout << "Media: " << media << endl;
    
    return 0;
}