#include "../inc/client.h"

void button_register_clicked(GtkWidget *widget,gpointer data, GtkWindow* win)
{
	back_button_was_clicked_register = false;
	gtk_window_close((GtkWindow*)mainWindow);
	       
	window_register = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window_register), WIDTH, HEIGHT);
    gtk_window_set_position(GTK_WINDOW(window_register), GTK_WIN_POS_CENTER);

	layout_register = gtk_layout_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER (window_register), layout_register);
    gtk_widget_show(layout_register);

	background_register = gtk_image_new_from_file("../resources/background/register.png");
    gtk_layout_put(GTK_LAYOUT(layout_register), background_register, 0, 0); 

	// for css
	GtkCssProvider *provider = gtk_css_provider_new();
	gtk_css_provider_load_from_path (provider, "../client/src/style.css", NULL);

	// login
	GtkWidget *passwordLabel, *grid;
    GtkWidget *loginEntry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(loginEntry), "anonymous login");
	gtk_entry_set_visibility(GTK_ENTRY(loginEntry),TRUE);
	gtk_layout_put(GTK_LAYOUT(layout_register), loginEntry, 683, 361);
    gtk_widget_set_size_request(loginEntry, 589, 35);
	gtk_style_context_add_class ( gtk_widget_get_style_context ( GTK_WIDGET ( loginEntry ) ), "loginEntry" );
	gtk_button_set_relief(GTK_BUTTON(loginEntry), GTK_RELIEF_NONE);
	GtkStyleContext *context = gtk_widget_get_style_context(loginEntry);
	gtk_style_context_add_provider (context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

	// password
    passwordEntryRegister = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(passwordEntryRegister), "anonymous password");
    gtk_entry_set_visibility(GTK_ENTRY(passwordEntryRegister), FALSE);
	gtk_layout_put(GTK_LAYOUT(layout_register), passwordEntryRegister, 683, 500);
    gtk_widget_set_size_request(passwordEntryRegister, 589, 35);
	gtk_style_context_add_class(gtk_widget_get_style_context(GTK_WIDGET(passwordEntryRegister ) ), "passwordEntryLogin" );
	gtk_button_set_relief(GTK_BUTTON(passwordEntryRegister), GTK_RELIEF_NONE);
	GtkStyleContext *context_password = gtk_widget_get_style_context(passwordEntryRegister);
	gtk_style_context_add_provider (context_password, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

	// confirm password
    ConfirmPasswordEntryRegister = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(ConfirmPasswordEntryRegister), "confirm anonymous password");
    gtk_entry_set_visibility(GTK_ENTRY(ConfirmPasswordEntryRegister),FALSE);
	gtk_layout_put(GTK_LAYOUT(layout_register), ConfirmPasswordEntryRegister, 683, 638);
    gtk_widget_set_size_request(ConfirmPasswordEntryRegister, 589, 35);
	gtk_style_context_add_class ( gtk_widget_get_style_context ( GTK_WIDGET ( ConfirmPasswordEntryRegister ) ), "passwordEntryLogin" );
	gtk_button_set_relief(GTK_BUTTON(ConfirmPasswordEntryRegister), GTK_RELIEF_NONE);
	GtkStyleContext *context_cofirm_password;
	context_cofirm_password = gtk_widget_get_style_context(ConfirmPasswordEntryRegister);
	gtk_style_context_add_provider (context_cofirm_password, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

	// sign up button
	signUpBtn = Create_new_button(layout_register, "", 890, 738, 150, 50);
	gtk_style_context_add_class (gtk_widget_get_style_context (GTK_WIDGET(signUpBtn)), "signupBtn" );
	gtk_button_set_relief(GTK_BUTTON(signUpBtn), GTK_RELIEF_NONE);
	gtk_button_set_relief(GTK_BUTTON(signUpBtn), GTK_RELIEF_NONE);
	GtkStyleContext *context_signupbtn = gtk_widget_get_style_context(signUpBtn);
	gtk_style_context_add_provider (context_signupbtn, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

	// when we click sign in button
	g_signal_connect(G_OBJECT(signUpBtn), "clicked", G_CALLBACK(signUpBtn_clicked),loginEntry);
	// back button

	GtkSettings *default_settings = gtk_settings_get_default();
	g_object_set(default_settings, "gtk-button-images", TRUE, NULL);	

	GtkWidget *backButton = Create_new_button(layout_register, "", 10, 15, 100, 100);
	gtk_style_context_add_class( gtk_widget_get_style_context( GTK_WIDGET(backButton) ), "backButton" );
	
	gtk_button_set_relief(GTK_BUTTON(backButton), GTK_RELIEF_NONE);

	GtkStyleContext *context_backButton = gtk_widget_get_style_context(backButton);
	gtk_style_context_add_provider(context_backButton, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

	// when we click back button
	if(g_signal_connect(G_OBJECT(backButton), "clicked", G_CALLBACK(main_window), (GtkWindow*)window_register))
	{
		back_button_was_clicked_register = true;
	}

	g_signal_connect_swapped(G_OBJECT(window_register), "destroy", G_CALLBACK(gtk_main_quit), NULL);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
    gtk_widget_show_all(window_register);

    gtk_main();    
}

