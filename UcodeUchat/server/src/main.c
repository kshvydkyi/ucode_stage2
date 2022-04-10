#include "server.h"

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		fprintf(stderr, "uchat_server: usage [port]\n");
		exit(0);
	}
	int size_port = mx_strlen(argv[1]);
	for(int i = 0; argv[1][i]; i++)
	{
		if(isdigit(argv[1][i]) == false)
		{
			fprintf(stderr, "uchat_server error: invalid port format\n");
			exit(0);
		}
	}
	if(size_port > 1 && argv[1][0] == '0')
	{
		fprintf(stderr, "uchat_server error: invalid port format\n");
		exit(0);
	}
	int prt = mx_atoi(argv[1]);
	if(prt < 1 || prt > 65535)
	{
		fprintf(stderr, "uchat_server error: invalid port format\n");
		exit(0);
	}
	port = argv[1];

	char *err_msg = NULL; 
	sqlite3* db;
	int response = sqlite3_open("database.db", &db); 
	if(response != SQLITE_OK)
	{  // esli problema
		printf("error: %s", err_msg);
	}
	response = sqlite3_exec(db, " CREATE TABLE User ( id integer PRIMARY KEY AUTOINCREMENT, login varchar(100), password varchar(8000), user_id varchar(100) );",NULL, NULL, &err_msg); 
	response = sqlite3_exec(db, " CREATE TABLE User_profile (id integer PRIMARY KEY AUTOINCREMENT, Name varchar(100), Last_name varchar(100), Phone varchar(100), Email varchar(255), user_id varchar(100) );",NULL, NULL, &err_msg); 
	response = sqlite3_exec(db, " CREATE TABLE Online ( id integer PRIMARY KEY AUTOINCREMENT, user_id varchar(100) );",NULL, NULL, &err_msg); 
	response = sqlite3_exec(db, " CREATE TABLE Chat_message ( id integer PRIMARY KEY AUTOINCREMENT, chat_id varchar, text_message varchar, user_id varchar);",NULL, NULL, &err_msg); 
	response = sqlite3_exec(db, " CREATE TABLE Chat ( id integer PRIMARY KEY AUTOINCREMENT, chat_id varchar, user_id_1 varchar(100), user_id_2 varchar(100) );",NULL, NULL, &err_msg); 
	response = sqlite3_exec(db, " CREATE TABLE Groups ( id integer PRIMARY KEY AUTOINCREMENT, Group_Name varchar(100), Description varchar(1000), group_id varchar(200), admin_id varchar(100) );",NULL, NULL, &err_msg); 
	response = sqlite3_exec(db, " CREATE TABLE Group_list (id integer PRIMARY KEY AUTOINCREMENT, group_id varchar(200), user_id varchar(100) );	",NULL, NULL, &err_msg);
	response = sqlite3_exec(db, " INSERT INTO User VALUES (0, '1', '1', '1111')", NULL, NULL, &err_msg);
	response = sqlite3_exec(db, " INSERT INTO User_profile VALUES (0, 'None', 'None', 'None', 'None', '1111')", NULL, NULL, &err_msg);
	sqlite3_close(db);
	int listenfd = 0;
	int connfd = 0;



	int option = 0;
	socklen_t adrlen; 

    struct sockaddr_in serv_addr;

    time_t ticks;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);

	if(listenfd < 0)
	{
		perror("SERVER ERROR: Establishing socket error\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("SERVER: Socket was created\n");
	}

	serv_addr.sin_family = AF_INET;

    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);


    serv_addr.sin_port = htons(mx_atoi(port));

	signal(SIGPIPE, SIG_IGN);

	if(setsockopt(listenfd, SOL_SOCKET,(SO_REUSEPORT | SO_REUSEADDR),(char*)&option, sizeof(option)) < -1)
	{
		perror("ERROR: setsockopt failed");
   		return EXIT_FAILURE;
	}

    bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

	printf("SERVER: Listening clients...\n");

    listen(listenfd, BACKLOG);
	printf("Connected to the client...\n");
    while(1)
	{
		adrlen = sizeof(serv_addr);
        connfd = accept(listenfd, (struct sockaddr*)&serv_addr, &adrlen);  
		
		while(connfd > 0)
		{
			char buffer[BUFFER_LEN];
			strcpy(buffer, "Server connected!\n");
			send(connfd, buffer, BUFFER_LEN, 0);
			printf("Client connected!\n");
			printf("User connect!\n\n");
			break;
		} 

		if (connfd == -1)
		{
			perror("accept");
			continue;
		}
        sleep(1);

		if (fork())
		{ 
			continue;
		}
		else
		{
			char buffer1[BUFFER_LEN];
			char tmp[BUFFER_LEN] = "";
			while(true)
			{
				recv(connfd, buffer1, BUFFER_LEN, 0);
				if(mx_strlen(buffer1) != 0)
				{
					sqlite3_stmt *stmt = NULL;
					char *result = NULL;
					sqlite3* db1;
					int resp = sqlite3_open("database.db", &db1); 
					if(resp != SQLITE_OK)
					{  // esli problema
						//printf("error:");
					}
					printf("\n==============\n");
					printf("%s\n", buffer1);
					printf("\n==============\n");
					if(mx_strstr(buffer1, "INSERT INTO User VALUES (") != NULL)
					{	
						sqlite3_exec(db1, buffer1, NULL, NULL, &err_msg);	
						send(connfd, tmp, BUFFER_LEN, 0);
					}
					else if(mx_strstr(buffer1, "INSERT INTO User_profile VALUES (") != NULL)
					{	
						sqlite3_exec(db1, buffer1, NULL, NULL, &err_msg);
						send(connfd, tmp, BUFFER_LEN, 0);
					}
					else if(mx_strstr(buffer1, "INSERT INTO Chat VALUES (") != NULL)
					{	
						sqlite3_exec(db1, buffer1, NULL, NULL, &err_msg);
						send(connfd, tmp, BUFFER_LEN, 0);
					}
					else if(mx_strstr(buffer1, "INSERT INTO Chat_message VALUES") != NULL)
					{	
						sqlite3_exec(db1, buffer1, NULL, NULL, &err_msg);
						send(connfd, tmp, BUFFER_LEN, 0);
					}
					else if(mx_strstr(buffer1, "UPDATE User_profile SET") != NULL)
					{	
						sqlite3_exec(db1, buffer1, NULL, NULL, &err_msg);
						
						send(connfd, "", BUFFER_LEN, 0);
						
					}
					else if(mx_strstr(buffer1, "SELECT user_id FROM User WHERE Login = ") != NULL)
					{
						sqlite3_prepare_v2(db1, buffer1, -1, &stmt, NULL);
						while(sqlite3_step(stmt) != SQLITE_DONE)
						{
							const unsigned char *selected_login = sqlite3_column_text(stmt, 0);
							result = mx_strjoin(result, (char*)selected_login);
						}
						send(connfd, result, BUFFER_LEN, 0);
						
					}
					else if(mx_strcmp(buffer1, "SELECT Login, Password FROM User") == 0)
					{
						sqlite3_prepare_v2(db1, buffer1, -1, &stmt, NULL);
						while(sqlite3_step(stmt) != SQLITE_DONE)
						{
							const unsigned char *selected_login = sqlite3_column_text(stmt, 0);
							const unsigned char *selected_password = sqlite3_column_text(stmt, 1);
							result = mx_strjoin(result, (char*)selected_login);
							result = mx_strjoin(result, "#");
							result = mx_strjoin(result, (char*)selected_password);
							result = mx_strjoin(result, "|");
						}
						send(connfd, result, BUFFER_LEN, 0);
						
					}
					else if(mx_strcmp(buffer1, "SELECT Name, Last_name, user_id FROM User_profile") == 0)
					{
						sqlite3_prepare_v2(db1, buffer1, -1, &stmt, NULL);
						while(sqlite3_step(stmt) != SQLITE_DONE)
						{
							const unsigned char *selected_1 = sqlite3_column_text(stmt, 0);
							const unsigned char *selected_2 = sqlite3_column_text(stmt, 1);
							const unsigned char *selected_3 = sqlite3_column_text(stmt, 2);
							result = mx_strjoin(result, (char*)selected_1);
							result = mx_strjoin(result, "#");
							result = mx_strjoin(result, (char*)selected_2);
							result = mx_strjoin(result, "#");
							result = mx_strjoin(result, (char*)selected_3);
							result = mx_strjoin(result, "|");
						}
						send(connfd, result, BUFFER_LEN, 0);	
					}
					else if(mx_strcmp(buffer1, "SELECT chat_id, user_id_1, user_id_2 FROM Chat") == 0)
					{
						sqlite3_prepare_v2(db1, buffer1, -1, &stmt, NULL);
						while(sqlite3_step(stmt) != SQLITE_DONE)
						{
							const unsigned char *selected_1 = sqlite3_column_text(stmt, 0);
							const unsigned char *selected_2 = sqlite3_column_text(stmt, 1);
							const unsigned char *selected_3 = sqlite3_column_text(stmt, 2);
							result = mx_strjoin(result, (char*)selected_1);
							result = mx_strjoin(result, "#");
							result = mx_strjoin(result, (char*)selected_2);
							result = mx_strjoin(result, "#");
							result = mx_strjoin(result, (char*)selected_3);
							result = mx_strjoin(result, "|");
						}
						if(result == NULL)
						{
							result = "NONE";
						}
						send(connfd, result, BUFFER_LEN, 0);	
					}
					else if(mx_strstr(buffer1, "SELECT Name, Last_name, Phone, Email FROM User_profile WHERE user_id =") != NULL)
					{
						sqlite3_prepare_v2(db1, buffer1, -1, &stmt, NULL);
						while(sqlite3_step(stmt) != SQLITE_DONE)
						{
							const unsigned char *selected_1 = sqlite3_column_text(stmt, 0);
							const unsigned char *selected_2 = sqlite3_column_text(stmt, 1);
							const unsigned char *selected_3 = sqlite3_column_text(stmt, 2);
							const unsigned char *selected_4 = sqlite3_column_text(stmt, 3);
							result = mx_strjoin(result, (char*)selected_1);
							result = mx_strjoin(result, "#");
							result = mx_strjoin(result, (char*)selected_2);
							result = mx_strjoin(result, "#");
							result = mx_strjoin(result, (char*)selected_3);
							result = mx_strjoin(result, "#");
							result = mx_strjoin(result, (char*)selected_4);
							result = mx_strjoin(result, "|");
						}
						if(result == NULL)
						{
							result = "NONE";
						}
						send(connfd, result, BUFFER_LEN, 0);
					}
					else if(mx_strstr(buffer1, "SELECT text_message, user_id FROM Chat_message WHERE chat_id =") != NULL)
					{
						sqlite3_prepare_v2(db1, buffer1, -1, &stmt, NULL);
						while(sqlite3_step(stmt) != SQLITE_DONE)
						{
							const unsigned char *selected_1 = sqlite3_column_text(stmt, 0);
							const unsigned char *selected_2 = sqlite3_column_text(stmt, 1);
							result = mx_strjoin(result, (char*)selected_1);
							result = mx_strjoin(result, "#");
							result = mx_strjoin(result, (char*)selected_2);
							result = mx_strjoin(result, "|");
						}
						if(result == NULL)
						{
							result = "NONE";
						}
						send(connfd, result, BUFFER_LEN, 0);
					}
					else if(mx_strcmp(buffer1, "SELECT text_message, user_id FROM Chat_message") == 0)
					{
						sqlite3_prepare_v2(db1, buffer1, -1, &stmt, NULL);
						while(sqlite3_step(stmt) != SQLITE_DONE)
						{
							const unsigned char *selected_1 = sqlite3_column_text(stmt, 0);
							const unsigned char *selected_2 = sqlite3_column_text(stmt, 1);
							result = mx_strjoin(result, (char*)selected_1);
							result = mx_strjoin(result, "#");
							result = mx_strjoin(result, (char*)selected_2);
							result = mx_strjoin(result, "|");
						}
						if(result == NULL)
						{
							result = "NONE";
						}
						send(connfd, result, BUFFER_LEN, 0);
					}
					else if(mx_strcmp(buffer1, "SELECT Login FROM User") == 0)
					{
						sqlite3_prepare_v2(db1, buffer1, -1, &stmt, NULL);
						while(sqlite3_step(stmt) != SQLITE_DONE)
						{
							const unsigned char *selected_login = sqlite3_column_text(stmt, 0);
							result = mx_strjoin(result, (char*)selected_login);
							result = mx_strjoin(result, "|");
						}
						send(connfd, result, BUFFER_LEN, 0);
						
					}
					else if(mx_strcmp(buffer1, "SELECT chat_id FROM Chat") == 0)
					{
						sqlite3_prepare_v2(db1, buffer1, -1, &stmt, NULL);
						while(sqlite3_step(stmt) != SQLITE_DONE)
						{
							const unsigned char *selected_login = sqlite3_column_text(stmt, 0);
							result = mx_strjoin(result, (char*)selected_login);
							result = mx_strjoin(result, "|");
						}
						if(result == NULL)
						{
							result = "0|";
						}
						send(connfd, result, BUFFER_LEN, 0);
					}
					else if(mx_strcmp(buffer1, "SELECT user_id FROM User") == 0)
					{
						sqlite3_prepare_v2(db1, buffer1, -1, &stmt, NULL);
						while(sqlite3_step(stmt) != SQLITE_DONE)
						{
							const unsigned char *selected_login = sqlite3_column_text(stmt, 0);
							result = mx_strjoin(result, (char*)selected_login);
							result = mx_strjoin(result, "|");
						}
						send(connfd, result, BUFFER_LEN, 0);
					}
					else if(mx_strcmp(buffer1, "SELECT id FROM User_profile") == 0)
					{
						sqlite3_prepare_v2(db1, buffer1, -1, &stmt, NULL);
						
						while(sqlite3_step(stmt) != SQLITE_DONE)
						{
							const unsigned char *selected_login = sqlite3_column_text(stmt, 0);
							result = mx_strjoin(result, (char*)selected_login);
							result = mx_strjoin(result, "|");
						}
						if(result == NULL)
						{
							result = "0|";
						}
						send(connfd, result, BUFFER_LEN, 0);
					}
					else if(mx_strcmp(buffer1, "SELECT id FROM Chat_message") == 0)
					{
						sqlite3_prepare_v2(db1, buffer1, -1, &stmt, NULL);
						while(sqlite3_step(stmt) != SQLITE_DONE)
						{
							const unsigned char *selected_login = sqlite3_column_text(stmt, 0);
							result = mx_strjoin(result, (char*)selected_login);
							result = mx_strjoin(result, "|");
						}
						if(result == NULL)
						{
							result = "0|";
						}
						send(connfd, result, BUFFER_LEN, 0);
					}
					else if(mx_strcmp(buffer1, "SELECT id FROM User") == 0)
					{
						sqlite3_prepare_v2(db1, buffer1, -1, &stmt, NULL);
						
						while(sqlite3_step(stmt) != SQLITE_DONE)
						{
							const unsigned char *selected_login = sqlite3_column_text(stmt, 0);
							result = mx_strjoin(result, (char*)selected_login);
							result = mx_strjoin(result, "|");
						}
						if(result == NULL)
						{
							result = "0|";
						}
						send(connfd, result, BUFFER_LEN, 0);
					}
					else if(mx_strcmp(buffer1, "SELECT id FROM Chat") == 0)
					{
						sqlite3_prepare_v2(db1, buffer1, -1, &stmt, NULL);
						
						while(sqlite3_step(stmt) != SQLITE_DONE)
						{
							const unsigned char *selected_login = sqlite3_column_text(stmt, 0);
							result = mx_strjoin(result, (char*)selected_login);
							result = mx_strjoin(result, "|");
						}
						send(connfd, result, BUFFER_LEN, 0);
					}
					else if(mx_strcmp(buffer1, "SELECT user_id FROM User_profile") == 0)
					{
						sqlite3_prepare_v2(db1, buffer1, -1, &stmt, NULL);
						
						while(sqlite3_step(stmt) != SQLITE_DONE)
						{
							const unsigned char *selected_login = sqlite3_column_text(stmt, 0);
							result = mx_strjoin(result, (char*)selected_login);
							result = mx_strjoin(result, "|");
						}
						if(result == NULL)
						{
							result = "0|";
						}
						send(connfd, result, BUFFER_LEN, 0);
						
					}
					else if(mx_strstr(buffer1, "SELECT login FROM User WHERE user_id =") != NULL)
					{
						sqlite3_prepare_v2(db1, buffer1, -1, &stmt, NULL);
						while(sqlite3_step(stmt) != SQLITE_DONE)
						{
							const unsigned char *selected_1 = sqlite3_column_text(stmt, 0);
							result = mx_strjoin(result, (char*)selected_1);
						}
						if(result == NULL)
						{
							result = "NONE";
						}
						send(connfd, result, BUFFER_LEN, 0);
					}
					else if(mx_strstr(buffer1, "SELECT password FROM User WHERE user_id =") != NULL)
					{
						sqlite3_prepare_v2(db1, buffer1, -1, &stmt, NULL);
						while(sqlite3_step(stmt) != SQLITE_DONE)
						{
							const unsigned char *selected_1 = sqlite3_column_text(stmt, 0);
							result = mx_strjoin(result, (char*)selected_1);
						}
						if(result == NULL)
						{
							result = "NONE";
						}
						send(connfd, result, BUFFER_LEN, 0);
					}


					else if(mx_strstr(buffer1, "UPDATE User SET password =") != NULL)
					{
						sqlite3_exec(db1, buffer1, NULL, NULL, &err_msg);
						
						send(connfd, "", BUFFER_LEN, 0);
					}
					sqlite3_close(db1);
				}
			}
		}
		
        ticks = time(NULL);
		close(connfd);
    }
	
	return 0;
}

