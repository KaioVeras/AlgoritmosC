#include <stdio.h>

int main() {

    int number1, number2;

    printf("==========================\n");
    printf("  C A L C U L A T U D O\n");
    printf("==========================\n\n");

    printf("n1: ");
    scanf("%d", &number1);

    printf("n2: ");
    scanf("%d", &number2);

    printf("\n==========================\n");
    printf("    R E S U L T A D O\n");
    printf("==========================\n\n");

    printf("Adicao: %d\n", number1 + number2);
    printf("Subtracao: %d\n", number1 - number2);
    printf("Multiplicacao: %d\n", number1 * number2);
    printf("Divisao: %d\n", number1 / number2);
    printf("Mod: %d", number1 % number2);

    return 0;
}

/*
    2) Elabore uma CALCULATUDO onde serão iformados dois números (n1 e n2), ao final será apresentado o resultado
    do cálculo entre n1 e n2 utilizando todos os operadores aritméticos apresentados em aula (+ - * / %).

    Ex:

    CALCULATUDO

    n1: 10
    n2: 2

    adicao: 12
    subtracao: 8
    multiplicacao: 20
    divisao: 5
    mod: 0

---------------
 */