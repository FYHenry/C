/*
gcc $(pkg-config --cflags weechat) \
  -shared -fPIC -Wall -Wextra essai.c essai-command.c -o ./essai.so \
  $(pkg-config --libs weechat)
*/
#include <stdlib.h>
#include <weechat/weechat-plugin.h>
#include "essai.h"
#include "essai-command.h"

WEECHAT_PLUGIN_NAME(ESSAI_PLUGIN_NAME);
WEECHAT_PLUGIN_DESCRIPTION(ESSAI_PLUGIN_DESCRIPTION);
WEECHAT_PLUGIN_AUTHOR(ESSAI_PLUGIN_AUTHOR);
WEECHAT_PLUGIN_VERSION(ESSAI_PLUGIN_VERSION);
WEECHAT_PLUGIN_LICENSE(ESSAI_PLUGIN_LICENCE);
WEECHAT_PLUGIN_PRIORITY(ESSAI_PLUGIN_PRIORITY);

struct t_weechat_plugin *weechat_plugin = NULL;

int weechat_plugin_init(struct t_weechat_plugin *plugin,
    int argc,
    char *argv[]){
  weechat_plugin = plugin;
  
  essai_command_init();
      
  weechat_printf(NULL,
      "%sGreffon %sessai%s connecté!%s",
      weechat_color("green"),
      weechat_color("/green"),
      weechat_color("green"),
      weechat_color("reset"));
      
  return WEECHAT_RC_OK;
}

int weechat_plugin_end(struct t_weechat_plugin *plugin){
  weechat_printf(NULL,
      "%sGreffon %sessai%s déconnecté!%s",
      weechat_color("red"),
      weechat_color("/red"),
      weechat_color("red"),
      weechat_color("reset"));
      
  return WEECHAT_RC_OK;
}

