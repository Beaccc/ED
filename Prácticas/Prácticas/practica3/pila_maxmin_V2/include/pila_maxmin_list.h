/**
 * @file pila_maxmin_list.h
 * @brief Especificación de la clase Pila_maxmin con listas
*/

#ifndef _PILA_MAXMIN_LIST_
#define _PILA_MAXMIN_LIST_

#include <iostream>
#include <cstdlib>

#include "lista.h"

/**
 * @brief T.D.A. Pila_max
 *
 * Una instancia @e pila del tipo de datos abstracto @c Pila_maxmin es un objeto que se
 * compone de un un objeto tipo Lista (TDA Lista) donde este guardara en cada nodo una
 * estructura elemento que guarda "elem" un entero y el "max" hasta esa posicion dentro
 * de la pila.
 *
 * Lo representamos:
 *
 * Lista<elemento> pila;
 *
 * Un ejemplo de su uso:
 * @include usopilas_maxmin.cpp
 *
 * @author Mario Rodríguez Ruiz
 * @date Noviembre 2016
 */

class Pila_maxmin{
private:
    /**
     * @page repConjunto Rep del TDA Pila_maxmin
     *
     * @section invConjunto Invariante de la representación.
     *
     * El invariante El tope de la pila debe contener un conjunto de enteros pero
     * ademas se almacena el valor maximo que existe en la Pila.
     *
     * @section faConjunto Función de abstracción.
     *
     * Un objeto válido @e rep del TDA Pila_maxmin representa al valor.
     *
     * (rep.pila)
     *
    */
    Lista<elemento> * _pila; /**< pila objeto de tipo Lista<elemento*/

public:
    /**
     * @brief Constructor por defecto
     */
    Pila_maxmin(): _pila(new Lista<elemento>()){};

    /**
     * @brief Constructor de copia
    */
    Pila_maxmin(const Pila_maxmin & p){
        delete _pila;
        _pila = new Lista<elemento>(*p._pila);
    }

    /**
     * @brief Destructor
    */
    ~Pila_maxmin() ;

    /**
     * @brief Devuelve el elemento del tope.
     * @return El elemento en el tope de la pila.
    */
    elemento tope() const ;

    /**
     * @brief Añade un elemento encima del tope.
     * @param n Entero a colocar en el tope.
     * @post La pila crece un elemento, y el insertado pasa a ser el tope.
    */
    void poner(int n);

    /**
     * @brief Elimina el elemento del tope.
     * @post La pila decrece en un elemento.
    */
    void quitar();

    /**
     * @brief Comprueba si la pila esta vacía.
     * @retval true si la pila está vacía, false en caso contrario.
    */
    bool vacia();

    /**
     * @brief Comprueba si ya existe un valor en la pila.
     * @param n es el valor a comprobar
     * @retval true si ese valor ya existe, @a false en caso contrario.
    */
    bool repetido(int n);

    /**
    * @brief Entrada de una pila por istream
    * @param in Stream de entrada
    * @param p Pila a rellenar
    * @post Se obtiene en @a p la pila rellena con los elementos del fichero
    * de entrada.
    */
    friend istream& operator>>(istream &in, Pila_maxmin & p) ;

    /**
    * Sobrescritura del operador de relacional >
    * @param p Pila_maxmin de entrada
    * @return resultado de la comparacion
    *
    * El mínimo es mayor que el máximo de @a p
    */
    bool operator>(const Pila_maxmin & p) const;

    /**
    * Sobrescritura del operador de relacional []
    * @param p
    * @retval true si @a p se encuentra en el rango
    */
    bool operator[](const Pila_maxmin & p) const;
};

#include "pila_maxmin_list.cpp"

#endif
