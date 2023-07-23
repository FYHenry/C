#include <stdlib.h>
#include <weechat/weechat-plugin.h>
#include "essai.h"
#include "essai-command.h"

int essai_command(const void *pointer,
    void *data,
    struct t_gui_buffer *buffer,
    int argc,
    char **argv,
    char **argv_eol){
  int weechat_rc;
  
  if(weechat_buffer_match_list(buffer,
      "core.weechat")){
    weechat_printf(NULL,
        "Nombre d’arguments : %s%d%s\n"
        "Commande 0 : %s%s%s\n"
        "Commande 0 (fin de ligne) : %s%s%s",
        weechat_color("blue"),
        argc,
        weechat_color("reset"),
        weechat_color("green"),
        argv[0],
        weechat_color("reset"),
        weechat_color("green"),
        argv_eol[0],
        weechat_color("reset"));
    for(int i=1; i<argc; i++){
      weechat_printf(NULL,
          "Commande %d : %s%s%s\n"
          "Commande %d (fin de ligne) : %s%s%s",
          i,
          weechat_color("green"),
          argv[i],
          weechat_color("reset"),
          i,
          weechat_color("green"),
          argv_eol[i],
          weechat_color("reset"));
    }
    weechat_rc = WEECHAT_RC_OK;
  } else {
    weechat_printf(NULL,
        "Il n’y a que dans ce tampon que la commande %s/essai%s est possible.",
        weechat_color("italic"),
        weechat_color("-italic"));
    weechat_rc = WEECHAT_RC_ERROR;
  }
  return weechat_rc;
}

void essai_command_init(){
  weechat_hook_command("1000|essai",
      "Une commande d’essai",
      "[version]",
      "version : description du greffon",
      "version %-",
      &essai_command,
      NULL,
      NULL);
}
    
