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

// First Session functions XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
void signup();
//  void check_username(char *username);