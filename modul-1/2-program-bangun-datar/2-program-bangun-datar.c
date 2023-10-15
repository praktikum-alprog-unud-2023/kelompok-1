#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// declaration menu function
void outline();
void starting_screen();
int ending_screen();
int option_screen();
void clear_terminal();
void menu_segitiga();
void menu_belahketupat();
void menu_jajargenjang();

// declaration calculation function
double keliling_segitiga(double sisi_a, double sisi_b, double sisi_c);
double luas_segitiga(double sisi_a, double sisi_b, double sisi_c);
double keliling_belahketupat(double d1, double d2);
double luas_belahketupat(double d1, double d2);
double keliling_jajargenjang(double alas, double sisi);
double luas_jajargenjang(double alas, double tinggi);

// grafik
void outline()
{
  printf("\n--------------------------------------------------------------------\n");
}
// screen in terminal
void starting_screen()
{
  outline();
  printf("\n*    PROGRAM MENGHITUNG VOLUME DAN LUAS PERMUKAAN BANGUN RUANG     *\n");
  printf("\n                            *Kelompok 1*                            \n");
  printf("\n          NI NENGAH SENJA SRI PRATIWI             2305551014        \n");
  printf("\n          NI GUSTI AYU MARTINI                    2305551020        \n");
  printf("\n          PUTU EKA DODY ARSANA PUTRA              2305551075        \n");
  printf("\n          KALVIN ANGELITO ANG                     2305551115        \n");
  printf("\n          MUHAMMAD DZIKRI DHANIAWAN               2305551146        \n");
  printf("\n          VINCENTIUS BONAVERREL DOMINICO          2305554176        \n");
  outline();
  printf("\n       *Silahkan tekan enter untuk melanjutkan ke menu utama*       \n");
  outline();

  getchar();
  system("cls");
}
int ending_screen()
{
  int opsi_end;

  outline();
  printf("\n                        PROGRAM SUDAH SELESAI                       \n");
  outline();
  printf("\n             <1> Ulangi Program <2> Keluar dari Program             \n");
  outline();

  printf("Opsi = ");
  scanf("%d", &opsi_end);

  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;

  if (opsi_end == 2)
  {
    printf("ANDA SUDAH KELUAR DARI PROGRAM!\n");
    exit(0);
  }
  return opsi_end;
}
int option_screen()
{
  int opsi_bd;

  outline();
  printf("\n-Silahlan untuk memilih opsi perhitungan bangun datar dibawah ini :  -\n");
  printf("\n-                        <1> Segitiga Sembarang                      -\n");
  printf("\n-                        <2> Belah Ketupat                           -\n");
  printf("\n-                        <3> Jajar Genjang                           -\n");
  printf("\n-                        <4> Trapesium                               -\n");
  printf("\n-                        <5> Lingkaran                               -\n");
  outline();

  while (1)
  {
    printf("Opsi = ");
    scanf("%d", &opsi_bd);
    if (opsi_bd >= 1 && opsi_bd <= 5)
    {
      break;
    }
    else
    {
      printf("\n%d tidak ada di opsi, coba pilih kembali.\n", opsi_bd);
    }
  }

  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;

  outline();
  printf("\n              *Silahkan tekan enter untuk melanjutkan*              \n");
  outline();

  getchar();
  system("cls");
  return opsi_bd;
}
void clear_terminal()
{
  getchar();
  system("cls");
}

