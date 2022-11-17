#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <ctype.h>

// Include "linker" header file
#include "functions.h"

// Declare global structs
account *table_account[MINTABLESIZE];
char current_account[MAXMAXSIZE];

// Declare global variables
int increment_answer_debug = 0;

// General purpose functions XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// Function to clean terminal screen
void clear()
{
    // For linux
    system("clear");
    // For windows
    // system("clr");
}

// Print boilerplate on screen
void boilerplate()
{
    // Clear terminal screen
    clear();

    // Boilerplate
    puts("\t\t\t<<<<< SLS 1.0 >>>>>\n");
}

// Function that checks if a given credential falls under the specifications
bool check_length(char *credential)
{

    // Declare variable that will increment starting from zero
    int increment = 0;
    int check = 0;

    // Loop that will go around strlen(credential) times
    for (int i = 0, n = strlen(credential); i < n; i++)
    {
        // printf("%i %i\n", check, increment);
        // printf("%c\n", credential[i]);

        if (credential[i] == 0)
        {
            break;
        }

        // Increment goes up by one for every array position that does not contain a space character
        if (credential[i] >= 33 && credential[i] <= 126)
        {
            increment++;
        }

        // "check" goes up by one at every loop iteration
        check++;

        // Check if there are spaces present in the input
        // We do this by checking if "check" amounts to 10 even though increment is less than 10
        // If increment gets bigger than 10, we also stop there
        if (credential[i] == 32 || increment > 10)
        {

            // printf("\n\n%i\n\n", increment);
            // free(credential);

            // puts("check == 10 && increment < 10 || increment > 10");

            puts("\nNome de Usuario/Senha INVALIDO!");
            puts("Seu Nome de Usuario/Senha devem ter entre 5 e 10 caracteres sem espaços");

            press_to_continue();

            return false;
        }
    }

    // printf("\n\n%i\n\n", increment);

    // Check if the amount of "no-space" characters present in user input is less than 5
    if (increment < 5)
    {
        // Free allocated memory
        // free(credential);

        // puts("check == 10 && increment < 10 || increment > 10");

        puts("\nNome de Usuario/Senha INVALIDO!");
        puts("Seu Nome de Usuario/Senha devem ter entre 5 e 10 caracteres sem espaços");

        press_to_continue();
    }
    else
    {
        return true;
    }
}

// Function that will ask for a confirmation of a password
// And validate if both given passwords are equal
bool check_password(char *password, char *confirmation)
{

    // if check_length has already returned false, dont even bother continuing this function
    if (check_length(password) == false)
    {
        return false;
    }

    // Declare increment variable starting from zero
    int increment = 0;

    // Ask for password confirmation
    confirmation = strdup(getpass("Insira a senha novamente: "));

    // Check each character on the array of the newly received string
    // // Loop that will go around strlen(password) times
    for (int i = 0, n = strlen(password); i < n; i++)
    {

        // If characters at each array position are the same..
        if (confirmation[i] == password[i])
        {

            // Increment goes up by one
            increment++;
        }
        else
        {
            puts("\nAs senhas inseridas não são iguais!");

            press_to_continue();

            return false;
        }
    }

    // Check if amount of times both array position match is equal to the lenght of the passed value "password"
    if (increment != strlen(password))
    {
        puts("\nAs senhas inseridas nao sao iguais!");

        press_to_continue();

        return false;
    }
    else
    {
        return true;
    }
}

// Fnction that waits until user presses ENTER to continue
void press_to_continue()
{

    // Multipurpose character storage variable
    char storage;

    puts("Aperte ENTER para continuar...");

    // Wait until user presses enter
    scanf("%c", &storage);
    while (storage != 10)
    {
        scanf("%c", &storage);
    }
}

