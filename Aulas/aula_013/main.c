#include <stdio.h>

float somatoria(float n1, float n2);
float subtracao(float n1, float n2);
float multiplicacao(float n1, float n2);
float divisao(float n1, float n2);

int main() {
	float num1 = 0, num2 = 0;
	char operacao;
	
	printf("--------------------------------\n");
	printf("     C A L C U L A D O R A\n");
	printf("--------------------------------\n\n");
	
	printf("Numero 1: ");
	scanf("%f", &num1);
	
	printf("Numero 2: ");
	scanf("%f", &num2);
	
	fflush(stdin);
	printf("\nEscolha uma operacao (+ , - , * , / , %%): ");
	scanf(" %c", &operacao);
	
	printf("\n--------------------------------\n");
	
	switch(operacao) {
		case '+':
			printf("Soma: %.1f", somatoria(num1, num2));
		break;
		case '-':
			printf("Subtracao: %.1f", subtracao(num1, num2));
		break;
		case '*':
			printf("Multiplicacao: %.1f", multiplicacao(num1, num2));
		break;
		case '/':
			if(num2 == 0) {
				printf("Operacao Invalida!");
			} else {
				printf("Divisao: %.1f", divisao(num1, num2));
			}
		break;
		default: 
			printf("Operacao nao encontrada!");
	}

	return 0;
}

float somatoria(float n1, float n2) {
	int result = 0;
	result = n1 + n2;
	return result;
}

float subtracao(float n1, float n2) {
	int result = 0;
	result = n1 - n2;
	return result;
}

float multiplicacao(float n1, float n2) {
	int result = 0;
	result = n1 * n2;
	return result;
}

float divisao(float n1, float n2) {
	int result = 0;
	result = n1 / n2;
	return result;
}

/*
	-->  $  -->  Entrada processamento saída
	 
	Modularização (subprogramas)
		Variável de escopo: Funciona somente dentro do escopo da função
	
		Funções - Existem 3 momentos
			1 = Declaração
			2 = Prototipação
			3 = Chamada
	
	-- Repetição --
	
	For
		Trabalha mais com iterações, números e inteiros
		A variável controladora de forma invariável sempre vai ser inteiro
	
	While
		Maior controle no tipo da variável
		
	do..while
		Trata a questão de um grande loop
		
	
	-- Condicional --	
	
	switch case
		Bom para situações predefinidas
		Usado muito em menus
*/
