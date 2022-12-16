#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <time.h>

// Include "linker" header file
#include "functions.h"

// Declare global structs
employee *table_employee[MINTABLESIZE];
product *table_product[MINTABLESIZE];
dealer *table_dealer[MINTABLESIZE];

// Declare global variables
int increment_remove_account = 0;
int increment_signup_admin = 0;
int increment_answer_signup_account = 0;
int increment_answer_edit_item = 0;
int increment_answer_register_item = 0;
int increment_answer_remove_item = 0;
int increment_answer_general_debug_employee = 0;
int increment_answer_general_debug_product = 0;
int increment_answer_general_debug_dealer = 0;

//
//
//
//
// REPORT XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// Functions to count the total amount of items are present at all databases
int count_numerical_quantity_employee()
{

    // Load all employee databases
    load_employee_databases();

    // Declare an increment variable
    int increment = 0;

    // Loop that will go around MINTABLESIZE times
    for (int i = 0; i < MINTABLESIZE; i++)
    {

        // Navigate a linked list horizontally
        for (employee *tmp = table_employee[i]; tmp != NULL; tmp = tmp->next)
        {
            // For every iteration, increment goes up by one
            increment++;
        }
    }

    // Unload all employee databases
    unload_employee_databases();

    return increment;
}

int count_numerical_quantity_product()
{

    // Load all product databases
    load_product_databases();

    // Declare an increment variable
    int increment = 0;

    // Loop that will go around MINTABLESIZE times
    for (int i = 0; i < MINTABLESIZE; i++)
    {

        // Navigate a linked list horizontally
        for (product *tmp = table_product[i]; tmp != NULL; tmp = tmp->next)
        {
            // For every iteration, increment goes up by one
            increment++;
        }
    }

    // Unload all product databases
    unload_product_databases();

    return increment;
}

int count_numerical_quantity_dealer()
{

    // Load all dealer databases
    load_dealer_databases();

    // Declare an increment variable
    int increment = 0;

    // Loop that will go around MINTABLESIZE times
    for (int i = 0; i < MINTABLESIZE; i++)
    {

        // Navigate a linked list horizontally
        for (dealer *tmp = table_dealer[i]; tmp != NULL; tmp = tmp->next)
        {
            // For every iteration, increment goes up by one
            increment++;
        }
    }

    // Unload all dealer databases
    unload_dealer_databases();

    return increment;
}

// Function to calculate the total amount of money it is needed to pay for employee salaries
float calculate_total_money_amount_employee()
{

    // Load all employee databases
    load_employee_databases();

    // Declare a float variable
    float amount = 0;

    // Loop that will go around MINTABLESIZE times
    for (int i = 0; i < MINTABLESIZE; i++)
    {

        // Navigate a linked list horizontally
        for (employee *tmp = table_employee[i]; tmp != NULL; tmp = tmp->next)
        {
            amount = amount + atoi(tmp->salary);
        }
    }

    // Unload all loaded databasess
    unload_employee_databases();

    return amount;
}

// Function to calculate the arithmetical medium of employee salaries
float calculate_medium_money_amount_employee()
{
    return calculate_total_money_amount_employee() / count_numerical_quantity_employee();
}

// Function to calculate the total amount of money has been spent with products
float calculate_total_money_amount_product()
{

    // Load all product databases
    load_product_databases();

    // Declare a float variable
    float amount = 0;

    // Loop that will go around MINTABLESIZE times
    for (int i = 0; i < MINTABLESIZE; i++)
    {

        // Navigate a linked list horizontally
        for (product *tmp = table_product[i]; tmp != NULL; tmp = tmp->next)
        {
            amount = amount + atoi(tmp->total_value);
        }
    }

    // Unload all loaded databasess
    unload_product_databases();

    return amount;
}

// Function to calculate the arithmetical medium of total product value
float calculate_medium_money_amount_product()
{
    return calculate_total_money_amount_product() / count_numerical_quantity_product();
}

// Function that will return the value off all items present at all databases summed up
int count_item_total()
{
    return count_numerical_quantity_dealer() + count_numerical_quantity_employee() + count_numerical_quantity_product();
}

//
//
//
//
// GENERAL functions XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

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

        boilerplate();

        puts("Conta com status 'ADMINISTRADORA'\n");

        // Check if we have already entered the menu
        // If so, we must clear te buffer, otherwise the next fgets will get conflicted
        // If we haven´t already entered the menu, that can only mean this is the first tine
        // The program is being executed, getchar is not necessary in this case
        if (increment_signup_admin != 0)
        {
            getchar();
        }

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

        boilerplate();

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

// Function to signup a LIMITED account
void signup_limited()
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

        boilerplate();

        puts("Conta com status 'LIMITADA'\n");

        getchar();

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

        boilerplate();

        puts("Conta com status 'LIMITADA'\n");

        // Start asking for user input
        printf("Nome de usuario (Entre 5 e 10 caracteres): %s", storage.username);
        puts("\n\n*****A senha não aparecerá enquanto a digitação ocorrer*****");

        // Turn off terminal echoing to mask password
        // TODO: REDO THIS FUNCTIONS FOR WINDOWS
        storage.password = strdup(getpass("Senha (Entre 5 e 10 caracteres): "));

    } while (check_password(storage.password, confirmation) == false);

    // Call save_acount_admin function
    save_account_limited(storage);

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
    fprintf(data, "%s", encrypt(account.username));

    // Print a line break in beetween
    // This must be done because we removed the \n at the last position of the account.username[] array
    fprintf(data, "\n");

    fprintf(data, "%s\n", encrypt(account.password));
    fprintf(data, "admin\n");

    fclose(data);
}

// Function that will save a new account when all the validations passes
void save_account_limited(createaccount account)
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
    fprintf(data, "limited\n");

    fclose(data);
}

// Function that will render a functionality menu with ADMIN capabilities
void menu_admin()
{

    increment_signup_admin++;

    boilerplate();

    puts("Conta com status 'ADMINISTRADORA'\n\n");

    // Available tools
    puts("1 - Cadastrar item");
    puts("2 - Vizualizar item\n");

    puts("3 - Excluir item");
    puts("4 - Editar item\n");

    puts("5 - Cadastrar conta");
    puts("6 - Excluir conta\n");

    puts("7 - Relatórios");
    puts("8 - Manual\n");

    puts("e - Sair\n");

    // Call answer_admin function
    answer_admin();
}

// Function that will receive user answer and will route another function
void answer_admin()
{

    // Declare a multipurpose storage variable
    char answer;

    printf("\nFerramenta escolhida (Insira o numero): ");

    // Get user input
    scanf("%c", &answer);

    // Route depending on user input
    // tolower() function is invoked so the program works if user input is capslock
    switch (tolower((char)answer))
    {
    case '1':
        menu_register_item();
    case '2':
        menu_show_items();
    case '3':
        menu_remove_item();
    case '4':
        menu_edit_item();
    case '5':
        menu_signup_account();
    case '6':
        remove_account_menu_and_answer();
    case '7':
        report();
    case '8':
        menu_manual_admin();
        break;
    case 'e':
        getchar();
        press_to_continue();
        exit(0);
    default:
        puts("Opção inválida!");
        press_to_continue();
        menu_admin();
    }
}

// Function to print the options presents at "1 - Register Item"
void menu_register_item()
{
    boilerplate();

    // Available tools
    puts("1 - Cadastar PRODUTO\n");
    puts("2 - Cadastrar FORNECEDOR\n");
    puts("3 - Cadastrar FUNCIONÁRIO\n");

    puts("e - Voltar");

    // Call answer_register_item function
    answer_register_item();
}

// Function that will receive user answer and will route another function
// tolower() function is invoked so the program works if user input is capslock
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
    switch (tolower((char)storage))
    {
    case '1':
        signup_product();
        menu_register_item();
    case '2':
        signup_dealer();
        menu_register_item();
    case '3':
        signup_employee();
        menu_register_item();
    case 'e':
        increment_answer_register_item = 0;
        getchar();
        menu_admin();
        break;
    default:
        puts("Opção inválida!");
        press_to_continue();
        menu_register_item();
    }
}

// Function to display the options inside "remove item" tool
void menu_remove_item()
{

    boilerplate();

    // Boilerplate
    puts("1 - Remover PRODUTO\n");
    puts("2 - Remover FORNECEDOR\n");
    puts("3 - Remover FUNCIONÁRIO\n");

    puts("e - Voltar");

    // Call answer_remove_item function
    answer_remove_item();
}

// Function that will receive user answer and will route another function
void answer_remove_item()
{

    if (increment_answer_remove_item == 0)
    {
        getchar();
    }

    increment_answer_remove_item++;

    // Declare a multipurpose storage variable
    char storage;

    printf("\nFerramenta escolhida (Insira o numero): ");

    // Get user input
    scanf("%c", &storage);

    // Route depending on user input
    switch (tolower((char)storage))
    {
    case '1':
        remove_product();
        break;
    case '2':
        remove_dealer();
        break;
    case '3':
        remove_employee();
        break;
    case 'e':
        increment_answer_remove_item = 0;
        getchar();
        menu_admin();
        break;
    default:
        puts("Opção inválida!");
        press_to_continue();
        menu_remove_item();
        break;
    }
}

// Function to display the options inside "edit item" tool
void menu_edit_item()
{

    boilerplate();

    // boilerplate
    puts("1 - Editar PRODUTO\n");
    puts("2 - Editar FORNECEDOR\n");
    puts("3 - Editar FUNCIONÁRIO\n");

    puts("e - Voltar");

    // Call answer_edit_item function
    answer_edit_item();
}

