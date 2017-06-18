 
/** @file ArbolGeneral.cpp
 *  @brief Implementación del ArbolGeneral
 *
 *  @author Mario Rodríguez Ruiz
 *  @date Diciembre 2016
 */

#ifndef NULL
#define NULL (void *)0
#endif

#ifndef __ArbolGeneral_cpp__
#define __ArbolGeneral_cpp__

#include "ArbolGeneral.h"

/*******************************
*      Métodos privados        *
*******************************/

template<class Tbase>
void ArbolGeneral<Tbase>::destruir(nodo * n){
    // Si n es válido
    // se destruye recursivamente el subárbol del hijo a la izquierda
    // y el subarbol del hermano a la derecha
    if(n != 0){
        destruir(n->izqda);
        destruir(n->drcha);
        delete n;
    }
}

//--------------------------------------------------------------------

template<class Tbase>
void ArbolGeneral<Tbase>::copiar(nodo *& dest, nodo * orig){
    // Si orig está vacío se borra en dest.
    if (orig==0)
        dest= 0;
    else {
        dest= new nodo;
        dest->etiqueta= orig->etiqueta;
        copiar (dest->izqda,orig->izqda);
        copiar (dest->drcha,orig->drcha);
        if (dest->izqda!=0)
            dest->izqda->padre= dest;
        if (dest->drcha!=0)
            dest->drcha->padre= dest;
    }
}

//--------------------------------------------------------------------

template<class Tbase>
int ArbolGeneral<Tbase>::contar(const nodo * n) const{
    if (n==0)
        return 0;
    else
        return 1+contar(n->izqda)+contar(n->drcha);
}

//--------------------------------------------------------------------

template<class Tbase>
bool ArbolGeneral<Tbase>::soniguales(const nodo * n1, const nodo * n2) const{
    // Si los nodos son ambos nulos o validos se continua.
    if( (n1 != NULL) == (n2 != NULL)){
        if(n1){
            // Se comprueba que las etiquetas no son iguales.
            // se rompe la recursividad si lo fueran.
            if(n1->etiqueta != n2->etiqueta){
                return false;
            }
            // Hijo-izquierda
            if(!soniguales(n1->izqda, n2->izqda))
                // Rompe si no son iguales
                return false;
            // Hermano-derecha
            if(!soniguales(n1->drcha, n2->drcha))
                return false;

        }
        // Si se llega a este punto es que los subarboles son iguales.
        return true;
    }

    else
        return false;
}

/******************************
*       Constructores         *
******************************/

template<class Tbase>
ArbolGeneral<Tbase>::ArbolGeneral(){
    laraiz = 0;
}

//--------------------------------------------------------------------

template<class Tbase>
ArbolGeneral<Tbase>::ArbolGeneral(const Tbase& e){
    laraiz = new nodo(e);
}

//--------------------------------------------------------------------

template<class Tbase>
ArbolGeneral<Tbase>::ArbolGeneral(const ArbolGeneral<Tbase>& v){
    copiar (laraiz,v.laraiz);
    if (laraiz!=0)
        laraiz->padre= 0;
}

//--------------------------------------------------------------------

template<class Tbase>
ArbolGeneral<Tbase>::~ArbolGeneral(){
    destruir(laraiz);
}

/********************************
*       Métodos publicos        *
********************************/


//--------------------------------------------------------------------

template <class Tbase>
void ArbolGeneral<Tbase>::escribe_arbol(std::ostream & out, nodo *nod) const
{
    if (nod==0)
        out << "x ";
    else {
        out << "n "<< nod->etiqueta << " ";
        escribe_arbol(out,nod->izqda);
        escribe_arbol(out,nod->drcha);
    }
}


//--------------------------------------------------------------------

template <class Tbase>
void ArbolGeneral<Tbase>::lee_arbol(istream& in, nodo*& nod)
{
    char c;
    in >> c;
    if (c=='n')
    {
        nod= new nodo;
        in >> nod->etiqueta;
        lee_arbol(in,nod->izqda);
        lee_arbol(in,nod->drcha);
        if (nod->izqda!=0)
            nod->izqda->padre=nod;
        if (nod->drcha!=0)
            nod->drcha->padre=nod;
    }
    else
        nod= 0;
}

//--------------------------------------------------------------------

template<class Tbase>
ArbolGeneral<Tbase>& ArbolGeneral<Tbase>::operator=(const ArbolGeneral<Tbase> & v){
    if (this!=&v){
        destruir(laraiz);
        copiar (laraiz,v.laraiz);
        if (laraiz!=0)
            laraiz->padre= 0;
    }
    return *this;
}

//--------------------------------------------------------------------

