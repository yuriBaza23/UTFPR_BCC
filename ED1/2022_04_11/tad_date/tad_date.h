#ifndef TAD_DATE_H
#define TAD_DATE_H

#include <stdio.h>
#include <stdlib.h>

/***************************************
 * DADOS
 ***************************************/
typedef struct date Date;

/***************************************
 * PROTÓTIPOS
 ***************************************/
Date* date_create(int day, int month, int year);
void date_destroy(Date** date);
void date_duplicate(Date* date, Date** newDate);
void date_print(Date* date);

#endif