// Function that will receive user answer and will route another function
void answer_edit_item()
{

    if (increment_answer_edit_item == 0)
    {
        getchar();
    }

    increment_answer_edit_item++;

    // Declare a multipurpose storage variable
    char storage;

    printf("\nFerramenta escolhida (Insira o numero): ");

    // Get user input
    scanf("%c", &storage);

    // Route depending on user input
    switch (tolower((char)storage))
    {
    case '1':
        edit_product();
        break;
    case '2':
        edit_dealer();
        break;
    case '3':
        edit_employee();
        break;
    case 'e':
        increment_answer_edit_item = 0;
        getchar();
        menu_admin();
        break;
    default:
        puts("Opção inválida!");
        press_to_continue();
        menu_edit_item();
        break;
    }
}

// Function to display the options inside "Create account" tool
void menu_signup_account()
{

    boilerplate();

    // boilerplate
    puts("1 - Criar conta ADMINISTRADORA\n");
    puts("2 - Criar conta LIMITADA\n");
    puts("3 - Saiba Mais\n");

    puts("e - Voltar");

    // Call answer_signup_account function
    answer_signup_account();
}

// Function that will receive user answer and will route to another function
void answer_signup_account()
{

    if (increment_answer_signup_account == 0)
    {
        getchar();
    }

    increment_answer_signup_account++;

    // Declare a multipurpose storage variable
    char storage;

    printf("\nFerramenta escolhida (Insira o numero): ");

    // Get user input
    scanf("%c", &storage);

    // Route depending on user input
    switch (tolower((char)storage))
    {
    case '1':
        signup_admin();
        boilerplate();
        puts("Conta criada com sucesso!");
        press_to_continue();
        menu_signup_account();
        break;
    case '2':
        signup_limited();
        boilerplate();
        puts("Conta criada com sucesso!");
        press_to_continue();
        menu_signup_account();
        break;
    case '3':
        tutorial_accounts();
        getchar();
        press_to_continue();
        menu_signup_account();
        break;
    case 'e':
        increment_answer_signup_account = 0;
        getchar();
        menu_admin();
        break;
    default:
        puts("Opção inválida!");
        press_to_continue();
        menu_signup_account();
        break;
    }
}

// Function that makes it so it is possible to remove an account
void remove_account_menu_and_answer()
{

    boilerplate();

    puts("Para que seja possível remover uma conta");
    puts("será necessário inserir seu nome de usuário.\n");
    puts("Uma vez que uma conta é excluida com sucesso");
    puts("não será possível recuperar a mesma.\n");
    puts("Não é possível exlcluir a conta");
    puts("que esta sendo utilizada no momento!\n");

    puts("1 - Continuar\n");
    puts("e - Voltar");

    // Declare a multipurpose storage variable
    char storage;

    printf("\nFerramenta escolhida (Insira o numero): ");

    if (increment_remove_account == 0)
    {
        getchar();
    }

    increment_remove_account++;

    // Get user input
    scanf("%c", &storage);

    // Route depending on user input
    switch (tolower((char)storage))
    {
    case '1':
        char answer[MAXMAXSIZE];

        // Declare an increment variable
        int increment = 0;

        // Declare a decrement variable
        int decrement = 4;

        // Ask for user input
        // Check if user is trying to remove the currently loged account
        // Ask for user input while check_if_current_account func is returning false
        do
        {
            do
            {
                boilerplate();
                printf("%i tentativas restantes.\n", decrement);
                increment++;
                decrement--;
                printf("Nome de usuário da conta: ");

                // Get trailing newline "\n" in the buffer if this is the first iteration of this loop
                if (increment == 1)
                {
                    getchar();
                }
                fgets(answer, MAXMAXSIZE, stdin);

                // CHeck if user is trying again and again without success
                if (increment == 4)
                {
                    increment_remove_account = 0;
                    boilerplate();
                    puts("\nLimite de tentativas atingido!");
                    puts("tente novamente mais tarde!\n");
                    press_to_continue();
                    menu_admin();
                }

                // Call remove account function
                // This function needs to be located at the functions_general file
                // Because it is where the table_account is located
            } while (!check_if_current_account(answer));
        } while (!remove_account(answer));

        boilerplate();

        puts("Conta excluida com sucesso!");
        press_to_continue();

        menu_admin();
    case 'e':
        increment_remove_account = 0;
        getchar();
        menu_admin();
    default:
        puts("Opção inválida!");
        press_to_continue();
        remove_account_menu_and_answer();
    }
}

//
//
//
//
// EMPLOYEE functions XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// Function to create a new employee
void signup_employee()
{

    // Initialize a storage struct of type "createemployee"
    createemployee storage;

    // Alloc a big chunk of memory to "name" | The size will that of "MAXMAXSIZE" constant
    storage.name = (char *)malloc(MAXMAXSIZE);
    if (storage.name == NULL)
    {
        puts("ERRO 1: Não há memória suficiente no sistema");
        return;
    }

    // Alloc a big chunk of memory to "role" | The size will that of "MAXMAXSIZE" constant
    storage.role = (char *)malloc(MAXMAXSIZE);
    if (storage.role == NULL)
    {
        puts("ERRO 1: Não há memória suficiente no sistema");
        return;
    }

    // Alloc a big chunk of memory to "role" | The size will that of "MAXMAXSIZE" constant
    storage.admission = (char *)malloc(MAXMAXSIZE);
    if (storage.admission == NULL)
    {
        puts("ERRO 1: Não há memória suficiente no sistema");
        return;
    }

    // -------------------------------------------------

    // Clear terminal screen
    clear();

    // Boilerplate
    puts("\t\t\t<<<<< SLS 1.0 >>>>>\n");

    // Star asking for user input
    printf("Nome do funcionario: ");
    getchar();
    fgets(storage.name, MAXMAXSIZE, stdin);

    // Remove trailing newline that comes together with user input when fgets() is used
    storage.name[strcspn(storage.name, "\n")] = 0;

    // -------------------------------------------------

    // Clear terminal screen
    clear();

    // Boilerplate
    puts("\t\t\t<<<<< SLS 1.0 >>>>>\n");

    // Start asking for user input
    printf("Nome do funcionario: %s\n", storage.name);

    printf("Cargo do funcionario: ");
    fgets(storage.role, MAXMAXSIZE, stdin);

    // Remove trailing newline that comes together with user input when fgets() is used
    storage.role[strcspn(storage.role, "\n")] = 0;

    // -------------------------------------------------

    // Clear terminal screen
    clear();

    // Boilerplate
    puts("\t\t\t<<<<< SLS 1.0 >>>>>\n");

    // Star asking for user input
    printf("Nome do funcionario: %s\n", storage.name);
    printf("Cargo do funcionario: %s\n", storage.role);

    printf("Salario do funcionario: ");
    scanf("%f", &storage.salary);

    // Use a getchar here to get the trailing newline (\n) character scanf leave behind
    getchar();

    // -------------------------------------------------

    // Clear terminal screen
    clear();

    // Boilerplate
    puts("\t\t\t<<<<< SLS 1.0 >>>>>\n");

    // star asking fot user input
    printf("Nome do funcionário: %s\n", storage.name);
    printf("Cargo do funcionário: %s\n", storage.role);
    printf("Salario do funcionario: %.2f\n", storage.salary);

    printf("Data de admissao (ex.: 01/01/22): ");
    fgets(storage.admission, MAXSIZE, stdin);

    // Remove trailing newline that comes together with user input when fgets() is used
    storage.admission[strcspn(storage.admission, "\n")] = 0;

    // -------------------------------------------------

    // Call save_employee function
    save_employee(storage);

    // Free all allocated memory
    free(storage.name);
    free(storage.role);
    free(storage.admission);

    // -------------------------------------------------

    // Clear terminal screen
    clear();

    // Boilerplate
    puts("\t\t\t<<<<< SLS 1.0 >>>>>\n");

    puts("Funcionário salvo com sucesso!");

    press_to_continue();
}

// Function that will save a new employee
void save_employee(createemployee employee)
{

    // Declare e FILE Pointer
    FILE *data;

    // Open the correct file
    data = fopen("macros/employee.txt", "a");

    // Append all user input to file
    fprintf(data, "%s", employee.name);

    // Print a line break in beetween
    // This must be done because we removed the \n at the last position of the employee.name[] array
    fprintf(data, "\n");

    fprintf(data, "%s", employee.role);

    // Print a line break in beetween || For the same reason as previously
    fprintf(data, "\n");

    fprintf(data, "%.2f", employee.salary);

    // Print a line break in beetween || For the same reason as previously
    fprintf(data, "\n");

    fprintf(data, "%s", employee.admission);

    // Print a line break in beetween || For the same reason as previously
    fprintf(data, "\n");

    fclose(data);
}

