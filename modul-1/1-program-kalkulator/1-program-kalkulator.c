#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include <math.h>
#define BUFFER_SIZE 4096

int pilihan;
int validasiInputInteger(char *string, int *integer);
void ulangprogram();
void startingScreen();
void head();
void outLine();
void outMsg(const char *format, ...);
void statusMsg(char *);
void pauseMsg();
void inputInt(char *inputText, int *inputVariable);
void inputPilihan(char *inputText, int *inputVariable);
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
  ulangprogram();
}

void penjumlahan()
{
  double angka1, angka2, hasil;
  head();
  outLine();
  outMsg("OPRASI PENJUMLAHAN");
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
  outMsg("OPRASI PENGURANGAN");
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
  outMsg("OPRASI PERKALIAN");
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
  outMsg("OPRASI PEMBAGIAN");
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
  inputInt("Angka Pertama  :", &angka1);
  inputInt("Angka Kedua    :", &angka2);
  hasil = (int)angka1 % (int)angka2;
  outLine();
  outMsg("Hasilnya adalah %i", hasil);
  outLine();
}

int validasiBil(double *bil)
{
  char strBil[100];
  while (1)
  {
    if (scanf("%[^\n]", strBil) != 1)
    {
      printf("Input harus berupa bilangan, silahkan ulangi kembali: ");
      getchar() != '\n';
    }
    else
    {
      char *endptr;
      *bil = strtod(strBil, &endptr);
      if (*endptr == '\0')
      {
        getchar() != '\n';
        return *bil;
        break;
      }
    }
  }
}
int validasiInputInteger(char *string, int *integer)
{

  int i = 0;

  while (isspace(string[i]))
    i++;

  int length = strlen(string);

  if (length == i)
    return 0;

  char integer_buffer[BUFFER_SIZE];
  int integer_chars = 0;

  // in the case of a negativ integer, the first char may be - symbol
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
  integer_buffer[integer_chars] = '\0';
  while (isspace(string[i]))
    i++;

  if (string[i] != '\0')
    return 0;
  *integer = atoi(integer_buffer);

  return 1;
}

void inputInt(char *inputText, int *inputVariable)
{
  int parsed_correct = 1;
  char buffer[BUFFER_SIZE];
  do
  {
    // input
    if (inputText != NULL)
    {
      printf("%s", inputText);
    }
    fgets(buffer, BUFFER_SIZE, stdin);

    if (validasiInputInteger(buffer, inputVariable) == 0)
    {
      statusMsg("ERROR: ANDA TIDAK MEMASUKKAN ANGKA");
    }

    if (*inputVariable <= 0)
    {
      statusMsg("ERROR: BILANGAN YANG DIMASUKKAN BUKAN BILANGAN POSITIF");
    }
  } while (validasiInputInteger(buffer, inputVariable) == 0 || *inputVariable < 0);
}

void inputPilihan(char *inputText, int *inputVariable)
{
  int parsed_correct = 1;
  char buffer[BUFFER_SIZE];
  do
  {
    // input
    if (inputText != NULL)
    {
      printf("%s", inputText);
    }
    fgets(buffer, BUFFER_SIZE, stdin);

    if (validasiInputInteger(buffer, inputVariable) == 0)
    {
      statusMsg("ERROR: ANDA TIDAK MEMASUKKAN NOMOR PERINTAH");
    }

    if (*inputVariable < 0)
    {
      statusMsg("ERROR: BILANGAN YANG DIMASUKKAN BUKAN BILANGAN POSITIF");
    }
  } while (validasiInputInteger(buffer, inputVariable) == 0 || *inputVariable < 0);
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

void pauseMsg()
{
  outMsg("Press enter to continue . . .");
  outLine();
  getchar();
  printf("\n");
}

void startingScreen() // tampilan head pada program
{
  system("cls");
  outLine();
  outMsg("");
  outMsg("PROGRAM KALKULATOR SEDERHANA");
  outMsg("");
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
  system("pause");
}

void head() // tampilan head pada program
{
  system("cls");
  outLine();
  outMsg("Program Kalkulator Sederhana");
  outLine();
}

void ulangprogram() // prosedur menampilkan status
{
  system("cls");
  outLine();
  outMsg("PROGRAM SELESAI");
  outLine();
  outMsg("Apakah Anda Ingin Mengulang Program?");
  outMsg("< 1 > Ulangi            < 2 > Keluar");
  outLine();
  inputPilihan("Masukkan perintah : ", &pilihan);
  do
  {
    if (pilihan == 1)
    {
      main();
    }
    else if (pilihan == 2)
    {
      printf("TERIMA KASIH SUDAH MENGGUNAKAN PROGRAM INI !");
      exit(0);
    }
    else
      statusMsg("ERROR: PERINTAH YANG ANDA PILIH TIDAK DITEMUKAN");
    inputPilihan("Masukkan perintah Kembali: ", &pilihan);
    fflush(stdin);
  } while (pilihan != 1 || pilihan != 2);
}

void menuUtama()
{
  head();
  // menu
  outMsg("Menu Pilihan Oprasi Aritmetika:");
  outMsg(" 1  = Penjumlahan               \0");
  outMsg(" 2  = Pengurangan               \0");
  outMsg(" 3  = Perkalian                 \0");
  outMsg(" 4  = Pembagian                 \0");
  outMsg(" 5  = Modulus                   \0");
  outMsg(" 0  = keluar                    \0");
  outLine();

  inputPilihan("masukkan pilihanmu: ", &pilihan);

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