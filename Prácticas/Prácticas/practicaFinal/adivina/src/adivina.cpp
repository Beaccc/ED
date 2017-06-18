#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <ctype.h>
#include "cual_compila.h"
using namespace std;

string OcultarRefran(const string &refran, const int porcentaje, bool *&ocultadas, int &tam_ocult){
    string nuevo ;
    tam_ocult = refran.size() - refran.size()*porcentaje/100 ;

    ocultadas = new bool[refran.size()] ;

    // Se inicializa todo a cero
    // Cero significa letra descubierta y uno letra oculta.
    for(unsigned i = 0 ; i < refran.size() ; i++)
        ocultadas[i] = 0 ;

    nuevo = refran ;
    int i = 0, pos ;

    // Mientras haya letras por ocultar.
    while(i < tam_ocult){
        pos = rand() % refran.size() + 0 ;
        // Si en la posición no se encuentra un espacio o
        // una letra oculta, se cubre dicha letra.
        if(nuevo[pos] != ' ' && nuevo[pos] != '_'){
            nuevo[pos] = '_' ;
            ocultadas[pos] = 1 ;
            i++ ;
        }
    }

    return nuevo ;
}

void ImprimirJugada(const string &refran){
    for(unsigned i = 0 ; i < refran.size() ; i++)
        cout << refran[i] << ' ' ;

    cout << endl ;
}

bool SeguirJugando(Refranes & refs, const int porcentaje){
    bool *ocultadas = 0, jugar = true ;
    int tam_ocultadas = 0 ;
    int encontradas, let_ayuda ;
    string original = refs.ObtenerRefranAleatorio() ;
    // Se borra este refrán para que no vuelva a aparecer en esta misma partida.
    //refs.BorrarRefran(original) ; // Comentado porque en el guión no se especifica.

    string refran_mod, entrada ;
    bool terminado = false, destapar;
    int pos_aleatoria ;

    cout << endl <<"*****************Comienza el juego******************" << endl ;


    //cout << original << endl ;
    refran_mod = OcultarRefran(original, porcentaje, ocultadas, tam_ocultadas) ;

    while(!terminado){
//         cout << original << endl ;
        cout << endl ;
        ImprimirJugada(refran_mod) ;
        cout << endl ;
        cout << "Pulsa 0 para obtener ayuda" << endl ;
        cout << "Dime un caracter (o el refrán para resolver: " ;
        getline(cin,entrada); ;

        // Ayuda para el juego
        if(entrada[0] == '0' && tam_ocultadas > 0){
            // Calcula un número aleatorio de letras a descubrir.
            let_ayuda = rand() % tam_ocultadas/4 + 1 ;
            // Tantas veces como el número de letras a descubrir anteriormente calculado.
            for(int i = 0 ; i < let_ayuda; i++){
                destapar = false ;
                // Hasta que no se encuentre una letra oculta.
                while(!destapar){
                    // Calcula una posición aleatoria para descubrir.
                    pos_aleatoria = rand() % refran_mod.size() + 0 ;
                    // Comprueba si en esa posición se encuentra
                    // un caracter oculto y si es así lo descubre.
                    if(refran_mod[pos_aleatoria] == '_'){
                        refran_mod[pos_aleatoria] = original[pos_aleatoria] ;
                        // Se destapa el booleano correspondiente.
                        ocultadas[pos_aleatoria] = 0 ;
                        // Hay que reducir en uno el número de letras
                        // que están ocultadas hasta el momento.
                        --tam_ocultadas ;
                        destapar = true ;
                    }
                }
            }
            cout << "Descubiertas: " << let_ayuda << endl ;
        }
        // Se ha introducido el refrá completo correctamente.
        else if(entrada == original){
            cout << "¡La has adivinado! " ;
            ImprimirJugada(original) ;
            cout << "¿Quieres seguir jugando[S/N]? " ;
            cin >> entrada ;
            if(entrada[0] == 'N' || entrada[0] == 'n')
                jugar = false ;

            terminado = true ;

            // Limpiar el buffer de entrada para la próxima partida
            cin.clear(); cin.ignore(256,'\n');
        }
        // Comprobar si el caracter introducido se encuentra
        // y si es así se descubre.
        else if(entrada.size() == 1){
            encontradas = 0 ;
            // Se recorren las letras del refrán original
            for(unsigned i = 0 ; i < refran_mod.size() ; i++){
                // Si la posición en el vector de bool está activa en
                // esa posición y si coinciden los caracteres
                // se descubre dicho caracter y se retira del desactiva del vector de bool.
                if(ocultadas[i] == 1 && original[i] == entrada[0]){
                    refran_mod[i] = original[i] ;
                    ocultadas[i] = 0 ;
                    --tam_ocultadas ;
                    ++encontradas ;
                }

            }
            cout << "Encontradas: " << encontradas << endl;
        }
        // Se ha introducido una cadena que no corresponde a la solución
        else{
            cout << "!Sigue probando! " << endl;
        }
    }

    delete []ocultadas ;
    return jugar ;
}

int main(int argc, char * argv[]){
    if (argc!=3 && argc!=2){
        cout<<"Los parametros son:"<<endl;
        cout<<"1.Dime el nombre del fichero los refranes"<<endl;
        cout<<"2.-[Opcional] Porcentaje de letras que se dejan sin ocultar"<<endl;
        return 0;
    }

    ifstream fin(argv[1]);
    if (!fin){
        cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
        return 0;
    }

    int len=3;
    int porcentaje = 50 ;
    bool jugar = true ;

    Refranes refs(len);
    if (argc==3)
        porcentaje=atoi(argv[2]);

    cout<<"Creando el juego..."<<endl;
    fin>>refs;

    cout<<"Refranes leidos: " << refs.size() << endl;

    while(jugar){
        jugar = SeguirJugando(refs, porcentaje) ;
    }
}  
