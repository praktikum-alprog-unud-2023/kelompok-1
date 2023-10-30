#include <stdio.h>

int hanoi_rekursif(int n, char sumber, char bantu, char tujuan) {
    if (n == 1) {
        printf("Pindahkan cakram 1 dari %c ke %c\n", sumber, tujuan);
        return 1;
    } else {
        int langkah1 = hanoi_rekursif(n - 1, sumber, tujuan, bantu);
        printf("Pindahkan cakram %d dari %c ke %c\n", n, sumber, tujuan);
        int langkah2 = 1;
        int langkah3 = hanoi_rekursif(n - 1, bantu, sumber, tujuan);
        return langkah1 + langkah2 + langkah3;
    }
}

int main() {
    int n;
    printf("Masukkan jumlah cakram: ");
    scanf("%d", &n);
    
    int total_langkah = hanoi_rekursif(n, 'A', 'B', 'C');
    printf("Jumlah langkah minimum: %d\n", total_langkah);
    return 0;
}