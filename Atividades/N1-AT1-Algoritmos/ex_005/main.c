#include <stdio.h>

// 5. Operadores
int main() {
	int mesAtual = 0, mesAnterior = 0;
	float consumo, fatura;
		
	printf("--------------------------------\n");
	printf("  C O N S U M O   M E N S A L\n");
	printf("--------------------------------\n\n");
	
	printf("--Consumo--\n");
	printf("Mes atual: ");
	scanf("%d", &mesAtual);
	
	printf("Mes anterior: ");
	scanf("%d", &mesAnterior);
	
	printf("\n--Resultado--\n");
	consumo = mesAtual - mesAnterior;
	fatura = consumo * 0.75;

	printf("Consumo: %.1f kWh\n", consumo);
	printf("Fatura: R$ %.2f", fatura);
	
	return 0;
}
