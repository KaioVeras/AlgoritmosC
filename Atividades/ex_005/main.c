#include <stdio.h>

// Calculadora usando switch/case

int main() {
    int n1 = 0, n2 = 0;
    char op;

    printf("--------------------------------\n");
    printf("---------- Calculadora ---------\n");
    printf("--------------------------------\n\n");

    printf("Informe N1: ");
    scanf("%d", &n1);

    printf("Informe OP: ");
    scanf(" %c", &op);

    printf("Informe N2: ");
    scanf("%d", &n2);
    
    printf("\n--------------------------------\n");

    switch(op) {
    	case '-':
			printf("Resultado: %d", n1 - n2); 
    	break;
    	
    	case '+':
			printf("Resultado: %d", n1 + n2); 
    	break;
    	
    	case '*':
			printf("Resultado: %d", n1 * n2); 
    	break;
    	
    	case '/':
			if(n2 == 0){
				printf("Invalido");
			} else {
				printf("Resultado: %d", n1 / n2); 
			}
    	break;
    	
    	case '%':
			printf("Resultado: %d", n1 % n2); 
    	break;
    	
    	default: 
    		printf("Operacao invalida");
	}

    return 0;
}

/*
	Quando se usa switch/case?
		Quando temos situações predefinidas
*/
