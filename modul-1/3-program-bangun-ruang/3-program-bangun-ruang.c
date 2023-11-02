//***************************************************//
/* Menghitung Volume dan Luas Permukaan Bangun Ruang */
//***************************************************//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include <math.h>
// Konstanta untuk ukuran buffer
#define BUFFER_SIZE 4096

// Deklarasi variabel global
int pilihan;

// Deklarasi daftar bentuk bangun ruang
char daftarBangunRuang[5][50] = {
    "Tabung                    \0",
    "Bola                      \0",
    "Limas Segiempat           \0",
    "Prisma Segitiga           \0",
    "Kerucut                   \0"};

// Prosedur utilitas
void endMsg();
void inputThisInt(char *inputText, int *inputVariable);
void inputThisDouble(char *inputText, double *inputVariable);
void startingScreen();
void head();
void outLine();
void outMsg(const char *format, ...);
void statusMsg(char *);
void pauseMsg();

// Validasi input
int validateInputInteger(char *string, int *integer);
int validateInputDouble(char *string, double *floating_point);

// Deklarasi menu
void menuUtama();
void menuTabung();
void menuBola();
void menuLimasSegiempat();
void menuPrismaSegitiga();
void menuKerucut();

// Fungsi rumus untuk perhitungan
double tabungVolume(double, double);
double tabungLuasPermukaan(double, double);
double bolaVolume(double);
double bolaLuasPermukaan(double);
double limasSegiempatVolume();
double limasSegiempatLuasPermukaan();
double prismaSegitigaVolume();
double prismaSegitigaLuasPermukaan();
double kerucutVolume();
double kerucutLuasPermukaan();

int main()
{
  startingScreen();
  menuUtama();
  return 0;
}

// validator
int validateInputInteger(char *string, int *integer)
{
  int i = 0;

  while (isspace(string[i]))
    i++;

  int length = strlen(string);

  if (length == i)
    return 0;

  char integer_buffer[BUFFER_SIZE];
  int integer_chars = 0;

  // in the case of a negative integer, the first char may be - symbol
  if (string[i] == '-')
  {

    integer_buffer[integer_chars] = '-';
    integer_chars++;
    i++;

    if (!isdigit(string[i]))
      return 0;
  }

  while (i < length && !isspace(string[i]))
  {
    if (!isdigit(string[i]))
      return 0;

    integer_buffer[integer_chars] = string[i];
    integer_chars++;
    i++;
  }

  // put a null terminator onto the end of the buffer to make it a proper string
  integer_buffer[integer_chars] = '\0';

  // loop through any trailing whitespace characters
  while (isspace(string[i]))
    i++;

  if (string[i] != '\0')
    return 0;

  *integer = atoi(integer_buffer);

  return 1;
}

int validateInputDouble(char *string, double *floating_point)
{
  int i = 0;

  while (isspace(string[i]))
    i++;

  int length = strlen(string);

  if (length == i)
    return 0;

  char double_buffer[BUFFER_SIZE];
  int double_chars = 0;
  int hasDecimal = 0; // To keep track of whether a decimal point has been encountered.

  // In the case of a negative double, the first character may be a '-' symbol
  if (string[i] == '-')
  {
    double_buffer[double_chars] = '-';
    double_chars++;
    i++;
  }

  while (i < length && !isspace(string[i]))
  {
    if (isdigit(string[i]))
    {
      double_buffer[double_chars] = string[i];
      double_chars++;
      i++;
    }
    else if (string[i] == '.' && !hasDecimal)
    {
      double_buffer[double_chars] = string[i];
      double_chars++;
      hasDecimal = 1; // Set the flag to indicate a decimal point has been encountered.
      i++;
    }
    else
    {
      return 0; // Invalid character for a double
    }
  }

  // Put a null terminator at the end of the buffer to make it a proper string
  double_buffer[double_chars] = '\0';

  // Loop through any trailing whitespace characters
  while (isspace(string[i]))
    i++;

  if (string[i] != '\0')
    return 0;

  // Use atof to convert the double_buffer string to a double
  *floating_point = atof(double_buffer);

  return 1;
}

