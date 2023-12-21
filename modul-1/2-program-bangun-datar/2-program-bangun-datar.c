#include "../../validasi/utility/utility.h"

char namaProgram[] = "PROGRAM BANGUN DATAR";
#define _USE_MATH_DEFINES

//  declaration for menu function
int option_screen();
void menu_segitiga();
void menu_belahketupat();
void menu_jajargenjang();
void menu_trapesium();
void menu_lingkaran();

// declaration for calculation function
double keliling_segitiga(double sisi_a, double sisi_b, double sisi_c);
double luas_segitiga(double sisi_a, double sisi_b, double sisi_c);
double keliling_belahketupat(double d1, double d2);
double luas_belahketupat(double d1, double d2);
double keliling_jajargenjang(double alas, double sisi);
double luas_jajargenjang(double alas, double tinggi);
double keliling_trapesium(double sisi_atas, double sisi_bawah, double sisi_kanan, double sisi_kiri);
double luas_trapesium(double sisi_atas, double sisi_bawah, double tinggi);
double keliling_lingkaran(double r);
double luas_lingkaran(double r);

int option_screen()
{
  int opsi_bd;
  char input[10];

  singleLine();
  outMsg("Silahlan untuk memilih opsi perhitungan bangun datar dibawah ini :");
  outMsg("<1> Segitiga Sembarang");
  outMsg("<2> Belah Ketupat     ");
  outMsg("<3> Jajar Genjang     ");
  outMsg("<4> Trapesium         ");
  outMsg("<5> Lingkaran         ");
  singleLine();

  while (1)
  {
    printf(">>>>>>>>>Opsi = ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    if (input_only_option(input))
    {
      opsi_bd = atoi(input);

      if (opsi_bd != 0 && opsi_bd <= 5)
      {
        pauseMsg();
        clear_terminal();
        return opsi_bd;
      }
      else
      {
        outMsg("Masukan input yang valid.");
      }
    }
    else
    {
      outMsg("Input harus berupa angka antara 1 sampai 5.");
    }
  }
}

// menu bangun datar
void menu_segitiga()
{
  double sisi_a, sisi_b, sisi_c;
  double keliling, luas;

  outline();
  outMsg("PROGRAM MENGHITUNG VOLUME DAN LUAS PERMUKAAN BANGUN DATAR");
  singleLine();
  outMsg("BANGUN DATAR SEGITIGA SEMBARANG");
  singleLine();
  outMsg("Masukan panjang dari masing masing sisi");
  printf("Sisi a =");
  sisi_a = input_positive_double();
  printf("Sisi b =");
  sisi_b = input_positive_double();
  printf("Sisi c =");
  sisi_c = input_positive_double();
  pauseMsg();
  clear_terminal();
  singleLine();
  outMsg("Diketahui : ");
  singleLine();
  printf("sisi a = %.5lf\n", sisi_a);
  printf("sisi b = %.5lf\n", sisi_b);
  printf("sisi c = %.5lf\n", sisi_c);
  singleLine();
  outMsg("Hasil Perhitungan :");
  singleLine();
  printf("\nKeliling = %.5lf", keliling_segitiga(sisi_a, sisi_b, sisi_c));
  printf("\nLuas     = %.5lf\n", luas_segitiga(sisi_a, sisi_b, sisi_c));
  pauseMsg();
  clear_terminal();
  endMsg();
}

void menu_belahketupat()
{
  double d1, d2;
  double keliling, luas;

  outline();
  outMsg("PROGRAM MENGHITUNG VOLUME DAN LUAS PERMUKAAN BANGUN DATAR");
  singleLine();
  outMsg("BANGUN DATAR BELAH KETUPAT");
  singleLine();
  outMsg("Masukan panjang dari masing masing diagonal");
  printf("Diagonal 1 =");
  d1 = input_positive_double();
  printf("Diagonal 2 =");
  d2 = input_positive_double();
  pauseMsg();
  clear_terminal();
  singleLine();
  outMsg("Diketahui : ");
  singleLine();
  printf("Diagonal 1 = %.5f\n", d1);
  printf("Diagonal 2 = %.5lf\n", d2);
  singleLine();
  outMsg("Hasil Perhitungan : ");
  singleLine();
  printf("\nKeliling = %.5lf", keliling_belahketupat(d1, d2));
  printf("\nLuas     = %.5lf\n", luas_belahketupat(d1, d2));
  pauseMsg();
  clear_terminal();
  endMsg();
}

void menu_jajargenjang()
{
  double alas, sisi, tinggi;
  double keliling, luas;

  outline();
  outMsg("PROGRAM MENGHITUNG VOLUME DAN LUAS PERMUKAAN BANGUN DATAR");
  singleLine();
  outMsg("BANGUN DATAR JAJAR GENJANG");
  singleLine();
  outMsg("Masukan panjang dari alas, sisi, tinggi");
  printf("Alas   =");
  alas = input_positive_double();
  printf("Sisi   =");
  sisi = input_positive_double();
  printf("Tinggi =");
  tinggi = input_positive_double();
  pauseMsg();
  clear_terminal();
  singleLine();
  outMsg("Diketahui : ");
  singleLine();
  printf("\nAlas   = %.5lf", alas);
  printf("\nSisi   = %.5lf", sisi);
  printf("\nTinggi = %.5lf", tinggi);
  singleLine();
  outMsg("Hasil Perhitungan : ");
  singleLine();
  printf("\nKeliling = %.5lf", keliling_jajargenjang(alas, sisi));
  printf("\nLuas = %.5lf\n", luas_jajargenjang(alas, tinggi));
  pauseMsg();
  clear_terminal();
  endMsg();
}

void menu_trapesium()
{
  double sisi_atas, sisi_bawah, sisi_kanan, sisi_kiri, tinggi;
  double keliling, luas;

  outline();
  outMsg("PROGRAM MENGHITUNG VOLUME DAN LUAS PERMUKAAN BANGUN DATAR");
  singleLine();
  outMsg("BANGUN DATAR TRAPESIUM");
  singleLine();
  outMsg("Masukan panjang dari masing masing sisi");
  printf("Sisi atas =");
  sisi_atas = input_positive_double();
  printf("Sisi bawah =");
  sisi_bawah = input_positive_double();
  printf("Sisi samping kanan =");
  sisi_kanan = input_positive_double();
  printf("Sisi samping kiri =");
  sisi_kiri = input_positive_double();
  printf("Sisi tinggi =");
  tinggi = input_positive_double();
  pauseMsg();
  clear_terminal();
  singleLine();
  outMsg("Diketahui : ");
  singleLine();
  printf("sisi atas = %.5lf\n", sisi_atas);
  printf("sisi bawah = %.5lf\n", sisi_bawah);
  printf("sisi kanan = %.5lf\n", sisi_kanan);
  printf("sisi kiri = %.5lf\n", sisi_kiri);
  printf("sisi tinggi = %.5lf\n", tinggi);
  singleLine();
  outMsg("Hasil Perhitungan :");
  singleLine();
  printf("\nKeliling = %.5lf", keliling_trapesium(sisi_atas, sisi_bawah, sisi_kanan, sisi_kiri));
  printf("\nLuas     = %.5lf\n", luas_trapesium(sisi_atas, sisi_bawah, tinggi));
  pauseMsg();
  clear_terminal();
  endMsg();
}

void menu_lingkaran()
{
  double r;
  double keliling, luas;

  outline();
  outMsg("PROGRAM MENGHITUNG VOLUME DAN LUAS PERMUKAAN BANGUN DATAR");
  singleLine();
  outMsg("BANGUN DATAR LINGKARAN");
  singleLine();
  outMsg("Masukan panjang dari jari-jari lingkaran");
  printf("Jari-jari =");
  r = input_positive_double();
  pauseMsg();
  clear_terminal();
  singleLine();
  outMsg("Diketahui : ");
  singleLine();
  printf("Jari-jari = %.5lf\n", r);
  singleLine();
  outMsg("Hasil Perhitungan :");
  singleLine();
  printf("\nKeliling = %.5lf", keliling_lingkaran(r));
  printf("\nLuas     = %.5lf\n", luas_lingkaran(r));
  pauseMsg();
  clear_terminal();
  endMsg();
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
  case 4:
    menu_trapesium();
    break;
  case 5:
    menu_lingkaran();
    break;
  }
}

