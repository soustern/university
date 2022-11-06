#include <stdio.h>

#define num 10

int main(void)
{
    // Vetor de 10 posições
    int numeros[num];

    // Variável quer servirá como "armazem" para números "passageiros"
    int storage;

    //  Loop para coletar 10 numeros e atribuir seus valores as respectivas posições numeros[i]
    for (int i = 0; i < num; i++)
    {
        printf("Numero %i: ", i + 1);
        scanf("%i", &numeros[i]);
    }

    // Loop para iterar os dez valores presentes em numeros[i] e implementar o "bubble-sort"
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num - i - 1; j++)
        {
            if (numeros[j] > numeros[j + 1])
            {
                storage = numeros[j + 1];
                numeros[j + 1] = numeros[j];
                numeros[j] = storage;
            }
        }
    }

    // Imprimir todas as posições de numeros[i]
    for (int i = 0; i < num; i++)
    {
        printf("\n%i\n", numeros[i]);
    }
}