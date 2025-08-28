#include <stdio.h>

int main() {
	int n1 = 0, n2 =0;
	
	printf("--- Comparador ---\n\n");
	
	printf("N1: ");
	scanf("%d", &n1);
	
	printf("N2: ");
	scanf("%d", &n2);
	
	if(n1 == n2) {
		printf("\nn1 == n2");
	} else {
		if(n1 > n2) {
			if(n1%2 == 0){
				printf("\nN1: par!");
			} else {
				printf("\nN1: impar!");
			}	
		} else {
			if(n2%2 == 0){
				printf("\nN2: par!");
			} else {
				printf("\nN2: impar!");
			}
		}
	}	
	
	
	return 0;
}

/*
	Operadores?
		Aritméticos?
		+ - * / %
		
		Atribuição?
		=
		
		Comparação?
		== != > < >= <=
		
		Lógicos?
		&& || !
*/
