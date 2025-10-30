/*
	Elabore um programa com base nas structs abaixo, receba o cadastro de 50 alunos
	e apresente ao final a maior idade identificada, e os nomes que tenham a respectiva
	idade.
*/

#include <stdio.h>
#define TAM 3

void cabecalho();

int main() {
	int i = 0;
	int maior_idade = 0;	
	
	struct Endereco{
		char logradouro[20];
		int numero;
		char cep[10];
	};
	
	struct Aluno{
		char nome[30];
		int idade;
		struct Endereco endereco[2];
		int notas[3];
	};
	
	struct Aluno aluno[TAM];
	
	cabecalho();
	
	for(i = 0; i < TAM; i++) {
		printf("Nome aluno %d: ", i + 1);
		scanf("%s", &aluno[i].nome);
		
		printf("Idade aluno %d: ", i + 1);
		scanf("%d", &aluno[i].idade);
		
		if(aluno[i].idade > maior_idade) {
			maior_idade = aluno[i].idade;
		}
		
		printf("\n");
	}
	
	printf("\n--------------------------------\n");
	
	printf("Maior idade: %d\n", maior_idade);
	
	printf("--------------------------------\n\n");
	
	printf("Alunos com a maior idade:\n\n");
	for(i = 0; i < TAM; i++) {
		if(aluno[i].idade == maior_idade) {
			printf("%s\n", aluno[i].nome);
		}
	}
	return 0;
}

void cabecalho() {
	printf("--------------------------------\n");
	printf("       C A D A S T R O\n");
	printf("--------------------------------\n\n");
}

