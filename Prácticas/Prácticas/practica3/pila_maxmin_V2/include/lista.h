/**
 * @file lista.h
 * @brief Fichero cabecera del TDA Lista
 *
 * Gestiona una secuencia de elementos con facilidades para la inserción y
 * borrado de elementos en cualquier posicion.
 *
 * @author Mario Rodríguez Ruiz
 * @date Noviembre 2016
*/

#ifndef _LISTA_H_
#define _LISTA_H_

#include <cstdlib>

/**
 *  @brief Struct Celda
 * struct que define el tipo de celdas utilizadas para la implementacion de la lista.
*/
template <class T>
struct Celda {
    T elem;                   /**< Elemento de información.*/
    Celda<T> *siguiente;     /**< Puntero al siguiente nodo.*/

    Celda(){
        elem = 0 ;
        siguiente = 0 ;
    }

    Celda(T e){
        elem = e ;
        siguiente = 0 ;
    }

    inline Celda * getSiguiente() const{
        return siguiente ;
    }

    void setSiguiente(Celda *sig){
        siguiente = sig ;
    }

    void setElem(T e){
        elem = e ;
    }
};

/**
 *  @brief T.D.A. Lista
 *
 *
 * Una instancia @e c del tipo de dato abstracto lista sobre un dominio @e T es
 * una sucesión finita de elementos del mismo. En una lista, las operaciones de inserción
 * y borrado tienen lugar en cualquier posición, denominado. Una lista de longitud @e n la
 * denotamos
 *
 * - <a1,a2,a3,..,an>
 *
 * El espacio requerido para el almacenamiento es O(n), donde n es el número
 * de elementos de la lista.
 *
 * La lista contiene una celda cabecera que no contiene datos útiles y es solamente el punto de
 * entrada a ésta. Una lista vacía tiene por tanto <b> un elemento </b>. Los elementos se acceden
 * a traves de objetos de tipo Iterador, que apuntan a la celda anterior del elemento en cuestión.
 *
 * @author Mario Rodríguez Ruiz
 * @date Noviembre 2016
*/

template <class T>
class Lista{
    private:
        /**
        * @page repConjunto Rep del TDA Lista
        *
        * @section invConjunto Invariante de la representación.
        *
        * La lista contiene una celda de cabecera apuntada por "_cab", y no debe ser nunca borrada.
        * La cabecera no contiene datos.
        *
        */
        Celda<T> * _cab;        /**< Puntero a la cabecera de la celda */
        int _size;         /**< Número de elementos almacenados actualmente */

        /**
        * @brief Copia en el objeto otra lista
        * @param l objeto lista a copiar
        */
        void copiar(const Lista<T> & l);

        /**
        * @brief Libera memoria ocupada por la lista.
        */
        void liberarMemoria() ;

        Celda<T> * obtenerCelda(const int indice) const ;
    public:
        /**
        * @brief Constructor por defecto.
        */
        Lista();

        /**
        * @brief Constructor de copia.
        * @param l Lista a partir de la que se construye el objeto
        */
        Lista(const Lista<T> & l);

        /**
        * @brief Destructor de la clase
        */
        ~Lista();

        /**
        * @brief Sobrecarga el operador de asignación
        * @param lista es el objeto a copiar
        *
        * Construye una lista a partir de @a otra
        */
        Lista& operator= (const Lista<T> &otra) ;

        /**
        * @brief inserta un nuevo elemento al final de la lista
        * @param e elemento a insertar en la lista
        *
        * Añade un nuevo elemento ( @a e ) a la lista
        */
        void insertar(const T & e);

        /**
        * @brief elimina la última celda.
        *
        *
        */
        void eliminaUltimaCelda() ;

        /**
        * @brief Comprueba si la lista está vacía
        * @retval true si está vacía, falso en caso contrario.
        */
        bool vacia();

        /**
        * @brief Tamaño de la lista.
        * @return Devuelve el tamaño de la lista.
        */
        inline int size() const{
            return _size ;
        }

        /**
        * @brief Operador de indexación.
        * @param i El elemento a acceder.
        */
        T & operator[](int i);

        /**
        * @brief Elimina una posicion de la lista, celda incluida.
        * @pre No se debe intentar la posición apuntada por _ultima (o el iterador devuelto por end() )
        * @param it Iterador a la posición a eliminar.
        */
        void borrar();

        /**
        * @brief Devuelve la primera celda
        *
        */
        Celda<T> *begin() const ;

        /**
        * @brief Devuelve la última celda
        *
        */
        Celda<T> *end() const ;

        /**
        * @brief Devuelve el elemento del principio de la lista.
        * @return El elemento de tipo T del principio de la lista.
        */
        T front() const;

        /**
        * @brief Devuelve el elemento del final de la lista.
        * @return El elemento de tipo T del final de la lista.
        */
        T back() const;

};

#include "lista.cpp"

#endif
