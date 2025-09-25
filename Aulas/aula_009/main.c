#include <stdio.h>

int main() {
// Exemplo de uso de 'do while'
	char continuar;
	
	do{
		printf("Deseja continuar (S/N)?: ");
		scanf(" %c",&continuar);
	}while(continuar == 'S');
	
// int i = 0;
// i = 15;
//	do{
//		printf("%d\n",i);
//		i++;	
//	}while(i < 11);
//	
//	printf("%d",i);

// int i = 0;	
// printf("for de 1 a 10");
//	for(i = 1;i <= 10;i++){
//		printf("%d\n",i);
//	}

// int i = 0;
// printf("while de 1 a 10");
//	i = 1;
//	while(i <= 10){
//		printf("%d\n",i);
//		i++;
//	}

//	int valor = 0, i = 0, j = 0;
//	
//	printf("Insira o valor: ");
//	scanf("%d",&valor);
//	
//	i = 1;
//	j = valor;
//	while(i <= valor){
//		printf("%d\t",i);
//		if(j % 15 == 0){
//			printf("M15\n");
//		} else{
//			if(j % 10 == 0){
//				printf("M10\n");
//			} else{
//				if(j % 5 == 0){
//					printf("M5\n");
//				} else{
//					printf("%d\n",j);
//				}
//			}
//		}
//		i++;
//		j--;
//	}
	return 0;
}
