#include "generateur.h"

#define VALEUR_INITIALE 1

int 
generateur(void)
{
    static int valeur = VALEUR_INITIALE;

    return valeur++;
}
