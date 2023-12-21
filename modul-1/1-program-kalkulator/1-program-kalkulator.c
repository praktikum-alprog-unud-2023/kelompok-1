#include "../../validasi/utility/utility.h"

char namaProgram[] = "PROGRAM KALKULATOR";

int pilihan;
int validasiBil(double *angka);

void penjumlahan();
void pengurangan();
void perkalian();
void pembagian();
void modulus();
void menuUtama();

int main()
{
  startingScreen();
  menuUtama();
  pauseMsg();
  endMsg();
}

void penjumlahan()
{
  double angka1, angka2, hasil;
  head();
  outLine();
  outMsg("OPERASI PENJUMLAHAN");
  outLine();
  printf("angka pertama : ");
  validasiBil(&angka1);
  printf("angka kedua   : ");
  validasiBil(&angka2);
  hasil = angka1 + angka2;
  outLine();
  outMsg("Hasilnya adalah %g", hasil);
  outLine();
}

void pengurangan()
{
  double angka1, angka2, hasil;
  head();
  outLine();
  outMsg("OPERASI PENGURANGAN");
  outLine();
  printf("angka pertama : ");
  validasiBil(&angka1);
  printf("angka kedua   : ");
  validasiBil(&angka2);
  hasil = angka1 - angka2;
  outLine();
  outMsg("Hasilnya adalah %g", hasil);
  outLine();
}

void perkalian()
{
  double angka1, angka2, hasil;
  head();
  outLine();
  outMsg("OPERASI PERKALIAN");
  outLine();
  printf("angka pertama : ");
  validasiBil(&angka1);
  printf("angka kedua   : ");
  validasiBil(&angka2);
  hasil = angka1 * angka2;
  outLine();
  outMsg("Hasilnya adalah %g", hasil);
  outLine();
}

void pembagian()
{
  double angka1, angka2, hasil;
  head();
  outLine();
  outMsg("OPERASI PEMBAGIAN");
  outLine();
  printf("angka pertama : ");
  validasiBil(&angka1);
  printf("angka kedua   : ");
  validasiBil(&angka2);
  while (angka2 == 0)
  {
    outLine();
    outMsg("Inputan Invalid");
    outLine();
    printf("Masukan Angka  :");
    validasiBil(&angka2);
  }
  hasil = angka1 / angka2;
  outLine();
  outMsg("Hasilnya adalah %g", hasil);
  outLine();
}

void modulus()
{
  int angka1, angka2, hasil;
  head();
  outLine();
  outMsg("OPERASI MODULUS");
  outLine();
  outMsg("Masukan Angka");
  outLine();
  inputThisInt("Angka Pertama  :", &angka1);
  inputThisInt("Angka Kedua    :", &angka2);
  hasil = (int)angka1 % (int)angka2;
  outLine();
  outMsg("Hasilnya adalah %i", hasil);
  outLine();
}
void menuUtama()
{
  head();
  // menu
  outMsg("Menu Pilihan Operasi Aritmatika:");
  outMsg("1 = Penjumlahan \0");
  outMsg("2 = Pengurangan \0");
  outMsg("3 = Perkalian   \0");
  outMsg("4 = Pembagian   \0");
  outMsg("5 = Modulus     \0");
  outMsg("0 = Keluar      \0");
  outLine();

  inputThisInt("Masukkan pilihanmu: ", &pilihan);

  switch (pilihan)
  {
  case 1:
    penjumlahan();
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
  case 0:
    printf("TERIMA KASIH SUDAH MENGGUNAKAN PROGRAM INI !\n");
    exit(0);
    break;
  default:
    statusMsg("ERROR: PERINTAH YANG ANDA PILIH TIDAK DITEMUKAN");
    pauseMsg();
    menuUtama();
    break;
  }
}