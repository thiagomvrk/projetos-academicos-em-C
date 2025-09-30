# 🕵️ Detective Quest – Sistema de Exploração da Mansão

Esse projeto foi feito em C como parte de um desafio técnico. A ideia é simular um mini-jogo onde o jogador explora uma **mansão misteriosa**, coleta pistas, associa essas pistas a suspeitos e no final faz uma acusação pra tentar descobrir o culpado.  

---

## 🎮 Como funciona o jogo

- O **mapa da mansão** é representado como uma **árvore binária** fixa, montada direto no código.  
- O jogador começa no **Hall de Entrada** e pode escolher os caminhos:
  - `(e)` → esquerda  
  - `(d)` → direita  
  - `(s)` → sair da exploração  

- Algumas salas têm **pistas escondidas**, que o jogador coleta automaticamente ao entrar.  
- Cada pista vai pra uma **árvore binária de busca (BST)**, onde ficam armazenadas em ordem.  
- Também existe uma **tabela hash** que liga cada pista ao suspeito correspondente.  
- No final da exploração, o jogador vê todas as pistas coletadas e faz uma acusação.  
- O sistema checa se pelo menos **duas pistas** incriminam o suspeito escolhido.  

---

## 🗂️ Estrutura usada

- **Árvore binária (salas)** → representa o mapa fixo da mansão.  
- **BST (pistas)** → guarda as pistas coletadas de forma ordenada.  
- **Tabela Hash (pista → suspeito)** → liga cada pista a quem pode ser culpado.  

---

## ⚙️ Funcionalidades principais

- `criarSala()` → cria dinamicamente uma sala.  
- `explorarSalas()` → permite o jogador navegar e coletar pistas.  
- `inserirPista()` → adiciona uma pista coletada na BST.  
- `inserirNaHash()` → insere a relação pista → suspeito.  
- `encontrarSuspeito()` → retorna o suspeito de uma pista.  
- `verificarSuspeitoFinal()` → checa se a acusação tem pistas suficientes.  

---

## 📖 Exemplo de gameplay

```bash
Você está na: Hall de Entrada
Escolha um caminho: (e) esquerda, (d) direita, (s) sair: e

Você está na: Sala de Estar
Você encontrou uma pista: Taça quebrada
Escolha um caminho: (e) esquerda, (d) direita, (s) sair: e

Você está na: Cozinha
Você encontrou uma pista: Faca suja de sangue
Fim do caminho nesta sala.

=== FASE FINAL ===
Pistas coletadas:
- Faca suja de sangue
- Taça quebrada

Digite o nome do suspeito que você acusa: Mordomo
Acusação correta! O suspeito Mordomo foi condenado.