// Function that will show all content present at employee databases
void show_employee_database_all()
{

    // Declare variable that will increment
    int increment = 0;

    // Declare a storage variable
    char storage;

    // Load all employee databases
    load_employee_databases();

    boilerplate();

    puts("FUNCIONÁRIOS:\n");

    // loop that will go around the amount of time it is specified in the MIN and MAX TABLESIZE consts
    for (int i = 0; i < MINTABLESIZE; i++)
    {
        // Navigate horizontally a linked list
        for (employee *tmp = table_employee[i]; tmp != NULL; tmp = tmp->next)
        {
            increment++;
            printf("\n%i ---------------------------------------------------\n", increment);
            printf("Nome: %s\n", tmp->name);
            printf("Cargo: %s\n", tmp->role);
            printf("Salario: %s\n", tmp->salary);
            printf("Data de admissao: %s\n", tmp->admission);
            printf("\n");
        }
    }

    // Unload all employee databases
    unload_employee_databases();

    // Boilerplate
    puts("\t\t\t<<<<<<<<<< OPCÕES >>>>>>>>>>\n");

    puts("1 - Salvar no computador\n");
    puts("Qualquer tecla - Voltar\n");

    printf("\nFerramenta escolhida (Insira o numero): ");

    // Get user input
    scanf("%c", &storage);

    switch (tolower((char)storage))
    {
    case '1':
        /* Function to save on computer */
        break;
    default:
        getchar();
        press_to_continue();
        menu_show_items();
    }
}

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
    while (fgets(buffer, MAXMAXSIZE, data))
    {

        // Allocate new memory chunk to node at each iteration
        node = malloc(sizeof(employee));
        if (node == NULL)
        {
            puts("ERRO 1: Não há memória suficiente no sistema");
            return false;
        }

        // Copy the string present at that line of the file to the username section of the current node
        strcpy(node->name, buffer);

        // Scan string from another line of the file to the buffer once again | buffer content is overwritten at this moment
        fgets(buffer, MAXMAXSIZE, data);

        // Copy the string present at that line of the file to the username section of the current node
        strcpy(node->role, buffer);

        // Scan string from another line of the file to the buffer once again | buffer content is overwritten at this moment
        fgets(buffer, MAXMAXSIZE, data);

        // Copy the string present at that line of the file to the username section of the current node
        strcpy(node->salary, buffer);

        // Scan string from another line of the file to the buffer once again | buffer content is overwritten at this moment
        fgets(buffer, MAXMAXSIZE, data);

        // Copy the string present at that line of the file to the username section of the current node
        strcpy(node->admission, buffer);

        // Index variable receives the value returned by the hash(node->) func
        index = hash_index(node->name);

        // Check if table_employee[index] is pointer is pointing to NULL
        if (table_employee[index] == NULL)
        {
            // If so, current node "next" pointer must point to NULL
            node->next = NULL;

            // set current node "previous" pointer to NULL
            node->previous = NULL;

            // That array position of table_employee must point to the current node
            table_employee[index] = node;

            // Skip next lines of code a got to the next iteration
            continue;
        }

        // If previous "if condition" is not met

        // Set the struct at location table_employee[index] "previous" section to point to current node
        table_employee[index]->previous = node;

        // Current node "next" point must point to what table_account[index] is pointing to
        node->next = table_employee[index];

        // set current node "previous" pointer to NULL
        node->previous = NULL;

        // table_account must point to what the current node
        table_employee[index] = node;
    }

    // Close all opened files
    fclose(data);

    // Free all allocated memory
    free(buffer);

    return true;
}

// Unloads table_employee from memory, returning true if successful, else false
bool unload_employee_databases()
{

    // Create a pointer of to a struct of type employee that will serve as a cursor
    employee *cursor = NULL;

    // loop that will go around the amount of time it is specified in the MIN and MAX TABLESIZE consts
    for (int i = 0; i < MINTABLESIZE; i++)
    {
        // Navigate horizontally a linked list
        for (employee *tmp = table_employee[i]; tmp != NULL; tmp = cursor)
        {
            cursor = table_employee[i]->next;
            free(table_employee[i]);
            table_employee[i] = cursor;
        }
    }

    return true;
}

// Search function for employee databases
void show_employee_database_detailed()
{

    // Load all employee databases
    load_employee_databases();

    // Global incrementor that will make it so every trailing \n character at "stdin" is removed by getchar
    // Preventing weird behavior such as the switch func detecting and invalid input instantly
    if (increment_answer_general_debug_employee == 0)
    {
        getchar();
    }

    increment_answer_general_debug_employee++;

    // Declare variable that will increment
    int increment = 0;

    // Declare 2 storage variables
    char storage;
    char *answer = (char *)malloc(MAXMAXSIZE);
    if (answer == NULL)
    {
        puts("ERRO 1: Não há memória suficiente no sistema");
        exit(1);
    }

    boilerplate();

    puts("VIZUALIZAR FUNCIONÁRIOS:\n");

    puts("1 - Pesquisar por NOME\n");
    puts("2 - Pesquisar por CARGO\n");
    puts("3 - Pesquisar por SALÁRIO\n");
    puts("e - Voltar");

    printf("\nFerramenta escolhida (Insira o numero): ");

    // Get user input
    scanf("%c", &storage);

    switch (tolower((char)storage))
    {
    case '1':
        boilerplate();

        printf("Nome do funcionario: ");
        getchar();

        // Get user input
        fgets(answer, MAXMAXSIZE, stdin);

        boilerplate();
        puts("VIZUALIZAR FUNCIONÁRIOS:\n");

        // All possible positions at a table of MINTABLESIZE size
        for (int i = 0; i < MINTABLESIZE; i++)
        {

            // Navigate a linked list horizontally
            for (employee *tmp = table_employee[i]; tmp != NULL; tmp = tmp->next)
            {

                // For every match, print
                if (strcasecmp(answer, tmp->name) == 0)
                {
                    increment++;
                    printf("\n%i ---------------------------------------------------\n", increment);
                    printf("Nome: %s\n", tmp->name);
                    printf("Cargo: %s\n", tmp->role);
                    printf("Salario: %s\n", tmp->salary);
                    printf("Data de admissao: %s\n", tmp->admission);
                    printf("\n");
                }
            }
        }

        if (increment == 0)
        {
            puts("Nenhum item encontrado!");
            press_to_continue();
            show_employee_database_detailed();
        }

        break;
    case '2':
        boilerplate();

        printf("Cargo do funcionario: ");
        getchar();

        // Get user input
        fgets(answer, MAXMAXSIZE, stdin);
        // answer[strcspn(answer, "\n")] = 0;

        boilerplate();
        puts("VIZUALIZAR FUNCIONÁRIOS:\n");

        // All possible positions at a table of MINTABLESIZE size
        for (int i = 0; i < MINTABLESIZE; i++)
        {

            // Navigate a linked list horizontally
            for (employee *tmp = table_employee[i]; tmp != NULL; tmp = tmp->next)
            {

                // For every match, print
                if (strcasecmp(answer, tmp->role) == 0)
                {
                    increment++;
                    printf("\n%i ---------------------------------------------------\n", increment);
                    printf("Nome: %s\n", tmp->name);
                    printf("Cargo: %s\n", tmp->role);
                    printf("Salario: %s\n", tmp->salary);
                    printf("Data de admissao: %s\n", tmp->admission);
                    printf("\n");
                }
            }
        }

        if (increment == 0)
        {
            puts("Nenhum item encontrado!");
            press_to_continue();
            show_employee_database_detailed();
        }

        break;
    case '3':
        boilerplate();

        printf("Salario do funcionario: ");
        getchar();

        // Get user input
        fgets(answer, MAXMAXSIZE, stdin);

        boilerplate();
        puts("VIZUALIZAR FUNCIONÁRIOS:\n");

        // All possible positions at a table of MINTABLESIZE size
        for (int i = 0; i < MINTABLESIZE; i++)
        {

            // Navigate a linked list horizontally
            for (employee *tmp = table_employee[i]; tmp != NULL; tmp = tmp->next)
            {

                // For every match, print
                if (strcasecmp(answer, tmp->salary) == 0)
                {
                    increment++;
                    printf("\n%i ---------------------------------------------------\n", increment);
                    printf("Nome: %s\n", tmp->name);
                    printf("Cargo: %s\n", tmp->role);
                    printf("Salario: %s\n", tmp->salary);
                    printf("Data de admissao: %s\n", tmp->admission);
                    printf("\n");
                }
            }
        }

        if (increment == 0)
        {
            puts("Nenhum item encontrado!");
            press_to_continue();
            show_employee_database_detailed();
        }

        break;
    case 'e':
        unload_employee_databases();
        free(answer);
        increment_answer_general_debug_employee = 0;
        getchar();
        menu_show_items();
    default:
        puts("Opção inválida!");
        press_to_continue();
        show_employee_database_detailed();
    }

    unload_employee_databases();
    free(answer);

    // Boilerplate
    puts("\t\t\t<<<<<<<<<< OPCÕES >>>>>>>>>>\n");

    puts("1 - Salvar no computador\n");
    puts("Qualquer tecla - Voltar\n");

    printf("\nFerramenta escolhida (Insira o numero): ");

    // Get user input
    scanf("%c", &storage);

    switch (tolower((char)storage))
    {
    case '1':
        /* Function to save on computer */
        break;
    default:
        increment_answer_general_debug_employee = 0;
        press_to_continue();
        menu_show_items();
    }
}

