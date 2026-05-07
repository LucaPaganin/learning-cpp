#include <iostream>
#include <string>

using namespace std;

class Particella {
// 1. STATO PRIVATO (Incapsulamento)
private: 
    string nome;
    double massa_MeV;

// 2. INTERFACCIA PUBBLICA
public: 
    // Costruttore con "Initializer List" (più efficiente dell'assegnazione nel corpo)
    Particella(string n, double m){
        this->nome = n;
        this->massa_MeV = m;
        cout << "Creata particella: " << nome << endl;
    }

    // Distruttore: chiamato automaticamente quando l'oggetto esce dallo scope
    ~Particella() {
        cout << "Distrutta particella: " << nome << endl;
    }

    // Metodi (Getters)
    // La keyword 'const' indica che questo metodo non modifica l'oggetto
    double getMassa() const {
        return massa_MeV;
    }

    string getNome() const {
        return nome;
    }
};

int main() {
    // Istanziazione sullo STACK (gestione automatica della memoria)
    Particella p1("Elettrone", 0.511);
    Particella p2("Protone", 938.27);

    cout << "Massa " << p1.getNome() << ": " << p1.getMassa() << " MeV" << endl;

    // Quando il main finisce, i distruttori di p1 e p2 vengono chiamati 
    // in ordine inverso di creazione (prima Protone, poi Elettrone).
    return 0; 
}
