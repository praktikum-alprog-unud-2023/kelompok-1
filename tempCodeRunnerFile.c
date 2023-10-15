#include <stdio.h>

// Fungsi untuk memasukkan angka
void masukkanAngka() {
    int angka;
    printf("Masukkan sebuah angka: ");
    scanf("%d", &angka);
    printf("Anda memasukkan angka %d\n", angka);
}

// Fungsi untuk mencetak pesan
void cetakPesan() {
    printf("Ini adalah pesan dari fungsi cetakPesan.\n");
}

int main() {
    int pilihan;

    do {
        printf("Menu:\n");
        printf("1. Masukkan angka\n");
        printf("2. Cetak pesan\n");
        printf("3. Kembali ke menu sebelumnya\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                masukkanAngka();
                break;
            case 2:
                cetakPesan();
                break;
            case 3:
                printf("Kembali ke menu sebelumnya.\n");
                break;
            default:
                printf("Pilihan tidak valid. Coba lagi.\n");
        }
    } while (pilihan != 3);

    printf("Program selesai.\n");

    return 0;
}