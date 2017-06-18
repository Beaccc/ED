// Mario Rodríguez Ruiz
/*
 Usando la clase list<T>, construye la siguiente función que permite
"duplicar" una lista (intercalando alternativamente tras cada elemento en la posición i, el
elemento que está en la posición n-i-1 (i=0,1,...,n-1).
template <typename T>
void duplicar(const list<T> & inicial, list<T> & final)
    Ejemplo 1:
        Lista inicial: (a,b,c,d)
        Lista final: (a,d,b,c,c,b,d,a)
    Ejemplo 2:
        Lista inicial: (1,2,3,4,5)
        Lista final: (1,5,2,4,3,3,4,2,5,1)

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

char generaLetra(){
    int tam= 'a' - 'z' + 1;
    return ((rand()%tam)+'a');
}

// Crea el abecedario con apariciones aleatorias para cada letra
void creaAbecedario(list<char> & l){
    int tam = generaEntero(4, 9) ;

    for(int i = 0 ; i < tam ; i ++){
        l.push_back(generaLetra()) ;
    }
}

void creaListaDeNumeros(list<int> & l){
//     int tam = generaEntero(1, 5) ;

    for(int i = 1 ; i < 6 ; i ++){
        l.push_back(i) ;
//         l.push_back(generaEntero(1,tam)) ;
    }
}

template <typename T>
T DevuelveValor(const list<T> c, const unsigned pos){
    typename list<T>::const_iterator it ;
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

template <typename T>
void duplicar(const list<T> & inicial, list<T> & final)
{
    unsigned n = inicial.size() ;
    for(unsigned i =  0 ; i < n ; i++){
        final.push_back(DevuelveValor(inicial, i)) ;
        final.push_back(DevuelveValor(inicial, n-i-1)) ;
    }
}

int main(){
  
	list<char> lc;
    list<int> ln ;

	InicializarSemilla();
	creaAbecedario(lc) ;
    creaListaDeNumeros(ln) ;
	
	// Abecedario inicial
	cout << "Abecedario inicial:" << endl ;
	cout << endl << lc << endl ;

    cout << "Lista de números inicial:" << endl ;
	cout << endl << ln << endl ;;
	
    list<int> lnf ;

    duplicar(ln, lnf) ;

    list<char> lcf ;

    duplicar(lc, lcf) ;

	cout << "\nLista duplicada:" << endl ;
    cout << endl << lnf << endl ;

    cout << "\nLista duplicada:" << endl ;
    cout << endl << lcf << endl ;

}  
  
  
  
  
  
  
  
  
