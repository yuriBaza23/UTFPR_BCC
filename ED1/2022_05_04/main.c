#include<stdio.h>
#include "pilha.h"

int main(){
	
  printf("\n");
  printf("**************************************\n");
  printf("* PILHA\n");
  printf("**************************************\n\n");

  Pilha* p1 = pilha_criar();
  pilha_empilhar(p1, 10);
  pilha_empilhar(p1, 20);
  pilha_empilhar(p1, 30);
  pilha_imprimir(p1); // [10, 20,30]

  int topo;
  pilha_topo(p1, &topo);
  printf("topo: %d\n\n", topo); // 30

  int elemento;
  pilha_desempilhar(p1, &elemento);
  printf("elemento: %d\n", elemento); // 30
  pilha_desempilhar(p1, &elemento);
  printf("elemento: %d\n\n", elemento); // 20

  pilha_imprimir(p1); // [10]

  Pilha* p2 = pilha_clone(p1);
  pilha_imprimir(p2); // [10]

  pilha_empilhar(p2, 20);
  pilha_empilhar(p2, 30);
  pilha_empilhar(p2, 40);
  pilha_empilhar(p2, 20);
  pilha_empilhar(p2, 30);
  pilha_empilhar(p2, 40);
  pilha_empilhar(p2, 20);
  pilha_empilhar(p2, 30);
  pilha_empilhar(p2, 40);
  pilha_imprimir(p2); // [10 20 30 40]

  pilha_inverter(p2);

  Pilha* p3 = pilha_criar();
  TipoElemento* vetor = (TipoElemento*)malloc(5 * sizeof(TipoElemento));
  vetor[0] = 1960;
  vetor[1] = 1974;
  vetor[2] = 2001;
  vetor[3] = 2006;
  vetor[4] = 2006;
  pilha_empilharTodos(p3, vetor, 5);
  pilha_imprimir(p3); // [1960 1974 2001 2006 2006]
  pilha_desempilhar(p3, &elemento);
  pilha_desempilhar(p3, &elemento);
  pilha_desempilhar(p3, &elemento);
  pilha_desempilhar(p3, &elemento);
  pilha_desempilhar(p3, &elemento);
  pilha_desempilhar(p3, &elemento);

  char str[200];
  pilha_toString(p2, str);
  printf("\nto string: %s\n", str); // 40 30 20 10
}