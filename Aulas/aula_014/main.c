#include <stdio.h>

int le_valida_idade();
char le_valida_continuar();

int main() {
	char nome[20], continuar;
	int idade;
	
	do {
		printf("--------------------------------\n");
		printf("        C A D A S T R O\n");
		printf("--------------------------------\n\n");
	
		printf("Nome: ");
		scanf(" %[^\n]s", &nome);
	
		idade = le_valida_idade();
	
		printf("\n--------------------------------\n");
		printf("Nome: %s - Idade: %d", nome, idade);
		printf("\n--------------------------------\n");
		
		continuar = le_valida_continuar();
		system("cls");
	} while(continuar == 's');
	
	printf("\n--------------------------------\n");
	printf("Programa Finalizado");
	return 0;
}

int le_valida_idade() {
	int idade = 0;
	
	printf("Idade: ");
	scanf("%d", &idade);
	
	if(idade < 1 || idade > 130) {
		do {
			system("cls");
			printf("\n--------------------------------\n");
			printf("Idade invalida, necessario estar entre 1 e 130\n");
			printf("Informe novamente: ");
			scanf("%d", &idade);
			system("cls");
		} while(idade < 1 || idade > 130);
	} else {
		return idade;
	}
}

char le_valida_continuar() {
	char continuar;
	int cont = 0;
	
	do {
		if(cont == 0) {
			printf("\nDeseja continuar(S/N)? ");
			scanf(" %c", &continuar);	
		} else {
			printf("Entrada invalida, deseja continuar (S/N)? ");
			scanf(" %c", &continuar);
		}
		
		continuar = tolower(continuar);
		
		cont++;
	} while(continuar != 's' && continuar != 'n');
	
	return continuar;
}
