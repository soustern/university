#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <ctype.h>

// Include "linker" header file
#include "functions.h"

// Declare global structs
employee *table_employee[MINTABLESIZE];

// Declare global variables
int increment_answer_register_item = 0;

// ADMIN functions XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// Function to signup a ADMIN account
void signup_admin()
{

    // Load all account databases onto memory
    load_account_databases();

    // Initialize a storage struct of type "createperson"
    createaccount storage;

    // Alloc a big chunck of memory to "confirmation" | The size will that of "MAXSIZE" constant
    // Declare storage variable that will be responsible for receiving "password confirmation" input
    char *confirmation = (char *)malloc(MAXSIZE);
    if (confirmation == NULL)
    {
        puts("ERRO 1: Memória insuficiente no sistema");
        return;
    }

    // Alloc a big chunck of memory to "storage.username" | The size will that of "MAXSIZE" constant
    // The memory allocated has to be big as to be user-error proof
    storage.username = (char *)malloc(MAXSIZE);
    if (storage.username == NULL)
    {
        puts("ERRO 1: Memória insuficiente no sistema");
        return;
    }

    // Alloc a big chunck of memory to "storage.password" | The size will that of "MAXSIZE" constant
    // The memory allocated has to be big as to be user-error proof
    storage.password = (char *)malloc(MAXSIZE);
    if (storage.password == NULL)
    {
        puts("ERRO 1: Memória insuficiente no sistema");
        return;
    }

    do
    {
        // Clear terminal screen
        clear();

        // Boilerplate
        puts("\t\t\t<<<<< SLS 1.0 >>>>>\n");
        puts("Conta com status 'ADMINISTRADORA'\n");

        // Start asking for user input
        printf("Nome de usuario (Entre 5 e 10 caracteres): ");
        fgets(storage.username, MAXSIZE, stdin);

        // Remove trailing newline that comes together with user input when fgets() is used
        storage.username[strcspn(storage.username, "\n")] = 0;

    } while (check_length(storage.username) == false || check_username(storage.username) == false);

    /* FILE *f = fopen("credential.txt", "a");
    fwrite(storage.username, strlen(storage.username), 1, f);
    fclose(f); */

    do
    {

        // Clear terminal screen
        clear();

        // Boilerplate
        puts("\t\t\t<<<<< SLS 1.0 >>>>>\n");
        puts("Conta com status 'ADMINISTRADORA'\n");

        // Start asking for user input
        printf("Nome de usuario (Entre 5 e 10 caracteres): %s", storage.username);

        puts("\n\n*****A senha não aparecerá enquanto a digitação ocorrer*****");

        // Turn off terminal echoing to mask password
        // TODO: REDO THIS FUNCTIONS FOR WINDOWS
        storage.password = strdup(getpass("Senha (Entre 5 e 10 caracteres): "));

    } while (check_password(storage.password, confirmation) == false);

    // Call save_acount_admin function
    save_account_admin(storage);

    // Free all allocated memory
    free(storage.username);
    free(storage.password);
    free(confirmation);

    // Unload initially loaded database
    unload_account_databases();
}

// Function that will save a new account when all the validations passes
void save_account_admin(createaccount account)
{

    // Declare e FILE Pointer
    FILE *data;

    // Save account.username in a file ->->->->->->

    // Open the correct file
    data = fopen("macros/account.txt", "a");

    // Append username and password to file
    fprintf(data, "%s", account.username);

    // Print a line break in beetween
    // This must be done because we removed the \n at the last position of the account.username[] array
    fprintf(data, "\n");

    fprintf(data, "%s\n", account.password);
    fprintf(data, "admin\n");

    fclose(data);
}

// Function that will render a functionality menu with ADMIN capabilities
void menu_admin()
{

    // Clear terminal screen
    clear();

    // Boiler plate
    puts("\t\t\t<<<<< SLS 1.0 >>>>>\n");
    puts("Conta com status 'ADMINISTRADORA'\n\n");

    // Available tools
    puts("1 - Cadastrar item");
    puts("2 - Vizualizar item\n");

    puts("3 - Excluir item");
    puts("4 - Editar item\n");

    puts("5 - Cadastrar conta");
    puts("6 - Excluir conta\n");

    puts("7 - Relatórios");
    puts("8 - Configurações");
    puts("9 - Manual\n");

    puts("e - Sair\n");

    // Call answer_admin function
    answer_admin();
}

// Function that will receive user answer and will route another function
void answer_admin()
{

    // Declare a multipurpose storage variable
    char storage;

    printf("\nFerramenta escolhida (Insira o numero): ");

    // Get user input
    scanf("%c", &storage);

    // Route depending on user input
    switch ((char)storage)
    {
    case '1':
        menu_register_item();
        break;
    case '2':
        /* code */
        break;
    case '3':
        /* code */
        break;
    case '4':
        /* code */
        break;
    case '5':
        /* code */
        break;
    case '6':
        /* code */
        break;
    case '7':
        /* code */
        break;
    case '8':
        /* code */
        break;
    case '9':
        /* code */
        break;
    case 'e':
        getchar();
        press_to_continue();
        break;
    default:
        puts("Opção inválida!");
        press_to_continue();
        menu_admin();
    }
}

////////////////////////////////////////////////////////////////////////////////////////////

// Function to create a new employee
void signup_employee()
{
}

// Function to print the options presents at "1 - Register Item"
void menu_register_item()
{
    // Clear terminal screen
    clear();

    // Boiler plate
    puts("\t\t\t<<<<< SLS 1.0 >>>>>\n");

    // Available tools
    puts("1 - Cadastar PRODUTO\n");
    puts("2 - Cadastrar FORNECEDOR\n");
    puts("3 - Cadastrar FUNCIONÁRIO\n");

    puts("e - Voltar");

    // Call answer_register_item function
    answer_register_item();
}

// Function that will receive user answer and will route another function
void answer_register_item()
{

    if (increment_answer_register_item == 0)
    {
        getchar();
    }

    increment_answer_register_item++;

    // Declare a multipurpose storage variable
    char storage;

    printf("\nFerramenta escolhida (Insira o numero): ");

    // Get user input
    scanf("%c", &storage);

    // Route depending on user input
    switch ((char)storage)
    {
    case '1':
        /* code */
        break;
    case '2':
        /* code */
        break;
    case '3':
        /* code */
        break;
    case '4':
        /* code */
        break;
    case 'e':
        increment_answer_register_item = 0;
        getchar();
        press_to_continue();
        menu_admin();
        break;
    default:
        puts("Opção inválida!");
        press_to_continue();
        menu_register_item();
    }
}

////////////////////////////////////////////////////////////////////////////////////////////

// Function that will load all databases hashtables of employees
bool load_employee_databases()
{

    // Create a buffer
    char *buffer = malloc(MAXMAXSIZE);
    if (buffer == NULL)
    {
        puts("ERRO 1: Não há memória o suficiente no sistema");
        return false;
    }

    // Declare a variable that will receive hashed indexes
    int index;

    // Declare a struct of "employee" type
    // Initialize it to NULL
    employee *node = NULL;

    // Load "employee" databases ->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->

    // Open "employee.txt" file
    FILE *data = fopen("macros/employee.txt", "r");
    if (data == NULL)
    {
        puts("ERRO 2: Não foi possível abrir o arquivo necessário");
        return false;
    }

    // Write each string inside the file onto the buffer | buffer content is overwritten at this moment
}