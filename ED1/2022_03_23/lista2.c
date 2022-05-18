#include <stdio.h>
#include <stdlib.h>

#define TAM 4

void imprimeValores(int **ponteiroPonteiro, int tamanho) {
  for (int i = 0; i < tamanho; i++) {
    printf("%d ", *(*(ponteiroPonteiro + i)));
  }
}

int main() {
  int a = 10;
  int b = 20;
  int c = 30;
  int d = 40;

  int *v[4] = { &a, &b, &c, &d };

  int **p = v;

  imprimeValores(p, TAM);

  return 0;
}