/**
 * @file cual_compila.h
 * @brief Fichero de definiciones para insertar la implementacion deseada.
 *
 * @author Mario Rodríguez Ruiz
 * @date Diciembre 2016
*/

#define CUAL_COMPILA 1

#if CUAL_COMPILA == 1
    #include "refranes.h"
#elif CUAL_COMPILA == 2
    #include "refranes_hash.h"
#elif
    #include "refranes.h"
#endif

