#include <stdio.h>
#include <string.h>

int main() {
	char nome1[20], nome2[20];
	int i = 0;
	
	printf("Insira o Nome1: ");
	scanf("%[^\n]s",&nome1);
	
	fflush(stdin);
	printf("Insira o Nome2: ");
	scanf("%[^\n]s",&nome2);
	
	printf("Nome1: %s | Nome2: %s\n",nome1,nome2);
	printf("------------------------\n");
	
	for(i = 0;i < strlen(nome2);i++){
		printf("%c\n",nome2[i]);
	}
	printf("------------------------\n");
	
	printf("%s\n",strcat(nome1,nome2));
	printf("------------------------\n");
	
	printf("%d",strcmp(nome1,"MacroMatheus"));
	return 0;
}

/*
String = Vetor de Caracteres
	<string.h>
		strcpy(variavel, "string"); -  Estrutura | Atribui a variavel a string passada
		strlen(variavel) - retorna o tamanho da string
		strcat(variavel1, variavel2) - concatena as duas variaveis em uma só, por exemplo: strcpy(variavel1, "Diego"), strcpy(variavel2, "Rod"), depois de
		passar na função a varialvel1 vai ser "DiegoRod"
		strcmp(variavel, "Diego"); - Diferença entre variavel e Diego, se forem diferentes vai retornar 1, se for igual vai ser 0
		stricmp(variavel, "Diego); - Indiferença entre variavel e Diego
	<ctype.h>
		toupper(letra) - Transforma o char em maiusculo
		tolower(letra) - Transforma o char em minusculo
	
	strcpy(nome1, "Diego");
	printf("%c",nome1[2]); - Imprimira o caractere da terceira posição, então "e"
	
	for(i = 0; i < 5; i++){
		printf("%c\n",nome1[i]);
	}	

	strlen(nome1) - retorna 5
	----------------------------------------------------------
	Elabore um programa onde o usuário informará nome1 e nome2
	
	Ao final apresente:
	
	nome1: diego - nome2: maria
	----------------------------------------------------------
*/

