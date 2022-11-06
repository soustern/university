#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Include "linker" header file
#include "functions.h"

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
    // Multipurpose character storage variable
    char storage;

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
            puts("Aperte ENTER para tentar novamente...");

            // Wait until user presses enter
            scanf("%c", &storage);
            while (storage != 10)
            {
                scanf("%c", &storage);
            }

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

        puts("\nNome de usuario INVALIDO!");
        puts("Seu nome de usuario deve ter entre 5 e 10 caracteres quaisquer s/ espaços");
        puts("Aperte ENTER para tentar novamente...");

        // Wait until user presses enter
        scanf("%c", &storage);
        while (storage != 10)
        {
            scanf("%c", &storage);
        }

        return false;
    }
    else
    {
        return true;
    }
}

bool check_password(char *password, char *confirmation)
{

    // if check_length has already returned false, dont even bother continuing this function
    if (check_length(password) == false)
    {
        return false;
    }

    // Declare increment variable starting from zero
    int increment = 0;

    // Multipurpose character storage variable
    char storage;

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
            puts("As senhas inseridas nao sao iguais!");
            puts("Aperte ENTER para tentar novamente...");

            // Wait until user presses enter
            scanf("%c", &storage);
            while (storage != 10)
            {
                scanf("%c", &storage);
            }

            return false;
        }
    }

    // Check if amount of times both array position match is equal to the lenght of the passed value "password"
    if (increment != strlen(password))
    {
        puts("As senhas inseridas nao sao iguais!");
        puts("Aperte ENTER para tentar novamente...");

        // Wait until user presses enter
        scanf("%c", &storage);
        while (storage != 10)
        {
            scanf("%c", &storage);
        }

        return false;
    }
    else
    {
        puts("As senhas sao iguais");

        return true;
    }
}

// First Session functions XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// Function to signup the first account
// The first account is always of ADMIN status
void signup()
{
    // Clear terminal screen
    clear();

    // Initialize a storage struct of type "createperson"
    createperson storage;

    // Alloc a big chunck of memory to "confirmation" | The size will that of "MAXSIZE" constant
    // Declare storage variable that will be responsible for receiving "password confirmation" input
    char *confirmation = (char *)malloc(MAXSIZE);
    if (confirmation == NULL)
    {
        puts("ERRO 1: Memoria insuficiente no sistema");
        return;
    }

    // Alloc a big chunck of memory to "storage.username" | The size will that of "MAXSIZE" constant
    // The memory allocated has to be big as to be user-error proof
    storage.username = (char *)malloc(MAXSIZE);
    if (storage.username == NULL)
    {
        puts("ERRO 1: Memoria insuficiente no sistema");
        return;
    }

    // Alloc a big chunck of memory to "storage.password" | The size will that of "MAXSIZE" constant
    // The memory allocated has to be big as to be user-error proof
    storage.password = (char *)malloc(MAXSIZE);
    if (storage.password == NULL)
    {
        puts("ERRO 1: Memoria insuficiente no sistema");
        return;
    }

    do
    {
        // Clear terminal screen
        clear();

        // Boilerplate
        puts("\t\t\t<<<<< SLS 1.0 >>>>>\n");
        puts("Conta com status 'ADMINISTRADOR'");
        puts("Salve as credenciais escolhidas em um lugar seguro!\n");

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
        puts("Conta com status 'ADMINISTRADOR'");
        puts("Salve as credenciais escolhidas em um lugar seguro!\n");

        // Start asking for user input
        printf("Nome de usuario (Entre 5 e 10 caracteres): %s", storage.username);
        // printf("Senha (Entre 5 e 10 caracteres): ");
        puts("*****A senha não aparecera enquanto a digitaçao ocorrer*****");

        // Turn off terminal echoing to mask password
        // TODO: REDO THIS FUNCTIONS FOR WINDOWS
        storage.password = strdup(getpass("Senha (Entre 5 e 10 caracteres): "));

    } while (check_password(storage.password, confirmation) == false);

    printf("\n\n\n%s\n%s\n\n\n", storage.username, storage.password);

    // Free all allocated memory
    free(storage.username);
    free(storage.password);
    free(confirmation);
}
