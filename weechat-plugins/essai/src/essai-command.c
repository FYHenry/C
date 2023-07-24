#include <stdlib.h>
#include <weechat/weechat-plugin.h>
#include "essai.h"
#include "essai-command.h"

int essai_args_command(struct t_gui_buffer *buffer,
    int argc,
    char **argv,
    char **argv_eol){
  weechat_printf(buffer,
      "Nombre d’arguments : %s%d%s",
      weechat_color("blue"),
      argc,
      weechat_color("reset"));

  for(int i=0; i<argc; i++){
    weechat_printf(buffer,
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

  return WEECHAT_RC_OK;
}

int essai_version_command(struct t_gui_buffer *buffer,
    int argc,
    char **argv,
    char **argv_eol){
  const char *weechat_version = weechat_info_get("version", NULL);
  weechat_printf(buffer,
      "Version de WeeChat : %s%s%s\n"
      "Version du greffon : %s" ESSAI_PLUGIN_VERSION "%s",
      weechat_color("green"),
      weechat_version,
      weechat_color("reset"),
      weechat_color("green"),
      weechat_color("reset"));

  free((void*) weechat_version);

  return WEECHAT_RC_OK;
}

int essai_command(const void *pointer,
    void *data,
    struct t_gui_buffer *buffer,
    int argc,
    char **argv,
    char **argv_eol){
  int weechat_rc = 0;
  
  if(weechat_buffer_match_list(buffer,
      "core.weechat")){
    int i = 1;
    while(i<argc){
      if(!weechat_strcmp(argv[i], "-arg")){
        weechat_rc = essai_args_command(NULL,
            argc,
            argv,
            argv_eol);

        break;
      } else if(!weechat_strcmp(argv[i], "-version") ||
          !weechat_strcmp(argv[i], "-v")){
        essai_version_command(buffer,
            argc,
            argv,
            argv_eol);

        break;
      }
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
      "Une commande d’essai.",
      "[-arg | -version]",
      "    -arg : essai sur les arguments,\n"
      "-version : versions.",
      "-arg %- || -version %-",
      &essai_command,
      NULL,
      NULL);
}
    
