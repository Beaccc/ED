/** @file pila_maxmin_list.cpp
  * @brief Implementación de la clase Pila_maxin en Lista.
  * @author Mario Rodríguez Ruiz
  * @date Noviembre 2016
*/

#include "pila_maxmin_list.h"

/* _________________________________________________________________________ */

bool Pila_maxmin::vacia(){
    return _pila->vacia();
}

/* _________________________________________________________________________ */

Pila_maxmin::~Pila_maxmin(){
    while(!_pila->vacia()){
        quitar() ;
    }
    delete _pila ;
}

/* _________________________________________________________________________ */

elemento Pila_maxmin::tope() const{
    if( !_pila->vacia() )
        return _pila->front();
    else
        return _pila->back();
}

/* _________________________________________________________________________ */

void Pila_maxmin::poner(int n){
    elemento e;
    e.elem = n;

    if( _pila->vacia() ){
        e.max = n;
        e.min = n;
        _pila->insertar(_pila->begin(), e);
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

        _pila->insertar(_pila->begin(), e);
    }
}

/* _________________________________________________________________________ */

void Pila_maxmin::quitar(){
    if( !_pila->vacia() ){
        _pila->borrar(_pila->begin());
    }
}

/* _________________________________________________________________________ */

bool Pila_maxmin::repetido(int n){
    bool resultado = false ;
    elemento e ;

    // Recorre la cola y devuelve true si encuentra
    // un valor específico en ella.
    for (unsigned i = 0 ; i < _pila->size() && !resultado ; i++){
        e = (*_pila)[i] ;
        if(e.elem == n || e.max == n || e.min == n)
            resultado = true ;
    }

    return resultado ;
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

/* _________________________________________________________________________ */
