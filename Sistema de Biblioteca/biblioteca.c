// SISTEMA DE BIBLIOTECA COM STRUCT/ENCAPSULAMENTO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// CONSTANTES GLOBAIS
#define MAX_LIVROS 50       
#define MAX_EMPRESTIMOS 100  
#define TAMANHO_STRING 100  

//=================== DEFINIÇÃO DAS ESTRUTURAS ============
struct livro {
    char nome[TAMANHO_STRING];
    char autor[TAMANHO_STRING];
    char editora[TAMANHO_STRING];
    int edicao;
    int disponivel; 
};

struct emprestimo {
    int indiceLivro;  
    char nomeUsuario[TAMANHO_STRING];
};

// Função para limpar o buffer do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

// --------- FUNÇÕES DE OPERAÇÃO ---------
void cadastrarLivro(struct livro *biblioteca, int *totalLivros) {
    if (*totalLivros < MAX_LIVROS) {
        printf("Digite o nome do livro: ");
        fgets(biblioteca[*totalLivros].nome, TAMANHO_STRING, stdin);

        printf("Digite o nome do autor: ");
        fgets(biblioteca[*totalLivros].autor, TAMANHO_STRING, stdin);

        printf("Digite o nome da editora: ");
        fgets(biblioteca[*totalLivros].editora, TAMANHO_STRING, stdin);

        // Remove '\n'
        biblioteca[*totalLivros].nome[strcspn(biblioteca[*totalLivros].nome, "\n")] = '\0';
        biblioteca[*totalLivros].autor[strcspn(biblioteca[*totalLivros].autor, "\n")] = '\0';
        biblioteca[*totalLivros].editora[strcspn(biblioteca[*totalLivros].editora, "\n")] = '\0';

        printf("Digite o número da edição: ");
        scanf("%d", &biblioteca[*totalLivros].edicao);
        limparBuffer();

        biblioteca[*totalLivros].disponivel = 1; 
        (*totalLivros)++; 
        printf("Livro armazenado com sucesso!\n");
    } else {
        printf("Biblioteca cheia, impossível cadastrar mais.\n");
    }
    printf("Pressione Enter para continuar...\n");
    getchar();
}

void listarLivros(struct livro *biblioteca, int totalLivros) {
    printf("====== LISTA DE LIVROS CADASTRADOS ======\n");

    if (totalLivros == 0) {
        printf("Nenhum livro cadastrado.\n");
    } else {
        for (int i = 0; i < totalLivros; i++) {
            printf("\nLIVRO %d\n", i + 1);
            printf("NOME: %s\n", biblioteca[i].nome);
            printf("AUTOR: %s\n", biblioteca[i].autor);
            printf("EDITORA: %s\n", biblioteca[i].editora);
            printf("EDIÇÃO: %d\n", biblioteca[i].edicao);
            printf("DISPONÍVEL: %s\n", biblioteca[i].disponivel ? "Sim" : "Não");
        }
        printf("========================================\n");
    }
    printf("\nPressione Enter para continuar...");
    getchar();
}

void realizarEmprestimo(struct livro *biblioteca, struct emprestimo *emprestimos, int totalLivros, int *totalEmprestimos) {
    printf("----REALIZAR EMPRESTIMO------\n");
    if (*totalEmprestimos >= MAX_EMPRESTIMOS) {
        printf("Limite de emprestimos atingido.\n");
    } else {
        printf("Livros disponíveis:\n");
        int disponiveis = 0;
        for (int i = 0; i < totalLivros; i++) {
            if (biblioteca[i].disponivel) {
                printf("%d - %s\n", i + 1, biblioteca[i].nome);
                disponiveis++;
            }
        }

        if (disponiveis == 0) {
            printf("Nenhum livro disponível para empréstimos.\n");
        } else {
            printf("\nDigite o número do livro que deseja emprestar: ");
            int numLivro;
            scanf("%d", &numLivro);
            limparBuffer();

            int indice = numLivro - 1;

            if (indice >= 0 && indice < totalLivros && biblioteca[indice].disponivel) {
                printf("\nDigite o nome do usuário que está pegando o livro: ");
                fgets(emprestimos[*totalEmprestimos].nomeUsuario, TAMANHO_STRING, stdin);
                emprestimos[*totalEmprestimos].nomeUsuario[
                    strcspn(emprestimos[*totalEmprestimos].nomeUsuario, "\n")
                ] = '\0';

                emprestimos[*totalEmprestimos].indiceLivro = indice;
                biblioteca[indice].disponivel = 0;

                (*totalEmprestimos)++;
                printf("Empréstimo realizado com sucesso!\n");
            } else {
                printf("Número de livro inválido ou indisponível.\n");
            }
        }
    }
    printf("\nPressione Enter para continuar...");
    getchar();
}

