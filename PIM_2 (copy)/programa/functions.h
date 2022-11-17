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

// Counters XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

int count_numerical_quantity_employee();

int count_numerical_quantity_product();

int count_numerical_quantity_dealer();

void count_total_money_amount_employee();

void count_total_money_amount_product();

// Tutorials XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

void newcomer_message_first();

void newcomer_message_second();

void tutorial_accounts();

void first_steps();

// General purpose functions XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

void clear();

void boilerplate();

bool check_length(char *credential);

bool check_password(char *password, char *confirmation);

bool check_username(char *username);

void press_to_continue();

void login();

bool check_login(account *input);

bool load_account_databases();

int hash_index(char *subject);

bool unload_account_databases();

void menu_show_items();

void answer_show_items();

bool check_if_current_account(char *username);

bool remove_account(char *username);

// // // // // // // //

void menu_manual_admin();

void menu_manual_limited();

void answer_manual_admin();

void answer_manual_limited();

// LIMITED functions XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

void menu_limited();

void answer_limited();

// ADMIN functions XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

void signup_admin();

void signup_limited();

void save_account_admin(createaccount account);

void save_account_limited(createaccount account);

void menu_admin();

void answer_admin();

void menu_register_item();

void answer_register_item();

void menu_remove_item();

void answer_remove_item();

void menu_edit_item();

void answer_edit_item();

void menu_signup_account();

void answer_signup_account();

void remove_account_menu_and_answer();

////////////////////////////////////////////////////////////////////////////////////////////

void signup_employee();

void save_employee(createemployee employee);

void show_employee_database_all();

bool load_employee_databases();

bool unload_employee_databases();

void show_employee_database_detailed();

void remove_employee();

void edit_employee();

////////////////////////////////////////////////////////////////////////////////////////////

void signup_product();

void save_product(createproduct product);

void show_product_database_all();

bool load_product_databases();

bool unload_product_databases();

void show_product_database_detailed();

void remove_product();

void edit_product();

////////////////////////////////////////////////////////////////////////////////////////////

void signup_dealer();

void save_dealer(createdealer dealer);

void show_dealer_database_all();

bool load_dealer_databases();

bool unload_dealer_databases();

void show_dealer_database_detailed();

void remove_dealer();

void edit_dealer();