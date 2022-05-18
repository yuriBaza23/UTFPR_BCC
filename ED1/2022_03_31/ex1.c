#include <stdio.h>
#include <stdlib.h>

// Cria um vetor de tamanho "n" preenchidos com qualquer valor.
// Retorna o vetor
int* criaVetorAleatorio1(int tamanho) {
  int* vetor = (int*)malloc(tamanho * sizeof(int));

  for (int i = 0; i < tamanho; i++) {
    *(vetor + i) = rand() % 10;
  }

  return vetor;
}

// Cria um vetor de tamanho "n" preenchidos com qualquer valor.
void criaVetorAleatorio2(int** vetor, int tamanho) {
  int* vetorF = (int*)malloc(tamanho * sizeof(int));

  for (int i = 0; i < tamanho; i++) {
    *(vetorF + i) = rand() % 10;
  }

  *vetor = vetorF;
}

int main() {

  int* vetor1;
  int* vetor2;

  vetor1 = criaVetorAleatorio1(4);
  criaVetorAleatorio2(&vetor2, 4);

  return 0;
}