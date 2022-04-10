#include "../inc/client.h"

void gtk_hide_widget10()
{
    gpointer data = NULL;
    gtk_widget_hide(edit_profileField);
    gtk_window_close((GtkWindow*)mainChatWindow);
    chat_main(mainChatWindow, data, (GtkWindow*)mainChatWindow);
}

void editProfileFieldChat(GtkWidget *widget, gpointer data, GtkWindow* win)
{
    // when we click again
	g_signal_connect(G_OBJECT(settingsButton), "clicked", G_CALLBACK(gtk_hide_widget10), (GtkWindow*)mainChatWindow);
    
    gtk_widget_show(edit_profileField);
    gtk_widget_show(users_loginProfile);
    gtk_widget_show(backBtnEditProf);
    gtk_widget_show(users_loginProfileEdit);
    gtk_widget_show(usersTelephoneEditProfile);
	gtk_widget_show(usersNameEditProfile);
	gtk_widget_show(usersSecondNameEditProfile);
	gtk_widget_show(usersEmailEditProfile);
    gtk_widget_show(Change_pass_old_pass);
	gtk_widget_show(Change_pass_new_pass);
	gtk_widget_show(Change_pass_confirm_pass);
    gtk_widget_show(changePasswordButton);

    gtk_widget_hide(users_photo);
    gtk_widget_hide(deanonField);
    gtk_widget_hide(donateField);
    gtk_widget_hide(settingsButtonField);
	gtk_widget_hide(photo_and_login_Field);
	gtk_widget_hide(peregorodka);
	gtk_widget_hide(peregorodka_2);
    gtk_widget_hide(tritochkiButtonField);
    gtk_widget_hide(faqField);
}

