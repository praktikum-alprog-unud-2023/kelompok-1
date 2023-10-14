#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int input_positive_int()
{
  char input[10];
  int i = 0, output, error = 0;

  fflush(stdin);
  fgets(input, sizeof(input), stdin);

  if (input[0] == '\0')
    error = 1;

  while (input[i] != '\0' && input[i] != '\n')
  {
    if (isdigit(input[i]))
      i++;
    else
    {
      error = 1;
      break;
    }
  }

  output = atoi(input);

  if (error == 1)
  {
    printf("\nInput Tidak Sesuai!");
    printf("\nMasukan Angka Kembali : ");
    return input_positive_int();
  }
  else
    return output;
}

int main()
{
  int inputInt2;

  printf("\n======================================");
  printf("\nValidasi Bilangan Bulat Positif");
  printf("\n--------------------------------------");
  printf("\nMasukan bilangan bulat positif : ");
  inputInt2 = input_positive_int();
  printf("%d\n", inputInt2);

  return 0;
}