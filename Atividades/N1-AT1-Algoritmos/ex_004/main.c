#include <stdio.h> //Importa a biblioteca stdio.h para entrada e sa�da de dados
#define PI 3.14159 // Define o valor de PI como 3.14159

// 4. Coment�rios
int main() // fun��o principal 
{
	float raio, area; // declara��o da vari�vel raio e area do tipo float
	printf("Raio: "); // Label para o scanf do raio
	scanf("%f", &raio); // Entrada de dados na vari�vel raio
	area = PI * raio * raio; // Atribui a vari�vel area uma equa��o para calcular a area
	printf("Area = %.2f\n", area); // Vai imprimir o valor da area
	return 0; // Finaliza o c�digo
}
