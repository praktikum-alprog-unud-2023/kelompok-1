#include "../../validasi/utility/utility.h"
#include <time.h>

void startingScreen();
void head();
void outLine();
void endMsg();

// Fungsi validasi
int validasi()
{
  int pilihan, ukuran;
  char enter;

  if (scanf("%d%c", &pilihan, &enter) != 2 || pilihan < 0 || pilihan > 3 || enter != '\n')
  {
    fflush(stdin);
    printf("Input Tidak Valid. Silahkan memilih antara 1-3 : ");
    return validasi();
  }
  else
  {
    switch (pilihan)
    {
    case 1:
      ukuran = 1000;
      break;
    case 2:
      ukuran = 16000;
      break;
    case 3:
      ukuran = 64000;
      break;
    case 0:
      exit(0);

    default:
      printf("\n");
      break;
    }
    return ukuran;
  }
}
// Fungsi untuk menghasilkan angka acak antara 1 dan 10000
int angkaAcak(int banyak_angka)
{
  return rand() % banyak_angka + 1;
}

// Fungsi Bubble Sort
void bubbleSort(int arr[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        // Swap
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

void bubbleSortPointer(int *arr, int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        // Swap menggunakan pointer
        int temp = *(arr + j);
        *(arr + j) = *(arr + j + 1);
        *(arr + j + 1) = temp;
      }
    }
  }
}

int main()
{
  int ukuran;

  startingScreen();
  head();
  outLine();
  outMsg("Silahkan memilih banyak angka yang ingin di urutkan");
  outMsg("1. Mengurutkan 1000 bilangan acak");
  outMsg("2. Mengurutkan 16000 bilangan acak");
  outMsg("3. Mengurutkan 64000 bilangan acak");
  outMsg("0. Selesai Program");
  outLine();
  outMsg("Silahkan Input Angka : ");
  ukuran = validasi();

  const int size = ukuran;
  int arr[size];
  srand(time(NULL));

  // Inisialisasi array dengan data acak
  for (int i = 0; i < size; i++)
  {
    arr[i] = angkaAcak(ukuran);
  }

  // Cetak array sebelum diurutkan
  printf("Array sebelum diurutkan:\n");
  for (int i = 0; i < size; i++)
  {
    printf("Index ke [%d] = %d\n", i, arr[i]);
  }
  printf("\n");
  outLine();
  getchar();

  // Panggil fungsi Bubble Sort
  bubbleSort(arr, size);

  // Cetak array setelah diurutkan
  printf("Array setelah diurutkan:\n");
  outLine();
  for (int i = 0; i < size; i++)
  {
    printf("Index ke [%d] = %d\n", i, arr[i]);
  }
  printf("\n");

  // Catat waktu sebelum pengurutan
  clock_t start_time = clock();

  // Panggil fungsi Bubble Sort
  bubbleSort(arr, size);

  // Catat waktu setelah pengurutan
  clock_t end_time = clock();

  // Hitung waktu yang dibutuhkan untuk pengurutan dalam detik
  double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

  // Catat waktu sebelum pengurutan
  clock_t start_time1 = clock();

  // Panggil fungsi Bubble Sort Pointer
  bubbleSortPointer(arr, size);

  // Catat waktu setelah pengurutan
  clock_t end_time1 = clock();

  // Hitung waktu yang dibutuhkan untuk pengurutan dalam detik
  double elapsed_time1 = ((double)(end_time1 - start_time1)) / CLOCKS_PER_SEC;

  outLine();
  printf("Waktu yang dibutuhkan untuk Bubble Sort (size %d) : %f detik\n", size, elapsed_time);
  outLine();
  printf("waktu yang dibutuhkan bubble Sort Pointer (size%d) : %f detik\n", size, elapsed_time1);
  outLine();

  if (elapsed_time > elapsed_time1)
  {
    printf("Waktu dari penggunaan Bubble Sort Pointer lebih cepat.\n");
  }
  else
  {
    printf("Waktu dari penggunaan Bubble Sort lebih cepat.\n");
  }

  endMsg();
  return 0;
}
