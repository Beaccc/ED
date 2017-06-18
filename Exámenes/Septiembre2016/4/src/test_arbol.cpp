#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <ctype.h>
#include <math.h>
#include "ArbolGeneral.h"

using namespace std;

int CalculaPotenciaExterna(ArbolGeneral<int> &arbol){
    ArbolGeneral<int>::iter_preorden it ;
    ArbolGeneral<int>::iter_preorden itaux ;
    int res = 0, potencia ;

    for(it=arbol.begin() ; it!=arbol.end() ; ++it){
        potencia = 0 ;
        if(it.Hoja()){
            itaux = it ;
            while(itaux.TienePadre()){
                potencia++ ;
                --itaux ;
            }
            res += pow(2, potencia) ;
        }
    }

    return res ;
}


int main(int argc, char * argv[]){

    ArbolGeneral<int> arbol(50) ;

    ArbolGeneral<int>::Nodo n = arbol.raiz() ;
    ArbolGeneral<int>::Nodo naux ;

    arbol.insertar_hijomasizquierda(n, 30) ;
    n = n->izqda ;

    arbol.insertar_hermanoderecha(n, 65) ;

    arbol.insertar_hijomasizquierda(n, 10) ;
    n = n->izqda ;

    arbol.insertar_hermanoderecha(n, 40) ;
    naux = n->drcha ;

    arbol.insertar_hijomasizquierda(naux, 34) ;
    naux = naux->izqda ;
    arbol.insertar_hermanoderecha(naux, 43) ;

    arbol.insertar_hijomasizquierda(n, 5) ;
    n = n->izqda ;

    arbol.insertar_hermanoderecha(n, 20) ;
    n = n->drcha ;

    arbol.insertar_hijomasizquierda(n,12) ;
    n = n->izqda ;

    arbol.insertar_hermanoderecha(n,23) ;




    cout << "Potencia Externa: " << CalculaPotenciaExterna(arbol) << endl ;
    ;
}  
