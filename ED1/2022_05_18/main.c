#include<stdio.h>
#include "pilha.h"

int main(){
	
  printf("\n");
  printf("**************************************\n");
  printf("* UTILIZAÇÃO PILHA\n");
  printf("**************************************\n\n");

  char str[6] = "UTFPR";
  char expressao[6] = "234*+";

  inverter(str);

  calcular_pos(expressao);
}