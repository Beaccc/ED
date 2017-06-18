#ifndef __REFRANES__H
#define __REFRANES__H
#include <fstream>
#include <iostream>
#include <unordered_set>
#include <functional>
using namespace std;

/** 
 * @file Refranes.h: TDA Refranes
 * 
 * 
 * 
 */


/**
   @brief T.D.A.Refranes
   
   \b Definición:
   Una instancia \e a del tipo de dato abstracto Refranes es una
   colección de frases tipicas de un idioma, dispuestas de forma 
   ordenada en las que no hay refranes repetidos.
   
   
   
   <tt>\#include Refranes.h</tt>
   
   El espacio requerido para el almacenamiento es O(n), donde n es el número de
   refranes
   
   @author Mario Rodríguez Ruiz
   @date Enero de 2017
*/


class Refranes{
  /**
  * @page repRefranes Rep del TDA Refranes
  *
  * @section invRefranes Invariante de la representación
  *
  * Añadir el invariante de la representación
  *
  * @section faRefranes Función de abstracción
  *
  * Añadir la función de abstracción
  */

  private:
    class my_hash{
        private:
            // número de elementos sobre los que hay que calcular la función hash
            unsigned int len;
        public:
            // Constructor
            my_hash(int l=3):len(l){};

            // Modifica len
            void set_len(int l){
                len = l ;
            }

            size_t operator()(const string & clave) const{
                size_t s = 0 ;
                int ff = 1 ;
                for(unsigned i = 0 ; i < clave.size() ; i++){
                    s = (int)(s+ff*clave[i]) ;
                    ff*=28 ;
                }
                return s ;
            }
    } ;
    
    unordered_set<string,my_hash> ab;
    int len_prefijo;//la longitud del prefijo para definir obtener el valor hash
    int n_ref;
    int caracteres_totales;//numero de caracteres totales

 public:
    /** @brief Constructor por defecto. Inicia len_prefijo a 3
     * */
    Refranes();
    
    /** @brief Constructor por defecto. Inicia len_prefijo a  un valor
     **/
    
    Refranes(int lpre);

    /** @brief Elimina todos los refranes
     */

    ~Refranes();
    
    /** @brief devuelve el numero de refranes alamacenados
     */
    
    int size()const;
    
    /** @brief Inserta un refran en el conjunto 
     * @param r: refran a insertar
     * @note el numero de refranes se incrementa en uno mas
     */
    void Insertar(const string & refran);
    
    /** @brief Borra un refrán en el conjunto 
     * @param r: refran a borrar
     * @note el numero de refranes se decrementa en uno mas
     */
    
    void BorrarRefran(const string &refran);
    
    class iterator; 
    class const_iterator; //declaracion adelantada de los iteradores de refranes
    
    /** @brief Devuelve si un refran esta en el conjunto. Si esta devuelve un iterador a el
     * @param r: refran a buscar
     * @return una pareja que contiene si el refran esta y en caso afirmativo un iterador a el
    */
    pair<bool, iterator> Esta(const string &refran);

    /** @brief Elimina todos los refranes
     */
    void clear();

    /** @brief Devuelve un refrán obtenido de forma aleatoria.
     */
    string ObtenerRefranAleatorio();
    
    /** @brief Lectura/Escritura de un conjunto de refranes
     */
    friend istream & operator>>(istream &is, Refranes &R);
    
    friend ostream & operator<<(ostream &is,const Refranes &R);
    
    /** @brief Devuelve el numero total de los caracteres en todos los refranes
     */
    int Caracteres_Refranes()const;
    
    
    /****************************************/
    class iterator{
        private:
            unordered_set<string,my_hash> :: iterator it ;
        public:
            iterator(){}
            bool operator == (const iterator &i)const;
            bool operator != (const iterator &i)const;
            string operator*() ;
            iterator &operator ++();
            iterator &operator --();

            friend class Refranes;
            friend class const_iterator;
    };


    class const_iterator{
        private:
            unordered_set<string,my_hash> :: const_iterator it ;
        public:
            const_iterator(){}
            bool operator == (const const_iterator &i)const;
            bool operator != (const const_iterator &i)const;
            string operator*() ;
            const_iterator &operator ++();
            const_iterator &operator --();

            friend class Refranes;

    };
    
    /***************BEGIN y END*************/
    
    iterator begin();
    iterator end();
    
    const_iterator begin()const;
    const_iterator end()const;
};

#include "refranes_hash.cpp"

#endif
