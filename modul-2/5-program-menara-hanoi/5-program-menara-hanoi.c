#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include <math.h>

// Konstanta untuk ukuran buffer
#define BUFFER_SIZE 4096

// Deklarasi variabel global
int pilihan;

void endMsg();
void inputThisInt(char *inputText, int *inputVariable);
void inputThisDouble(char *inputText, double *inputVariable);
void startingScreen();
void head();
void outLine();
void outMsg(const char *format, ...);
void statusMsg(char *);
void pauseMsg();

// Validasi input
int validateInputInteger(char *string, int *integer);
int validateInputDouble(char *string, double *floating_point);
void input_binary_str(char *input_param);
void hanoiRekursif(int n, char tiang_sumber, char tiang_tujuan, char tiang_bantu);

/*=================================================================================
  Tampilan Ketika Program Pertama Kali Dibuka
  Prosedur Pelengkap:
      outline();
      outMsg(pesan);
      pauseMsg();
  =================================================================================
*/
void startingScreen()
{
    system("cls");
    outLine();
    outLine();
    outMsg("");
    outMsg("PROGRAM MENARA HANOI");
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
    outMsg("");
    outMsg("");
    outMsg("");
    pauseMsg();
}

/*=================================================================================
  Tampilan Judul Program (Isi di Setiap Bagian Program)
  =================================================================================
*/
void head() // tampilan head pada program
{
    system("cls");
    outLine();
    outMsg("Program Menara Hanoi");
    outLine();
}

void outLine() // prosedur menampilkan garis
{
    printf("|=================================================================================|\n");
}

/*=================================================================================
  Prosedur Untuk mencetak Teks Dengan Posisi Otomatis Center
  Library:
      #include <stdio.h>
      #include <stdarg.h>
      #include <string.h>
  =================================================================================
*/
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

/*=================================================================================
  Prosedur Untuk Mencetak Pesan Kesalahan
  Prosedur Pelengkap:
      outMsg("pesan");
  =================================================================================
*/
void statusMsg(char *inputText) // prosedur menampilkan status
{
    outLine();
    outMsg(inputText);
    outLine();
}

/*=================================================================================
  Prosedur Untuk Menampilkan Konfirmasi Apakah User Ingin Mengulang Program
  Prosedur Pelengkap:
      outline();
      outMsg("pesan");
      inputThisInt("teks", &variabel);
  Library:
      #include <stdio.h>
      #include <stdlib.h>
  =================================================================================
*/
void endMsg() // prosedur menampilkan status
{
    outLine();
    outMsg("PROGRAM SELESAI");
    outMsg("< 1 > Ulangi            < 2 > Keluar");
    inputThisInt("Masukkan perintah : ", &pilihan);
    do
    {
        if (pilihan == 1)
        {
            // arahkan program kembali ke menu utama
            main();
        }
        else if (pilihan == 2)
        {
            // keluar dari program
            exit(0);
            break;
        }

        statusMsg("ERROR: PERINTAH YANG ANDA PILIH TIDAK DITEMUKAN");
        endMsg();
    } while (pilihan != 1 || pilihan != 2);
}

void pauseMsg()
{
    outMsg("Press enter to continue . . .");
    getchar();
    printf("\n");
}

/*=================================================================================
  Fungsi Untuk Memvalidasi Input Bilangan Bulat
  Library:
      #include <ctype.h>
      #include <string.h>
      #include <stdlib.h>
  =================================================================================
*/
int validateInputInteger(char *string, int *integer)
{
    int i = 0;

    while (isspace(string[i]))
        i++;

    int length = strlen(string);

    if (length == i)
        return 0;

    char integer_buffer[BUFFER_SIZE];
    int integer_chars = 0;

    // in the case of a negative integer, the first char may be - symbol
    if (string[i] == '-')
    {

        integer_buffer[integer_chars] = '-';
        integer_chars++;
        i++;

        if (!isdigit(string[i]))
            return 0;
    }

    while (i < length && !isspace(string[i]))
    {
        if (!isdigit(string[i]))
            return 0;

        integer_buffer[integer_chars] = string[i];
        integer_chars++;
        i++;
    }

    // put a null terminator onto the end of the buffer to make it a proper string
    integer_buffer[integer_chars] = '\0';

    // loop through any trailing whitespace characters
    while (isspace(string[i]))
        i++;

    if (string[i] != '\0')
        return 0;

    *integer = atoi(integer_buffer);

    return 1;
}

