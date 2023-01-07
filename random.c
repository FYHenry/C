/*
 * Fichier : random.c
 * Auteur : Frédéric Henry
 * Diplôme : Lpro Vision robotique
 * Date : 23/10/2018
 * Version : 0.1
 */
/* En-tête : Bibliothèque standard pour I/O. */
#include <stdio.h>
/* En-tête : Bibliothèque standard pour "rand()" et "random()". */
#include <stdlib.h>
/* Taille du tableau. */
#define N 128
/* Valeur aléatoire maximale. */
#define MAXI 2147483648
/* Fonction principale.
 * Un programme pour étudier la fonction "random()",
 *  la distribution uniforme et celle normale.
 */
int main(void)
{
    unsigned i ;
    unsigned j ;
    short int flag0 = 0 ;
    short int flag1 = 1 ;
    long int maximum = 0 ;
    long int minimum = MAXI ;
    long int alea ;
    unsigned table[N] ;
    /* Remplissage de zéros. */
    for (i=0;i<N;i=i+1)
    {
        table[i] = 0 ;
    }
    printf("Randomness values :\n") ;
    for(i=0;i<10000;i=i+1)
    {
        /* Création de valeur aléatoire. */
        alea = 0 ;
        for (j=0;j<16;j=j+1)
        {
            /* diviser atténue l'amplitude. */
            alea = random()/16 + alea ;
        }
        /* Classement  croissant des valeurs. */
        for (j=0;j<N;j=j+1)
        {
            /* Multiplier élargit les intervalles. */
            if (alea > MAXI / N * j && alea < MAXI / N * (j+1))
            {
                table[j] = table[j] + 1 ;
                j = N ;
            }
        }
        /* Recherche des extremums. */
        if (maximum < alea)
        {
            maximum = alea ;
        }
        if (minimum > alea)
        {
            minimum = alea ;
        }
       /* printf("N%02u = %010ld\n", i, alea) ; */
    }
    printf("Highest number : %ld\n", minimum) ;
    printf("Highest number : %ld\n", maximum) ;
    /* Multiples binaires. */
    alea = 1 ;
    i = 0 ;
    while (alea < maximum)
    {
        alea = alea * 2 ;
        i = i + 1 ;
        if (alea > minimum && flag1 == 1)
        {
            printf("2^%2u = %ld\n", i, alea) ;
            flag1 = 0 ;
        }
    }
    printf("2^%2u = %ld\n", i, alea) ;
    /* Graphe */
    printf("Graph :\n\n") ;
    for (i=0;i<N;i=i+1)
    {
        printf("[ %03u / %03d ]\t", i+1, N) ;
        /* Sauter des valeurs atténue l'amplitude. */
        for (j=0;j<table[i];j=j+2)
        {
            printf("|") ;
        }
        printf("\n") ;
    }
    return 0 ;
}
