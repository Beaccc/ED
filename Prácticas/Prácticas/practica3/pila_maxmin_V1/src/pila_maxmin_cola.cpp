#include "pila_maxmin_cola.h"

/* _________________________________________________________________________ */

bool Pila_maxmin::vacia() const {
    return _pila[_activa]->vacia();
}

/* _________________________________________________________________________ */

elemento Pila_maxmin::tope() const {
    return _pila[_activa]->frente();
}

/* _________________________________________________________________________ */

void Pila_maxmin::poner(int n){
    elemento e;
    e.elem = n;
    if(_pila[_activa]->vacia()){
        e.max = n;
        e.min = n;
        //_max = n;
        _pila[_activa]->poner(e);
    }
    else if(!repetido(n)){
        int max = _pila[_activa]->frente().max;     // Crea una nueva variable con el máximo actual
        int min = _pila[_activa]->frente().min;     // Crea una nueva variable con el mínimo actual

        // Si el valor nuevo es mayor que el máximo actual, éste se actualiza.
        // sino se queda como estaba.
        if(n > max){
            e.max = n;
        }
        else
            e.max = max;

        // Si el valor nuevo es menor que el mínimo actual, éste se actualiza.
        // sino se queda como estaba.
        if(n < min)
            e.min = n;
        else
            e.min = min;

        short inactiva = _activa;
        _activa = (_activa + 1) % 2;
        _pila[_activa]->poner(e);

        while(!_pila[inactiva]->vacia()){
            _pila[_activa]->poner( _pila[inactiva]->frente() );
            _pila[inactiva]->quitar();
        }
    }
}

/* _________________________________________________________________________ */

void Pila_maxmin::quitar(){
    _pila[_activa]->quitar();
}

/* _________________________________________________________________________ */

bool Pila_maxmin::repetido(int n){
    unsigned tam = _pila[_activa]->num_elementos() ;
    bool resultado = false ;
    elemento e ;

    // Recorre la cola y devuelve true si encuentra
    // un valor específico en ella.
    for (unsigned i = 0 ; i < tam && !resultado ; i++){
        e = (*_pila[_activa])[i] ;
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
//     cout << p._pila[1]->num_elementos() << endl ;
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
