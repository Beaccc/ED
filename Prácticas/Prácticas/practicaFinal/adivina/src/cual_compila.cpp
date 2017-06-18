/**
  * @file cual_compila.cpp
  * @brief Fichero de definiciones para insertar la implementacion deseada.
  * @author Mario Rodríguez Ruiz
  * @date Diciembre 2016
  *
  *
  */

#include "cual_compila.h" // Definición del valor CUAL_COMPILA

#if CUAL_COMPILA == 1
    #include "refranes.h"
#elif CUAL_COMPILA == 2
    #include "refranes_hash.h"
#elif
    #include "refranes.h"
#endif
