#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_REGISTROS 50
#define MAX_NOME 100
#define MAX_SIGLA 3

typedef struct {
    int id;
    char sigla[MAX_SIGLA];
    char nome[MAX_NOME];
} UF;

typedef struct {
    int id;
    char nome[MAX_NOME];
    int id_uf;
} Cidade;

typedef struct {
    int id;
    char nome[MAX_NOME];
} Categoria;

typedef struct {
    int id;
    char nome[MAX_NOME];
} Marca;

typedef struct {
    int id;
    char nome[MAX_NOME];
    int id_cidade;
} Fornecedor;

typedef struct {
    int id;
    char nome[MAX_NOME];
    int quantidade;
    float valor;
    int id_categoria;
    int id_marca;
    int id_fornecedor;
} Produto;

UF g_ufs[MAX_REGISTROS];
int g_count_uf = 0;
int g_id_counter_uf = 1;

Cidade g_cidades[MAX_REGISTROS];
int g_count_cidade = 0;
int g_id_counter_cidade = 1;

Categoria g_categorias[MAX_REGISTROS];
int g_count_categoria = 0;
int g_id_counter_categoria = 1;

Marca g_marcas[MAX_REGISTROS];
int g_count_marca = 0;
int g_id_counter_marca = 1;

Fornecedor g_fornecedores[MAX_REGISTROS];
int g_count_fornecedor = 0;
int g_id_counter_fornecedor = 1;

Produto g_produtos[MAX_REGISTROS];
int g_count_produto = 0;
int g_id_counter_produto = 1;

void limpar_buffer_teclado();
void limpar_tela();
int le_valida_opcao_menu(int min, int max);
void le_valida_string(char* prompt, char* destino, int max_len);
int le_valida_int(char* prompt);
float le_valida_float(char* prompt);
int buscar_por_id(int id, void* array, int count, size_t struct_size);

void manter_categoria();
void manter_fornecedor();
void manter_produto();
void manter_marca();
void manter_uf();
void manter_cidade();

void criar_categoria();
void listar_categorias();
void atualizar_categoria();
void deletar_categoria();

void criar_uf();
void listar_ufs();
void atualizar_uf();
void deletar_uf();
void bubble_sort_ufs(UF* array_copia, int n, int ascendente);

void criar_cidade();
void listar_cidades();
void listar_cidades_recursivo(int index);
void atualizar_cidade();
void deletar_cidade();

void criar_marca();
void listar_marcas();
void atualizar_marca();
void deletar_marca();

void criar_fornecedor();
void listar_fornecedores();
void atualizar_fornecedor();
void deletar_fornecedor();

void criar_produto();
void listar_produtos();
void atualizar_produto();
void deletar_produto();

void menu_relatorios();
void relatorio_produtos_marca_cidade();
void relatorio_quantidade_cidades();
void relatorio_ufs_maior_valor_produto();
void relatorio_fornecedores_cidade();

int main() {
    int opcao;
    do {
        limpar_tela();
        printf("\n--- Controle de Estoque Simples ---\n");
        printf("(1) Manter Categoria\n");
        printf("(2) Manter Fornecedor\n");
        printf("(3) Manter Produto\n");
        printf("(4) Manter Marca\n");
        printf("(5) Manter UF\n");
        printf("(6) Manter Cidade\n");
        printf("(7) Relatorios\n");
        printf("(8) Sair\n");
        printf("-----------------------------------\n");
        
        opcao = le_valida_opcao_menu(1, 8);

        switch (opcao) {
            case 1: manter_categoria(); break;
            case 2: manter_fornecedor(); break;
            case 3: manter_produto(); break;
            case 4: manter_marca(); break;
            case 5: manter_uf(); break;
            case 6: manter_cidade(); break;
            case 7: menu_relatorios(); break;
            case 8: printf("Saindo do sistema. Ate logo!\n"); break;
        }
    } while (opcao != 8);

    return 0;
}

void limpar_tela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void limpar_buffer_teclado() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int le_valida_opcao_menu(int min, int max) {
    int opcao;
    char buffer[100];

    while (1) {
        printf("Escolha uma opcao (%d-%d): ", min, max);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%d", &opcao) == 1) {
                if (opcao >= min && opcao <= max) {
                    return opcao;
                } else {
                    printf("Opcao invalida. Digite um numero entre %d e %d.\n", min, max);
                }
            } else {
                printf("Entrada invalida. Digite apenas numeros.\n");
            }
        }
    }
}

