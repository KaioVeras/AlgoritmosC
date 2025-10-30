#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAM_NOME 101
#define TAM_PARTE 51

int main() {
    char nomeCompleto[TAM_NOME];
    char primeiroNome[TAM_PARTE];
    char ultimoSobrenome[TAM_PARTE];
    char tagPassageiro[TAM_NOME];
    int i = 0, j = 0;

    printf("? Don't Worry Airlines - Check-in ?\n");
    printf("Por favor, informe o nome completo do passageiro: ");

    if (fgets(nomeCompleto, TAM_NOME, stdin) == NULL) {
        printf("Erro ao ler o nome.\n");
        return 1;
    }

    nomeCompleto[strcspn(nomeCompleto, "\n")] = '\0';

    for (i = 0; nomeCompleto[i] != '\0'; i++) {
        nomeCompleto[i] = tolower(nomeCompleto[i]);
    }

    i = 0;
    while (nomeCompleto[i] != ' ' && nomeCompleto[i] != '\0' && i < TAM_PARTE - 1) {
        primeiroNome[i] = nomeCompleto[i];
        i++;
    }
    primeiroNome[i] = '\0';

    char* pUltimoEspaco = strrchr(nomeCompleto, ' ');

    if (pUltimoEspaco != NULL) {
        strcpy(ultimoSobrenome, pUltimoEspaco + 1);
    } else {
        strcpy(ultimoSobrenome, nomeCompleto);
    }

    if (primeiroNome[0] != '\0') {
        primeiroNome[0] = toupper(primeiroNome[0]);
    }

    for (j = 0; ultimoSobrenome[j] != '\0'; j++) {
        ultimoSobrenome[j] = toupper(ultimoSobrenome[j]);
    }

    sprintf(tagPassageiro, "%s/%s", ultimoSobrenome, primeiroNome);

    printf("\n+-------------------------+\n");
    printf("|     %-20s|\n", tagPassageiro);
    printf("|     %-20s|\n", "Boa viagem!");
    printf("+-------------------------+\n");

    return 0;
}

