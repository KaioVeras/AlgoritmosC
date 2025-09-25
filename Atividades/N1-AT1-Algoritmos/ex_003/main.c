#include <stdio.h>

// 3. Variáveis
int main() {
	float n1 = 7.5, n2 = 6.5, n3 = 8.9;
	char nome[5] = "Kaio";
	float media = (n1 + n2 + n3) / 3;
	
	printf("--------------------------------\n");
	printf("     D A D O S   A L U N O\n");
	printf("--------------------------------\n\n");
	
	
	printf("Nome do aluno: %s\n\n", nome);
	printf("-Notas-\n");
	printf("N1: %.1f\n", n1);	
	printf("N2: %.1f\n", n2);	
	printf("N3: %.1f\n\n", n3);
	printf("Media: %.1f", media);	
	
	return 0;
}
