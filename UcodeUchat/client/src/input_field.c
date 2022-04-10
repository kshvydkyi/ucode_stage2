#include "../inc/client.h"

GtkWidget *emailLabel, *emailEntry, *passwordLabel, *passwordEntry, *signupBtn, *grid;

void signup_button_clicked(GtkWidget *wid,gpointer data)
{
    const gchar *emailData = gtk_entry_get_text(GTK_ENTRY(emailEntry)); 
    gtk_label_set_text(GTK_LABEL(data),emailData); 
    gtk_entry_set_text(GTK_ENTRY(emailEntry),"");                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
    gtk_entry_set_text(GTK_ENTRY(passwordEntry),"");
} 

void activate (GtkWidget* window, gpointer user_data)
{
    emailLabel = gtk_label_new("Email:"); 
    emailEntry = gtk_entry_new(); 
    gtk_entry_set_placeholder_text(GTK_ENTRY(emailEntry),"Email");
    GFile *path = g_file_new_for_path("D:/path/emailicon.png"); 
    GIcon *icon = g_file_icon_new(path); 
    gtk_entry_set_icon_from_gicon(GTK_ENTRY(emailEntry), GTK_ENTRY_ICON_PRIMARY, icon); 
    
    passwordLabel = gtk_label_new("Password:");
    passwordEntry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(passwordEntry),"Password");
    gtk_entry_set_visibility(GTK_ENTRY(passwordEntry),FALSE);
    signupBtn = gtk_button_new_with_label("Sign Up");
    GtkWidget *showEmail = gtk_label_new("");

    g_signal_connect(signupBtn, "clicked", G_CALLBACK(signup_button_clicked), showEmail);

    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL,20);
    gtk_box_pack_start(GTK_BOX(box),emailLabel,FALSE,FALSE,0);
    gtk_box_pack_start(GTK_BOX(box),emailEntry,FALSE,FALSE,0);
    gtk_box_pack_start(GTK_BOX(box),passwordLabel,FALSE,FALSE,0);
    gtk_box_pack_start(GTK_BOX(box),passwordEntry,FALSE,FALSE,0); 
    gtk_box_pack_start(GTK_BOX(box),signupBtn,FALSE,FALSE,0); 
    gtk_box_pack_start(GTK_BOX(box),showEmail,FALSE,FALSE,0); 

    gtk_container_add(GTK_CONTAINER(window),box); 
    gtk_widget_show_all (window);
} 

