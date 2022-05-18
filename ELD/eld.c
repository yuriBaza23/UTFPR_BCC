#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct info {
  char version[16];
  char lastUpdate[9];
} Info;

int printHeader(int option, Info info) {
  printf("[ELD %s] -------------------------------\n", info.version);
  printf("Ultima atualização em %s\n\n", info.lastUpdate);
  scanf("%d", &option);

  return option;
}

int main() {
  Info appInfo;
  strcpy(appInfo.version, "v0.0.1-beta");
  strcpy(appInfo.lastUpdate, "19/03/22");
  int option;

  

  return 0;
}