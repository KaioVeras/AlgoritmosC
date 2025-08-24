#include <stdio.h>

int main() {

	char nome_completo[40], cpf[15], rua[20], cidade[15], estado[15], cep[11], data_nascimento[11], tipo_sanguineo[4];
	int idade = 0, numero_casa = 0, numero_sapato = 0, idade_dez_anos = 0;
	float altura;

	printf("==========================\n");
	printf("     C A D A S T R O\n");
	printf("==========================\n\n");

	// Entrada de Dados
	printf("Nome completo: ");
	scanf(" %[^\n]s", &nome_completo);

	printf("CPF: ");
	scanf(" %[^\n]s", &cpf);

	printf("Idade: ");
	scanf("%d", &idade);

	printf("Rua: ");
	scanf(" %[^\n]s", &rua);

	printf("Numero da casa: ");
	scanf("%d", &numero_casa);

	printf("Cidade: ");
	scanf(" %[^\n]s", &cidade);

	printf("Estado: ");
	scanf(" %[^\n]s", &estado);

	printf("CEP: ");
	scanf(" %[^\n]s", &cep);

	printf("Data de nascimento: ");
	scanf(" %[^\n]s", &data_nascimento);

	printf("Numero sapato: ");
	scanf("%d", &numero_sapato);

	printf("Idade em dez anos: ");
	scanf("%d", &idade_dez_anos);

	printf("Altura: ");
	scanf("%f", &altura);

	printf("Tipo sanguineo: ");
	scanf(" %s", &tipo_sanguineo);

	// Saída de Dados
	printf("\n==============================\n");
	printf("D A D O S  I N F O R M A D O S\n");
	printf("==============================\n\n");

	printf("Nome completo: %s\n", nome_completo);
	printf("CPF: %s\n", cpf);
	printf("Idade: %d\n", idade);
	printf("Rua: %s\n", rua);
	printf("Numero da casa: %d\n", numero_casa);
	printf("Cidade: %s\n", cidade);
	printf("Estado: %s\n", estado);
	printf("CEP: %s\n", cep);
	printf("Data de Nascimento: %s\n", data_nascimento);
	printf("Numero sapato: %d\n", numero_sapato);
	printf("Idade em dez anos: %d\n", idade_dez_anos);
	printf("Altura: %.2f\n", altura);
	printf("Tipo sanguineo: %s\n", tipo_sanguineo);

	return 0;
}

/*
1) Entrada e saída de dados, desenvolva o simples cadastro abaixo:

==================
CADASTRO
==================

Nome completo:
CPF:
Idade:
Rua:
Numero da casa:
Cidade:
Estado:
CEP:
Data nascimento:
Numero sapato:
Idade em 10 anos:
Altura:
Tipo sanguineo:

==================
Dados Informados
==================
Nome completo: Joanita Martinez
CPF: 888.123.456-78
Idade: 12
Rua: Rua das flores
Numero da casa: 44
Cidade: Nova Iorque
Estado: Maranhao
CEP: 89.222-000
Data nascimento: 22/08/2013
Numero sapato: 33
Idade em 10 anos: 22
Altura: 1.52
Tipo sanguineo: O+

---------------
*/

/*
	% - significa mod, resto de divisão
	Exemplo: 17 % 5 = 2
	Exemplo: 15 % 5 = 0
*/
