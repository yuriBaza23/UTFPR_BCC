#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void preencheVetor(int tamanho, int** vetor) {
  int* vetorF = (int*)malloc(tamanho * sizeof(int));

  for (int i = 0; i < tamanho; i++) {
    *(vetorF + i) = rand() % 10;
  }

  *vetor = vetorF;
}

void preservaValores(int tam, int *vetor, int **endVetor) {
  for (int i = 0; i < tam; i++) {
    *(vetor + i) = *(*(endVetor) + i);
  }
}

void imprimirVetor(int tam, int *vetor) {
  printf("[");
  for(int i = 0; i < tam; i++) {
    printf(" %d ", *(vetor + i));
  }
  printf("]\n");
}

// A função deve:
// 1 - Alocar um novo vetor com o dobro do tamanho do vetor recebido por parâmetro.
// 2 - Copiar os valores para o vetor novo
// 3 - Preencher com '0' as novas posições
// 4 - Desalocar o vetor antigo
// 5 - Atualizar a referência do vetor recebido por parâmetro
// RETORNO: Boolean
bool dobra(int tam, int **endVetor) {
  int* novoVetor = (int*)calloc(tam*2, sizeof(int));

  preservaValores(tam, novoVetor, endVetor);

  free(*endVetor);
  *endVetor = NULL;

  imprimirVetor(tam*2, novoVetor);

  *endVetor = novoVetor;
  return true;
};

int main() {
  int* vetor;

  preencheVetor(16, &vetor);
  dobra(16, &vetor);

  return 0;
}