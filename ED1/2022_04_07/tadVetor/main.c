#include <stdio.h>
#include <stdlib.h>
#include "tad_vetor.h"

int main() {
  Vetor* array1 = vector_create(10);
  Vetor* array2 = vector_create(20);

  vector_toIndex(array1, 16);
  vector_toIndex(array1, 31);
  vector_toIndex(array1, 23);
  vector_toIndex(array1, 3);
  vector_toIndex(array1, 3);

  vector_toIndex(array2, 23);
  vector_toIndex(array2, 3);
  vector_toIndex(array2, 3);

  vector_print(array1);
  vector_print(array2);

  vector_destroy(&array1);
  vector_destroy(&array2);

  return 0;
}