void inputThisInt(char *inputText, int *inputVariable)
{
  int parsed_correct = 1;
  char buffer[BUFFER_SIZE];
  do
  {
    // input
    if (inputText != NULL)
    {
      printf(">>>>>>>>>>>>>>>>>>>>>>>    %s", inputText);
    }

    // accept a line of string input from the user, store it into buffer

    fgets(buffer, BUFFER_SIZE, stdin);

    if (validateInputInteger(buffer, inputVariable) == 0)
    {
      statusMsg("ERROR: ANDA TIDAK MEMASUKKAN NOMOR PERINTAH");
    }

    if (*inputVariable <= 0)
    {
      statusMsg("ERROR: BILANGAN YANG DIMASUKKAN BUKAN BILANGAN POSITIF");
    }
  } while (validateInputInteger(buffer, inputVariable) == 0 || *inputVariable < 0);
}

void inputThisDouble(char *inputText, double *inputVariable)
{
  int parsed_correct = 1;
  char buffer[BUFFER_SIZE];
  do
  {
    // input
    if (inputText != NULL)
    {
      printf(">>>>>>>>>>>>>>>>>>>>>>>    %s", inputText);
    }

    // accept a line of string input from the user, store it into buffer

    fgets(buffer, BUFFER_SIZE, stdin);

    if (validateInputDouble(buffer, inputVariable) == 0)
    {
      statusMsg("ERROR: ANDA TIDAK MEMASUKKAN ANGKA");
      pauseMsg();
    }
    if (*inputVariable <= 0)
    {
      statusMsg("ERROR: BILANGAN YANG DIMASUKKAN BUKAN BILANGAN POSITIF");
      pauseMsg();
    }
  } while (validateInputDouble(buffer, inputVariable) == 0 || *inputVariable < 0);
}

// utilitas
void startingScreen() // tampilan head pada program
{
  system("cls");
  outLine();
  outLine();
  outMsg("");
  outMsg("%s", namaProgram);
  outMsg("");
  outLine();
  outLine();
  outMsg("KELOMPOK 1");
  outLine();
  outMsg("ANGGOTA:");
  outMsg("AGUS ARYA WIRAGUNA                      2305551013");
  outMsg("NI NENGAH SENJA SRI PRATIWI             2305551014");
  outMsg("I GUSTI AYU MARTINI                     2305551020");
  outMsg("PUTU EKA DODY ARSANA PUTRA              2305551075");
  outMsg("KALVIN ANGELITO ANG                     2305551115");
  outMsg("MUHAMMAD DZIKRI DHANIAWAN               2305551146");
  outMsg("VINCENTIUS BONAVERREL DOMINICO          2305554176");
  outLine();
  outLine();
  outMsg("PROGAM STUDI TEKNOLOGI INFORMASI");
  outMsg("FAKULTAS TEKNIK");
  outMsg("UNIVERSITAS UDAYANA");
  outMsg("2023");
  outLine();
  outLine();
  outMsg("");
  outMsg("");
  outMsg("");
  pauseMsg();
}

void head() // tampilan head pada program
{
  system("cls");
  outLine();
  outMsg("%s", namaProgram);
  outLine();
}

void outLine() // prosedur menampilkan garis
{
  printf("|=================================================================================|\n");
}

void outMsg(const char *format, ...) // prosedur menampilkan pesan
{
  va_list args;
  va_start(args, format);

  char outputMessage[82];
  int outputLength = 82;

  vsnprintf(outputMessage, outputLength, format, args);

  va_end(args);

  int inputLength = strlen(outputMessage);
  int numSpaces = (outputLength - inputLength) / 2;

  if (numSpaces < 0)
  {
    numSpaces = 0; // Avoid negative padding
  }

  char tempMessage[82]; // Buat variabel sementara
  memset(tempMessage, ' ', numSpaces);
  strcpy(tempMessage + numSpaces, outputMessage);
  memset(tempMessage + numSpaces + inputLength, ' ', numSpaces);

  tempMessage[outputLength - 1] = '\0'; // Pastikan null-terminated string
  printf("|%s|\n", tempMessage);
}

