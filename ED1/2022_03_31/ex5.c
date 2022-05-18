#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produto{
	unsigned int codigo;
	char nome[50];
	float preco;
} Produto;

void criaProduto(unsigned int codigo, char* nome, float preco, Produto** endereco) {
  Produto* dinamico = (Produto*)calloc(1, sizeof(Produto));

  dinamico->codigo = codigo;
  strcpy(dinamico->nome, nome);
  dinamico->preco = preco;

  *endereco = dinamico;
}

void imprimeProduto(Produto** endereco) {
  printf("[Produto %d] -------------------\n", (*endereco)->codigo);
  printf("Nome: %s\n", (*endereco)->nome);
  printf("Preço: %.2f\n", (*endereco)->preco);
  printf("--------------------------------\n");
}

int main() {
  Produto* produto;

  criaProduto(3, "Mouse", 52.5, &produto);
  imprimeProduto(&produto);

  return 0;
}