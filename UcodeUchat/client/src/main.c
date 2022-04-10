#include "../inc/client.h"

int main_window(int argc, char *argv[], GtkWindow *zjfsdjf);

bool mx_isnumber(char *s)
{
    int i = -1;
    while (s[++i])
	{
        if (!isdigit(s[i]))
		{
            return false;
        }
    }
    return true;
}

char * mx_strjoin1(const char *glue, ...)
{
	va_list ap;
	unsigned total, count, len, glue_len;
	const char *str;
	char *res;
	va_start(ap, glue);
	total = count = 0;
	while ((str = va_arg(ap, const char *)))
	{
		total += strlen(str);
		count ++;
	}
	va_end(ap);

	glue_len = glue ? strlen(glue) : 0;
	total += (count - 1) * glue_len;
	res = (char*)malloc(total + 1);
	if (!res)
	{
		return NULL;
	}
	va_start(ap, glue);
	total = 0;
	while ((str = va_arg(ap, const char *)))
	{
		if (total && glue_len)
		{
			memcpy(res + total, glue, glue_len);
			total += glue_len;
		}
		strcpy(res + total, str);
		total += strlen(str);
	}
	va_end(ap);
	return res;
}

int LENGTH_client = 1024;

// Global variables
volatile sig_atomic_t flag = 0;
int sockfd = 0;
char name[32];

void str_overwrite_stdout(char *message)
{
	printf("%s", "> ");  
  	fflush(stdout);
}

void str_trim_lf (char* arr, int length)
{
  	for (int i = 0; i < length; i++)
	{ // trim \n
		if (arr[i] == '\n')
		{
			arr[i] = '\0';
			break;
		}
	}
}

void catch_ctrl_c_and_exit(int sig)
{
    flag = 1;
}

void send_msg_handler()
{
  	char message[LENGTH_client];
	char buffer[LENGTH_client + 32];

  	while(1)
	{
	  	fgets(message, LENGTH_client, stdin);
		str_overwrite_stdout(message);
		str_trim_lf(message, LENGTH_client);

		if (strcmp(message, "exit") == 0)
		{
			break;
		}
		else
		{
			sprintf(buffer, "%s: %s\n", name, message);
			send(sockfd, buffer, strlen(buffer), 0);
		}
		bzero(message, LENGTH_client);
		bzero(buffer, LENGTH_client + 32);
	}
	catch_ctrl_c_and_exit(2);
}

void recv_msg_handler()
{
	char message[LENGTH_client];
	while (1)
	{
		int receive = recv(sockfd, message, LENGTH_client, 0);
		if (receive > 0)
		{
			printf("%s", message);
			str_overwrite_stdout(message);
		} 
		else if (receive == 0)
		{
			break;
		} 
		memset(message, 0, sizeof(message));
	}
}

