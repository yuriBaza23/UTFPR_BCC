#include <stdio.h>
#include <stdlib.h>

int main() {
  // Malloc: Aloca um espaço na memória Heap e devolve o endereço do primeiro byte.
  // void *malloc(size_t tam)

  // PARA UMA INFORMAÇÃO
  int i = 1;
  int *p1 = &i;
  int *p2;
  p2 = (int *)malloc(sizeof(int));
  *p2 = 5;

  // PARA UM VETOR
  int v1[3] = { 1, 2, 3 };
  int *v2;
  v2 = (int *)malloc(3* sizeof(int));
  v2[0] = 1;
  *(v2 + 1) = 2;

  // Calloc: Aloca um espaço na memória Heap e devolve o endereço do primeiro byte.
  // Elimina lixo de memória ao ser alocado (transforma em zero)
  // void *calloc(tam, size_t tam)
  int j = 1;
  int *p3 = &j;
  int *p4;
  p4 = (int *)calloc(1, sizeof(int));
  *p4 = 5;

  // Free: Usado para desalocar: MARCA COMO LIVRE MAS NÃO MUDA O CONTEÚDO DOS PONTEIROS
  free(p2);
  free(v2);
  free(p4);

  p2 = NULL; // Boa prática
  v2 = NULL; // Boa prática
  p4 = NULL; // Boa prática


  return 0;
}