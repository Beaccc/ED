#include <iostream>
#include "pila_max.h"

using namespace std;

int main(){

  Pila_max p;
  int i;

  p.Poner(5);
  
  for ( i=10; i>=0 ; i--) 
    p.Poner(i);
  
  p.Poner(7);
  
  while (!p.Vacia() ){
    elemento x = p.Tope();
    cout << x<<endl;
    p.Quitar();
  }     
  
  return 0;
}
