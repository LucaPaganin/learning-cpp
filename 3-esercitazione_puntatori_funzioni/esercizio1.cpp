#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

double CalcolaDistanza(double x1, double y1, double x2, double y2) {
   double dx = x2 - x1;
   double dy = y2 - y1;
   return sqrt(dx*dx + dy*dy);
}

int main() {
   string fileName;
   cout << "Inserire il nome del file con le coordinate dei punti: ";
   cin >> fileName;
   
   ifstream file(fileName);

   int numEntries = 0;
   double x, y; // variabili temporanee per lettura coordinate da file
   while(file >> x >> y)
      numEntries++;
   
   // Sapendo quante coppie di punti sono contenute nel file, posso allocare dinamicamente
   // due array y e x di dimensioni adeguate e li riempio leggendo il file di nuovo
   double* x_array = new double[numEntries];
   double* y_array = new double[numEntries];   

   file.clear(); //resetto l'input streamer per errori e status End-Of-File
   file.seekg(ios_base::beg); //Muovo l'input streamer all'inzio del file
   for(int i=0; i<numEntries; i++){
     file >> x_array[i] >> y_array[i];
   }


   //Finalmente utilizzo la funzione per calcolare la distanza geometrica di due punti
   // per confrontare la distanza del primo punto, di contatore i==0, con tutti gli altri
   // di contatore i>=1 e i<numEntries

   double xD, yD; // coordinate del punto piu' distante dal punto iniziale
   double distanzaMassima = 0;
      
   for(int i=1; i<numEntries; i++){
      double distanza = CalcolaDistanza(x_array[i], y_array[i], x_array[0], y_array[0]);
      if(distanza > distanzaMassima) {
         xD = x_array[i];
         yD = y_array[i];
         distanzaMassima = distanza;
      }
   }

   cout << "Il punto piu' distante da P0(" << x_array[0] << ", " << y_array[0]
	<< ") ha coordinate (" << xD << ", " << yD
	<< ") e la distanza vale " << distanzaMassima << endl;

   delete[] x_array;
   delete[] y_array;   
   return 0;
}
