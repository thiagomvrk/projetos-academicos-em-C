#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FILA 5   // tamanho da fila de peças futuras
#define MAX_PILHA 3  // tamanho da pilha de reserva

// struct que representa uma peça
typedef struct {
    char tipo; // 'I', 'O', 'T', 'L'
    int id;    // identificador único da peça
} Peca;

// struct da fila circular
typedef struct {
    Peca itens[MAX_FILA];
    int inicio;
    int fim;
    int total;
} Fila;

// struct da pilha
typedef struct {
    Peca itens[MAX_PILHA];
    int topo;
} Pilha;

// gera uma peça aleatória
Peca gerarPeca(int id) {
    Peca p;
    char tipos[4] = {'I','O','T','L'};
    p.tipo = tipos[rand() % 4];
    p.id = id;
    return p;
}

// inicializa a fila
void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
}

// inicializa a pilha
void inicializarPilha(Pilha *p) {
    p->topo = -1; // -1 indica pilha vazia
}

// verifica se a fila está cheia
int filaCheia(Fila *f) {
    return f->total == MAX_FILA;
}

// verifica se a fila está vazia
int filaVazia(Fila *f) {
    return f->total == 0;
}

// verifica se a pilha está cheia
int pilhaCheia(Pilha *p) {
    return p->topo == MAX_PILHA - 1;
}

// verifica se a pilha está vazia
int pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

// insere peça no final da fila (enqueue)
int enqueue(Fila *f, Peca p) {
    if(filaCheia(f)) return 0; // não cabe
    f->itens[f->fim] = p;
    f->fim = (f->fim + 1) % MAX_FILA;
    f->total++;
    return 1;
}

// remove peça da frente da fila (dequeue)
Peca dequeue(Fila *f) {
    Peca vazia = {'-', -1};
    if(filaVazia(f)) return vazia;
    Peca p = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % MAX_FILA;
    f->total--;
    return p;
}

// adiciona peça na pilha (push)
int push(Pilha *p, Peca x) {
    if(pilhaCheia(p)) return 0;
    p->itens[++(p->topo)] = x;
    return 1;
}

// remove peça do topo da pilha (pop)
Peca pop(Pilha *p) {
    Peca vazia = {'-', -1};
    if(pilhaVazia(p)) return vazia;
    return p->itens[(p->topo)--];
}

// mostra a fila
void mostrarFila(Fila *f) {
    printf("\nFila de peças: ");
    for(int i = 0; i < f->total; i++) {
        int idx = (f->inicio + i) % MAX_FILA;
        printf("[%c %d] ", f->itens[idx].tipo, f->itens[idx].id);
    }
    printf("\n");
}

// mostra a pilha
void mostrarPilha(Pilha *p) {
    printf("Pilha de reserva (Topo -> Base): ");
    for(int i = p->topo; i >= 0; i--) {
        printf("[%c %d] ", p->itens[i].tipo, p->itens[i].id);
    }
    printf("\n");
}

// troca a peça da frente da fila com o topo da pilha
void trocarUma(Fila *f, Pilha *p) {
    if(filaVazia(f) || pilhaVazia(p)) {
        printf("Não é possível realizar troca.\n");
        return;
    }
    int idx = f->inicio;
    Peca aux = f->itens[idx];
    f->itens[idx] = p->itens[p->topo];
    p->itens[p->topo] = aux;
    printf("Troca simples realizada!\n");
}

// troca os 3 primeiros da fila com as 3 peças da pilha (se houver 3 ou mais em cada)
void trocarTres(Fila *f, Pilha *p) {
    if(f->total < 3 || p->topo < 2) {
        printf("Não é possível realizar troca múltipla, faltam peças.\n");
        return;
    }
    for(int i = 0; i < 3; i++) {
        int idxFila = (f->inicio + i) % MAX_FILA;
        Peca aux = f->itens[idxFila];
        f->itens[idxFila] = p->itens[p->topo - i];
        p->itens[p->topo - i] = aux;
    }
    printf("Troca múltipla realizada entre os 3 primeiros da fila e pilha!\n");
}

// função principal
int main() {
    srand(time(NULL));

    Fila fila;
    Pilha pilha;
    int contadorID = 0;

    inicializarFila(&fila);
    inicializarPilha(&pilha);

    // preenche a fila inicialmente
    for(int i = 0; i < MAX_FILA; i++) {
        enqueue(&fila, gerarPeca(contadorID++));
    }

    int opcao;
    do {
        mostrarFila(&fila);
        mostrarPilha(&pilha);

        printf("\nOpções:\n");
        printf("1 - Jogar peça da frente da fila\n");
        printf("2 - Enviar peça da fila para a pilha de reserva\n");
        printf("3 - Usar peça da pilha de reserva\n");
        printf("4 - Trocar peça da frente da fila com topo da pilha\n");
        printf("5 - Trocar os 3 primeiros da fila com 3 peças da pilha\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if(opcao == 1) {
            Peca p = dequeue(&fila);
            if(p.id != -1) {
                printf("Você jogou a peça [%c %d]\n", p.tipo, p.id);
                enqueue(&fila, gerarPeca(contadorID++)); // gera nova peça
            }
        } else if(opcao == 2) {
            Peca p = dequeue(&fila);
            if(p.id != -1) {
                if(push(&pilha, p)) {
                    printf("Peça [%c %d] enviada para a pilha!\n", p.tipo, p.id);
                } else {
                    printf("Pilha cheia! Não foi possível enviar a peça.\n");
                    enqueue(&fila, p); // devolve à fila
                }
                enqueue(&fila, gerarPeca(contadorID++)); // gera nova peça
            }
        } else if(opcao == 3) {
            Peca p = pop(&pilha);
            if(p.id != -1) {
                printf("Você usou a peça [%c %d] da pilha!\n", p.tipo, p.id);
            } else {
                printf("Pilha vazia! Não há peça para usar.\n");
            }
        } else if(opcao == 4) {
            trocarUma(&fila, &pilha);
        } else if(opcao == 5) {
            trocarTres(&fila, &pilha);
        } else if(opcao != 0) {
            printf("Opção inválida!\n");
        }

    } while(opcao != 0);

    printf("Fim do programa!\n");
    return 0;
}
