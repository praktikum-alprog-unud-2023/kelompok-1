#include <stdio.h>

int perjumlahan(), pengurangan(), perkalian(), pembagian(), modulus();

int main()
{
  int i;
  printf("MENU OPERASI ARITMATIKA\n");
  printf("1 = Perjumlahan\n");
  printf("2 = Pengurangan\n");
  printf("3 = Perkalian\n");
  printf("4 = Pembagian\n");
  printf("5 = Modulus\n");
  printf("Pilihan : ");
  scanf("%d", &i);

  switch (i)
  {
  case 1:
    perjumlahan();
    break;
  case 2:
    pengurangan();
    break;
  case 3:
    perkalian();
    break;
  case 4:
    pembagian();
    break;
  case 5:
    modulus();
    break;
  default:
    printf("Invalid Input");
    break;
  }
}
int perjumlahan()
{
  double angka1, angka2, hasil;
  printf("=====OPERASI PENJUMLAHAN=====\n");
  printf("\n");
  printf("\n");
  printf("Angka pertama  : ");
  if (scanf("%lf", &angka1) != 1)
  {
    printf("\ninvalid , Masukan Angka\n");
    return 1;
  }
  printf("Angka kedua    : ");
  if (scanf("%lf", &angka2) != 1)
  {
    printf("invalid , Masukan Angka\n");
    return 1;
  }
  hasil = angka1 + angka2;
  if (hasil == (int)hasil)
  {
    printf("\nHasilnya adalah: %.0lf\n", hasil);
  }
  else if (hasil == (double)hasil)
  {
    printf("\nHasilnya adalah: %.2lf\n", hasil);
  }
  else
    printf("Hasilnya Invalid");

  return 0;
}

int pengurangan()
{
  double angka1, angka2, hasil;
  printf("=====OPERASI PENGURANGAN=====\n");
  printf("\n");
  printf("\n");
  printf("Angka pertama  : ");
  if (scanf("%lf", &angka1) != 1)
  {
    printf("invalid , Masukan Angka\n");
    return 1;
  }
  printf("Angka kedua    : ");
  if (scanf("%lf", &angka2) != 1)
  {
    printf("invalid , Masukan Angka\n");
    return 1;
  }

  hasil = angka1 - angka2;
  if (hasil == (int)hasil)
  {
    printf("\nHasilnya adalah: %.0lf\n", hasil);
  }
  else if (hasil == (double)hasil)
  {
    printf("\nHasilnya adalah: %.2lf\n", hasil);
  }
  else
    printf("Hasilnya Invalid");

  return 0;
}

int perkalian()
{
  double angka1, angka2, hasil;
  printf("=====OPERASI PERKALIAN=====\n");
  printf("\n");
  printf("\n");
  printf("Angka pertama  : ");
  if (scanf("%lf", &angka1) != 1)
  {
    printf("invalid , Masukan Angka\n");
    return 1;
  }
  printf("Angka kedua    : ");
  if (scanf("%lf", &angka2) != 1)
  {
    printf("invalid , Masukan Angka\n");
    return 1;
  }

  hasil = angka1 * angka2;
  if (hasil == (int)hasil)
  {
    printf("\nHasilnya adalah: %.0lf\n", hasil);
  }
  else if (hasil == (double)hasil)
  {
    printf("\nHasilnya adalah: %.2lf\n", hasil);
  }
  else
    printf("Hasilnya Invalid");

  return 0;
}

int pembagian()
{
  double angka1, angka2, hasil;
  printf("=====OPERASI PEMBAGIAN=====\n");
  printf("\n");
  printf("\n");
  printf("Angka pertama  : ");
  if (scanf("%lf", &angka1) != 1)
  {
    printf("invalid , Masukan Angka\n");
    return 1;
  }
  printf("Angka kedua    : ");
  if (scanf("%lf", &angka2) != 1)
  {
    printf("invalid , Masukan Angka\n");
    return 1;
  }

  hasil = angka1 / angka2;
  if (hasil == (int)hasil)
  {
    printf("\nHasilnya adalah: %.0lf\n", hasil);
  }
  else if (hasil == (double)hasil)
  {
    printf("\nHasilnya adalah: %.2lf\n", hasil);
  }
  else
    printf("Hasilnya Invalid");

  return 0;
}

int modulus()
{
  int angka1, angka2, hasil;
  printf("=====OPERASI MODULUS=====\n");
  printf("\n");
  printf("\n");
  printf("Angka pertama  : ");
  if (scanf("%d", &angka1) != 1)
  {
    printf("invalid , Masukan Angka\n");
    return 1;
  }
  printf("Angka kedua    : ");
  if (scanf("%d", &angka2) != 1)
  {
    printf("invalid , Masukan Angka\n");
  }

  hasil = (int)angka1 % (int)angka2;
  printf("\nHasilnya adalah  : %d\n", hasil);

  return 0;
}
