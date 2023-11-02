#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#define BUFFER_SIZE 4096

int pilihan;

int validasiInputInteger(char *string, int *integer);
int validasiBil(int *bil);
void ulangprogram();
void startingScreen();
void head();
void outLine();
void outMsg(const char *format, ...);
void statusMsg(const char *);
void pauseMsg();
void inputInt(const char *inputText, int *inputVariable);
void inputPilihan(const char *inputText, int *inputVariable);
void fibonacci();
void menuUtama();

int main()
{
  startingScreen();
  menuUtama();
  pauseMsg();
  ulangprogram();
}

void fibonacci()
{
  int jumlah;
  int b1 = 0, b2 = 1;
  int nextBil = b1 + b2;
  head();
  outLine();
  outMsg("Deret Bilangan Fibonacci");
  outLine();
  outMsg("Masukkan banyak bilangan : ");
  validasiBil(&jumlah);

  if (jumlah <= 0)
  {
    statusMsg("ERROR: Masukkan bilangan positif.");
  }
  else
  {
    outMsg("Bilangan Fibonacci: ");
    for (int i = 1; i <= jumlah; i++)
    {
      outMsg("%d", b1);
      if (i < jumlah)
        outMsg(", ");
      nextBil = b1 + b2;
      b1 = b2;
      b2 = nextBil;
    }
  }
}

int validasiBil(int *bil)
{
  char strBil[100];
  while (1)
  {
    if (scanf("%99[^\n]", strBil) != 1)
    {
      printf("Input harus berupa bilangan, silahkan ulangi kembali: ");
      while (getchar() != '\n')
        ;
    }
    else
    {
      char *endptr;
      *bil = atoi(strBil);
      if (*bil >= 0)
      {
        while (getchar() != '\n')
          ;
        return *bil;
      }
      else
      {
        printf("Bilangan harus positif, silahkan ulangi kembali: ");
        while (getchar() != '\n')
          ;
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

void inputInt(const char *inputText, int *inputVariable)
{
  char buffer[BUFFER_SIZE];
  do
  {
    if (inputText != NULL)
    {
      printf("%s", inputText);
    }
    fgets(buffer, BUFFER_SIZE, stdin);

    if (validasiInputInteger(buffer, inputVariable) == 0)
    {
      statusMsg("ERROR: ANDA TIDAK MEMASUKKAN ANGKA");
    }
  } while (validasiInputInteger(buffer, inputVariable) == 0 || *inputVariable < 0);
}

void inputPilihan(const char *inputText, int *inputVariable)
{
  char buffer[BUFFER_SIZE];
  do
  {
    if (inputText != NULL)
    {
      printf("%s", inputText);
    }
    fgets(buffer, BUFFER_SIZE, stdin);

    if (validasiInputInteger(buffer, inputVariable) == 0)
    {
      statusMsg("ERROR: ANDA TIDAK MEMASUKKAN NOMOR PERINTAH");
    }
    else if (*inputVariable < 0)
    {
      statusMsg("ERROR: BILANGAN YANG DIMASUKKAN BUKAN BILANGAN POSITIF");
    }
  } while (validasiInputInteger(buffer, inputVariable) == 0 || *inputVariable < 0);
}

void outLine()
{
  printf("|=================================================================================|\n");
}

void outMsg(const char *format, ...)
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
    numSpaces = 0;
  }

  char tempMessage[82];
  memset(tempMessage, ' ', numSpaces);
  strcpy(tempMessage + numSpaces, outputMessage);
  memset(tempMessage + numSpaces + inputLength, ' ', numSpaces);

  tempMessage[outputLength - 1] = '\0';
  printf("|%s|\n", tempMessage);
}

void statusMsg(const char *inputText)
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

void startingScreen()
{
  system("cls");
  outLine();
  outMsg("");
  outMsg("PROGRAM DERET BILANGAN FIBONACCI");
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

void head()
{
  system("cls");
  outLine();
  outMsg("Program Deret Bilangan Fibonacci");
  outLine();
}

void ulangprogram()
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
      printf("TERIMA KASIH SUDAH MENGGUNAKAN PROGRAM INI!\n");
      exit(0);
    }
    else
    {
      statusMsg("ERROR: PERINTAH YANG ANDA PILIH TIDAK DITEMUKAN");
      inputPilihan("Masukkan perintah Kembali: ", &pilihan);
    }
  } while (pilihan != 1 && pilihan != 2);
}

void menuUtama()
{
  outMsg(" 1 = Deret Bilangan Fibonacci");
  outMsg(" 0 = Keluar");
  outLine();
  inputPilihan("Masukkan pilihanmu : ", &pilihan);

  switch (pilihan)
  {
  case 1:
    fibonacci();
    break;
  case 0:
    printf("Terima Kasih Sudah Menggunakan Program Ini :)\n");
    exit(0);
    break;
  default:
    statusMsg("ERROR: PERINTAH YANG ANDA PILIH TIDAK DITEMUKAN");
    pauseMsg();
    menuUtama();
    break;
  }
}
