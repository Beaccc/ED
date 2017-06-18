 
/** @file Diccionario.cpp
 *  @brief Implementación del Diccionario
 *
 *  @author Mario Rodríguez Ruiz
 *  @date Diciembre 2016
 */

#ifndef NULL
#define NULL (void *)0
#endif

#ifndef __Diccionario_cpp__
#define __Diccionario_cpp__

#include "Diccionario.h"

/*******************************
*      Métodos privados        *
*******************************/



/******************************
*       Constructores         *
******************************/

Diccionario::Diccionario(){}

//--------------------------------------------------------------------
//

Diccionario::~Diccionario(){
    datos.clear();
}

/********************************
*       Métodos publicos        *
********************************/

void Diccionario::Insertar(const int &clave, const list<string> &l){
    datos[clave] = l ;
}

ostream & operator <<(ostream &out, const list<string> &l){
    list<string>::const_iterator lit ;

    for(lit = l.begin() ; lit != l.end() ; ++lit){
        out << (*lit) << ' ' ;
    }

    return out ;
}

ostream & operator <<(ostream &out, const Diccionario &d){
    Diccionario::const_iterator it ;

    for(it=d.begin() ; it!=d.end() ; ++it){
        out << (*it).first << " -> " << (*it).second << endl ;
    }
    return out ;
}
// //--------------------------------------------------------------------
//
// template<class Tbase>
Diccionario& Diccionario::operator=(const Diccionario &d){
    if (this!=&d){
        datos.clear() ;
        datos = d.datos ;
    }
    return *this;
}
//
// //--------------------------------------------------------------------


#endif
