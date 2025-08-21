#include <stdio.h>

int main() {
	char nome[20];
	int idade = 0;
	char status;
	float altura;
	char email[25];
	double salario;
	
	printf("        &&& &&  & &&\n");
    printf("    && &\\/&\\|& ()|/ @, &&\n");
    printf("    &\\/(/&/&||/& /_/)_&/_&\n");
    printf(" &() &\\/&|()|/&\\/ '%\" & ()\n");
    printf("&_\\_&&_\\ |& |&&/&__%_/_& &&\n");
    printf("&&   && & &| &| /& & % ()& /&&\n");
    printf(" ()&_---()&\\&\\|&&-&&--%---()~\n");
    printf("     &&     \\|||\n");
    printf("             |||\n");
    printf("             |||\n");
    printf("             |||\n");
    printf("       , -=-~  .-^- _\n\n");
	
	printf("--------------------------------\n");
	printf("         C A D A S T R O\n");
	printf("--------------------------------\n\n");
	
	printf("Nome: ");
	scanf("%s", &nome);
	
	printf("Idade: ");
	scanf("%d", &idade);
	
	printf("Status (a ou i): ");
	scanf(" %c", &status);
	
	printf("Altura: ");
	scanf("%f", &altura);
	
	printf("Email: ");
	scanf("%s", &email);
	
	printf("Salario: ");
	scanf("%lf", &salario);
	
	printf("\n--------------------------------\n\n");
	
	printf("Nome informado: %s\n", nome);
	printf("Idade: %d\n", idade);
	printf("Status: %c\n", status);
	printf("Altura: %.2f \n", altura);
	printf("E-mail: %s\n", email);
	printf("Salario: %lf\n", salario);
	return 0;
}

/*
	=== Exemplo de valores para cada tipo de variável ===
	
		int idade
		char estado
		float altura
		double criptomoeda
		
	=== String ===
	
		String
		char *nome* [];
		String não é um tipo primitivo
		
	=== Especificador de String ===
	
		Especificador = %s
	
	=== Obeservações === 
	
	"&" usado para dizer 
	
	
*/
