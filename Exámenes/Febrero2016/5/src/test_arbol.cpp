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


// Returns true if trees with roots as root1 and root2 are mirror
bool isMirror(ArbolGeneral<int>::Nodo root1,ArbolGeneral<int>::Nodo root2)
{
    // If both trees are emptu, then they are mirror images
    if (root1 == NULL && root2 == NULL)
        return true;

    // For two trees to be mirror images, the following three
    // conditions must be true
    // 1 - Their root node's key must be same
    // 2 - left subtree of left tree and right subtree
    //      of right tree have to be mirror images
    // 3 - right subtree of left tree and left subtree
    //      of right tree have to be mirror images
    if (root1 && root2 && root1->etiqueta == root2->etiqueta)
        return isMirror(root1->izqda, root2->drcha) &&
               isMirror(root1->drcha, root2->izqda);

    // if neither of above conditions is true then root1
    // and root2 are not mirror images
    return false;
}


int main(int argc, char * argv[]){

    ArbolGeneral<int> arbol(5) ;

    ArbolGeneral<int>::Nodo n = arbol.raiz() ;
    ArbolGeneral<int>::Nodo naux ;

    arbol.insertar_hijomasizquierda(n, 3) ;
    arbol.insertar_hermanoderecha(n, 8) ;
    naux = n->drcha ;
    n = n->izqda ;


    arbol.insertar_hijomasizquierda(n, 1) ;
    arbol.insertar_hermanoderecha(n, 4) ;

    arbol.insertar_hijomasizquierda(naux, 6) ;
    arbol.insertar_hermanoderecha(naux, 9) ;
    naux = naux->izqda ;

    arbol.insertar_hijomasizquierda(naux, 7) ;

//     cout << "Recorrido inorden: " << endl ;
//     arbol.inorden(arbol.raiz()) ;
//     cout << endl ;
//
//     cout << "Recorrido preorden: " << endl ;
//     arbol.preorden(arbol.raiz()) ;
//     cout << endl ;

    ArbolGeneral<int> arbol1(5) ;
    ArbolGeneral<int>::Nodo no = arbol1.raiz() ;
    ArbolGeneral<int>::Nodo nx ;

    arbol1.insertar_hijomasizquierda(no, 8) ;
    arbol1.insertar_hermanoderecha(no, 3) ;
    nx = no->drcha ;
    no = no->izqda ;


    arbol1.insertar_hijomasizquierda(no, 9) ;
    arbol1.insertar_hermanoderecha(no, 6) ;
    no = no->drcha ;

    arbol1.insertar_hijomasizquierda(no, 7) ;

    arbol1.insertar_hijomasizquierda(nx, 4) ;
    arbol1.insertar_hermanoderecha(nx, 1) ;


//     cout << "Recorrido preorden: " << endl ;
//     arbol1.preorden(arbol1.raiz()) ;
//     cout << endl ;
//     cout << "Recorrido inorden: " << endl ;
//     arbol1.inorden(arbol1.raiz()) ;
//     cout << endl ;
//     cout << "Potencia Externa: " << CalculaPotenciaExterna(arbol) << endl ;
    cout << isMirror(arbol.raiz(),arbol1.raiz()) << endl ;
}  
