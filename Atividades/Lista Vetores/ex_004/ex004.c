/*
 *  4) Desenvolva um programa onde o usuario informará 10 valores que serão armazenados
 *  num vetor, posteriormente leia cada elemento do vetor, ao final apresente apenas
 *  a quantidade de pares e a quantidade de ímpares.
 */

#include <stdio.h>
#define TAM 10

int main() {
    int num[TAM];
    int par = 0, impar = 0, i = 0;

    printf("\n----------------------------\n");
    printf(" P a r e s / I m p a r e s");
    printf("\n----------------------------\n\n");

    for(i = 0; i < TAM; i++) {
        printf("Informe o numero %d: ", i + 1);
        scanf("%d", &num[i]);
    }

    printf("\n----------------------------\n");
    printf("     R e s u l t a d o");
    printf("\n----------------------------\n");

    for(i = 0; i < TAM; i++) {
        if(num[i] % 2 == 0) {
            par++;
        } else {
            impar++;
        }
    }

    if(par > 0) {
        printf("Pares: %d\n", par);
    }

    if(impar > 0) {
        printf("Impares: %d\n", impar);
    }
    return 0;
}