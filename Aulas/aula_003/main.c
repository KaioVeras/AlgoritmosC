#include <stdio.h>

int main() {
//	int idade = 0, em_dez_anos = 0;
//	idade = 10;	
//	
//	float altura;
//	altura = 2.10;
//	
//	printf("Idade: %d\n", idade);
//	printf("Altura: %.2f\n", altura);
//	
//	em_dez_anos = idade + 10;
//	printf("Em dez anos tera a idade: %d", em_dez_anos);

	int idade = 0;
	float altura;
	
	printf("Informe sua idade: ");
	scanf("%d", &idade);
	
	printf("Informe sua altura: ");
	scanf("%f", &altura);
	
	printf("Idade: %d\nAltura: %.2f", idade, altura);
	
	return 0;
}

/*
	Operador (=) serve para atribuição/receber
	int idade = 10 - idade recebe 10
	
	Operador (==) serve para comparar valores
*/
