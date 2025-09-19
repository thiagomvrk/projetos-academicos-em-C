#include <stdio.h>
#include <string.h>

#define TERRITORIOS 5      // quantidade máxima de territórios jogáveis
#define TAMANHO_STRING 100 // tamanho máximo para strings

// STRUCT DO TERRITÓRIO
struct territorio
{
    char nome[TAMANHO_STRING]; // nome do território
    char cor[TAMANHO_STRING];  // cor do jogador que o controla
    int tropas;                // número de tropas
};

// Função para limpar o buffer do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int main() {
    struct territorio territorios[TERRITORIOS]; // vetor de territórios
    int totalTerritorios;

    printf("Quantos territórios serão cadastrados? (máx %d): ", TERRITORIOS);
    scanf("%d", &totalTerritorios);
    limparBuffer();

    if (totalTerritorios > TERRITORIOS) {
        totalTerritorios = TERRITORIOS; // limita ao máximo definido
    }

    // Loop para cadastrar cada território
    for (int i = 0; i < totalTerritorios; i++) {
        printf("\n=== Território %d ===\n", i + 1);

        printf("Digite o nome do território: ");
        fgets(territorios[i].nome, TAMANHO_STRING, stdin);
        territorios[i].nome[strcspn(territorios[i].nome, "\n")] = '\0'; // remove '\n'

        printf("Digite a cor do jogador que controla: ");
        fgets(territorios[i].cor, TAMANHO_STRING, stdin);
        territorios[i].cor[strcspn(territorios[i].cor, "\n")] = '\0';

        printf("Digite o número de tropas: ");
        scanf("%d", &territorios[i].tropas);
        limparBuffer();
    }

    // Mostrando os territórios cadastrados
    printf("\n=== TERRITÓRIOS CADASTRADOS ===\n");
    for (int i = 0; i < totalTerritorios; i++) {
        printf("\nTerritório %d\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do jogador: %s\n", territorios[i].cor);
        printf("Tropas: %d\n", territorios[i].tropas);
    }

    return 0;
}

