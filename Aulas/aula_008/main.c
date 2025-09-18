#include <stdio.h>

int main() {
	int i = 0, n1 = 0;
	
	printf("--------------------------------\n");
	printf("             F O R\n");
	printf("--------------------------------\n\n");
	
	// Contador 10 até 1
	/*
	for(i = 10; i > 0; i--) {
		printf("Numero: %d\n", i);
	}
	*/
	
	//Contador de 1 até 100 saltando de dois em dois
	/*
	for(i = 1; i <= 100; i+=2) {
		printf("Numero: %d\n", i);
	}
	*/
	
	// Contador de 500 até 10 saltando de três em três
	/*
	for(i = 500; i >= 10; i-=3) {
		printf("Numero: %d\n", i);
	}
	*/
	
	/*
	printf("Infome um numero: ");
	scanf("%d", &n1);
	
	for(i = 1; i <= n1; i++) {
		if(i % 2 == 0) {
			printf("%d - PAR\n", i);
		} else {
			printf("%d - IMPAR\n", i);
		}
	}
	*/
	
	printf("--------------------------------\n");
	printf("           W H I L E\n");
	printf("--------------------------------\n\n");

	/*
	i = 1;	
	while(i <= 10) {
		printf("%d\n", i);
		i++;
	}
	*/
	
	/*
	i = 10;	
	while(i >= 1) {
		printf("%d\n", i);
		i--;
	}*/
	
	/*
	i = 1;	
	while(i <= 100) {
		printf("%d\n", i);
		i+=2;
	}*/
	
	/*
	i = 500;	
	while(i >= 10) {
		printf("%d\n", i);
		i-=3;
	}
	*/
	
	printf("Informe um numero: ");
	scanf("%d", &n1);

	i = 1;	
	while(i <= n1) {
		printf("Numero: %d\n", i);
		i++;
	}
	
	return 0;
}
