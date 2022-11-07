#include <stdio.h>
#include <stdbool.h>

// Define constant variable to be user elsewhere
#define MAXSIZE 200

// Structs XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

typedef struct
{
    char *username;
    char *password;
} createperson;

// General purpose functions XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

void clear();

bool check_length(char *credential);

bool check_password(char *password, char *confirmation);

void newcomer_message_first();

void newcomer_message_second();

void press_to_continue();

// ADMIN functions XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

void signup_admin();

void menu_admin();

void answer_admin();
