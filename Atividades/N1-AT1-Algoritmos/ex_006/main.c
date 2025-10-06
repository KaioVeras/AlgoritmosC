#include <stdio.h>

// 6. Operadores
int main() {
	float valorBruto, valorLiquido, taxaJuros = 0.05;
	int meses = 0;

	printf("--------------------------------\n");
	printf("   V A L O R   L I Q U I D O\n");
	printf("--------------------------------\n\n");

	printf("--Emprestimo--\n");
	printf("Valor bruto: ");
	scanf("%f", &valorBruto);

	printf("Meses: ");
	scanf("%d", &meses);

	valorLiquido = valorBruto + (valorBruto * taxaJuros * meses);

	printf("\n\n--Resultado--\n");
	printf("Valor Bruto: R$ %.2f\n", valorBruto);
	printf("Quantidade de meses: %d meses\n", meses);
	printf("Valor Liquido: R$ %.2f\n", valorLiquido);

	return 0;
}
