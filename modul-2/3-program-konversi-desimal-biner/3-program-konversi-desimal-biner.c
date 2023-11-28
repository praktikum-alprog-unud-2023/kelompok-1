#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

// define function from ultility
#define BUFFER_SIZE 4096 // Konstanta untuk ukuran buffer

// global variable
int pilihan;

void endMsg();
void pauseMsg();
void inputThisInt(char *inputText, int *inputVariable);
void head();
void outLine();
void outMsg(const char *format, ...);
void statusMsg(char *);
// Validasi input
int validateInputInteger(char *string, int *integer);
void input_binary_str(char *input_param);

void namaKelompok()
{
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
  pauseMsg();
}

int konversiDesimal(char biner[])
{
  int panjang = 0;
  while (biner[panjang] != '\0')
  {
    panjang++;
  }
  int desimal = 0;
  int pangkat = 0;
  for (int i = panjang - 1; i >= 0; i--)
  {
    if (biner[i] == '1')
    {
      desimal += pow(2, pangkat);
    }
    pangkat++;
  }
  return desimal;
}

void konversiBiner(int n)
{
  if (n == 0)
  {
    return;
  }
  konversiBiner(n / 2);
  printf("%d", n % 2);
}

int main()
{
  int desimal;
  char biner[100];

  system("cls");
  head();
  namaKelompok();
  system("cls");

  head();
  outLine();
  outMsg("Pilih Opsi:");
  outMsg("1. Desimal Ke Biner");
  outMsg("2. Biner Ke Desimal");
  outMsg("");
  inputThisInt("Masukkan perintah : ", &pilihan);
  outMsg("");
  outLine();
  system("cls");
  if (pilihan == 1)
  {
    outLine();
    outMsg("KONVERSI DESIMAL KE BINER");
    outLine();
    inputThisInt("Masukkan bilangan desimal : ", &desimal);
    printf("| Konversi ke biner\t\t: ");
    if (desimal == 0)
    {
      printf("0");
    }
    else
    {
      konversiBiner(desimal);
    }
    printf("\n");
    outLine();
  }
  else if (pilihan == 2)
  {
    outLine();
    outMsg("KONVERSI BINER KE DESIMAL");
    outLine();
    printf("| >>>>>>>>>>>>>> Masukan bilangan biner : ");
    input_binary_str(biner);

    desimal = konversiDesimal(biner);
    printf("| Konversi ke desimal\t\t: %d\n", desimal);
  }
  else
  {
    statusMsg("ERROR: PERINTAH YANG ANDA PILIH TIDAK DITEMUKAN");
    pauseMsg();
    main();
  }
  endMsg();
  return 0;
}

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
  outMsg("Program Nilai Akhir");
  outMsg("Konversi Bilangan");
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

void input_binary_str(char *input_param)
{
  char input[100];
  int i = 0, error = 0;

  fflush(stdin);
  fgets(input, sizeof(input), stdin);

  if (input[0] == '\0')
    error = 1;

  while (input[i] != '\0' && input[i] != '\n')
  {
    if (strchr("01", input[i]))
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
    outLine();
    outMsg("ERROR : INVALID BINARY NUMBER!");
    outLine();
    printf("| >>>>>>>>>>>>>> Masukan Angka Kembali : ");
    return input_binary_str(input_param);
  }
  input[i] = '\0';
  strcpy(input_param, input);
}