void signUpBtn_clicked(GtkWidget *button, GtkWidget *loginData)
{
	signUp_button_was_clicked = true;

	if(strlen(gtk_entry_get_text(GTK_ENTRY(loginData))) == 0 || strlen(gtk_entry_get_text(GTK_ENTRY(loginData))) >= 20)
	{
		printf("\n\nLOGIN SMALL\n\n");

		err_msg_no_login = GTK_WIDGET(Create_new_button(layout_register, "Login too small or too big",680,400,100,20));

		gtk_style_context_add_class ( gtk_widget_get_style_context ( GTK_WIDGET ( err_msg_no_login ) ), "err_msg_login_exists" );
		gtk_widget_set_sensitive (err_msg_no_login, FALSE);
		gtk_button_set_relief(GTK_BUTTON(err_msg_no_login), GTK_RELIEF_NONE);

		GtkStyleContext *context_err_msg_login_exists = gtk_widget_get_style_context(err_msg_no_login);
		gtk_style_context_add_provider (context_err_msg_login_exists, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																	
		gtk_widget_show_all(window_register);
	}
	else if(check_login_available(gtk_entry_get_text(GTK_ENTRY(loginData))) == false)
	{
		gtk_widget_destroy(GTK_WIDGET(err_msg_no_login));
		printf("LOGIN EXIST\n");

		err_msg_login_exists = GTK_WIDGET(Create_new_button(layout_register, "This login exists, try another one!",680,400,100,20));

		gtk_style_context_add_class ( gtk_widget_get_style_context ( GTK_WIDGET ( err_msg_login_exists ) ), "err_msg_login_exists" );
		gtk_widget_set_sensitive (err_msg_login_exists, FALSE);
		gtk_button_set_relief(GTK_BUTTON(err_msg_login_exists), GTK_RELIEF_NONE);

		GtkStyleContext *context_err_msg_login_exists;
		context_err_msg_login_exists = gtk_widget_get_style_context(err_msg_login_exists);
		gtk_style_context_add_provider (context_err_msg_login_exists, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																	
		gtk_widget_show_all(window_register);
	}
	else if (strlen(gtk_entry_get_text(GTK_ENTRY(passwordEntryRegister))) < 8 || check_strong_password(gtk_entry_get_text(GTK_ENTRY(passwordEntryRegister))) == false)
	{
		gtk_widget_destroy(GTK_WIDGET(err_msg_no_login));
		gtk_widget_destroy(GTK_WIDGET(err_msg_login_exists));
		printf("Password must contain at least 8 characters, 1 uppercase and lowercase letter and has at least 1 digit!\n");

		err_msg_password_not_strong = GTK_WIDGET(Create_new_button(layout_register, "Password must contain at least 8 characters, 1 uppercase and lowercase letter and has at least 1 digit!",
			665,540,100,20));

		gtk_style_context_add_class ( gtk_widget_get_style_context ( GTK_WIDGET ( err_msg_password_not_strong ) ), "err_msg_login_exists" );
		gtk_widget_set_sensitive (err_msg_password_not_strong, FALSE);
		gtk_button_set_relief(GTK_BUTTON(err_msg_password_not_strong), GTK_RELIEF_NONE);

		GtkStyleContext *context_err_msg_pass_match;
		context_err_msg_pass_match = gtk_widget_get_style_context(err_msg_password_not_strong);
		gtk_style_context_add_provider (context_err_msg_pass_match, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																	
		gtk_widget_show_all(window_register);
	}
	else if(strcmp(gtk_entry_get_text(GTK_ENTRY(passwordEntryRegister)), gtk_entry_get_text(GTK_ENTRY(ConfirmPasswordEntryRegister))) != 0)
	{
		gtk_widget_destroy(GTK_WIDGET(err_msg_no_login));
		gtk_widget_destroy(GTK_WIDGET(err_msg_login_exists));
		gtk_widget_destroy(GTK_WIDGET(err_msg_password_not_strong));
		printf("passwords don't match\n");

		err_msg_password_dont_match = GTK_WIDGET(Create_new_button(layout_register, "Passwords don't match!",680,670,100,20));

		gtk_style_context_add_class ( gtk_widget_get_style_context ( GTK_WIDGET ( err_msg_password_dont_match ) ), "err_msg_login_exists" );
		gtk_widget_set_sensitive (err_msg_password_dont_match, FALSE);
		gtk_button_set_relief(GTK_BUTTON(err_msg_password_dont_match), GTK_RELIEF_NONE);

		GtkStyleContext *context_err_msg_pass_match;
		context_err_msg_pass_match = gtk_widget_get_style_context(err_msg_password_dont_match);
		gtk_style_context_add_provider (context_err_msg_pass_match, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																	
		gtk_widget_show_all(window_register);
	}
	else
	{
		gtk_widget_destroy(GTK_WIDGET(err_msg_no_login));
		gtk_widget_destroy(GTK_WIDGET(err_msg_login_exists));
		gtk_widget_destroy(GTK_WIDGET(err_msg_password_not_strong));
		gtk_widget_destroy(GTK_WIDGET(err_msg_password_dont_match));

		char *result = mx_strnew(BUFFER_LEN);
		send(client, "SELECT Login FROM User", BUFFER_LEN, 0);
		recv(client, result, BUFFER_LEN, 0);
		int id = 0;
		char **tmp1 = mx_strsplit(result, '|');
		for(int i = 0; tmp1[i]; i++) 
		{
			id++;
		}
		srand(time(NULL));
		int secret = rand() % 10000 + 1000;
		while(check_usid(secret) == false)
		{
			secret = rand() % 10000 + 1000;
		}
		user_id = secret;
		char *result1 = mx_strnew(BUFFER_LEN);
		char *query = sqlite3_mprintf("INSERT INTO User VALUES (%d, '%q', '%q', %d);", id, gtk_entry_get_text(GTK_ENTRY(loginData)), hash((unsigned char*)gtk_entry_get_text(GTK_ENTRY(passwordEntryRegister))), user_id);
		send(client, query, BUFFER_LEN, 0);
		recv(client, query, BUFFER_LEN, 0);
        send(client, "SELECT id FROM User_profile", BUFFER_LEN, 0);
        recv(client, result1, BUFFER_LEN, 0);
        id = 0;
        char **tmp2 = mx_strsplit(result1, '|');
        for(int i = 0; tmp2[i]; i++) 
        {
            id = mx_atoi(tmp2[i]);
        }
		char *query1 = sqlite3_mprintf("INSERT INTO User_profile VALUES (%d, 'Anonymous', 'None', 'None', 'None', %d);", id+1, user_id);
		send(client, query1, BUFFER_LEN, 0);

		signUp_button_was_clicked = true;
		char *argv[] = {"./uchat","0.0.0.0:80"};
		main_window(2,argv,(GtkWindow*)messageGrid);
	}
}

void signInBtn_clicked(GtkWidget *button, GtkWidget *loginData)
{
	GtkWindow* win123 = NULL;
	GtkWidget *widget123 = NULL;
	gpointer data123 = NULL; 
	 
	signIn_button_was_clicked = true;
	if(check_log_pass(gtk_entry_get_text(GTK_ENTRY(loginData)), gtk_entry_get_text(GTK_ENTRY(passwordEntryLogin))) == false)
	{		
		err_msg_when_user_login = GTK_WIDGET(Create_new_button(layout_login, "This login doesn't exist or password doesn't match", 680, 400, 100, 20));
		gtk_style_context_add_class ( gtk_widget_get_style_context ( GTK_WIDGET ( err_msg_when_user_login ) ), "err_msg_login_exists" );
		gtk_widget_set_sensitive (err_msg_when_user_login, FALSE);
		gtk_button_set_relief(GTK_BUTTON(err_msg_when_user_login), GTK_RELIEF_NONE);
		GtkStyleContext *context_err_msg_when_user_login = gtk_widget_get_style_context(err_msg_when_user_login);
		gtk_style_context_add_provider (context_err_msg_when_user_login, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																	
		gtk_widget_show_all(window_login);
	}
	else
	{
		gtk_widget_destroy(GTK_WIDGET(err_msg_when_user_login));
		char *query = sqlite3_mprintf("SELECT user_id FROM User WHERE Login = '%q'", gtk_entry_get_text(GTK_ENTRY(loginData)));
		char *result = mx_strnew(BUFFER_LEN);
		send(client, query, BUFFER_LEN, 0);
		recv(client, result, BUFFER_LEN, 0);
		printf("%s",result);

		user_id = mx_atoi(result);

		signIn_button_was_clicked = true;
	
		chat_main(widget123, data123, win123);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
	}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
}

// Windows
int main_window(int argc, char *argv[], GtkWindow *zjfsdjf)
{	
	if(logoutbtn_was_clicked == true)
	{
		gtk_window_close((GtkWindow*)mainChatWindow);		
	}
	if(back_button_was_clicked_login == true)
	{
		gtk_window_close((GtkWindow*)window_login);
	}
	if(back_button_was_clicked_register == true)
	{
		gtk_window_close((GtkWindow*)window_register);
	}

	// Button_Setings
	GtkSettings *default_settings = gtk_settings_get_default();
	g_object_set(default_settings, "gtk-button-images", TRUE, NULL);

	GtkWidget *widget;
	gpointer data;

	// Inizilisation
    gtk_init(&argc, &argv);

	// MAIN window
    mainWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(mainWindow), WIDTH, HEIGHT);
    gtk_window_set_position(GTK_WINDOW(mainWindow), GTK_WIN_POS_CENTER);

	gtk_window_set_title(GTK_WINDOW(mainWindow), "AnonymousChat");

	// Layout create
    GtkWidget *layout = gtk_layout_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER (mainWindow), layout);
    gtk_widget_show(layout);

	// Background
    GtkWidget *background = gtk_image_new_from_file("../resources/background/background.png");
    gtk_layout_put(GTK_LAYOUT(layout), background, 0, 0); 
	g_signal_connect (mainWindow, "activate", G_CALLBACK(activate), NULL);

	// CSS provider
	provider = gtk_css_provider_new();
	gtk_css_provider_load_from_path (provider, "../client/src/style.css", NULL);

	// Login Button
	GtkWidget *btn_login = GTK_WIDGET(Create_new_button(layout, "", 824, 373, 270, 270));
	gtk_style_context_add_class ( gtk_widget_get_style_context ( GTK_WIDGET ( btn_login ) ), "button_to_login" );
	gtk_button_set_relief(GTK_BUTTON(btn_login), GTK_RELIEF_NONE);
	GtkStyleContext *context = gtk_widget_get_style_context(btn_login);
	gtk_style_context_add_provider (context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

	g_signal_connect(btn_login, "clicked", G_CALLBACK(button_login_clicked),(gpointer)10);

	// Registration Button
	GtkWidget *btn_register = GTK_WIDGET(Create_new_button(layout, "", 931, 835, 70, 70));
	gtk_style_context_add_class ( gtk_widget_get_style_context ( GTK_WIDGET ( btn_register ) ), "btn_to_register" );
	gtk_button_set_relief(GTK_BUTTON(btn_register), GTK_RELIEF_NONE);
	GtkStyleContext *context_register = gtk_widget_get_style_context(btn_register);
	gtk_style_context_add_provider (context_register, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

	g_signal_connect(btn_register, "clicked", G_CALLBACK(button_register_clicked),(gpointer)10);

    g_signal_connect_swapped(G_OBJECT(mainWindow), "destroy", G_CALLBACK(gtk_main_quit), NULL);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
    gtk_widget_show_all(mainWindow);

    gtk_main();

	return 0;
}

int main(int argc, char *argv[]) 
{
	char buffer[BUFFER_LEN];
	if(argc != 2 && argc != 3)
	{
		fprintf(stderr, "uchat: usage [ip] [port] OR [ip:port]\n");
		exit(0);
	}

	if(argc == 2)
	{
		int dbl_dot = 0;
		int sngl_dot = 0;
		int size = mx_strlen(argv[1]);
		int num = 0;
		for(int i = 0; argv[1][i]; i++)
		{
			if(argv[1][i] == ':')
			{
				dbl_dot++;
			}
			else if(argv[1][i] == '.')
			{
				sngl_dot++;
				if(num < 1 || num > 3 || argv[1][i+1] == ':')
				{
					fprintf(stderr, "uchat error: invalid ip format\n");
					exit(0);
				}
				num = 0;
			}
			else if(isdigit(argv[1][i]) == false)
			{
				fprintf(stderr, "uchat error: invalid ip format\n");
				exit(0);
			}
			else
			{
				num++;
			}
		}
		if(dbl_dot != 1 || sngl_dot != 3 || argv[1][0] == '.' || argv[1][size - 1] == ':') 
		{
			fprintf(stderr, "uchat error: invalid ip format\n");
			exit(0);
		}
		char** tmp = mx_strsplit(argv[1], ':');
		int prt = mx_atoi(tmp[1]);
		if(prt < 1 || prt > 65535)
		{
			fprintf(stderr, "uchat error: invalid port format\n");
			exit(0);
		}
		char** tmp1 = mx_strsplit(tmp[0], '.');
		for(int i = 0; tmp1[i]; i++)
		{
			
			if(mx_strlen(tmp1[i]) > 1 && tmp1[i][0] == '0')
			{
				fprintf(stderr, "uchat error: invalid ip format\n");
				exit(0);
			}
			int nip = mx_atoi(tmp1[i]);
			if(nip < 0 || nip > 255)
			{
				fprintf(stderr, "uchat error: invalid ip format\n");
				exit(0);	
			}
		}
		if(mx_strlen(tmp[1]) > 1 && tmp[1][0] == '0')
		{
			fprintf(stderr, "uchat error: invalid port format\n");
			exit(0);
		}
		ip = tmp[0];
		port = tmp[1];
	}
	else if (argc == 3)
	{
		int sngl_dot = 0;
		int num = 0;
		int size_ip = mx_strlen(argv[1]);
		int size_port = mx_strlen(argv[2]);
		for(int i = 0; argv[1][i]; i++)
		{
			if(argv[1][i] == '.')
			{
				sngl_dot++;
				if(num < 1 || num > 3)
				{
					fprintf(stderr, "uchat error: invalid ip format\n");
					exit(0);
				}
				num = 0;
			}
			else if(isdigit(argv[1][i]) == false)
			{
				fprintf(stderr, "uchat error: invalid ip format\n");
				exit(0);
			}
			else
			{
				num++;
			}
		}
		if(sngl_dot != 3 || argv[1][0] == '.' || argv[1][size_ip - 1] == '.') 
		{
			fprintf(stderr, "uchat error: invalid ip format\n");
			exit(0);
		}
		for(int i = 0; argv[2][i]; i++)
		{
			if(isdigit(argv[2][i]) == false)
			{
				fprintf(stderr, "uchat error: invalid port format\n");
				exit(0);
			}
		}
		if(size_port > 1 && argv[2][0] == '0')
		{
			fprintf(stderr, "uchat error: invalid port format\n");
			exit(0);
		}
		int prt = mx_atoi(argv[2]);
		if(prt < 1 || prt > 65535)
		{
			fprintf(stderr, "uchat error: invalid port format\n");
			exit(0);
		}
		char** tmp1 = mx_strsplit(argv[1], '.');
		for(int i = 0; tmp1[i]; i++)
		{	
			if(mx_strlen(tmp1[i]) > 1 && tmp1[i][0] == '0')
			{
				fprintf(stderr, "uchat error: invalid ip format\n");
				exit(0);
			}
			int nip = mx_atoi(tmp1[i]);
			if(nip < 0 || nip > 255)
			{
				fprintf(stderr, "uchat error: invalid ip format\n");
				exit(0);	
			}
		}
		ip = argv[1];
		port = argv[2];
	}
	printf("ip: %s\nport: %s\n", ip, port);
	struct sockaddr_in server_adress;
	client = socket(AF_INET, SOCK_STREAM, 0);

	server_adress.sin_family = AF_INET;
	
	server_adress.sin_port = htons(mx_atoi(port));
	
	server_adress.sin_addr.s_addr = inet_addr(ip);

	int ret = connect(client, (struct sockaddr *)&server_adress, sizeof(server_adress));

	if(ret == 0)
	{
		printf("Connection to server...\n");
	}
	else if(ret == -1)
	{
		printf("ERROR: connect\n");
		return EXIT_FAILURE;
	}
	printf("Waiting to server confirmation...\n");
	recv(client, buffer, BUFFER_LEN, 0);
	printf("Connection established\n");
	GtkWindow *window_register = NULL;
	main_window(argc, argv, window_register);
	close(client);
	return 0;
}

