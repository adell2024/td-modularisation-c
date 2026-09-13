#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../pluriel.h"
#include "../generateur.h"
#include "../nouveau_symbole.h"
#include "mini_test.h"

int main(void)
{
    printf("Tests unitaires\n");
    printf("===============\n\n");

    /* ---- pluriel : fonction pure, ordre indifferent ---- */
    printf("pluriel :\n");
    TEST("pluriel(0) -> \"\"");
    ASSERT_STR("", pluriel(0));
    TEST("pluriel(1) -> \"\"");
    ASSERT_STR("", pluriel(1));
    TEST("pluriel(2) -> \"s\"");
    ASSERT_STR("s", pluriel(2));
    TEST("pluriel(5) -> \"s\"");
    ASSERT_STR("s", pluriel(5));

    /* ---- generateur : compteur static, valeurs 1, 2, 3 ---- */
    printf("\ngenerateur :\n");
    TEST("1er appel -> 1");
    ASSERT_INT(1, generateur());
    TEST("2e appel -> 2");
    ASSERT_INT(2, generateur());
    TEST("3e appel -> 3");
    ASSERT_INT(3, generateur());

    /* ---- nouveau_symbole : utilise generateur, donc continue a 4, 5, 6 ---- */
    printf("\nnouveau_symbole :\n");

    char *s1 = nouveau_symbole();
    TEST("symbole suivant -> \"__GLB_4__\"");
    ASSERT_STR("__GLB_4__", s1);
    free(s1);

    char *s2 = nouveau_symbole();
    TEST("symbole suivant -> \"__GLB_5__\"");
    ASSERT_STR("__GLB_5__", s2);
    free(s2);

    char *s3 = nouveau_symbole();
    TEST("symbole suivant -> \"__GLB_6__\"");
    ASSERT_STR("__GLB_6__", s3);
    free(s3);

    BILAN();
}
