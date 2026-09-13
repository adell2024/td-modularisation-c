#include <stdio.h>
#include "generateur.h"
#include "formater.h"
#include "nouveau_symbole.h"

#define SYMBOLE_PREFIXE "__GLB_"
#define SYMBOLE_SUFFIXE "__"

char *
nouveau_symbole(void)
{
    int n = generateur();
    char *symbole = formater(String, SYMBOLE_PREFIXE, Int, n,
                             String, SYMBOLE_SUFFIXE, Eop);
    return symbole;
}
