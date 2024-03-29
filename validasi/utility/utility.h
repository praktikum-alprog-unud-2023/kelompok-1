#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <limits.h>
#include <stdbool.h>

// Konstanta untuk ukuran buffer
#define BUFFER_SIZE 4096

// Deklarasi variabel global
int pilihan;
char namaProgram[];

void menuUtama();
void endMsg();
void inputThisInt(char *inputText, int *inputVariable);
void inputThisDouble(char *inputText, double *inputVariable);
void inputThisAlpha(char *inputText, char *inputVariable);
void startingScreen();
void head();
void outLine();
void singleLine();
void outMsg(const char *format, ...);
void leftAlignOutMsg(const char *format, ...);
void statusMsg(char *);
void pauseMsg();
void clearInputBuffer();

// Validasi input
int validateInputInteger(char *string, int *integer);
int validateInputDouble(char *string, double *floating_point);
int validateInputAlpha(char *string, char *alpha_string);
void input_binary_str(char *input_param);
int validasiBil(int *bil);
int input_positive_int();
int input_valid_option();
int input_only_option(const char *str);
double input_positive_double();
void inputPilihan(const char *inputText, int *inputVariable);

/*=================================================================================
  Tampilan Ketika Program Pertama Kali Dibuka
  Prosedur Pelengkap:
      outline();
      outMsg(pesan);
      pauseMsg();
  =================================================================================
*/
void startingScreen()
{
  head();
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

/*=================================================================================
  Tampilan Judul Program (Isi di Setiap Bagian Program)
  =================================================================================
*/
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

void singleLine()
{
  printf("|---------------------------------------------------------------------------------|\n");
}

/*=================================================================================
  Prosedur Untuk mencetak Teks Dengan Posisi Otomatis Center
  Library:
      #include <stdio.h>
      #include <stdarg.h>
      #include <string.h>
  =================================================================================
*/
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

void leftAlignOutMsg(const char *format, ...) // prosedur menampilkan pesan
{
  va_list args;
  va_start(args, format);

  char outputMessage[82];
  int outputLength = 82;

  vsnprintf(outputMessage, outputLength, format, args);

  va_end(args);

  const int inputLength = strlen(outputMessage);
  if (inputLength >= outputLength - 1)
  {
    outputMessage[outputLength - 1] = '\0'; // Truncate if needed
  }
  else
  {
    printf("| %-*s|\n", outputLength - 2, outputMessage);
  }
}

/*=================================================================================
  Prosedur Untuk mencetak Teks Box
  Library:
      #include <stdio.h>
      #include <stdarg.h>
      #include <stdlib.h>
      #include <string.h>
  =================================================================================
*/
void txtBox(const char *format, int length, char alignment, ...) // prosedur menampilkan pesan
{
  va_list args;
  va_start(args, alignment);

  char *outputMessage = (char *)malloc((length + 1) * sizeof(char));
  if (outputMessage == NULL)
  {
    // Handle memory allocation failure
    return;
  }

  int outputLength = length;

  vsnprintf(outputMessage, outputLength, format, args);

  va_end(args);

  int inputLength = strlen(outputMessage);
  int numSpaces = outputLength - inputLength;

  if (numSpaces < 0)
  {
    numSpaces = 0; // Avoid negative padding
  }

  char *tempMessage = (char *)malloc((outputLength + 1) * sizeof(char));
  if (tempMessage == NULL)
  {
    // Handle memory allocation failure
    free(outputMessage);
    return;
  }

  if (alignment == 'L' || alignment == 'l')
  { // Left-aligned
    strcpy(tempMessage, outputMessage);
    memset(tempMessage + inputLength, ' ', numSpaces);
  }
  else if (alignment == 'R' || alignment == 'r')
  { // Right-aligned
    memset(tempMessage, ' ', numSpaces);
    strcpy(tempMessage + numSpaces, outputMessage);
  }
  else if (alignment == 'C' || alignment == 'c')
  { // Centered
    int numLeftSpaces = numSpaces / 2;
    int numRightSpaces = numSpaces - numLeftSpaces;
    memset(tempMessage, ' ', numLeftSpaces);
    strcpy(tempMessage + numLeftSpaces, outputMessage);
    memset(tempMessage + numLeftSpaces + inputLength, ' ', numRightSpaces);
  }
  else
  {
    // Default to left-align if an invalid alignment is provided
    strcpy(tempMessage, outputMessage);
    memset(tempMessage + inputLength, ' ', numSpaces);
  }

  tempMessage[outputLength] = '\0'; // Ensure null-terminated string
  printf("%s", tempMessage);

  free(outputMessage);
  free(tempMessage);
}

/*=================================================================================
  Prosedur Untuk Mencetak Pesan Kesalahan
  Prosedur Pelengkap:
      outMsg("pesan");
  =================================================================================
*/
void statusMsg(char *inputText) // prosedur menampilkan status
{
  outLine();
  outMsg(inputText);
  outLine();
}

/*=================================================================================
  Prosedur Untuk Menampilkan Konfirmasi Apakah User Ingin Mengulang Program
  Prosedur Pelengkap:
      outline();
      outMsg("pesan");
      inputThisInt("teks", &variabel);
  Library:
      #include <stdio.h>
      #include <stdlib.h>
  =================================================================================
*/
void endMsg() // prosedur menampilkan status
{
  system("cls");
  outLine();
  outMsg("PROGRAM SELESAI");
  outLine();
  outMsg("Apakah Anda Ingin Mengulang Program?");
  outMsg("< 1 > Ulangi            < 2 > Keluar");
  outLine();
  inputThisInt("Masukkan perintah : ", &pilihan);
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
    inputThisInt("Masukkan perintah Kembali: ", &pilihan);
    fflush(stdin);
  } while (pilihan != 1 || pilihan != 2);
}

