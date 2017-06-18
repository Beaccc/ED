#include "pila_maxmin_cola.h"
#include "pila_maxmin.h"

/* _________________________________________________________________________ */

istream& operator>>(istream &in, Pila_maxmin & p){
    int entero ;
    string f;
    while(!in.eof()){
        in >> f;
        cout << f << ", " ;
        entero = atoi( f.c_str() ) ;
        if(f != "\n" && f != " "){
            p.poner(entero) ;
        }
    }
    cout << endl ;
    cout << p._pila[1]->num_elementos() << endl ;
    return (in);
}

/* _________________________________________________________________________ */

bool operator>(const Pila_maxmin & p) {
    elemento local = tope() ;
    elemento entrada = p.tope() ;

    // Es mayor si el mínimo es mayor que
    if(local.min > entrada.max)
        return true ;
    else
        return false ;
}

/* _________________________________________________________________________ */

bool operator[](const Pila_maxmin & p) {
    elemento local = tope() ;
    elemento entrada = p.tope() ;

    if(local.min < entrada.min && local.max > entrada.max)
        return true ;
    else
        return false ;
}
