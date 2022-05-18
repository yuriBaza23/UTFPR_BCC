#include <stdio.h>
#include <stdlib.h>
#include "tad_vetor.h"

// DADOS
struct vetor {
  int* v;
  int tam;
  int qtd;
};

// FUNÇÕES
// - Criar um vetor
// - Destruir um vetor
// - Inserir um elemento no vetor
// - Imprimir um vetor

Vetor* vector_create(int tam) {
  Vetor* array = (Vetor*)malloc(sizeof(Vetor));

  array->v = (int*)calloc(tam, sizeof(int));
  array-> tam = tam;
  array->qtd = 0;

  return array;
}

void vector_toIndex(Vetor* array, int element) {
  int tam = array->tam;
  int qtd = array->qtd;

  if(qtd < tam) {
    array->v[qtd] = element;
    array->qtd = qtd+1;
  } else {
    printf("Elemento não adicionado!\n");
  }
}

void vector_print(Vetor* array) {
  printf("Array [");
  for (int i = 0; i < array->tam; i++) {
    printf(" %d ", array->v[i]);
  }
  printf("]\n");
}

void vector_destroy(Vetor** endArray) {
  free(*endArray);
  printf("\nConteúdo antes: %p  ", *endArray);
  *endArray = NULL;
  printf("Conteúdo agora: %p\n", *endArray);
  printf("Array desalocado.\n\n");
}