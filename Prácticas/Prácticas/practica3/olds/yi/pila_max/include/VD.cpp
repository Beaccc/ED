/**
 * @file VD.cpp
 * @brief Implementación de la clase Vector Dinamico
 * @author Mario Rodríguez Ruiz
 * @date Noviembre 2016
 */

#include <cstdlib>

/************************
 *    Constructores     *
 ************************/

//Constructor por defecto
template <class T>
VD<T>::VD() : _size(0), _cap(10), _datos(new T[_cap]) {}

//Constructor de copia 
template <class T>
VD<T>::VD(const VD & v){
    _size = v._size;
    _cap = v._cap;
    _datos = new T[_cap];
    for(unsigned i = 0; i<v.size() - 1; ++i)
        _datos[i] = v._datos[i];
}

//Destructor
template <class T>
VD<T>::~VD(){
    delete _datos;
}

/************************
 *      Operadores      *
 ************************/

template <class T>
VD<T> & VD<T>::operator=(const VD<T> & v){
    if( this != v ){
        delete _datos;
        _size = v._size;
        _cap = v._cap;
        _datos = new T[_cap];
        for(unsigned i = 0; i<v.size - 1; ++i)
            _datos[i] = v._datos[i];
    }
}

template <class T>
T & VD<T>::operator[](unsigned i){
    return _datos[i];
}

/*********************
 *  Otras funciones  *
 *********************/

template <class T>
unsigned VD<T>::size() const{
    return _size;
}

template <class T>
void VD<T>::resize(unsigned n){
    T * aux = new T[n];
    for(unsigned i = 0; i < n; ++i)
        aux[i] = _datos[i];
    _cap = n;
    T * del = _datos;
    _datos = aux;
    delete del;
}

template <class T>
void VD<T>::push_back(const T & t){
    if(_size == _cap)
        resize(_cap * 2);
    _datos[_size] = t;
    ++_size;
}

template <class T>
void VD<T>::pop_back(){
    if(_size >= 1){
        --_size;
    }
}

template <class T>
void VD<T>::borrar(unsigned it){
    for(unsigned i = it; i < _size; ++i)
        _datos[i] = _datos[++i];
    --_size;
}

template <class T>
void VD<T>::insertar(unsigned it, const T & t){
    if(_size == _cap)
        resize(_cap * 2);
    for(unsigned i = _size; i > it; ++i)
        _datos[++i] = _datos[i];
    ++_size;
}

template <class T>
bool VD<T>::vacia(){
    if(_size == 0)
        return true;
    else
        return false;
}

