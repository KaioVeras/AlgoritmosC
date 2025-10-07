/*
    5) Crie um programa onde o usuário informará até 20 valores e armazene em um vetor, crie outros
    dois vetores (par e impar), faça uma varredura no vetor original, apresente ao final:

    quantidade de pares:
    quantidade de impares:
    maior valor par:
    menor valor par:
    maior valor impar:
    menor valor impar:
    media dos pares:
    media dos impares:
    quantidade de pares acima da media dos pares:
    quantidade de impares abaixo da media dos impares:

    Ao declarar os vetores utilize o tipo int e inicialize todos os elementos com 0.
*/

#include <stdio.h>
#include <limits.h>

#define TAM 20

int main() {
    int numeros[TAM];
    int par[TAM];
    int impar[TAM];
    int i;

    int qtd_par = 0;
    int qtd_impar = 0;
    long int soma_par = 0;
    long int soma_impar = 0;

    int maior_par = 0;
    int menor_par = INT_MAX;
    int maior_impar = 0;
    int menor_impar = INT_MAX;

    float media_par = 0.0;
    float media_impar = 0.0;
    int pares_acima_media = 0;
    int impares_abaixo_media = 0;

    for (i = 0; i < TAM; i++) {
        numeros[i] = 0;
        par[i] = 0;
        impar[i] = 0;
    }

    printf("Digite os %d valores:\n", TAM);
    for (i = 0; i < TAM; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    for (i = 0; i < TAM; i++) {
        if (numeros[i] % 2 == 0) {
            par[qtd_par] = numeros[i];
            soma_par += numeros[i];

            if (qtd_par == 0) {
                maior_par = numeros[i];
                menor_par = numeros[i];
            } else {
                if (numeros[i] > maior_par) {
                    maior_par = numeros[i];
                }
                if (numeros[i] < menor_par) {
                    menor_par = numeros[i];
                }
            }
            qtd_par++;
        } else {
            impar[qtd_impar] = numeros[i];
            soma_impar += numeros[i];

            if (qtd_impar == 0) {
                maior_impar = numeros[i];
                menor_impar = numeros[i];
            } else {
                if (numeros[i] > maior_impar) {
                    maior_impar = numeros[i];
                }
                if (numeros[i] < menor_impar) {
                    menor_impar = numeros[i];
                }
            }
            qtd_impar++;
        }
    }

    if (qtd_par > 0) {
        media_par = (float)soma_par / qtd_par;
    }
    if (qtd_impar > 0) {
        media_impar = (float)soma_impar / qtd_impar;
    }

    if (qtd_par > 0) {
        for (i = 0; i < qtd_par; i++) {
            if (par[i] > media_par) {
                pares_acima_media++;
            }
        }
    }
    if (qtd_impar > 0) {
        for (i = 0; i < qtd_impar; i++) {
            if (impar[i] < media_impar) {
                impares_abaixo_media++;
            }
        }
    }

    printf("\n--- RESULTADOS ---\n");

    printf("\n--- PARES ---\n");
    if (qtd_par > 0) {
        printf("Quantidade de pares: %d\n", qtd_par);
        printf("Maior valor par: %d\n", maior_par);
        printf("Menor valor par: %d\n", menor_par);
        printf("Media dos pares: %.2f\n", media_par);
        printf("Quantidade de pares acima da media: %d\n", pares_acima_media);
    } else {
        printf("Nenhum numero par foi inserido.\n");
    }

    printf("\n--- IMPARES ---\n");
    if (qtd_impar > 0) {
        printf("Quantidade de impares: %d\n", qtd_impar);
        printf("Maior valor impar: %d\n", maior_impar);
        printf("Menor valor impar: %d\n", menor_impar);
        printf("Media dos impares: %.2f\n", media_impar);
        printf("Quantidade de impares abaixo da media: %d\n", impares_abaixo_media);
    } else {
        printf("Nenhum numero impar foi inserido.\n");
    }

    return 0;
}