 /**
 * @file refranes.cpp
 * @brief Implementación de la clase Refrán
 *
 * @author Mario Rodríguez Ruiz
 * @date Diciembre 2016
 */

#include "refranes.h"

/*******************************
*      Metodos privados        *
*******************************/

void Refranes::InsertaRefran(ArbolGeneral<string>::Nodo n, string refran, int nivel){
    // Posición dentro del string.
    int pos_ref = 0 ;
    // String auxiliar para ir insertando nodos.
    string aux = "" ;
    // Número de niveles auxiliar para no modificar el original.
    // Si no se especifica por parámetro en el main, por defecto es 3.
    int aux_len = nivel ;

    // Si aún quedan letras del string por incluir..
    if(refran.size() > 0){
        // Si no existe ningún hijo a la izquierda de éste..
        // se incluye directamente en el árbol.
        if(!ab.hijomasizquierda(n)){
            // Se insertan nodos NO hoja, tantos como niveles se hayan indicado.
            for(int i = 0 ; i < aux_len ; i++){
                // Rama que se incluirá en el árbol.
                ArbolGeneral<string> a;
                // Se añade la letra correspondiente al string auxiliar.
                aux.push_back(refran[pos_ref]) ;
                // Se le asigna como raíz el nodo a meter.
                a.AsignaRaiz(aux) ;
                // Se inserta la rama creada en el árbol, siempre en la izquierda
                // porque no existía una antes con letras iguales.
                ab.insertar_hijomasizquierda(n,a);
                ++numero_nodos ;
                // Se incrementa la posición en el refrán.
                pos_ref++ ;
                // Se limpia el string auxiliar para evitar
                // problemas posteriormente.
                aux.clear() ;
                // Ahora el nodo raiz será el que se acaba de crear.
                n = ab.hijomasizquierda(n) ;
                // Se incrementa en 1 los caracteres almacenados.
                ++caracteres_almacenados ;
            }
            // Rama que se incluirá en el árbol.
            ArbolGeneral<string> a;
            // Por si hubiera fallo y se produjera número negativo.
            if(aux_len<=0)
                aux_len = 0 ;
            // Se introduce el resto del refrán en el árbol.
            a.AsignaRaiz(refran.substr(aux_len)) ;
            // que será hoja.
            ab.insertar_hijomasizquierda(n,a);
            ++numero_nodos ;
            // Incrementar caracteres_almacenados, tantos y como
            // sea el tamaño del refrán restante.
            caracteres_almacenados+=refran.substr(aux_len).size() ;
        }
        else{
            // Número de letras a substraer del refrán
            int subs = 0 ;
            // Nodo sobre el que se va a realizar la tarea.
            n = ab.hijomasizquierda(n);
            // Limpiar el string auxiliar para que sea nuevo.
            aux.clear() ;
            // Si el nivel no está en hoja solo se inserta un caracteres
            // sino se inserta todo el refrán restante.
            if(aux_len!=0){
                aux.push_back(refran[0]) ;
                subs = 1 ;
            }
            else{
                aux+=refran ;
                subs = refran.size() ;
            }

            // Movimiento en anchura en el árbol mientras no coincida la letra
            // y hayan hermanos disponibles.
            while((ab.etiqueta(n) != aux) && (ab.hermanoderecha(n)) &&
                  (ab.etiqueta(ab.hermanoderecha(n)) <= aux)
            ){
                n = ab.hermanoderecha(n);
            }
            // Si coincide la letra, se llama recursivamente
            // a esta misma función quitando el caracter actual del string
            // y reduciendo el nivel en uno.
            if(ab.etiqueta(n) == aux){
                InsertaRefran(n, refran.substr(1), aux_len-1);
            }
            // En caso contrario, es que se ha llegado al final del nivel
            // sin encontrar la letra, por lo que se inserta un nuevo subárbol a la derecha.
            else{
                // Inicializamos una nueva rama para el árbol
                ArbolGeneral<string> a;
                // Asignar como raíz el nodo a meter
                a.AsignaRaiz(aux) ;
                // Se coloca el subárbol como hermano a la derecha
                ab.insertar_hermanoderecha(n,a);
                // Se incrementan los almacenados tanto como el valor de subs.
                caracteres_almacenados+=subs ;
                ++numero_nodos ;
                // Se actualiza la posición en el árbol
                n = ab.hermanoderecha(n);
                // Ahora se llamará recursivamente sobre dicho subárbol con la cadena restante
                if(nivel > 0)
                    InsertaRefran(n, refran.substr(subs), aux_len-1);
                // Incrementar en uno el número de refranes.
                ++n_ref ;
            }
        }
    }
}

