#include <stdio.h>
#include <stdlib.h>

#define TAM 4

void imprimeVetor(int *ponteiroVetor, int tamanhoVetor) {
  printf("[");
  for(int i = 0; i < tamanhoVetor; i++) {
    printf(" %d ", *(ponteiroVetor + i));
  }
  printf("]\n");
}

int main() {
  int i = 30;
  int *x = &i;

  int v[4] = { 1, 2, 3, 4 };
  int *p = v;
  int *w = v+2;

  imprimeVetor(p, TAM);

  return 0;
}