void le_valida_string(char* prompt, char* destino, int max_len) {
    printf("%s", prompt);
    if (fgets(destino, max_len, stdin) != NULL) {
        destino[strcspn(destino, "\n")] = '\0';
    } else {
        limpar_buffer_teclado();
    }
}

int le_valida_int(char* prompt) {
    int valor;
    char buffer[100];
    
    while (1) {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%d", &valor) == 1) {
                return valor;
            } else {
                printf("Entrada invalida. Digite um numero inteiro.\n");
            }
        }
    }
}

float le_valida_float(char* prompt) {
    float valor;
    char buffer[100];

    while (1) {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%f", &valor) == 1) {
                return valor;
            } else {
                printf("Entrada invalida. Digite um numero (ex: 10.50).\n");
            }
        }
    }
}

int find_uf_by_id(int id) {
    for (int i = 0; i < g_count_uf; i++) {
        if (g_ufs[i].id == id) return i;
    }
    return -1;
}

int find_cidade_by_id(int id) {
    for (int i = 0; i < g_count_cidade; i++) {
        if (g_cidades[i].id == id) return i;
    }
    return -1;
}

int find_categoria_by_id(int id) {
    for (int i = 0; i < g_count_categoria; i++) {
        if (g_categorias[i].id == id) return i;
    }
    return -1;
}

int find_marca_by_id(int id) {
    for (int i = 0; i < g_count_marca; i++) {
        if (g_marcas[i].id == id) return i;
    }
    return -1;
}

int find_fornecedor_by_id(int id) {
    for (int i = 0; i < g_count_fornecedor; i++) {
        if (g_fornecedores[i].id == id) return i;
    }
    return -1;
}

void menu_crud(char* titulo, void (*criar)(void), void (*listar)(void), void (*atualizar)(void), void (*deletar)(void)) {
    int opcao;
    do {
        limpar_tela();
        printf("\n--- Manter %s ---\n", titulo);
        printf("(1) Criar\n");
        printf("(2) Listar\n");
        printf("(3) Atualizar\n");
        printf("(4) Deletar\n");
        printf("(5) Voltar ao Menu Principal\n");
        
        opcao = le_valida_opcao_menu(1, 5);

        switch (opcao) {
            case 1: criar(); break;
            case 2: listar(); break;
            case 3: atualizar(); break;
            case 4: deletar(); break;
            case 5: printf("Voltando...\n"); break;
        }
    } while (opcao != 5);
}

void manter_categoria() {
    menu_crud("Categoria", criar_categoria, listar_categorias, atualizar_categoria, deletar_categoria);
}

void manter_fornecedor() {
    menu_crud("Fornecedor", criar_fornecedor, listar_fornecedores, atualizar_fornecedor, deletar_fornecedor);
}

void manter_produto() {
    menu_crud("Produto", criar_produto, listar_produtos, atualizar_produto, deletar_produto);
}

void manter_marca() {
    menu_crud("Marca", criar_marca, listar_marcas, atualizar_marca, deletar_marca);
}

void manter_uf() {
    menu_crud("UF", criar_uf, listar_ufs, atualizar_uf, deletar_uf);
}

void manter_cidade() {
    menu_crud("Cidade", criar_cidade, listar_cidades, atualizar_cidade, deletar_cidade);
}

void criar_categoria() {
    limpar_tela();
    if (g_count_categoria >= MAX_REGISTROS) {
        printf("Erro: Limite de categorias atingido!\n");
        return;
    }
    
    printf("\n--- Criar Categoria ---\n");
    Categoria nova_cat;
    nova_cat.id = g_id_counter_categoria++;
    
    le_valida_string("Nome da Categoria: ", nova_cat.nome, MAX_NOME);

    g_categorias[g_count_categoria] = nova_cat;
    g_count_categoria++;

    printf("Categoria '%s' (ID: %d) criada com sucesso!\n", nova_cat.nome, nova_cat.id);
    printf("\nPressione ENTER para continuar...");
    getchar();
}

