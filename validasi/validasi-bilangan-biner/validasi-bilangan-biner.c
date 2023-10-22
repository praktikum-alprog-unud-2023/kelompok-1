#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void input_binary_str(char *input_param)
{
  char input[100];
  int i = 0, error = 0;

  fflush(stdin);
  fgets(input, sizeof(input), stdin);

  if (input[0] == '\0')
    error = 1;

  while (input[i] != '\0' && input[i] != '\n')
  {
    if (strchr("01", input[i]))
    {
      i++;
    }
    else
    {
      error = 1;
      break;
    }
  }

  if (error == 1)
  {
    printf("\nInvalid binary number!");
    printf("\nSilahkan Masukan Angka Kembali : ");
    return input_binary_str(input_param);
  }
  input[i] = '\0';
  strcpy(input_param, input);
}

int main()
{
  char inputBinaryNumber[100];

  printf("\n======================================");
  printf("\nValidasi Bilangan Biner");
  printf("\n--------------------------------------");
  printf("\nMasukan bilangan biner: ");
  input_binary_str(inputBinaryNumber);
  printf("%s\n", inputBinaryNumber);

  return 0;
}