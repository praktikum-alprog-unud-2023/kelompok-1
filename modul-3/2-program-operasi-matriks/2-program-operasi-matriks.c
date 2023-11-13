#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>

#define BUFFER_SIZE 100
int validasiInputInteger(char *string, int *integer);
void ulangProgram();
void startingScreen();
void head();
void outLine();
void outMsg(const char *format, ...);
void statusMsg(char *);
void inputMatriks();
void inputInteger(char *message, int *integer);
int rows, cols;

void clearInputBuffer()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
  {
  }
}

int main()
{
  startingScreen();
  inputMatriks();
  system("pause");
  ulangProgram();
}

void inputInteger(char *message, int *integer)
{
  char input[BUFFER_SIZE];
  int isValid = 0;

  while (!isValid)
  {
    printf("%s", message);
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    if (input[0] == '\0')
    {
      statusMsg("Input tidak boleh kosong. Masukkan angka positif.");
    }
    else
    {
      int isValidInput = 1;
      for (int i = 0; input[i] != '\0'; i++)
      {
        if (!isdigit(input[i]))
        {
          isValidInput = 0;
          break;
        }
      }

      if (isValidInput)
      {
        *integer = atoi(input);
        if (*integer > 0)
        {
          isValid = 1;
        }
        else
        {
          statusMsg("Input harus menjadi angka positif.");
        }
      }
      else
      {
        statusMsg("Input tidak valid. Masukkan angka positif.");
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

  if (string[i] == '-' || string[i] == '+')
  {
    integer_buffer[integer_chars] = string[i];
    integer_chars++;
    i++;

    if (!isdigit(string[i]) && string[i] != '\n')
      return 0;
  }

  while (i < length && !isspace(string[i]) && string[i] != '\n')
  {
    if (!isdigit(string[i]))
      return 0;

    integer_buffer[integer_chars] = string[i];
    integer_chars++;
    i++;
  }
  integer_buffer[integer_chars] = '\0';

  if (integer_chars == 0)
    return 0;

  if (string[i] != '\0' && string[i] != '\n')
    return 0;

  *integer = atoi(integer_buffer);

  return 1;
}

// Fungsi untuk menampilkan matriks
void displayMatrix(int rows, int cols, int matrix[rows][cols])
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      printf("%d\t", matrix[i][j]);
    }
    printf("\n");
  }
}

// Fungsi untuk penjumlahan dua matriks
void addMatrices(int rows, int cols, int mat1[rows][cols], int mat2[rows][cols], int result[rows][cols])
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      result[i][j] = mat1[i][j] + mat2[i][j];
    }
  }
}

// Fungsi untuk perkalian dua matriks
void multiplyMatrices(int rows, int cols, int mat1[rows][cols], int mat2[rows][cols], int result[rows][cols])
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      result[i][j] = 0;
      for (int k = 0; k < rows; k++)
      {
        result[i][j] += mat1[i][k] * mat2[k][j];
      }
    }
  }
}

// Fungsi untuk mentranspose matriks
void transposeMatrix(int rows, int cols, int matrix[rows][cols], int result[cols][rows])
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      result[j][i] = matrix[i][j];
    }
  }
}

// utilities
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
void head() // tampilan head pada program
{
  system("cls");
  outLine();
  outMsg("PROGRAM OPERASI MATEMATIKA MATRIKS");
  outLine();
}

// tampilan program
void startingScreen() // tampilan pada program
{
  system("cls");
  outLine();
  outMsg("");
  outMsg("PROGRAM OPERASI MATEMATIKA MATRIKS");
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
  system("cls");
}
void menuMatriks()
{
  outLine();
  outMsg("MENU OPERASI MATEMATIKA MATRIKS ");
  outLine();
  outMsg("1 = Perkalian");
  outMsg("2 = Penjumlahan ");
  outMsg("3 = Transpose");
  outLine();
}