// Remove function for employee databases
void remove_employee()
{

    // Load all employee databases
    load_employee_databases();

    // Replace the content of "employee.txt" with the current content of table_employee at all indexes
    // We must open the database and erase its contents by using the parameter "w" at fopen()
    FILE *data = fopen("macros/employee.txt", "w");

    // Close so it can be reopened with a append "a" mode
    fclose(data);

    data = fopen("macros/employee.txt", "a");

    // Make it so the file is line buffered, not block buffered
    // This makes it so we can write onto the file while the program is running
    // Otherwise, we woul have to wait until the program is closed
    setlinebuf(data);

    // Declare a storage struct of type "employee"
    employee storage;

    // Declare a variable that will increment
    int increment = 0;

    // Declare a storage variable
    char *answer = (char *)malloc(MAXMAXSIZE);
    if (answer == NULL)
    {
        puts("ERRO 1: Não há memória suficiente no sistema");
        exit(1);
    }

    boilerplate();

    printf("\nNome do funcionario: ");
    getchar();

    // Get user input
    fgets(answer, MAXMAXSIZE, stdin);

    // Loop that goes around MINTABLESIZE times
    for (int i = 0; i < MINTABLESIZE; i++)
    {

        // Navigate a linked list horizontally
        for (employee *tmp = table_employee[i]; tmp != NULL; tmp = tmp->next)
        {

            // Check if user input is present at database
            // Check if this is an intermediate position at the linked list
            if (strcasecmp(answer, tmp->name) == 0)
            {
                increment++;
                continue;
            }

            // Copy the string present at this position of tmp to the storage.(appropriate section)
            strcpy(storage.name, tmp->name);
            strcpy(storage.role, tmp->role);
            strcpy(storage.salary, tmp->salary);
            strcpy(storage.admission, tmp->admission);

            // Append the strings present at storage.(section) onto the file
            fprintf(data, "%s", storage.name);
            fprintf(data, "%s", storage.role);
            fprintf(data, "%s", storage.salary);
            fprintf(data, "%s", storage.admission);
        }
    }

    if (increment == 0)
    {
        boilerplate();
        puts("Nenhum item encontrado!");
        // free(answer);
        unload_employee_databases();
        press_to_continue();
        menu_remove_item();
    }

    // Close all opened files
    fclose(data);

    // Free all allocated memory
    free(answer);

    // Unload all loaded databases
    unload_employee_databases();

    boilerplate();

    puts("Funcionário excluído com sucesso!");
    press_to_continue();
    menu_remove_item();
}

// Edit function for employee databases
void edit_employee()
{

    // Load all employee databases
    load_employee_databases();

    // Replace the content of "employee.txt" with the current content of table_employee at all indexes
    // We must open the database and erase its contents by using the parameter "w" at fopen()
    FILE *data = fopen("macros/employee.txt", "w");

    // Close so it can be reopened with a append "a" mode
    fclose(data);

    data = fopen("macros/employee.txt", "a");

    // Make it so the file is line buffered, not block buffered
    // This makes it so we can write onto the file while the program is running
    // Otherwise, we woul have to wait until the program is closed
    setlinebuf(data);

    // Declare a storage struct of type "employee"
    employee storage;

    // Declare a variable that will increment
    int increment = 0;

    // Declare a storage variable
    char *answer = (char *)malloc(MAXMAXSIZE);
    if (answer == NULL)
    {
        puts("ERRO 1: Não há memória suficiente no sistema");
        exit(1);
    }

    boilerplate();

    printf("\nNome do funcionario: ");
    getchar();

    // Get user input
    fgets(answer, MAXMAXSIZE, stdin);

    // Loop that goes around MINTABLESIZE times
    for (int i = 0; i < MINTABLESIZE; i++)
    {

        // Navigate a linked list horizontally
        for (employee *tmp = table_employee[i]; tmp != NULL; tmp = tmp->next)
        {

            // Check if user input is present at database
            // Check if this is an intermediate position at the linked list
            if (strcasecmp(answer, tmp->name) == 0)
            {
                boilerplate();
                puts("Item encontrado. Insira as novas informações.\n");
                increment++;

                // Get user input
                printf("Nome: ");
                fgets(tmp->name, MAXMAXSIZE, stdin);

                printf("Cargo: ");
                fgets(tmp->role, MAXMAXSIZE, stdin);

                printf("Salario: ");
                fgets(tmp->salary, MAXSIZE, stdin);

                printf("Data de admissao: ");
                fgets(tmp->admission, MAXSIZE, stdin);
            }

            // Copy the string present at this position of tmp to the storage.(appropriate section)
            strcpy(storage.name, tmp->name);
            strcpy(storage.role, tmp->role);
            strcpy(storage.salary, tmp->salary);
            strcpy(storage.admission, tmp->admission);

            // Append the strings present at storage.(section) onto the file
            fprintf(data, "%s", storage.name);
            fprintf(data, "%s", storage.role);
            fprintf(data, "%s", storage.salary);
            fprintf(data, "%s", storage.admission);
        }
    }

    if (increment == 0)
    {
        boilerplate();
        puts("Nenhum item encontrado!");
        unload_employee_databases();
        press_to_continue();
        menu_edit_item();
    }

    // Close all opened files
    fclose(data);

    // Free all allocated memory
    free(answer);

    // Unload all loaded databases
    unload_employee_databases();

    boilerplate();

    puts("Funcionário editado com sucesso!");
    press_to_continue();
    menu_edit_item();
}

//
//
//
//
// PRODUCT functions XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// Function to create a new product
void signup_product()
{

    // Initialize a storage struct of type "createproduct"
    createproduct storage;

    // Alloc a big chunck of memory to "name"
    // The size will be that of "MAXMAXSIZE" constant
    storage.name = (char *)malloc(MAXMAXSIZE);
    if (storage.name == NULL)
    {
        puts("ERRO 1: Não há memória suficiente no sistema");
        return;
    }

    // -------------------------------------------------

    // Clear terminal screen
    clear();

    // Boilerplate
    puts("\t\t\t<<<<< SLS 1.0 >>>>>\n");

    // Start asking for user input
    printf("Nome do produto: ");
    getchar();
    fgets(storage.name, MAXMAXSIZE, stdin);

    // Remove trailing newline that comes together with user input when fgets() is used
    storage.name[strcspn(storage.name, "\n")] = 0;

    // -------------------------------------------------

    // Clear terminal screen
    clear();

    // Boilerplate
    puts("\t\t\t<<<<< SLS 1.0 >>>>>\n");

    // Start asking for user input
    printf("Nome do produto: %s\n", storage.name);

    printf("Quantidade do produto (Número inteiro): ");
    scanf("%i", &storage.quantity);

    // Use a getchar here to get the trailing newline (\n) character scanf leave behind
    getchar();

    // -------------------------------------------------

    // Clear terminal screen
    clear();

    // Boilerplate
    puts("\t\t\t<<<<< SLS 1.0 >>>>>\n");

    // Start asking for user input
    printf("Nome do produto: %s\n", storage.name);
    printf("Quantidade do produto (Número inteiro): %i\n", storage.quantity);

    printf("Valor por unidade metrica: ");
    scanf("%f", &storage.unitary_value);

    // Use a getchar here to get the trailing newline (\n) character scanf leave behind
    getchar();

    // -------------------------------------------------

    // Call save_product function
    save_product(storage);

    // Free all allocated memory
    free(storage.name);

    // -------------------------------------------------

    // Clear terminal screen
    clear();

    // Boilerplate
    puts("\t\t\t<<<<< SLS 1.0 >>>>>\n");

    puts("Produto salvo com sucesso!");

    press_to_continue();
}

// Function that will save a new product
void save_product(createproduct product)
{

    // Declare a FILE Pointer
    FILE *data;

    // Open the correct file
    data = fopen("macros/product.txt", "a");

    // Append all user input to file
    fprintf(data, "%s", product.name);

    // Print a line break in beetween
    // This must be done because we removed the \n at the last position of the product.name[] array
    fprintf(data, "\n");

    fprintf(data, "%i", product.quantity);

    // Print a line break in beetween || For the same reason as previously
    fprintf(data, "\n");

    fprintf(data, "%.2f", product.unitary_value);

    // Print a line break in beetween || For the same reason as previously
    fprintf(data, "\n");

    fprintf(data, "%.2f", product.quantity * product.unitary_value);

    // Print a line break in beetween || For the same reason as previously
    fprintf(data, "\n");

    fclose(data);
}

// FUnction that will show all content at product databases
void show_product_database_all()
{

    // Declare variable that will increment
    int increment = 0;

    // Declare a storage variable
    char storage;

    // Load all product databases
    load_product_databases();

    // Clear terminal screen
    clear();

    // Boiler plate
    puts("\t\t\t<<<<< SLS 1.0 >>>>>\n");
    puts("PRODUTOS:\n");

    // loop that will go around the amount of time it is specified in the MIN and MAX TABLESIZE consts
    for (int i = 0; i < MINTABLESIZE; i++)
    {
        // Navigate horizontally a linked list
        for (product *tmp = table_product[i]; tmp != NULL; tmp = tmp->next)
        {
            increment++;
            printf("\n%i ---------------------------------------------------\n", increment);
            printf("Nome: %s\n", tmp->name);
            printf("Quantidade: %s\n", tmp->quantity);
            printf("Valor por unidade de medida: %s\n", tmp->unitary_value);
            printf("Valor total: %s\n", tmp->total_value);
            printf("\n");
        }
    }

    // Unload all employee databases
    unload_product_databases();

    // Boilerplate
    puts("\t\t\t<<<<<<<<<< OPCÕES >>>>>>>>>>\n");

    puts("1 - Salvar no computador\n");
    puts("Qualquer tecla - Voltar\n");

    printf("\nFerramenta escolhida (Insira o numero): ");

    // Get user input
    scanf("%c", &storage);

    switch (tolower((char)storage))
    {
    case '1':
        /* Function to save on computer */
        break;
    default:
        getchar();
        press_to_continue();
        menu_show_items();
    }
}

