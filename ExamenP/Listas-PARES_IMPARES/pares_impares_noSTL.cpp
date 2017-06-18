/*Ejercicio:
Insertar en un lista un conjunto aleatorio de enteros [1-100] junto con un numero indicando el numero de apariciones. Sobre esta lista se pide:
Construir dos nuevas listas, una con los elementos pares y otra con los elementos impares
Ordenar la listas
Construir una nueva lista con los 10 números pares más frecuentes.
Cada uno de los anteriores resultados debe imprimirse en la salida estándar.
*/

#include <iostream>
#include <list>
#include <ctime>
#include <cstdlib>
using namespace std;

/**
 * @brief Imprime una lista de tipo T sobre el flujo de salida
 * @param s: flujo de salida. Es MODIFICADO
 * @param l: la lista con los elementos a imprimi
 * */
template <class T>
ostream & operator<<(ostream & s, const list<T> & l){

  typename list<T>::const_iterator i;
  
  for (i=l.begin(); i != l.end(); i++)
      s << (*i) << "\n";
  
  return s;
}

class par{ //clase par que sustituye al pair de la stl.
    public:
        int first;
        int second;
        par(): first(0), second(0) {};              //constructor por defecto
        par(int a, int b): first(a), second(b) {};  //con parametros
        par(const par & p){                         //de copia
            this->first = p.first;
            this->second = p.second ;
        }
};

ostream & operator<<(ostream & s, const par & p){   //Sobrecarga de operador de salida para la clase par
            s << "(" << p.first << "," << p.second << ")";
           return s;
}

//comparador personalizado para comparar los pares segun las frecuencias (mayor a menor).
bool mycompfrec(const par & p1, const par & p2){
    return p1.second > p2.second;
}

//comparador personalizado para comparar los pares segun los valores (menor a mayor).
bool mycompval(const par & p1, const par & p2){
    return p1.first < p2.first;
}

/**
 * @brief Inicializar el generador de numero aleatorios
 *        Esta funcion debe ser llamada antes de usar rand
**/

void InicializarSemilla(){
  srand(time(0));
}

/**
 * @brief Genera numero enteros positivos aleatorios en el rango [min,max]
**/

par generaEntero(int min, int max){
    int tam= max -min+1;
    return (par((rand()%tam)+min,(rand()%tam)+min));
}

/**
 * @brief Inserta un entero y sus apariciones en una lista teniendo en cuenta
 * si ya ha aparecido anteriormente
 */

void insertaEntero(list<par> & lista){
    par p(generaEntero(1,100));             //crea un par con valor y apariciones aleatorios
    list<par>::iterator it = lista.begin();
    bool esta = false;
    for(;it != lista.end() && !esta; ++it){ //Buscamos si ya esta en la lista para añadir apariciones
        if(it->first == p.first){
            it->second += p.second;
            esta = true;;                   //rompemos el bucle
        }
    }
    if(!esta){                              //si no esta lo añadimos nuevo
        lista.push_back(p);
    }
    
}

//A partir de una lista de pares, crea otras dos, una con los valores pares y otra con los impares.
void separaParesImpares(list<par> orig, list<par> & pares, list<par> & impares){
    list<par>::iterator it = orig.begin();
    for(;it != orig.end(); ++it){
        if(it->first %2 == 0)       //es par
            pares.push_back(*it);
        else                        //es impar
            impares.push_back(*it);
    }
}

//Devuelve una lista con los elementos mas frecuentes a partir de una dada.
list<par> diezMasFrecuentes(list<par> & orig){
    orig.sort(mycompfrec);                  //ordenamos la lista ( O(n) )
    list<par>::iterator it = orig.begin();  //para recorrer la lista origen
    list<par> dest;                         //lista a devolver
    for(unsigned i = 0; i < 10 && it != orig.end(); ++i, ++it){
        dest.push_back(*it);
    }
    return dest;
}


int main(){
  
  list<par> l;
  
  InicializarSemilla();
  
  //crear la primera lista
  for (int i=0;i<30;i++)
    insertaEntero(l);   //Inserta un entero con apariciones.
  cout << "Lista inicial\n";
  cout << l << endl;
  
  //Creamos las listas con los pares y las listas con los impares
  list<par> pares;
  list<par> impares;
  separaParesImpares(l, pares, impares);
  cout << "Lista de pares\n";
  cout << pares << endl;
  cout << "Lista de impares\n";
  cout << impares << endl;
  
  //Ordenamos las listas
  pares.sort(mycompval);
  impares.sort(mycompval);
  cout << "Lista de pares ordenados por valor\n";
  cout << pares << endl;
  cout << "Lista de impares ordenados por valor\n";
  cout << impares << endl;
  
  //Sacamos los 10 pares mas frecuentes
  list<par> frecuentes(diezMasFrecuentes(pares));
  cout << "Lista de diez pares mas frecuentes\n";
  cout << frecuentes << endl;
  
  
}  
  
  
  
  