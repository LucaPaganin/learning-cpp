#include <iostream>
#include <string>

using namespace std;

int main() {
 string P1;
 string P2;
  cout << "inserisci la prima parola: " << endl;
  cin >> P1;
  cout << "inserisci la seconda parola: " << endl;
  cin >> P2;
 string Unita = P2 + P1;
 string P3 = Unita.substr(0,8);
  cout << "La terza parola è: " << P3 << endl;
  return 0;
}