// Function that will load all databases hashtables of accounts
bool load_account_databases()
{

    // Create a buffer
    char *buffer = malloc(MAXSIZE);
    if (buffer == NULL)
    {
        puts("ERRO 1: Não há memória suficiente no sistema");
        return false;
    }

    // Declare a variable that will receive hashed indexes
    int index;

    // clare a struct of the "account" type
    // Initialize it to NULL
    account *node = NULL;

    // Load "account" databases ->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->

    // Open "account_admin.txt" file
    FILE *data = fopen("macros/account.txt", "r");
    if (data == NULL)
    {
        puts("ERRO 2: Não foi possível abrir o arquivo necessário");
        return false;
    }

    // Write each string inside the file onto the buffer | buffer content is overwritten at this moment
    while (fscanf(data, "%s", buffer) == 1)
    {

        // Allocate new memory to node at each iteration
        node = malloc(sizeof(account));
        if (node == NULL)
        {
            puts("ERRO 1: Não há memória suficiente no sistema");
            return false;
        }

        // Copy the string present at that line of the file to the username section of the current node
        strcpy(node->username, buffer);

        // Scan string from another line of the file to the buffer once again | buffer content is overwritten at this moment
        fscanf(data, "%s", buffer);

        // Copy the string present at that line of the file to the password section of the current node
        strcpy(node->password, buffer);

        // Scan string from another line of the file to the buffer once again | buffer content is overwritten at this moment
        fscanf(data, "%s", buffer);

        // Set the type of the account for that node
        strcpy(node->type, buffer);

        // Index variable receives the value returned by the hash(node->) func
        index = hash_index(node->username);

        // Check if table_account[index] is pointer is pointing to NULL
        if (table_account[index] == NULL)
        {

            // If so, current node "next" pointer must point to NULL
            node->next = NULL;

            // That array position of table_account must point to the current node
            table_account[index] = node;

            // Skip next lines of code a got to the next iteration
            continue;
        }

        // If previous "if condition" is not met
        // Current node "next" point must point to what table_account[index] is pointing to
        node->next = table_account[index];

        // table_account must point to what the current node
        table_account[index] = node;
    }

    // Close the previously opened file
    fclose(data);

    // Free all allocated memory ->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->
    free(buffer);

    return true;
}

// Functions that will create a hash index based on a argument passed subject
int hash_index(char *subject)
{

    // Declare "index" variable
    int index = 0;

    for (int i = 0, n = sizeof(subject) - 1; i < n; i++)
    {
        index = index + tolower(subject[i]);
    }

    if (index > MINTABLESIZE)
    {
        index = index % MINTABLESIZE;
    }

    return index;
}

// Function to login with a account
void login()
{

    // Load all account databases onto memory
    load_account_databases();

    // Initialize a point to a struct of type account and allocate memory to it
    // This needs to be a pointer so we can exchange information with the check_login func later on
    account *storage = malloc(sizeof(account));
    if (storage == NULL)
    {
        puts("ERRO 1: Não há memória suficiente no sistema.");
        return;
    }

    do
    {

        boilerplate();

        // Start asking for user input
        printf("Nome de usuario (Entre 5 e 10 caracteres): ");
        fgets(storage->username, MAXSIZE, stdin);

        // Remove trailing newline that comes together with user input when fgets() is used
        storage->username[strcspn(storage->username, "\n")] = 0;

        puts("\n*****A senha não aparecerá enquanto a digitação ocorrer*****");

        // Copy to the memory location at storage->password the value at the memory location getpass() is pointing to
        strcpy(storage->password, getpass("Senha: "));
    } while (check_login(storage) == false);

    // Copy user input to current_account of struct of account type
    strcpy(current_account, storage->username);

    // If the value at memory location "storage->type" is "admin"
    if (strcmp(storage->type, "admin") == 0)
    {

        // We unload database, unload the previously allocated memory that storage is pointing to, and inicitialize menu_admin()
        unload_account_databases();
        free(storage);
        menu_admin();
    }
    else
    {
        // We unload database, unload the previously allocated memory that storage is pointing to, and inicitialize menu_parcial()
        unload_account_databases();
        free(storage);
        menu_limited();
    }
}

