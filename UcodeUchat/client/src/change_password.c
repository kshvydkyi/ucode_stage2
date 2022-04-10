#include "../inc/client.h"

void change_passwordEditProfile()
{
	gtk_widget_destroy(GTK_WIDGET(err_msg_old_pass_not_match));
	gtk_widget_destroy(GTK_WIDGET(err_msg_new_password_wrong));
	gtk_widget_destroy(GTK_WIDGET(err_msg_confirm_pass_wrong));

    const char *old_password_user_written = gtk_entry_get_text(GTK_ENTRY(Change_pass_old_pass));
    const char *new_pass_user_written = gtk_entry_get_text(GTK_ENTRY(Change_pass_new_pass));
    const char *pass_confirm_user_written = gtk_entry_get_text(GTK_ENTRY(Change_pass_confirm_pass));

    unsigned char *result = mx_strnew1(BUFFER_LEN);
    char *query = sqlite3_mprintf("SELECT password FROM User WHERE user_id = %d", user_id);
    send(client, query, BUFFER_LEN, 0);
    recv(client, result, BUFFER_LEN, 0);
    const unsigned char *old_password = NULL;
    char unsigned **tmp = mx_strsplit1(result, '|');
    for (uint32_t i = 0; tmp[i]; i++)
	{
        unsigned char **tmp1 = mx_strsplit1(tmp[i], '#');
        old_password = tmp1[0];
    }

	if(mx_strcmp1((unsigned char*)old_password,hash((unsigned char*)old_password_user_written)) != 0)
	{
		printf("Password doesn't match with old\n");

		err_msg_old_pass_not_match = GTK_WIDGET(Create_new_button(mainChatLayout, "Password doesn't match with old one!", 1500, 545, 100, 20));

		gtk_style_context_add_class ( gtk_widget_get_style_context ( GTK_WIDGET ( err_msg_old_pass_not_match ) ), "pass_dont_match" );
		gtk_widget_set_sensitive (err_msg_old_pass_not_match, FALSE);
		gtk_button_set_relief(GTK_BUTTON(err_msg_old_pass_not_match), GTK_RELIEF_NONE);

		GtkStyleContext *context_err_msg_old_pass_not_match = gtk_widget_get_style_context(err_msg_old_pass_not_match);
		gtk_style_context_add_provider (context_err_msg_old_pass_not_match, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																	
		gtk_widget_show(err_msg_old_pass_not_match);
	}
    else if (strlen(new_pass_user_written) < 8 || check_strong_password(new_pass_user_written) == false)
	{
		gtk_widget_destroy(GTK_WIDGET(err_msg_old_pass_not_match));

		err_msg_new_password_wrong = GTK_WIDGET(Create_new_button(mainChatLayout, "Password must have 8 chars, 1 uppercase,lowercase,digit", 1500, 630, 100, 20));

		gtk_style_context_add_class ( gtk_widget_get_style_context ( GTK_WIDGET ( err_msg_new_password_wrong ) ), "pass_dont_match" );
		gtk_widget_set_sensitive (err_msg_new_password_wrong, FALSE);
		gtk_button_set_relief(GTK_BUTTON(err_msg_new_password_wrong), GTK_RELIEF_NONE);

		GtkStyleContext *context_err_msg_new_password_wrong = gtk_widget_get_style_context(err_msg_new_password_wrong);
		gtk_style_context_add_provider (context_err_msg_new_password_wrong, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																	
		gtk_widget_show(err_msg_new_password_wrong);
	}
	else if(strcmp(new_pass_user_written,pass_confirm_user_written) != 0)
	{
		gtk_widget_destroy(GTK_WIDGET(err_msg_old_pass_not_match));
		gtk_widget_destroy(GTK_WIDGET(err_msg_new_password_wrong));

		err_msg_confirm_pass_wrong = GTK_WIDGET(Create_new_button(mainChatLayout, "Password doesn't match!", 1500, 710, 100, 20));

		gtk_style_context_add_class ( gtk_widget_get_style_context ( GTK_WIDGET ( err_msg_confirm_pass_wrong ) ), "pass_dont_match" );
		gtk_widget_set_sensitive (err_msg_confirm_pass_wrong, FALSE);
		gtk_button_set_relief(GTK_BUTTON(err_msg_confirm_pass_wrong), GTK_RELIEF_NONE);

		GtkStyleContext *context_err_msg_confirm_pass_wrong = gtk_widget_get_style_context(err_msg_confirm_pass_wrong);
		gtk_style_context_add_provider (context_err_msg_confirm_pass_wrong, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																	
		gtk_widget_show(err_msg_confirm_pass_wrong);
	}
	else
	{
		gtk_widget_destroy(GTK_WIDGET(err_msg_old_pass_not_match));
		gtk_widget_destroy(GTK_WIDGET(err_msg_new_password_wrong));
		gtk_widget_destroy(GTK_WIDGET(err_msg_confirm_pass_wrong));

		char *result1 = mx_strnew(BUFFER_LEN);
		char *query = sqlite3_mprintf("UPDATE User SET password = '%q' WHERE user_id = %d", hash((unsigned char*)new_pass_user_written), user_id);
		send(client, query, BUFFER_LEN, 0);

		GtkWindow *win123 = NULL;
		GtkWidget *widget123 = NULL;
		gpointer data123 = NULL;
		settingsChat(widget123, data123, win123);
	}
}

