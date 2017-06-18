// Mario Rodríguez Ruiz
/*
 Tenemos un contenedor de pares de elementos, {clave, vector<int>} definida
como:
    template <typename T>
    class contenedor{
        private:
            unordered_map<T, vector<int> > datos;
        .............
        .............
    }
Implementa un iterador que itere sobre los elementos que cumplan la propiedad de
que la suma de los elementos del vector<int> sea un número impar. Han de
implementarse (aparte de las de la clase iteradora) las funciones begin() y end().


*/

#include <iostream>
#include <list>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <unordered_map>

using namespace std;

template <typename T>
class contenedor{
    private:
        unordered_map<T, vector<int> > datos;

    public:
        contenedor(){}

        ~contenedor(){
            datos.clear() ;
        }

        class const_iter ;

        class iter{
            private:
                typename unordered_map<T, vector<int> >::iterator it;

            public:
                iter(){}

                pair<T, vector<int>> &operator*(){
                    return *it ;
                }

                iter & operator++(){


                    return *this ;
                }

                bool operator ==(const iter i)const{
                    return i.it == it ;
                }

                bool operator !=(const iter i)const{
                    return i.it != it ;
                }

                friend class contenedor ;
                friend class const_iter ;
        };

        class const_iter{
            private:
                typename unordered_map<T, vector<int> >::const_iterator it;

            public:
                const_iter(){}

                pair<T, vector<int>> &operator*(){
                    return *it ;
                }

                bool operator ==(const const_iter i)const{
                    return i.it == it ;
                }

                bool operator !=(const const_iter i)const{
                    return i.it != it ;
                }

                friend class contenedor ;
        };

        iter begin(){
            iter i ;
            i.it = datos.begin() ;
            return i ;
        }

        iter end(){
            iter i ;
            i.it = datos.end() ;
            return i ;
        }

        const_iter begin()const{
            const_iter i ;
            i.it = datos.begin() ;
            return i ;
        }

        const_iter end()const{
            const_iter i ;
            i.it = datos.end() ;
            return i ;
        }
};


int main(){


}  
  
  
  
  
  
  
  
  