// Function that will check if the credential provided at the login() function exists in the database
bool check_login(account *input)
{

    // Declare a variable that will receive the valor returned by hash_index function
    int index = hash_index(input->username);

    // Navigate horizontally a linked list
    for (account *tmp = table_account[index]; tmp != NULL; tmp = table_account[index]->next)
    {
        // If the the values of both input and tmp locations "->username" and "->password" are equal
        if (strcmp(input->username, tmp->username) == 0 && strcmp(input->password, tmp->password) == 0)
        {
            // We copy the value present at the memory location "tmp->type" is pointing to
            // To the memory location "input->type" is pointing to
            strcpy(input->type, tmp->type);
            return true;
        }
    }

    // unload_account_databases();
    puts("\nNome de usuário e/ou senha não encontrados.");
    press_to_continue();
    return false;
}

// Function that will check all databases to see if given username already exists
bool check_username(char *username)
{

    // Declare a variable that will receive the valor returned by hash_index function
    int index = hash_index(username);

    // Navigate horizontally a linked list
    for (account *tmp = table_account[index]; tmp != NULL; tmp = table_account[index]->next)
    {

        // If the the values of both input and tmp locations "->username"  are equal
        if (strcmp(username, tmp->username) == 0)
        {

            // If so, return false, that name already exists
            puts("\nNome de usuário já existe!");
            press_to_continue();
            return false;
        }
    }

    // Default
    return true;
}

// Unloads table_account from memory, returning true if successful, else false
bool unload_account_databases()
{

    // Create a pointer of to a struct of type account that will serve as a cursor
    account *cursor = NULL;

    // loop that will go around the amount of time it is specified in the MIN and MAX TABLESIZE consts
    for (int i = 0; i < MINTABLESIZE; i++)
    {

        // Navigate horizontally a linked list
        for (account *tmp = table_account[i]; tmp != NULL; tmp = cursor)
        {
            cursor = table_account[i]->next;
            free(table_account[i]);
            table_account[i] = cursor;
        }
    }

    return true;
}

// Function that will present the options avaiable at the "show items" section
void menu_show_items()
{
    boilerplate();

    puts("1 - Vizualizar PRODUTOS\n");
    puts("2 - Vizualizar FORNECEDORES\n");
    puts("3 - Vizualizar FUNCIONÁRIOS\n");

    puts("e - Voltar");

    // Call answer_show_items function
    answer_show_items();
}

// Function get a answer and display further options within the "show items" functionality
void answer_show_items()
{

    // Global incrementor that will make it so every trailing \n character at "stdin" is removed by getchar
    // Preventing weird behavior such as the switch func detecting and invalid input instantly
    if (increment_answer_debug == 0)
    {
        getchar();
    }

    increment_answer_debug++;

    // Declare the variable wich will receive user answer and a esecond one
    char storage;
    char storage2;

    printf("\nFerramenta escolhida (Insira o numero): ");

    // Get user input
    scanf("%c", &storage);

    // Route depending on user input
    // tolower() function is invoked so the program works if user input is capslock
    switch (tolower((char)storage))
    {
    case '1':
        // Get trailing new line (\n) character
        getchar();

        boilerplate();

        puts("VIZUALIZAR PRODUTOS:\n");

        puts("1 - Vizualizar TODOS\n");
        puts("2 - Pesquisar\n");

        puts("e - Voltar");

        printf("\nFerramenta escolhida (Insira o numero): ");

        // Get user input
        scanf("%c", &storage2);

        // Route depending on user input
        // tolower() function is invoked so the program works if user input is capslock
        switch (tolower((char)storage2))
        {
        // PRODUCT XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
        case '1':
            show_product_database_all();
        case '2':
            show_product_database_detailed();
        case 'e':
            getchar();
            menu_show_items();
        default:
            puts("Opção inválida!");
            press_to_continue();
            menu_show_items();
        }
    // DEALER XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    case '2':
        // Get trailing new line (\n) character
        getchar();

        boilerplate();

        puts("VIZUALIZAR FORNECEDORES:\n");

        puts("1 - Vizualizar TODOS\n");
        puts("2 - Pesquisar\n");

        puts("e - Voltar");

        printf("\nFerramenta escolhida (Insira o numero): ");

        // Get user input
        scanf("%c", &storage2);

        // Route depending on user input
        // tolower() function is invoked so the program works if user input is capslock
        switch (tolower((char)storage2))
        {
        case '1':
            show_dealer_database_all();
        case '2':
            show_dealer_database_detailed();
        case 'e':
            getchar();
            menu_show_items();
        default:
            puts("Opção inválida!");
            press_to_continue();
            menu_show_items();
        }
    // EMPLOYEES XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
    case '3':
        // Get trailing new line (\n) character
        getchar();

        boilerplate();

        puts("VIZUALIZAR FUNCIONÁRIOS:\n");

        puts("1 - Vizualizar TODOS\n");
        puts("2 - Pesquisar\n");

        puts("e - Voltar");

        printf("\nFerramenta escolhida (Insira o numero): ");

        // Get user input
        scanf("%c", &storage2);

        // Route depending on user input
        // tolower() function is invoked so the program works if user input is capslock
        switch (tolower((char)storage2))
        {
        case '1':

            // Call show_employee_database_all function
            show_employee_database_all();
        case '2':

            // Call show_employee_database_detailed function
            show_employee_database_detailed();
        case 'e':
            getchar();
            menu_show_items();
        default:
            puts("Opção inválida!");
            press_to_continue();
            menu_show_items();
        }
    case 'e':
        increment_answer_debug = 0;
        getchar();
        menu_admin();
    default:
        puts("Opção inválida!");
        press_to_continue();
        menu_show_items();
    }
}

