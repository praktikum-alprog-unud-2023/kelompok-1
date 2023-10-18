#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdarg.h>

//  declaration for menu function
void outline();
void starting_screen();
int endMsg();
int option_screen();
void clear_terminal();
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

// utilitas
void outline()
{
  printf("\n--------------------------------------------------------------------\n");
}
void doubleline()
{
  printf("\n====================================================================\n");
}
void outMsg(const char *format, ...)
{
  int totalWidth = 68;
  char buffer[100];
  va_list args;

  va_start(args, format);
  vsnprintf(buffer, sizeof(buffer), format, args);
  va_end(args);

  int textLength = strlen(buffer);
  int padding = (totalWidth - textLength) / 2;

  printf("\n");

  for (int i = 0; i < padding; i++)
  {
    putchar(' ');
  }

  printf("%s", buffer);

  for (int i = 0; i < padding; i++)
  {
    putchar(' ');
  }

  if (totalWidth % 2 != 0)
  {
    putchar(' ');
  }

  printf("\n");
}
void pauseMsg()
{
  outline();
  outMsg("*Silahkan tekan enter untuk melanjutkan...*");
  outline();
}
void clear_terminal()
{
  getchar();
  system("cls");
}

// validasi
int input_positive_int()
{
  char input[10];
  int i = 0, output, error = 0;

  fflush(stdin);
  fgets(input, sizeof(input), stdin);

  if (input[0] == '\0')
    error = 1;

  while (input[i] != '\0' && input[i] != '\n')
  {
    if (isdigit(input[i]))
      i++;
    else
    {
      error = 1;
      break;
    }
  }

  output = atoi(input);

  if (error == 1)
  {
    printf("\nInput Tidak Sesuai!");
    printf("\nMasukan Angka Kembali : ");
    return input_positive_int();
  }
  else
    return output;
}
int input_valid_option()
{
  char input[10];
  int i = 0, error = 0;
  int output;

  fflush(stdin);
  fgets(input, sizeof(input), stdin);

  if (input[0] == '\0')
    error = 1;

  while (input[i] != '\0' && input[i] != '\n')
  {
    if (isdigit(input[i]) && (input[i] == '1' || input[i] == '2'))
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
    printf("\nInput Tidak Sesuai! Harap masukkan angka 1 atau 2.");
    printf("\nMasukkan Angka Kembali : ");
    return input_valid_option();
  }
  else
  {
    output = atoi(input);
    return output;
  }
}
int input_only_option(const char *str)
{
  for (int i = 0; str[i] != '\0'; i++)
  {
    if (!isdigit(str[i]))
    {
      return 0;
    }
  }
  return 1;
}
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

