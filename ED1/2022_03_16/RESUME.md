# Resumo da aula do dia
Começa-se a estudar sobre *ponteiros* na linguagem C.
  
```c
// *: Indica que será armazenado um endereço
// Tipo: Naquele endereço há um valor do tipo especificado 
<tipo> *<nome>
```
  
```c
// Atrbui a variável inteira "qtde" o valor 30;
int qtde = 30;
// Cria um ponteiro que armazenará um endereço que nele há um valor inteiro
int *p = NULL;
// Nesse ponteiro, guarda-se o endereço de qtde
p = &qtde;
```
  
É interessante saber qu eum ponteriro, independentemente do seu tipo, sempre terá 8 bytes. O que varia é o tamanho da variável que ele aponta.
  
### Acessando um endereço
```c
// Atrbui a variável inteira "qtde" o valor 30;
int qtde = 30;
// Cria um ponteiro que armazenará um endereço que nele há um valor inteiro
int *p = NULL;
// Nesse ponteiro, guarda-se o endereço de qtde
p = &qtde;
// O asterico pode ser usado para acessar o endereço
*p = 50; // Agora o valor de quantidade vale 50;
```