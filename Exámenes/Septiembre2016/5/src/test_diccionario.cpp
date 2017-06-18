#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <ctype.h>
#include <math.h>
#include "Diccionario.h"

using namespace std;




int main(int argc, char * argv[]){

    Diccionario dic ;
    list<string> l,l1,l2,l3 ;

    l.push_back("hola") ;
    l.push_back("que tal") ;

    l1.push_back("soy") ;
    l1.push_back("la l1") ;

    l2.push_back("soy") ;
    l2.push_back("la l2") ;

    l3.push_back("soy") ;
    l3.push_back("la l3") ;

    dic.Insertar(0,l);
    dic.Insertar(1,l1);
    dic.Insertar(3,l3);
    dic.Insertar(2,l2);
    dic.Insertar(8,l3);
//     dic.Insertar(7,l3);

    cout << dic ;
}  