void statusMsg(char *inputText) // prosedur menampilkan status
{
  outLine();
  outMsg(inputText);
  outLine();
}

void endMsg() // prosedur menampilkan status
{
  outLine();
  outMsg("PROGRAM SELESAI");
  outMsg("< 1 > Ulangi            < 2 > Keluar");
  inputThisInt("Masukkan perintah : ", &pilihan);
  do
  {
    if (pilihan == 1)
    {
      menuUtama();
    }
    else if (pilihan == 2)
    {
      exit(0);
      break;
    }

    statusMsg("ERROR: PERINTAH YANG ANDA PILIH TIDAK DITEMUKAN");
    endMsg();
  } while (pilihan != 1 || pilihan != 2);
}

void pauseMsg()
{
  outMsg("Press enter to continue . . .");
  getchar();
  printf("\n");
}

// menu
void menuUtama()
{
  head();

  // menu
  outMsg("Menu Pilihan Bentuk Bangun Ruang:");
  for (int i = 0; i < 5; i++)
  {
    outMsg("< %d >  %s", i + 1, daftarBangunRuang[i]);
  }
  outMsg("< 0 >  keluar                    \0");
  outLine();

  inputThisInt("masukkan pilihanmu: ", &pilihan);

  switch (pilihan)
  {
  case 1:
    menuTabung();
    break;
  case 2:
    menuBola();
    break;
  case 3:
    menuLimasSegiempat();
    break;
  case 4:
    menuPrismaSegitiga();
    break;
  case 5:
    menuKerucut();
    break;

  case 0:
    break;

  default:
    statusMsg("ERROR: PERINTAH YANG ANDA PILIH TIDAK DITEMUKAN");
    pilihan = 0;
    pauseMsg();
    menuUtama();
    break;
  }
}

// prosedur perhitungan
void menuTabung()
{
  double diameter, tinggi;
  head();
  outLine();
  outMsg("Bangun Ruang Tabung");
  outLine();
  outMsg("Masukkan diameter alas");
  outLine();
  inputThisDouble("diameter = ", &diameter);
  head();
  outMsg("diameter alas = %lf", diameter);
  outLine();
  outMsg("Masukkan tinggi tabung");
  outLine();
  inputThisDouble("tinggi = ", &tinggi);
  head();
  outMsg("diameter alas = %lf", diameter);
  outMsg("tinggi tabung = %lf", tinggi);
  outLine();
  outMsg("hasil perhitungan");
  outMsg("volume = %lf", tabungVolume(diameter / 2, tinggi));
  outMsg("luas permukaan = %lf", tabungLuasPermukaan(diameter / 2, tinggi));
  outLine();
  endMsg();
}

void menuBola()
{
  double diameter, tinggi;
  head();
  outLine();
  outMsg("Bangun Ruang Bola");
  outLine();
  outMsg("Masukkan diameter bola");
  outLine();
  inputThisDouble("diameter = ", &diameter);
  head();
  outMsg("diameter bola = %lf", diameter);
  outLine();
  outMsg("hasil perhitungan");
  outMsg("volume = %lf", bolaVolume(diameter / 2));
  outMsg("luas permukaan = %lf", bolaLuasPermukaan(diameter / 2));
  outLine();
  endMsg();
}

void menuLimasSegiempat()
{
  double diameter, tinggi;
  head();
  outLine();
  outMsg("Bangun Ruang Limas Segiempat");
  outLine();
  outMsg("Masukkan diameter alas");
  outLine();
  inputThisDouble("diameter = ", &diameter);
  head();
  outMsg("diameter alas = %lf", diameter);
  outLine();
  outMsg("Masukkan tinggi tabung");
  outLine();
  inputThisDouble("tinggi = ", &tinggi);
  head();
  outMsg("diameter alas = %lf", diameter);
  outMsg("tinggi tabung = %lf", tinggi);
  outLine();
  outMsg("hasil perhitungan");
  outMsg("volume = %lf", tabungVolume(diameter / 2, tinggi));
  outMsg("luas permukaan = %lf", tabungLuasPermukaan(diameter / 2, tinggi));
  outLine();
  endMsg();
}

