#include <stdlib.h>

// Include "linker" header file
#include "functions.h"

// Declare global variables

// Function that will render a functionality menu with LIMITED capabilities
void menu_limited()
{

    boilerplate();

    puts("Conta com status 'LIMITADA'\n\n");

    // Available tools
    puts("1 - Vizualizar item\n");
    puts("2 - Manual\n");
    puts("e - Sair\n");

    // Call answer_limited function
    answer_limited();
}

// Function that will receive user answer and will route another function
void answer_limited()
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
        menu_show_items();
        break;
    case '2':
        //
        break;
    case 'e':
        getchar();
        press_to_continue();
        exit(0);
    default:
        puts("Opção inválida!");
        press_to_continue();
        menu_limited();
    }
}