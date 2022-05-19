#include "pilha.h"
#include "string.h"
#include <ctype.h>

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

float fazer_operacao(char operacao, int v1, int v2) {
	float v3 = 0;
	if(operacao == '*') {
		v3 = v1 * v2;
	} else if(operacao == '+') {
		v3 = v1 + v2;
	} else if(operacao == '-') {
		v3 = v1 - v2;
	} else if(operacao == '/') {
		v3 = v1 / v2;
	}

	return v3;
}

void calculadora(char* expressao) {
	printf("--------------------------\n");
	printf("| %s\n", expressao);
	printf("--------------------------\n\n");
	printf("Calculando...\n");
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

int pilha_desempilhar(Pilha* p) {
	if(!pilha_vazia(p)) {
		No* aux = p->topo->prox;
		TipoElemento elemento = p->topo->dado;
		p->topo = aux;
		p->qtdeElementos--;

		if(isdigit(elemento)) {
			return atoi(&elemento);
		} 
		return 0;
	}
	return 0;
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
	Pilha* p = pilha_criar();
	float num;
	bool j = false;

	calculadora(expressao);

	int i = 0;
	while(expressao[i] != '\0') {
		pilha_empilhar(p, expressao[i]);
		if(!isdigit(expressao[i])) {
			pilha_desempilhar(p);
			int v1 = pilha_desempilhar(p);
			int v2 = j ? num : pilha_desempilhar(p);

			num = fazer_operacao(expressao[i], v1, v2);

			j = true;
		}

		i++;
	}

	printf("Resultado: %.2f\n", num);
	return 0;
}