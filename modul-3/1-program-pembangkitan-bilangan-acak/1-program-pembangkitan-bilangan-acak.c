#include "../../validasi/utility/utility.h"
char namaProgram[] = "PROGRAM SORTING SEARCHING";

void bubbleSort(int arr[], int n);
int sequentialSearch(int arr[], int n, int x);
int binarySearch(int arr[], int low, int high, int x);
void menuUtama();

int main()
{
  startingScreen();
  menuUtama();
  endMsg();
}

// Fungsi untuk mengurutkan array
void bubbleSort(int arr[], int n)
{
  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < n - i - 1; j++)
      if (arr[j] > arr[j + 1])
      {
        // Tukar elemen jika tidak dalam urutan
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
}

// Fungsi untuk pencarian sequential
int sequentialSearch(int arr[], int n, int x)
{
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == x)
    {
      return i; // Mengembalikan indeks jika ditemukan
    }
  }
  return -1; // Mengembalikan -1 jika tidak ditemukan
}

// Fungsi untuk pencarian binary
int binarySearch(int arr[], int low, int high, int x)
{
  while (low <= high)
  {
    int mid = low + (high - low) / 2;

    if (arr[mid] == x)
    {
      return mid; // Mengembalikan indeks jika ditemukan
    }

    if (arr[mid] < x)
    {
      low = mid + 1; // Cari di setengah kanan
    }
    else
    {
      high = mid - 1; // Cari di setengah kiri
    }
  }

  return -1; // Mengembalikan -1 jika tidak ditemukan
}

void menuUtama()
{
  head();
  int n, x;
  outMsg("Pilih ukuran array (1000/16000/64000): ");
  scanf("%d", &n);

  if (n != 1000 && n != 16000 && n != 64000)
  {
    outMsg("Ukuran array yang dimasukkan tidak valid.");
    outMsg("Masukkan kembali ukuran array (1000/16000/64000)");
    scanf("%d", &n);
  }

  int arr[n];

  // Mengisi array dengan bilangan acak
  outMsg("Elemen array acak: ");
  for (int i = 0; i < n; i++)
  {
    arr[i] = rand() % 1000; // Angka acak antara 0 dan 999
    printf("%d ", arr[i]);
  }

  // Mengurutkan array untuk binary search
  bubbleSort(arr, n);
  printf("\n");
  outLine();
  outMsg("Masukkan elemen yang dicari: ");
  scanf("%d", &x);

  // Pencarian Sequential
  struct timeval startTimeSequential, endTimeSequential;
  gettimeofday(&startTimeSequential, NULL);
  int sequentialResult = sequentialSearch(arr, n, x);
  gettimeofday(&endTimeSequential, NULL);
  double sequentialTime = (endTimeSequential.tv_sec - startTimeSequential.tv_sec) +
                          (endTimeSequential.tv_usec - startTimeSequential.tv_usec) / 1e6;

  if (sequentialResult != -1)
  {
    outMsg("%d ditemukan pada indeks %d (Sequential Search)", x, sequentialResult);
    outMsg("Waktu yang dibutuhkan: %f detik", sequentialTime);
  }
  else
  {
    outMsg("%d tidak ditemukan (Sequential Search)", x);
  }

  // Pencarian Binary
  struct timeval startTimeBinary, endTimeBinary;
  gettimeofday(&startTimeBinary, NULL);
  int binaryResult = binarySearch(arr, 0, n - 1, x);
  gettimeofday(&endTimeBinary, NULL);
  double binaryTime = (endTimeBinary.tv_sec - startTimeBinary.tv_sec) +
                      (endTimeBinary.tv_usec - startTimeBinary.tv_usec) / 1e6;

  if (binaryResult != -1)
  {
    outMsg("%d ditemukan pada indeks %d (Binary Search)", x, binaryResult);
    outMsg("Waktu yang dibutuhkan: %f detik", binaryTime);
  }
  else
  {
    outMsg("%d tidak ditemukan (Binary Search)", x);
  }
  outLine();
  system("pause");
}