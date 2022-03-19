#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int hora;
  int minutos;
  int segundos;
} Horario;

typedef struct {
  int dia;
  int mes;
  int ano;
} Data;

typedef struct {
  Horario horario;
  Data data;
  char texto[256];
} Compromisso;

Compromisso criarCompromisso(Horario horarioCompromisso, Data dataCompromisso, char* tituloCompromisso) {
  Compromisso compromisso;

  compromisso.horario = horarioCompromisso;
  compromisso.data = dataCompromisso;
  strcpy(compromisso.texto, tituloCompromisso);

  return compromisso;
}

int main() {
  // ENTRADA
  Horario horario;
  Data data;

  horario.hora = 17;
  horario.minutos = 40;
  horario.segundos = 36;

  data.dia = 11;
  data.mes = 3;
  data.ano = 2022;

  char titulo[] = { "Ler livro: As Crônica de Nárnia." };

  // PROCESSAMENTO
  Compromisso meuCompromisso = criarCompromisso(horario, data, titulo);

  // SAIDA
  printf("-----------------------------------\n");
  printf("[Compromisso] %s\n", meuCompromisso.texto);
  printf("Data: %d/%d/%d     ", meuCompromisso.data.dia, meuCompromisso.data.mes, meuCompromisso.data.ano);
  printf("Horário: %d:%d:%d\n", meuCompromisso.horario.hora, meuCompromisso.horario.minutos, meuCompromisso.horario.segundos);
  printf("Obs: Esse compromisso foi definido por você\n");
  printf("-----------------------------------\n");

  return 0;
}