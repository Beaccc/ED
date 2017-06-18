#ifndef __Diccionario_h__
#define __Diccionario_h__

#include <cassert>
#include <iostream>
#include <fstream>
#include <map>
#include <list>
using namespace std;

/**
   @brief T.D.A. Diccionario

   @author Mario Rodríguez Ruiz
   @date Diciembre 2016
*/

class Diccionario{
/**
  * @page repDiccionario Rep del TDA Arbol General
  *
  * @section invDiccionario Invariante de la representación
  *
  * Añadir el invariante de la representación
  *
  * @section faDiccionario Función de abstracción
  *
  * Añadir la función de abstracción
  */

    private:
        map<int, list<string> > datos;

    public:
        /**
        * @brief Constructor por defecto
        *
        */
        Diccionario();
//
        /**
        * @brief Destructor
        *
        *
        */
        ~Diccionario();

        Diccionario & operator=(const Diccionario &d) ;

        void Insertar(const int &clave, const list<string> &l) ;

        friend ostream & operator <<(ostream &out, const Diccionario &d) ;

        friend ostream & operator <<(ostream &out, const list<string> &l) ;

        /**
        * @brief TDA. Iterador en preorden
        * */
        class const_iterator;//declaracion adelantada
        class iterator{
            private:
                map<int, list<string> >::iterator it;
            public:
                iterator(){}

                pair<int, list<string>> operator*(){
                    return *it;
                }

                iterator & operator ++(){
                    ++it ;
                    while((*it).first%2==0){
                        ++it ;
                    }
                    return *this ;
                }

                iterator & operator --(){
                    --it ;
                    while((*it).first%2==0){
                        --it ;
                    }
                    return *this ;
                }

                bool operator == (const iterator &i)const{
                    return i.it == it ;
                }

                bool operator != (const iterator &i)const{
                    return i.it != it ;
                }

                friend class Diccionario;
                friend class const_iterator;
        };


        class const_iterator{
            private:
                map<int, list<string> >::const_iterator it;
            public:
                const_iterator(){}

                pair<int, list<string>> operator*(){
                    return *it;
                }

                const_iterator & operator ++(){
                    ++it ;
                    while((*it).first%2==0 && it != datos.end()){
                        ++it ;
                    }
                    return *this ;
                }

                bool operator == (const const_iterator &i)const{
                    return i.it == it ;
                }

                bool operator != (const const_iterator &i)const{
                    return i.it != it ;
                }

                friend class Diccionario;
        };



        iterator begin(){
            iterator i;
            i.it = datos.begin() ;
            return i ;
        }

        iterator end(){
            iterator i;
            i.it = datos.end() ;
            return i ;
        }

        const_iterator begin()const{
            const_iterator i;
            i.it = datos.begin() ;
            return i ;
        }

        const_iterator end()const {
            const_iterator i;
            i.it = datos.end() ;
            return i ;
        }
};

#endif
