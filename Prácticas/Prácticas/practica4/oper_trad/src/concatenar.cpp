/**
  * @file concatenar.cpp
  * @brief Fichero para la versión concatenar traductores
  *
  * @author Mario Rodríguez Ruiz
  * @date Diciembre 2016
  *
  */
#include "traductor.h"
#include <fstream>
#include <iostream>

using namespace std;

void Concatenar( Traductor & t_origen1, Traductor & t_origen2, Traductor & t_destino){
    Traductor::const_iterator it_origen1;		// Iterador para recorrer el primer traductor
    Traductor::const_iterator it_origen2;		// Iterador para recorrer el segundo traductor
	set<string>::iterator if_1; 		// Iterador para recorrer las traducciones del primero.
	set<string>::iterator if_2; 		// Iterador para recorrer las traducciones del segundo.
    string nuevo_origen = "";           // Frase origen que contendrá el destino
	set<string> nuevo_destino;          // Traducciones para la frases destino.

    // Se recorre todo el primer traductor.
	for (it_origen1 = t_origen1.begin(); it_origen1!=t_origen1.end(); ++it_origen1){
        // Cada frase del primer traductor
        Frase p(*it_origen1);
        set<string> destino = p.GetFraseDestino();

        // Se recorre el destino de cada frase del primer traductor.
        for (if_1 = destino.begin(); if_1!=destino.end(); ++if_1){
            // Se busca una frase en el segundo traductor.
            Frase buscar = t_origen2.GetFrase(*if_1);
            string dest_origen = buscar.GetFraseOrigen();
            // Si la frase se encuentra, se inserta la frase original del traductor 1 como
            // la original en destino y la original del segundo como traducción en destino.
            if(dest_origen.size() > 0){
                // Se busca una frase en el traductor destino.
                Frase busca_dest = t_destino.GetFrase(*if_1);
                string dest = busca_dest.GetFraseOrigen();
                // Si no existe se inserta toda la frase como nueva,
                // por el contrario se añade solo las traducciones que provienen
                // de la frase original del segundo traductor.
                if(dest.size() == 0){
                    nuevo_destino = buscar.GetFraseDestino();
                    nuevo_origen = p.GetFraseOrigen();

                    // Nueva Frase para el traductor destino.
                    pair<string, set<string> > e;
                    e.first = nuevo_origen;
                    e.second = nuevo_destino;
                    Frase nueva(e);
                    t_destino.AniadeFrase(nueva);
                }
                else{
                    set<string> enc_destino = busca_dest.GetFraseDestino();
                    set<string>::iterator it_d;
                    // Se recorre todas las nuevas traducciones que
                    // se van a ir insertando en la frase original que ya existía.
                    for ( it_d=enc_destino.begin(); it_d!=enc_destino.end(); ++it_d){
                        enc_destino.insert(*it_d) ;
                    }
                }
            }
        }
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

    Concatenar(t_ori1, t_ori2, t_des);

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

