
/*
 *  1) Elabore um programa onde o usuário informará 5 notas, após receber
 *  as notas, as mesmas serão apresentadas na ordem inversa à informada!
 */

#include <stdio.h>
#define TAM 5

int main() {

    float notas[TAM];
    int i = 0;

    printf("----------------------------\n");
    printf("        N  O  T  A  S\n");
    printf("----------------------------\n\n");

    for(i = 0; i < TAM; i++) {
        printf("Informe uma nota para %d: ", i + 1);
        scanf("%f", &notas[i]);
    }

    printf("\n----------------------------\n\n");

    for(i = TAM - 1; i >= 0; i--) {
        printf("Nota %d: %.1f\n", i + 1, notas[i]);
    }


    return 0;
}