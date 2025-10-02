//#include <stdio.h>
//
//int main() {
//	float n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, media;
//	
//	printf("--------------------------------\n");
//	printf("         M  E  D  I  A\n");
//	printf("--------------------------------\n\n");
//	
//	printf("Nota 1: ");
//	scanf("%f", &n1);
//	
//	printf("Nota 2: ");
//	scanf("%f", &n2);
//	
//	printf("Nota 3: ");
//	scanf("%f", &n3);
//	
//	printf("Nota 4: ");
//	scanf("%f", &n4);
//	
//	printf("Nota 5: ");
//	scanf("%f", &n5);
//	
//	printf("Nota 6: ");
//	scanf("%f", &n6);
//	
//	printf("Nota 7: ");
//	scanf("%f", &n7);
//	
//	printf("Nota 8: ");
//	scanf("%f", &n8);
//	
//	printf("Nota 9: ");
//	scanf("%f", &n9);
//	
//	printf("Nota 10: ");
//	scanf("%f", &n10);
//		
//	media = (n1 + n2 + n3 + n4 + n5 + n6 + n7 + n8 + n9 + n10) / 10;
//	
//	printf("\n\nMedia: %.2f", media);
//	return 0;
//}


#include <stdio.h>
#define TAM 5

int main() {
	float notas[TAM];
	float media;
	int i = 0;
	
	printf("--------------------------------\n");
	printf("           M  E  D  I  A\n");
	printf("--------------------------------\n\n");
	
	for(i = 0; i < TAM; i++) {
		printf("Informe o valor para a nota %d: ", i + 1);
		scanf("%f", &notas[i]);
		media += notas[i] / TAM; 
	}
	printf("\n--------------------------------\n");
	
	for(i = 0; i < 5; i++) {
		printf("Nota %d: %.1f\n", i + 1, notas[i]);
	}
	
	printf("--------------------------------\n");
			
	printf("Media: %.1f", media);
		
	return 0;
}








