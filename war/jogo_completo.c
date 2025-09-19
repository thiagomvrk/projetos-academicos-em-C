#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAMANHO_STRING 100

// STRUCT DO TERRITÓRIO
typedef struct {
    char nome[TAMANHO_STRING];
    char cor[TAMANHO_STRING];
    int tropas;
} Territorio;

// Função para limpar o buffer do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

// Função para cadastrar territórios dinamicamente
Territorio* cadastrarTerritorios(int* totalTerritorios) {
    printf("Quantos territórios serão cadastrados? ");
    scanf("%d", totalTerritorios);
    limparBuffer();

    Territorio* mapa = (Territorio*) calloc(*totalTerritorios, sizeof(Territorio));
    if (!mapa) {
        printf("Erro na alocação de memória.\n");
        exit(1);
    }

    for (int i = 0; i < *totalTerritorios; i++) {
        printf("\n=== Território %d ===\n", i + 1);

        printf("Digite o nome do território: ");
        fgets(mapa[i].nome, TAMANHO_STRING, stdin);
        mapa[i].nome[strcspn(mapa[i].nome, "\n")] = '\0';

        printf("Digite a cor do jogador que controla: ");
        fgets(mapa[i].cor, TAMANHO_STRING, stdin);
        mapa[i].cor[strcspn(mapa[i].cor, "\n")] = '\0';

        printf("Digite o número de tropas: ");
        scanf("%d", &mapa[i].tropas);
        limparBuffer();
    }

    return mapa;
}

// Função para exibir os territórios
void exibirTerritorios(Territorio* mapa, int totalTerritorios) {
    printf("\n=== TERRITÓRIOS ===\n");
    for (int i = 0; i < totalTerritorios; i++) {
        printf("\nTerritório %d\n", i + 1);
        printf("Nome: %s\n", mapa[i].nome);
        printf("Cor do jogador: %s\n", mapa[i].cor);
        printf("Tropas: %d\n", mapa[i].tropas);
    }
}

// Função de ataque
void atacar(Territorio* atacante, Territorio* defensor) {
    if (strcmp(atacante->cor, defensor->cor) == 0) {
        printf("Não é possível atacar um território da mesma cor!\n");
        return;
    }

    int dadoAtacante = rand() % 6 + 1; // 1 a 6
    int dadoDefensor = rand() % 6 + 1; // 1 a 6

    printf("\n%s (Atacante) rolou: %d\n", atacante->nome, dadoAtacante);
    printf("%s (Defensor) rolou: %d\n", defensor->nome, dadoDefensor);

    if (dadoAtacante > dadoDefensor) {
        printf("Ataque bem-sucedido!\n");
        defensor->tropas = atacante->tropas / 2;
        strcpy(defensor->cor, atacante->cor);
    } else {
        printf("Ataque falhou!\n");
        atacante->tropas -= 1;
        if (atacante->tropas < 0) atacante->tropas = 0;
    }

    printf("\n--- Status pós-ataque ---\n");
    printf("%s - Cor: %s - Tropas: %d\n", atacante->nome, atacante->cor, atacante->tropas);
    printf("%s - Cor: %s - Tropas: %d\n", defensor->nome, defensor->cor, defensor->tropas);
}

// Função para liberar memória
void liberarMemoria(Territorio* mapa) {
    free(mapa);
}

int main() {
    srand(time(NULL)); // inicializa semente para números aleatórios

    int totalTerritorios;
    Territorio* mapa = cadastrarTerritorios(&totalTerritorios);

    exibirTerritorios(mapa, totalTerritorios);

    // Exemplo de ataque (pode ser adaptado para menu interativo)
    printf("\nExemplo de ataque: jogador escolhe territórios 1 e 2\n");
    if (totalTerritorios >= 2) {
        atacar(&mapa[0], &mapa[1]);
    }

    liberarMemoria(mapa);
    return 0;
}
