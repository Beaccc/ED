/**
  * @file traductor_inverso.cpp
  * @brief Fichero para la version Traductor inverso
  *
  * @author Mario Rodríguez Ruiz
  * @date Diciembre 2016
  *
  */
#include "traductor.h"
#include <fstream>
#include <iostream>
using namespace std;
void GetTraductorInverso(const Traductor & t_origen, Traductor & t_destino){
    Traductor::const_iterator it;		//Iterador para recorrer el traductor
	set<string>::iterator ip; 			//Iterador para recorrer un set

    // Se recorre todo el traductor original.
	for (it = t_origen.begin(); it!=t_origen.end(); ++it){
        // Cada Frase del traductor original
        Frase p(*it);
        set<string> destino = p.GetFraseDestino();
        // Se recorre el destino de cada Frase.
        for (ip = destino.begin(); ip!=destino.end(); ++ip){
            Frase buscar = t_destino.GetFrase(*ip);
            string dest_origen = buscar.GetFraseOrigen();
            // Si la frase no existe se crea una nueva
            // sino se inserta la nueva traducción en la existente
            if(dest_origen.size() == 0){
                Frase nueva = t_origen.GetFraseInversa(*ip);
                t_destino.AniadeFrase(nueva);
            }
            else{
                set<string> enc_destino = buscar.GetFraseDestino();
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

    if (argc!=2 && argc!=3){
        cout<<".-Dime el nombre de fichero del traductor origen"<<endl;
        cout<<".-[opcionalmente] El nombre de fichero del traductor destino"<<endl;
        return 0;
    }

    ifstream f (argv[1]);
    if (!f){
        cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
        return 0;
    }
   
    Traductor t_ori;
    f>>t_ori; //Cargamos en memoria, en el traductor.
    Traductor t_des;

    GetTraductorInverso(t_ori,t_des);

    if (argc==2)
        ImprimeTraductor(t_des,cout);
    else{
        ofstream fout(argv[2]);
        if (!fout){
            cout<<"No puedo crear el fichero "<<argv[2]<<endl;
            return 0;
        }
        ImprimeTraductor(t_des,fout);

    }
}
