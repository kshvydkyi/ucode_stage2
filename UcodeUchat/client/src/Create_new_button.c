#include "../inc/client.h"

gpointer Create_new_button(GtkWidget *layout, char *btn_name, int x, int y, int width, int height)
{
	GtkWidget *button = gtk_button_new_with_label(btn_name);
    gtk_container_add ( GTK_CONTAINER ( layout ), button);
	gtk_layout_put(GTK_LAYOUT(layout), button, x, y);
    gtk_widget_set_size_request(button, width, height);
	return GTK_WIDGET(button);
}

