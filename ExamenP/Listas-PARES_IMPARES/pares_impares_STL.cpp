/*
 *  Ejercicio:
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
#include <string>
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
      s << (*i) ;

  return s;
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

int generaEntero(int min, int max){
    int tam= max -min+1;
    return ((rand()%tam)+min);
}


struct numero{
	int num;
	int apariciones;
};

ostream & operator<<(ostream & s, const numero &nume){


     s << "Numero: " << nume.num << " - apariciones: " << nume.apariciones << endl;

  return s;
}

void insertaEntero(list<numero> & l){
    int ent = (generaEntero(1,100));             //crea un par con valor y apariciones aleatorios
    numero nuevo ;
    nuevo.num = ent ;
    list<numero>::iterator it ;
    bool esta = false;
    for(it = l.begin();it != l.end() && !esta; ++it){ //Buscamos si ya esta en la lista para añadir apariciones
        if(it->num == ent){
            ++it->apariciones ;
            esta = true;;                   //rompemos el bucle
        }
    }
    if(!esta){
        nuevo.apariciones = 1 ;//si no esta lo añadimos nuevo
        l.push_back(nuevo);
    }

}


int main(){
  
    list<numero> lista;

    InicializarSemilla();

    //crear la primera lista
    for (int i=0;i<30;i++)
        insertaEntero(lista);   //Inserta un entero con apariciones.

    cout << lista ;

/*
    list<numero>::const_iterator const_it;

	cout << endl << "Lista inicial: " << endl;
	for(const_it = lista.begin(); const_it != lista.end(); ++const_it){
		cout << "Numero: " << const_it->num << " - apariciones: " << const_it->apariciones << endl;
	}*/


//     //Creamos las listas con los pares y las listas con los impares
//     list<par> pares;
//     list<par> impares;
//     separaParesImpares(l, pares, impares);
//     cout << "Lista de pares\n";
//     cout << pares << endl;
//     cout << "Lista de impares\n";
//     cout << impares << endl;
//
//     //Ordenamos las listas
//     pares.sort(mycompval);
//     impares.sort(mycompval);
//     cout << "Lista de pares ordenados por valor\n";
//     cout << pares << endl;
//     cout << "Lista de impares ordenados por valor\n";
//     cout << impares << endl;
//
//     //Sacamos los 10 pares mas frecuentes
//     list<par> frecuentes(diezMasFrecuentes(pares));
//     cout << "Lista de diez pares mas frecuentes\n";
//     cout << frecuentes << endl;
  
  
}  
  
  
  
  
