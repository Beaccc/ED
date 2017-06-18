#include <iostream>
#include "pila_max.h"

using namespace std;

int main(){

  Pila_max p;
  int i;

  for ( i=10; i>=0 ; i--) 
    p.Poner(i);
  
  while (!p.Vacia() ){
    elemento x = p.Tope();
    cout << x<<endl;
    p.Quitar();
  }     
  
  return 0;
}
