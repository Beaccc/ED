//
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

struct pais{
	string nombre;
	int poblacion;
	int superficie;
};

bool ordenarPoblacion(const pais& p1, const pais& p2){
	bool before = false;

	if(p1.poblacion > p2.poblacion){
		before = true;
	}
	return before;
}

bool ordenarDensidad(const pair< string, float>& p1, const pair< string, float>& p2){
	bool before = false;

	if(p1.second > p2.second){
		before = true;
	}
	return before;
}



int main(){


	list<pais> l;
	pais p;
	p.nombre = "Peru"; l.push_back(p);
	p.nombre = "Spain"; l.push_back(p);
	p.nombre = "Chile"; l.push_back(p);
	p.nombre = "Chipre"; l.push_back(p);
	p.nombre = "Japon"; l.push_back(p);
	p.nombre = "Corea"; l.push_back(p);
	p.nombre = "Fiji"; l.push_back(p);
	p.nombre = "Brasil"; l.push_back(p);
	p.nombre = "Francia"; l.push_back(p);
	p.nombre = "Congo"; l.push_back(p);


	InicializarSemilla();

	list<pais>::iterator it;
	//Introducimos datos iniciales
	cout << endl << "Datos iniciales: " << endl;
	for(it = l.begin(); it != l.end(); ++it){
		it->poblacion = generaEntero(1,10000);
		it->superficie = generaEntero(1,10000);
		cout << "Pais: " << it->nombre << " - Poblacion: " << it->poblacion << " - Superficie:"<< it->superficie << endl;
	}


//1. Ordenar la lista por población
	l.sort(ordenarPoblacion);//Ordenamos la lista por población.
	list<pais>::const_iterator const_it;

	cout << endl << "Ordenado por población: " << endl;
	for(const_it = l.begin(); const_it != l.end(); ++const_it){
		cout << "Pais: " << const_it->nombre << " - Poblacion: " << const_it->poblacion << " - Superficie:"<< const_it->superficie << endl;
	}


//2. Construir una nueva lista de pares (pais,densidad_poblacion), siendo densidad_poblacion=poblacion/superficie

	list< pair< string, float> > l2;

	for(const_it = l.begin(); const_it != l.end(); ++const_it){
		l2.push_back(make_pair(const_it->nombre, (const_it->poblacion/(float)(const_it->superficie))));
	}



	list< pair< string, float> >::const_iterator const_it2;
	cout << endl << "Paises y sus densidades de poblacion: " << endl;
	for(const_it2 = l2.begin(); const_it2 != l2.end(); ++const_it2){
			cout << "Pais: " << const_it2->first << " - Densidad de poblacion: " << const_it2->second << endl;
	}
//3.Mostrar los dos paises mas densamente poblados (mayor densidad_poblacion).
	l2.sort(ordenarDensidad);
	cout << endl << "2 paises con mayor densidad de poblacion: " << endl;
	unsigned int i = 0;
	for(const_it2 = l2.begin(); i<2; ++const_it2){
			cout << "Pais: " << const_it2->first << " - Densidad de poblacion: " << const_it2->second << endl;
			i++;
	}
//4. Mostrar los dos paises menos densamente poblados (menor densidad_poblacion).

	l2.sort(ordenarDensidad);
    list< pair< string, float> >::const_iterator const_it4;
    cout << endl << "Ordenado por densidad: " << endl;
	for(const_it4 = l2.begin(); const_it4 != l2.end(); ++const_it4){
		cout << "Pais: " << const_it4->first << " - Densidad de poblacion: " << const_it4->second << endl;
	}

    list< pair< string, float> >::const_reverse_iterator const_it3;
	cout << endl << "2 paises con menor densidad de poblacion: " << endl;
	i = 0;
	for(const_it3 = l2.rbegin(); i<2; ++const_it3){
			cout << "Pais: " << const_it3->first << " - Densidad de poblacion: " << const_it3->second << endl;
			i++;
	}
}
