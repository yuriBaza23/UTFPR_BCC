#include <stdio.h>
#include "tad_date.h"

int main() {

  Date* dateDup;
  Date* date = date_create(23, 2, 2001);

  date_duplicate(date, &dateDup);

  date_print(date);
  date_print(dateDup);

  date_destroy(&date);
  date_destroy(&dateDup);

  return 0;
}