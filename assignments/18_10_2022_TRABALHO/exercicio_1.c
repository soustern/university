#include <stdio.h>
#include <stdlib.h>

typedef struct product
{
    int codigo;
    char nome[50];
    int valor;
    int estoque;
    struct product *next;
} product;

// Global Variables
const unsigned int N = 17576;
/* product *table[N];
 */
int main(void)
{
    // Local Variables
    int item_count = 0;

    char *choice = malloc(sizeof(char) * 3 + 1);

    product *products = NULL;

    do
    {
        item_count++;

        products = malloc(sizeof(product));

        printf("\n\nProduto %i--------------------------------\n", item_count);

        // Codigo
        printf("Codigo: ");
        scanf("%i", &products->codigo);

        // Nome
        printf("Nome: ");
        scanf("%s", products->nome);

        // Valor
        printf("Valor: ");
        scanf("%i", &products->valor);

        // Estoque
        printf("Quantidade em Etoque: ");
        scanf("%i", &products->estoque);

        // Continuar ou não
        printf("Cotinuar?(s/n) ");
        scanf("%c", choice);

        if (choice[1] == 'n')
        {
            break;
        }
    } while (item_count <= 100);
}