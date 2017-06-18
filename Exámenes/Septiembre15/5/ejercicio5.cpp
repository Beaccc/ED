// Mario Rodríguez Ruiz
/*
Implementa un iterator que itere sobre las claves que sean números pares
en una clase Diccionario definida como:
    class Diccionario{
        private:
            map<int, list<string> > datos;
            .............
            .............
    }
Han de implementarse (aparte de las de la clase iterator) las funciones begin() y end().


*/

#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <ctime>
#include <cstdlib>
using namespace std;

class Diccionario{
    private:
        map<int, list<string> > datos;

    public:

        Diccionario(){}

        void Insertar(const int &clave, const list<string> &l){
            datos[clave] = l ;
        }

        friend ostream & operator <<(ostream & out, const Diccionario &d) ;

        class const_iterator ;

        class iterator{
            private:
                map<int, list<string> >::iterator it ;
            public:
                iterator(){}

                pair<int, list<string>> operator*(){
                    return *it ;
                }

                bool operator == (const iterator i)const{
                    return i.it == it ;
                }

                bool operator != (const iterator i)const{
                    return i.it != it ;
                }

                iterator & operator++(){
                    if((*it).first%2==0)
                        ++it ;
                    return *this ;
                }



                friend class const_iterator ;
                friend class Diccionario ;
        };

        class const_iterator{
            private:
                map<int, list<string> >::const_iterator it ;
            public:
                const_iterator(){}

                bool operator == (const const_iterator i)const{
                    return i.it == it ;
                }

                bool operator != (const const_iterator i)const{
                    return i.it != it ;
                }

                const_iterator & operator++(){
                    ++it ;
                    while((*it).first%2!=0){
                        ++it ;
                    }
                    return *this ;
                }

                pair<int, list<string>> operator*() const{
                    return *it ;
                }

                friend class Diccionario ;
        };

        iterator begin(){
            iterator i ;
            i.it = datos.begin() ;
            return i ;
        }

        iterator end(){
            iterator i ;
            i.it = datos.end() ;
            return i ;
        }

        const_iterator begin()const{
            const_iterator i ;
            i.it = datos.begin() ;
            return i ;
        }

        const_iterator end()const{
            const_iterator i ;
            i.it = datos.end() ;
            return i ;
        }

};

ostream & operator <<(ostream & out, const list<string> &l){
    list<string>::const_iterator it ;

    for(it = l.begin() ; it != l.end() ; ++it){
        out << (*it) << ' ' ;
    }

    return out ;
}

ostream & operator <<(ostream & out, const Diccionario &d){
    Diccionario::const_iterator mit ;

    for(mit = d.begin() ; mit != d.end() ; ++mit){
        out << (*mit).first << " -> " << (*mit).second << endl ;
    }

    return out ;
}

int main(){

    list<string> mylist = {"barcos", "y", "putas"} ;
    list<string> mylist1 = {"barcos1", "y", "putas1"} ;
    list<string> mylist2 = {"barcos2", "y", "putas2"} ;
    list<string> mylist3 = {"barcos3", "y", "putas3"} ;
    list<string> mylist4 = {"barcos4", "y", "putas4"} ;
    list<string> mylist5 = {"barcos5", "y", "putas5"} ;

    Diccionario dic ;

    dic.Insertar(0, mylist) ;
    dic.Insertar(1, mylist1) ;
    dic.Insertar(2, mylist2) ;
    dic.Insertar(4, mylist4) ;
    dic.Insertar(3, mylist3) ;

    dic.Insertar(5, mylist5) ;


    cout << dic ;


}  
  
  
  
  
  
  
  
  
