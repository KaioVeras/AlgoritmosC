#include <stdio.h>

int main() {

	int n1 = 0, n2 = 0;
	char op;

	printf("--------------------------------\n");
	printf("---------- Calculadora ---------\n");
	printf("--------------------------------\n\n");

	printf("Informe um valor para N1: ");
	scanf("%d", &n1);

	printf("Informe uma operação: ");
	scanf(" %c", &op);

	printf("Informe um valor para N2: ");
	scanf("%d", &n2);

	printf("\n--------------------------------\n");

	switch(op) {
		case '+':
			printf("Resultado: %d", n1 + n2);
			break;

		case '-':
			printf("Resultado: %d", n1 - n2);
			break;

		case '*':
			printf("Resultado: %d", n1 * n2);
			break;

		case '/':
			if(n2 == 0) {
				printf("Operação Inválida");
			} else {
				printf("Resultado: %d", n1 / n2);
			}
			break;

		case '%':
			printf("Resultado: %d", n1 % n2);
			break;

		default:
			printf("Operação Inválida");
	}

	printf("\n--------------------------------\n");

	return 0;
}


/*
	Estruturas de decis�o
		if
		if/else
		switch/case
			switch() {
				case:   
				break;
				
				case: 
				break;
				
				default: 
			}
			
			
	Estruturas de repeti��o
		for 
		while
		do..while
*/

