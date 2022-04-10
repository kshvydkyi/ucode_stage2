#include "../inc/client.h"

void gtk_hide_widget11()
{
    gpointer data = NULL;
    gtk_widget_hide(tritochkiButtonField);
    gtk_window_close((GtkWindow*)mainChatWindow);
    chat_main(mainChatWindow, data, (GtkWindow*)mainChatWindow);
} 

void tri_tochki_buttonChat(GtkWidget *widget, gpointer data, GtkWindow* win)
{
    // for css
	GtkCssProvider *provider = gtk_css_provider_new();
	gtk_css_provider_load_from_path (provider, "../client/src/style.css", NULL);

    // when we click again
	g_signal_connect(G_OBJECT(tri_tochki_btn), "clicked", G_CALLBACK(gtk_hide_widget11), (GtkWindow*)mainChatWindow);

    gtk_widget_show(tritochkiButtonField);
    gtk_widget_hide(faqField);
    gtk_widget_hide(donateField);
    gtk_widget_hide(deanonField);
    gtk_widget_hide(settingsButtonField);
    gtk_widget_hide(edit_profileField);
	gtk_widget_hide(photo_and_login_Field);
	gtk_widget_hide(peregorodka);
	gtk_widget_hide(peregorodka_2);
	gtk_widget_hide(err_msg_wrong_telepone);
	gtk_widget_hide(err_msg_wrong_name);
	gtk_widget_hide(err_msg_wrong_second_name);
	gtk_widget_hide(err_msg_wrong_email);
	gtk_widget_hide(userNameProfile);
	gtk_widget_hide(users_loginProfile);
	gtk_widget_hide(users_photo);
	gtk_widget_hide(deanonMeButton);
	gtk_widget_hide(backBtnEditProf);
	gtk_widget_hide(backBtnDeanon);
	gtk_widget_hide(backBtnFaq);
	gtk_widget_hide(backBtnDonate);
	gtk_widget_hide(telephNumber);
	gtk_widget_hide(users_name_deanon);
	gtk_widget_hide(users_second_name_deanon);
	gtk_widget_hide(users_email_deanon);  
    gtk_widget_hide(users_loginProfileEdit);
    gtk_widget_hide(usersTelephoneEditProfile);
	gtk_widget_hide(usersNameEditProfile);
	gtk_widget_hide(usersSecondNameEditProfile);
	gtk_widget_hide(usersEmailEditProfile);
}

