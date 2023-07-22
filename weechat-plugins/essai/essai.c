/*
gcc \$(pkg-config --cflags weechat) -shared -fPIC -Wall -Wextra essai.c -o essai.so $(pkg-config --libs weechat)
*/
#include <stdlib.h>
#include <weechat/weechat-plugin.h>

WEECHAT_PLUGIN_NAME("essai");
WEECHAT_PLUGIN_DESCRIPTION("Plugin just to test the library :-/");
WEECHAT_PLUGIN_AUTHOR("Alnotz");
WEECHAT_PLUGIN_VERSION("0.1.0");
WEECHAT_PLUGIN_LICENSE("GPL-3.0-or-later");
WEECHAT_PLUGIN_PRIORITY(999);

struct t_weechat_plugin *weechat_plugin = NULL;

int command_essai(const void *pointer,
        void *data,
        struct t_gui_buffer *buffer,
        int argc,
        char **argv,
        char **argv_eol){
    /*Rien*/
    return WEECHAT_RC_OK;
}

int weechat_plugin_init(struct t_weechat_plugin *plugin,
        int argc,
        char *argv[]){
    weechat_plugin = plugin;
    weechat_hook_command("essai",
            "Une commande d’essai",
            "",
            "Aucun paramètre",
            NULL,
            &command_essai,
            NULL,
            NULL);
    return WEECHAT_RC_OK;
}

int weechat_plugin_end(struct t_weechat_plugin *plugins){
    return WEECHAT_RC_OK;
}