/******************************
*       Constructores         *
******************************/

//El refran vacío solo tiene una raíz, que no contiene nada.
Refranes::Refranes(){
    ab.AsignaRaiz("") ;
    n_ref = 1 ;
    caracteres_almacenados = 0 ;
    caracteres_totales = 0 ;
    numero_nodos = 1 ;
}

Refranes::Refranes(int lpre){
    len_prefijo = lpre ;
    n_ref = 1 ;
    ab.AsignaRaiz("") ;
    caracteres_almacenados = 0 ;
    caracteres_totales = 0 ;
    numero_nodos = 1 ;
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
    ++itbeg;
    while(itbeg != itend && result == ""){
        // Si es term y las posiciones coinciden
        // ya se obtiene el refrán aleatorio.
        // sino, se incrementa la variable de posición.
        if(pos_bucle == pos && (itbeg).terminal()){
            result = itbeg.cad ;
        }
        else if((itbeg).terminal())
            ++pos_bucle ;

        ++itbeg;
    }
//     cout << "Núm. Refranes: " << size() << endl ;
    return result;
}

//--------------------------------------------------------------------------------



void Refranes::Insertar(const string & refran){
    InsertaRefran(ab.raiz(), refran, len_prefijo) ;
    caracteres_totales += refran.size() ;
}

//--------------------------------------------------------------------------------

pair<bool, Refranes::iterator> Refranes::Esta(const string &refran){
    pair<bool, iterator> res ;
    iterator iter = begin();
    iterator itend = end();
    // Se inicializa el resultado a false.
    res.first = false ;

    // Mientras no se llegue al final o no se encuentre..
    while(iter != itend && !res.first){
        // Si se ha llegado al nodo hoja de la rama
        // y ambas cadenas coinciden...
        if((*iter) == refran && (iter).terminal()){
            res.first = true ;
            res.second = iter ;
        }
        ++iter;
    }

    return res ;
}

//--------------------------------------------------------------------------------

