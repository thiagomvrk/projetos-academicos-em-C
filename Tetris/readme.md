# 🎮 Tetris Stack – Gerenciador de Peças Avançado

## 📝 Descrição do projeto
Este projeto é um gerenciador de peças para o jogo Tetris Stack, desenvolvido em C, que utiliza **fila circular** e **pilha linear** para controlar peças futuras e reservadas. O jogador pode executar ações estratégicas como jogar peças, reservar, usar peças da reserva e realizar trocas simples ou múltiplas entre a fila e a pilha.

O projeto foi criado com foco no **aprendizado prático** de todas as ferramentas e conceitos utilizados, incluindo:

- Fila circular (manipulação eficiente com reaproveitamento de espaço)
- Pilha linear (LIFO – último a entrar, primeiro a sair)
- Structs para representar peças
- Arrays para armazenar elementos
- Funções modulares para organizar o código
- Operadores lógicos e condicionais para controle de fluxo
- Integração de estruturas para troca de valores entre fila e pilha

O objetivo é consolidar **conceitos avançados de programação em C**, como integração entre estruturas, modularização e manipulação de dados em tempo de execução.

---

## ⚡ Funcionalidades
O programa permite:

- 🆕 Inicializar automaticamente a fila de peças futuras (5 peças)
- 🆕 Inicializar a pilha de peças reservadas (3 peças)
- 🎯 Jogar a peça da frente da fila
- 📦 Enviar peça da fila para a pilha de reserva
- 🛠 Usar peça da pilha de reserva
- 🔄 Troca simples entre a frente da fila e o topo da pilha
- 🔁 Troca múltipla entre os 3 primeiros da fila e 3 peças da pilha (quando possível)
- 📊 Exibir o estado atual da fila e da pilha a cada ação

---

## 🛠 Tecnologias e ferramentas utilizadas
- Linguagem: **C**
- Estruturas de dados: **fila circular** e **pilha linear**
- Structs e arrays
- Funções modulares e separação de responsabilidades

---

## 💻 Como usar
1. Compile o programa usando GCC ou outro compilador compatível:
```bash
gcc tetris_stack.c -o tetris_stack
