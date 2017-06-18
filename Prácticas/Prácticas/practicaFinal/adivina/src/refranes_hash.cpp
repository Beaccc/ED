 /**
 * @file refranes.cpp
 * @brief Implementación de la clase Refrán
 *
 * @author Mario Rodríguez Ruiz
 * @date Diciembre 2016
 */

#include "refranes_hash.h"

/******************************
*       Constructores         *
******************************/

Refranes::Refranes(){
    len_prefijo = 3 ;
    n_ref = 0 ;
    caracteres_totales = 0 ;
}

Refranes::Refranes(int lpre){
    len_prefijo = lpre ;
    n_ref = 0 ;
    caracteres_totales = 0 ;
}

Refranes::~Refranes(){
    clear() ;
}

//--------------------------------------------------------------------------------

/********************************
*       Metodos publicos        *
********************************/

int Refranes::size() const{
    return n_ref ;
}

//--------------------------------------------------------------------------------

void Refranes::clear(){
    ab.clear() ;
}

//--------------------------------------------------------------------------------

string Refranes::ObtenerRefranAleatorio(){
    srand( time(0));
    // Se crea una posición aleatoria para obtener un refrán.
    int pos = rand() % size() + 1 ;
    // Posición que se incrementará al recorrer cada uno de
    // los refranes.
    int pos_bucle = 1 ;

    iterator itbeg = begin();
    iterator itend = end();
    //El vector a devolver
    string result = "";

    while(itbeg != itend && result == ""){
        // Si las posiciones coinciden
        // ya se obtiene el refrán aleatorio.
        // sino, se incrementa la variable de posición.
        if(pos_bucle == pos){
            result = *itbeg ;
        }
        ++pos_bucle ;
        ++itbeg;
    }

    return result;
}

//--------------------------------------------------------------------------------

void Refranes::Insertar(const string & refran){
    pair<bool, Refranes::iterator> res = Esta(refran) ;

    if(!res.first){
        ab.insert(refran) ;
        n_ref++ ;
        caracteres_totales += refran.size() ;
    }
}

//--------------------------------------------------------------------------------
//
pair<bool, Refranes::iterator> Refranes::Esta(const string &refran){
    pair<bool, Refranes::iterator> res ;

    if(ab.size()>0){
        unordered_set<string,Refranes::my_hash> :: iterator it ;
        it = ab.find(refran) ;

        if(it == ab.end()){
            res = {false, end()} ;
        }
        else{
            Refranes::iterator i ;
            i.it = it ;
            res = {true,i} ;
        }

        return res ;
    }

    res = {false, end()} ;
    return res ;
}
//
// //--------------------------------------------------------------------------------

void Refranes::BorrarRefran(const string &refran){
    pair<bool, iterator> res = Esta(refran) ;

    // Si existe, se borra.
    if(res.first){
        ab.erase(refran) ;
        --n_ref ;
    }
}

//--------------------------------------------------------------------------------
int Refranes::Caracteres_Refranes()const{
    return caracteres_totales ;
}

 //---------------------------------------------------------------------
string Refranes::iterator::operator*() {
    return *it;
}

string Refranes::const_iterator::operator*() {
    return *it;
}

//--------------------------------------------------------------------------------

typename Refranes::iterator & Refranes::iterator::operator++(){
    it++;
    return *this ;
}

typename Refranes::const_iterator & Refranes::const_iterator::operator++(){
    it++;
    return *this ;
}

//--------------------------------------------------------------------------------

bool Refranes::iterator::operator==(const iterator & i) const{
    return i.it == it ;
}

bool Refranes::const_iterator::operator==(const const_iterator & i) const{
    return i.it == it ;
}

//--------------------------------------------------------------------------------

bool Refranes::iterator::operator!=(const iterator & i) const{
    return i.it != it;
}

bool Refranes::const_iterator::operator!=(const const_iterator & i) const{
    return i.it != it;
}

 //--------------------------------------------------------------------------------

typename Refranes::iterator Refranes::begin(){
    iterator iter;
    iter.it = ab.begin();
    return iter;
}

typename Refranes::const_iterator Refranes::begin() const{
    const_iterator iter;
    iter.it = ab.begin();
    return iter;
}

//--------------------------------------------------------------------------------

typename Refranes::iterator Refranes::end(){
    iterator iter;
    iter.it = ab.end();
    return iter;
}

typename Refranes::const_iterator Refranes::end() const{
    const_iterator iter;
    iter.it = ab.end();
    return iter;
}

/*******************************
*      Entrada y salida        *
*******************************/

istream & operator>>(istream & is, Refranes & D){
    string refran;
    while(!is.eof()){
        getline(is, refran);
        D.Insertar(refran);
    }
    return is;
}

//--------------------------------------------------------------------------------
//
ostream & operator<<(ostream & os, const Refranes & D){
    Refranes::const_iterator iter = D.begin();
    Refranes::const_iterator itend = D.end();
    // Se evita la raiz.
    while(iter != itend){
        os << (*iter) << endl;
        ++iter;
    }
    return os;
}
