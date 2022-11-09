#include <stdio.h>
#include <stdbool.h>

// Define constant variable to be user elsewhere
#define MAXSIZE 200
#define MINTABLESIZE 200
#define MAXTABLESIZE 1000

// Structs XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

typedef struct
{
    char *username;
    char *password;
} createaccount;

typedef struct account
{
    char username[MAXSIZE];
    char password[MAXSIZE];
    char type[MAXSIZE];
    struct account *next;
} account;

// accountadmin table_account_admin[TABLESIZE];

// General purpose functions XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

void clear();

bool check_length(char *credential);

bool check_password(char *password, char *confirmation);

bool check_username(char *username);

void newcomer_message_first();

void newcomer_message_second();

void press_to_continue();

void login();

bool check_login(account *input);

bool load_account_databases();

int hash_index(char *subject);

bool unload_account_databases();

// ADMIN functions XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

void signup_admin();

void save_account_admin(createaccount account);

void menu_admin();

void answer_admin();
