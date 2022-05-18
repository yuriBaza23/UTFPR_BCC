#include <stdio.h>
#include <stdlib.h>

// Retorna a quantidade de caracteres de uma string
int tamanhoString1(char* string) {
  int i = 0;
  int total = 0;

  while(*(string + i) != '\0') {
    total = i + 1;
    i++;
  }

  return total;
}

// Retorna a quantidade de caracteres de uma string mas por referencia
void tamanhoString2(char* string, int* lenght) {
  int i = 0;
  int total = 0;

  while(*(string + i) != '\0') {
    total = i + 1;
    i++;
  }

  *lenght = total;
}

int main() {

  char minhaString[5] = "Yuri";
  char minhaString2[8] = "Ulisses";
  int lenght;

  int tamanho = tamanhoString1(minhaString); // 4
  printf("%d\n", tamanho);
  tamanhoString2(minhaString2, &lenght); // 7
  printf("%d\n", lenght);

  return 0;  
}