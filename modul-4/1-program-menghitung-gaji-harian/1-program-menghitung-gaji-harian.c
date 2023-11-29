#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include <math.h>

#define BUFFER_SIZE 4096

struct Gaji {
    double gajiPerJam;
    double gajiPerJamLembur;
    int jamKerja;
    double gajiHarian;
};

void menuUtama();
void endMsg();
void startingScreen();
void head();
void outLine();
void outMsg(const char *format, ...);
void statusMsg(char *);
void pauseMsg();
struct Gaji hitungGaji(double jamKerja, double gajiPerjam);

int validateInputInteger(char *string, int *integer);
int validateInputDouble(char *string, double *floating_point);

int main(){
    startingScreen();
    menuUtama();
    endMsg();
}

struct Gaji hitungGaji(double jamKerja, double gajiPerJam) {
    struct Gaji hasil;

    // Mengatur nilai gaji per jam dan gaji per jam lembur
    hasil.gajiPerJam = gajiPerJam;
    hasil.gajiPerJamLembur = 8 * gajiPerJam;

    // Menghitung gaji harian
    if (jamKerja <= 8) {
        hasil.gajiHarian = jamKerja * gajiPerJam;
    } else {
        hasil.gajiHarian = 8 * gajiPerJam + (jamKerja - 8) * hasil.gajiPerJamLembur;
    }

    // Menyimpan jumlah jam kerja
    hasil.jamKerja = jamKerja;

    return hasil;
}

void startingScreen()
{
  system("cls");
  outLine();
  outMsg("");
  outMsg("PROGRAM MENGHITUNG GAJI HARIAN");
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
  outMsg("PROGAM STUDI TEKNOLOGI INFORMASI");
  outMsg("FAKULTAS TEKNIK");
  outMsg("UNIVERSITAS UDAYANA");
  outMsg("2023");
  outLine();
  pauseMsg();
}

void menuUtama()
{
    head();
    int jamKerja;
    char input[50]; // Menggunakan array karakter untuk membaca input

    do
    {
        outMsg("Masukkan jumlah jam kerja: ");
        scanf("%s", input);

        // Validasi input
        if (!validateInputInteger(input, &jamKerja) || jamKerja < 0)
        {
            outMsg("ERROR: Masukkan harus berupa angka non-negatif.");
            while (getchar() != '\n')
                ; // Membersihkan buffer input
        }
        else
        {
            break;
        }

    } while (1);

    // Gaji per jam
    double gajiPerJam = 10.625;

    // Menghitung gaji menggunakan fungsi hitungGaji
    struct Gaji hasilGaji = hitungGaji(jamKerja, gajiPerJam);

    // Menampilkan rincian perhitungan gaji harian
    outLine();
    outMsg("Rincian Gaji Harian");
    outMsg("Jumlah Jam Kerja: %d jam", hasilGaji.jamKerja);
    outMsg("Jumlah Jam Lembur: %d jam", (hasilGaji.jamKerja > 8) ? hasilGaji.jamKerja - 8 : 0);
    outMsg("Jam Kerja Harian: %d jam", (hasilGaji.jamKerja > 8) ? 8 : hasilGaji.jamKerja);
    outMsg("Gaji Per Jam: Rp%.3f", hasilGaji.gajiPerJam);
    outMsg("Gaji Per Jam Lembur: Rp%.3f", hasilGaji.gajiPerJamLembur);
    outMsg("Gaji Harian: Rp%.3f", hasilGaji.gajiHarian);
    outLine();
    system("pause");
}


void head() 
{
  system("cls");
  outLine();
  outMsg("PROGRAM MENGHITUNG GAJI HARIAN");
  outLine();
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

void statusMsg(char *inputText) 
{
  outLine();
  outMsg(inputText);
  outLine();
}

void endMsg()
{
    int pilihan;
    char input[50];

    do
    {
        outLine();
        outMsg("PROGRAM SELESAI");
        outMsg("< 1 > Ulangi            < 2 > Keluar");
        outMsg("Masukkan perintah : ");
        scanf("%s", input);

        // Validasi input
        if (!validateInputInteger(input, &pilihan) || (pilihan != 1 && pilihan != 2))
        {
            outMsg("ERROR: Masukkan harus berupa angka 1 atau 2.");
            while (getchar() != '\n');
        }
        else
        {
            break;
        }

    } while (1);

    if (pilihan == 1)
    {
        menuUtama();
    }
    else if (pilihan == 2)
    {
        exit(0);
    }
}
void pauseMsg()
{
  outMsg("Press enter to continue . . .");
  getchar();
  printf("\n");
}

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

  if (string[i] == '-')
  {
    integer_buffer[integer_chars] = '-';
    integer_chars++;
    i++;
  }

  while (i < length && !isspace(string[i]))
  {
    if (!isdigit(string[i]))
    {
      outMsg("ERROR: Masukkan harus berupa angka.");
      return 0;
    }

    integer_buffer[integer_chars] = string[i];
    integer_chars++;
    i++;
  }

  integer_buffer[integer_chars] = '\0';

  while (isspace(string[i]))
    i++;

  if (string[i] != '\0')
  {
    printf("ERROR: Karakter tak dikenal setelah angka.\n");
    return 0;
  }

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
  int hasDecimal = 0; 

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
      hasDecimal = 1;
      i++;
    }
    else
    {
      return 0; 
    }
  }

  double_buffer[double_chars] = '\0';

  while (isspace(string[i]))
    i++;

  if (string[i] != '\0')
    return 0;

  *floating_point = atof(double_buffer);

  return 1;
}