void pauseMsg()
{
  outMsg("Press enter to continue . . .");
  outLine();
  getchar();
  printf("\n");
}

/*=================================================================================
  Fungsi Untuk Memvalidasi Input Bilangan Bulat
  Library:
      #include <ctype.h>
      #include <string.h>
      #include <stdlib.h>
  =================================================================================
*/
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

/*=================================================================================
  Fungsi Untuk Memvalidasi Input Bilangan Desimal
  Library:
      #include <ctype.h>
      #include <string.h>
      #include <stdlib.h>
  =================================================================================
*/
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

/*=================================================================================
  Fungsi Untuk Memvalidasi Input Huruf
  Library:
      #include <ctype.h>
      #include <string.h>
      #include <stdlib.h>
  =================================================================================
*/
int validateInputAlpha(char *string, char *text)
{
  int i = 0;
  int containsText = 0;

  while (isspace(string[i]))
    i++;

  int length = strlen(string);

  if (length == i)
    return 0;

  int text_chars = 0;

  while (i < length && string[i] != '\n')
  {
    if (isalpha(string[i]) || isspace(string[i])) // Check if the character is alphabetic or a space
    {
      text[text_chars] = string[i];
      text_chars++;
      i++;
      if (isalpha(string[i]))
        containsText = 1;
    }
    else
    {
      return 0; // Invalid character found (e.g., a number or special character)
    }
  }

  // Put a null terminator at the end of the text to make it a proper string
  text[text_chars] = '\0';

  if (containsText)
    return 1;
  else
    return 0; // No alphabetic characters found
}

/*=================================================================================
  Fungsi Untuk Menginputkan Bilangan Bulat dan Memvalidasinya
  Fungsi Pelengkap:
      validateInputInteger(param1, param2)
      statusMsg("pesan");
  Library:
      #include <stdio.h>
      #include <stdlib.h>
  =================================================================================
*/
void inputThisInt(char *inputText, int *inputVariable)
{
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

/*=================================================================================
  Fungsi Untuk Menginputkan Bilangan Desimal dan Memvalidasinya
  Fungsi Pelengkap:
      validateInputDouble(param1, param2)
      statusMsg("pesan");
  Library:
      #include <stdio.h>
      #include <stdlib.h>
  =================================================================================
*/
void inputThisDouble(char *inputText, double *inputVariable)
{
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

/*=================================================================================
  Fungsi Untuk Menginputkan Huruf dan Memvalidasinya
  Fungsi Pelengkap:
      validateInputAlpha(param1, param2)
      statusMsg("pesan");
  Library:
      #include <stdio.h>
      #include <stdlib.h>
  =================================================================================
*/
void inputThisAlpha(char *inputText, char *inputVariable)
{
  int parsed_correct = 1;
  char buffer[BUFFER_SIZE];
  do
  {
    // Input prompt
    if (inputText != NULL)
    {
      printf(">>>>>>>>>>>>>>>>>>>>>>>    %s", inputText);
    }

    // Accept a line of string input from the user, store it into buffer
    fgets(buffer, BUFFER_SIZE, stdin);

    if (validateInputAlpha(buffer, inputVariable) == 0)
    {
      statusMsg("ERROR: ANDA TIDAK MEMASUKKAN HURUF ALFABET");
      pauseMsg();
    }
  } while (validateInputAlpha(buffer, inputVariable) == 0);
}

/*=================================================================================
  Fungsi Untuk Menginputkan Bilangan Biner dan Memvalidasinya
  Variabel yang digunakan dalam parameter misalnya:
      char inputBinaryNumber[100];
  Cara memanggil:
      input_binary_str(inputBinaryNumber);
      printf("%s\n", inputBinaryNumber);
  =================================================================================
*/
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
    printf("\nInvalid binary number!");
    printf("\nSilahkan Masukan Angka Kembali : ");
    return input_binary_str(input_param);
  }
  input[i] = '\0';
  strcpy(input_param, input);
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

    if (validateInputInteger(buffer, inputVariable) == 0)
    {
      statusMsg("ERROR: ANDA TIDAK MEMASUKKAN NOMOR PERINTAH");
    }
    else if (*inputVariable < 0)
    {
      statusMsg("ERROR: BILANGAN YANG DIMASUKKAN BUKAN BILANGAN POSITIF");
    }
  } while (validateInputInteger(buffer, inputVariable) == 0 || *inputVariable < 0);
}

void clearInputBuffer()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
  {
  }
}