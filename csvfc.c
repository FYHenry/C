/*****************************************\
|* Code C pour lire un fichier CSV.      *|
|*                                       *|
|* Auteur : Frederic Henry.              *|
|* Note : On peut surement faire mieux ! *|
\*****************************************/
/*g++ -Wall -Wextra -c csvfc.c && g++ -Wall -Wextra csvfc.o -o csvfc && ./csvfc;*/
/* Bibliotheques standards de C 90. */
/* Entree/sortie & fichiers. */
#include <stdio.h>
/* Caracteres. */
#include <string.h>
/* Controles de procedures. */
#include <stdlib.h>
/* Lignes. */
#define LINES 8
/* Colonnes. */
#define ROWS 6
/* Fonction secondaire. */
/* Un texte d'aide pour connaître les commandes. */
/* Une seule commande ici : '-h' pour l'aide. X-) */
void helper(void)/* Que du texte... :-| */
{
  printf("/*********************************************\\\n");
  printf("|* Section d'aide pour le programme 'csvfc'. *|\n");
  printf("|*                                           *|\n");
  printf("|* csvfc [-h|--help]                         *|\n");
  printf("|*                                           *|\n");
  printf("\\*********************************************/\n");
  printf("Pour manipuler ce programme, il suffit d'avoir");
  printf(" le fichier 'csvin.csv' dans le meme repertoire.\n\n");
  printf(" Contenu de 'csvin.csv' :\n");
  printf("\"X\",\"Y\",\"Z\",\"U\",\"V\",\"P\"\n");
  printf("1,1,1,1,1,1\n");
  printf("2,2,2,2,2,2\n");
  printf("3,3,3,3,3,3\n");
  printf("4,4,4,4,4,4\n");
  printf("5,5,5,5,5,5\n");
  printf("6,6,6,6,6,6\n");
  printf("7,7,7,7,7,7\n");
  printf("8,8,8,8,8,8\n\n");
  printf("Apres ca, on execute 'csvf'.\n");
}
/* Fonction principale. */
int main(int argc, char** argv)
{
  /* Avant de commencer, a-t-on ajoute une option ? */
  if (argc == 2)/* Si une option... */
  {
    /* En cas d'option '-h' ou '--help'... */
    if (strcmp(argv[1],"--help")==0 || strcmp(argv[1],"-h")==0)
    {
      /* Page d'aide invoquee. */
      helper();
      /* Fin du programme avec succes. */
      exit(EXIT_SUCCESS);
    }
  }
  /* Texte memorise. */
  char text[LINES+1][5*ROWS-1];
  /* Indices ligne/colonne. */
  char i,j;
  /* Matrice d'entiers. */
  int matrix[LINES][ROWS];
  /* Pour s'assurer la fin de chaque ligne.
   * Une ligne = une sous-chaine.
   */
  for (i=1; i<ROWS; i=i+1)
  {
    text[i][5*ROWS-1-1]='\0';
  }
  /* Pour la deco. car j'aime ca. :-D */
  printf("/*****************************************\\\n");
  printf("|* Code C++ pour lire un fichier CSV.    *|\n");
  printf("|*                                       *|\n");
  printf("|* Auteur : Frederic Henry.              *|\n");
  printf("|* Note : On peut surement faire mieux ! *|\n");
  printf("\\*****************************************/\n\n");
  printf("Lecture de \"./csvin.csv\"...\n");
  /* Lecture de fichier texte avec "FILE*". */
  FILE* entree;
  entree = fopen("./csvin.csv","r");
  printf("Table CSV (en-tete) :\n");
  /* Ligne 0 lue. */
  fscanf(entree,"%s",text[0]);
  printf("%s\n",text[0]);
  /* Les autres lignes. */
  printf("Table CSV (corps) :\n");
  for (i=1; i<LINES+1; i=i+1)
  {
    fscanf(entree,"%s",text[i]);
    printf("%s\n",text[i]);
  }
  /* Lecture integrale. */
  printf("Table CSV (tout) :\n");
  for (i=0; i<LINES+1; i=i+1)
  {
    printf("%s\n",text[i]);
  }
  printf("\n");
  /* Fermeture du fichier. */
  fclose(entree);
  /* Affichage du tableau de caracteres. */
  printf("Version tableau de caracteres :\n");
  /* En-tete. */
  for (j=0; j<ROWS; j=j+1)
  {
    printf("%c ",text[0][4*j+1]);
  }
  /* Corps. */
  printf("\n");
  for (i=1; i<LINES+1; i=i+1)
  {
    for (j=0; j<ROWS; j=j+1)
    {
      printf("%c ",text[i][2*j]);
    }
    printf("\n");
  }
  printf("\n");
  /* Pareil, facon nombres entiers. */
  printf("Version tableau d'entiers :\n");
  /* Conversion du texte a la matrice entiere. */
  for (i=0; i<LINES; i=i+1)
  {
    for (j=0; j<ROWS; j=j+1)
    {
      matrix[i][j]=(int)text[i+1][2*j]-48;
    }
  }
  /* Affichage de la matrice. */
  for (i=0; i<LINES; i=i+1)
  {
    for (j=0; j<ROWS; j=j+1)
    {
      printf("%d ",matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  /* Ce coup-ci, ecriture de tableau dans un fichier. */
  printf("Ecriture d'un tableau CSV \"./csvout.csv\"...\n");
  FILE* sortie;
  sortie = fopen("csvout.csv","w");
  /* Dabord l'en-tete. */
  fprintf(sortie,"\"X\",\"Y\",\"Z\",\"U\",\"V\",\"P\"\n");
  /* En suite le corps. */
  for (i=0; i<LINES; i=i+1)
  {
    for (j=0; j<ROWS-1; j=j+1)
    {
      fprintf(sortie,"%d,",matrix[i][j]);
    }
    fprintf(sortie,"%d\n",matrix[i][ROWS-1]);
  }
  /* Fichier ferme. */
  fclose(sortie);
  printf("\n");
  /* Fini. */
  printf("Fin\n");
  /* Pour dire que tout a bien marche. */
  return EXIT_SUCCESS;
}

