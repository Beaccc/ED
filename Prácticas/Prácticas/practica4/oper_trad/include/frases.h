/**
  * @file frases.h
  * @brief Fichero cabecera del TDA Frase
  *
  * @author Mario Rodríguez Ruiz
  * @date Noviembre 2016
  */

#ifndef FRASES_H
#define FRASES_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <utility>

using namespace std;

/**
 * @brief T.D.A. Frase
 *
 * Una instancia @p c del tipo de datos abstracto @c Frase es un objeto
 * que se compone de una frase en el idioma origen y sus posibles traducciones
 * en el idioma destino.
 *
 * @author Mario Rodríguez Ruiz
 * @date Noviembre 2016
 */

class Frase{
    private:
        /**
        * @page repConjunto Rep del TDA Frase
        *
        * @section invConjunto Invariante de la representación
        *
        * El invariante es @e rep.origen!="" , rep.traduccion!=0 y para todo rep.traduccion[i]!=""
        *
        * @section faConjunto Función de abstracción
        *
        * Un objeto válido @e rep del TDA Frase representa al valor
        *
        * (rep.origen,rep.traduccion[0], ... , rep.traduccion[n-1])
        *
        */

        pair< string, set<string> > datos; /**< objeto Frase que se compone de un pair */

        /**
        * @brief Copia los datos de un objeto de tipo Frase
        * @param f objeto tipo Frase que se desea copiar
        * @return Crea una copia del objeto \a f
        */
        void copiarDatos(const Frase &f);

    public:
        /**
        * @brief Constructor por defecto.
        */
        Frase();
        /**
        * @brief Constructor con parámetros
        * @param tamanio Número de frases
        * @return Crea la frase con una reserva de un número específico de frases.
        */
        Frase(const int tamanio) ;

        /**
        * @brief Constructor con parámetros
        * @param tamanio Número de frases
        * @return Crea la frase con una reserva de un número específico de frases.
        */
        Frase(const pair<string, set<string> > p);

        /**
        * @brief Constructor de copia
        * @param f objeto Frase que se desea copiar
        * @return Crea una copia del objeto f
        */
        Frase(const Frase &f);

        /**
        * @brief Modifica una frase al completo
        * @param origen cadena para asignarle a origen
        * @param destino set de string para asignarle a destino
        * @return Asigna origen y traducciones al objeto frase que lo invoca
        */
        void SetFrase(string origen, set<string>  destino);

        /**
        * @brief Modifica el origen de una frase
        * @param origen cadena para asignarle a origen
        * @return Asigna origen al objeto frase que lo invoca
        */
        void SetOrigenFrase(string origen);

        /**
        * @brief Devuelve el objeto Frase
        *
        */
        pair<string, set<string> > GetFrase();

        /**
        * @brief Devuelve el origen del objeto frase
        *
        */
        string GetFraseOrigen();

        /**
        * @brief Devuelve el destino del objeto frase
        *
        */
        set<string> GetFraseDestino();

        /**
        * @brief Incluir nueva traducción
        * @param trad es la traducción a añadir
        * @return Añade una nueva traducción a la frase
        */
        void AniadeTraduccion(string trad) ;

        /**
        * @brief Sobrecarga el operador de asignación
        * @param f es el objeto a copiar
        *
        * Construye una frase a partir de @a f
        */
        const Frase & operator=(const Frase &f);

        /**
        * @brief Entrada de una Frase desde un flujo
        * @param input flujo de entrada
        * @param f Frase que recibe el valor
        * @retval La frase leida en f
        * @pre El formato de entrada debe ser frase_origen;frase_traduccion_0;...;frase_traduccion_n;
        */
        friend istream& operator>> (istream& input, Frase &f);

        /**
        * @brief Salida de una frase a un flujo
        * @param flujo flujo de salida
        * @param f Frase a escribir
        * @post Se obtiene en @a flujo la cadena "Frase origen : origen Frases traducidas: traduccion_1 ... traduccion_n"
        * con @e _origen,traduccion_ los valores de frase origen y frases traducidas de @a f
        */
        friend ostream& operator<< (ostream& flujo, Frase &f);

        /**
        * @brief Clase para iterar sobre la Frase
        *
        */
        class const_iterator{
            private:
                set<string>::const_iterator it; /**< Iterador de tipo set*/
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
                * @retval Devuelve el tipo de dato que recorre el iterador
                */
                const string &operator *(){
                    return *it;
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

                friend class Frase;

        };

        /**
        * @brief Inicializa un iterator al comienzo de las frases destino
        * @return devuelve la posición del iterador inicial
        *
        */
        const_iterator begin() const {
            const_iterator i;
            i.it=datos.second.begin();
            return i;
        }

        /**
        * @brief Inicializa un iterator al final de las frases destino
        * @return devuelve la posición del iterador final
        *
        */
        const_iterator end() const {
            const_iterator i;
            i.it=datos.second.end();
            return i;
        }



};

#endif  /* FRASES_H */