// Function that will load all databases hashtables of products
bool load_product_databases()
{
    // Create a buffer
    char *buffer = (char *)malloc(MAXMAXSIZE);
    if (buffer == NULL)
    {
        puts("ERRO 1: Não há memória o suficiente no sistema");
        return false;
    }

    // Declare variable that will receive hashed indexes
    int index;

    // Declare a struct o "product" type
    // Initialize it to NULL
    product *node = NULL;

    // Load "product" databases ->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->

    // Open "product.txt" file
    FILE *data = fopen("macros/product.txt", "r");
    if (data == NULL)
    {
        puts("ERRO 2: Não foi possível abrir o arquivo necessário");
        return false;
    }

    // Load "product" databases ->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->

    // Write each string inside the file onto the buffer | buffer content is overwritten at this moment
    while (fgets(buffer, MAXMAXSIZE, data))
    {
        // Allocate new memory chunck to node at each iteration
        node = malloc(sizeof(product));
        if (node == NULL)
        {
            puts("ERRO 1: Não há memória suficiente no sistema");
            return false;
        }

        // Copy the string present at that line of the file to the username section of the current node
        strcpy(node->name, buffer);

        // Scan string from another line of the file to the buffer once again | buffer content is overwritten at this moment
        fgets(buffer, MAXMAXSIZE, data);

        // Copy the string present at that line of the file to the username section of the current node
        strcpy(node->quantity, buffer);

        // Scan string from another line of the file to the buffer once again | buffer content is overwritten at this moment
        fgets(buffer, MAXMAXSIZE, data);

        // Copy the string present at that line of the file to the username section of the current node
        strcpy(node->unitary_value, buffer);

        // Scan string from another line of the file to the buffer once again | buffer content is overwritten at this moment
        fgets(buffer, MAXMAXSIZE, data);

        // Copy the string present at that line of the file to the username section of the current node
        strcpy(node->total_value, buffer);

        // Index variable receives the value returned by the hash(node->) func
        index = hash_index(node->name);

        // Check if table_product[index] pointer is pointing to NULL
        if (table_product[index] == NULL)
        {

            // If so, current node "next" pointer must point to NULL
            node->next = NULL;

            // Set current node "previous" pointer to NULL
            node->previous = NULL;

            // THat array position of table_product must point to the current node
            table_product[index] = node;

            // Skip next lines of code and go to the next iteration
            continue;
        }

        // If previous "if condition" is not met

        // Set the struct at location table_product[index] "previous" section to point to current node
        table_product[index]->previous = node;

        // Current node "next" point must point to what table_product[index] is pointing to
        node->next = table_product[index];

        // Set current node "previous" pointer to NULL
        node->previous = NULL;

        // table_product must point to the current node
        table_product[index] = node;
    }

    // Close all opened files
    fclose(data);

    // Free all allocated memory
    free(buffer);

    return true;
}

// Unloads table_product from memory, returning true if successful, else false
bool unload_product_databases()
{

    // Create a pointer to a struct o type product that will serve as a cursor
    product *cursor = NULL;

    // Loop that will go around the amount of times it is specified in the MINTABLESIZE const
    for (int i = 0; i < MINTABLESIZE; i++)
    {

        // Navigate horizontally a linked list
        for (product *tmp = table_product[i]; tmp != NULL; tmp = cursor)
        {
            cursor = table_product[i]->next;
            free(table_product[i]);
            table_product[i] = cursor;
        }
    }

    return true;
}

// Search function for product databases
void show_product_database_detailed()
{
    // Load all employee databases
    load_product_databases();

    // Global incrementor that will make it so every trailing \n character at "stdin" is removed by getchar
    // Preventing weird behavior such as the switch func detecting and invalid input instantly
    if (increment_answer_general_debug_product == 0)
    {
        getchar();
    }

    increment_answer_general_debug_product++;

    // Declare variable that will increment
    int increment = 0;

    // Declare 2 storage variables
    char storage;
    char *answer = (char *)malloc(MAXMAXSIZE);
    if (answer == NULL)
    {
        puts("ERRO 1: Não há memória suficiente no sistema");
        exit(1);
    }

    boilerplate();

    puts("VIZUALIZAR PRODUTOS:\n");

    puts("1 - Pesquisar por NOME\n");
    puts("2 - Pesquisar por QUANTIDADE\n");
    puts("3 - Pesquisar por VALOR UNITÁRIO\n");
    puts("4 - Pesquisar por VALOR TOTAL\n");
    puts("e - Voltar");

    printf("\nFerramenta escolhida (Insira o numero): ");

    // Get user input
    scanf("%c", &storage);

    switch (tolower((char)storage))
    {
    case '1':
        boilerplate();

        printf("Nome do produto: ");
        getchar();

        // Get user input
        fgets(answer, MAXMAXSIZE, stdin);

        boilerplate();
        puts("VIZUALIZAR PRODUTOS:\n");

        // All possible positions at a table of MINTABLESIZE size
        for (int i = 0; i < MINTABLESIZE; i++)
        {

            // Navigate a linked list horizontally
            for (product *tmp = table_product[i]; tmp != NULL; tmp = tmp->next)
            {

                // For every match, print
                if (strcasecmp(answer, tmp->name) == 0)
                {
                    increment++;
                    printf("\n%i ---------------------------------------------------\n", increment);
                    printf("Nome: %s\n", tmp->name);
                    printf("Quantidade: %s\n", tmp->quantity);
                    printf("Valor por unidade de medida: %s\n", tmp->unitary_value);
                    printf("Valor total: %s\n", tmp->total_value);
                    printf("\n");
                }
            }
        }

        if (increment == 0)
        {
            puts("Nenhum item encontrado!");
            press_to_continue();
            show_product_database_detailed();
        }

        break;
    case '2':
        boilerplate();

        printf("Quantidade do produto: ");
        getchar();

        // Get user input
        fgets(answer, MAXMAXSIZE, stdin);
        // answer[strcspn(answer, "\n")] = 0;

        boilerplate();
        puts("VIZUALIZAR PRODUTOS:\n");

        // All possible positions at a table of MINTABLESIZE size
        for (int i = 0; i < MINTABLESIZE; i++)
        {

            // Navigate a linked list horizontally
            for (product *tmp = table_product[i]; tmp != NULL; tmp = tmp->next)
            {

                // For every match, print
                if (strcasecmp(answer, tmp->quantity) == 0)
                {
                    increment++;
                    printf("\n%i ---------------------------------------------------\n", increment);
                    printf("Nome: %s\n", tmp->name);
                    printf("Quantidade: %s\n", tmp->quantity);
                    printf("Valor por unidade de medida: %s\n", tmp->unitary_value);
                    printf("Valor total: %s\n", tmp->total_value);
                    printf("\n");
                }
            }
        }

        if (increment == 0)
        {
            puts("Nenhum item encontrado!");
            press_to_continue();
            show_product_database_detailed();
        }

        break;
    case '3':
        boilerplate();

        printf("Valor Unitario do produto: ");
        getchar();

        // Get user input
        fgets(answer, MAXMAXSIZE, stdin);

        boilerplate();
        puts("VIZUALIZAR PRODUTOS:\n");

        // All possible positions at a table of MINTABLESIZE size
        for (int i = 0; i < MINTABLESIZE; i++)
        {

            // Navigate a linked list horizontally
            for (product *tmp = table_product[i]; tmp != NULL; tmp = tmp->next)
            {

                // For every match, print
                if (strcasecmp(answer, tmp->unitary_value) == 0)
                {
                    increment++;
                    printf("\n%i ---------------------------------------------------\n", increment);
                    printf("Nome: %s\n", tmp->name);
                    printf("Quantidade: %s\n", tmp->quantity);
                    printf("Valor por unidade de medida: %s\n", tmp->unitary_value);
                    printf("Valor total: %s\n", tmp->total_value);
                    printf("\n");
                }
            }
        }

        if (increment == 0)
        {
            puts("Nenhum item encontrado!");
            press_to_continue();
            show_product_database_detailed();
        }

        break;
    case '4':
        boilerplate();

        printf("Valor Total do produto: ");
        getchar();

        // Get user input
        fgets(answer, MAXMAXSIZE, stdin);

        boilerplate();
        puts("VIZUALIZAR PRODUTOS:\n");

        // All possible positions at a table of MINTABLESIZE size
        for (int i = 0; i < MINTABLESIZE; i++)
        {

            // Navigate a linked list horizontally
            for (product *tmp = table_product[i]; tmp != NULL; tmp = tmp->next)
            {

                // For every match, print
                if (strcasecmp(answer, tmp->total_value) == 0)
                {
                    increment++;
                    printf("\n%i ---------------------------------------------------\n", increment);
                    printf("Nome: %s\n", tmp->name);
                    printf("Quantidade: %s\n", tmp->quantity);
                    printf("Valor por unidade de medida: %s\n", tmp->unitary_value);
                    printf("Valor total: %s\n", tmp->total_value);
                    printf("\n");
                }
            }
        }

        if (increment == 0)
        {
            puts("Nenhum item encontrado!");
            press_to_continue();
            show_product_database_detailed();
        }

        break;
    case 'e':
        unload_product_databases();
        free(answer);
        increment_answer_general_debug_product = 0;
        getchar();
        menu_show_items();
    default:
        puts("Opção inválida!");
        press_to_continue();
        show_product_database_detailed();
    }

    unload_product_databases();
    free(answer);

    // Boilerplate
    puts("\t\t\t<<<<<<<<<< OPCÕES >>>>>>>>>>\n");

    puts("1 - Salvar no computador\n");
    puts("Qualquer tecla - Voltar\n");

    printf("\nFerramenta escolhida (Insira o numero): ");

    // Get user input
    scanf("%c", &storage);

    switch (tolower((char)storage))
    {
    case '1':
        /* Function to save on computer */
        break;
    default:
        increment_answer_general_debug_product = 0;
        press_to_continue();
        menu_show_items();
    }
}

