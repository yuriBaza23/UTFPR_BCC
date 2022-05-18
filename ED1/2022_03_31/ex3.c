#include <stdio.h>
#include <stdlib.h>

int* clonarVetor1(int* vetor, int tam) {
  int *v = (int*)malloc(tam * sizeof(int));

  for(int i = 0; i < tam; i++) {
    *(v + i) = *(vetor + i);
  }

  return vetor;
}

void clonarVetor2(int* vetor, int** duplicado, int tam) {
  int *v = (int*)malloc(tam * sizeof(int));

  for(int i = 0; i < tam; i++) {
    *(v + i) = *(vetor + i);
  }

  *duplicado = v;
}

int main() {

  int vetor1[4] = { 0, 1, 2, 3 };
  int vetor2[4] = { 4, 5, 6, 7 };

  int* vetorDuplicado1;
  int* vetorDuplicado2;
  
  vetorDuplicado1 = clonarVetor1(vetor1, 4);
  clonarVetor2(vetor2, &vetorDuplicado2, 4);

  return 0;
}