#include <iostream>
#include <string>
#include <string.h>
#include "conjuntofrases.h"

using namespace std;

// Constructor por defecto
ConjuntoFrases::ConjuntoFrases(){
    num_frases = 0 ;
}

// Constructor con parámetros
ConjuntoFrases::ConjuntoFrases(const int tamanio){
    reservarMemoria(tamanio) ;
}

// Constructor de copia
ConjuntoFrases::ConjuntoFrases(const ConjuntoFrases & c){
	reservarMemoria(c.num_frases) ;
    copiarDatos(c) ;
}

// Función de copia.
void ConjuntoFrases::copiarDatos(const ConjuntoFrases & c){
    for(int i = 0 ; i < c.num_frases ; i++)
        frases[i] = c.frases[i] ;
}

// Reserva memoria con tamaño especificado.
void ConjuntoFrases::reservarMemoria(const int tamanio){
    if(tamanio > 0){
        frases = new Frase[tamanio] ;
    }

    num_frases = tamanio ;
}

// Destructor
ConjuntoFrases::~ConjuntoFrases(){
    liberarMemoria() ;
}

// Libera la memoria del array de frases.
void ConjuntoFrases::liberarMemoria(){
    if(num_frases != 0){
        delete []frases ;
        num_frases = 0 ;
    }
}

// Sobrecarga del operador de asignación
const ConjuntoFrases & ConjuntoFrases::operator=(const ConjuntoFrases & c){
	if(this != &c){
        liberarMemoria() ;
        reservarMemoria(c.num_frases) ;
		copiarDatos(c);
	}
	return *this;
}

//Insertar alfabéticamente una frase
void ConjuntoFrases::insertaAlfabeticamente(Frase & f){
    bool puesta = false ;
    int nuevoTam = num_frases + 1 ;
    // Crea un ConjuntoFrases auxiliar con el tamaño actualizado.
    ConjuntoFrases nuevoCto(nuevoTam) ;

    int tam_ant = 0 ;
    int tam_nu = 0 ;

    // Mientras no se añada la nueva frase o no se complete el nuevo vector.
    while(tam_nu < nuevoTam || !puesta){
        // Si es la primera que se va a insertar.
        if(num_frases == 0){
            nuevoCto.frases[tam_nu] = f ;
            puesta = true ;
        }
        // Si es la última
        else if(tam_ant == num_frases){
            nuevoCto.frases[tam_nu] = f ;
            puesta = true ;
        }
        // Si ya se ha insertado la nueva pero hay que
        // completar las que había de antes.
        else if(puesta){
            nuevoCto.frases[tam_nu] = frases[tam_ant] ;
            tam_ant++ ;
        }
        // Comprobar cuál de las dos es menor alfabéticamente
        // o si son iguales
        else if(f < frases[tam_ant] || f == frases[tam_ant]){
            nuevoCto.frases[tam_nu] = f ;
            puesta = true ;
        }
        // Para los demás casos.
        else{
            nuevoCto.frases[tam_nu] = frases[tam_ant] ;
            tam_ant++ ;
        }
        tam_nu++ ;
    }

    // Se libera memoria del antiguo vector de frases.
    liberarMemoria() ;

    // Reserva de memoria para el nuevo vector de frases.
    reservarMemoria(nuevoTam) ;

    // Se copia el objeto local al global.
    *this = nuevoCto ;

    // Libera memoria del objeto local porque no se vuelve
    // a utilizar.
    nuevoCto.liberarMemoria() ;
}

// Sobrecarga del operador de entrada
istream& operator>>(istream &input, ConjuntoFrases & c){
    while(!input.eof()){
        Frase f;
        input >> f;
        // Asegurar que la linea no esté vacía.
        if(f.getOrigen()[0] != 0 && f.getOrigen()[0] != '\n')
            c.insertaAlfabeticamente(f);
    }

    return (input);
}

// Sobrecarga del operador de salida
ostream& operator<< (ostream& flujo, ConjuntoFrases & c){
	for( int i = 0; i < c.num_frases; ++i){
		flujo << c.frases[i] ;
	}

	return flujo;
}

// Transforma una frase a todo minúsculas.
string ConjuntoFrases::covierteAminusculas(const string f){
    string st = f;

    for(unsigned i = 0; i < st.length(); i++)
         st[i] = tolower(st[i]);

    return st ;
}

// Comprueba si una frase se encuentra dentro del diccionario.
bool ConjuntoFrases::Esta(string f){
    bool resultado = false ;

    f = covierteAminusculas(f) ;

    for(int i = 0 ; i < num_frases && !resultado; i++){
        if(f.compare(covierteAminusculas(frases[i].getOrigen())) == 0)
            resultado = true;
    }

    return resultado ;
}

// Obtiene las traducciones de una frase dada.
Frase ConjuntoFrases::GetTraducciones(string f){
    Frase nueva ;
    nueva.setOrigen(f) ;

    f = covierteAminusculas(f) ;

    for(int i = 0 ; i < num_frases ; i++){
        if(f.compare(covierteAminusculas(frases[i].getOrigen())) == 0){
            for(int j = 0 ; j < frases[i].getNumTrads() ; j++)
                nueva.insertaTraduccion(frases[i][j]) ;
        }
    }
    return nueva ;
}

// Obtiene todas las frases que contienen una cadena específica.
// Tanto frases origen como traducciones.
ConjuntoFrases ConjuntoFrases::Contenga(const string f){
    ConjuntoFrases resultado ;
    const char *nuevaF = covierteAminusculas(f).c_str() ;

    // Recorrido del vector frases.
    for(int i = 0 ; i < num_frases ; i++){
        // Comprueba si la cadena se encuentra en la frase origen.
        if(strstr(covierteAminusculas(frases[i].getOrigen()).c_str(), nuevaF) != NULL)
                resultado.insertaAlfabeticamente(frases[i]) ;
        // Comprueba si la cadena se encuentra en alguna de las traducciones de la frase.
        else{
            for(int j = 0 ; j < frases[i].getNumTrads() ; j++)
                if(strstr(covierteAminusculas(frases[i][j]).c_str(), nuevaF) != NULL)
                        resultado.insertaAlfabeticamente(frases[i]) ;
        }

    }

    return resultado ;
}

