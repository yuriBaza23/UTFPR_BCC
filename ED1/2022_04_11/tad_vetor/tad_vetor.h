#ifndef _TAD_VETOR_
#define _TAD_VETOR_

#include <stdlib.h>
#include <stdbool.h>

/********************************************
 * DADOS
 *******************************************/
typedef struct vetor Vetor;

/********************************************
 * OPERAÇÕES
 *******************************************/

// 1. Criar uma nova sequência
Vetor* vet_criar();

// 2. Inserir um elemento no final da sequência
bool vet_anexar(Vetor* v, int elemento);

// 3. Inserir um elemento em qualquer posição da sequência
bool vet_inserir(Vetor* v, int elemento, int posicao);

// 4. Substituir um elemento em uma determinada posição
bool vet_substituir(Vetor* v, int posicao, int novoElemento);

// 5. Remover um elemento de uma determinada posição
bool vet_removerPosicao(Vetor* v, int posicao, int* endereco);

// 6. Remover um elemento de acordo com o seu valor. Caso haja valores repetidos remover apenas a primeira ocorrência.
int vet_removerElemento(Vetor* v, int elemento);

// 7. Recuperar quantos elementos estão armazenados na sequência.
int vet_tamanho(Vetor* v);

// 8. Recuperar qual elemento está armazenado em uma determinada posição
bool vet_elemento(Vetor* v, int posicao, int* saida);

// 9. Recuperar a posição em que um determinado elemento está armazenado. Caso haja valores repetidos, recuperar a primeira ocorrência.
int vet_posicao(Vetor* v, int elemento);

// 10. Imprimir a sequência
void vet_imprimir(Vetor* v);

// 11. Desalocar
void vet_desalocar(Vetor** endVetor);

// 12. Devolve o vetor na forma de String
bool vet_toString(Vetor* v, char* enderecoString);

#endif