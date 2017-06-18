#include "pila_max_list.h"

bool Pila_max::Vacia(){
    return _pila->Vacia();
}

elemento Pila_max::Tope(){
    if( !_pila->Vacia() )
        return (*_pila)[_pila->size() - 1];
}

void Pila_max::Poner(int n){
    elemento e;
    e.elem = n;
    if( _pila->Vacia() ){
        e.max = n;
        _pila->push_back(e);
    }else{
        elemento f = Tope();
        if(n > f.max)
            e.max = n;
        else
            e.max = f.max;
        _pila->push_back(e);
    }
}

void Pila_max::Quitar(){
    if( !_pila->Vacia() ){
        _pila->pop_back();
    }
}