void listarEmprestimos(struct livro *biblioteca, struct emprestimo *emprestimos, int totalEmprestimos) {
    printf("--- Lista de Emprestimos ---\n\n"); 
    if (totalEmprestimos == 0) {
        printf("Nenhum emprestimo realizado.\n");
    } else {
        for (int i = 0; i < totalEmprestimos; i++) {
            int indiceLivro = emprestimos[i].indiceLivro;
            printf("--------------------------------\n");
            printf("EMPRESTIMO %d\n", i + 1);
            printf("Livro: %s\n", biblioteca[indiceLivro].nome);
            printf("Usuario: %s\n", emprestimos[i].nomeUsuario);
        }      
        printf("----------------------\n");
    }
    printf("\nPressione Enter para continuar...");
    getchar();
}

void devolverLivro(struct livro *biblioteca, struct emprestimo *emprestimos, int *totalEmprestimos) {
    printf("---- DEVOLVER LIVRO ----\n");

    if (*totalEmprestimos == 0) {
        printf("Nenhum empréstimo registrado.\n");
    } else {
        for (int i = 0; i < *totalEmprestimos; i++) {
            int indiceLivro = emprestimos[i].indiceLivro;
            printf("%d - %s (Usuário: %s)\n", i + 1, biblioteca[indiceLivro].nome, emprestimos[i].nomeUsuario);
        }

        printf("\nDigite o número do empréstimo que deseja devolver: ");
        int numEmp;
        scanf("%d", &numEmp);
        limparBuffer();

        int indice = numEmp - 1;

        if (indice >= 0 && indice < *totalEmprestimos) {
            int indiceLivro = emprestimos[indice].indiceLivro;
            biblioteca[indiceLivro].disponivel = 1;

            for (int j = indice; j < *totalEmprestimos - 1; j++) {
                emprestimos[j] = emprestimos[j + 1];
            }

            (*totalEmprestimos)--;
            printf("Livro devolvido com sucesso!\n");
        } else {
            printf("Número de empréstimo inválido.\n");
        }
    }

    printf("\nPressione Enter para continuar...");
    getchar();
}

//===========FUNÇÃO PRINCIPAL==========
int main() {
    struct livro *biblioteca = calloc(MAX_LIVROS, sizeof(struct livro));
    struct emprestimo *emprestimos = malloc(MAX_EMPRESTIMOS * sizeof(struct emprestimo));

    if (biblioteca == NULL || emprestimos == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    int totalLivros = 0;
    int totalEmprestimos = 0;
    int opcao;

    do {
        printf("\n=== BIBLIOTECA ===\n");
        printf("1. Cadastrar livro\n");
        printf("2. Listar livros\n");
        printf("3. Realizar emprestimo\n");
        printf("4. Listar emprestimos\n");
        printf("5. Devolver livro\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao) {
            case 1: cadastrarLivro(biblioteca, &totalLivros); break;
            case 2: listarLivros(biblioteca, totalLivros); break;
            case 3: realizarEmprestimo(biblioteca, emprestimos, totalLivros, &totalEmprestimos); break;
            case 4: listarEmprestimos(biblioteca, emprestimos, totalEmprestimos); break;
            case 5: devolverLivro(biblioteca, emprestimos, &totalEmprestimos); break;
            case 0: printf("Saindo do sistema...\n"); break;
            default: 
                printf("\nOpção inválida.\n");
                printf("Pressione Enter para continuar...\n");
                getchar();
                break;
        }
    } while (opcao != 0);

    free(biblioteca);
    free(emprestimos);

    printf("Memória liberada com sucesso!\n");
    return 0;
}