// Remove function for product databases
void remove_product()
{

    // Load all product databases
    load_product_databases();

    // Replace the content of "product.txt" with the current content of table_product at all indexes
    // We must open the database and erase its contents by using the parameter "w" at fopen()
    FILE *data = fopen("macros/product.txt", "w");

    // Close so it can be reopened with a append "a" mode
    fclose(data);

    data = fopen("macros/product.txt", "a");

    // Make it so the file is line buffered, not block buffered
    // This makes it so we can write onto the file while the program is running
    // Otherwise, we woul have to wait until the program is closed
    setlinebuf(data);

    // Declare two cursors
    product storage;

    // Declare a variable that will increment
    int increment = 0;

    // declare a storage variable
    char *answer = (char *)malloc(MAXMAXSIZE);
    if (answer == NULL)
    {
        puts("ERRO 1: Não há memória suficiente no sistema");
        exit(1);
    }

    boilerplate();

    printf("\nNome do produto: ");
    getchar();

    // Get user input
    fgets(answer, MAXMAXSIZE, stdin);

    // Loop that goes around MINTABLESIZE times
    for (int i = 0; i < MINTABLESIZE; i++)
    {

        // Navigate a linked list horizontally
        for (product *tmp = table_product[i]; tmp != NULL; tmp = tmp->next)
        {

            // Check if user input is present at database
            // Check if this is an intermediate position at the linked list
            if (strcasecmp(answer, tmp->name) == 0)
            {
                increment++;
                continue;
            }

            // Copy the string present at this position of tmp to the storage.(appropriate section)
            strcpy(storage.name, tmp->name);
            strcpy(storage.quantity, tmp->quantity);
            strcpy(storage.unitary_value, tmp->unitary_value);
            strcpy(storage.total_value, tmp->total_value);

            // Append the strings present at storage.(section) onto the file
            fprintf(data, "%s", storage.name);
            fprintf(data, "%s", storage.quantity);
            fprintf(data, "%s", storage.unitary_value);
            fprintf(data, "%s", storage.total_value);
        }
    }

    if (increment == 0)
    {
        boilerplate();
        puts("Nenhum item encontrado!");
        // free(answer);
        unload_product_databases();
        press_to_continue();
        menu_remove_item();
    }

    // Close all opened files
    fclose(data);

    // Free all allocated memory
    free(answer);

    // Onload all loaded databases
    unload_product_databases();

    boilerplate();

    puts("Produto excluído com sucesso!");
    press_to_continue();
    menu_remove_item();
}

// Edit function for product databases
void edit_product()
{

    // Load all product databases
    load_product_databases();

    // Replace the content of "product.txt" with the current content of table_product at all indexes
    // We must open the database and erase its contents by using the parameter "w" at fopen()
    FILE *data = fopen("macros/product.txt", "w");

    // Close so it can be reopened with a append "a" mode
    fclose(data);

    data = fopen("macros/product.txt", "a");

    // Make it so the file is line buffered, not block buffered
    // This makes it so we can write onto the file while the program is running
    // Otherwise, we woul have to wait until the program is closed
    setlinebuf(data);

    // Declare a storage struct of type "product"
    product storage;

    // Declare a variable that will increment
    int increment = 0;

    // Declare a storage variable
    char *answer = (char *)malloc(MAXMAXSIZE);
    if (answer == NULL)
    {
        puts("ERRO 1: Não há memória suficiente no sistema");
        exit(1);
    }

    boilerplate();

    printf("\nNome do produto: ");
    getchar();

    // Get user input
    fgets(answer, MAXMAXSIZE, stdin);

    // Loop that goes around MINTABLESIZE times
    for (int i = 0; i < MINTABLESIZE; i++)
    {

        // Navigate a linked list horizontally
        for (product *tmp = table_product[i]; tmp != NULL; tmp = tmp->next)
        {

            // Check if user input is present at database
            // Check if this is an intermediate position at the linked list
            if (strcasecmp(answer, tmp->name) == 0)
            {
                boilerplate();
                puts("Item encontrado. Insira as novas informações.\n");
                increment++;

                // Get user input
                printf("Nome: ");
                fgets(tmp->name, MAXMAXSIZE, stdin);

                printf("Quantidade: ");
                fgets(tmp->quantity, MAXSIZE, stdin);

                printf("Valor Unitario: ");
                fgets(tmp->unitary_value, MAXMAXSIZE, stdin);

                printf("Valor Total: ");
                fgets(tmp->total_value, MAXMAXSIZE, stdin);
            }

            // Copy the string present at this position of tmp to the storage.(appropriate section)
            strcpy(storage.name, tmp->name);
            strcpy(storage.quantity, tmp->quantity);
            strcpy(storage.unitary_value, tmp->unitary_value);
            strcpy(storage.total_value, tmp->total_value);

            // Append the strings present at storage.(section) onto the file
            fprintf(data, "%s", storage.name);
            fprintf(data, "%s", storage.quantity);
            fprintf(data, "%s", storage.unitary_value);
            fprintf(data, "%s", storage.total_value);
        }
    }

    if (increment == 0)
    {
        boilerplate();
        puts("Nenhum item encontrado!");
        unload_product_databases();
        press_to_continue();
        menu_edit_item();
    }

    // Close all opened files
    fclose(data);

    // Free all allocated memory
    free(answer);

    // Unload all loaded databases
    unload_product_databases();

    boilerplate();

    puts("Produto editado com sucesso!");
    press_to_continue();
    menu_edit_item();
}

//
//
//
//
// DEALER functions XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// Function to create a new dealer
void signup_dealer()
{

    // Initialize a storage struct of type "createdealer"
    createdealer storage;

    // Allocate all needed memory

    storage.name = (char *)malloc(MAXMAXSIZE);
    if (storage.name == NULL)
    {
        puts("ERRO 1: Não há memória o suficiente no sistema");
        return;
    }

    storage.owner_name = (char *)malloc(MAXMAXSIZE);
    if (storage.owner_name == NULL)
    {
        puts("ERRO 1: Não há memória o suficiente no sistema");
        return;
    }

    storage.city = (char *)malloc(MAXMAXSIZE);
    if (storage.city == NULL)
    {
        puts("ERRO 1: Não há memória o suficiente no sistema");
        return;
    }

    storage.service_type = (char *)malloc(MAXMAXSIZE);
    if (storage.service_type == NULL)
    {
        puts("ERRO 1: Não há memória o suficiente no sistema");
        return;
    }

    storage.contact = (char *)malloc(MAXMAXSIZE);
    if (storage.contact == NULL)
    {
        puts("ERRO 1: Não há memória o suficiente no sistema");
        return;
    }

    storage.email = (char *)malloc(MAXMAXSIZE);
    if (storage.email == NULL)
    {
        puts("ERRO 1: Não há memória o suficiente no sistema");
        return;
    }

    // -------------------------------------------------

    boilerplate();

    // Start asking for user input
    printf("Nome da empresa: ");
    getchar();
    fgets(storage.name, MAXMAXSIZE, stdin);

    // Remove trailing newline that comes together with user input when fgets() is used
    storage.name[strcspn(storage.name, "\n")] = 0;

    // -------------------------------------------------

    boilerplate();

    // Start asking for user input
    printf("Nome da empresa: %s\n", storage.name);

    printf("Nome do/da responsável: ");
    fgets(storage.owner_name, MAXMAXSIZE, stdin);

    // Remove trailing newline that comes together with user input when fgets() is used
    storage.owner_name[strcspn(storage.owner_name, "\n")] = 0;

    // -------------------------------------------------

    boilerplate();

    // Star asking for user input
    printf("Nome da empresa: %s\n", storage.name);
    printf("Nome do/da responsável: %s\n", storage.owner_name);

    printf("Cidade: ");
    fgets(storage.city, MAXMAXSIZE, stdin);

    storage.city[strcspn(storage.city, "\n")] = 0;

    // -------------------------------------------------

    boilerplate();

    // Start asking for user input
    printf("Nome da empresa: %s\n", storage.name);
    printf("Nome do/da responsável: %s\n", storage.owner_name);
    printf("Cidade: %s\n", storage.city);

    printf("Tipo de servico: ");
    fgets(storage.service_type, MAXMAXSIZE, stdin);

    storage.service_type[strcspn(storage.service_type, "\n")] = 0;

    // -------------------------------------------------

    boilerplate();

    // Start asking for user input
    printf("Nome da empresa: %s\n", storage.name);
    printf("Nome do/da responsável: %s\n", storage.owner_name);
    printf("Cidade: %s\n", storage.city);
    printf("Tipo de servico: %s\n", storage.service_type);

    printf("Contato: ");
    fgets(storage.contact, MAXMAXSIZE, stdin);

    storage.contact[strcspn(storage.contact, "\n")] = 0;

    // -------------------------------------------------

    boilerplate();

    // Start asking for user input
    printf("Nome da empresa: %s\n", storage.name);
    printf("Nome do/da responsável: %s\n", storage.owner_name);
    printf("Cidade: %s\n", storage.city);
    printf("Tipo de servico: %s\n", storage.service_type);
    printf("Contato: %s\n", storage.contact);

    printf("Email: ");
    fgets(storage.email, MAXMAXSIZE, stdin);

    storage.email[strcspn(storage.email, "\n")] = 0;

    // -------------------------------------------------

    // Call function that saves
    save_dealer(storage);

    // Free all allocated memory
    free(storage.name);
    free(storage.owner_name);
    free(storage.city);
    free(storage.service_type);
    free(storage.contact);
    free(storage.email);

    // -------------------------------------------------

    boilerplate();

    puts("Fornecedor salvo com sucesso!");

    press_to_continue();
}

