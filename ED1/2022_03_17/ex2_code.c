#include <stdio.h>
#include <stdlib.h>

int main() {
  // Código já definido
  int i2 = 22;
  float f = 2.5;
  int *p1 = &i2;
  short int si = 30;
  short int *psi = &si;
  int **x = &p1;

  // Código criado
  int i1 = 15;
  char c = "b";
  int *p2 = &i1;
  char *pc = &c;
  int **w = &p1;
  int ***z = &w;

  return 0;
}