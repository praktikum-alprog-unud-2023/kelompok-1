#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include <sys/time.h>

#define BUFFER_SIZE 4096

void endMsg();
void outLine();
void statusMsg(const char *inputText);
void pauseMsg();
void startingScreen();
void bubbleSort(int arr[], int n);
int sequentialSearch(int arr[], int n, int x) ;
int binarySearch(int arr[], int low, int high, int x);
void menuUtama();
void head();

int main() {
    startingScreen();
    menuUtama();
    endMsg();
}

void outLine()
{
  printf("|=================================================================================|\n");
}

void outMsg(const char *format, ...)
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
    numSpaces = 0;
  }

  char tempMessage[82];
  memset(tempMessage, ' ', numSpaces);
  strcpy(tempMessage + numSpaces, outputMessage);
  memset(tempMessage + numSpaces + inputLength, ' ', numSpaces);

  tempMessage[outputLength - 1] = '\0';
  printf("|%s|\n", tempMessage);
}

void statusMsg(const char *inputText)
{
  outLine();
  outMsg(inputText);
  outLine();
}

void pauseMsg()
{
  outMsg("Press enter to continue . . .");
  outLine();
  getchar();
  printf("\n");
}

void head(){
  system("cls");
  outLine();
  outMsg("");
  outMsg("PROGRAM BILANGAN ACAK");
  outMsg("");
  outLine();
  
}
void startingScreen()
{
  outLine();
  outMsg("PROGRAM BILANGAN ACAK");
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
  outMsg("PROGRAM STUDI TEKNOLOGI INFORMASI");
  outMsg("FAKULTAS TEKNIK UNIVERSITAS UDAYANA");
  outLine();
  system("pause");
}

// Fungsi untuk mengurutkan array
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1]) {
                // Tukar elemen jika tidak dalam urutan
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
}

// Fungsi untuk pencarian sequential
int sequentialSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i; // Mengembalikan indeks jika ditemukan
        }
    }
    return -1; // Mengembalikan -1 jika tidak ditemukan
}

// Fungsi untuk pencarian binary
int binarySearch(int arr[], int low, int high, int x) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == x) {
            return mid; // Mengembalikan indeks jika ditemukan
        }
        
        if (arr[mid] < x) {
            low = mid + 1; // Cari di setengah kanan
        } else {
            high = mid - 1; // Cari di setengah kiri
        }
    }
    
    return -1; // Mengembalikan -1 jika tidak ditemukan
}

void menuUtama(){
  head();
      int n, x;
    outMsg("Pilih ukuran array (1000/16000/64000): ");
    scanf("%d", &n);

    if (n != 1000 && n != 16000 && n != 64000) {
        outMsg("Ukuran array yang dimasukkan tidak valid.");
        outMsg("Masukkan kembali ukuran array (1000/16000/64000)");
        scanf("%d", &n);
    }

    int arr[n];

    // Mengisi array dengan bilangan acak
outMsg("Elemen array acak: ");
for (int i = 0; i < n; i++) {
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

    if (sequentialResult != -1) {
        outMsg("%d ditemukan pada indeks %d (Sequential Search)", x, sequentialResult);
        outMsg("Waktu yang dibutuhkan: %f detik", sequentialTime);
    } else {
        outMsg("%d tidak ditemukan (Sequential Search)", x);
    }

    // Pencarian Binary
struct timeval startTimeBinary, endTimeBinary;
    gettimeofday(&startTimeBinary, NULL);
    int binaryResult = binarySearch(arr, 0, n-1, x);
    gettimeofday(&endTimeBinary, NULL);
    double binaryTime = (endTimeBinary.tv_sec - startTimeBinary.tv_sec) +
                        (endTimeBinary.tv_usec - startTimeBinary.tv_usec) / 1e6;

    if (binaryResult != -1) {
        outMsg("%d ditemukan pada indeks %d (Binary Search)", x, binaryResult);
        outMsg("Waktu yang dibutuhkan: %f detik", binaryTime);
    } else {
        outMsg("%d tidak ditemukan (Binary Search)", x);
    }
    outLine();
    system("pause");
}

void endMsg()
{
  head();
int pilihan;

  outMsg("PROGRAM SELESAI");
  outLine();
  outMsg("Apakah Anda Ingin Mengulang Program?");
  outMsg("< 1 > Ulangi            < 2 > Keluar");
  outLine();
  scanf("%d", &pilihan);
  do
  {
    if (pilihan == 1)
    {
      menuUtama();
    }
    else if (pilihan == 2)
    {
      system("cls");
      outLine();
      outMsg("TERIMA KASIH SUDAH MENGGUNAKAN PROGRAM INI!");
      outLine();
      exit(0);
    }
    else
    {
      statusMsg("ERROR: PERINTAH YANG ANDA PILIH TIDAK DITEMUKAN");
    scanf("%d", &pilihan);
    }
  } while (pilihan != 1 && pilihan != 2);
}
