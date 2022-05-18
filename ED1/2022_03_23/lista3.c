#include <stdio.h>
#include <stdlib.h>

#define TAM 3
#define TAMP 2

void imprimeValores(int** ponteiroPonteiros, int tamanho, int tamanhoVetorPonteiro) {
  printf("[");
  for (int i = 0; i < tamanhoVetorPonteiro; i++) {
    for (int j = 0; j < tamanho; j++) {
      printf(" %d ", **(ponteiroPonteiros + i) + j);

      if(j == tamanho - 1 && i != tamanhoVetorPonteiro - 1)
        printf("] [");
    }

    if(i == tamanhoVetorPonteiro - 1) 
      printf("]\n");
  }
}

int main() {
  int v1[3] = { 1, 2, 3 };
  int v2[3] = { 4, 5, 6 };

  int *p1 = v1;
  int *p2 = v2;

  int *m[2] = { v1, v2 };
  int **pm = m;

  imprimeValores(pm, TAM, TAMP);

  return 0;
}