void listar_categorias() {
    limpar_tela();
    printf("\n--- Lista de Categorias ---\n");
    if (g_count_categoria == 0) {
        printf("Nenhuma categoria cadastrada.\n");
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }
    for (int i = 0; i < g_count_categoria; i++) {
        printf("ID: %d | Nome: %s\n", g_categorias[i].id, g_categorias[i].nome);
    }
    printf("\nPressione ENTER para continuar...");
    getchar();
}

void atualizar_categoria() {
    limpar_tela();
    listar_categorias();
    int id = le_valida_int("Digite o ID da categoria que deseja atualizar: ");
    
    int index = find_categoria_by_id(id);
    if (index == -1) {
        printf("Erro: Categoria com ID %d nao encontrada.\n", id);
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }

    printf("Atualizando categoria: %s\n", g_categorias[index].nome);
    le_valida_string("Novo nome: ", g_categorias[index].nome, MAX_NOME);
    
    printf("Categoria atualizada com sucesso!\n");
    printf("\nPressione ENTER para continuar...");
    getchar();
}

void deletar_categoria() {
    limpar_tela();
    listar_categorias();
    int id = le_valida_int("Digite o ID da categoria que deseja DELETAR: ");

    int index = find_categoria_by_id(id);
    if (index == -1) {
        printf("Erro: Categoria com ID %d nao encontrada.\n", id);
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }

    printf("Deletando categoria: %s\n", g_categorias[index].nome);

    for (int i = index; i < g_count_categoria - 1; i++) {
        g_categorias[i] = g_categorias[i + 1];
    }
    g_count_categoria--;

    printf("Categoria deletada com sucesso.\n");
    printf("\nPressione ENTER para continuar...");
    getchar();
}

void criar_uf() {
    limpar_tela();
    if (g_count_uf >= MAX_REGISTROS) {
        printf("Erro: Limite de UFs atingido!\n");
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }

    printf("\n--- Criar UF ---\n");
    UF nova_uf;
    nova_uf.id = g_id_counter_uf++;
    
    le_valida_string("Sigla (ex: SP): ", nova_uf.sigla, MAX_SIGLA);
    le_valida_string("Nome (ex: Sao Paulo): ", nova_uf.nome, MAX_NOME);

    g_ufs[g_count_uf] = nova_uf;
    g_count_uf++;

    printf("UF '%s' (ID: %d) criada com sucesso!\n", nova_uf.nome, nova_uf.id);
    printf("\nPressione ENTER para continuar...");
    getchar();
}

void listar_ufs() {
    limpar_tela();
    printf("\n--- Lista de UFs ---\n");
    if (g_count_uf == 0) {
        printf("Nenhuma UF cadastrada.\n");
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }

    printf("Como deseja ordenar a lista?\n");
    printf("(1) A-Z (por Sigla)\n");
    printf("(2) Z-A (por Sigla)\n");
    printf("(3) Ordem de Cadastro\n");
    int ordem = le_valida_opcao_menu(1, 3);

    if (ordem == 3) {
        for (int i = 0; i < g_count_uf; i++) {
            printf("ID: %d | Sigla: %s | Nome: %s\n", g_ufs[i].id, g_ufs[i].sigla, g_ufs[i].nome);
        }
    } else {
        UF ufs_copia[MAX_REGISTROS];
        memcpy(ufs_copia, g_ufs, g_count_uf * sizeof(UF));

        bubble_sort_ufs(ufs_copia, g_count_uf, (ordem == 1));

        for (int i = 0; i < g_count_uf; i++) {
            printf("ID: %d | Sigla: %s | Nome: %s\n", ufs_copia[i].id, ufs_copia[i].sigla, ufs_copia[i].nome);
        }
    }
    printf("\nPressione ENTER para continuar...");
    getchar();
}

void bubble_sort_ufs(UF* array_copia, int n, int ascendente) {
    int i, j;
    UF temp;
    int trocou;

    printf("...Ordenando com Bubble Sort...\n");

    for (i = 0; i < n - 1; i++) {
        trocou = 0;
        for (j = 0; j < n - i - 1; j++) {
            int comparacao = strcmp(array_copia[j].sigla, array_copia[j + 1].sigla);

            if ((ascendente && comparacao > 0) || (!ascendente && comparacao < 0)) {
                temp = array_copia[j];
                array_copia[j] = array_copia[j + 1];
                array_copia[j + 1] = temp;
                trocou = 1;
            }
        }
        if (trocou == 0) break;
    }
}

