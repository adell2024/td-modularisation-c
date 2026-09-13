#include "pluriel.h"

char *
pluriel(int n)
{
    if (n > 1)
	return "s";
    else
	return "";
}
