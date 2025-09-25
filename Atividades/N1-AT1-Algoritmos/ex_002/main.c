#include <stdio.h>

// 2. Entrada e saída
int main() {
	char nome[10];
	int idade = 0;
	float altura;
	
	printf("--------------------------------\n");
	printf("         C L I N I C A\n");
	printf("--------------------------------\n\n");
	
	printf("Nome: ");
	scanf(" %s", &nome);
	
	printf("Idade: ");
	scanf(" %d", &idade);
	
	printf("Altura: ");
	scanf(" %f", &altura);
	
	printf("\n--------------------------------\n\n");
	
	printf("Paciente %s possui %d anos e altura de %.2fm", nome, idade, altura);
	
	
	return 0;
}
