#include "../inc/client.h"

gpointer Create_new_button1(GtkWidget *layout, const char *btn_name, int x, int y, int width, int height)
{
	GtkWidget *button = gtk_button_new_with_label(btn_name);
    gtk_container_add ( GTK_CONTAINER ( layout ), button);
	gtk_layout_put(GTK_LAYOUT(layout), button, x, y);
    gtk_widget_set_size_request(button, width, height);
	return GTK_WIDGET(button);
}

void searchAccountFound(char *name)
{
    char *result = mx_strnew(BUFFER_LEN);
    char *query = sqlite3_mprintf("SELECT login FROM User WHERE user_id = %d", mx_atoi(namePersonFound));
    send(client, query, BUFFER_LEN, 0);
    recv(client, result, BUFFER_LEN, 0);
    char *Login = NULL;
    char **tmp = mx_strsplit(result, '|');
    for (int i = 0; tmp[i]; i++)
    {
        char **tmp1 = mx_strsplit(tmp[i], '#');
        Login = tmp1[0];
    }

    gtk_entry_set_text((GtkEntry *)searchInputField, "");
    gtk_widget_hide(PersonFound);
    PersonFound = Create_new_button1(mainChatLayout, Login, 500, 20, search_person_Witdth, 30); 
    gtk_style_context_add_class (gtk_widget_get_style_context (GTK_WIDGET (PersonFound)), "PersonFound");
    gtk_button_set_relief(GTK_BUTTON(PersonFound), GTK_RELIEF_NONE);
    GtkStyleContext *context_PersonFound = gtk_widget_get_style_context(PersonFound);
    gtk_style_context_add_provider (context_PersonFound, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    gtk_widget_set_sensitive (PersonFound, FALSE);
    gtk_widget_show(PersonFound);
    gtk_widget_show(searchedPeopleField);
	gtk_widget_show(emOtpravkaInputField);
	gtk_widget_show(emojiiBtn);
	gtk_widget_show(otpravkaBtn);
    gtk_widget_show(writeInputField);
}

