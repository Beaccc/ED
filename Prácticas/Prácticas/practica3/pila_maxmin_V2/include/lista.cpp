/** @file lista.cpp
  * @brief Implementación de la clase Lista.
  * @author Mario Rodríguez Ruiz
  * @date Noviembre 2016
*/

#include "lista.h"
#include <cassert>
#include <cstdio>

/* _________________________________________________________________________ */

template<class T>
Lista<T>::Lista(){
    _cab = 0 ;
    _size = 0 ;
}

/* _________________________________________________________________________ */

template<class T>
Lista<T>::~Lista(){
    if(_cab != NULL)
        liberarMemoria() ;
    _cab = 0 ;
    _size = 0 ;
}

/* _________________________________________________________________________ */

template<class T>
void Lista<T>::liberarMemoria(){
    for(int i = 0 ; i < _size ; i++){
        eliminaUltimaCelda() ;
    }

    delete _cab ;
}

/* _________________________________________________________________________ */

template<class T>
void Lista<T>::eliminaUltimaCelda(){
    if(_size > 1){
        Celda<T> *ultima = obtenerCelda(_size-1) ;
        ultima->setSiguiente(0) ;
        delete obtenerCelda(_size) ;

        _size-- ;
    }
    else{
        delete _cab ;
        _cab = 0 ;
        _size = 0 ;
    }
}

/* _________________________________________________________________________ */

template<class T>
void Lista<T>::insertar(const T & e){
    Celda<T> *ultima, *nueva ;
    nueva = new Celda<T>(e) ;
    ultima = obtenerCelda(_size) ;

    if(_cab != 0){
        ultima->setSiguiente(nueva) ;
    }
    else{
        _cab = nueva ;
    }

    _size++ ;
}

/* _________________________________________________________________________ */

template<class T>
Celda<T> * Lista<T>::obtenerCelda(const int indice) const{
    assert(indice >= 0 && indice <= _size) ;

    Celda<T> *pCelda = _cab ;

    if(indice != 0)
        for(int i = 0 ; i < indice-1 ; i++)
            pCelda = pCelda->getSiguiente() ;

    return pCelda ;
}

/* _________________________________________________________________________ */

template <class T>
T & Lista<T>::operator[](int indice){
    Celda<T> * aux = _cab ;

    if(indice != 0)
        for(int i = 0 ; i < indice-1 ; i++)
            aux = aux->getSiguiente()  ;

    return aux->elem;
}

/* _________________________________________________________________________ */

template<class T>
bool Lista<T>::vacia(){
    if(_cab == 0)
        return true;
    else
        return false;
}

/* _________________________________________________________________________ */

template <class T>
void Lista<T>::borrar(){
  assert(_cab!=0);             //Si la cola está vacía, abortar
  Celda<T> *aux = _cab;           //Copiamos el puntero al primer nodo
  _cab = _cab->siguiente;   //Actualizamos primera
  delete aux;                     //Borramos el primer nodo
//   if (_cab == 0)               //Si no quedan nodos,
//     ultima=0;                     //actualizamos ultima
  _size--;                     //Actualizamos el número de elementos
}

/* _________________________________________________________________________ */

template<class T>
Celda<T> * Lista<T>::begin() const{
    return _cab ;
}

/* _________________________________________________________________________ */

template<class T>
Celda<T> * Lista<T>::end() const{
    return obtenerCelda(_size) ;
}

/* _________________________________________________________________________ */

template<class T>
T Lista<T>::front() const{
    return _cab->elem;
}

/* _________________________________________________________________________ */

template<class T>
T Lista<T>::back() const{
    return obtenerCelda(_size)->elem;
}
