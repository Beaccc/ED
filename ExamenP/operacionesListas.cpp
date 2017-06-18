// Aqui os dejo una funcion para realizar la unión de dos listas.

template <class T>
list<T>  Union(const list<T> &l1,const list<T> &l2){
      typename list<T>::const_iterator it2;
      list<T>l3(l1);//construimos l3 como copia de l1

      //insertamos los de l2
      for (it2=l2.begin();it2!=l2.end();it2++)
            l3.insert(l3.end(),*it2);

      //ordenamos
      l3.sort();
      //quitamos los repetidos
      l3.unique();
      return l3;

}


// Aqui os paso un codigo para realizar la intersección de dos listas.

template <class T>
bool Esta(const list <T> &l,const T & d){
   typename list<T>::const_iterator it;
   for (it=l.begin();it!=l.end();++it)
     if (*it==d) return true;
   return false;
}


template <class T>
list<T>  Interseccion(const list<T> &l1,const list<T> &l2){
      typename list<T>::const_iterator it2;
      list<T>l3(l1);//construimos l3 como copia de l1

      //insertamos los de l2 que esten en l1
      for (it2=l2.begin();it2!=l2.end();it2++)
      if (l3.Esta(*it2))
        l3.insert(l3.end(),*it2);

      return l3;

}
