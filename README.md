# 📂 Lista, pilha e fila

Este repositório contém a implementação das atividades propostas relacionadas à disciplina de Estrutura de Dados I, compreendendo as seguintes estruturas:

* Lista ligada
* Pilha estática
* Fila

## 📚 Atividades implementadas  

### 1. Lista Ligada
Transformação de uma lista ligada simples em uma lista duplamente ligada, implementando e revisando a função:
- `bool inserirElemListaOrd(LISTA* l, REGISTRO reg);`

### Propósitos:
- Atualizar o campo `ant` dos elementos;
- Garantir que a iinserção seja ordenada e sem repetição.

### 2. Pilha Estática
Implementação da função:
- `void exibirPilhaInvertida(PILHA* p);`

### Objetivo:
- Exibir os elementos da pilha de baixo para cima;

### 3. Fila com Nó-Cabeça
Adaptação das funções de inserção e remoção para considerar a existência de um nó-cabeça:
- `bool inserirNaFila(FILA* f, REGISTRO reg);`
- `bool excluirDaFila(FILA* f, REGISTRO* reg);`

#### Objetivo:
- Manter a integridade da fila com a inclusão de um nó-cabeça para facilitar a gestão dos elementos.
