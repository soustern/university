#include <stdio.h>
#include <stdbool.h>

// Define constant variable to be user elsewhere
#define MAXSIZE 200
#define MINTABLESIZE 200
#define MAXTABLESIZE 200

// Structs XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

typedef struct
{
    char *username;
    char *password;
} createaccount;

typedef struct accountadmin
{
    char username[MAXSIZE];
    char password[MAXSIZE];
    char type[MAXSIZE];
    struct accountadmin *next;
} accountadmin;

// accountadmin table_account_admin[TABLESIZE];

// General purpose functions XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

void clear();

bool check_length(char *credential);

bool check_password(char *password, char *confirmation);

/* void remove_first_space(char *password); */

void newcomer_message_first();

void newcomer_message_second();

void press_to_continue();

void login();

bool load_databases();

int hash_index(char *subject);

// ADMIN functions XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

void signup_admin();

void save_account_admin(createaccount account);

void menu_admin();

void answer_admin();
