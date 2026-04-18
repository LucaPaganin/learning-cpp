#include <iostream> 
using namespace std; 

int main(){ 
  const int n=3; 
  int v[n]; 

  for (int i=0;i<n;i++){ 
    cout << "Inserire v[" << i << "]: "; 
    cin >> v[i]; 
  }

  for (int i=0;i<n;i++){ 
    cout << "La componente " << i  << " del vettore v vale "  
         << v[i] << endl; 
  } 

  return 0; 
}