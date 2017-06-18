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
void Lista<T>::copiar(const Lista<T> & l){
    _cab = new Celda<T>;
    Iterador<T> it = l.begin();
    _ultima = _cab;
    while(it.ptr->sig != NULL){
        _ultima->sig = new Celda<T>;
        _ultima = _ultima->sig;
        _ultima->elem = it.ptr->sig->elem;
        it++;
    }
    _ultima->sig = NULL;
}

/* _________________________________________________________________________ */

template<class T>
Lista<T>::Lista(){
    _cab = new Celda<T>;
    _ultima = _cab;
}

/* _________________________________________________________________________ */

template<class T>
Lista<T>::Lista(const Lista<T> & l){
    _cab = new Celda<T>;
    _ultima = _cab;
    Iterador<T> it = l.begin();
    while(it.ptr->sig != NULL){
        _ultima->sig = new Celda<T>;
        _ultima = _ultima->sig;
        _ultima->elem = it.ptr->sig->elem;
        ++it;
    }
    _ultima->sig = NULL;
}

/* _________________________________________________________________________ */

template<class T>
Lista<T>::~Lista(){
    Celda<T> * c;
    while(_cab != NULL){
        c = _cab;
        _cab = _cab->sig;
        delete c;
    }
    delete _cab ;
}

/* _________________________________________________________________________ */

template<class T>
Iterador<T> Lista<T>::begin() const{
    Iterador<T> it;
    it.ptr = _cab;

    return it ;
}

/* _________________________________________________________________________ */

template<class T>
Iterador<T> Lista<T>::end() const{
    Iterador<T> it;
    it->ptr = _ultima;

    return it ;
}

/* _________________________________________________________________________ */

template<class T>
T Lista<T>::front() const{
    return _cab->sig->elem;
}

template<class T>
T Lista<T>::back() const{
    return _ultima->elem;
}

/* _________________________________________________________________________ */

template<class T>
bool Lista<T>::vacia(){
    if(_cab == _ultima) return true;
    else    return false;
}

/* _________________________________________________________________________ */

template<class T>
void Lista<T>::set(Iterador<T> it, const T & t){
    *it = t;
}

/* _________________________________________________________________________ */

template<class T>
T Lista<T>::get(Iterador<T> it){
    return *it;
}

/* _________________________________________________________________________ */

template<class T>
Iterador<T> Lista<T>::borrar(Iterador<T> it){
    assert(it.ptr != _ultima);
    Celda<T> * c = it.ptr->sig;
    it.ptr->sig = c->sig;
    if(c == _ultima) _ultima = it.ptr;
    delete c;
    return it;
}

/* _________________________________________________________________________ */

template<class T>
Iterador<T> Lista<T>::insertar(Iterador<T> it, const T & t){
    Celda<T> * ins = new Celda<T>;
    ins->elem = t;
    ins->sig = it.ptr->sig;
    it.ptr->sig = ins;
    if(it.ptr == _ultima)
        _ultima = ins;

    ++_size;
    return it;
}

/* _________________________________________________________________________ */

template <class T>
unsigned Lista<T>::size() const{
    return _size;
}

/* _________________________________________________________________________ */

template <class T>
T & Lista<T>::operator[](unsigned indice){
    Celda<T> * aux = _cab->sig ;

    for(unsigned i = -1 ; i < indice-1 ; i++)
        aux = aux->sig ;

    return aux->elem;
}

/* _________________________________________________________________________ */