void atualizar_uf() {
    limpar_tela();
    listar_ufs();
    int id = le_valida_int("Digite o ID da UF que deseja atualizar: ");
    
    int index = find_uf_by_id(id);
    if (index == -1) {
        printf("Erro: UF com ID %d nao encontrada.\n", id);
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }

    printf("Atualizando UF: %s\n", g_ufs[index].nome);
    le_valida_string("Nova Sigla: ", g_ufs[index].sigla, MAX_SIGLA);
    le_valida_string("Novo Nome: ", g_ufs[index].nome, MAX_NOME);
    
    printf("UF atualizada com sucesso!\n");
    printf("\nPressione ENTER para continuar...");
    getchar();
}

void deletar_uf() {
    limpar_tela();
    listar_ufs();
    int id = le_valida_int("Digite o ID da UF que deseja DELETAR: ");

    int index = find_uf_by_id(id);
    if (index == -1) {
        printf("Erro: UF com ID %d nao encontrada.\n", id);
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }

    printf("Deletando UF: %s\n", g_ufs[index].nome);

    for (int i = index; i < g_count_uf - 1; i++) {
        g_ufs[i] = g_ufs[i + 1];
    }
    g_count_uf--;

    printf("UF deletada com sucesso.\n");
    printf("\nPressione ENTER para continuar...");
    getchar();
}

void criar_cidade() {
    limpar_tela();
    if (g_count_cidade >= MAX_REGISTROS) {
        printf("Erro: Limite de cidades atingido!\n");
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }
    
    printf("\n--- Criar Cidade ---\n");

    if (g_count_uf == 0) {
        printf("Erro: Nenhuma UF cadastrada. Cadastre uma UF primeiro.\n");
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }
    
    listar_ufs();
    int id_uf_escolhida = le_valida_int("Digite o ID da UF desta cidade: ");
    int index_uf = find_uf_by_id(id_uf_escolhida);

    if (index_uf == -1) {
        printf("Erro: UF com ID %d nao existe!\n", id_uf_escolhida);
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }

    Cidade nova_cid;
    nova_cid.id = g_id_counter_cidade++;
    nova_cid.id_uf = id_uf_escolhida;
    
    le_valida_string("Nome da Cidade: ", nova_cid.nome, MAX_NOME);

    g_cidades[g_count_cidade] = nova_cid;
    g_count_cidade++;

    printf("Cidade '%s' (ID: %d) criada com sucesso!\n", nova_cid.nome, nova_cid.id);
    printf("\nPressione ENTER para continuar...");
    getchar();
}

void listar_cidades() {
    limpar_tela();
    printf("\n--- Lista de Cidades (Recursiva) ---\n");
    if (g_count_cidade == 0) {
        printf("Nenhuma cidade cadastrada.\n");
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }
    listar_cidades_recursivo(0);
    printf("\nPressione ENTER para continuar...");
    getchar();
}

void listar_cidades_recursivo(int index) {
    if (index >= g_count_cidade) {
        return;
    }

    int id_uf_da_cidade = g_cidades[index].id_uf;
    int index_uf = find_uf_by_id(id_uf_da_cidade);
    char sigla_uf[MAX_SIGLA] = "N/A";

    if (index_uf != -1) {
        strcpy(sigla_uf, g_ufs[index_uf].sigla);
    }
    
    printf("ID: %d | Nome: %s (UF: %s)\n", 
           g_cidades[index].id, 
           g_cidades[index].nome, 
           sigla_uf);

    listar_cidades_recursivo(index + 1);
}

void atualizar_cidade() {
    limpar_tela();
    listar_cidades();
    int id = le_valida_int("Digite o ID da cidade que deseja atualizar: ");
    
    int index = find_cidade_by_id(id);
    if (index == -1) {
        printf("Erro: Cidade com ID %d nao encontrada.\n", id);
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }

    printf("Atualizando cidade: %s\n", g_cidades[index].nome);
    le_valida_string("Novo nome: ", g_cidades[index].nome, MAX_NOME);

    listar_ufs();
    int id_uf_escolhida = le_valida_int("Digite o NOVO ID da UF desta cidade: ");
    int index_uf = find_uf_by_id(id_uf_escolhida);

    if (index_uf == -1) {
        printf("Erro: UF com ID %d nao existe! Atualizacao cancelada.\n", id_uf_escolhida);
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }
    
    g_cidades[index].id_uf = id_uf_escolhida;
    printf("Cidade atualizada com sucesso!\n");
    printf("\nPressione ENTER para continuar...");
    getchar();
}