void ulangProgram()
{
  int pilihan;
  system("cls");
  outLine();
  outMsg("PROGRAM SELESAI");
  outLine();
  outMsg("Apakah Anda Ingin Mengulang Program?");
  outMsg("< 1 > Ulangi            < 2 > Keluar");
  outLine();
  inputInteger("Masukkan perintah : ", &pilihan);
  do
  {
    if (pilihan == 1)
    {
      main();
    }
    else if (pilihan == 2)
    {
      statusMsg("TERIMA KASIH SUDAH MENGGUNAKAN PROGRAM INI !");
      exit(0);
    }
    else
    {
      statusMsg("ERROR: PERINTAH YANG ANDA PILIH TIDAK DITEMUKAN");
    }
    inputInteger("Masukkan perintah Kembali: ", &pilihan);
  } while (pilihan != 1 && pilihan != 2);
}

void inputMatriks()
{
  head();
  outLine();
  outMsg("MASUKAN ORDO MATRIKS");
  outLine();
  inputInteger("Masukkan jumlah baris matriks: ", &rows);
  inputInteger("Masukkan jumlah kolom matriks: ", &cols);

  system("pause");
  system("cls");

  int matrix1[rows][cols];
  int matrix2[rows][cols];
  int transposeMatrix1[cols][rows];
  int transposeMatrix2[cols][rows];
  int resultMatrix[rows][cols];
  int choice;

  head();

  statusMsg("Masukkan nilai untuk matriks 1");
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      char input[BUFFER_SIZE];
      int isValid = 0;
      while (!isValid)
      {
        printf("Masukkan nilai baris %d kolom %d: ", i + 1, j + 1);
        scanf("%s", input);
        clearInputBuffer();

        // Melakukan validasi input sebelum mengonversi ke integer
        if (validasiInputInteger(input, &matrix1[i][j]))
        {
          isValid = 1;
        }
        else
        {
          statusMsg("Input tidak valid. Masukkan angka.");
        }
      }
    }
  }

  statusMsg("Masukkan nilai untuk matriks 2");
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      char input[BUFFER_SIZE];
      int isValid = 0;
      while (!isValid)
      {
        printf("Masukkan nilai baris %d kolom %d: ", i + 1, j + 1);
        scanf("%s", input);
        clearInputBuffer();

        // Melakukan validasi input sebelum mengonversi ke integer
        if (validasiInputInteger(input, &matrix2[i][j]))
        {
          isValid = 1;
        }
        else
        {
          statusMsg("Input tidak valid. Masukkan angka.");
        }
      }
    }
  }

  system("pause");

  system("cls");

  statusMsg("Pilih operasi matematika yang ingin dilakukan:");
  outMsg("1. Penjumlahan Matriks");
  outMsg("2. Perkalian Matriks");
  outMsg("3. Transpose Matriks");
  statusMsg("MASUKAN PILIHAN (1-3)");
  inputInteger("masukan pilihan :", &choice); // DISINI ERROR TERUS TOT

  switch (choice)
  {
  case 1:
    statusMsg("Penjumlahan Matrix:");
    addMatrices(rows, cols, matrix1, matrix2, resultMatrix);
    displayMatrix(rows, cols, resultMatrix);
    break;
  case 2:
    statusMsg("Perkalian Matrix:");
    multiplyMatrices(rows, cols, matrix1, matrix2, resultMatrix);
    displayMatrix(rows, cols, resultMatrix);
    break;
  case 3:
    printf("Matrix 1:\n");
    displayMatrix(rows, cols, matrix1);
    printf("Matrix 2:\n");
    displayMatrix(rows, cols, matrix2);

    transposeMatrix(rows, cols, matrix1, transposeMatrix1);
    printf("Transpose of Matrix 1:\n");
    displayMatrix(cols, rows, transposeMatrix1);

    transposeMatrix(rows, cols, matrix2, transposeMatrix2);
    printf("Transpose of Matrix 2:\n");
    displayMatrix(cols, rows, transposeMatrix2);
    break;
  default:
    statusMsg("Pilihan tidak valid.");
  }
}
