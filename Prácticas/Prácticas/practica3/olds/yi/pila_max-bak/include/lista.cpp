/** @file lista.cpp
  * @brief Implementación de la clase Lista.
*/

#include "lista.h"
#include <cassert>
#include <cstdio>

template<class T>
void Lista<T>::Copiar(const Lista<T> & l){
    //if(_cab != NULL ) delete this;              ///A VER
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

template<class T>
Lista<T>::Lista(){
    _cab = new Celda<T>;
    _ultima = _cab;
}

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

template<class T>
Lista<T>::~Lista(){
    Celda<T> * c;
    while(_cab != NULL){
        c = _cab;
        _cab = _cab->sig;
        delete c;
    }
}

template<class T>
Iterador<T> Lista<T>::begin() const{
    Iterador<T> it;
    it.ptr = _cab;
}
    
template<class T>
Iterador<T> Lista<T>::end() const{
    Iterador<T> it;
    it->ptr = _ultima;
}

template<class T>
T Lista<T>::front() const{
    return _cab->sig->elem;
}

template<class T>
T Lista<T>::back() const{
    return _ultima->elem;
}
    
template<class T>
bool Lista<T>::Vacia(){
    if(_cab == _ultima) return true;
    else    return false;
}

template<class T>
void Lista<T>::Set(Iterador<T> it, const T & t){
    *it = t;
}

template<class T>
T Lista<T>::Get(Iterador<T> it){
    return *it;
}

template<class T>
Iterador<T> Lista<T>::Borrar(Iterador<T> it){
    assert(it.ptr != _ultima);
    Celda<T> * c = it.ptr->sig;
    it.ptr->sig = c->sig;
    if(c == _ultima) _ultima = it.ptr;
    delete c;
    return it;
}

template<class T>
Iterador<T> Lista<T>::Insertar(Iterador<T> it, const T & t){
    Celda<T> * ins = new Celda<T>;
    ins->elem = t;
    ins->sig = it.ptr->sig;     //REVIENTA AQUI Y NO SE POR QUE COJONES
    it.ptr->sig = ins;
    if(it.ptr == _ultima) 
        _ultima = ins;
    return it;
}

