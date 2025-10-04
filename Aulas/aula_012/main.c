/* 
Elabore um programa onde o usuário informará 5 notas, após receber 
as notas, as mesmas serão apresentadas na ordem inversa à informada
*/

//#include <stdio.h>
//#define TAM 5
//
//int main() {
//	
//	float notas[TAM];
//	int i = 0;
//	
//	printf("--------------------------------\n");
//	printf("         N  O  T  A  S\n");
//	printf("--------------------------------\n\n");
//	
//	for(i=0;i<TAM;i++) {
//		printf("Informe o valor para a nota %d: ", i+1);
//		scanf("%f", &notas[i]);
//	}
//	
//	printf("\n\n--------------------------------\n\n");
//	
//	for(i = TAM - 1; i >= 0; i--) {
//		printf("Nota %d: %.1f\n", i+1, notas[i]);
//	}
//	
//	return 0;
//}

// Vetores - Estrutura de dados composta homogênea

//#include <stdio.h>
//#define TAM 5
//
//int main() {
//	float notas[TAM];
//	int i = 0;
//	char saida;
//	
//	for(i = 0; i < TAM; i++) {
//		printf("Informe um valor para a nota %d: ", i + 1);
//		scanf("%f", &notas[i]);
//		
//		printf("Deseja sair? (S/N): ");
//		scanf(" %c", &saida);
//		
//		if(saida == 'S') {
//			printf("Fim do programa!");
//			return 0;
//		}
//	}
//	
//	return 0;
//}


#include <stdio.h>
#define TAM 10

int main() {
	float notas[TAM], media;
	char saida;
	int i = 0;
	
	printf("--------------------------------\n");
	printf("         M  E  D  I  A\n");
	printf("--------------------------------\n\n");
	
	for(i = 0; i < TAM; i++) {
		printf("Informe uma nota para %d: ", i + 1);
		scanf("%f", &notas[i]);
		
		printf("Deseja sair? (S/N): ");
		scanf(" %c", &saida);
		
		if(saida == 'S') {
			printf("Fim do programa!");
			return 0;
		}
		
		media += notas[i] / TAM;
	}
	
	printf("\n--------------------------------\n");
	printf("Media: %.1f", media);
	printf("\n--------------------------------\n\n");
	
	for(i = 0; i < TAM; i++) {
		if(notas[i] >= 7) {
			printf("Aluno %d | Aprovado\n", i + 1);
		}else{
			printf("Aluno %d | Reprovado\n", i + 1);
		}
	}
	
	return 0;
}




