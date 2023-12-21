#include "../../validasi/utility/utility.h"

char namaProgram[] = "PROGRAM BILANGAN FIBONACCI";

int fibonacciRekursif(int n, int *sum);
int fibonacciIteratif(int n, int *sum);
void menuUtama();

int main()
{
  startingScreen();
  menuUtama();
  pauseMsg();
  endMsg();
}

int fibonacciRekursif(int n, int *sum)
{
  if (n <= 0)
  {
    *sum = 0;
    return 0;
  }
  else if (n == 1)
  {
    *sum = 1;
    return 1;
  }
  else
  {
    int prevSum1, prevSum2;
    int fib1 = fibonacciRekursif(n - 1, &prevSum1);
    int fib2 = fibonacciRekursif(n - 2, &prevSum2);

    *sum = fib1 + fib2 + prevSum1;
    return fib1 + fib2;
  }
}

int fibonacciIteratif(int n, int *sum)
{
  if (n <= 0)
  {
    *sum = 0;
    return 0;
  }
  int b1 = 1, b2 = 1, nextBil, current, sumFib = 0;

  for (int i = 0; i < n; i++)
  {
    sumFib += b1;
    current = b1;
    nextBil = b1 + b2;
    b1 = b2;
    b2 = nextBil;
  }

  *sum = sumFib;
  return current;
}

void menuUtama()
{
  head();
  outMsg(" 1 = Deret Bilangan Fibonacci Rekursif");
  outMsg(" 2 = Deret Bilangan Fibonacci Iteratif");
  outMsg(" 0 = Keluar");
  outLine();
  inputPilihan("Masukkan pilihanmu : ", &pilihan);

  switch (pilihan)
  {
  case 1:
  {
    int n, sum = 0;
    head();
    outMsg("Deret Bilangan Fibonacci Rekursif");
    outLine();
    outMsg("Masukkan jumlah bilangan dalam deret Fibonacci: ");
    validasiBil(&n);
    outMsg("Bilangan Fibonacci: ");

    for (int i = 0; i < n; i++)
    {
      int fib = fibonacciRekursif(i, &sum);
      printf("%d", fib);

      if (i < n - 1)
      {
        printf(", ");
      }
    }

    printf("\nJumlah dari deret Fibonacci adalah: %d \n", sum);
    break;
  }
  case 2:
  {
    int n, sum = 0;
    head();
    outMsg("Deret Bilangan Fibonacci Iteratif");
    outLine();
    outMsg("Masukkan jumlah bilangan dalam deret Fibonacci: ");
    validasiBil(&n);
    outMsg("Bilangan Fibonacci: ");

    for (int i = 0; i < n; i++)
    {
      int fib = fibonacciIteratif(i, &sum);
      printf("%d", fib);

      if (i < n - 1)
      {
        printf(", ");
      }
    }

    printf("\nJumlah dari deret Fibonacci adalah : %d \n", sum);
    break;
  }
  case 0:
    outLine();
    outMsg("Terima Kasih Sudah Menggunakan Program Ini :)");
    outLine();
    exit(0);
    break;
  default:
    statusMsg("ERROR: PERINTAH YANG ANDA PILIH TIDAK DITEMUKAN");
    pauseMsg();
    menuUtama();
    break;
  }
}
