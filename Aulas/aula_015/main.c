#include <stdio.h>
#include <string.h>

//int main() {
//	struct Produto{
//		char desc[30];
//		float valor;
//	};
//	
//	struct Produto produto1, produto2;
//	
//	strcpy(produto1.desc, "Margarina boa");
//	produto1.valor = 15.4;
//	
//	strcpy(produto2.desc, "Margarina boa demais");
//	produto2.valor = 19.2;
//	
//	printf("--------------------------------\n");
//	
//	printf("\nProduto1: %s | Valor: %.2f", produto1.desc,produto1.valor);
//	printf("\nProduto2: %s | Valor: %.2f\n", produto2.desc,produto2.valor);
//	return 0;
//}

//int main() {
//	struct End{
//		char endereco[30];
//		int numero;
//		char complemento[30];
//		char cep[10];
//	};
//	
//	struct Aluno{
//		char nome[20];
//		int idade;
//		struct End end;
//	};
//	
//	struct Aluno aluno;
//	aluno.idade = 45;
//	aluno.end.numero = 100;
//	
//	printf("Informe seu cep: ");
//	scanf("%s", &aluno.end.cep);
//	
//	printf("Cep informado: %s", aluno.end.cep);
//	
//	return 0;
//}

// Vetores de Structs 

int main() {	
	struct Aluno{
		char nome[20];
		int idade;
	};
	
	struct Aluno aluno[20]; // Vetor de alunos
	
	printf("Informe o nome: ");
	scanf(" %s", &aluno[0].nome);
	
	printf("Informe sua idade: ");
	scanf("%d", &aluno[0].idade);
	
	printf("Nome: %s\n", aluno[0].nome);
	printf("Idade: %d", aluno[0].idade);
	
	return 0;
}

/*
	# Estruturas de Dados compostas Heterogêneas
	
		-- Structs --
		
			Estrutura:
				struct Aluno{
					char nome[20];
					int idade;
				};
			
			struct Aluno aluno;
			
			aluno.idade = 15;
			
			scanf("%d", &aluno.idade);
			
			printf("Idade de (aluno): %d", aluno.idade);
*/
