/*******************\
|  GTK3 Calculator  |
|  By Alnotz        |
\*******************/
/*
gcc -Wall -Wextra -o gtk3_calc main.c $(pkg-config --libs --cflags gtk+-3.0)
*/
#include "gtk3_calc.h"

int main( int argc, char* argv[])
{
  printf("DÉBUT\n");
  GtkApplication *app;
  int status;

  app=gtk_application_new("fr.alnotz.gtk3_calc", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(app, "activate", G_CALLBACK (activate), NULL);
  status=g_application_run(G_APPLICATION (app), argc, argv);
  g_object_unref(app);
  printf("FIN\n");
  return status;
}
