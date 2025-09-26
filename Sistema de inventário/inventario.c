
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// =======================
// Definição da struct Item
// Cada item possui nome, tipo e quantidade
// =======================
struct Item {
    char nome[30];
    char tipo[20];
    int quantidade;
};

// =======================
// VERSÃO VETOR (lista sequencial)
// =======================
struct Item mochilaVetor[10]; // vetor com até 10 itens
int totalItensVetor = 0;      // controla quantos itens cadastrados
int comparacoesSeqVetor = 0;  // contador para busca sequencial
int comparacoesBinVetor = 0;  // contador para busca binária

// Função para listar itens do vetor
void listarItensVetor() {
    if (totalItensVetor == 0) {
        printf("Mochila (vetor) vazia.\n");
        return;
    }
    printf("\nItens na mochila (vetor):\n");
    for (int i = 0; i < totalItensVetor; i++) {
        printf("Nome: %s | Tipo: %s | Quantidade: %d\n",
               mochilaVetor[i].nome, mochilaVetor[i].tipo, mochilaVetor[i].quantidade);
    }
}

// Inserir item no vetor
void inserirItemVetor() {
    if (totalItensVetor >= 10) {
        printf("Mochila (vetor) cheia!\n");
        return;
    }

    struct Item novo;

    printf("Digite o nome do item: ");
    fgets(novo.nome, 30, stdin);
    novo.nome[strcspn(novo.nome, "\n")] = 0;

    printf("Digite o tipo do item (arma, municao, cura): ");
    fgets(novo.tipo, 20, stdin);
    novo.tipo[strcspn(novo.tipo, "\n")] = 0;

    printf("Digite a quantidade: ");
    scanf("%d", &novo.quantidade);
    getchar(); // limpa buffer

    mochilaVetor[totalItensVetor] = novo;
    totalItensVetor++;

    printf("Item adicionado ao vetor!\n");
    listarItensVetor();
}

// Remover item do vetor pelo nome
void removerItemVetor() {
    if (totalItensVetor == 0) {
        printf("Mochila (vetor) vazia.\n");
        return;
    }

    char nomeRemover[30];
    printf("Digite o nome do item para remover: ");
    fgets(nomeRemover, 30, stdin);
    nomeRemover[strcspn(nomeRemover, "\n")] = 0;

    for (int i = 0; i < totalItensVetor; i++) {
        if (strcmp(mochilaVetor[i].nome, nomeRemover) == 0) {
            // desloca os elementos para trás
            for (int j = i; j < totalItensVetor - 1; j++)
                mochilaVetor[j] = mochilaVetor[j + 1];
            totalItensVetor--;
            printf("Item removido do vetor!\n");
            listarItensVetor();
            return;
        }
    }
    printf("Item nao encontrado.\n");
}

// Ordenação do vetor pelo nome (Bubble Sort)
void ordenarVetor() {
    for (int i = 0; i < totalItensVetor - 1; i++) {
        for (int j = 0; j < totalItensVetor - i - 1; j++) {
            if (strcmp(mochilaVetor[j].nome, mochilaVetor[j + 1].nome) > 0) {
                struct Item temp = mochilaVetor[j];
                mochilaVetor[j] = mochilaVetor[j + 1];
                mochilaVetor[j + 1] = temp;
            }
        }
    }
    printf("Vetor ordenado por nome.\n");
}

// Busca sequencial no vetor
void buscarSequencialVetor(char nomeBusca[]) {
    comparacoesSeqVetor = 0;
    for (int i = 0; i < totalItensVetor; i++) {
        comparacoesSeqVetor++;
        if (strcmp(mochilaVetor[i].nome, nomeBusca) == 0) {
            printf("Item encontrado (sequencial): %s | Tipo: %s | Quantidade: %d\n",
                   mochilaVetor[i].nome, mochilaVetor[i].tipo, mochilaVetor[i].quantidade);
            printf("Comparacoes realizadas: %d\n", comparacoesSeqVetor);
            return;
        }
    }
    printf("Item nao encontrado na busca sequencial. Comparacoes: %d\n", comparacoesSeqVetor);
}

// Busca binária no vetor (deve estar ordenado)
void buscarBinariaVetor(char nomeBusca[]) {
    comparacoesBinVetor = 0;
    int inicio = 0, fim = totalItensVetor - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        comparacoesBinVetor++;
        int cmp = strcmp(mochilaVetor[meio].nome, nomeBusca);
        if (cmp == 0) {
            printf("Item encontrado (binaria): %s | Tipo: %s | Quantidade: %d\n",
                   mochilaVetor[meio].nome, mochilaVetor[meio].tipo, mochilaVetor[meio].quantidade);
            printf("Comparacoes realizadas: %d\n", comparacoesBinVetor);
            return;
        } else if (cmp < 0) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    printf("Item nao encontrado na busca binaria. Comparacoes: %d\n", comparacoesBinVetor);
}