// Function that will check if user is trying to remove an account that is present at current_account
bool check_if_current_account(char *username)
{

    // Remove the trailing newline character "\n" currently present at the last array position of username
    username[strcspn(username, "\n")] = 0;

    // Check if user input is equal to what is present at current_account globar variable
    if (strcmp(current_account, username) == 0)
    {
        boilerplate();
        puts("Não é possível excluir a conta que");
        puts("esta sendo utilizada no momento!\n");
        press_to_continue();
        return false;
    }
    else
    {
        return true;
    }
}

// Function to remove an account or signal if it doesnt exist
bool remove_account(char *username)
{

    // Load all account databases
    load_account_databases();

    // Declare a variable that will increment
    int increment = 0;

    // FIRST WE CHECK IF USER INPUT IS PRESENT AT THE DATABASE AT ALL
    // Loop that will go around MINTABLESIZE times
    for (int i = 0; i < MINTABLESIZE; i++)
    {

        // Navigate a linked list horizontally
        for (account *tmp = table_account[i]; tmp != NULL; tmp = tmp->next)
        {
            printf("\n%s %s\n", username, tmp->username);
            if (strcmp(tmp->username, username) == 0)
            {
                increment++;
            }
        }
    }

    if (increment == 0)
    {
        boilerplate();
        puts("Nenhum item foi encontrado");
        unload_account_databases();
        press_to_continue();
        return false;
    }

    // If the function does not return, WE CAN BEGIN

    // Replace the content of "account.txt" with the current content of table_account at all indexes
    // We must open the database and erase its contents by using the parameter "w" at fopen()
    FILE *data = fopen("macros/account.txt", "w");

    // Close so it can be reopened with a append "a" mode
    fclose(data);

    data = fopen("macros/account.txt", "a");

    // Make it so the file is line buffered, not block buffered
    // This makes it so we can write onto the file while the program is running
    // Otherwise, we woul have to wait until the program is closed
    setlinebuf(data);

    // Declare a storage struct of type "account"
    account storage;

    // Loop that goes around MINTABLESIZE times
    for (int i = 0; i < MINTABLESIZE; i++)
    {

        // Navigate a linked list horizontally
        for (account *tmp = table_account[i]; tmp != NULL; tmp = tmp->next)
        {

            if (strcmp(tmp->username, username) == 0)
            {
                continue;
            }

            // Copy the string present at this position of tmp to the storage.(appropriate section)
            strcpy(storage.username, tmp->username);
            strcpy(storage.password, tmp->password);
            strcpy(storage.type, tmp->type);

            // Append the strings present at storage.(section) onto the file
            fprintf(data, "%s\n", storage.username);
            fprintf(data, "%s\n", storage.password);
            fprintf(data, "%s\n", storage.type);
        }
    }

    // Close all opened files
    fclose(data);

    // Unload all loaded databases
    unload_account_databases();

    return true;
}