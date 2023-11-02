#include "../../validasi/utility/utility.h"
char namaProgram[] = "PROGRAM MENGHITUNG ANGSURAN";

int main()
{
  startingScreen();
  menuUtama();
  return 0;
}

void menuUtama()
{
  head();

  double pokokPinjaman, bunga;
  int bulan;

  inputThisDouble("Pokok Pinjaman                 = ", &pokokPinjaman);
  inputThisDouble("Besar Bunga dalam setahun (%)  = ", &bunga);
  inputThisInt("Lama Pinjaman dalam Bulan      = ", &bulan);

  // Validasi Bilangan Negatif :3
  if (pokokPinjaman < 0 || bunga < 0 || bulan < 0)
  {
    printf("Tolong masukkan bilangan non-negatif.\n");
    return;
  }

  double angsuranPokok = pokokPinjaman / bulan;
  double bungaBulanY, totalBunga, totalAngsuran = 0;

  // header tabel
  head();
  printf("\n\n");
  outLine();
  outMsg("PROYEKSI ANGSURAN");
  outLine();
  printf("|");
  txtBox("Bulan", 12, 'C');
  printf("|");
  txtBox("Bunga", 22, 'C');
  printf("|");
  txtBox("Angsuran Pokok", 22, 'C');
  printf("|");
  txtBox("Angsuran Perbulan", 22, 'C');
  printf("|");
  printf("\n");
  outLine();

  // efisiensi
  /*
  (pokokPinjaman - ((bulanY - 1) * angsuranPokok)) * (bunga / 100) / 12
  (bunga / 100) / 12 ==> sukuBunga
  */

  double sukuBunga = (bunga / 100) / 12;

  for (int bulanY = 1; bulanY <= bulan; bulanY++)
  {
    printf("|  ");
    txtBox("%d", 9, 'C', bulanY);
    printf(" |  ");
    bungaBulanY = (pokokPinjaman - ((bulanY - 1) * angsuranPokok)) * sukuBunga;
    txtBox("Rp%.2lf", 18, 'R', bungaBulanY);
    printf("  |  ");
    totalBunga += bungaBulanY;
    txtBox("Rp%.2lf", 18, 'R', angsuranPokok);
    printf("  |  ");
    txtBox("Rp%.2lf", 18, 'R', (angsuranPokok + bungaBulanY));
    totalAngsuran += (angsuranPokok + bungaBulanY);
    printf("  |");
    printf("\n");
  }

  outLine();
  printf("|   ");
  txtBox("Total Bunga = ", 20, 'L');
  txtBox("Rp%.2lf", 56, 'R', totalBunga);
  printf("  |");
  printf("\n");
  printf("|   ");
  txtBox("Total Angsuran = ", 20, 'L');
  txtBox("Rp%.2lf", 56, 'R', totalAngsuran);
  printf("  |");
  printf("\n");
  outLine();
  printf("\n\n\n");
  endMsg();
}