//  Function that will save a new dealer
void save_dealer(createdealer dealer)
{

    // Declare a file pointer
    FILE *data;

    // Open the correct file
    data = fopen("macros/dealer.txt", "a");

    // Append all user input to file

    fprintf(data, "%s", dealer.name);
    fprintf(data, "\n");
    fprintf(data, "%s", dealer.owner_name);
    fprintf(data, "\n");
    fprintf(data, "%s", dealer.city);
    fprintf(data, "\n");
    fprintf(data, "%s", dealer.service_type);
    fprintf(data, "\n");
    fprintf(data, "%s", dealer.contact);
    fprintf(data, "\n");
    fprintf(data, "%s", dealer.email);
    fprintf(data, "\n");

    fclose(data);
}

// FUnction that will show all content at dealer databases
void show_dealer_database_all()
{

    // Declare variable that will increment
    int increment = 0;

    // Declare a storage variable
    char storage;

    // Load all dealer databases
    load_dealer_databases();

    boilerplate();

    puts("FORNECEDORES:\n");

    // loop that will go around the amount of time it is specified in the MIN and MAX TABLESIZE consts
    for (int i = 0; i < MINTABLESIZE; i++)
    {
        // Navigate horizontally a linked list
        for (dealer *tmp = table_dealer[i]; tmp != NULL; tmp = tmp->next)
        {
            increment++;
            printf("\n%i ---------------------------------------------------\n", increment);
            printf("Nome da empresa: %s\n", tmp->name);
            printf("Nome do/da responsável: %s\n", tmp->owner_name);
            printf("Cidade: %s\n", tmp->city);
            printf("Tipo de servico: %s\n", tmp->service_type);
            printf("Contato: %s\n", tmp->contact);
            printf("Email: %s\n", tmp->email);
            printf("\n");
        }
    }

    // Unload all dealer databases
    unload_dealer_databases();

    // Boilerplate
    puts("\t\t\t<<<<<<<<<< OPCÕES >>>>>>>>>>\n");

    puts("1 - Salvar no computador\n");
    puts("Qualquer tecla - Voltar\n");

    printf("\nFerramenta escolhida (Insira o numero): ");

    // Get user input
    scanf("%c", &storage);

    switch (tolower((char)storage))
    {
    case '1':
        /* Function to save on computer */
        break;
    default:
        getchar();
        press_to_continue();
        menu_show_items();
    }
}

// Function that will load all databases hashtables of delers
bool load_dealer_databases()
{

    // Create a buffer
    char *buffer = (char *)malloc(MAXMAXSIZE);
    if (buffer == NULL)
    {
        puts("ERRO 1: Não há memória o suficiente no sistema");
        return false;
    }

    // Declare a variable that will receive hashed indexes
    int index;

    // Declare a struct o "dealer" type
    // Initialize it to NULL
    dealer *node = NULL;

    // Load "dealer" databases ->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->

    // Open "dealer.txt" file
    FILE *data = fopen("macros/dealer.txt", "r");
    if (data == NULL)
    {
        puts("ERRO 2: Não foi possível abrir o arquivo necessário");
        return false;
    }

    // Write each string inside the file onto the buffer | buffer content is overwritten at this moment
    while (fgets(buffer, MAXMAXSIZE, data))
    {

        // Allocate a new memory chunck to node at each iteration
        node = malloc(sizeof(dealer));
        if (node == NULL)
        {
            puts("ERRO 1: Não há memória o suficiente no sistema");
            return false;
        }

        // Copy the string present at that line of the file to the username section of the current node
        strcpy(node->name, buffer);

        // Scan string from another line of the file to the buffer once again | buffer content is overwritten at this moment
        fgets(buffer, MAXMAXSIZE, data);

        strcpy(node->owner_name, buffer);

        // Scan string from another line of the file to the buffer once again | buffer content is overwritten at this moment
        fgets(buffer, MAXMAXSIZE, data);

        strcpy(node->city, buffer);

        // Scan string from another line of the file to the buffer once again | buffer content is overwritten at this moment
        fgets(buffer, MAXMAXSIZE, data);

        strcpy(node->service_type, buffer);

        // Scan string from another line of the file to the buffer once again | buffer content is overwritten at this moment
        fgets(buffer, MAXMAXSIZE, data);

        strcpy(node->contact, buffer);

        // Scan string from another line of the file to the buffer once again | buffer content is overwritten at this moment
        fgets(buffer, MAXMAXSIZE, data);

        strcpy(node->email, buffer);

        // Index variable receives the value returned by the hash(node->) func
        index = hash_index(node->name);

        // Check if table_dealer[index] pointer is pointing to NULL
        if (table_dealer[index] == NULL)
        {

            // If so, current conde "next" pointer must point to NULL
            node->next = NULL;

            // Set curremt node "previous" pointer to NULL
            node->previous = NULL;

            // That array position of table_dealer must point to the current node
            table_dealer[index] = node;

            // Skip next lines of code and go to the next iteration
            continue;
        }

        // If previous "if condition" is not met

        // Set the struct at location table_dealer[index] "previous" section to point to current node
        table_dealer[index]->previous = node;

        // Current node "next" pointer must point to waht table_dealer[index] is pointing to
        node->next = table_dealer[index];

        // Set current node "previous" pointer to NULL
        node->previous = NULL;

        // table_dealer must point to the current node
        table_dealer[index] = node;
    }

    // Close all opened files
    fclose(data);

    // Free all allocated memory
    free(buffer);

    return true;
}

// Unload table_dealer from memory, returning true if successful, else false
bool unload_dealer_databases()
{

    // Create a pointer to a struct of type dealer that will serve as a cursor
    dealer *cursor = NULL;

    // Loop that will got around the amount of times it is specified int the MINTABLESIZE const
    for (int i = 0; i < MINTABLESIZE; i++)
    {

        // Navigate horizontally a linked list
        for (dealer *tmp = table_dealer[i]; tmp != NULL; tmp = cursor)
        {
            cursor = table_dealer[i]->next;
            free(table_dealer[i]);
            table_dealer[i] = cursor;
        }
    }

    return true;
}

// Search function for dealer databases
void show_dealer_database_detailed()
{
    // Load all employee databases
    load_dealer_databases();

    // Global incrementor that will make it so every trailing \n character at "stdin" is removed by getchar
    // Preventing weird behavior such as the switch func detecting and invalid input instantly
    if (increment_answer_general_debug_dealer == 0)
    {
        getchar();
    }

    increment_answer_general_debug_dealer++;

    // Declare variable that will increment
    int increment = 0;

    // Declare 2 storage variables
    char storage;
    char *answer = (char *)malloc(MAXMAXSIZE);
    if (answer == NULL)
    {
        puts("ERRO 1: Não há memória suficiente no sistema");
        exit(1);
    }

    boilerplate();

    puts("VIZUALIZAR FORNECEDORES:\n");

    puts("1 - Pesquisar por NOME\n");
    puts("2 - Pesquisar por NOME DO RESPONSÁVEL\n");
    puts("3 - Pesquisar por CIDADE\n");
    puts("4 - Pesquisar por TIPO DE SERVIÇO\n");
    puts("e - Voltar");

    printf("\nFerramenta escolhida (Insira o numero): ");

    // Get user input
    scanf("%c", &storage);

    switch (tolower((char)storage))
    {
    case '1':
        boilerplate();

        printf("Nome do fornecedor: ");
        getchar();

        // Get user input
        fgets(answer, MAXMAXSIZE, stdin);

        boilerplate();
        puts("VIZUALIZAR FORNECEDORES:\n");

        // All possible positions at a table of MINTABLESIZE size
        for (int i = 0; i < MINTABLESIZE; i++)
        {

            // Navigate a linked list horizontally
            for (dealer *tmp = table_dealer[i]; tmp != NULL; tmp = tmp->next)
            {

                // For every match, print
                if (strcasecmp(answer, tmp->name) == 0)
                {
                    increment++;
                    printf("\n%i ---------------------------------------------------\n", increment);
                    printf("Nome da empresa: %s\n", tmp->name);
                    printf("Nome do/da responsável: %s\n", tmp->owner_name);
                    printf("Cidade: %s\n", tmp->city);
                    printf("Tipo de servico: %s\n", tmp->service_type);
                    printf("Contato: %s\n", tmp->contact);
                    printf("Email: %s\n", tmp->email);
                    printf("\n");
                }
            }
        }

        if (increment == 0)
        {
            puts("Nenhum item encontrado!");
            press_to_continue();
            show_dealer_database_detailed();
        }

        break;
    case '2':
        boilerplate();

        printf("Nome do responsavel: ");
        getchar();

        // Get user input
        fgets(answer, MAXMAXSIZE, stdin);
        // answer[strcspn(answer, "\n")] = 0;

        boilerplate();
        puts("VIZUALIZAR FORNECEDORES:\n");

        // All possible positions at a table of MINTABLESIZE size
        for (int i = 0; i < MINTABLESIZE; i++)
        {

            // Navigate a linked list horizontally
            for (dealer *tmp = table_dealer[i]; tmp != NULL; tmp = tmp->next)
            {

                // For every match, print
                if (strcasecmp(answer, tmp->owner_name) == 0)
                {
                    increment++;
                    printf("\n%i ---------------------------------------------------\n", increment);
                    printf("Nome da empresa: %s\n", tmp->name);
                    printf("Nome do/da responsável: %s\n", tmp->owner_name);
                    printf("Cidade: %s\n", tmp->city);
                    printf("Tipo de servico: %s\n", tmp->service_type);
                    printf("Contato: %s\n", tmp->contact);
                    printf("Email: %s\n", tmp->email);
                    printf("\n");
                }
            }
        }

        if (increment == 0)
        {
            puts("Nenhum item encontrado!");
            press_to_continue();
            show_dealer_database_detailed();
        }

        break;
    case '3':
        boilerplate();

        printf("Nome da cidade: ");
        getchar();

        // Get user input
        fgets(answer, MAXMAXSIZE, stdin);

        boilerplate();
        puts("VIZUALIZAR FORNECEDORES:\n");

        // All possible positions at a table of MINTABLESIZE size
        for (int i = 0; i < MINTABLESIZE; i++)
        {

            // Navigate a linked list horizontally
            for (dealer *tmp = table_dealer[i]; tmp != NULL; tmp = tmp->next)
            {

                // For every match, print
                if (strcasecmp(answer, tmp->city) == 0)
                {
                    increment++;
                    printf("\n%i ---------------------------------------------------\n", increment);
                    printf("Nome da empresa: %s\n", tmp->name);
                    printf("Nome do/da responsável: %s\n", tmp->owner_name);
                    printf("Cidade: %s\n", tmp->city);
                    printf("Tipo de servico: %s\n", tmp->service_type);
                    printf("Contato: %s\n", tmp->contact);
                    printf("Email: %s\n", tmp->email);
                    printf("\n");
                }
            }
        }

        if (increment == 0)
        {
            puts("Nenhum item encontrado!");
            press_to_continue();
            show_dealer_database_detailed();
        }

        break;
    case '4':
        boilerplate();

        printf("Tipo de servico: ");
        getchar();

        // Get user input
        fgets(answer, MAXMAXSIZE, stdin);

        boilerplate();
        puts("VIZUALIZAR FORNECEDORES:\n");

        // All possible positions at a table of MINTABLESIZE size
        for (int i = 0; i < MINTABLESIZE; i++)
        {

            // Navigate a linked list horizontally
            for (dealer *tmp = table_dealer[i]; tmp != NULL; tmp = tmp->next)
            {

                // For every match, print
                if (strcasecmp(answer, tmp->service_type) == 0)
                {
                    increment++;
                    printf("\n%i ---------------------------------------------------\n", increment);
                    printf("Nome da empresa: %s\n", tmp->name);
                    printf("Nome do/da responsável: %s\n", tmp->owner_name);
                    printf("Cidade: %s\n", tmp->city);
                    printf("Tipo de servico: %s\n", tmp->service_type);
                    printf("Contato: %s\n", tmp->contact);
                    printf("Email: %s\n", tmp->email);
                    printf("\n");
                }
            }
        }

        if (increment == 0)
        {
            puts("Nenhum item encontrado!");
            press_to_continue();
            show_dealer_database_detailed();
        }

        break;
    case 'e':
        unload_dealer_databases();
        free(answer);
        increment_answer_general_debug_dealer = 0;
        getchar();
        menu_show_items();
    default:
        puts("Opção inválida!");
        press_to_continue();
        show_dealer_database_detailed();
    }

    unload_dealer_databases();
    free(answer);

    // Boilerplate
    puts("\t\t\t<<<<<<<<<< OPCÕES >>>>>>>>>>\n");

    puts("1 - Salvar no computador\n");
    puts("Qualquer tecla - Voltar\n");

    printf("\nFerramenta escolhida (Insira o numero): ");

    // Get user input
    scanf("%c", &storage);

    switch (tolower((char)storage))
    {
    case '1':
        /* Function to save on computer */
        break;
    default:
        increment_answer_general_debug_dealer = 0;
        press_to_continue();
        menu_show_items();
    }
}

