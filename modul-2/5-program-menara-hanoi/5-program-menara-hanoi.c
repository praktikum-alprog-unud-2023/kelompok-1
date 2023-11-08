#include <stdio.h>
#include <math.h>

// Fungsi untuk menghitung jumlah langkah minimum
int hitungLangkahMinimum(int n) {
    return (int)(pow(2, n) - 1);
}

// Fungsi untuk menyelesaikan masalah Menara Hanoi secara iteratif
void hanoiIteratif(int n) {
    int totalLangkah = hitungLangkahMinimum(n);
    char tiang_sumber = 'A';
    char tiang_tujuan = 'C';
    char tiang_bantu = 'B';

    if (n % 2 == 0) {
        char sumber = tiang_tujuan;
        tiang_tujuan = tiang_bantu;
        tiang_bantu = sumber;
    }

    for (int langkah = 1; langkah <= totalLangkah; langkah++) {
        if (langkah % 3 == 1) {
            printf("Pindahkan cakram %d dari %c ke %c\n", langkah % 3, tiang_sumber, tiang_tujuan);
        } else if (langkah % 3 == 2) {
            printf("Pindahkan cakram %d dari %c ke %c\n", langkah % 3, tiang_sumber, tiang_bantu);
        } else if (langkah % 3 == 0) {
            printf("Pindahkan cakram %d dari %c ke %c\n", langkah % 3, tiang_bantu, tiang_tujuan);
        }
    }
}

int main() {
    int n,validinput=0;
    
    //Fungsi untuk memasukkan nilai dan melakukan validasi
    do{
    printf ("Masukkan jumlah cakram : ");
    if(scanf ("%d",&n) !=1){
        printf ("Nilai harus berupa angka! Coba lagi \n");
        while (getchar()!='\n');
    } else {
        validinput =1;
    }
    } while (!validinput);
    validinput=0;

    int langkah_minimum = hitungLangkahMinimum(n);
    printf("Jumlah langkah minimum : %d\n", langkah_minimum);

    printf("Langkah penyelesaian : \n");
    hanoiIteratif(n);

    return 0;
}
