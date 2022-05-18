#include <string.h>
#include "pilha.h"

#define TAM_INICIAL 5

/**************************************
* DADOS
**************************************/
struct pilha {
	TipoElemento* vetor;
	int tamVetor;
	int qtdeElementos;
};

/**************************************
* IMPLEMENTAÇÃO
**************************************/
// Funções auxiliares
void aumentar_tamanho(Pilha *p) {
  int qtd = p->qtdeElementos;
  Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
  TipoElemento* vetor = (TipoElemento*)malloc(p->tamVetor * 2 * sizeof(TipoElemento));
  pilha->vetor = vetor;
  pilha->tamVetor = p->tamVetor * 2;

  int i = 0;
  while(i != qtd) {
    pilha_empilhar(pilha, p->vetor[i]);
    i++;
  }

  p->vetor = pilha->vetor;
  p->tamVetor = pilha->tamVetor;
  free(pilha);
}

// Desenvolva as funções
Pilha* pilha_criar() {
  Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
  TipoElemento* vetor = (TipoElemento*)malloc(TAM_INICIAL * sizeof(TipoElemento));
  pilha->vetor = vetor;
  pilha->tamVetor = TAM_INICIAL;
  pilha->qtdeElementos = 0;

  return pilha;
}

void pilha_destruir(Pilha** endereco) {
  free(&endereco);
  endereco = NULL;
}

bool pilha_empilhar(Pilha* p, TipoElemento elemento) {
  if(p->qtdeElementos-1 == p->tamVetor) {
    aumentar_tamanho(p);
  }

  int qtd = p->qtdeElementos;
  p->vetor[qtd] = elemento;
  p->qtdeElementos = qtd + 1;

  return true;
}

bool pilha_topo(Pilha* p, TipoElemento* saida) {
  int qtd = p->qtdeElementos;

  *saida = p->vetor[qtd-1];
  return true;
} 

bool pilha_vazia(Pilha* p){
  if(p->qtdeElementos != 0) {
    return false;
  }

  return true;
}

bool pilha_desempilhar(Pilha* p, TipoElemento* saida) {
  if(pilha_vazia(p)) {
    printf("A pilha está vazia.\n");
    return false;
  } else {
    int qtd = p->qtdeElementos;

    *saida = p->vetor[qtd-1];

    p->vetor[qtd-1] = NULL;
    p->qtdeElementos = qtd - 1;

    return true;
  }
}

void pilha_imprimir(Pilha* p) {
  int qtd = p->qtdeElementos;
  int i = 0;
  printf("PILHA [ ");
  while(i != qtd) {
    printf("%d ", p->vetor[i]);
    i++;
  }
  printf("]\n\n");
}

int pilha_tamanho(Pilha* p) {
  return p->tamVetor;
}

Pilha* pilha_clone(Pilha* p) {
  Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
  TipoElemento* vetor = (TipoElemento*)malloc(p->tamVetor * sizeof(TipoElemento));
  pilha->vetor = vetor;
  pilha->tamVetor = p->tamVetor;
  pilha->qtdeElementos = 0;

  int qtd = p->qtdeElementos;
  int i = 0;
  while(i != qtd) {
    pilha_empilhar(pilha, p->vetor[i]);
    i++;
  }

  return pilha;
}

void pilha_inverter(Pilha* p) {
  Pilha* aux = pilha_clone(p);
  int i = 0;
  int j = p->qtdeElementos;
  while(i != p->qtdeElementos) {
    p->vetor[i] = aux->vetor[j-1];
    i++;
    j--;
  }
}

bool pilha_empilharTodos(Pilha* p, TipoElemento* vetor, int tamVetor) {
  int i = 0;
  while(i != tamVetor) {
    pilha_empilhar(p, vetor[i]);
    i++;
  }

  return true;
}

bool pilha_toString(Pilha* f, char* str) {
  char tmp[200] = "\0";
  strcat(str, "[");
  for(int i = 0; i < f->qtdeElementos; i++) {
    sprintf(tmp, "%d", f->vetor[i]);
    strcat(str, tmp);
    if(i != f->qtdeElementos-1) {
      strcat(str, ", ");
    }
  }
    strcat(str, "]");
    return str;
}