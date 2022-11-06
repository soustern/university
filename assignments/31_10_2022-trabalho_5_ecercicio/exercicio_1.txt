#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

// Constants
#define MIN 100
#define MAX 200
#define HASH 10000

// Functions
void menu();
void answer();

bool add();
void show();

/* int hash(char *hash); */

// Product custom struct
typedef struct
{
    char name[MIN];
    int code;
    char description[MAX];
    float valor;
} prod;

// Default table that will receive a hash code as index
prod *table[HASH];

int main()
{
    menu();
    answer();
}

// Function that clears the terminal screen
void clear_screen()
{
    system("clear");
}

// Function that prints the options menu
void menu()
{
    // Clear window
    clear_screen();
    puts("<<<<<<<<<<PRODUCT-MANAGER>>>>>>>>>>\n");

    puts("1 - Cadastrar");
    puts("2 - Exibir");
    puts("3 - Pesquisar");
    puts("4 - Sair\n");
}

// Function that receives an answer
void answer()
{
    menu();

    // Variable tha will receive the selected option correspondent number
    int opt;
    printf("Insira o numero correspondente a opçao desejada: ");
    scanf("%i", &opt);

    switch (opt)
    {
    case 1:
        add();
        break;

    case 2:
        show();
        break;

    case 3:

        break;

    case 4:
        puts("\nTodos os dados foram salvos com sucesso.");
        puts("Ate mais! :)\n");
        return;
        break;

    default:
        printf("\nEsse comando nao existe! Aperte ENTER para continuar.\n");
        getchar();
        getchar();
        break;
    }

    answer();
}

// Function to add a product
bool add()
{
    // Call menu
    menu();

    // Open file to pointer
    FILE *data = fopen("database.txt", "a");
    if (data == NULL)
    {
        printf("Não foi possivel acessar o arquivo");
        return false;
    } 

    // Initialize a new struct
    prod storage;

    // User input
    printf("Nome do produto: ");
    getchar();
    fgets(storage.name, sizeof(storage.name), stdin);

    printf("Codigo do produto: ");
    scanf("%i", &storage.code);

    printf("Faça uma descriçao breve (Max. 200 caracteres): ");
    getchar();
    fgets(storage.description, sizeof(storage.description), stdin);

    printf("Valor: ");
    scanf("%f", &storage.valor);
    getchar();

    // Write user input to file
    fprintf(data, "Nome: %s", storage.name);
    fprintf(data, "Codigo: %i\n", storage.code);
    fprintf(data, "Descricao: %s", storage.description);
    fprintf(data, "Valor: R$%f\n", storage.valor);
    fprintf(data, "\n");

    // Ask for user input to continue
    puts("\nSalvo com sucesso!");
    puts("Aperte enter para continuar...");
    getchar();

    // Close the file
    fclose(data);
    return true;
}

void show()
{
    // Printing menu
    menu();

    // Declaring storage variable
    char *storage = malloc(sizeof(prod));
    if (storage == NULL)
    {
        puts("\nERRO: Nao a memoria o suficiente no sistema!");
        return;
    }

    // Opening file
    FILE *data = fopen("database.txt", "r");

    // Read from file to storage
    while (fgets(storage, sizeof(prod), data))
    {
        printf("%s", storage);
    }

    puts("Aperte ENTER para continuar.");
    getchar();
    getchar();

    // Free any allocated memory
    free(storage);

}

/* // Function that will multiply the first letters of the received argument by themselves
int hash(char *hash)
{
    // Variable where hash_index will be stored
    int value = 0;

    // Number of iterations
    int iterations = 3;

    for (int i = 0; i < iterations; i++)
    {
        value += hash[i];
        printf("%i\n", value);
    }
} */

