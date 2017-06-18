 
/**
 * @file pila_max_cola.h
 * @brief Especificación de la clase Pila_max con colas
 * @author Mario Rodríguez Ruiz
 * @date Noviembre 2016
*/

#ifndef _PILA_MAX_LIST_
#define _PILA_MAX_LIST_

#include <iostream>
#include <cstdlib>
#include <cassert>

#include "cola.h"

/**
  * @brief Salida de un elemento a ostream
  * @param out Stream de salida
  * @param e Elemento a escribir
  * @post Se obtiene en out la cadena con el el ele y el maximo de un elemento
  */

    inline std::ostream & operator << (std::ostream & out, elemento & e){
        out << "(" << e.elem << "," << e.max << ")" << " " ;	
        return out;	
    }

/**
 * @brief T.D.A. Pila_max
 *
 * Una instancia @e pila del tipo de datos abstracto @c Pila_max es un objeto que se 
 * compone de un un objeto tipo Cola (TDA Cola) donde este guardara en cada nodo una 
 * estructura elemento que guarda "elem" un entero y el "max" hasta esa posicion dentro 
 * de la pila.
 *
 * Lo representamos:
 *
 *Cola<elemento> pila;	
 *
 * Un ejemplo de su uso:
 * @include usopilas_max.cpp
 *
 * @author Mario Rodríguez Ruiz
 * @date Noviembre 2016
 */

class Pila_max{
private:
    /**
     * @page repConjunto Rep del TDA Pila_max
     *
     * @section invConjunto Invariante de la representación.
     *
     * El invariante El tope de la pila debe contener un conjunto de enteros pero
     * ademas se almacena el valor maximo que existe en la Pila.
     *
     * @section faConjunto Función de abstracción.
     *
     * Un objeto válido @e rep del TDA Pila_max representa al valor.
     *
     * (rep.pila)
     *
    */
    short _activa;            /**< Indica la pila activa en el array */
    Cola<elemento> * _pila[2]; /**< array con dos colas, para ir volcando una en otra y poner el final al principio*/
public:
    /**
     * @brief Constructor por defecto
    */ 
    Pila_max(){
        _pila[0] = new Cola<elemento>();
        _pila[1] = new Cola<elemento>();
        _activa = 0;
    }
    
    /**
     * @brief Constructor de copia
    */
    Pila_max(const Pila_max & p){
        delete _pila[0];
        delete _pila[1];
        _pila[0] = new Cola<elemento>(*p._pila[p._activa]);
        _activa = 0;
    }
    
    /**
     * @brief Devuelve el elemento del tope.
     * @return El elemento en el tope de la pila.
    */
    elemento Tope();
    
    /**
     * @brief Añade un elemento encima del tope.
     * @param n Entero a colocar en el tope.
     * @post La pila crece un elemento, y el insertado pasa a ser el tope.
    */
    void Poner(int n);
    
    /**
     * @brief Elimina el elemento del tope.
     * @post La pila decrece en un elemento.
    */
    void Quitar();
    
    /**
     * @brief Comprueba si la pila esta vacía.
     * @retval true si la pila está vacía, false en caso contrario.
    */
    bool Vacia();
};
#endif
