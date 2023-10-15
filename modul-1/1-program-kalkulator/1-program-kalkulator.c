#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int perjumlahan();
int pengurangan();
int perkalian();
int pembagian();
int modulus();
int ulangprogram();

int main()
{
  int i;
  printf("MENU OPERASI ARITMATIKA\n");
  printf("\n");
  printf("1 = Perjumlahan\n");
  printf("2 = Pengurangan\n");
  printf("3 = Perkalian\n");
  printf("4 = Pembagian\n");
  printf("5 = Modulus\n");
  printf("Masukan Pilihan : ");
  while (scanf("%d", &i) != 1 || i < 0 || i > 5)
  {
    printf("Masukan salah, silahkan Masukan Pilihan: ");
    while (getchar() != '\n')
      ;
  }
  system("cls");
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
    break;
  }
  system("pause");
  system("cls");
  ulangprogram();
}
int perjumlahan()
{
  double angka1, angka2, hasil;
  printf("=====OPERASI PENJUMLAHAN=====\n");
  printf("\n");
  printf("\n");
  printf("Angka pertama  : ");
  while (scanf("%lf", &angka1) != 1)
  {
    printf("invalid , Masukan Angka  :");
    while (getchar() != '\n')
      ;
  }
  printf("Angka kedua    : ");
  while (scanf("%lf", &angka2) != 1)
  {
    printf("invalid , Masukan Angka  :");
    while (getchar() != '\n')
      ;
  }
  hasil = angka1 + angka2;
  printf("\nHasilnya adalah: %g\n", hasil);
  return 0;
}

int pengurangan()
{
  double angka1, angka2, hasil;
  printf("=====OPERASI PENGURANGAN=====\n");
  printf("\n");
  printf("\n");
  printf("Angka pertama  : ");
  while (scanf("%lf", &angka1) != 1)
  {
    printf("invalid , Masukan Angka  :");
    while (getchar() != '\n')
      ;
  }
  printf("Angka kedua    : ");
  while (scanf("%lf", &angka2) != 1)
  {
    printf("invalid , Masukan Angka  :");
    while (getchar() != '\n')
      ;
  }
  hasil = angka1 - angka2;
  printf("\nHasilnya adalah: %g\n", hasil);
  return 0;
}

int perkalian()
{
  double angka1, angka2, hasil;
  printf("=====OPERASI PERKALIAN=====\n");
  printf("\n");
  printf("\n");
  printf("Angka pertama  : ");
  while (scanf("%lf", &angka1) != 1)
  {
    printf("invalid , Masukan Angka  :");
    while (getchar() != '\n')
      ;
  }
  printf("Angka kedua    : ");
  while (scanf("%lf", &angka2) != 1)
  {
    printf("invalid , Masukan Angka  :");
    while (getchar() != '\n')
      ;
  }
  hasil = angka1 * angka2;
  printf("\nHasilnya adalah: %g\n", hasil);
  return 0;
}

int pembagian()
{
  double angka1, angka2, hasil;
  printf("=====OPERASI PEMBAGIAN=====\n");
  printf("\n");
  printf("\n");
  printf("Angka pertama  : ");
  while (scanf("%lf", &angka1) != 1)
  {
    printf("invalid , Masukan Angka  :");
    while (getchar() != '\n')
      ;
  }
  printf("Angka kedua    : ");
  while (scanf("%lf", &angka2) != 1)
  {
    printf("invalid , Masukan Angka  :");
    while (getchar() != '\n')
      ;
  }
  hasil = angka1 / angka2;
  printf("\nHasilnya adalah: %g\n", hasil);
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
    return 0;
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

int ulangprogram()
{
  int i;
  printf("Apakah Anda Ingin Mengulang Program?    \n");
  printf("\n");
  printf("1. Ulang\n");
  printf("2. Keluar\n");
  printf("\n");
  printf("Masukkan Pilihan : ");
  while (scanf("%d", &i) != 1 || i < 0 || i > 5)
  {
    printf("Masukan salah, silahkan Masukan Pilihan lagi: ");
    while (getchar() != '\n')
      ;
  }
  switch (i)
  {
  case 1:
    system("cls");
    main();
    break;
  case 2:
    printf("TERIMA KASIH SUDAH MENGGUNAKAN PROGRAM INI\n");
    break;
  }
}
