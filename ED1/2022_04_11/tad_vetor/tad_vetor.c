#include <stdio.h>
#include <string.h>
#include "tad_vetor.h"

/********************************************
 * Especificação dos dados
 *******************************************/
struct vetor{
  int* vet;
  int tam;
  int qtd;
};

/********************************************
 * Implementação das funções
 *******************************************/
int* redimensionar(int* vet, int tam) {
  int* v = (int*)calloc(tam, sizeof(int));

  for (int i = 0; i < tam; i++) {
    v[i] = vet[i]; 
  }

  return v;
}

Vetor* vet_criar() {
  Vetor* vetor = (Vetor*)malloc(sizeof(Vetor));
  int* vet = (int*)calloc(4, sizeof(int));

  vetor->vet = vet;
  vetor->tam = 4;
  vetor->qtd = 0;

  return vetor;
}

bool vet_anexar(Vetor* v, int elemento) {
  int qtd = v->qtd;
  int tam = v->tam;

  if(qtd > tam) {
    int* vet = redimensionar(v->vet, tam*2);
    free(v->vet);
    v->vet = vet;
    v->tam = tam*2;
  }

  v->vet[qtd] = elemento;
  v->qtd = qtd + 1;

  return true;
}

bool vet_inserir(Vetor* v, int elemento, int posicao) {
  int qtd = v->qtd;
  int tam = v->tam;
  int prox = 0;
  int newTam = qtd > tam ? tam*2 : tam;

  int* vet = redimensionar(v->vet, newTam);
  v->tam = newTam;

  for(int i = 0; i < tam+1; i++) {
    if(posicao == i || prox != 0) {
      vet[i] = posicao == i ? elemento : prox;
      prox = v->vet[i];
    } else {
      vet[i] = v->vet[i];
    }
  }

  free(v->vet);
  v->qtd = qtd+1;
  v->vet = vet;

  return true;
}

bool vet_substituir(Vetor* v, int posicao, int novoElemento) {
  int qtd = v->qtd;
  int tam = v->tam;

  if(posicao > tam) {
    return false;
  }

  v->vet[posicao] = novoElemento;

  return true;
}

bool vet_removerPosicao(Vetor* v, int posicao, int* endereco) {
  int qtd = v->qtd;
  int tam = v->tam;

  if(posicao > qtd) return false;

  for (int i = 0; i < tam; i++) {
    if(i == posicao) {
      *endereco = v->vet[i];
    }
    if(i >= posicao) {
      v->vet[i] = v->vet[i+1];
    } 
  }

  v->qtd = qtd-1;

  return true;
}

int vet_posicao(Vetor* v, int elemento) {
  for(int i = 0; i < v->tam; i++) {
    if(v->vet[i] == elemento) {
      return i;
    }
  }

  return -1;
}

int vet_removerElemento(Vetor* v, int elemento) {
  int exist = vet_posicao(v, elemento);

  int i;
  vet_removerPosicao(v, exist, &i);

  return exist;
}

int vet_tamanho(Vetor* v) {
  return v->qtd;
}

bool vet_elemento(Vetor* v, int posicao, int* saida) {
  if(posicao > v->qtd) return false;

  for (int i = 0; i < v->tam; i++) {
    if(i == posicao) {
      *saida = v->vet[i];
    }
  }

  return true;
}

void vet_imprimir(Vetor* v) {
  printf("[");
  for (int i = 0; i < v->qtd; i++) {
    printf(" %d ", v->vet[i]);
  }
  printf("]\n");
}

void vet_desalocar(Vetor** endVetor) {
  free(endVetor);
  endVetor = NULL;
}

bool vet_toString(Vetor* v, char* saida) {
  char* str = (char*)malloc(200 * sizeof(char));
  char* c = (char*)malloc(10 * sizeof(char));

  strcat(str, "[");
  for(int i = 0; i < v->qtd; i++) {
    sprintf(c, " %d ", v->vet[i]);
    strcat(str, c);
  }
  strcat(str, "]");

  return true;
}