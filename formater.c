#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include "exit_if.h"
#include "erreurs.h"
#include "formater.h"

#define TBLOC 256
#define TAILLE_TAMPON_FORMATAGE 64

static char *tampon;
static int position;
static int taille;

static void
verifier_tampon(int extension)
{
    if (position + extension < taille)
	return;
    do
	taille += TBLOC;
    while (position + extension >= taille);
    tampon = realloc(tampon, taille);
    EXIT_IF(tampon == NULL, err_realloc);
}

char *
formater(formaterTypes debut, ...)
{
    va_list parametres;

    va_start(parametres, debut);

    formaterTypes specification = debut;

    tampon = malloc(TBLOC);
    EXIT_IF(tampon == NULL, err_malloc);
    position = 0;
    taille = TBLOC;

    int taille_extension;
    char *p;    
    while (true)
    {
	char tampon_de_formatage[TAILLE_TAMPON_FORMATAGE];

        switch (specification)
        {
          case Char:
	  {
	      char c = va_arg(parametres, int);

	      taille_extension =
		  snprintf(tampon_de_formatage, 
			   sizeof tampon_de_formatage, "%c", c);
	      p = tampon_de_formatage;
	      break;
	  }
          case Int:
	  {
	      int i = va_arg(parametres, int);

	      taille_extension = 
		  snprintf(tampon_de_formatage, 
			   sizeof tampon_de_formatage, "%d", i);
	      p = tampon_de_formatage;
	      break;
	  }
          case Double:
	  {
	      double x = va_arg(parametres, double);

	      taille_extension = 
		  snprintf(tampon_de_formatage, 
			   sizeof tampon_de_formatage, "%g", x);
	      p = tampon_de_formatage;
	      break;
	  }
          case String:
	  {
	      p = va_arg(parametres, char *);
	      taille_extension = strlen(p);
	      break;
	  }
	  case Eop :
	  {
	      char *resultat = malloc(strlen(tampon) + 1);
    
	      EXIT_IF(tampon == NULL, err_malloc);
	      strcpy(resultat, tampon);
	      free(tampon);
	      return resultat;
	  }
        }
	
	verifier_tampon(taille_extension);
	strcpy(tampon+position, p);
	position += taille_extension;
	specification = va_arg(parametres, formaterTypes);
    }
}
