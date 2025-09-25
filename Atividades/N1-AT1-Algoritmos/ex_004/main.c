#include <stdio.h> //Importa a biblioteca stdio.h para entrada e saída de dados
#define PI 3.14159 // Define o valor de PI como 3.14159

// 4. Comentários
int main() // função principal 
{
	float raio, area; // declaração da variável raio e area do tipo float
	printf("Raio: "); // Label para o scanf do raio
	scanf("%f", &raio); // Entrada de dados na variável raio
	area = PI * raio * raio; // Atribui a variável area uma equação para calcular a area
	printf("Area = %.2f\n", area); // Vai imprimir o valor da area
	return 0; // Finaliza o código
}
