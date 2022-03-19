#include <stdio.h>
#include <stdlib.h>

int main() {
  int **w= NULL;
  int *p = NULL;
  int qtde = 50;

  w = &p;
  p = &qtde;

  return 0;
}