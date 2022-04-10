#include "../inc/client.h"

void chat_main(GtkWidget *widget, gpointer data, GtkWindow* win)
{	
	logoutbtn_was_clicked = false;
    if(signUp_button_was_clicked == true)
	{
		chat_id = -1;
        gtk_window_close((GtkWindow*)window_register);
    }
    else if(signIn_button_was_clicked == true)
	{
		chat_id = -1;
        gtk_window_close((GtkWindow*)window_login);
    }
    mainChatWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(mainChatWindow), WIDTH, HEIGHT);
    gtk_window_set_position(GTK_WINDOW(mainChatWindow), GTK_WIN_POS_CENTER);

	mainChatLayout = gtk_layout_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER (mainChatWindow), mainChatLayout);
    gtk_widget_show(mainChatLayout);

	GtkWidget *mainchatBackground = gtk_image_new_from_file("../resources/background/chat.png");
    gtk_layout_put(GTK_LAYOUT(mainChatLayout), mainchatBackground, 0, 0); 

	// for css
	GtkCssProvider *provider = gtk_css_provider_new();
	gtk_css_provider_load_from_path (provider, "../client/src/style.css", NULL);

	GtkSettings *default_settings = gtk_settings_get_default();
	g_object_set(default_settings, "gtk-button-images", TRUE, NULL);

	{   // message field
		messageFieldChat = gtk_grid_new();
		gtk_container_add (GTK_CONTAINER (mainChatWindow), messageFieldChat);

		gtk_layout_put(GTK_LAYOUT(mainChatLayout), messageFieldChat, 1700, 64);
		gtk_widget_set_size_request(messageFieldChat, 100, 10);

		gtk_style_context_add_class ( gtk_widget_get_style_context ( GTK_WIDGET ( messageFieldChat ) ), "messageFieldChatMain");

		gtk_button_set_relief(GTK_BUTTON(messageFieldChat), GTK_RELIEF_NONE);
		GtkStyleContext *context_messageFieldChat = gtk_widget_get_style_context(messageFieldChat);
		gtk_style_context_add_provider(context_messageFieldChat, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

	
		GtkStyleContext *context;
		GtkAdjustment *hadjust = gtk_adjustment_new(0, 0, 50, 20, 1, 5);
		GtkAdjustment *vadjust = gtk_adjustment_new(50, 0, 50, 1, 100, 50);
		scrollable_w = gtk_scrolled_window_new(hadjust, vadjust);
		gtk_scrolled_window_set_min_content_width((GtkScrolledWindow*)scrollable_w, 400);
		gtk_scrolled_window_set_max_content_width((GtkScrolledWindow*)scrollable_w, 400);
		gtk_scrolled_window_set_min_content_height((GtkScrolledWindow*)scrollable_w, 950);
		gtk_scrolled_window_set_max_content_height((GtkScrolledWindow*)scrollable_w, 950);
		gtk_scrolled_window_set_propagate_natural_width((GtkScrolledWindow*)scrollable_w, TRUE);

		messageGrid = gtk_grid_new();
		gtk_grid_set_column_homogeneous((GtkGrid*)messageGrid, TRUE);
		gtk_grid_attach(GTK_GRID(messageFieldChat), messageGrid, 0, 10, 1440, 10);
		gtk_container_add(GTK_CONTAINER(scrollable_w), messageGrid);
		gtk_grid_attach(GTK_GRID(messageFieldChat), scrollable_w, 0, 1, 1, 1);
	}


	{   // message field 2
		messageFieldChat_2 = gtk_grid_new();
		gtk_container_add (GTK_CONTAINER (mainChatWindow), messageFieldChat_2);

		gtk_layout_put(GTK_LAYOUT(mainChatLayout), messageFieldChat_2, 500, 64);
		gtk_widget_set_size_request(messageFieldChat_2, 100, 10);

		gtk_style_context_add_class ( gtk_widget_get_style_context ( GTK_WIDGET ( messageFieldChat_2 ) ), "messageFieldChatMain");

		gtk_button_set_relief(GTK_BUTTON(messageFieldChat_2), GTK_RELIEF_NONE);
		GtkStyleContext *context_messageFieldChat_2 = gtk_widget_get_style_context(messageFieldChat_2);
		gtk_style_context_add_provider(context_messageFieldChat_2, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

		GtkAdjustment *hadjust_2 = gtk_adjustment_new(0, 0, 50, 20, 1, 5);
		GtkAdjustment *vadjust_2 = gtk_adjustment_new(50, 0, 50, 1, 100, 50);
		GtkWidget *scrollable_w_2 = gtk_scrolled_window_new(hadjust_2, vadjust_2);
		gtk_scrolled_window_set_min_content_width((GtkScrolledWindow*)scrollable_w_2, 400);
		gtk_scrolled_window_set_max_content_width((GtkScrolledWindow*)scrollable_w_2, 400);
		gtk_scrolled_window_set_min_content_height((GtkScrolledWindow*)scrollable_w_2, 950);
		gtk_scrolled_window_set_max_content_height((GtkScrolledWindow*)scrollable_w_2, 950);
		gtk_scrolled_window_set_propagate_natural_width((GtkScrolledWindow*)scrollable_w_2, TRUE);

		GtkWidget *messageGrid_2 = gtk_grid_new();
		gtk_grid_set_column_homogeneous((GtkGrid*)messageGrid_2, TRUE);
		gtk_grid_attach(GTK_GRID(messageFieldChat_2), messageGrid_2, 0, 10, 1440, 10);
		gtk_container_add(GTK_CONTAINER(scrollable_w_2), messageGrid_2);
		gtk_grid_attach(GTK_GRID(messageFieldChat_2), scrollable_w_2, 0, 1, 1, 1);
	}
	

	


	{// settingsButton_field
		int settingsW = 380;
		int settingsH = 60;
		int peregorodkaPOS = 0;
		int edit_profilePOS = 1;
		int notificationsPOS = 2;
		int deanonPOS = 3; 
		int chat_settingsPOS = 4;
		int foldersPOS = 5;
		int advanced_settingsPOS = 6;
		int languagePOS = 7;
		int faqPOS = 8;
		int donatePOS = 9;	
		int messageW = 0;
		int messageH = 0;
		settingsButtonField = gtk_grid_new();
		gtk_container_add (GTK_CONTAINER (mainChatWindow), settingsButtonField);

		gtk_layout_put(GTK_LAYOUT(mainChatLayout), settingsButtonField, 1500, 182);
		gtk_widget_set_size_request(settingsButtonField, 380, 600);

		gtk_style_context_add_class ( gtk_widget_get_style_context ( GTK_WIDGET ( settingsButtonField ) ), "settingsButtonField");

		gtk_button_set_relief(GTK_BUTTON(settingsButtonField), GTK_RELIEF_NONE);
		GtkStyleContext *context_settingsButtonField = gtk_widget_get_style_context(settingsButtonField);
		gtk_style_context_add_provider(context_settingsButtonField, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

		{ // edit profile field
			edit_profileField = gtk_grid_new();
			gtk_container_add (GTK_CONTAINER (mainChatWindow), edit_profileField);

			gtk_layout_put(GTK_LAYOUT(mainChatLayout), edit_profileField, 1500, 70);
			gtk_widget_set_size_request(edit_profileField, 380, 718);

			gtk_style_context_add_class ( gtk_widget_get_style_context ( GTK_WIDGET ( edit_profileField ) ), "editProfileField");

			gtk_button_set_relief(GTK_BUTTON(edit_profileField), GTK_RELIEF_NONE);
			GtkStyleContext *context_edit_profileField = gtk_widget_get_style_context(edit_profileField);
			gtk_style_context_add_provider(context_edit_profileField, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

			{ // CHANGING PASSWORD   // OLD PASSWORD
				Change_pass_old_pass = gtk_entry_new();
				gtk_widget_set_size_request(Change_pass_old_pass, 344, 10);
				gtk_layout_put(GTK_LAYOUT(mainChatLayout), Change_pass_old_pass, 1520, 520);
				gtk_style_context_add_class (gtk_widget_get_style_context (GTK_WIDGET (Change_pass_old_pass)), "deanonGraph");
				gtk_button_set_relief(GTK_BUTTON(Change_pass_old_pass), GTK_RELIEF_NONE);
				GtkStyleContext *context_Change_pass_old_pass = gtk_widget_get_style_context(Change_pass_old_pass);
				gtk_style_context_add_provider (context_Change_pass_old_pass, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
				gtk_entry_set_visibility(GTK_ENTRY(Change_pass_old_pass), FALSE);
			}
			
			{ // CHANGING PASSWORD  // New password
				Change_pass_new_pass = gtk_entry_new();
				gtk_widget_set_size_request(Change_pass_new_pass, 344, 10);
				gtk_layout_put(GTK_LAYOUT(mainChatLayout), Change_pass_new_pass, 1520, 600);
				gtk_style_context_add_class (gtk_widget_get_style_context (GTK_WIDGET (Change_pass_new_pass)), "deanonGraph");
				gtk_button_set_relief(GTK_BUTTON(Change_pass_new_pass), GTK_RELIEF_NONE);
				GtkStyleContext *context_Change_pass_new_pass = gtk_widget_get_style_context(Change_pass_new_pass);
				gtk_style_context_add_provider (context_Change_pass_new_pass, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
				gtk_entry_set_visibility(GTK_ENTRY(Change_pass_new_pass), FALSE);
			}	

			{ // CHANGING PASSWORD  // Confirm new password
				Change_pass_confirm_pass = gtk_entry_new();
				gtk_widget_set_size_request(Change_pass_confirm_pass, 344, 10);
				gtk_layout_put(GTK_LAYOUT(mainChatLayout), Change_pass_confirm_pass, 1520, 685);
				gtk_style_context_add_class (gtk_widget_get_style_context (GTK_WIDGET (Change_pass_confirm_pass)), "deanonGraph");
				gtk_button_set_relief(GTK_BUTTON(Change_pass_confirm_pass), GTK_RELIEF_NONE);
				GtkStyleContext *context_Change_pass_confirm_pass= gtk_widget_get_style_context(Change_pass_confirm_pass);
				gtk_style_context_add_provider (context_Change_pass_confirm_pass, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
				gtk_entry_set_visibility(GTK_ENTRY(Change_pass_confirm_pass), FALSE);
			}

			{ // change password button
				
				changePasswordButton = Create_new_button(mainChatLayout, "", 1620, 735, 122, 33); 
				gtk_style_context_add_class (gtk_widget_get_style_context (GTK_WIDGET (changePasswordButton)), "changePasswordButton");
				
				gtk_button_set_relief(GTK_BUTTON(changePasswordButton), GTK_RELIEF_NONE);

				gtk_button_set_relief(GTK_BUTTON(changePasswordButton), GTK_RELIEF_NONE);
				GtkStyleContext *context_changePasswordButton = gtk_widget_get_style_context(changePasswordButton);
				gtk_style_context_add_provider (context_changePasswordButton, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

				// when we click deanon me button
				g_signal_connect(G_OBJECT(changePasswordButton), "clicked", G_CALLBACK(change_passwordEditProfile), (GtkWindow*)mainChatWindow);

			}
		
			{ // back button
				backBtnEditProf = Create_new_button(mainChatLayout, "", 1502, 71, 23, 40); 
				gtk_style_context_add_class (gtk_widget_get_style_context (GTK_WIDGET (backBtnEditProf)), "backBtnDonate");
				gtk_button_set_relief(GTK_BUTTON(backBtnEditProf), GTK_RELIEF_NONE);
				GtkStyleContext *context_backBtnEditProf = gtk_widget_get_style_context(backBtnEditProf);
				gtk_style_context_add_provider (context_backBtnEditProf, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

				// when we click edit profile button
				g_signal_connect(G_OBJECT(backBtnEditProf), "clicked", G_CALLBACK(settingsChat), edit_profileField);
			}

			char *result = mx_strnew(BUFFER_LEN);
			char *query = sqlite3_mprintf("SELECT Name, Last_name, Phone, Email FROM User_profile WHERE user_id = %d", user_id);
			send(client, query, BUFFER_LEN, 0);
			recv(client, result, BUFFER_LEN, 0);
			char *Name = NULL;
			char *Last_Name = NULL;
			char *Phone = NULL;
			char *Email = NULL;
			char **tmp = mx_strsplit(result, '|');
			for (int i = 0; tmp[i]; i++)
			{
				char **tmp1 = mx_strsplit(tmp[i], '#');
				Name = tmp1[0];
				Last_Name = tmp1[1];
				Phone = tmp1[2];
				Email = tmp1[3];
			}
			
			{ // user's login
				users_loginProfileEdit = Create_new_button(mainChatLayout, Name, 1570, 155, 23, 40); 
				gtk_style_context_add_class (gtk_widget_get_style_context (GTK_WIDGET (users_loginProfileEdit)), "users_login");
				gtk_button_set_relief(GTK_BUTTON(users_loginProfileEdit), GTK_RELIEF_NONE);
				GtkStyleContext *context_users_loginProfileEdit = gtk_widget_get_style_context(users_loginProfileEdit);
				gtk_style_context_add_provider (context_users_loginProfileEdit, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
				gtk_widget_set_sensitive (users_loginProfileEdit, FALSE);
			}

			{ // user's telephone
				usersTelephoneEditProfile = Create_new_button(mainChatLayout, Phone, 1595, 246, 23, 40); 
				gtk_style_context_add_class (gtk_widget_get_style_context (GTK_WIDGET (usersTelephoneEditProfile)), "users_login");
				gtk_button_set_relief(GTK_BUTTON(usersTelephoneEditProfile), GTK_RELIEF_NONE);
				GtkStyleContext *context_usersTelephoneEditProfile = gtk_widget_get_style_context(usersTelephoneEditProfile);
				gtk_style_context_add_provider (context_usersTelephoneEditProfile, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
				gtk_widget_set_sensitive (usersTelephoneEditProfile, FALSE);
			}

			{ // user's name
				usersNameEditProfile = Create_new_button(mainChatLayout, Name, 1558, 285, 23, 40); 
				gtk_style_context_add_class (gtk_widget_get_style_context (GTK_WIDGET (usersNameEditProfile)), "users_login");
				gtk_button_set_relief(GTK_BUTTON(usersNameEditProfile), GTK_RELIEF_NONE);
				GtkStyleContext *context_usersNameEditProfile = gtk_widget_get_style_context(usersNameEditProfile);
				gtk_style_context_add_provider (context_usersNameEditProfile, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
				gtk_widget_set_sensitive (usersNameEditProfile, FALSE);
			}

			{ // user's second name
				usersSecondNameEditProfile = Create_new_button(mainChatLayout, Last_Name, 1623, 330, 23, 40); 
				gtk_style_context_add_class (gtk_widget_get_style_context (GTK_WIDGET (usersSecondNameEditProfile)), "users_login");
				gtk_button_set_relief(GTK_BUTTON(usersSecondNameEditProfile), GTK_RELIEF_NONE);
				GtkStyleContext *context_usersSecondNameEditProfile= gtk_widget_get_style_context(usersSecondNameEditProfile);
				gtk_style_context_add_provider (context_usersSecondNameEditProfile, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
				gtk_widget_set_sensitive (usersSecondNameEditProfile, FALSE);
			}

			{ // user's email 
				usersEmailEditProfile = Create_new_button(mainChatLayout, Email, 1558, 370, 23, 40); 
				gtk_style_context_add_class (gtk_widget_get_style_context (GTK_WIDGET (usersEmailEditProfile)), "users_login");
				gtk_button_set_relief(GTK_BUTTON(usersEmailEditProfile), GTK_RELIEF_NONE);
				GtkStyleContext *context_usersEmailEditProfile= gtk_widget_get_style_context(usersEmailEditProfile);
				gtk_style_context_add_provider (context_usersEmailEditProfile, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
				gtk_widget_set_sensitive (usersEmailEditProfile, FALSE);
			}
		}

		{// 3 tochki button field
			tritochkiButtonField = gtk_grid_new();
			gtk_container_add (GTK_CONTAINER (mainChatWindow), tritochkiButtonField);
			
			gtk_layout_put(GTK_LAYOUT(mainChatLayout), tritochkiButtonField, 1780, 65);
			gtk_widget_set_size_request(tritochkiButtonField, 50, 50);

			gtk_style_context_add_class ( gtk_widget_get_style_context ( GTK_WIDGET ( tritochkiButtonField ) ), "settingsButtonField");

			gtk_button_set_relief(GTK_BUTTON(tritochkiButtonField), GTK_RELIEF_NONE);
			GtkStyleContext *context_tritochkiButtonField= gtk_widget_get_style_context(tritochkiButtonField);
			gtk_style_context_add_provider(context_tritochkiButtonField, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

			{ // log out button
				GtkWidget *logoutBtn = NULL;
				logoutBtn = gtk_button_new_with_label ("");
				gtk_widget_set_size_request(logoutBtn, 50, 50);
				gtk_grid_attach (GTK_GRID(tritochkiButtonField), logoutBtn, 0, 1, 1, 1);
				gtk_style_context_add_class ( gtk_widget_get_style_context ( GTK_WIDGET ( logoutBtn ) ), "logoutBtn");

				gtk_button_set_relief(GTK_BUTTON(logoutBtn), GTK_RELIEF_NONE);
				GtkStyleContext *context_logoutBtn = gtk_widget_get_style_context(logoutBtn);
				gtk_style_context_add_provider(context_logoutBtn, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
				
				// when we click deanon button
				if(g_signal_connect(G_OBJECT(logoutBtn), "clicked", G_CALLBACK(main_window), (GtkWindow*)mainChatWindow))
				{
					logoutbtn_was_clicked = true;
				}
			}
		}

		{ // photo and login field
			photo_and_login_Field = gtk_grid_new();
			gtk_container_add (GTK_CONTAINER (mainChatWindow), photo_and_login_Field);
			
			gtk_layout_put(GTK_LAYOUT(mainChatLayout), photo_and_login_Field, 1500, 70);
			gtk_widget_set_size_request(photo_and_login_Field, 380, 100);

			gtk_style_context_add_class ( gtk_widget_get_style_context ( GTK_WIDGET ( photo_and_login_Field ) ), "photo_and_login_Field");

			gtk_button_set_relief(GTK_BUTTON(photo_and_login_Field), GTK_RELIEF_NONE);
			GtkStyleContext *context_photo_and_login_Field = gtk_widget_get_style_context(photo_and_login_Field);
			gtk_style_context_add_provider(context_photo_and_login_Field, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
			
			{ // user's photo
				users_photo = Create_new_button(mainChatLayout, "", 1510, 115, 50, 50); 
				gtk_style_context_add_class (gtk_widget_get_style_context (GTK_WIDGET (users_photo)), "users_photo");
				gtk_button_set_relief(GTK_BUTTON(users_photo), GTK_RELIEF_NONE);
				GtkStyleContext *context_users_photo = gtk_widget_get_style_context(users_photo);
				gtk_style_context_add_provider (context_users_photo, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
		
			}

			{ // user's login
				GtkWidget *users_login = NULL;
				char *result = mx_strnew(BUFFER_LEN);
				char *query = sqlite3_mprintf("SELECT login FROM User WHERE user_id = %d", user_id);
				send(client, query, BUFFER_LEN, 0);
				recv(client, result, BUFFER_LEN, 0);
				char *Login = NULL;
				char **tmp = mx_strsplit(result, '|');
				for (int i = 0; tmp[i]; i++) {
					char **tmp1 = mx_strsplit(tmp[i], '#');
					Login = tmp1[0];
				}

				users_login = gtk_button_new_with_label(Login);
				gtk_widget_set_size_request(users_login, 60, 60);
				gtk_grid_attach (GTK_GRID(photo_and_login_Field), users_login, 3, 0, 3, 3);
				gtk_style_context_add_class ( gtk_widget_get_style_context ( GTK_WIDGET ( users_login ) ), "users_login");
				gtk_widget_set_sensitive (users_login, FALSE);

				gtk_button_set_relief(GTK_BUTTON(users_login), GTK_RELIEF_NONE);
				GtkStyleContext *context_users_login= gtk_widget_get_style_context(users_login);
				gtk_style_context_add_provider(context_users_login, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
			}

			{ // user's id Text 
				GtkWidget *users_idTextSettings = NULL;

				users_idTextSettings = gtk_button_new_with_label("Your user id = ");
				gtk_widget_set_size_request(users_idTextSettings, 60, 60);
				gtk_grid_attach (GTK_GRID(photo_and_login_Field), users_idTextSettings, 7, 0, 3, 3);
				gtk_style_context_add_class ( gtk_widget_get_style_context ( GTK_WIDGET ( users_idTextSettings ) ), "users_login");
				gtk_widget_set_sensitive (users_idTextSettings, FALSE);

				gtk_button_set_relief(GTK_BUTTON(users_idTextSettings), GTK_RELIEF_NONE);
				GtkStyleContext *context_users_idTextSettings = gtk_widget_get_style_context(users_idTextSettings);
				gtk_style_context_add_provider(context_users_idTextSettings, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
			}

			{ // user's id
				GtkWidget *users_idSettings = NULL;

				users_idSettings = gtk_button_new_with_label(mx_itoa(user_id));
				gtk_widget_set_size_request(users_idSettings, 60, 60);
				gtk_grid_attach (GTK_GRID(photo_and_login_Field), users_idSettings, 10, 0, 3, 3);
				gtk_style_context_add_class ( gtk_widget_get_style_context ( GTK_WIDGET ( users_idSettings ) ), "users_login");
				gtk_widget_set_sensitive (users_idSettings, FALSE);

				gtk_button_set_relief(GTK_BUTTON(users_idSettings), GTK_RELIEF_NONE);
				GtkStyleContext *context_users_idSettings = gtk_widget_get_style_context(users_idSettings);
				gtk_style_context_add_provider(context_users_idSettings, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
			}
		}

		{ // donate field
			donateField = gtk_grid_new();
			gtk_container_add (GTK_CONTAINER (mainChatWindow), donateField);

			gtk_layout_put(GTK_LAYOUT(mainChatLayout), donateField, 1500, 70);
			gtk_widget_set_size_request(donateField, 380, 718);

			gtk_style_context_add_class ( gtk_widget_get_style_context ( GTK_WIDGET ( donateField ) ), "donateField");

			gtk_button_set_relief(GTK_BUTTON(donateField), GTK_RELIEF_NONE);
			GtkStyleContext *context_donateField= gtk_widget_get_style_context(donateField);
			gtk_style_context_add_provider(context_donateField, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

			// back btn
			backBtnDonate = Create_new_button(mainChatLayout, "", 1502, 71, 23, 40); 
			gtk_style_context_add_class (gtk_widget_get_style_context (GTK_WIDGET (backBtnDonate)), "backBtnDonate");
			gtk_button_set_relief(GTK_BUTTON(backBtnDonate), GTK_RELIEF_NONE);
			GtkStyleContext *context_backBtnDonate= gtk_widget_get_style_context(backBtnDonate);
			gtk_style_context_add_provider (context_backBtnDonate, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

			// when we click edit profile button
			g_signal_connect(G_OBJECT(backBtnDonate), "clicked", G_CALLBACK(settingsChat), donateField);
		}
		
		{ // faq field
			faqField = gtk_grid_new();
			gtk_container_add (GTK_CONTAINER (mainChatWindow), faqField);

			gtk_layout_put(GTK_LAYOUT(mainChatLayout), faqField, 1500, 70);
			gtk_widget_set_size_request(faqField, 380, 718);

			gtk_style_context_add_class ( gtk_widget_get_style_context ( GTK_WIDGET ( faqField ) ), "faqField");

			gtk_button_set_relief(GTK_BUTTON(faqField), GTK_RELIEF_NONE);
			GtkStyleContext *context_faqField= gtk_widget_get_style_context(faqField);
			gtk_style_context_add_provider(context_faqField, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

			// back btn
			backBtnFaq= Create_new_button(mainChatLayout, "", 1502, 71, 23, 40); 
			gtk_style_context_add_class (gtk_widget_get_style_context (GTK_WIDGET (backBtnFaq)), "backBtnDonate");
			gtk_button_set_relief(GTK_BUTTON(backBtnFaq), GTK_RELIEF_NONE);
			GtkStyleContext *context_backBtnFaq= gtk_widget_get_style_context(backBtnFaq);
			gtk_style_context_add_provider (context_backBtnFaq, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

			// when we click edit profile button
			g_signal_connect(G_OBJECT(backBtnFaq), "clicked", G_CALLBACK(settingsChat), faqField);
		}

		{ // deanon field
			deanonField = gtk_grid_new();
			gtk_container_add (GTK_CONTAINER (mainChatWindow), deanonField);

			gtk_layout_put(GTK_LAYOUT(mainChatLayout), deanonField, 1500, 70);
			gtk_widget_set_size_request(deanonField, 380, 718);

			gtk_style_context_add_class ( gtk_widget_get_style_context ( GTK_WIDGET ( deanonField ) ), "deanonField");

			gtk_button_set_relief(GTK_BUTTON(deanonField), GTK_RELIEF_NONE);
			GtkStyleContext *context_deanonField = gtk_widget_get_style_context(deanonField);
			gtk_style_context_add_provider(context_deanonField, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

			// back btn
			backBtnDeanon = Create_new_button(mainChatLayout, "", 1502, 71, 23, 40); 
			gtk_style_context_add_class (gtk_widget_get_style_context (GTK_WIDGET (backBtnDeanon)), "backBtnDonate");
			gtk_button_set_relief(GTK_BUTTON(backBtnDeanon), GTK_RELIEF_NONE);
			GtkStyleContext *context_backBtnDeanon= gtk_widget_get_style_context(backBtnDeanon);
			gtk_style_context_add_provider (context_backBtnDeanon, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

			// when we click edit profile button
			g_signal_connect(G_OBJECT(backBtnDeanon), "clicked", G_CALLBACK(settingsChat), deanonField);
			
			{ // telephone number 
				telephNumber = gtk_entry_new();
				gtk_widget_set_size_request(telephNumber, 344, 10);
				gtk_layout_put(GTK_LAYOUT(mainChatLayout), telephNumber, 1510, 179);
				gtk_style_context_add_class (gtk_widget_get_style_context (GTK_WIDGET (telephNumber)), "deanonGraph");
				gtk_button_set_relief(GTK_BUTTON(telephNumber), GTK_RELIEF_NONE);
				GtkStyleContext *context_telephNumber = gtk_widget_get_style_context(telephNumber);
				gtk_style_context_add_provider (context_telephNumber, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
			}

			{ // users's name deanon
				users_name_deanon = gtk_entry_new();
				gtk_widget_set_size_request(users_name_deanon, 344, 10);
				gtk_layout_put(GTK_LAYOUT(mainChatLayout), users_name_deanon, 1510, 255);
				gtk_style_context_add_class (gtk_widget_get_style_context (GTK_WIDGET (users_name_deanon)), "deanonGraph");
				gtk_button_set_relief(GTK_BUTTON(users_name_deanon), GTK_RELIEF_NONE);
				GtkStyleContext *context_users_name_deanon= gtk_widget_get_style_context(users_name_deanon);
				gtk_style_context_add_provider (context_users_name_deanon, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
			}
		
			{ // users's second name deanon
				users_second_name_deanon = gtk_entry_new();
				gtk_widget_set_size_request(users_second_name_deanon, 344, 10);
				gtk_layout_put(GTK_LAYOUT(mainChatLayout), users_second_name_deanon, 1510, 350);
				gtk_style_context_add_class (gtk_widget_get_style_context (GTK_WIDGET (users_second_name_deanon)), "deanonGraph");
				gtk_button_set_relief(GTK_BUTTON(users_second_name_deanon), GTK_RELIEF_NONE);
				GtkStyleContext *context_users_second_name_deanon = gtk_widget_get_style_context(users_second_name_deanon);
				gtk_style_context_add_provider (context_users_second_name_deanon, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
			}

			{ // users's email deanon
				users_email_deanon = gtk_entry_new();
				gtk_widget_set_size_request(users_email_deanon, 344, 10);
				gtk_layout_put(GTK_LAYOUT(mainChatLayout), users_email_deanon, 1510, 445);
				gtk_style_context_add_class (gtk_widget_get_style_context (GTK_WIDGET (users_email_deanon)), "deanonGraph");
				gtk_button_set_relief(GTK_BUTTON(users_email_deanon), GTK_RELIEF_NONE);
				GtkStyleContext *context_users_email_deanon = gtk_widget_get_style_context(users_email_deanon);
				gtk_style_context_add_provider (context_users_email_deanon, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
			}

			{ // deanon me button
				deanonMeButton = Create_new_button(mainChatLayout, "", 1600, 500, 122, 33); 
				gtk_style_context_add_class (gtk_widget_get_style_context (GTK_WIDGET (deanonMeButton)), "deanonMeButton");
				
				gtk_button_set_relief(GTK_BUTTON(deanonMeButton), GTK_RELIEF_NONE);

				gtk_button_set_relief(GTK_BUTTON(deanonMeButton), GTK_RELIEF_NONE);
				GtkStyleContext *context_deanonMeButton = gtk_widget_get_style_context(deanonMeButton);
				gtk_style_context_add_provider (context_deanonMeButton, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

				// when we click deanon me button
				g_signal_connect(G_OBJECT(deanonMeButton), "clicked", G_CALLBACK(deanonMeButtonClicked), (GtkWindow*)mainChatWindow);
			}

		}

		{ // peregodoka grid
			peregorodka_2 = gtk_grid_new(); 
			gtk_container_add (GTK_CONTAINER (mainChatWindow), peregorodka_2);

			gtk_layout_put(GTK_LAYOUT(mainChatLayout), peregorodka_2, 1500, 722);
			gtk_widget_set_size_request(peregorodka_2, 380, 10);

			gtk_style_context_add_class ( gtk_widget_get_style_context ( GTK_WIDGET ( peregorodka_2 ) ), "peregorodka");

			gtk_button_set_relief(GTK_BUTTON(peregorodka_2), GTK_RELIEF_NONE);
			GtkStyleContext *context_peregorodka_2 = gtk_widget_get_style_context(peregorodka_2);
			gtk_style_context_add_provider(context_peregorodka_2, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
		}

		{ // peregodoka button
			GtkWidget *peregorodka = NULL;
			peregorodka = gtk_entry_new ();
			gtk_widget_set_size_request(peregorodka, 200, 1);
			gtk_grid_attach (GTK_GRID(settingsButtonField), peregorodka, 0, peregorodkaPOS, 1, 1);
			gtk_style_context_add_class ( gtk_widget_get_style_context ( GTK_WIDGET ( peregorodka ) ), "peregorodka");
			gtk_widget_set_sensitive (peregorodka, FALSE);
			gtk_button_set_relief(GTK_BUTTON(peregorodka), GTK_RELIEF_NONE);
			GtkStyleContext *context_peregorodka= gtk_widget_get_style_context(peregorodka);
			gtk_style_context_add_provider(context_peregorodka, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
		}
		
		{ // edit profile button
			GtkWidget *editProfleBtn = NULL;
			editProfleBtn = gtk_button_new_with_label ("");
			gtk_widget_set_size_request(editProfleBtn, settingsW, settingsH);
			gtk_grid_attach (GTK_GRID(settingsButtonField), editProfleBtn, 0, edit_profilePOS, 1, 1);
			gtk_style_context_add_class ( gtk_widget_get_style_context ( GTK_WIDGET ( editProfleBtn ) ), "editProfleBtn");

			gtk_button_set_relief(GTK_BUTTON(editProfleBtn), GTK_RELIEF_NONE);
			GtkStyleContext *context_editProfleBtn = gtk_widget_get_style_context(editProfleBtn);
			gtk_style_context_add_provider(context_editProfleBtn, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

			// when we click edit profile button
			g_signal_connect(G_OBJECT(editProfleBtn), "clicked", G_CALLBACK(editProfileFieldChat), (GtkWindow*)mainChatWindow);
		}

		{ // notifications button
			GtkWidget *notificationsBtn = NULL;
			notificationsBtn = gtk_button_new_with_label ("");
			gtk_widget_set_size_request(notificationsBtn, settingsW, settingsH);
			gtk_grid_attach (GTK_GRID(settingsButtonField), notificationsBtn, 0, notificationsPOS, 1, 1);
			gtk_style_context_add_class ( gtk_widget_get_style_context ( GTK_WIDGET ( notificationsBtn ) ), "notificationsBtn");

			gtk_button_set_relief(GTK_BUTTON(notificationsBtn), GTK_RELIEF_NONE);
			GtkStyleContext *context_notificationsBtn = gtk_widget_get_style_context(notificationsBtn);
			gtk_style_context_add_provider(context_notificationsBtn, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
		}

		{ // deanon button
			GtkWidget *deanonBtn = NULL;
			deanonBtn = gtk_button_new_with_label ("");
			gtk_widget_set_size_request(deanonBtn, settingsW, settingsH);
			gtk_grid_attach (GTK_GRID(settingsButtonField), deanonBtn, 0, deanonPOS, 1, 1);
			gtk_style_context_add_class ( gtk_widget_get_style_context ( GTK_WIDGET ( deanonBtn ) ), "deanonBtn");

			gtk_button_set_relief(GTK_BUTTON(deanonBtn), GTK_RELIEF_NONE);
			GtkStyleContext *context_deanonBtn = gtk_widget_get_style_context(deanonBtn);
			gtk_style_context_add_provider(context_deanonBtn, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
			
			// when we click deanon button
			g_signal_connect(G_OBJECT(deanonBtn), "clicked", G_CALLBACK(deanonFieldChat), (GtkWindow*)mainChatWindow);
		}

		{ // language button
			GtkWidget *languageBtn = NULL;
			languageBtn = gtk_button_new_with_label ("");
			gtk_widget_set_size_request(languageBtn, settingsW, settingsH);
			gtk_grid_attach (GTK_GRID(settingsButtonField), languageBtn, 0, languagePOS, 1, 1);
			gtk_style_context_add_class ( gtk_widget_get_style_context ( GTK_WIDGET ( languageBtn ) ), "languageBtn");
			gtk_widget_set_sensitive (languageBtn, FALSE);
			gtk_button_set_relief(GTK_BUTTON(languageBtn), GTK_RELIEF_NONE);
			GtkStyleContext *context_languageBtn = gtk_widget_get_style_context(languageBtn);
			gtk_style_context_add_provider(context_languageBtn, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

		}

		{ // faq button
			GtkWidget *faqBtn = NULL;
			faqBtn = gtk_button_new_with_label ("");
			gtk_widget_set_size_request(faqBtn, settingsW, settingsH);
			gtk_grid_attach (GTK_GRID(settingsButtonField), faqBtn, 0, faqPOS, 1, 1);
			gtk_style_context_add_class ( gtk_widget_get_style_context ( GTK_WIDGET ( faqBtn ) ), "faqBtn");

			gtk_button_set_relief(GTK_BUTTON(faqBtn), GTK_RELIEF_NONE);
			GtkStyleContext *context_faqBtn = gtk_widget_get_style_context(faqBtn);
			gtk_style_context_add_provider(context_faqBtn, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

			// when we click notifications button
			g_signal_connect(G_OBJECT(faqBtn), "clicked", G_CALLBACK(faqFieldChatt), (GtkWindow*)mainChatWindow);
		}

		{ // donate button
			GtkWidget *donateBtn = NULL;
			donateBtn = gtk_button_new_with_label ("");
			gtk_widget_set_size_request(donateBtn, settingsW, settingsH);
			gtk_grid_attach (GTK_GRID(settingsButtonField), donateBtn, 0, donatePOS, 1, 1);
			gtk_style_context_add_class ( gtk_widget_get_style_context ( GTK_WIDGET ( donateBtn ) ), "donateBtn");

			gtk_button_set_relief(GTK_BUTTON(donateBtn), GTK_RELIEF_NONE);
			GtkStyleContext *context_donateBtn = gtk_widget_get_style_context(donateBtn);
			gtk_style_context_add_provider(context_donateBtn, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

			// when we click notifications button
			g_signal_connect(G_OBJECT(donateBtn), "clicked", G_CALLBACK(donateFieldChat), (GtkWindow*)mainChatWindow);
		}

		{ // advanced settings button
			GtkWidget *advancSettingsBtn = NULL;
			advancSettingsBtn = gtk_button_new_with_label ("");
			gtk_widget_set_size_request(advancSettingsBtn, settingsW, settingsH);
			gtk_grid_attach (GTK_GRID(settingsButtonField), advancSettingsBtn, 0, advanced_settingsPOS, 1, 1);
			gtk_style_context_add_class ( gtk_widget_get_style_context ( GTK_WIDGET ( advancSettingsBtn ) ), "advancSettingsBtn");
			gtk_button_set_relief(GTK_BUTTON(advancSettingsBtn), GTK_RELIEF_NONE);
			GtkStyleContext *context_advancSettingsBtn = gtk_widget_get_style_context(advancSettingsBtn);
			gtk_style_context_add_provider(context_advancSettingsBtn, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

		}

		{ // chat settings button
			GtkWidget *chatSettingBtn = NULL;
			chatSettingBtn = gtk_button_new_with_label ("");
			gtk_widget_set_size_request(chatSettingBtn, settingsW, settingsH);
			gtk_grid_attach (GTK_GRID(settingsButtonField), chatSettingBtn, 0, chat_settingsPOS, 1, 1);
			gtk_style_context_add_class ( gtk_widget_get_style_context ( GTK_WIDGET ( chatSettingBtn ) ), "chatSettingBtn");
			gtk_button_set_relief(GTK_BUTTON(chatSettingBtn), GTK_RELIEF_NONE);
			GtkStyleContext *context_chatSettingBtn= gtk_widget_get_style_context(chatSettingBtn);
			gtk_style_context_add_provider(context_chatSettingBtn, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
		}

		{ // folders button
			GtkWidget *foldersBtn = NULL;
			foldersBtn = gtk_button_new_with_label ("");
			gtk_widget_set_size_request(foldersBtn, settingsW, settingsH);
			gtk_grid_attach (GTK_GRID(settingsButtonField), foldersBtn, 0, foldersPOS, 1, 1);
			gtk_style_context_add_class ( gtk_widget_get_style_context ( GTK_WIDGET ( foldersBtn ) ), "foldersBtn");
			gtk_button_set_relief(GTK_BUTTON(foldersBtn), GTK_RELIEF_NONE);
			GtkStyleContext *context_foldersBtn = gtk_widget_get_style_context(foldersBtn);
			gtk_style_context_add_provider(context_foldersBtn, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
		}
	}

	{ // settings button
		settingsButton = Create_new_button(mainChatLayout, "", 1855, 8, 50, 50);
		gtk_style_context_add_class ( gtk_widget_get_style_context ( GTK_WIDGET ( settingsButton ) ), "settingsBtn");

		gtk_button_set_relief(GTK_BUTTON(settingsButton), GTK_RELIEF_NONE);
		GtkStyleContext *context_settingsButton = gtk_widget_get_style_context(settingsButton);
		gtk_style_context_add_provider(context_settingsButton, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

		// when we click back button
		g_signal_connect(G_OBJECT(settingsButton), "clicked", G_CALLBACK(settingsChat), (GtkWindow*)mainChatWindow);
	}

	{ // 3 tochki button
		tri_tochki_btn = Create_new_button(mainChatLayout, "", 1805, 6, 50, 50);
		gtk_style_context_add_class ( gtk_widget_get_style_context ( GTK_WIDGET ( tri_tochki_btn ) ), "tri_tochki_btn");

		gtk_button_set_relief(GTK_BUTTON(tri_tochki_btn), GTK_RELIEF_NONE);
		GtkStyleContext *context_tri_tochki_btn = gtk_widget_get_style_context(tri_tochki_btn);
		gtk_style_context_add_provider(context_tri_tochki_btn, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

		// when we click back button
		g_signal_connect(G_OBJECT(tri_tochki_btn), "clicked", G_CALLBACK(tri_tochki_buttonChat), (GtkWindow*)mainChatWindow);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
	}

	{ // trubka button
		GtkWidget *trubka_button = Create_new_button(mainChatLayout, "", 1750, 4, 50, 50);
		gtk_style_context_add_class ( gtk_widget_get_style_context ( GTK_WIDGET ( trubka_button ) ), "trubka_button");

		gtk_button_set_relief(GTK_BUTTON(trubka_button), GTK_RELIEF_NONE);
		GtkStyleContext *context_trubka_button = gtk_widget_get_style_context(trubka_button);
		gtk_style_context_add_provider(context_trubka_button, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

		// when we click back button
		if(g_signal_connect(G_OBJECT(trubka_button), "clicked", G_CALLBACK(main_window), (GtkWindow*)mainChatWindow)) {
			back_button_was_clicked_login = true;
		}
	}

	{ // abcd button
		GtkWidget *abcd_btn = Create_new_button(mainChatLayout, "", 1680, 4, 50, 50);
		gtk_style_context_add_class ( gtk_widget_get_style_context ( GTK_WIDGET ( abcd_btn ) ), "abcd_btn");

		gtk_button_set_relief(GTK_BUTTON(abcd_btn), GTK_RELIEF_NONE);
		GtkStyleContext *context_abcd_btn = gtk_widget_get_style_context(abcd_btn);
		gtk_style_context_add_provider(context_abcd_btn, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

		// when we click abcd button
		if(g_signal_connect(G_OBJECT(abcd_btn), "clicked", G_CALLBACK(main_window), (GtkWindow*)mainChatWindow))
		{
			//exit(1);
		}
	}

	{ // search input field + search button
	
		searchInputField = gtk_entry_new();
		gtk_entry_set_placeholder_text(GTK_ENTRY(searchInputField), "Enter here user id");
		gtk_layout_put(GTK_LAYOUT(mainChatLayout), searchInputField, 90, 10);
		gtk_widget_set_size_request(searchInputField, 370, 37);
		gtk_style_context_add_class(gtk_widget_get_style_context(GTK_WIDGET(searchInputField)), "searchBar");
		gtk_button_set_relief(GTK_BUTTON(searchInputField), GTK_RELIEF_NONE);
		GtkStyleContext *contextSearcgInputField;
		contextSearcgInputField = gtk_widget_get_style_context(searchInputField);
		gtk_style_context_add_provider (contextSearcgInputField, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

		abcd_btn1 = Create_new_button(mainChatLayout, "", 10, 4, 50, 50);
		gtk_style_context_add_class ( gtk_widget_get_style_context ( GTK_WIDGET ( abcd_btn1 ) ), "abcd_btn");
		gtk_button_set_relief(GTK_BUTTON(abcd_btn1), GTK_RELIEF_NONE);
		GtkStyleContext *context_abcd_btn1 = gtk_widget_get_style_context(abcd_btn1);
		gtk_style_context_add_provider(context_abcd_btn1, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

		g_signal_connect(G_OBJECT(abcd_btn1), "clicked", G_CALLBACK(search_person), (GtkWindow*)mainChatWindow);
	}

	{ // write a message
		writeInputField = gtk_entry_new();
		gtk_entry_set_placeholder_text(GTK_ENTRY(writeInputField), "Write a message ✎");
		gtk_entry_set_visibility(GTK_ENTRY(writeInputField),TRUE);
		gtk_layout_put(GTK_LAYOUT(mainChatLayout), writeInputField, 490, 1020);
		gtk_widget_set_size_request(writeInputField, 1248, 45);
		
		gtk_style_context_add_class(gtk_widget_get_style_context(GTK_WIDGET(writeInputField)), "messageBar");
		gtk_button_set_relief(GTK_BUTTON(writeInputField), GTK_RELIEF_NONE);
		GtkStyleContext *contextWriteInputField;
		contextWriteInputField = gtk_widget_get_style_context(writeInputField);
		gtk_style_context_add_provider (contextWriteInputField, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
	}

	{ // emojii and send field
		emOtpravkaInputField = gtk_entry_new();
		gtk_entry_set_placeholder_text(GTK_ENTRY(emOtpravkaInputField), " ");
		gtk_entry_set_visibility(GTK_ENTRY(emOtpravkaInputField),TRUE);
		gtk_layout_put(GTK_LAYOUT(mainChatLayout), emOtpravkaInputField, 1743, 1018);
		gtk_widget_set_size_request(emOtpravkaInputField, 12, 47);

		
		gtk_style_context_add_class(gtk_widget_get_style_context(GTK_WIDGET(emOtpravkaInputField)), "emOtpravkaBar");
		gtk_button_set_relief(GTK_BUTTON(emOtpravkaInputField), GTK_RELIEF_NONE);
		GtkStyleContext *contextemOtpravkaInputField;
		contextemOtpravkaInputField = gtk_widget_get_style_context(emOtpravkaInputField);
		gtk_style_context_add_provider (contextemOtpravkaInputField, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
		gtk_widget_set_sensitive (emOtpravkaInputField, FALSE);
	}

	{ // emojii button
		emojiiBtn = Create_new_button(mainChatLayout, "", 1750, 1017, 48, 48);
		gtk_style_context_add_class (gtk_widget_get_style_context (GTK_WIDGET (emojiiBtn)), "emojiiBtn");
		gtk_button_set_relief(GTK_BUTTON(emojiiBtn), GTK_RELIEF_NONE);
		GtkStyleContext *context_emojiiBtn = gtk_widget_get_style_context(emojiiBtn);
		gtk_style_context_add_provider (context_emojiiBtn, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
	}

	{ // otpravvka button
		otpravkaBtn = Create_new_button(mainChatLayout, "", 1850, 1018, 50, 50); 
		gtk_style_context_add_class (gtk_widget_get_style_context (GTK_WIDGET (otpravkaBtn)), "otpravkaBtn");
		gtk_button_set_relief(GTK_BUTTON(otpravkaBtn), GTK_RELIEF_NONE);
		GtkStyleContext *context_otpravkaBtn = gtk_widget_get_style_context(otpravkaBtn);
		gtk_style_context_add_provider (context_otpravkaBtn, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

		// when we click notifications button
		g_signal_connect(G_OBJECT(otpravkaBtn), "clicked", G_CALLBACK(sendMessageFunctionChat), (GtkWindow*)mainChatWindow);
	}

	{ // searched people field
		searchedPeopleField = gtk_grid_new();
		gtk_container_add (GTK_CONTAINER (mainChatWindow), searchedPeopleField);

		gtk_layout_put(GTK_LAYOUT(mainChatLayout), searchedPeopleField, 0, 63);
		gtk_widget_set_size_request(searchedPeopleField, 480, 90);

		gtk_style_context_add_class ( gtk_widget_get_style_context ( GTK_WIDGET ( searchedPeopleField ) ), "searchedPeopleField");

		gtk_button_set_relief(GTK_BUTTON(searchedPeopleField), GTK_RELIEF_NONE);
		GtkStyleContext *context_searchedPeopleField = gtk_widget_get_style_context(searchedPeopleField);
		gtk_style_context_add_provider(context_searchedPeopleField, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
	}

	g_signal_connect_swapped(G_OBJECT(mainChatWindow), "destroy", G_CALLBACK(gtk_main_quit), NULL);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
    
	gtk_widget_show_all(mainChatWindow);

	gtk_widget_hide(settingsButtonField);
	gtk_widget_hide(tritochkiButtonField);
	gtk_widget_hide(photo_and_login_Field);
	gtk_widget_hide(peregorodka);
	gtk_widget_hide(peregorodka_2);
	gtk_widget_hide(donateField);
	gtk_widget_hide(faqField);
	gtk_widget_hide(deanonField);
	gtk_widget_hide(edit_profileField);
	gtk_widget_hide(Change_pass_old_pass);
	gtk_widget_hide(Change_pass_new_pass);
	gtk_widget_hide(Change_pass_confirm_pass);
	gtk_widget_hide(changePasswordButton);
	gtk_widget_hide(err_msg_old_pass_not_match);
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
	gtk_widget_hide(searchedPeopleField);
	gtk_widget_hide(searchePeopleUsernameButton);
	gtk_widget_hide(messageFieldChat);
	gtk_widget_hide(searchedPeopleField);
	gtk_widget_hide(emOtpravkaInputField);
	gtk_widget_hide(emojiiBtn);
	gtk_widget_hide(otpravkaBtn);
	gtk_widget_hide(writeInputField);
    gtk_main();    
}

