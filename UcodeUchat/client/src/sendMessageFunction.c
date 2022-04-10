#include "../inc/client.h"

int msg_count = 0;
int ABOBUS_AVTOBUS = 0;
int n = 0;
bool inherit = false;

void sendMessageFunctionChat(GtkWidget *widget, gpointer data, GtkWindow* win)
{
	// for css
	GtkCssProvider *providerButton = gtk_css_provider_new();
	gtk_css_provider_load_from_path (providerButton, "../client/src/style.css", NULL);
	gtk_widget_show(messageFieldChat);
	gtk_widget_show(messageFieldChat_2);
	const char *text_message = gtk_entry_get_text(GTK_ENTRY(writeInputField));
	char *help_text_message = (char *)text_message;
	gtk_container_add(GTK_CONTAINER(scrollable_w), messageGrid);

	for(int i = 0; i < 1; i++)
	{
		if (strlen(text_message) > 0)
		{
		buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(largeEntry));
		gtk_text_buffer_set_text(buffer, gtk_entry_get_text(GTK_ENTRY(writeInputField)) , 1);	
		
		gtk_container_add(GTK_CONTAINER(scrollable_w), messageGrid);

		for(int i = 0; i < 1; i++)
		{
			if(msg_count % 2 == 0)
			{
				gtk_layout_put(GTK_LAYOUT(mainChatLayout), messageFieldChat, 1700, 64);
			}
			else 
			{
				gtk_layout_put(GTK_LAYOUT(mainChatLayout), messageFieldChat_2, 500, 64);
			}
			// css buttonMessage 
			gtk_widget_set_sensitive (buttonMessage[ABOBUS_AVTOBUS], FALSE);
			buttonMessage[ABOBUS_AVTOBUS] = gtk_button_new_with_label(text_message);
			gtk_style_context_add_class(gtk_widget_get_style_context(GTK_WIDGET(buttonMessage[ABOBUS_AVTOBUS])), "buttonMessageCss");
			gtk_button_set_relief(GTK_BUTTON(buttonMessage[ABOBUS_AVTOBUS]), GTK_RELIEF_NONE);
			GtkStyleContext *context_buttonMessage = gtk_widget_get_style_context(buttonMessage[ABOBUS_AVTOBUS]);
			gtk_style_context_add_provider(context_buttonMessage, GTK_STYLE_PROVIDER(providerButton), GTK_STYLE_PROVIDER_PRIORITY_USER);
			gtk_widget_set_size_request(buttonMessage[ABOBUS_AVTOBUS], message_sizeW(help_text_message), 10);
	
			gtk_grid_attach(GTK_GRID(messageGrid), buttonMessage[ABOBUS_AVTOBUS], 1, msg_count + 1, 1, 1);
			gtk_widget_show(buttonMessage[ABOBUS_AVTOBUS]);
			msg_count++;

			char *result = mx_strnew(BUFFER_LEN);
			send(client, "SELECT id FROM Chat_message", BUFFER_LEN, 0);
			recv(client, result, BUFFER_LEN, 0);
			int id = 0;
			char **tmp1 = mx_strsplit(result, '|');
			for(int i = 0; tmp1[i]; i++) 
			{
				id = mx_atoi(tmp1[i]);
			}
			char *query = sqlite3_mprintf("INSERT INTO Chat_message VALUES (%d, '%q', '%q', '%q');", id+1, mx_itoa(chat_id), text_message, mx_itoa(user_id));
			send(client, query, BUFFER_LEN, 0);
		}
		ABOBUS_AVTOBUS++;
	}
	gtk_entry_set_text((GtkEntry *)writeInputField, "");
	}
}