template<class Tbase>
void ArbolGeneral<Tbase>::AsignaRaiz(const Tbase & e){
    destruir(laraiz);
    laraiz = new nodo(e);
}

//--------------------------------------------------------------------

template<class Tbase>
typename ArbolGeneral<Tbase>::Nodo ArbolGeneral<Tbase>::raiz() const{
    return laraiz;
}

//--------------------------------------------------------------------

template<class Tbase>
typename ArbolGeneral<Tbase>::Nodo ArbolGeneral<Tbase>::hijomasizquierda(const ArbolGeneral<Tbase>::Nodo n) const{
    return n->izqda;
}

//--------------------------------------------------------------------

template<class Tbase>
typename ArbolGeneral<Tbase>::Nodo ArbolGeneral<Tbase>::hermanoderecha(const ArbolGeneral<Tbase>::Nodo n) const{
    return n->drcha;
}

//--------------------------------------------------------------------

template<class Tbase>
typename ArbolGeneral<Tbase>::Nodo ArbolGeneral<Tbase>::padre(const ArbolGeneral<Tbase>::Nodo n) const{
    return n->padre;
}

//--------------------------------------------------------------------

template<class Tbase>
Tbase& ArbolGeneral<Tbase>::etiqueta(const ArbolGeneral<Tbase>::Nodo n){
    return n->etiqueta;
}

//--------------------------------------------------------------------

template<class Tbase>
void ArbolGeneral<Tbase>::asignar_subarbol(const ArbolGeneral<Tbase>& orig, const ArbolGeneral<Tbase>::Nodo nod){
    destruir(laraiz);
    copiar(laraiz,nod);
    if (laraiz!=0)
        laraiz->padre=0;
}

//--------------------------------------------------------------------

template<class Tbase>
void ArbolGeneral<Tbase>::podar_hijomasizquierda(ArbolGeneral<Tbase>::Nodo n, ArbolGeneral<Tbase>& dest){
    destruir(dest.laraiz);
    dest.laraiz=n->izqda;
    if (dest.laraiz!=0)
    {
        dest.laraiz->padre=0;
        n->izqda=0;
    }
}

//--------------------------------------------------------------------

template<class Tbase>
void ArbolGeneral<Tbase>::podar_hermanoderecha(ArbolGeneral<Tbase>::Nodo n, ArbolGeneral<Tbase>& dest){
    destruir(dest.laraiz);
    dest.laraiz=n->drcha;
    if (dest.laraiz!=0)
    {
        dest.laraiz->padre=0;
        n->drcha=0;
    }
}

//--------------------------------------------------------------------

template<class Tbase>
void ArbolGeneral<Tbase>::insertar_hijomasizquierda(ArbolGeneral<Tbase>::Nodo n, ArbolGeneral<Tbase> & rama){
    destruir(n->izqda);
    n->izqda=rama.laraiz;
    if (n->izqda!=0)
    {
        n->izqda->padre= n;
        rama.laraiz=0;
    }
}

template<class Tbase>
void ArbolGeneral<Tbase>::insertar_hijomasizquierda(ArbolGeneral<Tbase>::Nodo n, Tbase tb){
    destruir(n->izqda);
    ArbolGeneral<Tbase> aux(tb) ;
    n->izqda=aux.laraiz;
    if (n->izqda!=0)
    {
        n->izqda->padre= n;
        aux.laraiz=0;
    }
}

//--------------------------------------------------------------------

template<class Tbase>
void ArbolGeneral<Tbase>::insertar_hermanoderecha(ArbolGeneral<Tbase>::Nodo n , ArbolGeneral<Tbase>& rama){
    destruir(n->drcha);
    n->drcha=rama.laraiz;
    if (n->drcha!=0){
        n->drcha->padre= n->padre;
        rama.laraiz=0;
    }
}

template<class Tbase>
void ArbolGeneral<Tbase>::insertar_hermanoderecha(ArbolGeneral<Tbase>::Nodo n , Tbase tb){
    destruir(n->drcha);
    ArbolGeneral<Tbase> aux(tb) ;
    n->drcha=aux.laraiz;
    if (n->drcha!=0){
        n->drcha->padre= n->padre;
        aux.laraiz=0;
    }
}

//--------------------------------------------------------------------

template<class Tbase>
void ArbolGeneral<Tbase>::clear(){
    destruir(this->laraiz);
    laraiz = 0 ;
}

//--------------------------------------------------------------------

template<class Tbase>
int ArbolGeneral<Tbase>::size() const{
    return contar(laraiz);
}

//--------------------------------------------------------------------

template<class Tbase>
bool ArbolGeneral<Tbase>::empty() const{
    // Se hace así en lugar de con contar() para eficiencia O(1)
    return laraiz == NULL;
}

#endif
