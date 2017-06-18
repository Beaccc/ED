/**
  * @file pila_max.cpp
  * @brief Fichero de definiciones para insertar la implementacion deseada.
  *
  * Incluye la definicion correspondiente del fichero Pila_max.h
  *
  */

#include "pila_max.h" // Definicion del valor CUAL_COMPILA

#if CUAL_COMPILA == 1
    #include "pila_max_VD.cpp"
#elif CUAL_COMPILA == 2
    #include "pila_max_list.cpp"
#elif CUAL_COMPILA == 3
    #include "pila_max_cola.cpp"
#endif