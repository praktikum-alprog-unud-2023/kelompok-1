#include "../../validasi/utility/utility.h"
#include <time.h>

// Konstanta untuk looping opembuatan sampel percobaan
#define SAMPLE_SIZE 100

char namaProgram[] = "PROGAM PEMBANGKITAN BILANGAN ACAK";

// Deklarasi record timer
typedef struct
{
  clock_t startTime;
  clock_t endTime;
} Timer;
Timer timer[SAMPLE_SIZE];

// Prosedur untuk mereset timer
void resetTimer()
{
  for (int i = 0; i < SAMPLE_SIZE; i++)
  {
    timer[i].startTime = 0;
    timer[i].endTime = 0;
  }
}

// Fungsi untuk menghitung waktu berlalu
double elapsedTime()
{
  double elapsedTime;
  for (int i = 0; i < SAMPLE_SIZE; i++)
  {
    elapsedTime += ((double)(timer[i].endTime - timer[i].startTime)) / CLOCKS_PER_SEC;
  }
  return elapsedTime / SAMPLE_SIZE;
}

// Fungsi untuk pengisian ukuran array
int arraySize()
{
  head();

  int arraySize;

  outMsg("Jumlah Bilangan yang Dibangkitkan");
  outMsg("<1>            1000");
  outMsg("<2>           16000");
  outMsg("<3>           64000");
  inputThisInt("Masukkan Perintah : ", &pilihan);

  if (pilihan == 1)
  {
    arraySize = 1000;
  }
  else if (pilihan == 2)
  {
    arraySize = 16000;
  }
  else if (pilihan == 3)
  {
    arraySize = 64000;
  }
  else
  {
    statusMsg("ERROR: PERINTAH YANG ANDA MASUKKAN TIDAK DITEMUKAN");
  }

  return arraySize;
}

// Fungsi untuk pengisian nilai maksimal
int maxValue()
{
  head();

  int value;

  outMsg("Masukkan Batas Maksimal Nilai Bilangan yang Dibangkitkan");
  outLine();
  outMsg("Deskripsi");
  outMsg("Bilangan yang dibangkitkan akan berupa bilangan acak dari");
  outMsg("            1            hingga     <Batas Maksimal>     ");
  outLine();
  inputThisInt("Masukkan Batas Maksimal : ", &value);

  return value;
}

// Prosedur menampilkan isi array
void printArray(int *array, int size)
{
  outMsg("Array");
  outLine();
  for (int i = 0; i < size; i++)
  {
    printf("|                     ");
    txtBox("Bilangan ke-%d", 23, 'R', i + 1);
    txtBox("=", 4, 'C');
    txtBox("%d ", 12, 'R', array[i]);
    printf("                     |");
    printf("\n");
  }
  outLine();
}

//
void copyArray(int *array, int *newArray, int size)
{
  for (int i = 0; i < size; i++)
  {
    newArray[i] = array[i];
  }
}

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Prosedur mengurutkan dengan insertion sort
void insertionSort(int *array, int size)
{
  int i, key, j;
  for (i = 1; i < size; i++)
  {
    key = array[i];
    j = i - 1;

    // Memindahkan elemen yang lebih besar dari key ke posisi satu tingkat di atasnya
    while (j >= 0 && array[j] > key)
    {
      swap(&array[j + 1], &array[j]);
      j = j - 1;
    }
    array[j + 1] = key;
  }
}

// Prosedur mengurutkan dengan Bubble sort
void bubbleSort(int *array, int size)
{
  for (int i = 0; i < size - 1; i++)
  {
    for (int j = 0; j < size - i - 1; j++)
    {

      // Menukar elemen jika elemen sekarang lebih besar dari elemen berikutnya
      if (array[j] > array[j + 1])
      {
        swap(&array[j], &array[j + 1]);
      }
    }
  }
}

