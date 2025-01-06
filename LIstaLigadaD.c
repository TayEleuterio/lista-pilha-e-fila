#include "listaLigadaD.h"
#include <stdio.h>
#include <stdlib.h>

void inicializarLista(LISTA* l) {
  l->inicio = NULL;
}

void exibirLista(LISTA* l) {
  PONT end = l->inicio;
  printf("Lista: \" ");
  while (end != NULL) {
    printf("%d ", end->reg.chave);
    end = end->prox;
  }
  printf("\"\n");
}

int tamanho(LISTA* l) {
  PONT end = l->inicio;
  int tam = 0;
  while (end != NULL) {
    tam++;
    end = end->prox;
  }
  return tam;
}

int tamanhoEmBytes(LISTA* l) {
  return (tamanho(l) * sizeof(ELEMENTO)) + sizeof(LISTA);
}

PONT buscaSequencial(LISTA* l, TIPOCHAVE ch) {
  PONT pos = l->inicio;
  while (pos != NULL) {
    if (pos->reg.chave == ch) return pos;
    pos = pos->prox;
  }
  return NULL;
}

PONT buscaSeqOrd(LISTA* l, TIPOCHAVE ch) {
  PONT pos = l->inicio;
  while (pos != NULL && pos->reg.chave < ch) pos = pos->prox;
  if (pos != NULL && pos->reg.chave == ch) return pos;
  return NULL;
}

PONT buscaSeqExc(LISTA* l, TIPOCHAVE ch, PONT* ant) {
  *ant = NULL;
  PONT atual = l->inicio;
  while (atual != NULL && atual->reg.chave < ch) {
    *ant = atual;
    atual = atual->prox;
  }
  if (atual != NULL && atual->reg.chave == ch) return atual;
  return NULL;
}

bool excluirElemLista(LISTA* l, TIPOCHAVE ch) {
  PONT i = l->inicio;
  i = buscaSeqExc(l, ch, &ant);
  whilw (i !=NULL && i->reg.chave != ch) {
    i = i->prox;
  }
  if (i == NULL) return false;
  if (i->ant != NULL) { ant->prox = i->prox
  }
  else {
    l->inicio = i->prox;
  }
  if (i->prox != NULL) {
    i->prox->ant = i->ant;
  }
  free(i);
  return true;
}

void reinicializarLista(LISTA* l) {
  PONT end = l->inicio;
  while (end != NULL) {
    PONT apagar = end;
    end = end->prox;
    free(apagar);
  }
  l->inicio = NULL;
}

bool inserirElemListaOrd(LISTA* l, REGISTRO reg) {
  PONT novo = (PONT) malloc(sizeof(ELEMENTO));
  if (novo == NULL) return false;
  novo->reg = reg;
  nov->prox = NULL;
  novo->ant = NULL;

  PONT atual = l->inicio;
  PONT anterior = NULL;

  while (atual != NULL && atual->reg.chave == reg.chave) {
    anterior = atual;
    atual = atual->prox;
  }
  
  if (atual != NULL && atual->reg.chave == reg.chave) {
    free(novo);
    return false;
  }
  
  if (antterior == NULL) {
    novo->prox = l->inicio;
    if (l->inicio != NULL) {
      l->inicio->ant = novo;
    }
    l->inicio = novo;
  } 
  
  else {
    novo->prox = atual;
    novo->ant = anterior;
    anterior->prox = novo;
    if (atual != NULL){
      atual->ant = novo;
    }
  }
  return true;
}

PONT retornarPrimeiro(LISTA* l, TIPOCHAVE *ch) {
  if (l->inicio != NULL) *ch = l->inicio->reg.chave;
  return l->inicio;
}

PONT retornarUltimo(LISTA* l, TIPOCHAVE *ch) {
  PONT ultimo = l->inicio;
  if (l->inicio == NULL) return NULL;
  while (ultimo->prox != NULL) ultimo = ultimo->prox;
  *ch = ultimo->reg.chave;
  return ultimo;
}