// screen in terminal
void starting_screen()
{
  doubleline();
  outMsg("PROGRAM MENGHITUNG VOLUME DAN LUAS PERMUKAAN BANGUN DATAR");
  outMsg("*KELOMPOK 1*");
  doubleline();
  outMsg("NI NENGAH SENJA SRI PRATIWI             2305551014");
  outMsg("NI GUSTI AYU MARTINI                    2305551020");
  outMsg("PUTU EKA DODY ARSANA PUTRA              2305551075");
  outMsg("KALVIN ANGELITO ANG                     2305551115");
  outMsg("MUHAMMAD DZIKRI DHANIAWAN               2305551146");
  outMsg("VINCENTIUS BONAVERREL DOMINICO          2305554176");
  doubleline();
  outMsg("*Silahkan tekan enter untuk melanjutkan ke menu utama*");
  doubleline();

  clear_terminal();
}
int endMsg()
{
  int opsi_end;

  outline();
  outMsg("PROGRAM SUDAH SELESAI");
  outline();
  outMsg("<1> Ulangi Program <2> Keluar dari Program");
  outline();

  while (1)
  {
    printf(">>>>>>>>> Opsi = ");
    scanf("%d", &opsi_end);

    int c;
    while ((c = getchar()) != '\n' && c != EOF)
      ;

    if (opsi_end == 1 || opsi_end == 2)
    {
      break;
    }
    else
    {
      outMsg("Masukan input yang valid.");
      printf("\n");
    }
  }

  if (opsi_end == 2)
  {
    doubleline();
    outMsg(">>>ANDA SUDAH KELUAR DARI PROGRAM<<<");
    doubleline();

    exit(0);
  }

  return opsi_end;
}
int option_screen()
{
  int opsi_bd;
  char input[10];

  outline();
  outMsg("Silahlan untuk memilih opsi perhitungan bangun datar dibawah ini :");
  outMsg("<1> Segitiga Sembarang");
  outMsg("<2> Belah Ketupat     ");
  outMsg("<3> Jajar Genjang     ");
  outMsg("<4> Trapesium         ");
  outMsg("<5> Lingkaran         ");
  outline();

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

  doubleline();
  outMsg("PROGRAM MENGHITUNG VOLUME DAN LUAS PERMUKAAN BANGUN DATAR");
  outline();
  outMsg("BANGUN DATAR SEGITIGA SEMBARANG");
  outline();
  outMsg("Masukan panjang dari masing masing sisi");
  printf("Sisi a =");
  sisi_a = input_positive_double();
  printf("Sisi b =");
  sisi_b = input_positive_double();
  printf("Sisi c =");
  sisi_c = input_positive_double();
  pauseMsg();
  clear_terminal();
  outline();
  outMsg("Diketahui : ");
  outline();
  printf("sisi a = %.5lf\n", sisi_a);
  printf("sisi b = %.5lf\n", sisi_b);
  printf("sisi c = %.5lf\n", sisi_c);
  outline();
  outMsg("Hasil Perhitungan :");
  outline();
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

  doubleline();
  outMsg("PROGRAM MENGHITUNG VOLUME DAN LUAS PERMUKAAN BANGUN DATAR");
  outline();
  outMsg("BANGUN DATAR BELAH KETUPAT");
  outline();
  outMsg("Masukan panjang dari masing masing diagonal");
  printf("Diagonal 1 =");
  d1 = input_positive_double();
  printf("Diagonal 2 =");
  d2 = input_positive_double();
  pauseMsg();
  clear_terminal();
  outline();
  outMsg("Diketahui : ");
  outline();
  printf("Diagonal 1 = %.5f\n", d1);
  printf("Diagonal 2 = %.5lf\n", d2);
  outline();
  outMsg("Hasil Perhitungan : ");
  outline();
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

  doubleline();
  outMsg("PROGRAM MENGHITUNG VOLUME DAN LUAS PERMUKAAN BANGUN DATAR");
  outline();
  outMsg("BANGUN DATAR JAJAR GENJANG");
  outline();
  outMsg("Masukan panjang dari alas, sisi, tinggi");
  printf("Alas   =");
  alas = input_positive_double();
  printf("Sisi   =");
  sisi = input_positive_double();
  printf("Tinggi =");
  tinggi = input_positive_double();
  pauseMsg();
  clear_terminal();
  outline();
  outMsg("Diketahui : ");
  outline();
  printf("\nAlas   = %.5lf", alas);
  printf("\nSisi   = %.5lf", sisi);
  printf("\nTinggi = %.5lf", tinggi);
  outline();
  outMsg("Hasil Perhitungan : ");
  outline();
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

  doubleline();
  outMsg("PROGRAM MENGHITUNG VOLUME DAN LUAS PERMUKAAN BANGUN DATAR");
  outline();
  outMsg("BANGUN DATAR TRAPESIUM");
  outline();
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
  outline();
  outMsg("Diketahui : ");
  outline();
  printf("sisi atas = %.5lf\n", sisi_atas);
  printf("sisi bawah = %.5lf\n", sisi_bawah);
  printf("sisi kanan = %.5lf\n", sisi_kanan);
  printf("sisi kiri = %.5lf\n", sisi_kiri);
  printf("sisi tinggi = %.5lf\n", tinggi);
  outline();
  outMsg("Hasil Perhitungan :");
  outline();
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

  doubleline();
  outMsg("PROGRAM MENGHITUNG VOLUME DAN LUAS PERMUKAAN BANGUN DATAR");
  outline();
  outMsg("BANGUN DATAR LINGKARAN");
  outline();
  outMsg("Masukan panjang dari jari-jari lingkaran");
  printf("Jari-jari =");
  r = input_positive_double();
  pauseMsg();
  clear_terminal();
  outline();
  outMsg("Diketahui : ");
  outline();
  printf("Jari-jari = %.5lf\n", r);
  outline();
  outMsg("Hasil Perhitungan :");
  outline();
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
  double sisi_a, sisi_b, sisi_c, d1, d2, alas, sisi, tinggi, sisi_atas, sisi_bawah, sisi_samping_kanan, sisi_samping_kiri, r;
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
