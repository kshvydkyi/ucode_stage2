#include "../inc/client.h"

void gtk_hide_widget3()
{
    gpointer data = NULL;
    gtk_widget_hide(deanonField);
    gtk_window_close((GtkWindow*)mainChatWindow);
    chat_main(mainChatWindow, data, (GtkWindow*)mainChatWindow);
}

void deanonFieldChat(GtkWidget *widget, gpointer data, GtkWindow* win)
{
    // when we click again
	g_signal_connect(G_OBJECT(settingsButton), "clicked", G_CALLBACK(gtk_hide_widget3), (GtkWindow*)mainChatWindow);
    
    gtk_widget_show(deanonField);
    gtk_widget_show(deanonMeButton);
    gtk_widget_show(backBtnDeanon);
    gtk_widget_show(telephNumber);
	gtk_widget_show(users_name_deanon);
	gtk_widget_show(users_second_name_deanon);
	gtk_widget_show(users_email_deanon);  
    gtk_widget_hide(faqField);
    gtk_widget_hide(donateField);
    gtk_widget_hide(settingsButtonField);
	gtk_widget_hide(photo_and_login_Field);
	gtk_widget_hide(peregorodka);
	gtk_widget_hide(peregorodka_2);
    gtk_widget_hide(tritochkiButtonField);
    gtk_widget_hide(edit_profileField);
    gtk_widget_hide(users_photo);
    gtk_widget_hide(users_loginProfileEdit);
    gtk_widget_hide(usersTelephoneEditProfile);
	gtk_widget_hide(usersNameEditProfile);
	gtk_widget_hide(usersSecondNameEditProfile);
	gtk_widget_hide(usersEmailEditProfile);
    gtk_widget_hide(err_msg_wrong_telepone);
    gtk_widget_hide(err_msg_wrong_name);
    gtk_widget_hide(err_msg_wrong_second_name);
    gtk_widget_hide(err_msg_wrong_email);
}

