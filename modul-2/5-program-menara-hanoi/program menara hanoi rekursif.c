#include <stdio.h>

// Fungsi rekursif untuk menyelesaikan masalah Menara Hanoi
void hanoiRekursif(int n, char tiang_sumber, char tiang_tujuan, char tiang_bantu) {
    if (n == 1) {
        printf("Pindahkan cakram 1 dari %c ke %c\n", tiang_sumber, tiang_tujuan);
        return;
    }
    hanoiRekursif(n - 1, tiang_sumber, tiang_bantu, tiang_tujuan);
    printf("Pindahkan cakram %d dari %c ke %c\n", n, tiang_sumber, tiang_tujuan);
    hanoiRekursif(n - 1, tiang_bantu, tiang_tujuan, tiang_sumber);
}

// Fungsi untuk menghitung jumlah langkah minimum
int hitungLangkahMinimum(int n) {
    if (n == 1) {
        return 1;
    }
    return 2 * hitungLangkahMinimum(n - 1) + 1;
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

    printf("Langkah penyelesaian : \n");
    hanoiRekursif(n, 'A', 'C', 'B');

    int langkah_minimum = hitungLangkahMinimum(n);
    printf("Jumlah langkah minimum : %d\n", langkah_minimum);

    return 0;
}