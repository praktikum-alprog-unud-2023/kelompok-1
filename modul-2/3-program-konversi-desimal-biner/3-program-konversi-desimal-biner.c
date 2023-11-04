#include <stdio.h>
#include <math.h>

int konversiDesimal(char biner[])
{
  int panjang = 0;
  while (biner[panjang] != '\0')
  {
    panjang++;
  }
  int desimal = 0;
  int pangkat = 0;
  for (int i = panjang - 1; i >= 0; i--)
  {
    if (biner[i] == '1')
    {
      desimal += pow(2, pangkat);
    }
    pangkat++;
  }
  return desimal;
}

void konversiBiner(int n)
{
  if (n == 0)
  {
    return;
  }
  konversiBiner(n / 2);
  printf("%d", n % 2);
}

void namaKelompok()
{
  printf("=================== KELOMPOK I ===================\n");
  printf("1. NI NENGAH SENJA SRI PRATIWI (2305551014)\n");
  printf("2. I GUSTI AYU MARTINI (2305551020)\n");
  printf("3. PUTU EKA DODY ARSANA PUTRA (2305551075)\n");
  printf("4. KALVIN ANGELITO ANG (2305551115)\n");
  printf("5. MUHAMMAD DZIKRI DHANIAWAN (2305551146)\n");
  printf("6. VINCENTIUS BONAVERREL DOMINICO (2305554176)\n");
  printf("=================================================\n\n");
}

int main()
{
  int desimal;
  char biner[32];
  int pilihan;
  char lanjut = 'y';

  namaKelompok();

  do
  {

    printf("=================== Pilih Opsi ===================\n");
    printf("1. Desimal Ke Biner\n2. Biner Ke Desimal\n");
    printf("\n** Pilih [1 or 2] : ");
    scanf("%d", &pilihan);
    printf("\n");

    if (pilihan == 1)
    {
      printf("=========== KONVERSI DESIMAL KE BINER ===========\n");
      printf("* Masukkan bilangan desimal\t: ");
      if (scanf("%d", &desimal) != 1)
      {
        printf("Masukan Input Bilangan Desimal !!!\n\n");
        while ((getchar()) != '\n')
          ;
        continue;
      }
      printf("* Konversi ke biner\t\t: ");
      if (desimal == 0)
      {
        printf("0");
      }
      else
      {
        konversiBiner(desimal);
      }
      printf("\n");
    }
    else if (pilihan == 2)
    {
      printf("=========== KONVERSI BINER KE DESIMAL ===========\n");
      printf("* Masukkan bilangan biner\t: ");
      scanf("%s", biner);

      for (int i = 0; biner[i] != '\0'; i++)
      {
        if (biner[i] != '0' && biner[i] != '1')
        {
          if (i == 0)
          {
            printf("Masukkan Input Bilangan Biner !!!\n");
          }
          continue;
        }
      }

      desimal = konversiDesimal(biner);
      printf("* Konversi ke desimal\t\t: %d\n", desimal);
    }
    else
    {
      printf("Pilih Opsi 1 atau 2 !!!\n\n");
    }
    printf("\n* Konversi Lagi? [y/n]\t\t: ");
    while ((getchar()) != '\n')
      ;
    scanf("%c", &lanjut);
    printf("\n");
  } while (lanjut == 'y' || lanjut == 'Y');

  return 0;
}
