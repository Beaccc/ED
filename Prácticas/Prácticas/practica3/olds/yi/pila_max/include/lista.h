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
      T elem;        /**< Elemento de información.*/
      Celda<T> * sig; /**< Puntero al siguiente nodo.*/
      Celda() : sig(NULL) {};
};


template <class T>
class Lista;

/**
 * @brief Clase Iterador
 *
 * Una instancia de la Clase Iterador es un puntero de tipo Celda<T>, 
 * que nos sirve para movernos por El TDA Lista. El acceso a los elementos
 * tambien se hace por medio de la clase Iterador. Un objeto de tipo Iterador
 * apunta <b>a la celda anterior</b> a la deseada.
 * 
 * @author Mario Rodríguez Ruiz
 * @date Noviembre 2016
*/


template <class T>
class Iterador {
private:
    Celda<T> *ptr;/**< puntero a una celda de la lista. */

public:
    /**
    * @brief Constructor por defecto
    */
    Iterador(){
        ptr = NULL;
    }

/**
* @brief Operador de incremento.
* @return Devuelve la siguiente posición.
*/
Iterador<T> & operator++() {
    ptr = ptr->sig;
    return *this;
}

/**
* @brief Operador de comprobación si es igual.
* @param p Iterador con la que se compara.
* @return Devuelve true si son iguales los punteros de lo contrario false.
*/
    bool operator==(const Iterador& p){ 
        return ptr == p.ptr;
    }

/**
* @brief Operador de comprobación distinto
* @param p Iterador con la que se compara
* @return Devuelve true si son distintos los punteros de lo contrario false.
*/
    bool operator!=(const Iterador& p){ 
        return ptr != p.ptr; 
    }

/**
* @brief Operador *
* @return Devuelve una referencia al elemento donde apunta una posición.
*/
    T& operator*(){
        return ptr->elem;
    }

    friend class Lista<T>;
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
 * entrada a ésta. Una lista vacía tiene por tanto <b>un elemento</b>. Los elementos se acceden
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
    Celda<T> * _cab; /**< Puntero a la cabecera de la celda */
    Celda<T> * _ultima; /**< Puntero al ultimo elemento de la lista */
    
    /**
     * @brief Copia en el objeto otra lista
     * @param l objeto lista a copiar
    */
    void copiar(const Lista<T> & l);
public:
    /**
     * @brief Constructor por defecto.
    */
    Lista();
    
    /**
     * @brief Constructor de copia.
     * @param l Lista a partir de la que se construye el objeto
    */
    Lista(const Lista<T> & t);
    
    /**
     * @brief Destructor de la clase
    */
    ~Lista();
    
    /**
     * @brief Devuelve un iterador a la primera posición.
     * @return Se devuelve un puntero al primer elemento. Si la lista está vacía se devuelve un puntero a NULL.
    */
    Iterador<T> begin() const;
    
    /**
     * @brief Devuelve un iterador a la última posición.
     * @return Se devuelve un puntero al último elemento. Si la lista está vacía se devuelve un puntero a NULL.
     * @post El iterador devuelto apunta a la posicion \b siguiente al último elemento, por lo que nunca debe ser deferenciada.
    */
    Iterador<T> end() const;
    
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
    
    /**
     * @brief Modifica el elemento de una posición.
     * @param it Iterador que apunta a la posición que queremos modificar.
     * @param t Elemento a insertar como modificación.
    */
    void set(Iterador<T> it, const T & t);
    
    /**
     * @brief Devuelve el elemento de una posición.
     * @param it Iterador a la posición a devolver.
    */
    T get(Iterador<T> it);
    
    /**
     * @brief Elimina una posicion de la lista, celda incluida.
     * @pre No se debe intentar la posición apuntada por _ultima (o el iterador devuelto por end() )
     * @param it Iterador a la posición a eliminar.
    */
    Iterador<T> borrar(Iterador<T> it);
    
    /**
     * @brief Inserta un elemento en una posición
     * @param it Iterador a la posición a insertar.
     * @post El iterador it sigue siendo válido.
    */
    Iterador<T> insertar(Iterador<T> it, const T & t);
    
    /**
     * @brief Comprueba si la lista está vacía
     * @retval true si está vacía, falso en caso contrario.
    */
    bool vacia();
    
};


#include "lista.cpp"
#endif