// Remove function for dealer databases
void remove_dealer()
{

    // Load all dealer databases
    load_dealer_databases();

    // Replace the content of "dealer.txt" with the current content of table_dealer at all indexes
    // We must open the database and erase its contents by using the parameter "w" at fopen()
    FILE *data = fopen("macros/dealer.txt", "w");

    // Close so it can be reopened with a append "a" mode
    fclose(data);

    data = fopen("macros/dealer.txt", "a");

    // Make it so the file is line buffered, not block buffered
    // This makes it so we can write onto the file while the program is running
    // Otherwise, we woul have to wait until the program is closed
    setlinebuf(data);

    // Declare two cursors
    dealer storage;

    // Declare a variable that will increment
    int increment = 0;

    // declare a storage variable
    char *answer = (char *)malloc(MAXMAXSIZE);
    if (answer == NULL)
    {
        puts("ERRO 1: Não há memória suficiente no sistema");
        exit(1);
    }

    boilerplate();

    printf("\nNome do fornecedor: ");
    getchar();

    // Get user input
    fgets(answer, MAXMAXSIZE, stdin);

    // Loop that goes around MINTABLESIZE times
    for (int i = 0; i < MINTABLESIZE; i++)
    {

        // Navigate a linked list horizontally
        for (dealer *tmp = table_dealer[i]; tmp != NULL; tmp = tmp->next)
        {

            // Check if user input is present at database
            // Check if this is an intermediate position at the linked list
            if (strcasecmp(answer, tmp->name) == 0)
            {
                increment++;
                continue;
            }

            // Copy the string present at this position of tmp to the storage.(appropriate section)
            strcpy(storage.name, tmp->name);
            strcpy(storage.owner_name, tmp->owner_name);
            strcpy(storage.city, tmp->city);
            strcpy(storage.service_type, tmp->service_type);
            strcpy(storage.contact, tmp->contact);
            strcpy(storage.email, tmp->email);

            // Append the strings present at storage.(section) onto the file
            fprintf(data, "%s", storage.name);
            fprintf(data, "%s", storage.owner_name);
            fprintf(data, "%s", storage.city);
            fprintf(data, "%s", storage.service_type);
            fprintf(data, "%s", storage.contact);
            fprintf(data, "%s", storage.email);
        }
    }

    if (increment == 0)
    {
        boilerplate();
        puts("Nenhum item encontrado!");
        // free(answer);
        unload_dealer_databases();
        press_to_continue();
        menu_remove_item();
    }

    // Close all opened files
    fclose(data);

    // Free all allocated memory
    free(answer);

    // Onload all loaded databases
    unload_dealer_databases();

    boilerplate();

    puts("Fornecedor excluído com sucesso!");
    press_to_continue();
    menu_remove_item();
}

// Edit function for dealer databases
void edit_dealer()
{

    // Load all dealer databases
    load_dealer_databases();

    // Replace the content of "dealer.txt" with the current content of table_dealer at all indexes
    // We must open the database and erase its contents by using the parameter "w" at fopen()
    FILE *data = fopen("macros/dealer.txt", "w");

    // Close so it can be reopened wth a append "a" mode
    fclose(data);

    data = fopen("macros/dealer.txt", "a");

    // Make it so the file is line buffered, not block buffered
    // This makes it so we can write onto the file while the program is running
    // Otherwise, we woul have to wait until the program is closed
    setlinebuf(data);

    // Declare a storage struct of type "dealer"
    dealer storage;

    // Declare  avariable that will increment
    int increment = 0;

    // Declare a storage variable
    char *answer = (char *)malloc(MAXMAXSIZE);
    if (answer == NULL)
    {
        puts("ERRO 1: Não há memória suficiente no sistema");
        exit(1);
    }

    boilerplate();

    printf("\nNome da empresa fornecedora: ");
    getchar();

    // Get user input
    fgets(answer, MAXMAXSIZE, stdin);

    // Loop that goes around MINTABLESIZE times
    for (int i = 0; i < MINTABLESIZE; i++)
    {

        // Navigate a linked list horizontally
        for (dealer *tmp = table_dealer[i]; tmp != NULL; tmp = tmp->next)
        {

            // Check if user input is present at database
            // Check if this is an intermediate position at the linked list
            if (strcasecmp(answer, tmp->name) == 0)
            {
                boilerplate();
                puts("Item encontrado. Insira as novas informações.\n");
                increment++;

                // Get user input
                printf("Nome: ");
                fgets(tmp->name, MAXMAXSIZE, stdin);

                printf("Nome do responsavel: ");
                fgets(tmp->owner_name, MAXMAXSIZE, stdin);

                printf("Cidade: ");
                fgets(tmp->city, MAXMAXSIZE, stdin);

                printf("Tipo de servico: ");
                fgets(tmp->service_type, MAXMAXSIZE, stdin);

                printf("Contato: ");
                fgets(tmp->contact, MAXMAXSIZE, stdin);

                printf("Email: ");
                fgets(tmp->email, MAXMAXSIZE, stdin);
            }

            // Copy the string present at this position of tmp to the storage.(appropriate section)
            strcpy(storage.name, tmp->name);
            strcpy(storage.owner_name, tmp->owner_name);
            strcpy(storage.city, tmp->city);
            strcpy(storage.service_type, tmp->service_type);
            strcpy(storage.contact, tmp->contact);
            strcpy(storage.email, tmp->email);

            // Append the strings present at storage.(section) onto the file
            fprintf(data, "%s", storage.name);
            fprintf(data, "%s", storage.owner_name);
            fprintf(data, "%s", storage.city);
            fprintf(data, "%s", storage.service_type);
            fprintf(data, "%s", storage.contact);
            fprintf(data, "%s", storage.email);
        }
    }

    if (increment == 0)
    {
        boilerplate();
        puts("Nenhum item encontrado!");
        unload_dealer_databases();
        press_to_continue();
        menu_edit_item();
    }

    // Close all opened files
    fclose(data);

    // Free all allocated memory
    free(answer);

    // Unload all loaded databases
    unload_dealer_databases();

    boilerplate();

    puts("Produto editado com sucesso!");
    press_to_continue();
    menu_edit_item();
}