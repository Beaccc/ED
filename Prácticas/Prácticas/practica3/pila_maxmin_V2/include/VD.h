/**
 * @file VD.h
 * @brief Fichero cabecera del TDA VD(Vector dinámico).
 *
 * Gestiona una secuencia de elementos almacenados en memoria de forma consecutiva.
 *
 * @author Mario Rodríguez Ruiz
 * @date Noviembre 2016
*/

#ifndef _VD_H_
#define _VD_H_

template <class T>
class VD;

/**
 *  @brief T.D.A. Vector Dinámico
 *
 *
 * Una instancia @e c del tipo de dato abstracto vector dinámico sobre un dominio @e T es
 * una sucesión finita de elementos del mismo. En un vector, los elementos se encuentran contiguos
 * en memoria por lo que las operaciones de búsqueda y modificación en bucle resultan más eficientes.
 *
 * El espacio requerido para el almacenamiento es O(n), donde n es el número
 * de elementos del vector.
 *
 * @author Mario Rodríguez Ruiz
 * @date Noviembre 2016
*/

template <class T>
class VD{
private:
    unsigned _size; /**< Número de elementos almacenados actualmente */
    unsigned _cap; /**< Capacidad real del vector: Memoria fisicamente reservada. */
    T * _datos; /**< Puntero a los datos del vector */

public:
    /**
     * @brief Constructor por defecto.
    */
    VD();

    /**
     * @brief Constructor de copia.
     * @param l VD a partir de la que se construye el objeto
    */
    VD(const VD<T> & t);

    /**
     * @brief Destructor de la clase
    */
    ~VD();

    /**
     * @brief Operador de asignación.
     * @param v El vector a asignar.
     */
    VD & operator=(const VD<T> & v);

    /**
     * @brief Operador de indexación.
     * @param i El elemento a acceder.
     */
    T & operator[](unsigned i);

    /**
     * @brief Tamaño el vector.
     * @return Devuelve el tamaño del vector.
     */
    unsigned size() const;

    /**
     * @brief Redimensiona el vector.
     */

    void resize(unsigned n);

    /**
     * @brief Inserta un elemento al final del vector.
     */

    void push_back(const T & t);

    /**
     * @brief Elimina el elemento del final del vector.
     */
    void pop_back();

    /**
     * @brief Elimina una posicion de la vector, celda incluida.
     * @param it Posición a eliminar.
    */
    void borrar(unsigned it);

    /**
     * @brief Inserta un elemento en una posición
     * @param it Posición a insertar.
    */
    void insertar(unsigned it, const T & t);

    /**
     * @brief Comprueba si el vector está vacío
     * @retval true si está vacío, falso en caso contrario.
    */
    bool vacia();

};


#include "VD.cpp"
#endif
