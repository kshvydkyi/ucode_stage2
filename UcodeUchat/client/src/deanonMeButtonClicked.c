#include "../inc/client.h"

bool isChar(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
  
bool isDigit(const char c)
{
    return (c >= '0' && c <= '9');
}
  
bool is_valid_email(const char *email)
{
    if (!isChar(email[0]))
    {
        return 0;
    }
    int At = -1, Dot = -1;

    for (int i = 0; email[i]; i++)
    {
        if (email[i] == '@')
        {
            At = i;
        }
        else if (email[i] == '.') 
        {
            Dot = i;
        }
    }
  
    if (At == -1 || Dot == -1)
    {
        return 0;
    }
  
    if (At > Dot)
    {
        return 0;
    }
  
    // If Dot is present at the end
    return !(Dot >= (mx_strlen(email) - 1));
}

bool check_digits_in_arr(const char *arr)
{
    if(arr[0] != '+')
    {
        return false;
    }
    for(int i = 1; arr[i]; i++)
    {
        if(!isdigit(arr[i]))
        {
            return false;
        }
    }
    return true;
}

bool check_if_dog(const char *arr)
{
    for(int i = 0; arr[i]; i++)
    {
        if(arr[i] == '@')
        {
            return true;
        }
    }
    return false;
}

bool check_valid_name(const char *s)
{
    for(int i = 0; s[i]; i++)
    {
        if((s[i]>=65 && s[i]<=90)|| (s[i]>=97 && s[i]<=122))
        {
          continue;
        }
        else if(s[i]>=48 && s[i]<=57)
        {
            return false;
        }
        else
        {
            return false;
        }
    }
    return true;
}

void deanonMeButtonClicked(GtkWidget *widget, gpointer data, GtkWidget* widget1)
{
    
    if(strlen(gtk_entry_get_text(GTK_ENTRY(telephNumber))) != 13 || check_digits_in_arr(gtk_entry_get_text(GTK_ENTRY(telephNumber))) == false)
    {
        
        err_msg_wrong_telepone = GTK_WIDGET(Create_new_button(mainChatLayout, "Phone number must looks like this: +380111111111!", 1500, 205, 100, 20));

		gtk_style_context_add_class ( gtk_widget_get_style_context ( GTK_WIDGET ( err_msg_wrong_telepone ) ), "err_msg_login_exists" );
		gtk_widget_set_sensitive (err_msg_wrong_telepone, FALSE);
		gtk_button_set_relief(GTK_BUTTON(err_msg_wrong_telepone), GTK_RELIEF_NONE);

		GtkStyleContext *context_err_msg_wrong_telepone = gtk_widget_get_style_context(err_msg_wrong_telepone);
		gtk_style_context_add_provider (context_err_msg_wrong_telepone, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																	
		gtk_widget_show(err_msg_wrong_telepone);
    }
    else if(check_valid_name(gtk_entry_get_text(GTK_ENTRY(users_name_deanon))) == false || strlen(gtk_entry_get_text(GTK_ENTRY(users_name_deanon))) < 2)
    {      
        gtk_widget_hide(err_msg_wrong_telepone);
        
        err_msg_wrong_name = GTK_WIDGET(Create_new_button(mainChatLayout, "Name must not contain digits and special characters!",1485,300,100,20));

		gtk_style_context_add_class ( gtk_widget_get_style_context ( GTK_WIDGET ( err_msg_wrong_name ) ), "err_msg_login_exists" );
		gtk_widget_set_sensitive (err_msg_wrong_name, FALSE);
		gtk_button_set_relief(GTK_BUTTON(err_msg_wrong_name), GTK_RELIEF_NONE);

		GtkStyleContext *context_err_msg_wrong_name= gtk_widget_get_style_context(err_msg_wrong_name);
		gtk_style_context_add_provider (context_err_msg_wrong_name, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																	
		gtk_widget_show(err_msg_wrong_name);
    }
    else if(check_valid_name(gtk_entry_get_text(GTK_ENTRY(users_second_name_deanon))) == false || strlen(gtk_entry_get_text(GTK_ENTRY(users_second_name_deanon))) < 4)
    {
        gtk_widget_hide(err_msg_wrong_telepone);
        gtk_widget_hide(err_msg_wrong_name);
        
        err_msg_wrong_second_name = GTK_WIDGET(Create_new_button(mainChatLayout, "Name must not contain digits and special characters!",1485,390,100,20));

		gtk_style_context_add_class ( gtk_widget_get_style_context ( GTK_WIDGET ( err_msg_wrong_second_name ) ), "err_msg_login_exists" );
		gtk_widget_set_sensitive (err_msg_wrong_second_name, FALSE);
		gtk_button_set_relief(GTK_BUTTON(err_msg_wrong_second_name), GTK_RELIEF_NONE);

		GtkStyleContext *context_err_msg_wrong_second_name = gtk_widget_get_style_context(err_msg_wrong_second_name);
		gtk_style_context_add_provider (context_err_msg_wrong_second_name, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																	
		gtk_widget_show(err_msg_wrong_second_name);
    }
    else if(is_valid_email(gtk_entry_get_text(GTK_ENTRY(users_email_deanon))) == false || strlen(gtk_entry_get_text(GTK_ENTRY(users_email_deanon))) < 4  )
    {
        gtk_widget_hide(err_msg_wrong_telepone);
        gtk_widget_hide(err_msg_wrong_name);
        gtk_widget_hide(err_msg_wrong_second_name);
        
        err_msg_wrong_email = GTK_WIDGET(Create_new_button(mainChatLayout, "Email must looks like this: name@name!",1500,470,100,20));

		gtk_style_context_add_class ( gtk_widget_get_style_context ( GTK_WIDGET ( err_msg_wrong_email ) ), "err_msg_login_exists" );
		gtk_widget_set_sensitive (err_msg_wrong_email, FALSE);
		gtk_button_set_relief(GTK_BUTTON(err_msg_wrong_email), GTK_RELIEF_NONE);

		GtkStyleContext *context_err_msg_wrong_email = gtk_widget_get_style_context(err_msg_wrong_email);
		gtk_style_context_add_provider (context_err_msg_wrong_email, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																	
		gtk_widget_show(err_msg_wrong_email);
    }
    else
    {
        gtk_widget_destroy(err_msg_wrong_telepone);
        gtk_widget_destroy(err_msg_wrong_name);
        gtk_widget_destroy(err_msg_wrong_second_name);
        gtk_widget_destroy(err_msg_wrong_email);

        char *result = mx_strnew(BUFFER_LEN);
        send(client, "SELECT user_id FROM User_profile", BUFFER_LEN, 0);
        recv(client, result, BUFFER_LEN, 0);
        char **tmp1 = mx_strsplit(result, '|');
        bool uid = false;
        for(int i = 0; tmp1[i]; i++) 
        {
            if(user_id == mx_atoi(tmp1[i]))
            {
                uid = true;
            }
        }
        send(client, "SELECT id FROM User_profile", BUFFER_LEN, 0);
        recv(client, result, BUFFER_LEN, 0);
        int id = 0;
        char **tmp2 = mx_strsplit(result, '|');
        for(int i = 0; tmp2[i]; i++) 
        {
            id = mx_atoi(tmp1[i]);
        }

        char *query = NULL;
        if(uid == false)
        {
            query = sqlite3_mprintf("INSERT INTO User_profile VALUES (%d, '%q', '%q', '%q', '%q', %d);", id+1, gtk_entry_get_text(GTK_ENTRY(users_name_deanon)), gtk_entry_get_text(GTK_ENTRY(users_second_name_deanon)), gtk_entry_get_text(GTK_ENTRY(telephNumber)), gtk_entry_get_text(GTK_ENTRY(users_email_deanon)), user_id);
        }
        else
        {
            query = sqlite3_mprintf("UPDATE User_profile SET Name = '%q', Last_Name = '%q', Phone = '%q', Email = '%q' WHERE user_id = %d", gtk_entry_get_text(GTK_ENTRY(users_name_deanon)), gtk_entry_get_text(GTK_ENTRY(users_second_name_deanon)), gtk_entry_get_text(GTK_ENTRY(telephNumber)), gtk_entry_get_text(GTK_ENTRY(users_email_deanon)), user_id);
        }
        send(client, query, BUFFER_LEN, 0);
        
        settingsChat(widget, data, (GtkWindow*)deanonField);
    }
}

