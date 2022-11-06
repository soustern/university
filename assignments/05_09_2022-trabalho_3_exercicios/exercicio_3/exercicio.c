/* 3 - FAça um programa em c que recebe 2 valores reais e um código e executa uma operação com base na tabela abaixo:

CÓDIGO | OPERAÇÃO
1      | soma
2      | subtração
3      | multiplicação
4      | divisão 
*/

// Inclusions
#include <stdio.h>

// Main function
void main () {

    // Variable declaration
    float v1, v2, result;
    int operation_code;

    // Collecting user input
    printf("Choose a number corresponding to the operating you wish to do\n1 - sum\n2 - subtraction\n3 - multiplication\n4 - division\nEnter your number of choice: ");
    scanf("%i", &operation_code);

    // Establishing conditions and printing results
    if (operation_code == 1) {
        printf("Enter two numbers to perform the operation.\n");
        printf("First number: ");
        scanf("%f", &v1);
        printf("Second number: ");
        scanf("%f", &v2);
        result = v1 + v2;
        printf("(SUM) The result of your operation is: %.2f", result);
    }
    else if (operation_code == 2) {
        printf("Enter two numbers to perform the operation.\n");
        printf("First number: ");
        scanf("%f", &v1);
        printf("Second number: ");
        scanf("%f", &v2);
        result = v1 - v2;
        printf("(SUB) The result of your operation is: %.2f", result);
    }
    else if (operation_code == 3) {
        printf("Enter two numbers to perform the operation.\n");
        printf("First number: ");
        scanf("%f", &v1);
        printf("Second number: ");
        scanf("%f", &v2);
        result = v1 * v2;
        printf("(MULT) The result of your operation is: %.2f", result);
    }
    else if (operation_code == 4) {
        printf("Enter two numbers to perform the operation.\n");
        printf("First number: ");
        scanf("%f", &v1);
        printf("Second number: ");
        scanf("%f", &v2);
        if (v1 != 0 && v2 != 0) {
            result = v1 / v2;
            printf("(DIV) The result of your operation is: %.2f", result);
        }
        else {
            printf("(ERROR) No division with 0");
        }
    }
    else {
        printf("(ERROR) No such operation as: %i", operation_code);
    }
}
