// Mario Rodríguez Ruiz
/*
Dada una lista de enteros con elementos repetidos, diseña (usando el TDA
list) una función que construya a partir de ella una lista ordenada de listas, de forma que
en la lista resultado los elementos iguales se agrupen en la misma sublista. La lista
original no se ve modificada. Por ejemplo:
si entrada={1,3,4,5,6,3,2,1,4,5,5,1,1,7},salida={{1,1,1},{2},{3,3},{4,4},{5,5,5},{6},{7}


*/

#include <iostream>
#include <list>
#include <ctime>
#include <cstdlib>

using namespace std;

ostream & operator << (ostream &out, const list<int> &l){
    list<int>::const_iterator it ;

    for(it = l.begin() ; it != l.end() ; ++it){
        out << (*it) << ' ' ;
    }
    return out ;
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

// Crea el abecedario con apariciones aleatorias para cada letra
void creaLista(list<int> & l){
//     for(int i = 0 ; i < 15 ; i++)
//         l.push_back(generaEntero(1,7)) ;
    l.push_back(1) ;
    l.push_back(3) ;
    l.push_back(4) ;
    l.push_back(5) ;
    l.push_back(6) ;
    l.push_back(3) ;
    l.push_back(2) ;
    l.push_back(1) ;
    l.push_back(4) ;
    l.push_back(5) ;
    l.push_back(5) ;
    l.push_back(1) ;
    l.push_back(1) ;
    l.push_back(7) ;
}

void creaListaOrdenadaDeListas(const list<int> &orig, list<list<int>> &dest){
    list<int>::const_iterator it_orig ;
    list<list<int>>::iterator it_dest ;
    list<int> aux ;
    bool seguir = true ;
//     int valor ;

    for(it_orig = orig.begin() ; it_orig != orig.end() ; ++it_orig){
        for(it_dest = dest.begin() ; it_dest != dest.end() && seguir; ++it_dest){
            list<int>::const_iterator it ;
            it = (*it_dest).begin() ;
            if((*it) == (*it_orig)){
                (*it_dest).push_back((*it)) ;
                seguir = false ;
            }
        }
        if(seguir){
            aux.clear() ;
            aux.push_back((*it_orig)) ;
            for(it_dest = dest.begin() ; it_dest != dest.end() && seguir; ++it_dest){
                list<int>::const_iterator it ;
                it = (*it_dest).begin() ;
                if((*it_orig) < (*it)){
                    dest.insert(it_dest,aux) ;
                    seguir = false ;
                }
            }
            if(seguir)
                dest.push_back(aux) ;
        }
        seguir = true ;
    }
}

int main(){
  
	list<int> l;
    list<list<int>> ll ;

	InicializarSemilla();
	creaLista(l) ;
	
	// Abecedario inicial
	cout << "Lisa inicial:" << endl ;
    cout << l << endl ;
	
    creaListaOrdenadaDeListas(l, ll) ;

    list<list<int>>::const_iterator it ;

    for(it = ll.begin() ; it != ll.end() ; ++it)
        cout << *it ;
    cout << endl ;
}  
  
  
  
  
  
  
  
  
