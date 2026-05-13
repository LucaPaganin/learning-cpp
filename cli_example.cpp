#include <iostream>

using namespace std;

int main(int argc, char **argv){

    cout << "Ciao, mi hai passato " << argc << " parametri da riga di comando." << endl;

    for (int i = 0; i < argc; i++){
        cout << "argv[" << i << "] = " << argv[i] << endl;
    }

    return 0;
}