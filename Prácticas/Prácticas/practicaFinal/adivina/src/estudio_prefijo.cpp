#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <ctype.h>
#include "refranes.h"
using namespace std;

int main(int argc, char * argv[]){
    if (argc!=3){
        cout<<"Los parametros son:"<<endl;
        cout<<"1.Dime el nombre del fichero los refranes"<<endl;
        cout<<"2.Dime el nombre del fichero de salida (en formato csv)" << endl;
        return 0;
    }

    ifstream fin(argv[1]);
    if (!fin){
        cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
        return 0;
    }

    ofstream csv(argv[2]);
    if (!csv){
        cout<<"No puedo abrir el fichero "<<argv[2]<<endl;
        return 0;
    }

    double porcentaje_red = 0 ;
    double porcentaje_red_rodos = 0 ;
    double car_almacenados = 0 ;
    double car_totales = 0 ;
    double num_nodos = 0 ;

    for(int i = 2 ; i < 15 ; i++){
        ifstream aux(argv[1]);
        Refranes refs(i);
        aux>>refs;

        car_totales = refs.Caracteres_Refranes() ;
        car_almacenados = refs.Caracteres_Almacenados() ;
        num_nodos = refs.Numero_Nodos() ;
        porcentaje_red = 100 - (car_almacenados*100 / car_totales) ;
        porcentaje_red_rodos = porcentaje_red/num_nodos ;

        csv << endl << "Prefijo" << ";" << "Car.Total" << ";" << "Car.Arb" << ";" << "% Red" << ";" << "# Nodos" << ";" << "Red/#Nodos" << endl ;
        csv << i << ";" << car_totales << ";" << car_almacenados << ";" << porcentaje_red << ";" << num_nodos << ";" << porcentaje_red_rodos << endl ;
    }

}  
