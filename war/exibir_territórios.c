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
