#include <iostream>
#include <sstream>
#include <string>
#include "frases.h"

using namespace std;

//Constructor por defecto
Frase::Frase(){
    num_trad = 0 ;
}

//Constructor con parámetros
Frase::Frase(const int tamanio){
    reservarMemoria(tamanio) ;
}

//Constructor de copia
Frase::Frase(const Frase & f){
    reservarMemoria(f.num_trad) ;
    copiarDatos(f);
}

//Funcion de copia.
void Frase::copiarDatos(const Frase & f){
    origen = f.origen ;

    for(int i = 0 ; i < f.num_trad ; i++)
        traducciones[i] = f.traducciones[i] ;
}

// Reserva memoria con tamaño especificado.
void Frase::reservarMemoria(const int tamanio){
    if(tamanio > 0){
        traducciones = new string[tamanio] ;
    }

    num_trad = tamanio ;
}

// Destructor
Frase::~Frase(){
    liberarMemoria() ;
}

// Libera la memoria de las traducciones.
void Frase::liberarMemoria(){
    if(num_trad != 0){
        delete []traducciones ;
        num_trad = 0 ;
    }
}

// Sobrecarga del operador de asignacion
const Frase & Frase::operator=(const Frase & f){
	if(this != &f){
        liberarMemoria() ;
        reservarMemoria(f.num_trad) ;
		copiarDatos(f);
	}
	return *this;
}

// Sobrecarga del operador de desigualdad
const bool Frase::operator!=(const Frase &f){
    return origen != f.origen;
}

// Sobrecarga del operador de igualdad
const bool Frase::operator==(const Frase &f){
    return origen == f.origen;
}

//Operador menor que
const bool Frase::operator<(const Frase & f){
    string izq = origen;
    string der = f.origen;

    // Transformar las claves a minúscula para poder comparar sin
    // distinciones los caracteres.
    transform(izq.begin(), izq.end(), izq.begin(), ::tolower);
    transform(der.begin(), der.end(), der.begin(), ::tolower);

    // Cálculo de la frase que tiene menor número de letras.
    unsigned tam;
    izq.size() < der.size() ? tam = izq.size() : tam = der.size();

    // Recorrer letra a letra comparando ordenadamente si
    // la de la izquierda tiene una letra menor o mayor que la de la derecha.
    for (unsigned i = 0; i < tam; ++i){
        if(izq.at(i) < der.at(i))
            return true;
        else if(izq.at(i) > der.at(i))
            return false;
    }

    // Si una vez acabado el bucle no se encuentran resultados
    // será menor aquella que menos letras tenga.
    return izq.size() < der.size();
}


// Sobrecarga de operador de entrada
istream& operator>> (istream& input, Frase & f){
	string linea;
	string trad;

    // Obtener la frase origen delimitado por ;
	getline(input, f.origen, ';');

    // Obtener el resto de frases que serán las traducciones.
	getline(input, linea);

    // Stringstream para la entrada entrada.
	istringstream iss(linea);

	while(getline( iss, trad, ';' )){
		f.insertaTraduccion(trad);
	}

	return (input);
}

// Inserta una traducción en la frase.
void Frase::insertaTraduccion(string trad){
    int nuevoTam = num_trad + 1 ;
    Frase nuevaF(nuevoTam) ;
    nuevaF.origen = origen ;

    for(int i = 0 ; i < num_trad ; i++)
        nuevaF.traducciones[i] = traducciones[i] ;

    nuevaF.traducciones[num_trad] = trad ;
    liberarMemoria() ;

    reservarMemoria(nuevoTam) ;

    *this = nuevaF ;

    nuevaF.liberarMemoria() ;
}

// Devuelve un vector de las traducciones de una frase.
vector<string> Frase::GetDestino() {
    vector <string> _traducciones ;

    for(int i = 0 ; i < num_trad ; i++)
        _traducciones.push_back(traducciones[i]) ;

    return _traducciones;
}

// Sobrecarga del operador []
string Frase::operator[](const int indice) const{
    // Se comprueba que el índice pasado como argumento sea válido
    if (indice < 0 || indice > num_trad){
        // Se genera una excepción
        throw out_of_range("Índice fuera de rango en acceso con []");
    }
    // Si todo ha ido bien, devuelve el valor
    return traducciones[indice];
}


// Sobrecarga del operador de salida
ostream& operator<< (ostream& flujo, const Frase & f){
	flujo << "Frase origen: " << f.origen << endl;
	flujo << "Traducciones: ";
	for(int i = 0; i < f.num_trad; ++i){
		flujo << "\t" << f.traducciones[i] << endl ;
        flujo << "\t" ;
	}
	flujo << endl;

	return flujo;
}
