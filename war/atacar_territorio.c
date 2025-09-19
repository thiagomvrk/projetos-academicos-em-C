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
