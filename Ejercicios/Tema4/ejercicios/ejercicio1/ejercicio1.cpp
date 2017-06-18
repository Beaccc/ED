// Mario Rodríguez Ruiz
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

// struct letra{
// 	char let;
// 	float apariciones;
// };
//
// ostream & operator<<(ostream & s, const letra &l){
//   	s << "Letra: " << l.let << " - apariciones: " << l.apariciones << endl;
//   	return s;
// }
//
// /**
//  * @brief Genera numero enteros positivos aleatorios en el rango [min,max]
// **/
//
// int generaEntero(int min, int max){
//     int tam= max -min+1;
//     return ((rand()%tam)+min);
// }
//
// // Crea el abecedario con apariciones aleatorias para cada letra
// void creaAbecedario(list<letra> & l){
//     letra nueva ;
//
// 	for(char car = 'a' ; car <= 'z' ; car++){
// 		nueva.let = car ;
// 		nueva.apariciones = generaEntero(1,10);
// 		l.push_back(nueva);
// 	}
// }
//
// /*
// Sustituir el número de apariciones de una letra por la frecuencia relativa
// (frecuencia_relativa= apariciones*100/total_apariciones, siendo total_apariciones
// la sumatoria del numero de apariciones de cada letra es decir ∑l ∈[A-Z]aparicionesl).
// */
//
// int totalApariciones(list<letra> & l){
// 	int total = 0 ;
// 	list<letra>::iterator it;
//
// 	for(it = l.begin(); it != l.end(); ++it){
// 		total += it->apariciones ;
// 	}
//
// 	return total ;
// }
//
// // Lista frecuencia relativa
// void frecuenciaRelativa(list<letra> & l){
// 	list<letra>::iterator it;
// 	float frecRelativa = 0 ;
// 	//cout << "total apariciones:" << endl ;
// 	//cout << totalApariciones(l) << endl ;
// 	for(it = l.begin(); it != l.end(); ++it){
// 		frecRelativa = it->apariciones*100/totalApariciones(l);
// 		it->apariciones = frecRelativa ;
// 	}
// }
//
// bool estaFrecRelativa(const letra& l1, const letra& l2){
// 	bool before = false;
//
// 	if(l1.apariciones > l2.apariciones){
// 		before = true;
// 	}
// 	return before;
// }
//
// // Ordenar la lista por la frecuencia relativa
// void ordenaPorFrecuenciaRelativa(list<letra> & l){
// 	frecuenciaRelativa(l) ;
// 	l.sort(estaFrecRelativa);
// }
//
// void creaListaFrecuentes(list<letra> & nueval, list<letra> & masf, const int num){
// 	letra nueva ;
// 	list<letra>::iterator it;
//
// 	unsigned int i = 0;
// 	for(it = nueval.begin(); i < 10; ++it,i++){
// 		nueva.let = it->let ;
// 		nueva.apariciones =	it->apariciones ;
// 		masf.push_back(nueva);
// 	}
// }

// ostream & operator<<(ostream & s, const lista &l){
//   	s << "Letra: " << l.let << " - apariciones: " << l.apariciones << endl;
//   	return s;
// }

// Crea lista de enteros con números aleatorios
void creaLista(list<int> & l){
	for(int i = 0 ; i < 10 ; i++){
		l.push_back(i);
	}
}

void Invertir(const list<int> & lsource, list<int>& ldestino){
    list<int>::const_reverse_iterator iter(lsource.rbegin()), iter_end(lsource.rend()) ;

    while (iter != iter_end){
        ldestino.push_back(*iter) ;
        ++iter ;
    }
}


int main(){
  
	list<int> l, invertida;

	InicializarSemilla();
	creaLista(l) ;
	
	// Abecedario inicial
	cout << "Lista inicial:" << endl ;
	cout<<endl<<l << endl;

    cout << "Invertida:" << endl ;
    Invertir(l, invertida) ;
    cout<<endl<<invertida << endl;
	
// 	cout << "\nAbecedario con frecuencia relativa:" << endl ;
// 	frecuenciaRelativa(l) ;
// 	cout<<endl<<l;
//
// 	list<letra> nueval;
// 	cout << "\nAbecedario ordenado por frecuencia relativa:" << endl ;
// 	creaAbecedario(nueval) ;
// 	ordenaPorFrecuenciaRelativa(nueval);
// 	cout<<endl<<nueval;
//
//
// 	// Crea una lista nueva con las 10 más frecuentes
// 	list<letra> masf;
// 	cout << endl << "10 letras más frecuentes: " << endl;
// 	creaListaFrecuentes(nueval, masf, 10) ;
// 	cout<<endl<<masf;
}  
  
  
  
  
  
  
  
  
