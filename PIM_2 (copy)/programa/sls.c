#include <stdio.h>
#include <stdlib.h>

// Include "linker" header file
#include "functions.h"

int main()
{
    // Initialize a file pointer opening "session_counter.txt"
    FILE *data = fopen("macros/session_counter.txt", "r");
    if (data == NULL)
    {
        puts("ERRO 2: Nao foi possivel acessar o arquivo");
        return 2;
    }

    // Initialize a storage variable wich will receive the content of the "data" file pointer
    char storage;

    // Read the content of the "data" file pointer to the storage char variable
    fread(&storage, sizeof(char), 1, data);

    // Close the "session_counter.txt" file
    fclose(data);

    // Check if value is 0 or 1
    // If zero, initialize "first session mode" where the first signup will occur
    // The first signup is always of a ADMIN account
    if (storage == '0')
    {

        // Call newcomer_message_first function
        newcomer_message_first();

        // Call signup_admin function
        signup_admin();

        //  Call newcomer_message_second function
        newcomer_message_second();

        // Call menu_admin function
        menu_admin();

        // Change the value of "sessions_counter.txt" to 1
        // Give the char of '1' to the storage variable
        storage = '1';

        // Open the "session_counter.txt" file once again to the "data" file pointer
        // Open with write method
        data = fopen("macros/session_counter.txt", "w");
        if (data == NULL)
        {
            puts("ERRO 2: Nao foi possivel acessar o arquivo");
            return 2;
        }

        // Write the value of storage onto the "session counter file"
        fwrite(&storage, sizeof(char), 1, data);

        return 0;
    }
    else
    {
        login();
    }

    return 0;
}