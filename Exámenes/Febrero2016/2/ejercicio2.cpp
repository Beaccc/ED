// Mario Rodríguez Ruiz
/*
 Implementa una función bool sumaIgual(const list<list<int> > &L) que
devuelve true si todas las sumas por filas y por columnas da el mismo resultado (se
asume que todas las listas tienen igual longitud). Por ejemplo, en la siguiente lista si se
suma cada fila y cada columna siempre se obtiene 3
        L=< <0,1,1,1>,
        <2,1,0,0>,
        <1,0,2,0>,
        <0,1,0,2> >

*/

#include <iostream>
#include <list>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <unordered_set>

using namespace std;

bool sumaIgual(const list<list<int> > &L){
    list<list<int>>::const_iterator it=L.begin() ;
    list<int>::const_iterator lit=(*it).begin() ;
    bool res = true ;
    int suma_fil, total = 0, comprobar = 0 ;
    vector<int> suma_col ;
    unsigned i ;

    for( ; lit != (*it).end() && res; ++lit)
        suma_col.push_back(0) ;

    for(it=L.begin() ; it != L.end() && res; ++it){
        i = 0 ;
        suma_fil = 0 ;
        comprobar++ ;
        for(lit=(*it).begin() ; lit != (*it).end() && res; ++lit){
            suma_fil+=(*lit) ;
            suma_col[i]+=(*lit) ;
            i++ ;
        }

        if(comprobar <= 1)
            total = suma_fil ;
        else if(total!=suma_fil)
            res = false ;
    }

    if(res){
        for(unsigned j = 0 ; j < suma_col.size() && res; j++)
            if(total != suma_col[j])
                res = false ;
    }

    return res ;
}

int main(){
    list<list<int>> lista ;

    list<int> l1 = {0, 1, 1, 1} ;
    lista.push_back(l1) ;

    list<int> l2 = {2, 1, 0, 0} ;
    lista.push_back(l2) ;

    list<int> l3 = {1, 0, 2, 0} ;
    lista.push_back(l3) ;

    list<int> l4 = {0, 1, 0, 2} ;
    lista.push_back(l4) ;

    cout << "La suma " ;

    if(sumaIgual(lista))
        cout << "es igual!" << endl ;
    else
        cout << "no es igual." << endl ;

}  
  
  
  
  
  
  
  
  