/*=================================================================================
  Fungsi Untuk Memvalidasi Input Bilangan Desimal
  Library:
      #include <ctype.h>
      #include <string.h>
      #include <stdlib.h>
  =================================================================================
*/
int validateInputDouble(char *string, double *floating_point)
{
    int i = 0;

    while (isspace(string[i]))
        i++;

    int length = strlen(string);

    if (length == i)
        return 0;

    char double_buffer[BUFFER_SIZE];
    int double_chars = 0;
    int hasDecimal = 0; // To keep track of whether a decimal point has been encountered.

    // In the case of a negative double, the first character may be a '-' symbol
    if (string[i] == '-')
    {
        double_buffer[double_chars] = '-';
        double_chars++;
        i++;
    }

    while (i < length && !isspace(string[i]))
    {
        if (isdigit(string[i]))
        {
            double_buffer[double_chars] = string[i];
            double_chars++;
            i++;
        }
        else if (string[i] == '.' && !hasDecimal)
        {
            double_buffer[double_chars] = string[i];
            double_chars++;
            hasDecimal = 1; // Set the flag to indicate a decimal point has been encountered.
            i++;
        }
        else
        {
            return 0; // Invalid character for a double
        }
    }

    // Put a null terminator at the end of the buffer to make it a proper string
    double_buffer[double_chars] = '\0';

    // Loop through any trailing whitespace characters
    while (isspace(string[i]))
        i++;

    if (string[i] != '\0')
        return 0;

    // Use atof to convert the double_buffer string to a double
    *floating_point = atof(double_buffer);

    return 1;
}

/*=================================================================================
  Fungsi Untuk Menginputkan Bilangan Bulat dan Memvalidasinya
  Fungsi Pelengkap:
      validateInputInteger(param1, param2)
      statusMsg("pesan");
  Library:
      #include <stdio.h>
      #include <stdlib.h>
  =================================================================================
*/
void inputThisInt(char *inputText, int *inputVariable)
{
    int parsed_correct = 1;
    char buffer[BUFFER_SIZE];
    do
    {
        // input
        if (inputText != NULL)
        {
            printf(">>>>>>>>>>>>>>>>>>>>>>>    %s", inputText);
        }

        // accept a line of string input from the user, store it into buffer

        fgets(buffer, BUFFER_SIZE, stdin);

        if (validateInputInteger(buffer, inputVariable) == 0)
        {
            statusMsg("ERROR: ANDA TIDAK MEMASUKKAN NOMOR PERINTAH");
        }

        if (*inputVariable <= 0)
        {
            statusMsg("ERROR: BILANGAN YANG DIMASUKKAN BUKAN BILANGAN POSITIF");
        }
    } while (validateInputInteger(buffer, inputVariable) == 0 || *inputVariable < 0);
}

/*=================================================================================
  Fungsi Untuk Menginputkan Bilangan Desimal dan Memvalidasinya
  Fungsi Pelengkap:
      validateInputDouble(param1, param2)
      statusMsg("pesan");
  Library:
      #include <stdio.h>
      #include <stdlib.h>
  =================================================================================
*/
void inputThisDouble(char *inputText, double *inputVariable)
{
    int parsed_correct = 1;
    char buffer[BUFFER_SIZE];
    do
    {
        // input
        if (inputText != NULL)
        {
            printf(">>>>>>>>>>>>>>>>>>>>>>>    %s", inputText);
        }

        // accept a line of string input from the user, store it into buffer

        fgets(buffer, BUFFER_SIZE, stdin);

        if (validateInputDouble(buffer, inputVariable) == 0)
        {
            statusMsg("ERROR: ANDA TIDAK MEMASUKKAN ANGKA");
            pauseMsg();
        }
        if (*inputVariable <= 0)
        {
            statusMsg("ERROR: BILANGAN YANG DIMASUKKAN BUKAN BILANGAN POSITIF");
            pauseMsg();
        }
    } while (validateInputDouble(buffer, inputVariable) == 0 || *inputVariable < 0);
}

