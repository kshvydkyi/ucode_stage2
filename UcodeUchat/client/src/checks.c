#include "../inc/client.h"

bool check_log_pass(const char login[256], const char password[256])
{
	bool login_was_found = false;
	unsigned char *result = mx_strnew1(BUFFER_LEN);
	send(client, "SELECT Login, Password FROM User", BUFFER_LEN, 0);
	recv(client, result, BUFFER_LEN, 0);
	printf("%s\n", result);
	unsigned char **tmp1 = mx_strsplit1(result, '|');
	if(mx_strcmp_logins(login, "1") == 0)
	{
		if(mx_strcmp_logins(password, "1") == 0)
		{
			return true;
		}
	}
	for(int i = 0; tmp1[i]; i++) 
	{
		printf("%s\n", tmp1[i]);
		unsigned char** tmp2 = mx_strsplit1(tmp1[i], '#');
		const char *selected_login = (const char*)tmp2[0];
		unsigned char *selected_password = tmp2[1];
		if(mx_strcmp_logins(selected_login, login) == 0) 
		{
			if(mx_strcmp_logins((const char *)selected_password, (const char *)hash((unsigned char *)password)) != 0)
			{
				return false;
			}
			login_was_found = true;
		}
	}
	if(login_was_found == false)
	{
		return false;
	}
	return true;
}

bool check_login_available(const char login[256])
{
	char *result = mx_strnew(BUFFER_LEN);
	send(client, "SELECT Login FROM User", BUFFER_LEN, 0);
	recv(client, result, BUFFER_LEN, 0);
	char **tmp1 = mx_strsplit(result, '|');
	for(int i = 0; tmp1[i]; i++) 
	{
		if(mx_strcmp_logins(tmp1[i], login) == 0)
		{
			return false;
		}
	}
	return true;
}

bool check_usid(int id)
{
	char *result = mx_strnew(BUFFER_LEN);
	send(client, "SELECT user_id FROM User", BUFFER_LEN, 0);
	recv(client, result, BUFFER_LEN, 0);
	char **tmp1 = mx_strsplit(result, '|');
	for(int i = 0; tmp1[i]; i++) 
	{
		if(mx_strcmp(tmp1[i], mx_itoa(id)) == 0)
		{
			return false;
		}
	}
	return true;
}

bool check_chatidava(int id)
{
	char *result = mx_strnew(BUFFER_LEN);
	send(client, "SELECT chat_id FROM Chat", BUFFER_LEN, 0);
	recv(client, result, BUFFER_LEN, 0);
	char **tmp1 = mx_strsplit(result, '|');
	for(int i = 0; tmp1[i]; i++) 
	{
		if(mx_atoi(tmp1[i]) == id)
		{
			return false;
		}
	}
	return true;
}

int check_chat_id(int user_id1, int user_id2)
{
	char *result = mx_strnew(BUFFER_LEN);
	send(client, "SELECT chat_id, user_id_1, user_id_2 FROM Chat", BUFFER_LEN, 0);
	recv(client, result, BUFFER_LEN, 0);
	if(mx_strcmp(result, "NONE") == 0)
	{
		int secret = rand() % 10000 + 1000;
		while(check_chatidava(secret) == false)
		{
			secret = rand() % 10000 + 1000;
		}
		char *query = sqlite3_mprintf("INSERT INTO Chat VALUES (%d, '%q', '%q', '%q');", 0, mx_itoa(secret), mx_itoa(user_id1), mx_itoa(user_id2));
		send(client, query, BUFFER_LEN, 0);
		return secret;
	}
	else
	{
		char **tmp1 = mx_strsplit(result, '|');
		for(int i = 0; tmp1[i]; i++) 
		{
			char **tmp2 = mx_strsplit(tmp1[i], '#');

			if((mx_atoi(tmp2[1]) == user_id1 && mx_atoi(tmp2[2]) == user_id2) || (mx_atoi(tmp2[1]) == user_id1 && mx_atoi(tmp2[2]) == user_id1))
			{
				return mx_atoi(tmp2[0]);
			}
		}
		char *result1 = mx_strnew(BUFFER_LEN);
		send(client, "SELECT id FROM Chat", BUFFER_LEN, 0);
		recv(client, result1, BUFFER_LEN, 0);
		int id = 0;
		char **tmp2 = mx_strsplit(result1, '|');
		for(int i = 0; tmp2[i]; i++) 
		{
			id = mx_atoi(tmp2[i]);
		}
		int secret = rand() % 10000 + 1000;
		while(check_chatidava(secret) == false)
		{
			secret = rand() % 10000 + 1000;
		}
		char *query = sqlite3_mprintf("INSERT INTO Chat VALUES (%d, '%q', '%q', '%q');", id+1, mx_itoa(secret), mx_itoa(user_id1), mx_itoa(user_id2));
		send(client, query, BUFFER_LEN, 0);
		return secret;
	}
	return -1;
}

bool check_strong_password(const char *password)
{
	bool hasUpper = false;
	bool hasLower = false;
	bool hasDigit = false;
	for(int i = 0; password[i]; i++)
	{
		if(islower(password[i])) hasLower = true;
    	if(isupper(password[i])) hasUpper = true;
    	if(isdigit(password[i])) hasDigit = true;
	}
	if(hasLower && hasUpper && hasDigit)
	{
    	return true;
	}
	else
	{ 
    	return false;
	}  
}

