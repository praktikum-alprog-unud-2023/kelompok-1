#include "../../validasi/utility/utility.h"

char namaProgram[] = "PROGRAM PALINDROM";

#define MAX_WORD_LENGTH 100

// Struktur untuk menyimpan informasi setiap huruf
typedef struct
{
    char character;
    int count;
    int kataPertama;
} Isi;

int inputPalindrome();
void inputThisInt(char *message, int *integer);
void tampilkanBolakBalik(char *kata);

int main()
{
    startingScreen();
    inputPalindrome();
    clearInputBuffer();
    system("pause");
    endMsg();
}

void tampilkanBolakBalik(char *kata)
{
    int panjang = strlen(kata);

    outLine();
    printf("Kata Asli : %s", kata);
    printf("\nkata dibalik : ");

    for (int i = panjang - 1; i >= 0; i--)
    {
        printf("%c", kata[i]);
    }

    printf("\n");
}

// Fungsi untuk menentukan apakah sebuah kata merupakan palindrom atau bukan
int palindromee(char kataUtama[])
{
    int left = 0;
    int right = strlen(kataUtama) - 1;

    while (right > left)
    {
        if (kataUtama[left++] != kataUtama[right--])
        {
            return 0; // Bukan palindrom
        }
    }

    return 1; // Palindrom
}

// Fungsi untuk membandingkan huruf berdasarkan urutan pertama kali muncul
int kompirasi(const void *a, const void *b)
{
    Isi *isiA = (Isi *)a;
    Isi *isiB = (Isi *)b;

    // Urutkan berdasarkan urutan pertama kali muncul
    return isiA->kataPertama - isiB->kataPertama;
}
bool validasiHuruf(const char *str)
{
    while (*str)
    {

        if (!(*str >= 'A' && *str <= 'Z' || *str >= 'a' && *str <= 'z'))
        {
            return true;
        }
        str++;
    } // Selain kondisi yang di atas maka inputan salah
    return false;
}

int inputPalindrome()
{
    char kataUtama[MAX_WORD_LENGTH];

    // Meminta input kata dari pengguna
    head();
    do
    {

        printf(">>>   Masukkan kata: ");
        scanf("%s", kataUtama);

        if (validasiHuruf(kataUtama))
        {
            statusMsg("Input tidak valid.");
        }
        else
        {
            break;
        }

    } while (1);

    // Menentukan banyak huruf dalam kata
    int panjangKata = strlen(kataUtama);

    // Menentukan apakah kata merupakan palindrom atau bukan
    int P = palindromee(kataUtama);

    // Membuat array Isi untuk setiap huruf
    Isi huruf[MAX_WORD_LENGTH];
    int A = 0;

    // Inisialisasi setiap huruf dalam array huruf
    for (int i = 0; i < panjangKata; i++)
    {
        char hurufSekarang = tolower(kataUtama[i]);

        // Mengecek apakah huruf sudah tercatat sebelumnya
        int j;
        for (j = 0; j < A; j++)
        {
            if (huruf[j].character == hurufSekarang)
            {
                huruf[j].count++;
                break;
            }
        }

        // Jika huruf belum tercatat, tambahkan ke array huruf
        if (j == A)
        {
            huruf[A].character = hurufSekarang;
            huruf[A].count = 1;
            huruf[A].kataPertama = i;
            A++;
        }
    }

    // Sorting huruf berdasarkan urutan pertama kali muncul
    qsort(huruf, A, sizeof(Isi), kompirasi);

    // Menampilkan output sesuai dengan format yang diinginkan
    tampilkanBolakBalik(kataUtama);
    printf("%s(%d) : ", kataUtama, panjangKata);

    for (int i = 0; i < A; i++)
    {
        printf("%c=%d ", huruf[i].character, huruf[i].count);
    }

    printf(": %s\n", P ? "Palindrom" : "Bukan Palindrom");

    statusMsg("Data dimasukan ke kamuskata.txt");

    // buat dan buka file
    FILE *file = fopen("kamuskata.txt", "a");
    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    // Print output
    fprintf(file, "%s(%d) : ", kataUtama, panjangKata);

    for (int i = 0; i < A; i++)
    {
        fprintf(file, "%c=%d ", huruf[i].character, huruf[i].count);
    }

    fprintf(file, ": %s\n", P ? "Palindrom" : "Bukan Palindrom");

    // menutup file
    fclose(file);

    return 0;
}