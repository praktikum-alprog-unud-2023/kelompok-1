#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

double input_positive_double()
{
  char input[11];
  int i = 0, error = 0, negative = 0, decimal = 0, whole_num = 0, fract_num = 0, chars = 0;
  float zero_point = 1, output;

  fflush(stdin);
  fgets(input, sizeof(input), stdin);

  if (input[0] == '\0')
    error = 1;

  while (input[i] != '\0' && input[i] != '\n')
  {
    if (input[i] == '-')
    {
      error = 1;
      break;
    }
    else if (input[i] == '.')
    {
      decimal++;
      if (decimal > 1 || input[i + 1] == '\0' || input[0] == '.')
      {
        error = 1;
        break;
      }
      i++;
    }
    else if (isdigit(input[i]))
    {
      if (decimal == 1)
      {
        fract_num = (fract_num * 10) + (input[i] - 48);
        chars++;
        i++;
      }
      else
      {
        whole_num = (whole_num * 10) + (input[i] - 48);
        i++;
      }
    }
    else
    {
      error = 1;
      break;
    }
  }

  if (decimal == 1)
  {
    for (int j = 0; j < chars; j++)
    {
      zero_point /= 10;
    }
    output = fract_num * zero_point + whole_num;
  }
  else
    output = whole_num;

  if (negative == 1)
    output -= (output * 2);

  if (error == 1)
  {
    printf("\nInput Tidak Sesuai ");
    printf("\nSilahkan Masukan Angka Kembali : ");
    return input_positive_double();
  }
  else
    return output;
}
int main()
{
  float inputDouble;

  printf("\n======================================");
  printf("\nValidasi Bilangan Desimal Positif");
  printf("\n--------------------------------------");
  printf("\nMasukan bilangan desimal positive: ");
  inputDouble = input_positive_double();
  printf("%f\n", inputDouble);

  return 0;
}