#include <stdio.h>

int main() {
	int idade = 0;
	idade = 18;
	
	float altura = 0;
	altura = 1.75;
	
	double peso = 0;
	peso = 82.1234567;
	
	char status = 'A';
	
	float imc = peso / (altura * altura);
	
	printf("Idade: %d\n", idade);
	printf("Altura: %.2f\n", altura);
	printf("Peso: %lf\n", peso);
	printf("Status: %c\n", status);
	printf("Imc: %.2lf\n", imc);
	
	return 0;
}

/*
	-- Desafio --
	
	Desenvolva um programa onde serão declaradas as variáveis abaixo e apresente seus valores na tela
	
	idade (ex: 89)
	altura (ex: 1.87)
	peso (ex: 82.1234567)
	status (ex: 'a')
*/
