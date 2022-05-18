#include "pilha.h"
#include "string.h"

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

} 

void pilha_imprimir(Pilha* p) {
	TipoElemento* vetor = (TipoElemento*)malloc(p->qtdeElementos * sizeof(TipoElemento));
	vetor = devolve_elementos(p);
	int i = 0;
	int j = p->qtdeElementos;
	printf("PILHA [ ");
	while (i != p->qtdeElementos) {
		printf("%c ", vetor[j-1]);
		i++;
		j--;
	}
	printf("]\n\n");
}

void pilha_inverter(Pilha* p) {
	No* aux = p->topo;
	int i = 0;
	printf("PILHA [ ");
	while (i != p->qtdeElementos) {
		printf("%c ", aux->dado);
		aux = aux->prox;
		i++;
	}
	printf("]\n\n");
}

void inverter(char* str) {
	Pilha* p = pilha_criar();

	int i = 0;
	while(str[i] != '\0') {
		pilha_empilhar(p, str[i]);
		i++;
	}

	pilha_imprimir(p);
	pilha_inverter(p);
}

int calcular_pos(char* expressao) {
	return 0;
}