#include <stdio.h>

int main() {	
//	char nome[20], sobrenome[20], nome_completo[20];
//
//	printf("Nome: ");
//	scanf("%s", &nome);
//	
//	printf("Sobrenome: ");
//	scanf("%s", &sobrenome);
//	
//	printf("Nome completo: %s %s", nome, sobrenome);
//	
//	printf("\n\n--------------------\n\n");
//	
//	printf("Informe nome completo: ");
//	fflush(stdin);
//	scanf("%[^\n]s", &nome_completo);
//	printf("Nome completo: %s", nome_completo);


	double numberOne, numberTwo, resultado;
	
	printf("Numero 1: ");
	scanf("%lf", &numberOne);
	
	printf("Numero 2: ");
	scanf("%lf", &numberTwo);
	
	resultado = numberOne - numberTwo;
	printf("Resultado: %lf", resultado);
	
	return 0;
}

/*
	--- Expressão Regular (scan set) ---
	[^\n] - Permite utilizar espaço no scanf, normalmente o espaço significa o próximo parâmetro 
*/
