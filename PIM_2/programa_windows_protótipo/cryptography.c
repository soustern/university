#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Include "linker" header file
#include "functions.h"

// Define all constant values
#define ALPHABET 26

// Discriminating asccii values for upper and lower case letters
int ascii_lower[] = {97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122};
int ascii_upper[] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90};
int encryptor[] = {33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 64, 91, 92, 93, 94, 58, 59, 60, 61, 62, 63};

char *encrypt(char *plaintext)
{
    // Loop to iterate each character present in the plaintext user input
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        // printf("first iterator: %i\n", i);
        // printf("%i\n", plaintext[i]);

        // Checking if plaintext[i] is a letter
        if ((plaintext[i] >= 97 && plaintext[i] <= 122) || (plaintext[i] >= 65 && plaintext[i] <= 90))
        {
            // Checking if lowercase
            if (islower(plaintext[i]) != 0)
            {

                // Loop that goes for the total amount of letters on the alphabet
                for (int j = 0; j < ALPHABET; j++)
                {

                    // At each iteration, a variable made only for storage receiveis all the values of ascii lowercase alphabet
                    // This is necessary so the original ascii value doesnt get contaminated with the encrypted ones each iteration
                    int ascii_storage[] = {97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122};

                    // Condition to see at wich postion that plaintext[i] appars on the ascii_storage list
                    if (plaintext[i] == ascii_storage[j])
                    {

                        // After we find it, we exchance that ascii_storage value by the one existent on the same position at the key provided
                        ascii_storage[j] = encryptor[j];

                        // Then that plaintext position receives the now exchanged ascii_value || we also force lowercase on that value existent on the key so we retain the user input
                        // If lowercase, it stays that way, even if the value being received from the key isnt
                        plaintext[i] = tolower(ascii_storage[j]);

                        // Condition braks so we dont iterate more once the positions are found and values are exchanged
                        break;
                    }
                }
            }

            // Checking if uppercase
            if (isupper(plaintext[i]) != 0)
            {

                // Loop that goes for the total amount of letters on the alphabet
                for (int j = 0; j < ALPHABET; j++)
                {

                    // At each iteration, a variable made only for storage receiveis all the values of ascii uppercase alphabet
                    // This is necessary so the original ascii value doesnt get contaminated with the encrypted ones each iteration
                    int ascii_storage[] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90};

                    // Condition to see at wich postion that plaintext[i] appars on the ascii_storage list
                    if (plaintext[i] == ascii_storage[j])
                    {

                        // After we find it, we exchance that ascii_storage value by the one existent on the same position at the key provided
                        ascii_storage[j] = encryptor[j];

                        // Then that plaintext position receives the now exchanged ascii_value || we also force uppercase on that value existent on the key so we retain the user input
                        // If uppercase, it stays that way, even if the value being received from the key isnt
                        plaintext[i] = toupper(ascii_storage[j]);

                        // Condition braks so we dont iterate more once the positions are found and values are exchanged
                        break;
                    }
                }
            }
        }
    }

    // We return the newly encrypted plaintext string
    return plaintext;
}

char *decrypt(char *plaintext)
{

    // Loop to iterate each character present in the plaintext user input
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {

        // Loop that goes for the total amount of letters on the alphabet
        for (int j = 0; j < ALPHABET; j++)
        {
            // Condition to see at wich postion that plaintext[i] appars on the ascii_storage list
            if (plaintext[i] == encryptor[j])
            {

                // Then that plaintext position receives the now exchanged ascii_value || we also force uppercase on that value existent on the key so we retain the user input
                // If uppercase, it stays that way, even if the value being received from the key isnt
                plaintext[i] = ascii_lower[j];

                // Condition braks so we dont iterate more once the positions are found and values are exchanged
                break;
            }
        }
    }

    // We return the newly encrypted plaintext string
    return plaintext;
}
