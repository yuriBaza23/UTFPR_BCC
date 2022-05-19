#include "pilha.h"
#include <string.h>

/**************************************
* DADOS
**************************************/
typedef struct no{
	TipoElemento dado;
	struct no *prox;
}No;

struct pilha{
	No *topo;
	int qtdeElementos;
};

/**************************************
* IMPLEMENTAÇÃO
**************************************/
// Funções auxiliares
TipoElemento* devolve_elementos(Pilha* p) {
	No* aux = p->topo;
	TipoElemento* vetor = (TipoElemento*)malloc(p->qtdeElementos * sizeof(TipoElemento));
	int i = 0;
	while (i != p->qtdeElementos) {
		vetor[i] = aux->dado;
		aux = aux->prox;
		i++;
	}

	return vetor;	
} 

// Desenvolva as funções
Pilha* pilha_criar() {
	Pilha *p = (Pilha*)malloc(sizeof(Pilha));
	p->topo = NULL;
	p->qtdeElementos = 0;
	return p;
}

void pilha_destruir(Pilha** endereco) {

}

bool pilha_vazia(Pilha* p) {
	if(p->topo == NULL){
		return true;
	}

	return false;
}

bool pilha_empilhar(Pilha* p, TipoElemento elemento) {
	No* novoElemento = (No*)malloc(sizeof(No));
	novoElemento->dado = elemento;

	novoElemento->prox = pilha_vazia(p) ? NULL : p->topo;
	p->topo = novoElemento;
	p->qtdeElementos++;

	return true;
}

bool pilha_desempilhar(Pilha* p, TipoElemento* saida) {
	if(!pilha_vazia(p)) {
		No* aux = p->topo->prox;
		TipoElemento elemento = p->topo->dado;
		p->topo = aux;
		p->qtdeElementos--;

		*saida = elemento;
		return true;
	}

	return false;
} 

bool pilha_topo(Pilha* p, TipoElemento* saida) {

} 

void pilha_imprimir(Pilha* p) {
	TipoElemento* vetor = (TipoElemento*)malloc(p->qtdeElementos * sizeof(TipoElemento));
	vetor = devolve_elementos(p);
	int i = 0;
	int j = p->qtdeElementos;
	printf("PILHA [ ");
	while (i != p->qtdeElementos) {
		printf("%d ", vetor[j-1]);
		i++;
		j--;
	}
	printf("]\n\n");
}

int pilha_tamanho(Pilha* p) {
	return p->qtdeElementos;
}

Pilha* pilha_clone(Pilha* p) {
	TipoElemento* vetor = (TipoElemento*)malloc(p->qtdeElementos * sizeof(TipoElemento));
	vetor = devolve_elementos(p);
	Pilha* clone = pilha_criar();
	int i = 0;
	int j = p->qtdeElementos;
	while(i != p->qtdeElementos) {
		pilha_empilhar(clone, vetor[j-1]);
		j--;
		i++;
	}

	return clone;
}

void pilha_inverter(Pilha* p) {
	No* aux = p->topo;
	int i = 0;
	printf("PILHA [ ");
	while (i != p->qtdeElementos) {
		printf("%d ", aux->dado);
		aux = aux->prox;
		i++;
	}
	printf("]\n\n");
}

bool pilha_empilharTodos(Pilha* p, TipoElemento* vetor, int tamVetor) {
	int i = 0;
	while (i != tamVetor) {
		pilha_empilhar(p, vetor[i]);
		i++;
	}

	return true;
}

bool pilha_toString(Pilha* f, char* str) {
	char tmp[200] = "\0";
  strcat(str, "[");
	TipoElemento* vetor = (TipoElemento*)malloc(f->qtdeElementos * sizeof(TipoElemento));
	vetor = devolve_elementos(f);
  for(int i = 0; i < f->qtdeElementos; i++) {
    sprintf(tmp, "%d", vetor[i]);
    strcat(str, tmp);
    if(i != f->qtdeElementos-1) {
      strcat(str, ", ");
    }
  }
  strcat(str, "]");
  return str;
}