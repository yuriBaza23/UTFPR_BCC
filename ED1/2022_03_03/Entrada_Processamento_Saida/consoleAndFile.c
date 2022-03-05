#include <stdio.h>
#include <math.h>

int main() {
  float altura, peso, imc;

  // Entrada
  printf("Qual a sua altura? ");
  scanf("%f", &altura);
  printf("Ok. Qual o seu peso? ");
  scanf("%f", &peso);

  // Processamento
  imc = peso / pow(altura, 2);

  // Saída
  FILE *arq_out = fopen("ED1/2022_03_03/Entrada_Processamento_Saida/0saida.out", "w");
  if (imc < 18.5) {
    fprintf(arq_out, "\nIMC = %f\nDe acordo com seu IMC você está classificado MAGREZA e tem grau de obesidade 0\n", imc);
  } else if (imc < 24.9) {
    fprintf(arq_out, "\nIMC = %f\nDe acordo com seu IMC você está classificado NORMAL e tem grau de obesidade 0\n", imc);
  } else if (imc < 29.9) {
    fprintf(arq_out, "\nIMC = %f\nDe acordo com seu IMC você está classificado SOBREPESO e tem grau de obesidade 1\n", imc);
  } else if (imc < 39.9) {
    fprintf(arq_out, "\nIMC = %f\nDe acordo com seu IMC você está classificado OBESIDADE e tem grau de obesidade 2\n", imc);
  } else {
    fprintf(arq_out, "\nIMC = %f\nDe acordo com seu IMC você está classificado OBESIDADE GRAVE e tem grau de obesidade 3\n", imc);
  }
  fclose(arq_out);

  return 0;
}