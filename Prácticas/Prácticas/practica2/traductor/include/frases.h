/**
  * @file frases.h
  * @brief Fichero cabecera del TDA Frase
  *
  */

#ifndef FRASES_H
#define FRASES_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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

        string origen ;         /**< Frase original */
        string *traducciones ;  /**< Distintas traducciones de la original */
        int num_trad ;          /**< Número de traduciones distintas */

        /**
        * @brief Copia los datos de un objeto de tipo Frase
        * @param f objeto tipo Frase que se desea copiar
        * @return Crea una copia del objeto \a f
        */
        void copiarDatos(const Frase &f);

        /**
        * @brief Libera la memoria reservada llamando al destructor.
        *
        * Además de liberar la memoria, también debe poner el número de traducciones a cero.
        */
        void liberarMemoria() ;

        /**
        * @brief Reserva la memoria que se va a utilizar para guardar traducciones.
        * @param tamanio entero que especifica el número de traducciones a guardar.
        * Además de liberar la memoria, también debe poner el número de traducciones a cero.
        */
        void reservarMemoria(const int tamanio) ;

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
        * @brief Constructor de copia
        * @param f objeto Frase que se desea copiar
        * @return Crea una copia del objeto f
        */
        Frase(const Frase &f);

        /**
        * @brief Libera por defecto la memoria reservada.
        *
        * Invoca a la función liberarMemoria para hacer una limpieza personalizada.
        *
        */
        ~Frase();

        /**
        * @brief Frase origen
        * @return Devuelve la frase origen.
        */
        inline string getOrigen() const {
            return origen;
        }

        /**
        * @brief Número de traducciones
        * @return Devuelve el número de traducciones que tiene la frase origen.
        */
        inline int getNumTrads() const {
            return num_trad;
        }

        /**
        * @brief Modifica la frase original.
        * @param f es la frase que será la nueva original.
        *
        */
        inline void setOrigen(string f){
            origen = f ;
        }

        /**
        * @brief Inserta una traducción en una frase
        * @param p traducción que se quiere introducir en el diccionario
        * @return Inserta en el objeto implicito la traduccion \a trad
        */
        void insertaTraduccion(string trad) ;

        /**
        * @brief Traducciones
        * @return Devuelve un vector con las traducciones de la frase
        */
        vector <string> GetDestino() ;

        /**
        * @brief Sobrecarga el operador [] r-value
        * @param pos es la posición de la traducción a devolver
        * @pre la posicion @a pos debe ser un índice válido ( 0 < @a pos > num_trad )
        * @return Devuelve el contenido de traducciones[@a pos]
        *
        */
        string operator[](const int pos) const;

        /**
        * @brief Sobrecarga el operador de asignación
        * @param f es el objeto a copiar
        *
        * Construye una frase a partir de @a f
        */
        const Frase & operator=(const Frase &f);

        /**
        * @brief Operador de igualdad
        * @param f frase a comparar
        * @retval true si son iguales, false en caso contrario.
        */
        const bool operator==(const Frase &f);

        /**
        * @brief Operador de desigualdad
        * @param f frase a comparar
        * @retval true si son desiguales, false en caso contrario.
        */
        const bool operator!=(const Frase &f);

        /**
        * @brief Operador "menor que".
        * @param f frase a comparar
        * @retval true si es menor, false en caso contrario.
        *
        * Devuelve si la frase es alfabéticamente menor que @a f
        */
        const bool operator<(const Frase & f);

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
        friend ostream& operator<< (ostream& flujo, const Frase &f);

};

#endif  /* FRASES_H */
