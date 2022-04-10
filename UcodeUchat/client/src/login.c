#include "../inc/client.h"

void button_login_clicked(GtkWidget *widget, gpointer data, GtkWindow* win)
{
	back_button_was_clicked_login = false;
	gtk_window_close((GtkWindow*)mainWindow);

	window_login = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window_login), WIDTH, HEIGHT);
    gtk_window_set_position(GTK_WINDOW(window_login), GTK_WIN_POS_CENTER);

	layout_login = gtk_layout_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER (window_login), layout_login);
    gtk_widget_show(layout_login);

	background_login = gtk_image_new_from_file("../resources/background/login.png");
    gtk_layout_put(GTK_LAYOUT(layout_login), background_login, 0, 0); 
 
	// for css
	GtkCssProvider *provider = gtk_css_provider_new();
	gtk_css_provider_load_from_path (provider, "../client/src/style.css", NULL);

	// input field

	// login
	GtkWidget *passwordLabel, *grid;
    loginEntry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(loginEntry), "anonymous login");
	gtk_entry_set_visibility(GTK_ENTRY(loginEntry), TRUE);
	gtk_layout_put(GTK_LAYOUT(layout_login), loginEntry, 680, 359);
    gtk_widget_set_size_request(loginEntry, 596, 37);

	gtk_style_context_add_class(gtk_widget_get_style_context(GTK_WIDGET(loginEntry)), "loginEntry");
	gtk_button_set_relief(GTK_BUTTON(loginEntry), GTK_RELIEF_NONE);
	GtkStyleContext *context = gtk_widget_get_style_context(loginEntry);
	gtk_style_context_add_provider (context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

	// password
    passwordEntryLogin = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(passwordEntryLogin), "anonymous password");
    gtk_entry_set_visibility(GTK_ENTRY(passwordEntryLogin), FALSE);
	gtk_layout_put(GTK_LAYOUT(layout_login), passwordEntryLogin, 680, 500);
    gtk_widget_set_size_request(passwordEntryLogin, 596, 35);
	gtk_style_context_add_class(gtk_widget_get_style_context(GTK_WIDGET(passwordEntryLogin ) ), "passwordEntryLogin");
	gtk_button_set_relief(GTK_BUTTON(passwordEntryLogin), GTK_RELIEF_NONE);
	GtkStyleContext *context_password = gtk_widget_get_style_context(passwordEntryLogin);
	gtk_style_context_add_provider (context_password, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

    // sign in button
	signInBtn = Create_new_button(layout_login, "", 890, 596, 150, 50); //544, 185
	gtk_style_context_add_class (gtk_widget_get_style_context (GTK_WIDGET (signInBtn)), "signinBtn");
	gtk_button_set_relief(GTK_BUTTON(signInBtn), GTK_RELIEF_NONE);
	gtk_button_set_relief(GTK_BUTTON(signInBtn), GTK_RELIEF_NONE);
	GtkStyleContext *context_signinbtn = gtk_widget_get_style_context(signInBtn);
	gtk_style_context_add_provider (context_signinbtn, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

	// when we click sign in button
	g_signal_connect(G_OBJECT(signInBtn), "clicked", G_CALLBACK(signInBtn_clicked),loginEntry);

	GtkSettings *default_settings = gtk_settings_get_default();
	g_object_set(default_settings, "gtk-button-images", TRUE, NULL);

	// back button
	GtkWidget *backButton = Create_new_button(layout_login, "", 10, 15, 100, 100);
	gtk_style_context_add_class ( gtk_widget_get_style_context ( GTK_WIDGET ( backButton ) ), "backButton");
	gtk_button_set_relief(GTK_BUTTON(backButton), GTK_RELIEF_NONE);
	GtkStyleContext *context_backButton = gtk_widget_get_style_context(backButton);
	gtk_style_context_add_provider(context_backButton, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

	// when we click back button
	if(g_signal_connect(G_OBJECT(backButton), "clicked", G_CALLBACK(main_window), (GtkWindow*)window_login))
	{
		back_button_was_clicked_login = true;
	}

	g_signal_connect_swapped(G_OBJECT(window_login), "destroy", G_CALLBACK(gtk_main_quit), NULL);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
    gtk_widget_show_all(window_login);

    gtk_main();    
}

