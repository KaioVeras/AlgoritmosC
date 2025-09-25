#include <stdio.h>


// 1. Entrada e saída
int main() {
	char medicamento[30];
	int codigo = 0;
	float valorUni;
	
	printf("--------------------------------\n");
	printf("        F A R M A C I A\n");
	printf("--------------------------------\n\n");
	
	printf("Medicamento: ");
	scanf(" %s", &medicamento);
	
	printf("Codigo: ");
	scanf(" %d", &codigo);
	
	printf("Valor unitario: R$ ");
	scanf("%f", &valorUni);
	
	printf("\n--------------------------------\n\n");
	
	printf("Medicamento: %s\n", medicamento);
	printf("Codigo: %d\n", codigo);
	printf("Valor Unitario: %.2f\n", valorUni);
	return 0;
}