void deletar_cidade() {
    limpar_tela();
    listar_cidades();
    int id = le_valida_int("Digite o ID da cidade que deseja DELETAR: ");

    int index = find_cidade_by_id(id);
    if (index == -1) {
        printf("Erro: Cidade com ID %d nao encontrada.\n", id);
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }
    
    printf("Deletando cidade: %s\n", g_cidades[index].nome);

    for (int i = index; i < g_count_cidade - 1; i++) {
        g_cidades[i] = g_cidades[i + 1];
    }
    g_count_cidade--;

    printf("Cidade deletada com sucesso.\n");
    printf("\nPressione ENTER para continuar...");
    getchar();
}

void criar_marca() {
    limpar_tela();
    if (g_count_marca >= MAX_REGISTROS) {
        printf("Limite atingido.\n");
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }
    Marca nova;
    nova.id = g_id_counter_marca++;
    le_valida_string("Nome da Marca: ", nova.nome, MAX_NOME);
    g_marcas[g_count_marca++] = nova;
    printf("Marca criada (ID: %d)\n", nova.id);
    printf("\nPressione ENTER para continuar...");
    getchar();
}

void listar_marcas() {
    limpar_tela();
    if (g_count_marca == 0) {
        printf("Nenhuma marca cadastrada.\n");
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }
    for (int i = 0; i < g_count_marca; i++) {
        printf("ID: %d | Nome: %s\n", g_marcas[i].id, g_marcas[i].nome);
    }
    printf("\nPressione ENTER para continuar...");
    getchar();
}

void atualizar_marca() {
    limpar_tela();
    listar_marcas();
    int id = le_valida_int("Digite o ID da marca que deseja atualizar: ");
    
    int index = find_marca_by_id(id);
    if (index == -1) {
        printf("Erro: Marca com ID %d nao encontrada.\n", id);
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }

    printf("Atualizando marca: %s\n", g_marcas[index].nome);
    le_valida_string("Novo nome: ", g_marcas[index].nome, MAX_NOME);
    
    printf("Marca atualizada com sucesso!\n");
    printf("\nPressione ENTER para continuar...");
    getchar();
}

void deletar_marca() {
    limpar_tela();
    listar_marcas();
    int id = le_valida_int("Digite o ID da marca que deseja DELETAR: ");

    int index = find_marca_by_id(id);
    if (index == -1) {
        printf("Erro: Marca com ID %d nao encontrada.\n", id);
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }

    printf("Deletando marca: %s\n", g_marcas[index].nome);

    for (int i = index; i < g_count_marca - 1; i++) {
        g_marcas[i] = g_marcas[i + 1];
    }
    g_count_marca--;

    printf("Marca deletada com sucesso.\n");
    printf("\nPressione ENTER para continuar...");
    getchar();
}

void criar_fornecedor() {
    limpar_tela();
    if (g_count_fornecedor >= MAX_REGISTROS) {
        printf("Limite atingido.\n");
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }
    if (g_count_cidade == 0) {
        printf("Cadastre uma Cidade primeiro.\n");
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }

    Fornecedor novo;
    novo.id = g_id_counter_fornecedor++;
    le_valida_string("Nome do Fornecedor: ", novo.nome, MAX_NOME);

    listar_cidades();
    int id_cid = le_valida_int("ID da Cidade do Fornecedor: ");
    if (find_cidade_by_id(id_cid) == -1) {
        printf("Cidade nao encontrada.\n");
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }
    novo.id_cidade = id_cid;
    g_fornecedores[g_count_fornecedor++] = novo;
    printf("Fornecedor criado (ID: %d)\n", novo.id);
    printf("\nPressione ENTER para continuar...");
    getchar();
}

