#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DADOS
typedef struct {
  char day[50];
  char month[50];
  char year[50];
  char hour[50];
  char minute[50];
  char second[50];
  char timezone[50];
} Date;

// FUNÇÕES
// - Criar uma data
// - Destruir uma data
// - Atualizar uma data
// - Formatar uma data
// - Adicionar um dia
// - Subtrair um dia 

Date* date_create(char* day, char* month, char* year, char* hour, char* minute, char* second, char* timezone) {
  Date* date = (Date*)malloc(sizeof(Date));
  strcpy(date->day, day);
  strcpy(date->month, month);
  strcpy(date->year, year);
  strcpy(date->hour, hour);
  strcpy(date->minute, minute);
  strcpy(date->second, second);
  strcpy(date->timezone, timezone);

  printf("Created: %s-%s-%sT%s:%s:%sTZ%s\n", date->year, date->month, date->day, date->hour, date->minute, date->second, date->timezone);
  return date;
}

int main() {

  Date* date = date_create("8", "4", "2022", "N", "N", "N", "N");

  return 0;
}