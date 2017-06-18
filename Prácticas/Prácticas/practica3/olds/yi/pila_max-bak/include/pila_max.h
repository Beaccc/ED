#define CUAL_COMPILA 1

/**
 * @brief Estructura que guarda cada elemento de la pila.
 * Cada elemento guarda un entero, y un valor máximo,
 * que es el máximo de la pila hasta el momento.
*/


struct elemento{
    int elem;   /**< Valor en del elemento de la pila */
    int max;    /**< Valor máximo en la pila hasta el momento */
};

#if CUAL_COMPILA == 1
    #include "pila_max_VD.h"
#elif CUAL_COMPILA == 2
    #include "pila_max_list.h"
#elif CUAL_COMPILA == 3
    #include "pila_max_cola.h"
#endif