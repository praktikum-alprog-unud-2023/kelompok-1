#include "../../validasi/utility/utility.h"
char namaProgram[] = "PROGRAM OPERASI MATRIKS";

void inputMatriks();
void inputInteger(char *message, int *integer);
void inputPilihanNew(char *message, int *integer);
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
  endMsg();
}

void inputInteger(char *inputText, int *inputVariable)
{
  int parsed_correct = 1;
  char buffer[BUFFER_SIZE];
  do
  {
    // input
    if (inputText != NULL)
    {
      printf(">>>   %s", inputText);
    }

    // accept a line of string input from the user, store it into buffer

    fgets(buffer, BUFFER_SIZE, stdin);

    if (validateInputInteger(buffer, inputVariable) == 0)
    {
      statusMsg("ERROR: ANDA TIDAK MEMASUKKAN NOMOR PERINTAH");
    }

    if (*inputVariable <= 0)
    {
      statusMsg("ERROR: INPUT TIDAK VALID");
    }
  } while (validateInputInteger(buffer, inputVariable) == 0 || *inputVariable <= 0);
}

void inputPilihanNew(char *inputText, int *inputVariable)
{
  int parsed_correct = 1;
  char buffer[BUFFER_SIZE];
  do
  {
    // input
    if (inputText != NULL)
    {
      printf(">>>   %s", inputText);
    }

    // accept a line of string input from the user, store it into buffer

    fgets(buffer, BUFFER_SIZE, stdin);

    if (validateInputInteger(buffer, inputVariable) == 0)
    {
      statusMsg("ERROR: ANDA TIDAK MEMASUKKAN NOMOR PERINTAH");
    }
    if (*inputVariable <= 0)
    {
      statusMsg("ERROR: INPUT TIDAK VALID");
    }
    if (*inputVariable > 3)
    {
      statusMsg("ERROR: INPUT TIDAK VALID");
    }
  } while (validateInputInteger(buffer, inputVariable) == 0 || *inputVariable <= 0 || *inputVariable > 3);
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
        printf(">>>  Masukkan nilai baris %d kolom %d: ", i + 1, j + 1);
        scanf("%s", input);
        clearInputBuffer();

        // Melakukan validasi input sebelum mengonversi ke integer
        if (validateInputInteger(input, &matrix1[i][j]))
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
        printf(">>>  Masukkan nilai baris %d kolom %d: ", i + 1, j + 1);
        scanf("%s", input);
        clearInputBuffer();

        // Melakukan validasi input sebelum mengonversi ke integer
        if (validateInputInteger(input, &matrix2[i][j]))
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
  inputPilihanNew("masukan pilihan : ", &choice);

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
