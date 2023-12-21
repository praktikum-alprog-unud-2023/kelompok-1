#include "../../validasi/utility/utility.h"

char namaProgram[] = "PROGRAM MENARA HANOI";

int pilihan;

void hanoiRekursif(int n, char tiang_sumber, char tiang_tujuan, char tiang_bantu);
void hanoiIteratif(int n);
int hitungLangkahMinimum(int n);

int hitungLangkahMinimum(int n)
{
    return (int)(pow(2, n) - 1);
}

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
    outMsg("1. Rekursif");
    outMsg("2. Iteratif");
    outLine();
    inputThisInt("Masukkan pilihan anda : ", &menu);

    if (menu == 1)
    {
        head();
        outMsg("Metode rekursif");
        outLine();
        inputThisInt("Masukkan jumlah cakram : ", &jumlah_cakram);

        int langkah_minimum = hitungLangkahMinimum(jumlah_cakram);
        printf("Jumlah langkah minimum : %d\n", langkah_minimum);

        printf("Langkah penyelesaian : \n");
        hanoiRekursif(jumlah_cakram, 'A', 'C', 'B');
        outLine();
        getchar();
        endMsg();
    }
    else if (menu == 2)
    {
        head();
        outMsg("Metode iteratif");
        outLine();
        inputThisInt("Masukkan jumlah cakram : ", &jumlah_cakram);

        int langkah_minimum = hitungLangkahMinimum(jumlah_cakram);
        printf("Jumlah langkah minimum : %d\n", langkah_minimum);

        printf("Langkah penyelesaian : \n");
        hanoiIteratif(jumlah_cakram);
        outLine();
        getchar();
        endMsg();
    }
    else
    {
        outMsg("Input tidak sesuai");
        getchar();
        outLine();
        main();
    }

    return 0;
}