void listar_fornecedores() {
    limpar_tela();
    if (g_count_fornecedor == 0) {
        printf("Nenhum fornecedor cadastrado.\n");
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }
    for (int i = 0; i < g_count_fornecedor; i++) {
        int idx_cid = find_cidade_by_id(g_fornecedores[i].id_cidade);
        char* nome_cid = (idx_cid != -1) ? g_cidades[idx_cid].nome : "N/A";
        printf("ID: %d | Nome: %s | Cidade: %s\n", g_fornecedores[i].id, g_fornecedores[i].nome, nome_cid);
    }
    printf("\nPressione ENTER para continuar...");
    getchar();
}

void atualizar_fornecedor() {
    limpar_tela();
    listar_fornecedores();
    int id = le_valida_int("Digite o ID do fornecedor que deseja atualizar: ");
    
    int index = find_fornecedor_by_id(id);
    if (index == -1) {
        printf("Erro: Fornecedor com ID %d nao encontrado.\n", id);
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }

    printf("Atualizando fornecedor: %s\n", g_fornecedores[index].nome);
    le_valida_string("Novo nome: ", g_fornecedores[index].nome, MAX_NOME);

    listar_cidades();
    int id_cid = le_valida_int("Novo ID da Cidade: ");
    if (find_cidade_by_id(id_cid) == -1) {
        printf("Cidade nao encontrada. Atualizacao cancelada.\n");
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }
    
    g_fornecedores[index].id_cidade = id_cid;
    printf("Fornecedor atualizado com sucesso!\n");
    printf("\nPressione ENTER para continuar...");
    getchar();
}

void deletar_fornecedor() {
    limpar_tela();
    listar_fornecedores();
    int id = le_valida_int("Digite o ID do fornecedor que deseja DELETAR: ");

    int index = find_fornecedor_by_id(id);
    if (index == -1) {
        printf("Erro: Fornecedor com ID %d nao encontrado.\n", id);
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }

    printf("Deletando fornecedor: %s\n", g_fornecedores[index].nome);

    for (int i = index; i < g_count_fornecedor - 1; i++) {
        g_fornecedores[i] = g_fornecedores[i + 1];
    }
    g_count_fornecedor--;

    printf("Fornecedor deletado com sucesso.\n");
    printf("\nPressione ENTER para continuar...");
    getchar();
}

void criar_produto() {
    limpar_tela();
    if (g_count_produto >= MAX_REGISTROS) {
        printf("Limite atingido.\n");
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }

    if (g_count_categoria == 0 || g_count_marca == 0 || g_count_fornecedor == 0) {
        printf("Erro: Para criar um Produto, voce precisa ter pelo menos:\n");
        printf("- 1 Categoria cadastrada\n");
        printf("- 1 Marca cadastrada\n");
        printf("- 1 Fornecedor cadastrado\n");
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }

    Produto novo;
    novo.id = g_id_counter_produto++;
    le_valida_string("Nome do Produto: ", novo.nome, MAX_NOME);
    novo.valor = le_valida_float("Valor (R$): ");
    novo.quantidade = le_valida_int("Quantidade em Estoque: ");

    listar_categorias();
    int id_cat = le_valida_int("ID da Categoria: ");
    if (find_categoria_by_id(id_cat) == -1) {
        printf("Categoria nao existe.\n");
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }
    novo.id_categoria = id_cat;

    listar_marcas();
    int id_mar = le_valida_int("ID da Marca: ");
    if (find_marca_by_id(id_mar) == -1) {
        printf("Marca nao existe.\n");
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }
    novo.id_marca = id_mar;

    listar_fornecedores();
    int id_for = le_valida_int("ID do Fornecedor: ");
    if (find_fornecedor_by_id(id_for) == -1) {
        printf("Fornecedor nao existe.\n");
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }
    novo.id_fornecedor = id_for;

    g_produtos[g_count_produto++] = novo;
    printf("Produto '%s' criado (ID: %d)\n", novo.nome, novo.id);
    printf("\nPressione ENTER para continuar...");
    getchar();
}

