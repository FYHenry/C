/*******************\
|  GTK3 Calculator  |
|  By Alnotz        |
\*******************/
/*
gcc -Wall -Wextra -o gtk3_calc gtk3_calc.c $(pkg-config --libs --cflags gtk+-3.0)
*/

#include "gtk3_calc.h"

/*Terminal output*/
static void clicked(GtkWidget *button, gpointer data)
{
  const gchar* blabel=gtk_button_get_label(GTK_BUTTON (button));
  g_print("%s\n", blabel);
}

/*Window output*/
static void clickedOutput(GtkWidget *label, GtkWidget *button)
{
  const gchar* blabel=strcat((char *) gtk_label_get_label(GTK_LABEL (label)),
    (char *) gtk_button_get_label(GTK_BUTTON (button)));
  gtk_label_set_label(GTK_LABEL (label), blabel);
}