// =======================
// VERSÃO LISTA ENCADEADA
// =======================

// Estrutura No para lista encadeada
struct No {
    struct Item dados;
    struct No* proximo;
};

struct No* cabeca = NULL; // cabeça da lista

// Contador para busca sequencial na lista
int comparacoesSeqLista = 0;

// Inserir item na lista encadeada
void inserirItemLista() {
    struct No* novo = (struct No*)malloc(sizeof(struct No));
    if (!novo) {
        printf("Erro ao alocar memoria!\n");
        return;
    }

    printf("Digite o nome do item: ");
    fgets(novo->dados.nome, 30, stdin);
    novo->dados.nome[strcspn(novo->dados.nome, "\n")] = 0;

    printf("Digite o tipo do item (arma, municao, cura): ");
    fgets(novo->dados.tipo, 20, stdin);
    novo->dados.tipo[strcspn(novo->dados.tipo, "\n")] = 0;

    printf("Digite a quantidade: ");
    scanf("%d", &novo->dados.quantidade);
    getchar();

    novo->proximo = cabeca;
    cabeca = novo;

    printf("Item adicionado na lista encadeada!\n");
}

// Remover item da lista pelo nome
void removerItemLista() {
    if (!cabeca) {
        printf("Lista vazia.\n");
        return;
    }

    char nomeRemover[30];
    printf("Digite o nome do item para remover: ");
    fgets(nomeRemover, 30, stdin);
    nomeRemover[strcspn(nomeRemover, "\n")] = 0;

    struct No* atual = cabeca;
    struct No* anterior = NULL;

    while (atual) {
        if (strcmp(atual->dados.nome, nomeRemover) == 0) {
            if (anterior)
                anterior->proximo = atual->proximo;
            else
                cabeca = atual->proximo;
            free(atual);
            printf("Item removido da lista encadeada!\n");
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    printf("Item nao encontrado na lista.\n");
}

// Listar itens da lista encadeada
void listarItensLista() {
    if (!cabeca) {
        printf("Lista vazia.\n");
        return;
    }

    struct No* atual = cabeca;
    printf("\nItens na lista encadeada:\n");
    while (atual) {
        printf("Nome: %s | Tipo: %s | Quantidade: %d\n",
               atual->dados.nome, atual->dados.tipo, atual->dados.quantidade);
        atual = atual->proximo;
    }
}

// Buscar item sequencial na lista
void buscarSequencialLista(char nomeBusca[]) {
    comparacoesSeqLista = 0;
    struct No* atual = cabeca;
    while (atual) {
        comparacoesSeqLista++;
        if (strcmp(atual->dados.nome, nomeBusca) == 0) {
            printf("Item encontrado (lista): %s | Tipo: %s | Quantidade: %d\n",
                   atual->dados.nome, atual->dados.tipo, atual->dados.quantidade);
            printf("Comparacoes realizadas: %d\n", comparacoesSeqLista);
            return;
        }
        atual = atual->proximo;
    }
    printf("Item nao encontrado na lista. Comparacoes: %d\n", comparacoesSeqLista);
}

// =======================
// FUNÇÃO PRINCIPAL
// =======================
int main() {
    int estrutura, opcao;

    do {
        printf("\n=== Sistema de Mochila ===\n");
        printf("Escolha a estrutura de dados:\n");
        printf("1 - Vetor (lista sequencial)\n");
        printf("2 - Lista encadeada\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &estrutura);
        getchar();

        if (estrutura == 0) break;

        do {
            printf("\n=== Menu ===\n");
            if (estrutura == 1)
                printf("Total de itens no vetor: %d\n", totalItensVetor);
            else
            {
                // Contando itens na lista
                int count = 0;
                struct No* atual = cabeca;
                while (atual) { count++; atual = atual->proximo; }
                printf("Total de itens na lista: %d\n", count);
            }

            printf("1 - Inserir item\n");
            printf("2 - Remover item\n");
            printf("3 - Listar itens\n");
            if (estrutura == 1) {
                printf("4 - Buscar sequencial\n");
                printf("5 - Buscar binaria\n");
            } else {
                printf("4 - Buscar sequencial\n");
            }
            printf("0 - Voltar\n");
            printf("Opcao: ");
            scanf("%d", &opcao);
            getchar();

            char nomeBusca[30];

            switch (opcao) {
                case 1:
                    if (estrutura == 1) inserirItemVetor();
                    else inserirItemLista();
                    break;
                case 2:
                    if (estrutura == 1) removerItemVetor();
                    else removerItemLista();
                    break;
                case 3:
                    if (estrutura == 1) listarItensVetor();
                    else listarItensLista();
                    break;
                case 4:
                    printf("Digite o nome do item para buscar: ");
                    fgets(nomeBusca, 30, stdin);
                    nomeBusca[strcspn(nomeBusca, "\n")] = 0;
                    if (estrutura == 1)
