#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM 4

int somaElementosVetor(int *v) {
  int sum = 0;
  for (int i = 0; i < TAM; i++) {
    sum += *(v + i);
  }
  return sum;
}

int main() {
  // ENTRADA
  int vetor[TAM];

  FILE *arq_in = fopen("./ED1/2022_03_10/Revisao/arq_ex2.in", "r");
  fscanf(arq_in, "%d %d %d %d", &vetor[0], &vetor[1], &vetor[2], &vetor[3]);
  fclose(arq_in);

  // PROCESSAMENTO
  int soma = somaElementosVetor(vetor);

  // SAIDA
  printf("A soma de todos os elementos desse conjunto é de %d.\n", soma);

  return 0;
}