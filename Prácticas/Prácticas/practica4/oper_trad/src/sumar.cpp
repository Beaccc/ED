/**
  * @file sumar.cpp
  * @brief Fichero para la suma de dos traductores
  *
  * @author Mario Rodríguez Ruiz
  * @date Diciembre 2016
  *
  */
#include "traductor.h"
#include <fstream>
#include <iostream>

using namespace std;

void Suma( Traductor & t_origen1, Traductor & t_origen2, Traductor & t_destino){
    Traductor::const_iterator it_origen1;   // Iterador para recorrer los traductores
    string nuevo_origen = "";               // Frase origen que contendrá el destino
	set<string> nuevo_destino;              // Traducciones para la frases destino.

    // Se añade todo el primer traductor.
	for (it_origen1 = t_origen1.begin(); it_origen1!=t_origen1.end(); ++it_origen1){
        // Cada frase del primer traductor
        Frase p(*it_origen1);
        set<string> destino = p.GetFraseDestino();

        nuevo_destino = p.GetFraseDestino();
        nuevo_origen = p.GetFraseOrigen();

        // Nueva Frase para el traductor destino.
        pair<string, set<string> > es;
        es.first = nuevo_origen;
        es.second = nuevo_destino;
        Frase nueva(es);
        t_destino.AniadeFrase(nueva);
    }

    // Se recorre el segundo traductor.
    // Si existe ya la frase en el destino, solamente se añaden tracucciones.
    // Las comprobaciones se hacen en AniadeFrase
    for (it_origen1 = t_origen2.begin(); it_origen1!=t_origen2.end(); ++it_origen1){
        // Cada frase del primer traductor
        Frase p(*it_origen1);
        t_destino.AniadeFrase(p);
    }
}

void ImprimeTraductor(const Traductor &T,ostream &os){
    Traductor::const_iterator it;
    for (it=T.begin(); it!=T.end();++it){
        Frase p(*it);
        os<<p.GetFrase().first<<";";
        Frase::const_iterator it_d;
        for (it_d=p.begin(); it_d!=p.end();++it_d)
            os<<(*it_d)<<";";

        os << endl;
    }
}

int main(int argc, char * argv[]){

    if (argc!=4){
        cout<<".-Dime el nombre de fichero del traductor origen"<<endl;
        cout<<".-[opcionalmente] El nombre de fichero del traductor destino"<<endl;
        return 0;
    }

    ifstream f1 (argv[1]);
    if (!f1){
        cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
        return 0;
    }

    ifstream f2 (argv[2]);
    if (!f2){
        cout<<"No puedo abrir el fichero "<<argv[2]<<endl;
        return 0;
    }

    Traductor t_ori1, t_ori2, t_des;

    f1>>t_ori1; //Cargamos en memoria, en el primer traductor.
    f2>>t_ori2; //Cargamos en memoria, en el segundo traductor.

    Suma(t_ori1, t_ori2, t_des);

    if (argc==2)
        ImprimeTraductor(t_des,cout);
    else{
        ofstream fout(argv[3]);
        if (!fout){
            cout<<"No puedo crear el fichero "<<argv[3]<<endl;
            return 0;
        }
        ImprimeTraductor(t_des,fout);
    }
}

