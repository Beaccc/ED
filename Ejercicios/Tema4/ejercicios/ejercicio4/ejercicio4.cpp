// Mario Rodríguez Ruiz
#include <iostream>
#include <list>
#include <set>
#include <map>
#include <ctime>
#include <cstdlib>
#include <vector>
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

class Alumnos{
    private:
        pair< string, set<string> > alumno;
    public:
        Alumnos(){}

        Alumnos(const pair<string, set<string> > a){
            alumno.first = a.first;
            alumno.second = a.second;
        }

        pair<string, set<string> > GetAlumno(){
            return alumno;
        }

        // Devuelve la cadena origen de un alumno.
        string GetAlumnoOrigen(){
            return alumno.first;
        }

        // Devuelve las asignaturas de un alumno.
        set<string> GetAlumnoDestino(){
            return alumno.second;
        }

        // Añade una asignatura a un alumno
        void AniadeAsignatura(string asig){
            alumno.second.insert(asig);
        }
};

class Matriculas{
    private:
        map<string, set<string> > matriculas; /**< Objeto de tipo map */

    public:
        Matriculas(){
            clear() ;
        }

        void clear(){
            matriculas.clear() ;
        }

        void Insertar(const string& dni,const string &cod_asig){
            pair<string, set<string> > d ;

            d.first = dni ;
            d.second.insert(cod_asig) ;
            Alumnos al(d) ;
            AniadeAlumno(al) ;
        }

        // Añade un alumno o asignaturas de éste
        void AniadeAlumno(Alumnos &p){
            Alumnos encontrado = GetAlumno(p.GetAlumnoOrigen());
            // Si el alumno no existe se crea uno nuevo
            // sino se inserta el nuevo código en el existente
            if(encontrado.GetAlumnoOrigen().size() == 0){
                pair<string, set<string> > e = p.GetAlumno();
                matriculas.insert(e);
            }
            else{
                set<string> enc_destino = p.GetAlumnoDestino();
                set<string>::iterator it_d;
                // Se recorre todas las nuevas asignaturas que
                // se van a ir insertando en el alumno original que ya existía.
                for ( it_d=enc_destino.begin(); it_d!=enc_destino.end(); ++it_d){
                    matriculas[p.GetAlumnoOrigen()].insert(*it_d) ;
                }
            }
        }

        // Busca un alumno coincidente con la cadena pasada como parámetro
        Alumnos GetAlumno(const string origen){
            map<string, set<string> >::iterator it;
            it = matriculas.find(origen);

            if (it==matriculas.end())
                return Alumnos();
            else{
                Alumnos p(*it);
                return p;
            }
        }

        void Borrar(const string &dni,const string &cod_asig){
            Alumnos encontrado = GetAlumno(dni);
            // Si el alumno no existe no se hace nada
            if(encontrado.GetAlumnoOrigen().size() != 0){
                matriculas[encontrado.GetAlumnoOrigen()].erase(cod_asig) ;
            }
        }

        list<string> GetAsignatras(const string &dni){
            list <string> resultado;
            Alumnos encontrado = GetAlumno(dni);

            set<string> enc_destino = encontrado.GetAlumnoDestino();
            set<string>::iterator it;

            // Se recorren las asignaturas del alumno y se añaden a la nueva lista.
            for ( it=enc_destino.begin(); it!=enc_destino.end(); ++it){
                resultado.push_back(*it);
            }

            return resultado;
        }

        list<string> GetAlumnos(const string &cod_asig){
            list<string> resultado ;
            const_iterator it;		//Iterador para recorrer las matriculas
            set<string>::iterator ip; 			//Iterador para recorrer un set

            // Se recorre todas las matriculas.
            for (it = begin(); it!=end(); ++it){
                // Cada alumno de la matricula original
                Alumnos p(*it);
                set<string> destino = p.GetAlumnoDestino();
                // Se recorre el destino de cada Alumnos.
                for (ip = destino.begin(); ip!=destino.end(); ++ip){
                    Alumnos buscar = GetAlumno(cod_asig);
                    string dest_origen = buscar.GetAlumnoOrigen();
                    // Si la alumno no existe se crea una nueva
                    // sino se inserta la nueva traducción en la existente
                    if(dest_origen.size() != 0){
                        set<string> enc_destino = buscar.GetAlumnoDestino();
                        set<string>::iterator it_d;
                        // Se recorre todas las nuevas asignaturas que
                        // se van a ir insertando en la lista.
                        for ( it_d=enc_destino.begin(); it_d!=enc_destino.end(); ++it_d){
                            resultado.push_back(*it_d) ;
                        }
                    }
                }
            }
            return resultado ;
        }

        class const_iterator{
            private:
                map<string, set<string> >::const_iterator it;
            public:
                const_iterator & operator++(){
                    ++it;
                    return *this;
                }

                const_iterator & operator--(){
                    --it;
                    return *this;
                }

                Alumnos operator *(){
                    Alumnos p(*it);
                    return p;
                }

                bool operator ==(const const_iterator &i){
                    return i.it==it;
                }

                bool operator !=(const const_iterator &i){
                    return i.it!=it;
                }

                friend class Matriculas;
        };


        const_iterator begin() const {
            const_iterator i;
            i.it=matriculas.begin();
            return i;
        }


        const_iterator end() const {
            const_iterator i;
            i.it=matriculas.end();
            return i;
        }


        const_iterator buscar(string f) {
            const_iterator i;
            i.it=matriculas.find(f);
            return i;
        }

};

// Crea lista de enteros con números aleatorios
void creaLista(list<int> & l){
	for(int i = 0 ; i < 10 ; i++){
		l.push_back(i);
	}
}




int main(){

}  
  
  
  
  
  
  
  
  
