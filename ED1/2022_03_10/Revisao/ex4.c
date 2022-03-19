#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* extrairTrecho(char *texto, int inicial, int final) {
  char *extracao;
  extracao = &texto[inicial - 1];
  extracao[(final - inicial) + 1] = '\0';
  return extracao;
}

int main() {
  // ENTRADA
  // char texto[] = "Universidade Tecnológica Federal do Parana, Campus Campo Mourao";
  char texto[] = "UTFPR-CM";

  // PROCESSAMENTO
  char *textoExtraido = extrairTrecho(texto, 3, 4);

  // SAÍDA
  printf("Texto extraído: %s\n", textoExtraido);

  return 0;
}