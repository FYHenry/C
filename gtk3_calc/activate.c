/*******************\
|  GTK3 Calculator  |
|  By Alnotz        |
\*******************/
/*
gcc -Wall -Wextra -o gtk3_calc gtk3_calc.c $(pkg-config --libs --cflags gtk+-3.0)
*/
#include "gtk3_calc.h"
#define B_COLS 4
#define B_ROWS 3

/*Window building*/
static void activate(GtkApplication* app, gpointer user_data)
{
  /*Objects list*/
  GtkWidget *window;
  GtkWidget *box;
  GtkWidget *label;
  GtkWidget *frame;
  GtkWidget *grid;
  GtkWidget *button;
  GtkWidget *buttonQuit;
  char l_string[4];
  int l_count;

  /*Window*/
  window=gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW (window), "Fenêtre");
  gtk_container_set_border_width(GTK_CONTAINER (window), 10);

  /*Box*/
  box=gtk_box_new(GTK_ORIENTATION_VERTICAL, 2);
  gtk_container_add(GTK_CONTAINER (window), box);

  /*Text output*/
  label=gtk_label_new(NULL);
  gtk_container_add(GTK_CONTAINER (box), label);

  /*Grid frame*/
  frame=gtk_frame_new("Grille à boutons");
  gtk_frame_set_shadow_type(GTK_FRAME (frame), GTK_SHADOW_ETCHED_IN);
  gtk_container_add(GTK_CONTAINER (box), frame);
  gtk_widget_set_halign(frame, GTK_ALIGN_CENTER);

  /*Buttons grid*/
  grid=gtk_grid_new();
  gtk_grid_set_column_homogeneous(GTK_GRID (grid), TRUE);
  gtk_grid_set_column_spacing(GTK_GRID (grid), 2);
  gtk_grid_set_row_homogeneous(GTK_GRID (grid), TRUE);
  gtk_grid_set_row_spacing(GTK_GRID (grid), 2);
  gtk_container_add(GTK_CONTAINER (frame), grid);

  /*Buttons*/
  for(int l=0; l<B_ROWS; l++)
  {
    for(int c=0; c<B_COLS; c++)
    {
      l_count=l+c*B_ROWS;
      switch(l_count)
      {
        case 10:
          sprintf(l_string, "+");
          break;
        case 11:
          sprintf(l_string, "-");
          break;
        case 12:
          sprintf(l_string, "*");
          break;
        default:
          sprintf(l_string, "%d", l_count);
          break;
      }
      button=gtk_button_new_with_label(l_string); 
      g_signal_connect(button, "clicked", G_CALLBACK (clicked), NULL);
      g_signal_connect_swapped(button, "clicked", G_CALLBACK (clickedOutput), label);
      gtk_grid_attach(GTK_GRID (grid), button, (gint) l, (gint) c, 1, 1);
    }
  }

  /*Quit button*/
  buttonQuit=gtk_button_new_with_label("Quit");
  g_signal_connect_swapped(buttonQuit, "clicked", G_CALLBACK (gtk_widget_destroy), window);
  gtk_box_pack_end(GTK_BOX (box), buttonQuit, FALSE, TRUE, 2);
  gtk_widget_set_halign(buttonQuit, GTK_ALIGN_CENTER);

  gtk_widget_show_all(window);
}
