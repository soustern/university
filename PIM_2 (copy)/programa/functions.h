#include <stdio.h>
#include <stdbool.h>

// Define constant variable to be user elsewhere
#define MAXSIZE 200
#define MAXMAXSIZE 500
#define MINTABLESIZE 500
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

/////////////////////////////////

typedef struct
{
    char *name;
    char *role;
    float salary;
    char *admission;
} createemployee;

typedef struct employee
{
    char name[MAXMAXSIZE];
    char role[MAXMAXSIZE];
    char salary[MAXSIZE];
    char admission[MAXSIZE];
    struct employee *next;
    struct employee *previous;
} employee;

/////////////////////////////////
typedef struct
{
    char *name;
    int quantity;
    float unitary_value;
    float total_value;
} createproduct;

typedef struct product
{
    char name[MAXMAXSIZE];
    char quantity[MAXSIZE];
    char unitary_value[MAXMAXSIZE];
    char total_value[MAXMAXSIZE];
    struct product *next;
    struct product *previous;
} product;

/////////////////////////////////
typedef struct
{
    char *name;
    char *owner_name;
    char *city;
    char *service_type;
    char *contact;
    char *email;
} createdealer;

typedef struct dealer
{
    char name[MAXMAXSIZE];
    char owner_name[MAXMAXSIZE];
    char city[MAXMAXSIZE];
    char service_type[MAXMAXSIZE];
    char contact[MAXMAXSIZE];
    char email[MAXMAXSIZE];
    struct dealer *next;
    struct dealer *previous;
} dealer;

// General purpose functions XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

void clear();

void boilerplate();

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

void menu_show_items();

void answer_show_items();

// ADMIN functions XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

void signup_admin();

void save_account_admin(createaccount account);

void menu_admin();

void answer_admin();

////////////////////////////////////////////////////////////////////////////////////////////

void menu_register_item();

void answer_register_item();

////////////////////////////////////////////////////////////////////////////////////////////

void signup_employee();

void save_employee(createemployee employee);

void show_employee_database_all();

void show_employee_database_detailed(char *option);

bool load_employee_databases();

bool unload_employee_databases();

////////////////////////////////////////////////////////////////////////////////////////////

void signup_product();

void save_product(createproduct product);

void show_product_database_all();

bool load_product_databases();

bool unload_product_databases();

////////////////////////////////////////////////////////////////////////////////////////////

void signup_dealer();

void save_dealer(createdealer dealer);

void show_dealer_database_all();

bool load_dealer_databases();

bool unload_dealer_databases();
