#include "../../validasi/utility/utility.h"
char namaProgram[] = "PROGRAM STATISTIKA";

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

int main()
{
  startingScreen();
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
      pauseMsg();
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
