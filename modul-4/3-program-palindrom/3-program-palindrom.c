#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <stdbool.h>
#define MAX_WORD_LENGTH 100
#define BUFFER_SIZE 100
int validasiInputInteger(char *string, int *integer);
void ulangProgram();
void startingScreen();
void head();
void outLine();
void outMsg(const char *format, ...);
void statusMsg(char *);
int inputPalindrome();
void inputInteger(char *message, int *integer);
void tampilkanBolakBalik(char *kata);

// untuk input buffer biar gk ngebug;
void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

// fungsi main
int main()
{
    startingScreen();
    inputPalindrome();
    clearInputBuffer();
    system("pause");
    ulangProgram();
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

    outLine();
    outMsg("PROGRAM PALINDROM");
    outLine();
    statusMsg("Masukan Kata");
}

// tampilan program
void startingScreen() // tampilan pada program
{

    outLine();
    outMsg("");
    outMsg("PROGRAM PALINDROM");
    outMsg("");
    outLine();
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
    system("pause");
    system("cls");
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
// validasi
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

        if (validasiInputInteger(buffer, inputVariable) == 0)
        {
            statusMsg("ERROR: ANDA TIDAK MEMASUKKAN NOMOR PERINTAH");
        }

        if (*inputVariable <= 0)
        {
            statusMsg("ERROR: INPUT TIDAK VALID");
        }
    } while (validasiInputInteger(buffer, inputVariable) == 0 || *inputVariable <= 0);
}

// Struktur untuk menyimpan informasi setiap huruf
typedef struct
{
    char character;
    int count;
    int kataPertama;
} Isi;

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