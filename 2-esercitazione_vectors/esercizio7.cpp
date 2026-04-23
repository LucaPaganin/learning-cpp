#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string nomeFile;
    cout << "Inserire il file da leggere: ";
    cin >> nomeFile;

    ifstream file(nomeFile);
    if (!file.good()) {
        cerr << "Errore nella lettura del file: " << nomeFile << endl;
        return 1;
    }

    double somma = 0;
    int contatore = 0;
    double d, v;

    while (file >> d >> v) {
        double m = d * v;
        somma += m;
        contatore++;
    }
    file.close();

    cout << contatore << " coppie lette da file, la somma delle masse vale " << somma << " g" << endl;

    return 0;
}
