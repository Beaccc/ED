// Mario Rodríguez Ruiz
/*
Se dispone de un conjunto de claves de gran tamaño, que se almacenan de
forma ordenada. La particularidad de este conjunto es que las claves pueden aparecer de
forma consecutiva un numero indefinido de veces. Por ej:
    { 1,1,1,1,1,3,3,3,6,6,6,6,6,6,6,6,9,9,9,9,9,.....}
a) Para el acceso a las claves se pretende diseñar un TDA con la misma especificación
del vector de la STL, sin embargo se busca una representación que almacene los datos
con un espacio de memoria proporcional al número de claves distintas existentes. ¿Qué
representación propondrías?
b) Considerando dicha representación, construye una función que dada una posición i del
vector original devuelva el valor almacenado en esa posición.

*/

#include <iostream>
#include <list>
#include <ctime>
#include <cstdlib>
using namespace std;

/*
 *
 *
 // Aqui os dejo una funcion para realizar la unión de dos listas.

template <class T>
list<T>  Union(const list<T> &l1,const list<T> &l2){
      typename list<T>::const_iterator it2;
      list<T>l3(l1);//construimos l3 como copia de l1

      //insertamos los de l2
      for (it2=l2.begin();it2!=l2.end();it2++)
            l3.insert(l3.end(),*it2);

      //ordenamos
      l3.sort();
      //quitamos los repetidos
      l3.unique();
      return l3;

}


// Aqui os paso un codigo para realizar la intersección de dos listas.

template <class T>
bool Esta(const list <T> &l,const T & d){
   typename list<T>::const_iterator it;
   for (it=l.begin();it!=l.end();++it)
     if (*it==d) return true;
   return false;
}


template <class T>
list<T>  Interseccion(const list<T> &l1,const list<T> &l2){
      typename list<T>::const_iterator it2;
      list<T>l3(l1);//construimos l3 como copia de l1

      //insertamos los de l2 que esten en l1
      for (it2=l2.begin();it2!=l2.end();it2++)
      if (l3.Esta(*it2))
        l3.insert(l3.end(),*it2);

      return l3;

}
*/

/**
 * @brief Imprime una lista de tipo T sobre el flujo de salida
 * @param s: flujo de salida. Es MODIFICADO
 * @param l: la lista con los elementos a imprimi
 * */
template <class T>
ostream & operator<<(ostream & s, const list<T> & l){

  typename list<T>::const_iterator i;
  
  for (i=l.begin(); i != l.end(); i++)
      s << (*i) << " ";
  
  return s;
}

/**
 * @brief Inicializar el generador de numero aleatorios
 *        Esta funcion debe ser llamada antes de usar rand
**/

void InicializarSemilla(){
  srand(time(0));
}

struct letra{
	char let;
	float apariciones;
};

ostream & operator<<(ostream & s, const letra &l){
  	s << "Letra: " << l.let << " - apariciones: " << l.apariciones << endl;
  	return s;
}

/**
 * @brief Genera numero enteros positivos aleatorios en el rango [min,max]
**/

int generaEntero(int min, int max){
    int tam= max -min+1;
    return ((rand()%tam)+min);
}

// Crea el abecedario con apariciones aleatorias para cada letra
void creaAbecedario(list<letra> & l){
    letra nueva ;
	
	for(char car = 'a' ; car <= 'z' ; car++){
		nueva.let = car ;
		nueva.apariciones = generaEntero(1,10);
		l.push_back(nueva);
	}
}

/*
Sustituir el número de apariciones de una letra por la frecuencia relativa 
(frecuencia_relativa= apariciones*100/total_apariciones, siendo total_apariciones 
la sumatoria del numero de apariciones de cada letra es decir ∑l ∈[A-Z]aparicionesl).
*/

int totalApariciones(list<letra> & l){
	int total = 0 ;
	list<letra>::iterator it;
	
	for(it = l.begin(); it != l.end(); ++it){
		total += it->apariciones ;
	}
	
	return total ;
}

// Lista frecuencia relativa
void frecuenciaRelativa(list<letra> & l){
	list<letra>::iterator it;
	float frecRelativa = 0 ;
	//cout << "total apariciones:" << endl ;
	//cout << totalApariciones(l) << endl ;
	for(it = l.begin(); it != l.end(); ++it){
		frecRelativa = it->apariciones*100/totalApariciones(l);
		it->apariciones = frecRelativa ;
	}
}

bool estaFrecRelativa(const letra& l1, const letra& l2){
	bool before = false;

	if(l1.apariciones > l2.apariciones){
		before = true;
	}
	return before;
} 

// Ordenar la lista por la frecuencia relativa
void ordenaPorFrecuenciaRelativa(list<letra> & l){	
	frecuenciaRelativa(l) ;
	l.sort(estaFrecRelativa);
}

void creaListaFrecuentes(list<letra> & nueval, list<letra> & masf, const int num){	
	letra nueva ;
	list<letra>::iterator it;
	
	unsigned int i = 0;
	for(it = nueval.begin(); i < 10; ++it,i++){
		nueva.let = it->let ;
		nueva.apariciones =	it->apariciones ;
		masf.push_back(nueva);
	}
}

int main(){
  
	list<letra> l;	   	

	InicializarSemilla();
	creaAbecedario(l) ;  	
	
	// Abecedario inicial
	cout << "Abecedario inicial:" << endl ;
	cout<<endl<<l;	
	
	cout << "\nAbecedario con frecuencia relativa:" << endl ;
	frecuenciaRelativa(l) ;
	cout<<endl<<l;
	
	list<letra> nueval;
	cout << "\nAbecedario ordenado por frecuencia relativa:" << endl ;
	creaAbecedario(nueval) ; 	
	ordenaPorFrecuenciaRelativa(nueval);
	cout<<endl<<nueval;
	
	
	// Crea una lista nueva con las 10 más frecuentes
	list<letra> masf;
	cout << endl << "10 letras más frecuentes: " << endl;
	creaListaFrecuentes(nueval, masf, 10) ;	
	cout<<endl<<masf;
}  
  
  
  
  
  
  
  
  
