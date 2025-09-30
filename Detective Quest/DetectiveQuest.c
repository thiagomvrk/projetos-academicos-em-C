#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_HASH 10

// -----------------------------
// Struct para representar as salas da mansão
// -----------------------------
typedef struct Sala {
    char nome[50];
    struct Sala *esq;
    struct Sala *dir;
} Sala;

// -----------------------------
// Struct para representar as pistas na BST
// -----------------------------
typedef struct Pista {
    char nome[100];
    struct Pista *esq;
    struct Pista *dir;
} Pista;

// -----------------------------
// Struct para tabela hash (associa pista -> suspeito)
// -----------------------------
typedef struct HashNode {
    char pista[100];
    char suspeito[50];
    struct HashNode *prox;
} HashNode;

HashNode* tabelaHash[TAM_HASH];

// -----------------------------
// Funções auxiliares
// -----------------------------

// Criar sala da mansão
Sala* criarSala(const char *nome) {
    Sala *nova = (Sala*) malloc(sizeof(Sala));
    strcpy(nova->nome, nome);
    nova->esq = nova->dir = NULL;
    return nova;
}

// Criar nó de pista
Pista* criarPista(const char *nome) {
    Pista *nova = (Pista*) malloc(sizeof(Pista));
    strcpy(nova->nome, nome);
    nova->esq = nova->dir = NULL;
    return nova;
}

// Inserir pista em BST (ordenada)
Pista* inserirPista(Pista *raiz, const char *nome) {
    if (raiz == NULL) {
        return criarPista(nome);
    }
    if (strcmp(nome, raiz->nome) < 0) {
        raiz->esq = inserirPista(raiz->esq, nome);
    } else if (strcmp(nome, raiz->nome) > 0) {
        raiz->dir = inserirPista(raiz->dir, nome);
    }
    return raiz;
}

// Exibir pistas em ordem (in-order traversal)
void mostrarPistas(Pista *raiz) {
    if (raiz != NULL) {
        mostrarPistas(raiz->esq);
        printf("- %s\n", raiz->nome);
        mostrarPistas(raiz->dir);
    }
}

// Hash simples para strings
int hash(const char *chave) {
    int soma = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        soma += chave[i];
    }
    return soma % TAM_HASH;
}

// Inserir par pista -> suspeito na hash
void inserirNaHash(const char *pista, const char *suspeito) {
    int h = hash(pista);
    HashNode *novo = (HashNode*) malloc(sizeof(HashNode));
    strcpy(novo->pista, pista);
    strcpy(novo->suspeito, suspeito);
    novo->prox = tabelaHash[h];
    tabelaHash[h] = novo;
}

// Procurar suspeito por pista
char* encontrarSuspeito(const char *pista) {
    int h = hash(pista);
    HashNode *atual = tabelaHash[h];
    while (atual != NULL) {
        if (strcmp(atual->pista, pista) == 0) {
            return atual->suspeito;
        }
        atual = atual->prox;
    }
    return NULL;
}

// -----------------------------
// Pistas associadas às salas
// -----------------------------
const char* pistaDaSala(const char *nomeSala) {
    if (strcmp(nomeSala, "Cozinha") == 0) return "Faca suja de sangue";
    if (strcmp(nomeSala, "Biblioteca") == 0) return "Livro rasgado com anotações";
    if (strcmp(nomeSala, "Sala de Estar") == 0) return "Taça quebrada";
    if (strcmp(nomeSala, "Jardim") == 0) return "Pegadas recentes na terra";
    if (strcmp(nomeSala, "Quarto") == 0) return "Joia desaparecida";
    return NULL;
}

// -----------------------------
// Exploração das salas
// -----------------------------
Pista* explorarSalas(Sala *atual, Pista *raizPistas) {
    char escolha;
    while (1) {
        printf("\nVocê está na: %s\n", atual->nome);

        // Verifica se há pista na sala
        const char *pista = pistaDaSala(atual->nome);
        if (pista != NULL) {
            printf("Você encontrou uma pista: %s\n", pista);
            raizPistas = inserirPista(raizPistas, pista);
        }

        // Se for folha (sem caminhos), retorna
        if (atual->esq == NULL && atual->dir == NULL) {
            printf("Fim do caminho nesta sala.\n");
            return raizPistas;
        }

        printf("Escolha um caminho: (e) esquerda, (d) direita, (s) sair: ");
        scanf(" %c", &escolha);

        if (escolha == 'e' && atual->esq != NULL) {
            atual = atual->esq;
        } else if (escolha == 'd' && atual->dir != NULL) {
            atual = atual->dir;
        } else if (escolha == 's') {
            return raizPistas;
        } else {
            printf("Caminho inválido!\n");
        }
    }
}

// -----------------------------
// Verificação final do suspeito
// -----------------------------
void verificarSuspeitoFinal(Pista *raiz) {
    char acusado[50];
    int cont = 0;

    printf("\n=== FASE FINAL ===\n");
    printf("Pistas coletadas:\n");
    mostrarPistas(raiz);

    printf("\nDigite o nome do suspeito que você acusa: ");
    scanf(" %[^\n]", acusado);

    // Percorre a BST de pistas e conta quantas levam ao acusado
    if (raiz == NULL) return;
    if (encontrarSuspeito(raiz->nome) != NULL && strcmp(encontrarSuspeito(raiz->nome), acusado) == 0) {
        cont++;
    }
    if (raiz->esq) verificarSuspeitoFinal(raiz->esq);
    if (raiz->dir) verificarSuspeitoFinal(raiz->dir);

    if (cont >= 2) {
        printf("\nAcusação correta! O suspeito %s foi condenado.\n", acusado);
    } else {
        printf("\nAcusação falhou! Não há pistas suficientes contra %s.\n", acusado);
    }
}

// -----------------------------
// Main
// -----------------------------
int main() {
    // Montar árvore fixa da mansão
    Sala *hall = criarSala("Hall de Entrada");
    hall->esq = criarSala("Sala de Estar");
    hall->dir = criarSala("Biblioteca");
    hall->esq->esq = criarSala("Cozinha");
    hall->esq->dir = criarSala("Jardim");
    hall->dir->dir = criarSala("Quarto");

    // Inserir pistas e suspeitos na tabela hash
    inserirNaHash("Faca suja de sangue", "Mordomo");
    inserirNaHash("Livro rasgado com anotações", "Bibliotecária");
    inserirNaHash("Taça quebrada", "Socialite");
    inserirNaHash("Pegadas recentes na terra", "Jardineiro");
    inserirNaHash("Joia desaparecida", "Herdeira");

    // Exploração
    Pista *raizPistas = NULL;
    raizPistas = explorarSalas(hall, raizPistas);

    // Julgamento final
    verificarSuspeitoFinal(raizPistas);

    return 0;
}
