#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produto {
  int codigo;
  char descricao[21];
  float preco;
} Produto;

#define TAM 4

void imprimeProdutos(Produto *ponteiroProduto[], int tamanho) {
  for (int i = 0; i < tamanho; i++) {
    printf("[Produto %d] -----------------------\n", ponteiroProduto[i]->codigo);
    printf("Nome do produto: %s\n", ponteiroProduto[i]->descricao);
    printf("Preço do produto: %.2f\n", ponteiroProduto[i]->preco);
  }
}

int main() {
  Produto prodA = { 1, "Teclado", 98.5 };
  Produto prodB = { 2, "Mouse", 65.0 };
  Produto prodC = { 3, "Webcam", 130.0 };

  // ITEM A
  Produto vet[4];
  vet[0] = prodA;
  vet[1] = prodB;
  vet[2].codigo = prodC.codigo;
  strcpy(vet[2].descricao, prodC.descricao);
  vet[2].preco = prodC.preco;

  // ITEM B
  Produto *vet2[4];
  vet2[0] = &prodA;
  vet2[1] = &prodB;
  vet2[2] = &prodB;

  // ALTERAÇÕES
  // PEDIDO 1 DA LISTA
  vet2[2] = &prodC;
  (*vet2[2]).codigo = 100;

  // PEDIDO 2 DA LISTA
  strcpy((*vet2[1]).descricao, "Mouse sem fio"); 

  // PEDIDO 3 DA LISTA
  Produto prodD = { 4, "Monitor", 165.5 };
  vet2[3] = &prodD;

  imprimeProdutos(vet2, TAM);
}