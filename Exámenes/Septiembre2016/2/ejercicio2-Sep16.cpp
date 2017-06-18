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
#include <set>

using namespace std;



/**
 * @brief Imprime una lista de tipo T sobre el flujo de salida
 * @param s: flujo de salida. Es MODIFICADO
 * @param l: la lista con los elementos a imprimi
 * */
template <class T>
ostream & operator<<(ostream & s, const multiset<T> & l){

  typename multiset<T>::const_iterator i;
  
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


/**
 * @brief Genera numero enteros positivos aleatorios en el rango [min,max]
**/
int generaEntero(int min, int max){
    int tam= max -min+1;
    return ((rand()%tam)+min);
}

// Crea el conjunto con apariciones aleatorias para cada número
void creaConjuto(multiset<int> & c){
    for(int i = 0 ; i < 15 ; i++){
        c.insert(generaEntero(1,9)) ;
    }
}

int DevuelveValor(const multiset<int> c, const unsigned pos){
    multiset<int>::iterator it ;
    int res = -1;
    unsigned i = 0 ;

    if(pos < c.size())
        for (it=c.begin();it!=c.end();++it){
            if(i == pos)
                return *it ;
            else
                i++ ;
        }

    return res ;
}

int main(){
  
	multiset<int> c;
    unsigned pos ;

	InicializarSemilla();
	creaConjuto(c) ;
	
	// Abecedario inicial
	cout << "Conjunto inicial:" << endl ;
	cout << endl << c << endl ;;

    cout << "\nIntroduzca posición a devolver: " ;
    cin >> pos ;

    cout << "\nEn la posición " << pos << " está el valor " << DevuelveValor(c,pos) << endl ;

}  
  
  
  
  
  
  
  
  