// fungsi rumus kalkulasi keliling dan luas bangun datar
double keliling_segitiga(double sisi_a, double sisi_b, double sisi_c)
{
  double keliling = sisi_a + sisi_b + sisi_c;
  return keliling;
}

double luas_segitiga(double sisi_a, double sisi_b, double sisi_c)
{
  double s;
  double luas;

  s = (sisi_a + sisi_b + sisi_c) / 2;
  luas = sqrt(s * (s - sisi_a) * (s - sisi_b) * (s - sisi_c));
  return luas;
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

double keliling_trapesium(double sisi_atas, double sisi_bawah, double sisi_kanan, double sisi_kiri)
{
  double keliling = sisi_atas + sisi_bawah + sisi_kanan + sisi_kiri;
  return keliling;
}

double luas_trapesium(double sisi_atas, double sisi_bawah, double tinggi)
{
  double luas = (sisi_atas + sisi_bawah) * tinggi * 0.5;
  return luas;
}

double keliling_lingkaran(double r)
{
  double keliling = 2 * M_PI * r;
  return keliling;
}

double luas_lingkaran(double r)
{
  double luas = M_PI * pow(r, 2);
  return luas;
}

int main()
{
  double sisi_a,
      sisi_b, sisi_c, d1, d2, alas, sisi, tinggi, sisi_atas, sisi_bawah, sisi_samping_kanan, sisi_samping_kiri, r;
  int opsi_bd;
  int repeat_program = 1;

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