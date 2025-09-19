# 🎲 War Estruturado em C

![C](https://img.shields.io/badge/Linguagem-C-00599C?style=for-the-badge&logo=c)
![Memory](https://img.shields.io/badge/Mem%C3%B3ria-Aloca%C3%A7%C3%A3o%20Din%C3%A2mica-green?style=for-the-badge)
![Game](https://img.shields.io/badge/Jogo-War-orange?style=for-the-badge)

---

## 🏰 Sobre o projeto

Este é um **War estruturado** desenvolvido em **C**, onde você pode cadastrar territórios, distribuir tropas e simular ataques entre territórios de diferentes jogadores.  
O objetivo é **praticar conceitos de programação estruturada**, **ponteiros**, **alocação dinâmica de memória** e **simulação com números aleatórios**.

No jogo:  
- Cada território pertence a um jogador (representado por uma cor) e possui um número de tropas.  
- Jogadores podem atacar territórios inimigos, e o resultado é definido por uma **rolagem de dados simulada**.  
- Se o ataque vencer, o território muda de dono e recebe metade das tropas do atacante; se perder, o atacante perde uma tropa.  

---

## ⚡ Funcionalidades

- Cadastro de territórios com **nome, cor do jogador e número de tropas**.  
- Exibição clara dos territórios e suas tropas.  
- Ataque entre territórios usando **ponteiros** e **números aleatórios** (`rand()`).  
- Atualização automática da **cor e quantidade de tropas** após ataques.  
- **Alocação dinâmica de memória** para armazenamento flexível dos territórios.  
- **Liberação de memória** ao final do programa com `free()`.  

---

## 🛠 Tecnologias utilizadas

- **Linguagem C**: toda a lógica do jogo.  
- **Ponteiros**: para manipulação dos territórios durante ataques.  
- **Alocação dinâmica de memória** (`malloc` / `calloc` e `free`).  
- **Funções modulares**: cadastro, exibição, ataque e liberação de memória.  
- **Bibliotecas padrão**: `stdio.h`, `stdlib.h`, `string.h`, `time.h`.  

---

## 🎮 Como jogar

1. Compile o código com um compilador C:
```bash
gcc war.c -o war
