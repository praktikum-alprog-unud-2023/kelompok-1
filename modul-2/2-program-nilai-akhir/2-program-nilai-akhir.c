#include "../../validasi/utility/utility.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

void startingScreen();
void head();
void outLine();
void endMsg();

float input(float min, float max)
{
    float select;
    char enter;
    if (scanf("%f%c", &select, &enter) != 2 || enter != '\n' || select < min || select > max)
    {
        fflush(stdin);
        printf("Inputan salah, Masukan Bilangan Bulat Positif Dari %.2f Sampai %.2f: ", min, max);
        return input(min, max);
    }
    else
    {
        return select;
    }
}

int main()
{
    float absensi, tugas1, tugas2, tugas3, quiz, uts, uas, NilaiAkhir, TugasRata;
    startingScreen();
    head();
    outLine();

    printf("Masukkan nilai Absensi (maks. 15): ");
    absensi = input(0, 15);
    head();
    outLine();

    printf("Masukkan Nilai Tugas 1 : ");
    tugas1 = input(0, 100);
    printf("Masukkan nilai Tugas 2 : ");
    tugas2 = input(0, 100);
    printf("Masukkan nilai Tugas 3 : ");
    tugas3 = input(0, 100);
    head();
    outLine();
    printf("Masukkan nilai Quiz: ");
    quiz = input(0, 100);
    head();
    outLine();
    printf("Masukkan nilai UTS: ");
    uts = input(0, 100);
    head();
    outLine();
    printf("Masukkan nilai UAS: ");
    uas = input(0, 100);
    head();
    outLine();

    TugasRata = (tugas1 + tugas2 + tugas3) / 3;
    NilaiAkhir = ((absensi / 15) * 5) + (TugasRata * 0.2) + (quiz * 0.15) + (uts * 0.3) + (uas * 0.3);
    printf("Hasil Akhir : %.2f", NilaiAkhir);

    if (NilaiAkhir >= 0 && NilaiAkhir < 45)
    {
        printf("\nNilai Akhir: E\n");
    }
    else if (NilaiAkhir >= 45 && NilaiAkhir < 50)
    {
        printf("\nNilai Akhir: D\n");
    }
    else if (NilaiAkhir >= 50 && NilaiAkhir < 55)
    {
        printf("\nNilai Akhir: D+\n");
    }
    else if (NilaiAkhir >= 55 && NilaiAkhir < 60)
    {
        printf("\nNilai Akhir: C\n");
    }
    else if (NilaiAkhir >= 60 && NilaiAkhir < 65)
    {
        printf("\nNilai Akhir: C+\n");
    }
    else if (NilaiAkhir >= 65 && NilaiAkhir < 75)
    {
        printf("\nNilai Akhir: B\n");
    }
    else if (NilaiAkhir >= 75 && NilaiAkhir < 80)
    {
        printf("\nNilai Akhir: B+\n");
    }
    else if (NilaiAkhir >= 80 && NilaiAkhir <= 100)
    {
        printf("\nNilai Akhir: A\n");
    }
    else
    {
        printf("Input nilai tidak valid.");
    }
    endMsg();

    return 0;
}