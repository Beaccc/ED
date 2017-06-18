/**
  * @file traductor.cpp
  * @brief Fichero con las implementaciones del traductor
  *
  * @author Mario Rodríguez Ruiz
  * @date Diciembre 2016
  *
  */
#include <iostream>
#include <string>
#include <string.h>
#include "traductor.h"

using namespace std;

// Constructor por defecto
Traductor::Traductor(){
	traductor.clear();
}

//Constructor con parámetros
Traductor::Traductor(Frase p){
	pair<string, set<string> > e = p.GetFrase();
	traductor.insert(e);
}

// Constructor de copia
Traductor::Traductor(const Traductor & c){
    copiarDatos(c) ;
}

// Añade una frase o las traducciones de ésta
void Traductor::AniadeFrase(Frase &p){
    Frase encontrada = GetFrase(p.GetFraseOrigen());
    // Si la frase no existe se crea una nueva
    // sino se inserta la nueva traducción en la existente
    if(encontrada.GetFraseOrigen().size() == 0){
        pair<string, set<string> > e = p.GetFrase();
        traductor.insert(e);
    }
    else{
        set<string> enc_destino = p.GetFraseDestino();
        set<string>::iterator it_d;
        // Se recorre todas las nuevas traducciones que
        // se van a ir insertando en la frase original que ya existía.
        for ( it_d=enc_destino.begin(); it_d!=enc_destino.end(); ++it_d){
            traductor[p.GetFraseOrigen()].insert(*it_d) ;
        }
    }
}

// Sobrecarga del operador de entrada >>
istream& operator>> (istream& input, Traductor &t){
    while(!input.eof()){
        Frase f;
        input >> f;
        // Asegurar que la linea no esté vacía.
        //if(f.getOrigen()[0] != 0 && f.getOrigen()[0] != '\n')
            t.AniadeFrase(f);
    }
    return (input);
}

// Sobrecarga del operador salida <<
 ostream& operator<< (ostream& out, Traductor& t){
	Traductor::const_iterator i;
	for (i=t.begin(); i!=t.end(); ++i){
		Frase p(*i);

		out << p;
	}

	return out ;
}

// Función de copia de datos.
void Traductor::copiarDatos(const Traductor & t){
    traductor = t.traductor;
}

// Busca una frase coincidente con la cadena pasada como parámetro
Frase Traductor::GetFrase(const string origen){
    map<string, set<string> >::iterator it;
    it = traductor.find(origen);

    if (it==traductor.end())
        return Frase();
    else{
        Frase p(*it);
        return p;
    }
}

// Devuelve un vector con todas las traducciones de una cadena.
 vector<string> Traductor::GetTraducciones(const string c){
    vector <string> resultado;
    Frase encontrada = GetFrase(c);

    set<string> enc_destino = encontrada.GetFraseDestino();
    set<string>::iterator it;

    // Se recorren las traducciones de la frase y se añade una a una.
    for ( it=enc_destino.begin(); it!=enc_destino.end(); ++it){
        resultado.push_back(*it);
    }

    return resultado;
}

// Devuelve una frase introducida como parámetro invertida
Frase Traductor::GetFraseInversa(string des) const{
   string nuevo_origen = des;
	 set<string> nuevo_destino;

	 set<string>::iterator is;
	 Traductor::const_iterator it;

    // Se recorre todo el traductor
    for (it = (*this).begin(); it != (*this).end(); ++it){
        Frase p(*it);
        set<string> destino = p.GetFraseDestino();
        // Busca la traducción de una frase
        is = destino.find(des);
        // Si des se encuentra en la traducción de una frase
        // se añade como destino el origen momentaneo de esa frase.
        if (is != destino.end() ){
            nuevo_destino.insert(p.GetFraseOrigen());
        }
    }

    // Se crea la nueva Frase con los datos obtenidos anteriormente.
    pair<string, set<string> > e;
    e.first = nuevo_origen;
    e.second = nuevo_destino;
    Frase nueva(e);
    return nueva;
}
