#include <iostream>
#include <cmath>

using namespace std;

int calcola_area(){
    int exitcode = 0;
    double lato = 0.0, area = 0.0;

    cout << "Calcolero' l'area. Inserisci il valore del lato del quadrato: " << endl;
    cin >> lato;
    area = lato*lato;
    cout << "L'area del quadrato vale: " << area << endl;

    return exitcode;
}

int calcola_lato(){
    int exitcode = 0;
    double lato = 0.0, area = 0.0;

    cout << "Inserisci il valore dell'area" << endl;
    cin >> area;
    if (area < 0) {
        cout << "Valore area non deve essere negativo." << endl;
        exitcode = 1;
    }
    else {
        lato = sqrt(area);
        cout << "Il lato vale: " << lato << endl;
    }

    return exitcode;
}

int main(){
    int exitcode = 0;
    string mode;
    double lato = 0.0, area = 0.0;

    cout << "Inserisci cosa vuoi calcolare: 'area' o 'lato'" << endl;
    cin >> mode;
    cout << "Valore inserito: '" << mode << "'" << endl;

    if (mode == "area"){
        exitcode = calcola_area();
    }

    else if(mode == "lato"){
        exitcode = calcola_lato();
    }

    else {
        cout << "Valore non valido: " << mode << endl;
        exitcode = 1;
    }

    cout << "Fine del main." << endl;

    return exitcode;

}