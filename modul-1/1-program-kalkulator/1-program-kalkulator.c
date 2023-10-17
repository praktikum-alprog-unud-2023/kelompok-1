#include <stdio.h>
#include <stdlib.h>

int perjumlahan();
int pengurangan();
int perkalian();
int pembagian();
int modulus();
int ulangprogram();
int validasipil();
int validasiangka();

int main()
{
  int i;
  double x, y;
  printf("===MENU KALKULATOR SEDERHANA===\n");
  printf("\n");
  printf("1 = Perjumlahan\n");
  printf("2 = Pengurangan\n");
  printf("3 = Perkalian\n");
  printf("4 = Pembagian\n");
  printf("5 = Modulus\n");
  printf("0 = Keluar");
  printf("\n");
  printf("Masukan Pilihan : ");
  validasipil(&i);
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
  case 0 :
  printf("TERIMA KASIH SUDAH MENGGUNAKAN PROGRAM INI !\n");
  return 0;
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
  validasiangka(&angka1);
  printf("Angka kedua    : ");
  validasiangka(&angka2);
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
  validasiangka(&angka1);
  printf("Angka kedua    : ");
  validasiangka(&angka2);
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
  validasiangka(&angka1);
  printf("Angka kedua    : ");
  validasiangka(&angka2);
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
  validasiangka(&angka1);
  printf("Angka kedua    : ");
  validasiangka(&angka2);
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
  validasipil(&i);
  switch (i)
  {
  case 1:
    system("cls");
    main();
    break;
  case 2:
    printf("TERIMA KASIH SUDAH MENGGUNAKAN PROGRAM INI !\n");
    break;
  }
}

int validasipil(int *angka)
{
  char strBil[100];
  while (1)
  {
    if (scanf("%[^\n]", strBil) != 1)
    {
      getchar() != '\n';
    }
    else
    {
      char *endptr;

      *angka = strtol(strBil, &endptr, 10);
      if (*endptr == '\0' && *angka >= 0 && *angka <= 5)
      {
        return *angka;
        break;
      }
      else
      {
        printf("Input invalid, Silahkan input Pilihan kembali: ");
      }
    }
  }
}
int validasiangka(double *angka)
{
  getchar() != '\n';
  char strBil[100];
  while (1)
  {
    if (scanf("%[^\n]", strBil) != 1)
    {
      printf("Input invalid,silahkan input angka kembali: ");
      getchar() != '\n';
    }
    else
    {
      char *endptr;
      *angka = strtof(strBil, &endptr);
      if (*endptr == '\0')
      {
        return *angka;
        break;
      }
    }
  }
}