void menuPrismaSegitiga()
{
  double diameter, tinggi;
  head();
  outLine();
  outMsg("Bangun Ruang Prisma Segitiga");
  outLine();
  outMsg("Masukkan diameter alas");
  outLine();
  inputThisDouble("diameter = ", &diameter);
  head();
  outMsg("diameter alas = %lf", diameter);
  outLine();
  outMsg("Masukkan tinggi tabung");
  outLine();
  inputThisDouble("tinggi = ", &tinggi);
  head();
  outMsg("diameter alas = %lf", diameter);
  outMsg("tinggi tabung = %lf", tinggi);
  outLine();
  outMsg("hasil perhitungan");
  outMsg("volume = %lf", tabungVolume(diameter / 2, tinggi));
  outMsg("luas permukaan = %lf", tabungLuasPermukaan(diameter / 2, tinggi));
  outLine();
  endMsg();
}

void menuKerucut()
{
  double diameter, tinggi;
  head();
  outLine();
  outMsg("Bangun Ruang Kerucut");
  outLine();
  outMsg("Masukkan diameter alas");
  outLine();
  inputThisDouble("diameter = ", &diameter);
  head();
  outMsg("diameter alas = %lf", diameter);
  outLine();
  outMsg("Masukkan tinggi tabung");
  outLine();
  inputThisDouble("tinggi = ", &tinggi);
  head();
  outMsg("diameter alas = %lf", diameter);
  outMsg("tinggi tabung = %lf", tinggi);
  outLine();
  outMsg("hasil perhitungan");
  outMsg("volume = %lf", tabungVolume(diameter / 2, tinggi));
  outMsg("luas permukaan = %lf", tabungLuasPermukaan(diameter / 2, tinggi));
  outLine();
  endMsg();
}

// fungsi rumus

double tabungVolume(double radius, double tinggi)
{
  return 22 / 7 * pow(radius, 2) * tinggi;
}

double tabungLuasPermukaan(double radius, double tinggi)
{
  return 2 * 22 / 7 * radius * tinggi + 2 * 22 / 7 * pow(radius, 3);
}

double bolaVolume(double radius)
{
  return 4 / 3 * 22 / 7 * pow(radius, 3);
}

double bolaLuasPermukaan(double radius)
{
  return 4 * 22 / 7 * pow(radius, 2);
}

double limasSegiempatVolume(double luasAlas, double tinggi)
{
  return 1 / 2 * luasAlas * tinggi;
}

double limasSegiempatLuasPermukaan(double luasAlas, double luasSegitiga1, double luasSegitiga2, double luasSegitiga3, double luasSegitiga4)
{
  return luasAlas + luasSegitiga1 + luasSegitiga2 + luasSegitiga3 + luasSegitiga4;
}

double prismaSegitigaVolume(double luasAlas, double tinggi)
{
  return 1 / 2 * luasAlas * tinggi;
}

double prismaSegitigaLuasPermukaan(double luasAlas, double luasSegitiga1, double luasSegitiga2, double luasSegitiga3, double luasSegitiga4)
{
  return luasAlas + luasSegitiga1 + luasSegitiga2 + luasSegitiga3 + luasSegitiga4;
}

double kerucutVolume(double luasAlas, double tinggi)
{
  return 1 / 2 * luasAlas * tinggi;
}

double kerucutLuasPermukaan(double luasAlas, double luasSegitiga1, double luasSegitiga2, double luasSegitiga3, double luasSegitiga4)
{
  return luasAlas + luasSegitiga1 + luasSegitiga2 + luasSegitiga3 + luasSegitiga4;
}