void listar_produtos() {
    limpar_tela();
    if (g_count_produto == 0) {
        printf("Nenhum produto cadastrado.\n");
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }
    printf("\n--- Lista de Produtos ---\n");
    for (int i = 0; i < g_count_produto; i++) {
        int idx_cat = find_categoria_by_id(g_produtos[i].id_categoria);
        char* nome_cat = (idx_cat != -1) ? g_categorias[idx_cat].nome : "N/A";
        
        int idx_mar = find_marca_by_id(g_produtos[i].id_marca);
        char* nome_mar = (idx_mar != -1) ? g_marcas[idx_mar].nome : "N/A";

        printf("ID: %d | Nome: %s\n", g_produtos[i].id, g_produtos[i].nome);
        printf("  > Qtd: %d | Valor: R$ %.2f\n", g_produtos[i].quantidade, g_produtos[i].valor);
        printf("  > Categoria: %s | Marca: %s\n", nome_cat, nome_mar);
        printf("----------------------------------\n");
    }
    printf("\nPressione ENTER para continuar...");
    getchar();
}

void atualizar_produto() {
    limpar_tela();
    listar_produtos();
    int id = le_valida_int("Digite o ID do produto que deseja atualizar: ");
    
    int index = -1;
    for (int i = 0; i < g_count_produto; i++) {
        if (g_produtos[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Erro: Produto com ID %d nao encontrado.\n", id);
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }

    printf("Atualizando produto: %s\n", g_produtos[index].nome);
    le_valida_string("Novo nome: ", g_produtos[index].nome, MAX_NOME);
    g_produtos[index].valor = le_valida_float("Novo valor (R$): ");
    g_produtos[index].quantidade = le_valida_int("Nova quantidade: ");

    listar_categorias();
    int id_cat = le_valida_int("Novo ID da Categoria: ");
    if (find_categoria_by_id(id_cat) == -1) {
        printf("Categoria nao existe. Atualizacao cancelada.\n");
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }
    g_produtos[index].id_categoria = id_cat;

    listar_marcas();
    int id_mar = le_valida_int("Novo ID da Marca: ");
    if (find_marca_by_id(id_mar) == -1) {
        printf("Marca nao existe. Atualizacao cancelada.\n");
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }
    g_produtos[index].id_marca = id_mar;

    listar_fornecedores();
    int id_for = le_valida_int("Novo ID do Fornecedor: ");
    if (find_fornecedor_by_id(id_for) == -1) {
        printf("Fornecedor nao existe. Atualizacao cancelada.\n");
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }
    g_produtos[index].id_fornecedor = id_for;

    printf("Produto atualizado com sucesso!\n");
    printf("\nPressione ENTER para continuar...");
    getchar();
}

void deletar_produto() {
    limpar_tela();
    listar_produtos();
    int id = le_valida_int("Digite o ID do produto que deseja DELETAR: ");

    int index = -1;
    for (int i = 0; i < g_count_produto; i++) {
        if (g_produtos[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Erro: Produto com ID %d nao encontrado.\n", id);
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }

    printf("Deletando produto: %s\n", g_produtos[index].nome);

    for (int i = index; i < g_count_produto - 1; i++) {
        g_produtos[i] = g_produtos[i + 1];
    }
    g_count_produto--;

    printf("Produto deletado com sucesso.\n");
    printf("\nPressione ENTER para continuar...");
    getchar();
}

void menu_relatorios() {
    int opcao;
    do {
        limpar_tela();
        printf("\n--- Menu de Relatorios ---\n");
        printf("(1) Quantidade de produtos de determinada marca em uma cidade\n");
        printf("(2) Quantidade de cidades cadastradas\n");
        printf("(3) Quais UFs apresentam os produtos com o maior valor\n");
        printf("(4) Os fornecedores de determinada cidade\n");
        printf("(5) Voltar ao Menu Principal\n");
        
        opcao = le_valida_opcao_menu(1, 5);

        switch (opcao) {
            case 1: relatorio_produtos_marca_cidade(); break;
            case 2: relatorio_quantidade_cidades(); break;
            case 3: relatorio_ufs_maior_valor_produto(); break;
            case 4: relatorio_fornecedores_cidade(); break;
            case 5: printf("Voltando...\n"); break;
        }
    } while (opcao != 5);
}

void relatorio_produtos_marca_cidade() {
    limpar_tela();
    printf("\n--- Relatorio 1: Produtos por Marca/Cidade ---\n");
    listar_marcas();
    int id_marca = le_valida_int("Digite o ID da Marca: ");
    if (find_marca_by_id(id_marca) == -1) {
        printf("Marca nao existe.\n");
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }
    
    listar_cidades();
    int id_cidade = le_valida_int("Digite o ID da Cidade: ");
    if (find_cidade_by_id(id_cidade) == -1) {
        printf("Cidade nao existe.\n");
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }

    int quantidade_total = 0;

    for (int i = 0; i < g_count_produto; i++) {
        if (g_produtos[i].id_marca == id_marca) {
            int idx_forn = find_fornecedor_by_id(g_produtos[i].id_fornecedor);
            
            if (idx_forn != -1) {
                if (g_fornecedores[idx_forn].id_cidade == id_cidade) {
                    quantidade_total += g_produtos[i].quantidade;
                }
            }
        }
    }

    printf("Resultado: Ha %d produtos da marca (ID %d) na cidade (ID %d).\n",
           quantidade_total, id_marca, id_cidade);
    printf("\nPressione ENTER para continuar...");
    getchar();
}

void relatorio_quantidade_cidades() {
    limpar_tela();
    printf("\n--- Relatorio 2: Total de Cidades ---\n");
    printf("Total de Cidades cadastradas: %d\n", g_count_cidade);
    printf("\nPressione ENTER para continuar...");
    getchar();
}

void relatorio_ufs_maior_valor_produto() {
    limpar_tela();
    printf("\n--- Relatorio 3: UFs com Produto(s) de Maior Valor ---\n");
    if (g_count_produto == 0) {
        printf("Nenhum produto cadastrado.\n");
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }

    float maior_valor = 0.0;
    for (int i = 0; i < g_count_produto; i++) {
        if (g_produtos[i].valor > maior_valor) {
            maior_valor = g_produtos[i].valor;
        }
    }
    
    if (maior_valor == 0.0) {
        printf("Nenhum produto com valor cadastrado.\n");
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }

    printf("O maior valor de produto encontrado e: R$ %.2f\n", maior_valor);
    printf("Este valor e encontrado nas seguintes UFs:\n");

    char ufs_encontradas[MAX_REGISTROS][MAX_SIGLA];
    int count_ufs_encontradas = 0;

    for (int i = 0; i < g_count_produto; i++) {
        if (g_produtos[i].valor == maior_valor) {
            int idx_forn = find_fornecedor_by_id(g_produtos[i].id_fornecedor);
            if (idx_forn == -1) continue;

            int idx_cid = find_cidade_by_id(g_fornecedores[idx_forn].id_cidade);
            if (idx_cid == -1) continue;

            int idx_uf = find_uf_by_id(g_cidades[idx_cid].id_uf);
            if (idx_uf == -1) continue;

            int ja_listada = 0;
            for (int k = 0; k < count_ufs_encontradas; k++) {
                if (strcmp(ufs_encontradas[k], g_ufs[idx_uf].sigla) == 0) {
                    ja_listada = 1;
                    break;
                }
            }

            if (!ja_listada) {
                printf("- %s (%s)\n", g_ufs[idx_uf].sigla, g_ufs[idx_uf].nome);
                strcpy(ufs_encontradas[count_ufs_encontradas], g_ufs[idx_uf].sigla);
                count_ufs_encontradas++;
            }
        }
    }
    if (count_ufs_encontradas == 0) {
        printf("Nenhuma UF encontrada (verifique se os cadastros estao completos).\n");
    }
    printf("\nPressione ENTER para continuar...");
    getchar();
}

void relatorio_fornecedores_cidade() {
    limpar_tela();
    printf("\n--- Relatorio 4: Fornecedores por Cidade ---\n");
    listar_cidades();
    int id_cidade = le_valida_int("Digite o ID da Cidade: ");
    
    int index_cidade = find_cidade_by_id(id_cidade);
    if (index_cidade == -1) {
        printf("Cidade nao existe.\n");
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }

    printf("Fornecedores em %s:\n", g_cidades[index_cidade].nome);
    
    int encontrados = 0;
    for (int i = 0; i < g_count_fornecedor; i++) {
        if (g_fornecedores[i].id_cidade == id_cidade) {
            printf("- ID: %d | Nome: %s\n", g_fornecedores[i].id, g_fornecedores[i].nome);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("Nenhum fornecedor encontrado para esta cidade.\n");
    }
    printf("\nPressione ENTER para continuar...");
    getchar();
}