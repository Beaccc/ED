/**
  * @file pila_maxmin.cpp
  * @brief Fichero de definiciones para insertar la implementacion deseada.
  * @author Mario Rodríguez Ruiz
  * @date Noviembre 2016
  *
  * Incluye la definicion correspondiente del fichero Pila_maxmin.h
  *
  */

#include "pila_maxmin.h" // Definición del valor CUAL_COMPILA

#if CUAL_COMPILA == 1
    #include "pila_maxmin_VD.cpp"
#elif CUAL_COMPILA == 2
    #include "pila_maxmin_list.cpp"
#elif CUAL_COMPILA == 3
    #include "pila_maxmin_cola.cpp"
#endif
