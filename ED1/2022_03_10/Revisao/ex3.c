#include <stdio.h>
#include <stdlib.h>

int calcVogais(char *v) {
  int i = 0;
  int soma = 0;
  while(*(v + i) != '\0') {
    if(*(v + i) == 'a' || *(v + i) == 'e' || *(v + i) == 'i' || *(v + i) == 'o' || *(v + i) == 'u' ||
    *(v + i) == 'A' || *(v + i) == 'E' || *(v + i) == 'I' || *(v + i) == 'O' || *(v + i) == 'U') {
      soma += 1;
    }
    i++;
  }

  return soma;
}

int main() {
  // ENTRADA
  char frase[] = {"Algoritmos e Estruturas de Dados"};

  // PROCESSAMENTO
  int quantidadeVogais = calcVogais(frase);

  // SAIDA
  printf("O número de vogais presentes na frase é de %d.\n", quantidadeVogais);

  return 0;
}