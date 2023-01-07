/*********************\
|**Frédéric Henry*****|
|**SETSIS 2020********|
\*********************/
/* gcc -Wall -Wextra -o invNb invNb.c */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/* Opérateur puissance. */
int puis(int nb, int i)
{
  /* Base. */
  int b=nb;
  /* Multiplications. */
  if(i!=0)
  {
    for(long int j=0; j<i-1; j=j+1)
    {
      nb=nb*b;
    }
    return nb;
  }
  /* Extension nulle. */
  else
  {
    return 1;
  }
}
/* Fonction principale. */
int main(int argc, char* argv[])
{
  /* Aide. */
  if(!strcmp(argv[1],"-h")||!strcmp(argv[1],"--help"))
  {
    printf("Usage : %s -h|--help|NUMBER\n",argv[0]);
    printf("Litteral inverse of NUMBER is returned.\n");
    return EXIT_SUCCESS;
  }
  /* Le nombre entier non signé en entrée. */
  else
  {
    /* Nombre de chiffres. */
    const long int taille = strlen(argv[1]);
    /* Vraiment un nombre entier non signé?
     * Dans ce cas, les caractères sont dans
     * [48;57].
     */
    for(long int i=0; i<taille; i=i+1)
    {
      if(argv[1][i]<48||argv[1][i]>57)
      {
        /* Si non, erreur! */
        return EXIT_FAILURE;
      }
    }
    /* Nombre littéralement inversé. */
    int nb=0;
    for(long int i=0; i<taille; i=i+1)
    {
      nb=nb+(int)(argv[1][taille-i-1]-48)*puis(10,taille-i-1);
    }
    /* Nombre inversé en sortie. */
    printf("%d\n", nb);
    return EXIT_SUCCESS;
  }
}
