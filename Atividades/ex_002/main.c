#include <stdio.h>

int main() {
	
	char nome_completo[40];
	
	int idade = 0;
	
	printf("--------------------------------\n");
	printf("         C A D A S T R O\n");
	printf("--------------------------------\n\n");
	
	printf("Nome completo: ");
	scanf("%[^\n]s", &nome_completo);
	
	printf("Informe sua idade: ");
	scanf("%d", &idade);
	
	printf("\n--------------------------------\n\n");
	
	printf("Nome completo: %s\n", nome_completo);
	printf("Idade em 10 anos: %d", idade + 10);
	
	return 0;
}

/*
	% - significa mod, resto de divisão
	Exemplo: 17 % 5 = 2
	Exemplo: 15 % 5 = 0
*/
