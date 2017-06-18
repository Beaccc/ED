/**
 * @file traductor.h
 * @brief Fichero cabecera del TDA Traductor
 *
 * @author Mario Rodríguez Ruiz
 * @date Noviembre 2016
 *
 */

#ifndef TRADUCTOR_H
#define TRADUCTOR_H

#include <iostream>
#include <string>
#include <map>
#include "frases.h"

using namespace std;

/**
*  @brief T.D.A. Traductor
*
* Una instancia @e t del tipo de datos abstracto @c Traductor es un objeto
* compuesto por un conjunto de frases ordenadas por la frase en el idioma origen.
*
*
* @author Mario Rodríguez Ruiz
* @date Noviembre 2016
*/

class Traductor{
    private:
        /**
        * @page repConjunto Rep del TDA Traductor
        *
        * @section invConjunto Invariante de la representación
        *
        * El invariante es \e rep.frases_i<rep.frases_j para 0< =i, j < n
        *
        * @section faConjunto Función de abstracción
        *
        * Un objeto válido @e rep del TDA Traductor representa al valor
        *
        * (rep.frases)
        *
        */
        map<string, set<string> > traductor; /**< Objeto de tipo map */

        /**
        * @brief Copia los datos de un objeto de tipo Traductor
        * @param c objeto tipo Traductor que se desea copiar
        * @return Crea una copia del objeto @a c
        */
        void copiarDatos(const Traductor &c);

    public:
        /**
        * @brief Constructor por defecto.
        */
        Traductor();

        /**
        * @brief Constructor con parametros.
        * @param nombre es el nombre del traductor.
        * @param p es la frase.
        * @return Crea el traductor con todas las frases.
        */
        Traductor(Frase f);

        /**
        * @brief Constructor de copia.
        * @param c objeto Traductor que se desea copiar
        * @return Crea una copia del objeto c
        */
        Traductor(const Traductor & c);

        /**
        * @brief Entrada de un diccionario de traducciones
        * @param input flujo de entrada
        * @param c Traductor que recibe las frases
        * @retval frases contenidas en el diccionario de traducciones
        * @pre La entrada tiene el formato frase_origen;frase_destino_0;...;frase_destino_n;\n
        */
        friend istream& operator>>(istream & input, Traductor & c);

        /**
        * @brief Salida de un conjunto de frases a un flujo
        * @param flujo flujo de salida
        * @param c Frases a escribir
        * @post Se obtiene en @a flujo la cadena "Frase origen : origen Frases traducidas: traduccion_1 ... traduccion_n"
        * con @e _origen,traduccion_ los valores de frase origen y frases traducidas de @a c
        */
        friend ostream& operator<< (ostream& flujo, Traductor &c);

        /**
        * @brief Aniade una frase nueva
        * @param p objeto Frase a asignar
        * @return Añade al vector traductor el objeto p
        *
        * Añade una nueva original no existente o solo traducciones si ya existiera.
        */
        void AniadeFrase(Frase &p);

        /**
        * @brief GetFraseInvesa
        * @param des cadena destino a buscar en todo el Traductor
        * @return Devuelve el objeto Frase en el que origen es el párametro @a des y destino
        *       son todas los origenes donde se enecuentre el parametro des como destino.
        */
        Frase GetFraseInversa(string des) const;

        /**
        * @brief Busca una frase a través de una cadena especificada
        * @param c origen del objeto Frase a buscar en el vector
        * @return Devuelve el objeto Frase que hay en el vector.origen que coincide con @a c
        */
        Frase GetFrase(const string c);

        /**
        * @brief GetTraducciones
        * @param c es la frase origen a traducir
        * @return Devuelve un vector string con las traducciones
        */
        vector<string> GetTraducciones(const string c);

        /**
        * @brief Clase para iterar sobre el Traductor
        *
        */
        class const_iterator{
            private:
                map<string, set<string> >::const_iterator it; /**< Iterador de tipo map*/
            public:
                /**
                * @brief Operador++
                * @retval Incrementa el iterador y devuelve el propio objeto
                */
                const_iterator & operator++(){
                    ++it;
                    return *this;
                }
                /**
                * @brief Operador--
                * @retval Decrementa el iterador y devuelve el propio objeto
                */
                const_iterator & operator--(){
                    --it;
                    return *this;
                }

                /**
                * @brief Operador *
                * @retval Devuelve un objeto Frase
                */
                Frase operator *(){
                    Frase p(*it);
                    return p;
                }

                /**
                * @brief Operador ==
                * @param i Interador
                * @retval Devuelve si son iguales los iteradores
                */
                bool operator ==(const const_iterator &i){
                    return i.it==it;
                }

                /**
                * @brief Operador !=
                * @param i Interador
                * @retval Devuelve si son distintos los iteradores
                */
                bool operator !=(const const_iterator &i){
                    return i.it!=it;
                }

                friend class Traductor;
        };

        /**
        * @brief Inicializa un iterator al comienzo del Traductor
        * @return la posición inicial del iterador
        *
        */
        const_iterator begin() const {
            const_iterator i;
            i.it=traductor.begin();
            return i;
        }

        /**
        * @brief Inicializa un iterator al final del Traductor
        * @return la posición final del iterador
        *
        */
        const_iterator end() const {
            const_iterator i;
            i.it=traductor.end();
            return i;
        }

        /**
        * @brief Busca una cadena coincidente en el Traductor
        * @return la posición donde se encuentra la coincidencia.
        *
        */
        const_iterator buscar(string f) {
            const_iterator i;
            i.it=traductor.find(f);
            return i;
        }
};


#endif /* CONJUNTOFRASES_H */