void Refranes::BorrarRefran(ArbolGeneral<string>::Nodo n){
    // Si es la primera rama de la izquierda y no tiene
    // hermano a la derecha.
    if(n->drcha==0 && ab.padre(n)->izqda==n){
        // Nodo auxiliar inicializado como padre de n.
        ArbolGeneral<string>::Nodo aux = ab.padre(n) ;
        // Mientras n no tenga hermanos a la derecha
        // y el padre no sea la raiz.
        while(n->drcha==0 && ab.padre(n)->etiqueta!=""){
            // Se sube al siguiente nivel del árbol
            aux = ab.padre(n) ;
            // Borra el nodo.
            delete n ;
            // Se actualiza n al nodo actual.
            n = aux ;
        }
        // Si se ha encontrado algún hermano..
        if(n->drcha!=0){
            // La izquierda del padre ahora será
            // el hermano de la derecha de n.
            ab.padre(n)->izqda=n->drcha ;
            // Ahora se puede borrar n
            delete n ;
        }
        // Un refrán menos.
        --n_ref ;
    }
    // Cuando n no tiene hermano a la derecha.
    else if(ab.hermanoderecha(n)==0)
    {
        // Booleano para parar el bucle
        bool seguir = true ;
        while(seguir){
            // Nodo auxiliar inicializado como padre de n.
            ArbolGeneral<string>::Nodo aux = ab.padre(n) ;
            // Si la izquierda del padre es él mismo
            if(aux->izqda==n)
                aux->izqda = n->izqda ;
            else{
                // auxiliar es ahora el hijo de la izquierda
                // del padre de n ;
                aux = ab.hijomasizquierda(aux) ;
                // Mientras no se llegue hasta n
                // recorrer los hermanos de la derecha
                while(ab.hermanoderecha(aux)!=n){
                    aux = ab.hermanoderecha(aux) ;
                }
                // El hermano de la izquierda de n
                // ya puede apuntar al hermano de la derecha de n
                // para poder borrarse.
                aux->drcha=ab.hermanoderecha(n) ;
                seguir = false ;
            }

            delete n ;
            n = aux ;
        }
        // Un refrán menos.
        --n_ref ;
    }
    // Si n es el hijo de más izquierda de su padre.
    else if(ab.padre(n)->izqda==n){
        // Ahora su padre apuntará a su hermano derecha
        // para poder borrarlo.
        ab.padre(n)->izqda=ab.hermanoderecha(n) ;
        delete n ;
        // Un refrán menos.
        --n_ref ;
    }
    // Si existe algun hijo del padre de n más a la izquierda
    // y éste no tiene hermanos a la derecha
    else if(ab.padre(n)->izqda != 0 || ab.padre(n)->drcha != 0){
        // Nodo auxiliar inicializado como padre de n.
        ArbolGeneral<string>::Nodo aux = ab.padre(n) ;
        aux = ab.hijomasizquierda(aux) ;
        // Mientras el hermano derecha de aux no sea n.
        while(ab.hermanoderecha(aux)!=n){
            aux = ab.hermanoderecha(aux) ;
        }
        // Ahora ya se puede apuntar de aux al hermano
        // de la derecha de n para borrar a éste.
        aux->drcha=ab.hermanoderecha(n) ;
        delete n ;
        // Un refrán menos.
        --n_ref ;
    }
}
void Refranes::BorrarRefran(const string &refran){
    pair<bool, iterator> res = Esta(refran) ;

    // Si existe, se borra.
    if(res.first){
        BorrarRefran(res.second.getIt().GetNodo()) ;
    }
}

//--------------------------------------------------------------------------------
int Refranes::Caracteres_Refranes()const{
    return caracteres_totales ;
}

//--------------------------------------------------------------------------------

int Refranes::Caracteres_Almacenados(){
    return caracteres_almacenados ;
}

//--------------------------------------------------------------------------------

int Refranes::Numero_Nodos()const{
    return numero_nodos ;
}

//--------------------------------------------------------------------------------


void Refranes::clear(){
    ab.clear() ;
}


/*******************************
*       Metodos iterator       *
*******************************/

string & Refranes::iterator::operator*(){
    return cad;
}

string & Refranes::const_iterator::operator*(){
    return cad;
}

//--------------------------------------------------------------------------------

typename Refranes::iterator & Refranes::iterator::operator++(){
    if (terminal())
	{
        // Tener en cuenta que es un apuntador.
		++it;
        // Nivel actual.
		int level_actual = it.getlevel();

		// Si el nivel es cero es que se ha vuelto a la raiz.
		if (level_actual == 0 || !it)
		{
            // Liberar y inicializar nueva cadena.
			cad = "";
            // Inicializar el nivel a cero.
			level = 0;
			return *this;
		}

        // Si no se ha llegado al tamaño de len_prefijo
        if (level_actual <= level_max)
		{
            // Eliminar tantas letras de la cadena hasta la posición del nivel actual.
			cad.erase(cad.begin()+level_actual,cad.end());
            // Añadir la cadena proveniente del iterador en la anterior modificada.
            cad += ((*it));
            // Actualizar nivel del nodo.
			level = level_actual;
		}

	}
	// Si el nivel es cero y no es terminal.
    else if(level==0){
        // Si la cadena del iterador no está vacía
        // se añade a la cadena actual.
        if((*it)!="")
            cad+=((*it));
        // sino se inicializa de nuevo
        else
            cad="" ;

        // Si ya se ha dado valor a level_max
        // se cancela una posible nueva modificación.
        if(level_max>0){
            primera = false ;
        }
    }

    // Hasta que no sea un nodo hoja
	while (!terminal())
	{
		++it;
        // Se añade la cadena del iterador a la actual.
        cad+=((*it));
        // Incrementar el nivel del nodo.
        level++;
        // Si es el primer refrán, éste servirá
        // para medir el nivel de profundidad.
        if(primera && terminal()){
            level_max = level ;
            primera = false ;
        }
    }

    return *this;
}

