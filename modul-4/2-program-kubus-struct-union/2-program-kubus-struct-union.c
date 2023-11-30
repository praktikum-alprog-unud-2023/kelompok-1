#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>

struct KubusStruct
{
    int sisi;
    int luas;
    int volume;
};

union KubusUnion
{
    int sisi;
    int luas;
    int volume;
};

void hitungKubusStruct(struct KubusStruct *kubusStruct);
void hitungKubusUnion(union KubusUnion *kubusUnion);
void tampilkanHasil(struct KubusStruct *kubusStruct, union KubusUnion *kubusUnion);

// define function from ultility
#define BUFFER_SIZE 4096 // Konstanta untuk ukuran buffer

// ultility function
void endMsg();
void pauseMsg();
void inputThisInt(char *inputText, int *inputVariable);
void head();
void outLine();
void outMsg(const char *format, ...);
void leftAlignOutMsg(const char *format, ...);
void statusMsg(char *);
// Validasi input
int validateInputInteger(char *string, int *integer);

int main()
{
    system("cls");

    struct KubusStruct structKubus;
    union KubusUnion unionKubus;

    head();
    system("cls");
    outLine();
    outLine();
    outMsg("");
    int sisi;

    inputThisInt("Masukkan sisi kubus : ", &sisi);
    structKubus.sisi = sisi;
    unionKubus.sisi = sisi;
    hitungKubusStruct(&structKubus);
    hitungKubusUnion(&unionKubus);
    tampilkanHasil(&structKubus, &unionKubus);

    endMsg();
    return 0;
}

void hitungKubusStruct(struct KubusStruct *kubus)
{
    kubus->luas = 6 * kubus->sisi * kubus->sisi;
    kubus->volume = kubus->sisi * kubus->sisi * kubus->sisi;
}

void hitungKubusUnion(union KubusUnion *kubus)
{
    kubus->luas = 6 * kubus->sisi * kubus->sisi;
    kubus->volume = kubus->sisi * kubus->sisi * kubus->sisi;
}

void tampilkanHasil(struct KubusStruct *kubusStruct, union KubusUnion *kubusUnion)
{
    outLine();
    leftAlignOutMsg("Kubus dengan Struct");
    leftAlignOutMsg("Sisi           : %d", kubusStruct->sisi);
    leftAlignOutMsg("Luas Permukaan : %d", kubusStruct->luas);
    leftAlignOutMsg("Volume         : %d", kubusStruct->volume);
    outLine();
    leftAlignOutMsg("Kubus dengan Union");
    leftAlignOutMsg("Sisi           : %d", kubusStruct->sisi);
    leftAlignOutMsg("Luas Permukaan : %d", kubusStruct->luas);
    leftAlignOutMsg("Volume         : %d", kubusStruct->volume);
    outLine();
    leftAlignOutMsg("Ukuran memory pada kubus struct : %d", sizeof(*kubusStruct));
    leftAlignOutMsg("Ukuran memory pada kubus union  : %d", sizeof(*kubusUnion));
}

void endMsg() // prosedur menampilkan status
{
    int pilihan;
    outLine();
    outMsg("PROGRAM SELESAI");
    outMsg("< 1 > Ulangi            < 2 > Keluar");
    inputThisInt("Masukkan perintah : ", &pilihan);
    do
    {
        if (pilihan == 1)
        {
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

void head() // tampilan head pada program
{
    outMsg("");
    outLine();
    outLine();
    outMsg("PROGRAM LUAS DAN VOLUME KUBUS");
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
    pauseMsg();
}

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

void leftAlignOutMsg(const char *format, ...) // prosedur menampilkan pesan
{
    va_list args;
    va_start(args, format);

    char outputMessage[82];
    int outputLength = 82;

    vsnprintf(outputMessage, outputLength, format, args);

    va_end(args);

    const int inputLength = strlen(outputMessage);
    if (inputLength >= outputLength - 1)
    {
        outputMessage[outputLength - 1] = '\0'; // Truncate if needed
    }
    else
    {
        printf("| %-*s|\n", outputLength - 2, outputMessage);
    }
}

void statusMsg(char *inputText) // prosedur menampilkan status
{
    outLine();
    outMsg(inputText);
    outLine();
}

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
