/**
 * @file pila_maxmin.h
 * @brief Estructura que guarda cada elemento de la pila.
 * Cada elemento guarda un entero, un valor máximo y mínimo
 * de la pila hasta el momento.
 *
 * @author Mario Rodríguez Ruiz
 * @date Noviembre 2016
*/

#include <iostream>

#define CUAL_COMPILA 2

using namespace std ;

/**
 * @brief Estructura que guarda cada elemento de la pila.
 * Cada elemento guarda un entero, un valor máximo (máximo
 * de la pila hasta el momento) y un valor mínimo (mínimo
 * de la pila hasta el momento).
*/


struct elemento{
    int elem;   /**< Valor del elemento de la pila */
    int max;    /**< Valor máximo en la pila */
    int min;    /**< Valor mínimo en la pila */

    /**
    * @brief Salida de un elemento a ostream
    * @param out Stream de salida
    * @param e Elemento a escribir
    * @post Se obtiene en out la cadena con el el ele y el maximo de un elemento
    */
    friend ostream & operator << (ostream & out, const elemento & e){
        out << "(" << e.elem << "," << e.max << "," << e.min <<")" << " " ;
        return out;
    }

};

#if CUAL_COMPILA == 1
    #include "pila_maxmin_VD.h"
#elif CUAL_COMPILA == 2
    #include "pila_maxmin_list.h"
#elif CUAL_COMPILA == 3
    #include "pila_maxmin_cola.h"
#endif

