#include <iostream>
#include <fstream>
#include <cstdlib>
#include "pila_maxmin.h"

using namespace std;

int main(int argc, char **argv){
    if (argc!=3){
        cout <<"Los parametros son: " << endl;
        cout <<"Conjunto1 " << endl;
        cout <<"Conjunto2 " << endl;
        return 0;
    }

    ifstream conjunto1(argv[1]);
    if (!conjunto1){
        cout<<"No se puede abrir el fichero "<<argv[1]<<endl;
        return 0;
    }

    ifstream conjunto2(argv[2]);
    if (!conjunto1){
        cout<<"No se puede abrir el fichero "<<argv[1]<<endl;
        return 0;
    }

    Pila_maxmin p1, p2 ;

    conjunto1 >> p1 ;
    conjunto2 >> p2 ;

    elemento el1 = p1.tope() ;
    elemento el2 = p2.tope() ;

//     cout << el1 << endl ;
//     cout << el2 << endl ;

    if(p1 > p2)
        cout << "El conjunto1 es mayor que el conjunto2 ya que el mínimo del primero ( " << el1.min << " )"
        << " es mayor que el máximo del segundo ( " << el2.max << " )" << endl ;
    else if(p2 > p1)
        cout << "El conjunto2 es mayor que el conjunto1 ya que el mínimo del segundo ( " << el2.min << " )"
        << " es mayor que el máximo del primero ( " << el1.max << " )" << endl ;
    else if(p1[p2])
        cout << "El conjunto1 tiene un rango de valores [" << el1.min << "," << el1.max << "]"
        << " que contiene a conjunto2 siendo éste [" << el2.min << "," << el2.max << "]" << endl ;
    else if(p2[p1])
        cout << "El conjunto2 tiene un rango de valores [" << el2.min << "," << el2.max << "]"
        << " que contiene a conjunto1 siendo éste [" << el1.min << "," << el1.max << "]" << endl ;
    else
        cout << "Los conjuntos son iguales " << endl ;

}
