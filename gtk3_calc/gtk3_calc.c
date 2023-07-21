/*******************\
|  GTK3 Calculator  |
|  By Alnotz        |
\*******************/
/*
gcc -Wall -Wextra -o gtk3_calc gtk3_calc.c $(pkg-config --libs --cflags gtk+-3.0)
*/

#include <gtk/gtk.h>
/*Grid dimensions*/
#define B_COLS 5
#define B_ROWS 3
/*Total value*/
double total=0;
/*Operators
 * = -> 0
 * + -> 1
 * - -> 2
 * * -> 3
 * / -> 4
 * [:digit:] -> 5
 */
unsigned int op_flag=0;
/*Current value*/
double current=0;
/*Computing
 * 0;0 ""
 * 1
 * 0;1 "1"
 * 2
 * 0;12 "12"
 * + ()
 * 12;0 "12+"
 * 3
 * 12;3 "12+3"
 * 7
 * 12;37 "12+37"
 * - (12+37)
 * 49;0 "12+37-"
 * 5
 * 49;5 "12+37-5"
 * * (49-5)
 * 44;0 "12+37-5*"
 * 1
 * 44;1 "12+37-5*1"
 * = (44*1)
 * 44;0 "44"
 * + ()
 * 44;0 "44+"
 * 3
 * 44;3 "44+3"
 * = (44+3)
 * 47;0 "47"
*/

static void compute(GtkWidget *label, GtkWidget *button)
{
  const gchar *b_label=gtk_button_get_label(GTK_BUTTON (button));
  const gchar *l_label=gtk_label_get_label(GTK_LABEL (label));
  gchar new_label[256];
  if(!strcmp(b_label, "+") |
    !strcmp(b_label, "-") |
    !strcmp(b_label, "*") |
    !strcmp(b_label, "/"))
  {
    switch(op_flag)
    {
      case 0:
        total=current;
        break;
      case 1:
        total=total+current;
        break;
      case 2:
        total=total-current;
        break;
      case 3:
        total=total*current;
        break;
      case 4:
        total=total/current;
        break;
    }
    if(!strcmp(b_label, "+"))
    {
      op_flag=1;
    }
    else if(!strcmp(b_label, "-"))
    {
      op_flag=2;
    }
    else if(!strcmp(b_label, "*"))
    {
      op_flag=3;
    }
    else if(!strcmp(b_label, "/"))
    {
      op_flag=4;
    }
    sprintf(new_label, "%s%s", l_label, b_label);
    current=0;
  }
  else if(!strcmp(b_label, "="))
  {
    switch(op_flag)
    {
      case 0:
        total=current;
        break;
      case 1:
        total=total+current;
        break;
      case 2:
        total=total-current;
        break;
      case 3:
        total=total*current;
        break;
      case 4:
        total=total/current;
        break;
    }
    op_flag=0;
    sprintf(new_label, "%.0f", total);
    current=0;
  }
  else
  {
    current=10*current+atof(b_label);
    sprintf(new_label, "%s%s", l_label, b_label);
  }
  gtk_label_set_label(GTK_LABEL (label), new_label);
}

/*Terminal output*/
static void clicked(GtkWidget *button, gpointer data)
{
  const gchar* blabel=gtk_button_get_label(GTK_BUTTON (button));
  g_print("%s\n", blabel);
  g_print("%.0f;%.0f\n", total, current);
}

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
        case 13:
          sprintf(l_string, "/");
          break;
        case 14:
          sprintf(l_string, "=");
          break;
        default:
          sprintf(l_string, "%d", l_count);
          break;
      }
      button=gtk_button_new_with_label(l_string); 
      g_signal_connect_swapped(button, "clicked", G_CALLBACK (compute), label);
      g_signal_connect(button, "clicked", G_CALLBACK (clicked), NULL);
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

/*Application*/
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

