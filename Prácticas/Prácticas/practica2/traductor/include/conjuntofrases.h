/**
 * @file conjuntofrases.h
 * @brief Fichero cabecera del TDA ConjuntoFrases
 *
 */

#ifndef CONJUNTOFRASES_H
#define CONJUNTOFRASES_H

#include <iostream>
#include <string>
#include "frases.h"

using namespace std;

/**
*  @brief T.D.A. ConjuntoFrases
*
* Una instancia @e t del tipo de datos abstracto @c ConjuntoFrases es un objeto
* compuesto por un conjunto de frases ordenadas por la frase en el idioma origen.
*
*
* @author Mario Rodríguez Ruiz
* @date Noviembre 2016
*/

class ConjuntoFrases{
    private:
        /**
        * @page repConjunto Rep del TDA ConjuntoFrases
        *
        * @section invConjunto Invariante de la representación
        *
        * El invariante es \e rep.frases_i<rep.frases_j para 0< =i, j < n
        *
        * @section faConjunto Función de abstracción
        *
        * Un objeto válido @e rep del TDA ConjuntoFrases representa al valor
        *
        * (rep.frases)
        *
        */
        Frase *frases ;     /**< Vector con todas las frases junto con sus traducciones */
        int num_frases ;    /**< Número de frases */

        /**
        * @brief Copia los datos de un objeto de tipo ConjuntoFrases
        * @param c objeto tipo ConjuntoFrases que se desea copiar
        * @return Crea una copia del objeto @a c
        */
        void copiarDatos(const ConjuntoFrases &c);

        /**
        * @brief Libera la memoria reservada llamando al destructor.
        *
        * Además de liberar la memoria, también debe poner el número de frases a cero.
        */
        void liberarMemoria() ;

        /**
        * @brief Reserva la memoria que se va a utilizar para guardar frases.
        * @param tamanio entero que especifica el número de frases a guardar.
        * Además de liberar la memoria, también debe poner el número de frases a cero.
        */
        void reservarMemoria(const int tamanio) ;


    public:
        /**
        * @brief Constructor por defecto.
        */
        ConjuntoFrases();

        /**
        * @brief Constructor con parametros.
        * @param datos Vector con todas las frases del diccionario.
        * @return Crea el traductor con todas las frases.
        */
        ConjuntoFrases(const int tamanio);

        /**
        * @brief Constructor de copia.
        * @param c objeto ConjuntoFrases que se desea copiar
        * @return Crea una copia del objeto c
        */
        ConjuntoFrases(const ConjuntoFrases & c);

        /**
        *@brief Libera por defecto la memoria reservada.
        *
        * Invoca a la función liberarMemoria para hacer una limpieza personalizada.
        *
        */
        ~ConjuntoFrases() ;

        /**
        * @brief Tamaño del fichero de frases.
        * @return Devuelve el número de frases que contiene el fichero.
        */
        inline int Size() const{
            return num_frases ;
        }

        /**
        * @brief Insertar frase
        * @param f frase que se quiere introducir en el traductor
        * @return Inserta en el objeto implícito la frase f
        */
        void insertaAlfabeticamente(Frase & f) ;

        /**
        * @brief Entrada de un diccionario de traducciones
        * @param input flujo de entrada
        * @param c ConjuntoFrases que recibe las frases
        * @retval Las frases contenidas en el diccionario de traducciones
        * @pre La entrada tiene el formato frase_origen;frase_destino_0;...;frase_destino_n;\n
        */
        friend istream& operator>>(istream & input, ConjuntoFrases & c);

        /**
        * @brief Salida de un conjunto de frases a un flujo
        * @param flujo flujo de salida
        * @param c Frases a escribir
        * @post Se obtiene en @a flujo la cadena "Frase origen : origen Frases traducidas: traduccion_1 ... traduccion_n"
        * con @e _origen,traduccion_ los valores de frase origen y frases traducidas de @a c
        */
        friend ostream& operator<< (ostream& flujo, ConjuntoFrases &c);

        /**
        * @brief Sobrecarga el operador de asignación
        * @param c es el objeto a copiar
        *
        * Construye un conjunto de frases a partir de @a c
        */
        const ConjuntoFrases & operator = (const ConjuntoFrases & c);

        /**
        * @brief Pasa la cadena a minúscula
        * @param f es la frase a poner en minúscula
        * @return Construye una nueva cadena en minúscula a partir de @a f
        */
        string covierteAminusculas(const string f) ;

        /**
        * @brief Comprueba que una frase se encuentre en el diccionario.
        * @param f Frase a buscar en el diccionario.
        * @retval true si la frase @a f existe, false en caso contrario.
        */
        bool Esta(string f) ;

        /**
        * @brief Obtener traducciones de una frase.
        * @param f es la frase a buscar dentro del diccionario.
        *
        * Devuelve un objeto @c Frase donde se encuentra el origen @a f con todas las traducciones
        * encontradas.
        */
        Frase GetTraducciones(string f) ;

        /**
        * @brief Encuentra las frases que contengan una cadena especificada.
        * @param f es la cadena que debe contener las frases a buscar.
        *
        * Devuelve un objeto ConjuntoFrases en la que cada frase contiene la cadena @a f
        */
        ConjuntoFrases Contenga(const string f) ;

};


#endif /* CONJUNTOFRASES_H */

