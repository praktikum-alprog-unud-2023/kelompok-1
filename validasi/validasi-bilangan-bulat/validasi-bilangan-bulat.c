#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int validInt(int *var)
{
  char buff[1020];
  char cek;
  fflush(stdin);
  if (fgets(buff, sizeof(buff), stdin) != NULL)
  {
    if (sscanf(buff, "%d %c", var, &cek) == 1)
    {
      return 1;
    }
  }
  return 0;
}

void ReValidInt(int *var, char *prompt)
{
  while (1)
  {
    printf(prompt);
    if (validInt(var))
      break;
    printf("Input Tidak Sesuai! \n");
    printf("\n");
  }
}

int main()
{
  int inputInt;

  printf("\n======================================");
  printf("\nValidasi Bilangan Bulat");
  printf("\n--------------------------------------\n");

  ReValidInt(&inputInt, "Masukan angka: ");
  printf("%d\n", inputInt);

  return 0;
}