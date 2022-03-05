#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *argv[]) {
  float altura, peso, imc;

  // Entrada
  altura = atof(argv[1]);
  peso = atof(argv[2]);

  // Processamento
  imc = peso / pow(altura, 2);

  // Saída
  if (imc < 18.5) {
    printf("\nIMC = %f\nDe acordo com seu IMC você está classificado MAGREZA e tem grau de obesidade 0\n", imc);
  } else if (imc < 24.9) {
    printf("\nIMC = %f\nDe acordo com seu IMC você está classificado NORMAL e tem grau de obesidade 0\n", imc);
  } else if (imc < 29.9) {
    printf("\nIMC = %f\nDe acordo com seu IMC você está classificado SOBREPESO e tem grau de obesidade 1\n", imc);
  } else if (imc < 39.9) {
    printf("\nIMC = %f\nDe acordo com seu IMC você está classificado OBESIDADE e tem grau de obesidade 2\n", imc);
  } else {
    printf("\nIMC = %f\nDe acordo com seu IMC você está classificado OBESIDADE GRAVE e tem grau de obesidade 3\n", imc);
  }

  return 0;
}