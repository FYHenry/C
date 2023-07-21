/*******************\
|  GTK3 Calculator  |
|  By Alnotz        |
\*******************/
/*
gcc -Wall -Wextra -o gtk3_calc gtk3_calc.c $(pkg-config --libs --cflags gtk+-3.0)
*/
#ifndef GTK3_CALC_H
#define GTK3_CALC_H
#include <stdio.h>
#include <gtk/gtk.h>

/*Terminal output*/
static void clicked(GtkWidget *button, gpointer data);

/*Window output*/
static void clickedOutput(GtkWidget *label, GtkWidget *button);

/*Window building*/
static void activate(GtkApplication* app, gpointer user_data);

#endif /*GTK3_CALC_H*/

