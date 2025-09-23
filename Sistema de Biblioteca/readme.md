# 📚 Sistema de Biblioteca em C

Projeto desenvolvido como parte dos meus estudos em programação na linguagem **C**.  
A ideia é simular um sistema de biblioteca simples, onde é possível:

- 📖 **Cadastrar livros**  
- 📋 **Listar livros cadastrados**  
- 🤝 **Realizar empréstimos**  
- 📑 **Listar empréstimos**  
- 🔄 **Devolver livros**

---

## ⚙️ Ferramentas utilizadas

- **Linguagem:** C 
- **Conceitos aplicados:**
  - `struct` (para armazenar dados dos livros e empréstimos)  
  - `malloc` e `calloc` (alocação dinâmica de memória)  
  - Modularização (funções para cada funcionalidade)  
  - Manipulação de strings com `fgets` e `strcspn`

---

## 🚀 Como funciona

Ao executar o programa, aparece o seguinte menu:

===== BIBLIOTECA =====
1. Cadastrar livro
2. Listar livros
3. Realizar empréstimo
4. Listar empréstimos
5. Devolver livro
6. Sair


Cada número representa uma funcionalidade.  
O usuário escolhe a opção digitando o número correspondente, e o programa executa a ação:

- **Cadastrar livro** → Adiciona o livro ao array `biblioteca`.  
- **Listar livros** → Mostra todos os livros cadastrados com status de disponibilidade.  
- **Realizar empréstimo** → Marca o livro como **indisponível** e cria um registro na lista de empréstimos.  
- **Listar empréstimos** → Mostra todos os livros atualmente emprestados.  
- **Devolver livro** → O livro volta para o status **disponível** e o empréstimo é removido.  
- **Sair** → Encerra o programa.  






