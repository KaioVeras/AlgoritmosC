#include <stdio.h>

int main() {
	int idade = 0;
	idade = 10;
	
	printf("Idade: %d\n", idade);
	printf("Idade: %d %d\n", idade, 450);
	printf("Idade atual: %d, em 10 anos %d", idade, idade + 10);
	
	return 0;
}

/*
	--- Vari�veis ---
	
	Def: Aloca��o de espa�o em mem�ria
	
	- Ciclos:
		1. Declara��o (Nome e Tipo). Ex: int idade;
		2. Atribui��o de valores, a primeira atribui��o chamamos de inicializa��o. Ex: idade = 5;
	
	- Nome (identificador) 
		- N�o pode ter espa�o ou caractere especial
		- N�o pode come�ar com n�mero
		- N�o pode utilizar nomes de palavras reservadas
		- Conven��o de C: N�o se deve utilizar letra mai�scula
		- Exemplo: nome_completo
		
	- Tipo
		- int: n�mero inteiro (-35, 5, 8, 9090)
		- char: um caractere, � utilizado com '' ('a', 'X', '5', '@', '!')
		- float: n�mero com ponto, ocupa metade do espa�o de mem�ria do double (-85.5678)
		- double: mais de seis casas decimais (85.567891011)
	
	- Valor
	
	
	- Especificadores: 
	 - int: %d || %i
	 - char: %c
	 - float:  %f
	 - double: %lf
*/