/*=================================================================================
  Fungsi Untuk Menginputkan Bilangan Biner dan Memvalidasinya
  Variabel yang digunakan dalam parameter misalnya:
      char inputBinaryNumber[100];
  Cara memanggil:
      input_binary_str(inputBinaryNumber);
      printf("%s\n", inputBinaryNumber);
  =================================================================================
*/
void input_binary_str(char *input_param)
{
    char input[100];
    int i = 0, error = 0;

    fflush(stdin);
    fgets(input, sizeof(input), stdin);

    if (input[0] == '\0')
        error = 1;

    while (input[i] != '\0' && input[i] != '\n')
    {
        if (strchr("01", input[i]))
        {
            i++;
        }
        else
        {
            error = 1;
            break;
        }
    }

    if (error == 1)
    {
        printf("\nInvalid binary number!");
        printf("\nSilahkan Masukan Angka Kembali : ");
        return input_binary_str(input_param);
    }
    input[i] = '\0';
    strcpy(input_param, input);
}
#include <stdio.h>
#include <math.h>

// Fungsi untuk menghitung jumlah langkah minimum
int hitungLangkahMinimum(int n)
{
    return (int)(pow(2, n) - 1);
}

// Fungsi untuk menyelesaikan masalah Menara Hanoi secara iteratif
void hanoiIteratif(int n)
{
    int totalLangkah = hitungLangkahMinimum(n);
    char tiang_sumber = 'A';
    char tiang_tujuan = 'C';
    char tiang_bantu = 'B';

    if (n % 2 == 0)
    {
        char sumber = tiang_tujuan;
        tiang_tujuan = tiang_bantu;
        tiang_bantu = sumber;
    }

    for (int langkah = 1; langkah <= totalLangkah; langkah++)
    {
        if (langkah % 3 == 1)
        {
            printf("Pindahkan cakram %d dari %c ke %c\n", langkah % 3, tiang_sumber, tiang_tujuan);
        }
        else if (langkah % 3 == 2)
        {
            printf("Pindahkan cakram %d dari %c ke %c\n", langkah % 3, tiang_sumber, tiang_bantu);
        }
        else if (langkah % 3 == 0)
        {
            printf("Pindahkan cakram %d dari %c ke %c\n", langkah % 3, tiang_bantu, tiang_tujuan);
        }
    }
}

int main()
{
    int n, validinput = 0, menu, jumlah_cakram;
    startingScreen();
    head();
    outMsg("pilihan program");

    outLine();
    outMsg("1.Rekursif");
    outMsg("2.Iteratif");
    outLine();
    inputThisInt("masukkan pilihan anda : ", &menu);

    if (menu == 1)
    {
        head();
        outMsg("metode rekursif");
        outLine();
        inputThisInt("masukkan jumlah cakram : ", &jumlah_cakram);

        int langkah_minimum = hitungLangkahMinimum(jumlah_cakram);
        printf("Jumlah langkah minimum : %d\n", langkah_minimum);

        printf("Langkah penyelesaian : \n");
        hanoiRekursif(jumlah_cakram, 'A', 'C', 'B');
        endMsg();
    }
    else if (menu == 2)
    {
        head();
        outMsg("metode iteratif");
        outLine();
        inputThisInt("masukkan jumlah cakram : ", &jumlah_cakram);

        int langkah_minimum = hitungLangkahMinimum(jumlah_cakram);
        printf("Jumlah langkah minimum : %d\n", langkah_minimum);

        printf("Langkah penyelesaian : \n");
        hanoiIteratif(jumlah_cakram);
        endMsg();
    }
    else
    {
        outMsg("input tidak sesuai");
        main();
    }

    return 0;
}
// Fungsi rekursif untuk menyelesaikan masalah Menara Hanoi
void hanoiRekursif(int n, char tiang_sumber, char tiang_tujuan, char tiang_bantu)
{
    if (n == 1)
    {
        printf("Pindahkan cakram 1 dari %c ke %c\n", tiang_sumber, tiang_tujuan);
        return;
    }
    hanoiRekursif(n - 1, tiang_sumber, tiang_bantu, tiang_tujuan);
    printf("Pindahkan cakram %d dari %c ke %c\n", n, tiang_sumber, tiang_tujuan);
    hanoiRekursif(n - 1, tiang_bantu, tiang_tujuan, tiang_sumber);
}
