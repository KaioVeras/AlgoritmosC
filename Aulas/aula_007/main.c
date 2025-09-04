#include <stdio.h>

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

    if(op == '-') {
        printf("Resultado: %d", n1 - n2);
        return 0;
    }
    
    if(op == '+'){
    	printf("Resultado: %d", n1 + n2);
    	return 0;
	}
	
	if(op == '*'){
    	printf("Resultado: %d", n1 * n2);
    	return 0;
	}
	
	if(op == '/'){
    	printf("Resultado: %d", n1 / n2);
    	return 0;
	}
	
	if(op == '%'){
    	printf("Resultado: %d", n1 % n2);
    	return 0;
	}
	
	else {
		printf("Operacao nao encontrada");
	}

    return 0;
}

/*
	Estruturas de decisão
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
			
			
	Estruturas de repetição
		for 
		while
		do..while
*/

