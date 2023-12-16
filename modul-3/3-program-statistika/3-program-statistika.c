#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>

void menu();
void seedArray(int arr[], int n);
double input();
void hapus_buffer();
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void printArray(int arr[], int n);
float median(int arr[], int n);
float mean(int arr[], int n);
float modus(int arr[], int n);

// ultility function
void endMsg();
void pauseMsg();
void inputThisInt(char *inputText, int *inputVariable);
void head();
void outLine();
void outMsg(const char *format, ...);
void statusMsg(char *);
// Validasi input
int validateInputInteger(char *string, int *integer);

// global variable
#define BUFFER_SIZE 4096 // Konstanta untuk ukuran buffer

int main()
{
  system("cls");
  outLine();
  outMsg("PROGRAM STATISTIKA");
  outLine();
  outMsg("KELOMPOK I");
  outLine();
  outMsg("ANGGOTA:");
  outMsg("1. NI NENGAH SENJA SRI PRATIWI             2305551014");
  outMsg("2. I GUSTI AYU MARTINI                     2305551020");
  outMsg("3. PUTU EKA DODY ARSANA PUTRA              2305551075");
  outMsg("4. KALVIN ANGELITO ANG                     2305551115");
  outMsg("5. MUHAMMAD DZIKRI DHANIAWAN               2305551146");
  outMsg("6. VINCENTIUS BONAVERREL DOMINICO          2305554176");
  outLine();
  outLine();
  outMsg("PROGAM STUDI TEKNOLOGI INFORMASI");
  outMsg("FAKULTAS TEKNIK");
  outMsg("UNIVERSITAS UDAYANA");
  outMsg("2023");
  outLine();
  pauseMsg();
  menu();
  return 0;
}

void menu()
{
  float pilihan;
  int cek;
  int n;
  float hasil;

  system("cls");
  outLine();
  outMsg("Program Statistika");
  outLine();
  outMsg("Pilih Operasi :  ");
  outMsg("1. Median        ");
  outMsg("2. Modus         ");
  outMsg("3. Mean          ");
  outMsg("4. Keluar Program");
  outLine();
  printf("| >>>>>>>>>>>>>> Pilihan : ");
  pilihan = input();
  cek = pilihan;
  if (cek == pilihan)
  {
    if (pilihan > 3 || pilihan < 1)
    {
      if (pilihan == 4)
      {
        return;
      }
      else
      {
        system("cls");
        statusMsg("ERROR : Input Salah!!!");
        pauseMsg();
        menu();
      }
    }
    else
    {
      printf("| >>>>>>>>>>>>>> Masukkan panjang array : ");
      n = input();
      int arr[n];
      seedArray(arr, n);
      outLine();
      printf("| Hasil sorting array : ");
      quickSort(arr, 0, n - 1);
      printArray(arr, n);
      switch ((int)pilihan)
      {
      case 1:
        hasil = median(arr, n);
        printf("| Median dari data adalah : ");
        break;
      case 2:
        hasil = modus(arr, n);
        printf("| Modus dari data adalah : ");
        break;
      case 3:
        hasil = mean(arr, n);
        printf("| Mean dari data adalah : ");
        break;
      }
      printf("%.2lf\n", hasil);
      outLine();
      endMsg();
    }
  }
  else
  {
    system("cls");
    statusMsg("ERROR : Input Salah!!!");
    pauseMsg();
    menu();
  }
}

void seedArray(int arr[], int n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    printf("| >>>>>>>>>>>>>> Masukkan data ke %d : ", i + 1);
    *(arr + i) = input();
  }
}

double input()
{
  double angka;
  char karakter;
  if (scanf("%lf%c", &angka, &karakter) != 2 || angka <= 0 || karakter != '\n' || karakter == ',')
  {
    hapus_buffer();
    statusMsg("ERROR : Input Salah!!!");
    printf("| >>>>>>>>>>>>>> Masukkan angka yang benar : ");
    return input();
  }
  else
  {
    return angka;
  }
}

void hapus_buffer()
{
  char c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

void quickSort(int arr[], int low, int high)
{
  if (low < high)
  {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

int partition(int arr[], int low, int high)
{
  int pivot = *(arr + high);
  int temp;
  int i = (low - 1);
  int j;
  for (j = low; j <= high - 1; j++)
  {
    if (*(arr + j) <= pivot)
    {
      i++;
      temp = *(arr + i);
      *(arr + i) = *(arr + j);
      *(arr + j) = temp;
    }
  }
  temp = *(arr + i + 1);
  *(arr + i + 1) = *(arr + high);
  *(arr + high) = temp;
  return (i + 1);
}

void printArray(int arr[], int n)
{
  int i;
  for (i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

float median(int arr[], int n)
{
  float tengah;
  if (n % 2 == 0)
    tengah = (*(arr + ((n - 1) / 2)) + *(arr + (n / 2))) / 2.0;
  else
    tengah = *(arr + (n / 2));
  return tengah;
}

float mean(int arr[], int n)
{
  float sum = 0, avg;
  int i;
  for (i = 0; i < n; i++)
    sum = sum + *(arr + i);
  avg = sum / (float)n;
  return avg;
}

float modus(int arr[], int n)
{
  float modus;
  int max = 0;
  int i;
  int j;
  for (i = 0; i < n; i++)
  {
    int count = 0;
    for (j = i + 1; j < n; j++)
    {
      if (*(arr + i) == *(arr + j))
      {
        count = count + 1;
      }
      if (count > max)
      {
        max = count;
        modus = *(arr + i);
      }
    }
  }
  return modus;
}

// utility function
void endMsg() // prosedur menampilkan status
{
  int pilihan;
  outLine();
  outMsg("PROGRAM SELESAI");
  outMsg("< 1 > Ulangi            < 2 > Keluar");
  inputThisInt("Masukkan perintah : ", &pilihan);
  do
  {
    if (pilihan == 1)
    {
      main();
    }
    else if (pilihan == 2)
    {
      // keluar dari program
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

void head() // tampilan head pada program
{
  system("cls");
  outLine();
  outMsg("Program Statistika");
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
