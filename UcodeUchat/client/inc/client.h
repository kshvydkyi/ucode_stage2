#pragma once

#ifndef CLIENT_H
#define CLIENT_H

#define WIDTH 1920
#define HEIGHT 1080
#define BUFFER_LEN 2048

//----Include gtk lib----//
#include <gtk/gtk.h>
/////////////////

//----Include libmx lib----//
#include "../libmx/inc/libmx.h"
//////////////////////

//--------------Include openssl libs------------------//
#include <../../libraries/openssl/include/openssl/bio.h>
#include <../../libraries/openssl/include/openssl/buffer.h>
#include <../../libraries/openssl/include/openssl/des.h>
#include <../../libraries/openssl/include/openssl/evp.h>
#include <../../libraries/openssl/include/openssl/pem.h>
#include <../../libraries/openssl/include/openssl/rsa.h>
#include <../../libraries/openssl/include/openssl/ssl.h>
#include <../../libraries/openssl/include/openssl/md5.h>
///////////////////////////////////////////////////////

//----Include sql lib----//
#include "../../libraries/libs/include/sqlite3.h"
/////////////////

//----Include glib lib----//
#include <glib/gprintf.h>
#include <glib.h>
///////////////////

//----Include other libs----//
#include <ctype.h>
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <assert.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include <signal.h>
#include <cairo.h>
////////////////////////

//--------------------Global variables----------------------//
int client;
int search_person_Witdth;
GtkWidget *messageGrid;

GtkWidget *messageFieldChat_2;

GtkWidget *err_msg_old_pass_not_match;
GtkWidget *err_msg_new_password_wrong;
GtkWidget *err_msg_confirm_pass_wrong;

GtkWidget *Change_pass_old_pass;
GtkWidget *Change_pass_new_pass;
GtkWidget *Change_pass_confirm_pass;
GtkWidget *changePasswordButton;

GtkWidget *PersonFound;
GtkWidget *backBtnDeanon;
GtkWidget *backBtnFaq;
GtkWidget *backBtnDonate;
GtkWidget *backBtnEditProf;

// deanon field
GtkWidget *telephNumber;
GtkWidget *users_name_deanon;
GtkWidget *users_second_name_deanon;
GtkWidget *users_email_deanon;

GtkWidget *users_loginProfileEdit;
GtkWidget *usersTelephoneEditProfile;
GtkWidget *usersNameEditProfile;
GtkWidget *usersSecondNameEditProfile;
GtkWidget *usersEmailEditProfile;

GtkWidget *deanonMeButton;
GtkWidget *loginEntry;
GtkCssProvider *provider;

GtkWidget *emojiiBtn;
GtkWidget *emOtpravkaInputField;

const char *namePersonFound;

int user_id;
int chat_id;
char* ip;
char* port;

bool settings_button_was_clicked;
bool back_button_was_clicked_login;
bool back_button_was_clicked_register;
bool logoutbtn_was_clicked;

bool signUp_button_was_clicked;
bool signIn_button_was_clicked;

GtkWidget *searchePeopleUsernameButton;
GtkWidget *searchedPeopleField;
static GtkTextBuffer *buffer;
GtkWidget *largeEntry;

GtkWidget *mainChatWindow;
GtkWidget *mainChatLayout;

GtkWidget *mainWindow;
GtkWidget *window_login;
GtkWidget *window_register;

GtkWidget *layout_register;
GtkWidget *layout_login;

GtkWidget *passwordEntryLogin;
GtkWidget *passwordEntryRegister;
GtkWidget *ConfirmPasswordEntryRegister;

GtkWidget *donateField;
GtkWidget *faqField;
GtkWidget *photo_and_login_Field;
GtkWidget *deanonField;
GtkWidget *edit_profileField;

GtkWidget *messageFieldChat;

GtkWidget *tri_tochki_btn;

