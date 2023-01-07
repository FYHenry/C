/**************************************\
|    Alnotz                            |
|    Le générateur de sapin            |
\**************************************/
/* gcc -Wall -Wextra -o sapin sapin.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Une entrée numérique? */
int estNumerique(char chaine[])
{
  size_t taille = strlen(chaine);
  for(size_t i=0; i<taille; i=i+1)
  {
    switch(chaine[i])
    {
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
        break;
      default:
        return 0;
    }
  }
  return 1;
}
/* Bloc d'espaces ou traits */
void multibloc(unsigned long int compteur,unsigned int no)
{
  if(no==0)
  {
    for(unsigned long int i=compteur; i>0; i=i-1)
    {
      printf("    ");
    }
  }
  if(no==1)
  {
    for(unsigned long int i=compteur; i>0; i=i-1)
    {
      printf("____");
    }
  }
}
/* Fonction principale */
int main(int argc, char* argv[])
{
  if(argc<2)
  {
    printf("Pas d'argument? Ça sent le sapin!\n");
    return EXIT_FAILURE;
  }
  /* Aide */
  if(!strcmp(argv[1],"-h")||!strcmp(argv[1],"--help"))
  {
    printf("Commande : ");
    printf("%s",argv[0]);
    printf(" -h | --help | NOMBRE\n");
    printf("-h | --help\t\tDonne l\'aide.\n");
    printf("NOMBRE\t\tConstruit l\'arbre sur NOMBRE étages.\n");
    return EXIT_SUCCESS;
  }
  if(!estNumerique(argv[1]))
  {
    printf("Tape un nombre!\n");
    return EXIT_FAILURE;
  }
  /* Texte => Nombre */
  unsigned long int hauteur = strtoul(argv[1],argv,10);
  /* Étoile du soir */
  multibloc(hauteur-1,0);
  printf("   __/\\__\n");
  multibloc(hauteur-1,0);
  printf("   \\    /\n");
  multibloc(hauteur-1,0);
  printf("    \\/\\/\n");
  multibloc(hauteur-1,0);
  printf("____/  \\____\n");
  /* Étages */
  for(unsigned long int i=hauteur-1; i>0; i=i-1)
  {
    /* Ligne 0 */
    multibloc(i,0);
    printf("\\ ");
    multibloc(2*(hauteur-i),0);
    printf(" /\n");
    /* Ligne 1 */
    multibloc(i-1,0);
    multibloc(1,1);
    printf("_\\");
    multibloc(2*(hauteur-i),0);
    printf("/_");
    multibloc(1,1);
    printf("\n");
  }
  /* Dernier étage. */
  printf("\\ ");
  multibloc(2*hauteur,0);
  printf(" /\n \\");
  multibloc(2*hauteur,1);
  printf("/ \n");
  /* Tronc */
  for(unsigned long int i=0; i<hauteur; i=i+1)
  {
    multibloc(hauteur,0);
    printf("|  |\n");
  }
  /* Sol */
  multibloc(hauteur,0);
  printf("|__|\n");
  /* FINI! */
  return EXIT_SUCCESS;
}
