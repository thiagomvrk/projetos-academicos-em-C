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