GtkWidget *peregorodka;
GtkWidget *peregorodka_2;
GtkWidget *settingsButtonField;
GtkWidget *settingsButton;

GtkWidget *tritochkiButtonField;

GtkWidget *err_msg_login_exists;
GtkWidget *err_msg_no_login;
GtkWidget *err_msg_password_dont_match;
GtkWidget *err_msg_password_not_strong;
GtkWidget *err_msg_when_user_login;
GtkWidget *background_register;
GtkWidget *background_login;

GtkWidget *signInBtn;
GtkWidget *signUpBtn;

GtkWidget *searchInputField;
GtkWidget *searchInputField_2;

GtkWidget *err_msg_wrong_telepone;
GtkWidget *err_msg_wrong_email;
GtkWidget *err_msg_wrong_name;
GtkWidget *err_msg_wrong_second_name;

GtkWidget *err_msg_old_pass_not_match;
GtkWidget *err_msg_new_password_wrong;
GtkWidget *err_msg_confirm_pass_wrong;

GtkWidget *abcd_btn1;

// edit profile
GtkWidget *userNameProfile;

GtkWidget *writeInputField;
GtkWidget *otpravkaBtn;

GtkWidget *users_photo;

GtkWidget *users_loginProfile;
GtkWidget *scrollable_w;

GtkWidget *buttonMessage[200];
GtkWidget *empty_field[20];

int msg_count;
void db_to_msg();
void show_msg();
/////////////////////////////////////////////////

//--------------------Functions----------------------//
int main_window(int argc, char *argv[], GtkWindow *window_register);
void signInBtn_clicked(GtkWidget *button, GtkWidget *loginData);
void signUpBtn_clicked(GtkWidget *button,GtkWidget *loginData);

void activate (GtkWidget* app, gpointer user_data);
bool check_log_pass(const char login[256], const char password[256]);
gpointer Create_new_button(GtkWidget *layout, char *btn_name, int x, int y, int width, int height);
int mx_strcmp_logins(const char *s1, const char s2[]);
bool check_login_available(const char login[256]);
bool check_strong_password(const char *password);
bool check_usid(int id);
//Check ip-port
int mx_count_words(const char *str, char c);
char *mx_strdup(const char *str);
char *mx_strjoin(const char *s1, const char *s2);
int mx_strlen(const char *s);
char *mx_strndup(const char *s1, size_t n);
char *mx_strnew(const int size);
char **mx_strsplit(const char *s, char c);

void button_login_clicked(GtkWidget *widget,gpointer data, GtkWindow* win);
void button_register_clicked(GtkWidget *widget,gpointer data, GtkWindow* win);
void chat_main(GtkWidget *widget, gpointer data, GtkWindow* win);
void settingsChat(GtkWidget *widget, gpointer data, GtkWindow* win);
void donateFieldChat(GtkWidget *widget, gpointer data, GtkWindow* win);
void faqFieldChatt(GtkWidget *widget, gpointer data, GtkWindow* win);
void deanonFieldChat(GtkWidget *widget, gpointer data, GtkWindow* win);

void backBtnSettingsChat(GtkWidget *widget, gpointer data, GtkWidget* widget1);
void deanonMeButtonClicked(GtkWidget *widget, gpointer data, GtkWidget* widget1);
void tri_tochki_buttonChat(GtkWidget *widget, gpointer data, GtkWindow* win);
void editProfileFieldChat(GtkWidget *widget, gpointer data, GtkWindow* win);
void change_passwordEditProfile();
void search_person(GtkWidget *widget, gpointer data, GtkWidget* widget1);

void sendMessageFunctionChat(GtkWidget *widget, gpointer data, GtkWindow* win);

int search_person_sizeW(const char *name);
int message_sizeW(char *message);
int message_sizeH(char *message);

void searchAccountFound(char *name);
int check_chat_id(int user_id1, int user_id2);
//////////////////////////////////////////////////////////////////////////////////
unsigned char *hash(unsigned char* Password);
#endif

