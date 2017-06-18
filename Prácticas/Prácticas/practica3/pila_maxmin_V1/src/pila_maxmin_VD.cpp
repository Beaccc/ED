/** @file pila_maxmin_VD.cpp
  * @brief Implementación de la clase Pila_maxin en VD.
  * @author Mario Rodríguez Ruiz
  * @date Noviembre 2016
*/

#include "pila_maxmin_VD.h"
#include <string.h>
#include <string>

/* _________________________________________________________________________ */

Pila_maxmin::~Pila_maxmin(){
    while(!vacia()){
        quitar() ;
    }
    delete _pila ;
}

/* _________________________________________________________________________ */

bool Pila_maxmin::vacia(){
    return _pila->vacia();
}

/* _________________________________________________________________________ */

elemento Pila_maxmin::tope() const{
    if( !_pila->vacia() )
        return (*_pila)[_pila->size() - 1];
    else
        return (*_pila)[0];
}

/* _________________________________________________________________________ */

bool Pila_maxmin::repetido(int n){
    bool resultado = false ;
    //Pila_maxmin aux = *this ;
    elemento e ;

    for (unsigned i = 0 ; i < _pila->size() && !resultado ; i++){
        e = (*_pila)[i] ;
        if(e.elem == n || e.max == n || e.min == n)
            resultado = true ;
    }

    return resultado ;
}

/* _________________________________________________________________________ */

void Pila_maxmin::poner(int n){
    elemento e;
    e.elem = n;
    if( _pila->vacia() ){
        e.max = n;
        e.min = n ;
        _pila->push_back(e);
    }else if(!repetido(n)){
        elemento f = tope();
        // Si el valor nuevo es mayor que el máximo actual, éste se actualiza.
        // sino se queda como estaba.
        if(n > f.max)
            e.max = n;
        else
            e.max = f.max;
        // Si el valor nuevo es menor que el mínimo actual, éste se actualiza.
        // sino se queda como estaba.
        if(n < f.min)
            e.min = n;
        else
            e.min = f.min;

        _pila->push_back(e);
    }
}

/* _________________________________________________________________________ */

void Pila_maxmin::quitar(){
    if( !_pila->vacia() ){
        _pila->pop_back();
    }
}

/* _________________________________________________________________________ */

istream& operator>>(istream &in, Pila_maxmin & p){
    int entero ;
    string f;
    while(!in.eof()){
        in >> f;
//         cout << f << ", " ;
        entero = atoi( f.c_str() ) ;
        if(f != "\n" && f != " "){

            p.poner(entero) ;
        }
    }
//     cout << endl ;
//     cout << p._pila->size() << endl ;
    return (in);
}

/* _________________________________________________________________________ */

bool Pila_maxmin::operator>(const Pila_maxmin & p) const{
    elemento local = tope() ;
    elemento entrada = p.tope() ;

    if(local.min > entrada.max)
        return true ;
    else
        return false ;
}

/* _________________________________________________________________________ */

bool Pila_maxmin::operator[](const Pila_maxmin & p) const{
    elemento local = tope() ;
    elemento entrada = p.tope() ;

    if(local.min < entrada.min && local.max > entrada.max)
        return true ;
    else
        return false ;
}