// menu bangun datar
void menu_segitiga()
{
  double sisi_a, sisi_b, sisi_c;
  double keliling, luas;

  outline();
  printf("\nBANGUN DATAR SEGITIGA SEMBARANG\n");
  outline();
  printf("\nMasukan panjang dari masing masing sisi\n");
  printf("Sisi a =");
  scanf("%lf", &sisi_a);
  printf("Sisi b =");
  scanf("%lf", &sisi_b);
  printf("Sisi c =");
  scanf("%lf", &sisi_c);
  outline();
  printf("\n              *Silahkan tekan enter untuk melanjutkan*              \n");
  outline();
  clear_terminal();
  outline();
  printf("sisi a = %.5lf\n", sisi_a);
  printf("sisi a = %.5lf\n", sisi_b);
  printf("sisi a = %.5lf\n", sisi_c);
  outline();
  printf("Hasil Perhitungan : ");
  printf("\nKeliling = %.5lf", keliling_segitiga(sisi_a, sisi_b, sisi_c));
  printf("\nLuas = %.5lf\n", luas_segitiga(sisi_a, sisi_b, sisi_c));
  outline();
  printf("\n              *    Silahkan tekan enter...    *           \n");
  outline();
  clear_terminal();
  ending_screen();
}
void menu_belahketupat()
{
  double d1, d2;
  double keliling, luas;

  outline();
  printf("\nBANGUN DATAR BELAH KETUPAT\n");
  outline();
  printf("\nMasukan panjang dari masing masing diagonal\n");
  printf("Diagonal 1 =");
  scanf("%lf", &d1);
  printf("Diagonal 2 =");
  scanf("%lf", &d2);
  outline();
  printf("\n              *Silahkan tekan enter untuk melanjutkan*              \n");
  outline();
  clear_terminal();
  outline();
  printf("\nDiagonal 1 = %.5f\n", d1);
  printf("\nDiagonal 2 = %.5lf\n", d2);
  outline();
  printf("\nHasil Perhitungan : \n");
  printf("\nKeliling = %.5lf", keliling_belahketupat(d1, d2));
  printf("\nLuas = %.5lf\n", luas_belahketupat(d1, d2));
  outline();
  printf("\n              *    Silahkan tekan enter...    *           \n");
  outline();
  clear_terminal();
  ending_screen();
}
void menu_jajargenjang()
{
  double alas, sisi, tinggi;
  double keliling, luas;

  outline();
  printf("\nBANGUN DATAR JAJAR GENJANG\n");
  outline();
  printf("\nMasukan panjang dari alas, sisi, tinggi\n");
  printf("Alas =");
  scanf("%lf", &alas);
  printf("Sisi =");
  scanf("%lf", &sisi);
  printf("Tinggi =");
  scanf("%lf", &tinggi);
  outline();
  printf("\n              *    Silahkan tekan enter...    *           \n");
  outline();
  clear_terminal();
  outline();
  printf("\nAlas = %.5lf", alas);
  printf("\nSisi = %.5lf", sisi);
  printf("\nTinggi = %.5lf", tinggi);
  outline();
  printf("\nHasil Perhitungan : ");
  printf("\nKeliling = %.5lf", keliling_jajargenjang(alas, sisi));
  printf("\nLuas = %.5lf\n", luas_jajargenjang(alas, tinggi));
  outline();
  printf("\n              *    Silahkan tekan enter...    *           \n");
  outline();
  clear_terminal();
  ending_screen();
}

// pemilihan menu
void option(int opsi_bd)
{
  switch (opsi_bd)
  {
  case 1:
    menu_segitiga();
    break;
  case 2:
    menu_belahketupat();
    break;
  case 3:
    menu_jajargenjang();
    break;
  }
  /*case 4:
menu_trapesium();
break;
case 5:
menu_lingkaran();
break;*/
}

// fungsi rumus kalkulasi keliling dan luas bangun datar
double keliling_segitiga(double sisi_a, double sisi_b, double sisi_c)
{
  double keliling = sisi_a + sisi_b + sisi_c;
  return keliling;
}
double luas_segitiga(double sisi_a, double sisi_b, double sisi_c)
{
  double s = keliling_segitiga(sisi_a, sisi_b, sisi_c) / 2;
  return sqrt(s * (s - sisi_a) * (s - sisi_b) * (s - sisi_c));
}
double keliling_belahketupat(double d1, double d2)
{
  double keliling;
  if (d1 == d2)
  {
    keliling = 4 * d1;
  }
  else
  {
    keliling = 2 * (d1 + d2);
  }
  return keliling;
}
double luas_belahketupat(double d1, double d2)
{
  double luas = (d1 * d2) / 2;
  return luas;
}
double keliling_jajargenjang(double alas, double sisi)
{
  double keliling = 2 * (alas + sisi);
  return keliling;
}
double luas_jajargenjang(double alas, double tinggi)
{
  double luas = alas * tinggi;
  return luas;
}

int main()
{
  double sisi_a, sisi_b, sisi_c, d1, d2, alas, sisi, tinggi;
  int opsi_bd;
  int repeat_program = 1; // Add a flag to control program repetition

  while (repeat_program == 1)
  {
    starting_screen();
    opsi_bd = option_screen();
    option(opsi_bd);

    if (repeat_program == 1)
    {
      system("cls");
      continue;
    }
  }
  return 0;
}