// Fungsi partisi untuk quick sort
int partition(int *array, int low, int high)
{
  int pivot = array[high];
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++)
  {
    if (array[j] < pivot)
    {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

// Prosedur mengurutkan dengan quick sort
void quickSort(int *array, int low, int high)
{
  if (low < high)
  {
    int pi = partition(array, low, high);

    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}

void sorting(int *array, int size)
{
  double averageTime[3];
  int *sampleArray = malloc(size * sizeof(int));

  resetTimer();
  for (int i = 0; i < SAMPLE_SIZE; i++)
  {
    copyArray(array, sampleArray, size);
    timer[i].startTime = clock();
    insertionSort(sampleArray, size);
    timer[i].endTime = clock();
  }
  averageTime[0] = elapsedTime();

  resetTimer();
  for (int i = 0; i < SAMPLE_SIZE; i++)
  {
    copyArray(array, sampleArray, size);
    timer[i].startTime = clock();
    bubbleSort(sampleArray, size);
    timer[i].endTime = clock();
  }
  averageTime[1] = elapsedTime();

  resetTimer();
  for (int i = 0; i < SAMPLE_SIZE; i++)
  {
    copyArray(array, sampleArray, size);
    timer[i].startTime = clock();
    quickSort(sampleArray, 0, size - 1);
    timer[i].endTime = clock();
  }
  averageTime[2] = elapsedTime();

  head();
  outMsg("ARRAY TERURUT");
  outLine();
  quickSort(array, 0, size - 1);
  printArray(array, size);
  outLine();
  outLine();
  outMsg("Waktu yang dibutuhkan oleh Insertion Sort : %lf detik", averageTime[0]);
  outMsg("Waktu yang dibutuhkan oleh Bubble Sort : %lf detik", averageTime[1]);
  outMsg("Waktu yang dibutuhkan oleh Quick Sort : %lf detik", averageTime[2]);
  outLine();
}

// Fungsi untuk pencarian sequential
int sequentialSearch(int *array, int size, int target)
{
  for (int i = 0; i < size; i++)
  {
    if (array[i] == target)
    {
      return i; // Mengembalikan indeks jika ditemukan
    }
  }
  return -1; // Mengembalikan -1 jika tidak ditemukan
}

// Fungsi untuk pencarian binary
int binarySearch(int *array, int low, int high, int target)
{
  while (low <= high)
  {
    int mid = low + (high - low) / 2;

    if (array[mid] == target)
    {
      return mid; // Mengembalikan indeks jika ditemukan
    }

    if (array[mid] < target)
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

void searching(int *array, int size)
{
  double averageTime[2];
  int target;
  int targetIndexSequentialSearch;
  int targetIndexBinarySearch;

  quickSort(array, 0, size - 1);

  head();
  outMsg("OPERASI PENCARIAN BILANGAN");
  outLine();
  inputThisInt("Masukkan nilai bilangan yang ingin dicari : ", &target);

  resetTimer();
  for (int i = 0; i < SAMPLE_SIZE; i++)
  {
    timer[i].startTime = clock();
    targetIndexSequentialSearch = sequentialSearch(array, size, target);
    timer[i].endTime = clock();
  }
  averageTime[0] = elapsedTime();

  resetTimer();
  for (int i = 0; i < SAMPLE_SIZE; i++)
  {
    timer[i].startTime = clock();
    targetIndexBinarySearch = binarySearch(array, 0, size - 1, target);
    timer[i].endTime = clock();
  }
  averageTime[1] = elapsedTime();

  if (targetIndexSequentialSearch != -1 && targetIndexBinarySearch != -1)
  {
    outMsg("Array Terurut");
    outLine();
    printArray(array, size);
    outLine();
    outMsg("%d ditemukan pada indeks %d (Sequential Search)", target, targetIndexSequentialSearch + 1);
    outMsg("%d ditemukan pada indeks %d (Binary Search)", target, targetIndexBinarySearch + 1);
    outLine();
    outMsg("Waktu yang dibutuhkan oleh Sequential Search : %lf detik", averageTime[0]);
    outMsg("Waktu yang dibutuhkan oleh Binary Search : %lf detik", averageTime[1]);
    outLine();
  }
  else
  {
    outLine();
    outMsg("%d tidak ditemukan", target);
    outLine();
  }
}

// Prosedur untuk pemilihan operasi
void menuOperator(int *array, int size)
{
  outMsg("Pilih Operasi yang Ingin Dilakukan");
  outMsg("<1>         Sorting");
  outMsg("<2>       Searching");
  inputThisInt("Masukkan Perintah : ", &pilihan);

  do
  {
    if (pilihan == 1)
    {
      sorting(array, size);
    }
    else if (pilihan == 2)
    {
      searching(array, size);
    }
    else
    {
      statusMsg("ERROR: PERINTAH YANG ANDA MASUKKAN TIDAK DITEMUKAN");
      pilihan = 0;
    }
  } while (pilihan == 0);
}

void menuUtama()
{

  // Mengalokasikan ukuran array
  int size = arraySize();
  int *array = malloc(size * sizeof(int));

  if (array == NULL)
  {
    statusMsg("ERROR: ALLOKASI MEMORI GAGAL");
    exit(EXIT_FAILURE);
  }

  // Mengisi array dengan angka acak
  int max = maxValue();
  for (int i = 0; i < size; i++)
  {
    array[i] = rand() % max + 1; // Menghasilkan angka acak antara 1 dan 100
  }

  head();
  printArray(array, size);

  menuOperator(array, size);

  endMsg();
  free(array);
}

int main()
{
  startingScreen();
  menuUtama();
  return 0;
}