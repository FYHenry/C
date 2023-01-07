/*********************\
|  WCPlus             |
|  By Alnotz          |
\*********************/
/*
gcc -fPIC -Wall -Wextra -o wcplus.o `/usr/bin/pkg-config --libs --cflags weechat` -c wcplus.c
gcc -shared -fPIC -Wall -Wextra -o wcplus.so wcplus.o
*/
#include <stdlib.h>
#include <weechat-plugin.h>
#define VERBOSE_MASKS_SIZE 3
#define HELP_MASKS_SIZE 3
struct t_weechat_plugin *weechat_plugin = NULL;
WEECHAT_PLUGIN_NAME("WCPlus");
WEECHAT_PLUGIN_DESCRIPTION("Juste une autre extension");
WEECHAT_PLUGIN_AUTHOR("Alnotz <alnotz@protonmail.com>");
WEECHAT_PLUGIN_VERSION("0.2");
WEECHAT_PLUGIN_LICENSE("GNU GPLv3");
WEECHAT_PLUGIN_PRIORITY(999);
void arg_test(int argc,
              char **argv)
{
  weechat_printf(NULL, "%s###########%s", weechat_color("*green"), weechat_color("reset"));
  weechat_printf(NULL, "%sTotal d’arguments: %s%d%s", weechat_color("red"), weechat_color("*blue"), argc, weechat_color("reset"));
  for(int i=0; i<argc; i=i+1)
  {
    weechat_printf(NULL, "%sArgument n°%d: %s%s%s", weechat_color("red"), i, weechat_color("*blue"), argv[i], weechat_color("reset"));
  }
  weechat_printf(NULL, "%s###########%s", weechat_color("*green"), weechat_color("reset"));
}
int command_truc(const void *pointer,
                 void *data,
                 struct t_gui_buffer *buffer,
                 int argc,
                 char **argv,
                 char **argv_eol)
{
  (void) pointer;
  (void) data;
  (void) buffer;
  (void) argv_eol;
  if(argc == 1)
  {
    weechat_printf(NULL, "Tu peux taper `%s/truc -help%s`.", weechat_color("*white"), weechat_color("reset"));
  }
  else
  {
    unsigned char verbose_flag = 0;
    unsigned char help_flag = 0;
    for(int i=1; i<argc; i=i+1)
    {
      const char *verbose_masks[VERBOSE_MASKS_SIZE] = {"-v", "-verbose", NULL};
      const char *help_masks[HELP_MASKS_SIZE] = {"-h", "-help", NULL};
      if(weechat_string_match_list(argv[i], verbose_masks, 1) && verbose_flag == 0)
      {
        verbose_flag = 1;
      }
      if(weechat_string_match_list(argv[i], help_masks, 1) && help_flag == 0)
      {
        help_flag = 1;
      }
    }
    if(verbose_flag == 1)
    {
      arg_test(argc, argv);
    }
    if(help_flag == 1)
    {
      weechat_printf(NULL, "Maintenant tu peux taper `%s/help truc%s`.\n:-P", weechat_color("*white"), weechat_color("reset"));
    }
  }
  return WEECHAT_RC_OK;
}
int command_truc_options(const void *pointer,
                         void *data,
                         const char *completion_item,
                         struct t_gui_buffer *buffer,
                         struct t_gui_completion *completion)
{
  (void) pointer;
  (void) data;
  (void) completion_item;
  (void) buffer;
  weechat_completion_list_add (completion, "-verbose", 0, WEECHAT_LIST_POS_END);
  weechat_completion_list_add (completion, "-help", 0, WEECHAT_LIST_POS_END);
  return WEECHAT_RC_OK;
}
int weechat_plugin_init (struct t_weechat_plugin *plugin,
                         int argc, char *argv[])
{
  weechat_plugin = plugin;
  weechat_hook_completion("truc_options",
                        "Complétion des options de `truc`",
                        &command_truc_options,
                        NULL,
                        NULL);
  weechat_hook_command("truc",
                       "C’est une commande d'essai.",
                       "[-v|-verbose] [-h|-help]",
                       "-h|-help : Aide\n"
                       "-v|-verbose : Débogage",
                       "%(truc_options) %(truc_options)",
                       &command_truc,
                       NULL,
                       NULL);
  weechat_printf(NULL, "%sExtension chargée!%s", weechat_color("*red"), weechat_color("reset"));
  return WEECHAT_RC_OK;
}
int weechat_plugin_end (struct t_weechat_plugin *plugin)
{
  (void) plugin;
  weechat_printf(NULL, "%sExtension dé-chargée!%s", weechat_color("*red"), weechat_color("reset"));
  return WEECHAT_RC_OK;
}
