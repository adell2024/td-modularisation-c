#include <stdio.h>
#include <stdlib.h>
#include "pluriel.h"
#include "nouveau_symbole.h"

int 
main(int argc, char *argv[])
{
    int n = argc > 1 ? atoi(argv[1]) : 0;

    printf("- Production de %d symbole%s :\n", n, pluriel(n));
    while (n-- > 0)
    {
	char *symb = nouveau_symbole();

	printf("\"%s\"\n", symb);
	free(symb);
    }
    return EXIT_SUCCESS;
}