typename Refranes::const_iterator & Refranes::const_iterator::operator++(){
    if (terminal())
	{
        // Tener en cuenta que es un apuntador.
		++it;
        // Nivel actual.
		int level_actual = it.getlevel();

		// Si el nivel es cero es que se ha vuelto a la raiz.
		if (level_actual == 0 || !it)
		{
            // Liberar y inicializar nueva cadena.
			cad = "";
            // Inicializar el nivel a cero.
			level = 0;
			return *this;
		}

        // Si no se ha llegado al tamaño de len_prefijo
        if (level_actual <= level_max)
		{
            // Eliminar tantas letras de la cadena hasta la posición del nivel actual.
			cad.erase(cad.begin()+level_actual,cad.end());
            // Añadir la cadena proveniente del iterador en la anterior modificada.
            cad += ((*it));
            // Actualizar nivel del nodo.
			level = level_actual;
		}

	}
	// Si el nivel es cero y no es terminal.
    else if(level==0){
        // Si la cadena del iterador no está vacía
        // se añade a la cadena actual.
        if((*it)!="")
            cad+=((*it));
        // sino se inicializa de nuevo
        else
            cad="" ;

        // Si ya se ha dado valor a level_max
        // se cancela una posible nueva modificación.
        if(level_max>0){
            primera = false ;
        }
    }

    // Hasta que no sea un nodo hoja
	while (!terminal())
	{
		++it;
        // Se añade la cadena del iterador a la actual.
        cad+=((*it));
        // Incrementar el nivel del nodo.
        level++;
        // Si es el primer refrán, éste servirá
        // para medir el nivel de profundidad.
        if(primera && terminal()){
            level_max = level ;
            primera = false ;
        }
    }

    return *this;
}

//--------------------------------------------------------------------------------

bool Refranes::iterator::operator==(const iterator & i) const{
    return (i.it == this->it) && (i.cad == this->cad);
}

bool Refranes::const_iterator::operator==(const const_iterator & i) const{
    return (i.it == this->it) && (i.cad == this->cad);
}

//--------------------------------------------------------------------------------

bool Refranes::iterator::operator!=(const iterator & i) const{
    return (i.it != this->it) || (i.cad != this->cad);
}

bool Refranes::const_iterator::operator!=(const const_iterator & i) const{
    return (i.it != this->it) || (i.cad != this->cad) ;
}

//--------------------------------------------------------------------------------

bool Refranes::iterator::terminal(){
    if(level>0)
        return (it).Hoja();
    else
        return false ;
}

bool Refranes::const_iterator::terminal(){
    if(level>0)
        return (it).Hoja();
    else
        return false ;
}

//--------------------------------------------------------------------------------

ArbolGeneral<string>::iter_preorden Refranes::iterator::getIt(){
    return it ;
}

ArbolGeneral<string>::const_iter_preorden Refranes::const_iterator::getIt(){
    return it ;
}

//--------------------------------------------------------------------------------

typename Refranes::iterator Refranes::begin(){
    iterator iter;
    iter.it = this->ab.begin();
    iter.cad = "";
    return iter;
}

typename Refranes::const_iterator Refranes::begin() const{
    const_iterator iter;
    iter.it = this->ab.begin();
    iter.cad = "";
    return iter;
}

//--------------------------------------------------------------------------------

typename Refranes::iterator Refranes::end(){
    iterator iter;
    iter.it = this->ab.end();
    iter.cad = "";
    return iter;
}

typename Refranes::const_iterator Refranes::end() const{
    const_iterator iter;
    iter.it = this->ab.end();
    iter.cad = "";
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

ostream & operator<<(ostream & os, const Refranes & D){
    Refranes::const_iterator iter = D.begin();
    Refranes::const_iterator itend = D.end();
    // Se evita la raiz.
    ++iter;
    while(iter != itend){
        if((iter).terminal()){
            os << (*iter) << endl;
        }
        ++iter;
    }
    return os;
}
