/*
 * 2) Desenvolva uma solução onde o usuario informará até 5 notas, a cada nota
 * informada aparecerá a opção "Deseja sair? (S/N)", caso o usuario digite N
 * o programa continuará até atingir o limite de 5 notas.
 */

#include <stdio.h>
#define TAM 5

int main() {
    float notas[TAM];
    char sair;
    int i = 0;

    printf("----------------------------\n");
    printf("        M  E  D  I  A\n");
    printf("----------------------------\n\n");

    for(i = 0; i < TAM; i++) {
        printf("Informe uma nota para %d: ", i + 1);
        scanf("%f", &notas[i]);

        if(i != TAM - 1) {
            printf("Deseja sair? (S/N): ");
            scanf(" %c", &sair);
        }

        if(sair == 'S' || i == TAM - 1) {
            printf("Fim do programa!");
            return 0;
        }
    }

    return 0;
}