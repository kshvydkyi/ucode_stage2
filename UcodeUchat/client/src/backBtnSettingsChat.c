#include "../inc/client.h"

void backBtnSettingsChat(GtkWidget *widget, gpointer data, GtkWidget* widget1)
{
    gtk_widget_show(settingsButtonField);
    gtk_widget_hide(widget1);
}

