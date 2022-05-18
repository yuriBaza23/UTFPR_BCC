#include "tad_date.h"

/***************************************
 * DADOS
 ***************************************/
struct date {
  int day;
  int month;
  int year;
};

/***************************************
 * IMPLEMENTAÇÃO
 ***************************************/
Date* date_create(int day, int month, int year) {
  Date* date = (Date*)malloc(sizeof(Date));
  date->day = day;
  date->month = month;
  date->year = year;
  return date;
}

void date_destroy(Date** date) {
  free(*date);
  *date = NULL;
}

void date_duplicate(Date* date, Date** newDate) {
  Date* temp = date_create(date->day, date->month, date->year);
  *newDate = temp;
}

void date_print(Date* date) {
  printf("%02d/%02d/%d\n", date->day, date->month, date->year);
}