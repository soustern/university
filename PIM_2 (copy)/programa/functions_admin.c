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
product *table_product[MINTABLESIZE];
dealer *table_dealer[MINTABLESIZE];

// Declare global variables
int increment_answer_register_item = 0;

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
    // tolower() function is invoked so the program works if user input is capslock
    switch (tolower((char)storage))
    {
    case '1':
        menu_register_item();
        break;
    case '2':
        menu_show_items();
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
        getchar();
        press_to_continue();
        menu_admin();
    }
}

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
    getchar();
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

////////////////////////////////////////////////////////////////////////////////////////////

// Function that will show all content present at employee databases
void show_employee_database_all()
{

    // Declare variable that will increment
    int increment = 0;

    // Load all employee databases
    load_employee_databases();

    // Clear terminal screen
    clear();

    // Boiler plate
    puts("\t\t\t<<<<< SLS 1.0 >>>>>\n");
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
}

////////////////////////////////////////////////////////////////////////////////////////////

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

    printf("Quantidade do produto (Número inteiro)): ");
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

// PRODUCT functions XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

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