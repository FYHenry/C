/*********************\
|  By Alnotz          |
|                     |
|  ASCIIQuarium App   |
\*********************/
/*
gcc asciiquarium.c -wall -wextra -o asciiquarium $( pkg-config ncurses --cflags --libs )
*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <curses.h>

struct aq_init_random_objects
{
  struct add_ship;
	struct add_whale;
	struct add_monster;
	struct add_big_fish;
	struct add_shark;
	struct add_fishhook;
	struct add_swan;
	struct add_ducks;
	struct add_dolphins;
} aq_iro;

struct aq_depth
{
  /* no gui yet */
	int guiText;
	int gui;

	/* under water */
	int shark;
	int fish_start;
	int fish_end;
	int seaweed;
	int castle;

	/* waterline */
	int water_line3;
	int water_gap3;
	int water_line2;
	int water_gap2;
	int water_line1;
	int water_gap1;
	int water_line0;
	int water_gap0;
} aq_d = { .guiText = 0,
  .gui = 1,
  .shark = 2,
  .fish_start = 3,
  .fish_end = 20,
  .seaweed = 21,
  .castle = 22,
  .water_line3 = 2,
  .water_gap3 = 3,
  .water_line2 = 4,
  .water_gap2 = 5,
  .water_line1 = 6,
  .water_gap1 = 7,
  .water_line0 = 8,
  .water_gap0 = 9 };

struct aq_add_environment
{
  char water_line_segment[4][35];
} addenv = {"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",
  "^^^^ ^^^  ^^^   ^^^    ^^^^      ",
  "^^^^      ^^^^     ^^^    ^^     ",
  "^^      ^^^^      ^^^    ^^^^^^  "};
  
int segment_size;

time_t aq_start_time;
int aq_paused = 0;

int length(char *array)
{
  return ((int)sizeof(array))/((int)sizeof(array[0]));
}

int main(int argc, char* argv[])
{
  initscr();
  if(has_colors() == FALSE)
  {
    endwin();
    printf("Pas de couleur supportée par ce terminal\n");
    exit(EXIT_FAILURE);
  }
  start_color();
  init_pair(1, COLOR_RED, COLOR_BLACK);
  aq_start_time = time(NULL);
  aq_paused = 0;
  /*tile the segments so they stretch across the screen*/
  
  segment_size = length(addenv.water_line_segment[0]);
  
  printw("Salut");
  halfdelay(1);
  refresh();
  getch();
  endwin();
  return EXIT_SUCCESS;
}

