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
	--- Variáveis ---
	
	Def: Alocação de espaço em memória
	
	- Ciclos:
		1. Declaração (Nome e Tipo). Ex: int idade;
		2. Atribuição de valores, a primeira atribuição chamamos de inicialização. Ex: idade = 5;
	
	- Nome (identificador) 
		- Não pode ter espaço ou caractere especial
		- Não pode começar com número
		- Não pode utilizar nomes de palavras reservadas
		- Convenção de C: Não se deve utilizar letra maiúscula
		- Exemplo: nome_completo
		
	- Tipo
		- int: número inteiro (-35, 5, 8, 9090)
		- char: um caractere, é utilizado com '' ('a', 'X', '5', '@', '!')
		- float: número com ponto, ocupa metade do espaço de memória do double (-85.5678)
		- double: mais de seis casas decimais (85.567891011)
	
	- Valor
	
	
	- Especificadores: 
	 - int: %d || %i
	 - char: %c
	 - float:  %f
	 - double: %lf
*/
