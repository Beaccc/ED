 #include "pila_max_cola.h"

bool Pila_max::Vacia(){
    return _pila[_activa]->vacia();
}

elemento Pila_max::Tope(){
    return _pila[_activa]->frente();    
}

void Pila_max::Poner(int n){
    elemento e;
    e.elem = n;
    if(_pila[_activa]->vacia()){
        e.max = n;
        //_max = n;
        _pila[_activa]->poner(e);
    }
    else{
        int max = _pila[_activa]->frente().max;
        if(n > max){
            e.max = n;
        }
        else
            e.max = max;
        short inactiva = _activa;
        _activa = (_activa + 1) % 2;
        _pila[_activa]->poner(e);
        
        while(!_pila[inactiva]->vacia()){
            _pila[_activa]->poner( _pila[inactiva]->frente() );
            _pila[inactiva]->quitar();
        }
        
    }
}

void Pila_max::Quitar(){
    _pila[_activa]->quitar();
}