#include "../inc/client.h"

void gtk_hide_widget1()
{
    gpointer data = NULL;
    gtk_widget_hide(donateField);
    gtk_window_close((GtkWindow*)mainChatWindow);
    chat_main(mainChatWindow, data, (GtkWindow*)mainChatWindow);
}

void donateFieldChat(GtkWidget *widget, gpointer data, GtkWindow* win)
{
    // when we click again
	g_signal_connect(G_OBJECT(settingsButton), "clicked", G_CALLBACK(gtk_hide_widget1), (GtkWindow*)mainChatWindow);
    
    gtk_widget_show(donateField);
    gtk_widget_show(backBtnDonate);
 
    gtk_widget_hide(users_photo);
    gtk_widget_hide(settingsButtonField);
	gtk_widget_hide(photo_and_login_Field);
	gtk_widget_hide(peregorodka);
	gtk_widget_hide(peregorodka_2);
    gtk_widget_hide(faqField);
    gtk_widget_hide(deanonField);
    gtk_widget_hide(tritochkiButtonField);
    gtk_widget_hide(edit_profileField);
    gtk_widget_hide(users_loginProfileEdit);
    gtk_widget_hide(usersTelephoneEditProfile);
	gtk_widget_hide(usersNameEditProfile);
	gtk_widget_hide(usersSecondNameEditProfile);
	gtk_widget_hide(usersEmailEditProfile);
}

