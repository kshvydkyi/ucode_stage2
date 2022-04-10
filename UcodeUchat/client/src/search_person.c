#include "../inc/client.h"

void search_person(GtkWidget *widget, gpointer data, GtkWidget* widget123)
{   
    gtk_widget_hide(searchedPeopleField);
    gtk_widget_hide(searchePeopleUsernameButton);   
    char *result = mx_strnew(BUFFER_LEN);
	send(client, "SELECT Name, Last_name, user_id FROM User_profile", BUFFER_LEN, 0);
	recv(client, result, BUFFER_LEN, 0);
    int count = 1;
	char **tmp = mx_strsplit(result, '|');
    for (int i = 0; tmp[i]; i++)
    {
        char **tmp1 = mx_strsplit(tmp[i], '#');
        if(mx_atoi(tmp1[2]) == mx_atoi(gtk_entry_get_text(GTK_ENTRY(searchInputField))) && mx_atoi(tmp1[2]) != user_id)
        {
            chat_id = check_chat_id(mx_atoi(tmp1[2]), user_id);
            search_person_Witdth = search_person_sizeW(gtk_entry_get_text(GTK_ENTRY(searchInputField)));
            searchePeopleUsernameButton = Create_new_button(mainChatLayout, (char*)gtk_entry_get_text(GTK_ENTRY(searchInputField)), 80, 80, search_person_Witdth, 40); 
            gtk_style_context_add_class (gtk_widget_get_style_context (GTK_WIDGET (searchePeopleUsernameButton)), "search_name_clicked");
            gtk_button_set_relief(GTK_BUTTON(searchePeopleUsernameButton), GTK_RELIEF_NONE);
            GtkStyleContext *context_searchePeopleUsernameButton = gtk_widget_get_style_context(searchePeopleUsernameButton);
            gtk_style_context_add_provider (context_searchePeopleUsernameButton, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
            gtk_widget_hide(searchePeopleUsernameButton);
            namePersonFound = gtk_entry_get_text(GTK_ENTRY(searchInputField));
            g_signal_connect(G_OBJECT(searchePeopleUsernameButton), "clicked", G_CALLBACK(searchAccountFound), (void *)namePersonFound);
            gtk_widget_show(searchedPeopleField);
            gtk_widget_show(searchePeopleUsernameButton);
            break;
        }
    }
}

