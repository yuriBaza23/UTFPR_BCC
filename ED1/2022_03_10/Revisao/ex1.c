#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM 4

void imprimeVetor(int *v) {
  printf("Os números do vetor são: ");
  for (int i = 0; i < TAM; i++) {
    printf("%d ", *(v + i));
  }
  printf("\n");
}

bool encontrarNumero(int *v, int num) {
  for (int i = 0; i < TAM; i++) {
    if(*(v + i) == num) {
      return true;
    }
  }

  return false;
}

int main() {
  // ENTRADA
  int vetor[TAM];
  int numero;

  FILE *arq_in = fopen("./ED1/2022_03_10/Revisao/arq_ex1.in", "r");
  fscanf(arq_in, "%d %d %d %d %d", &vetor[0], &vetor[1], &vetor[2], &vetor[3], &numero);
  fclose(arq_in);

  // PROCESSAMENTO
  imprimeVetor(vetor);
  bool encontrado = encontrarNumero(vetor, numero);

  // SAIDA
  if(encontrado) 
    printf("O número %d foi encontrado no vetor.\n", numero);
  else
    printf("O número %d não foi encontrado no vetor.\n", numero);

  return 0;
}