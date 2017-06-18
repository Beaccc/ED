#include "pila_max_list.h"

bool Pila_max::Vacia(){
    return _pila->Vacia();
}

elemento Pila_max::Tope(){
    if( !_pila->Vacia() )
        return _pila->front();
}

void Pila_max::Poner(int n){
    elemento e;
    e.elem = n;
    if( _pila->Vacia() ){
        e.max = n;
        _pila->Insertar(_pila->begin(), e);
    }else{
        elemento f = Tope();
        if(n > f.max)
            e.max = n;
        else
            e.max = f.max;
        _pila->Insertar(_pila->begin(), e);
    }
}

void Pila_max::Quitar(){
    if( !_pila->Vacia() ){
        _pila->Borrar(_pila->begin());
    }
}

