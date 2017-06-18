// Mario Rodríguez Ruiz
#include <iostream>
#include <list>
#include <ctime>
#include <cstdlib>
#include <queue>
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
      s << (*i) << " " << endl;

  return s;
}

/**
 * @brief Inicializar el generador de numero aleatorios
 *        Esta funcion debe ser llamada antes de usar rand
**/

void InicializarSemilla(){
  srand(time(0));
}


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

// void Invertir(const list<int> & lsource, list<int>& ldestino){
//     list<int>::const_reverse_iterator iter(lsource.rbegin()), iter_end(lsource.rend()) ;
//
//     while (iter != iter_end){
//         ldestino.push_back(*iter) ;
//         ++iter ;
//     }
// }

// // Crea lista de enteros con números aleatorios
// void creaLista(list<int> & l){
// 	for(int i = 0 ; i < 10 ; i++){
// 		l.push_back(i);
// 	}
// }
// void Invertir(const list<int> & lsource, list<int>& ldestino){
//     list<int>::const_reverse_iterator iter(lsource.rbegin()), iter_end(lsource.rend()) ;
//
//     while (iter != iter_end){
//         ldestino.push_back(*iter) ;
//         ++iter ;
//     }
// }

struct alumno{
	string dni ;
    string nombre;
    string apellidos;
    string correo;
    double nota_selectividad;
};

bool operator <(const alumno &a1, const alumno &a2){
    if(a1.nota_selectividad < a2.nota_selectividad)
        return true ;
    return false ;
}

void ObtenerPrioridad (const list<alumno> & alumnos, priority_queue<alumno>  & pq){
    list<alumno>::const_iterator it;

	for(it = alumnos.begin(); it != alumnos.end(); ++it){
		pq.push(*it) ;
	}
}




ostream & operator<<(ostream & s, const alumno &al){
  	s << "Alumno: " << al.nombre << "\nApellidos: " << al.apellidos << "\nNota Selectividad: " << al.nota_selectividad << endl;
  	return s;
}


int main(){
    list<alumno> listaAl ;
    alumno al1, al2, al3 ;

	al1.dni = "74737144a" ;
    al1.nombre = "Mario" ;
    al1.apellidos = "Rodríguez" ;
    al1.correo = "uncorreo" ;
    al1.nota_selectividad = 5.9 ;

    al2.dni = "7473as4a" ;
    al2.nombre = "Mgasg" ;
    al2.apellidos = "hasas" ;
    al2.correo = "asdg" ;
    al2.nota_selectividad = 3.2 ;

    al3.dni = "7174444a" ;
    al3.nombre = "Fafelpaf" ;
    al3.apellidos = "Stadtd" ;
    al3.correo = "corro" ;
    al3.nota_selectividad = 9.5 ;

    listaAl.push_back(al1) ;
    listaAl.push_back(al2) ;
    listaAl.push_back(al3) ;

	
    cout<< listaAl << endl;

    priority_queue<alumno> pri ;

    ObtenerPrioridad(listaAl, pri) ;

    int size = pri.size();
    for (int i = 0; i < size; ++i)
    {
        cout<<pri.top() << endl ;
        pri.pop();
    }
	
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
  
  
  
  
  
  
  
  
