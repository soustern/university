#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <ctype.h>

// Include "linker" header file
#include "functions.h"

// Declare global structs
accountadmin *table_account_admin[MINTABLESIZE];

// General purpose functions XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// Function to clean terminal screen
void clear()
{
    // For linux
    system("clear");
    // For windows
    // system("clr");
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

/* // Function to remove the first space that is being added in front of the password input
// A blank space character is being placed at array[0] at the password input saved string
void remove_first_space(char *password)
{
    for (int i = 0, n = strlen(password) - 1; i < n; i++)
    {
        password[i] = password[i + 1];
    }
} */

// Function that will print a newcomer message
void newcomer_message_first()
{

    // Clear terminal screen
    clear();

    puts("\t\t\t<<<<< SLS 1.0 >>>>>\n");
    puts("Seja bem-vindo(a) ao Simple Logistical System!\n");
    puts("Para começar a utilizar o sistema, cadastre sua primeira conta");
    puts("que, por padrão, tera o escopo de CONTA ADMINISTRADORA.\n");

    puts("Para saber mais sobre as diferentes contas que o SLS suporta");
    puts("e suas particularidades, selecione a opção 8 no menu");
    puts("ou acesse a seção 'Manual' em nosso site!\n");

    press_to_continue();
}

// Function that will print another newcomer message
void newcomer_message_second()
{

    // Clear terminal screen
    clear();

    puts("\t\t\t<<<<< SLS 1.0 >>>>>\n");
    puts("Conta criada com sucesso!\n");
    puts("Não se esqueça de guardar as credenciaus fornecidas");
    puts("em um lugar seguro.\n");

    puts("A seguir você será redirecionado(a) para o MENU.");
    puts("A tela do menu discrimina as diferentes funcionalidades do sistema");
    puts("assim como seu respectivo número de designação.\n");

    puts("Para acessar qualquer funcionalidade que desejar");
    puts("digite o número correspondente aquela ferramenta");
    puts("e pressione ENTER\n");

    press_to_continue();
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

// Function that check databases to see if given credentials exists there
void login()
{
}

// Function that will load all databases hashtables
bool load_databases()
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

    // Load "account_admin" databases ->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->

    // clare a struct of the "account" type
    // Initialize it to NULL
    accountadmin *node = NULL;

    // Open "account_admin.txt" file
    FILE *data = fopen("macros/account_admin.txt", "r");

    // Write each string inside the file onto the buffer | buffer content is overwritten at this moment
    while (fscanf(data, "%s", buffer) == 1)
    {

        // Allocate new memory to node at each iteration
        node = malloc(sizeof(accountadmin));
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

        // Index variable receives the value returned by the hash(node->) func
        index = hash_index(node->password);

        // Check if table_account_admin[index] is pointer is pointing to NULL
        if (table_account_admin[index] == NULL)
        {

            // If so, current node "next" pointer must point to NULL
            node->next = NULL;

            // That array position of table_account_admin must point to the current node
            table_account_admin[index] = node;

            // Skip next lines of code a got to the next iteration
            continue;
        }

        // If previous "if condition" is not met
        // Current node "next" point must point to what table_account_admin[index] is pointing to
        node->next = table_account_admin[index];

        // table_account_admin must point to what the current node
        table_account_admin[index] = node;
    }

    fclose(data);

    // Free all allocated memory
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

// Function that will check all databases to see if given password already exists

// Functions that will free all structs

// Unloads structs from memory, returning true if successful, else false
bool unload()
{

    // Create a pointer of to a struct of type accountadmin that will serve as a cursor
    accountadmin *cursor = NULL;

    // loop that will go around the amount of time it is specified in the MIN and MAX TABLESIZE consts
    for (int i = 0; i < MINTABLESIZE; i++)
    {
        for (accountadmin *tmp = table_account_admin[i]; tmp != NULL; tmp = cursor)
        {
            cursor = table_account_admin[i]->next;
            free(table_account_admin[i]);
            table_account_admin[i] = cursor;
        }
    }
}

// ADMIN functions XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// Function to signup a ADMIN account
void signup_admin()
{
    // Clear terminal screen
    clear();

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
    } while (check_length(storage.username) == false);

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
        // printf("Senha (Entre 5 e 10 caracteres): ");
        puts("\n*****A senha não aparecerá enquanto a digitação ocorrer*****");

        // Turn off terminal echoing to mask password
        // TODO: REDO THIS FUNCTIONS FOR WINDOWS
        storage.password = strdup(getpass("Senha (Entre 5 e 10 caracteres): "));

    } while (check_password(storage.password, confirmation) == false);

    /* // Call remove_first_space function
    remove_first_space(storage.password); */

    // Call save_acount_admin function
    save_account_admin(storage);

    // Free all allocated memory
    free(storage.username);
    free(storage.password);
    free(confirmation);
}

// Function that will save a new account when all the validations passes
void save_account_admin(createaccount account)
{

    // Declare e FILE Pointer
    FILE *data;

    // Save account.username in a file ->->->->->->

    // Open the correct file
    data = fopen("macros/account_admin.txt", "a");

    // Append username and password to file
    fprintf(data, "%s", account.username);
    fprintf(data, "%s\n", account.password);

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

    puts("5 - Cadastrar conta\n");

    puts("6 - Relatórios");
    puts("7 - Configurações");
    puts("8 - Manual\n");

    puts("9 - Sair\n");

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
        getchar();
        press_to_continue();
        unload();
        break;
    default:
        puts("Opção inválida!");
        press_to_continue();
        menu_admin();
    }
}
