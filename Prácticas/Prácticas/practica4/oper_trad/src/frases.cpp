/**
  * @file frases.cpp
  * @brief Fichero con las implementaciones de Frase
  *
  * @author Mario Rodríguez Ruiz
  * @date Diciembre 2016
  *
  */
#include <iostream>
#include <sstream>
#include <string>
#include "frases.h"

using namespace std;

//Constructor por defecto
Frase::Frase(){}

//Constructor con parámetros
Frase::Frase(const pair<string, set<string> > p){
    datos.first = p.first;
    datos.second = p.second;
}

//Constructor de copia
Frase::Frase(const Frase & f){
    copiarDatos(f);
}

//Función de copia.
void Frase::copiarDatos(const Frase & f){
    datos.first = f.datos.first;
    datos.second = f.datos.second;
}

// Modifica el contenido de una frase
void Frase::SetFrase(string origen, set<string>  destino){
    datos.first = origen;
    datos.second = destino;
}

// Modifica el contenido de la frase origen de una frase.
void Frase::SetOrigenFrase(string origen){
    datos.first = origen;
}

// Devuelve una frase.
pair<string, set<string> > Frase::GetFrase(){
	return datos;
}

// Devuelve la cadena origen de una frase.
string Frase::GetFraseOrigen(){
    return datos.first;
}

// Devuelve las traducciones de una frase.
set<string> Frase::GetFraseDestino(){
    return datos.second;
}

// Añade traducción a una frase
void Frase::AniadeTraduccion(string trad){
    datos.second.insert(trad);
}

// Sobrecarga del Operador <<
ostream & operator << (ostream& out, Frase &p){

	out << "Frase origen: " << p.GetFrase().first << endl;
	out << "Frase o frases destino: ";
	Frase::const_iterator it;

	for ( it=p.begin(); it!=p.end(); ++it)
		out << *it << " ";

    out << endl;

    return (out);
}

// Sobrecarga del Operador >>
istream & operator >> (istream& input, Frase &p){
    string resto ;
    string orig ;
	string trad;

    // Obtener la frase origen delimitado por ;
	getline(input, orig, ';');
    p.SetOrigenFrase(orig) ;

    // Obtener el resto de frases que serán las traducciones.
	getline(input, resto);

    // Stringstream para la entrada entrada.
	istringstream iss(resto);

	while(getline( iss, trad, ';' )){
		p.datos.second.insert(trad);
	}

    return input;
}

// Sobrecarga del Operador =
 const Frase & Frase::operator = (const Frase &p){
	if (this != &p){
		copiarDatos(p);
	}
	return (*this);
}
