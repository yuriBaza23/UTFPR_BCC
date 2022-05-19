#ifndef _PILHA_H_
#define _PILHA_H_

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

typedef char TipoElemento;
/**************************************
* DADOS
**************************************/
typedef struct pilha Pilha;

/**************************************
* PROTÓTIPOS
**************************************/
Pilha* pilha_criar();
void pilha_destruir(Pilha** endereco);
bool pilha_empilhar(Pilha* p, TipoElemento elemento);
int pilha_desempilhar(Pilha* p); 
void pilha_imprimir(Pilha* p);
bool pilha_vazia(Pilha* p);

void pilha_inverter(Pilha* p);
int  pilha_calcularPos(char* expressao);

void inverter(char* str);
int calcular_pos(char* expressao);

#endif