/*
 * 3) Apresente um programa onde o usuario informará até 10 notas, ao final deverá ser
 * apresentado a média das notas informadas, quantas "aprovadas" (acima de 7 (inclusive)) e quantas "reprovadas".
 */

#include <stdio.h>
#define TAM 10

int main() {
    float notas[TAM], media = 0, soma = 0.0;
    char sair;
    int i = 0, aprovadas = 0, reprovadas = 0;
    int total_inseridas;

    printf("----------------------------\n");
    printf("    M  E  D  I  A   A/R\n");
    printf("----------------------------\n\n");

    for(i = 0; i < TAM; i++) {
        printf("Informe uma nota para %d: ", i + 1);
        scanf("%f", &notas[i]);

        soma += notas[i];

        if(i != TAM - 1) {
            printf("Deseja sair? (S/N): ");
            scanf(" %c", &sair);
        }

        if(sair == 'S') {
            printf("Fim do programa!\n");
            break;
        }
    }

    if(i == TAM) {
        total_inseridas = TAM;
    } else {
        total_inseridas = i + 1;
    }



    media = soma / total_inseridas;

    printf("\n----------------------------\n");
    printf("Media: %.1f", media);
    printf("\n----------------------------\n");

    for(int j = 0; j < total_inseridas; j++) {
        if(notas[j] >= 7) {
            aprovadas++;
        } else {
            reprovadas++;
        }
    }

    printf("----------------------------\n");
    printf("Resultado Geral (%d Notas)\n", total_inseridas);
    printf("Aprovados (>= 7.0): %d\n", aprovadas);
    printf("Reprovados (< 7.0): %d", reprovadas);
    printf("\n----------------------------");

    return 0;
}