#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produto {
    int codigo;
    char descricao[12];
    float preco;
} Produto;

void imprimeStruct(Produto *ponteiroProduto) {
  printf("Código do produto: %d\n", ponteiroProduto->codigo);
  printf("Descrição do produto: %s\n", ponteiroProduto->descricao);
  printf("Preço do produto: %.2f\n", ponteiroProduto->preco);
  printf("--------------------------------\n");
}

void opcoesImprimeStruct(Produto *ponteiroProduto, Produto produto) {
  printf("[AÇUCAR SINTÁTICO] PRIMEIRO JEITO DE IMPRIMIR:\n");
  printf("Código do produto: %d\n", ponteiroProduto->codigo);
  printf("Descrição do produto: %s\n", ponteiroProduto->descricao);
  printf("Preço do produto: %.2f\n", ponteiroProduto->preco);
  printf("--------------------------------\n");

  printf("[COM PONTO] SEGUNDO JEITO DE IMPRIMIR:\n");
  printf("Código do produto: %d\n", produto.codigo);
  printf("Descrição do produto: %s\n", produto.descricao);
  printf("Preço do produto: %.2f\n", produto.preco);
  printf("--------------------------------\n");

  printf("[NOTAÇÃO DE PONTEIROS] TERCEIRO JEITO DE IMPRIMIR:\n");
  printf("Código do produto: %d\n", (*ponteiroProduto).codigo);
  printf("Descrição do produto: %s\n", (*ponteiroProduto).descricao);
  printf("Preço do produto: %.2f\n", (*ponteiroProduto).preco);
  printf("--------------------------------\n");
}

int main() {
    Produto produto1;
    Produto *p = &produto1;
    int *pi = &produto1.codigo;
    char *pc = produto1.descricao;
    float *pf = &produto1.preco;

    p->codigo = 10;
    strcpy(p->descricao, "Teclado");
    p->preco = 98.5;

    imprimeStruct(p);
    opcoesImprimeStruct(p, produto1);

    return 0;
}