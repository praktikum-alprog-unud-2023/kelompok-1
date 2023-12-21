#include "../../validasi/utility/utility.h"

struct Mahasiswa {
    unsigned long long NIM;
    char Nama[100];
};

void tambahData(struct Mahasiswa data, FILE *file);
void cariData(unsigned long long nim, FILE *file);
void muatData(struct Mahasiswa *data, int *size, FILE *file);
void cetakData(const struct Mahasiswa *data, int size, FILE *file);

int main() {
    FILE *file;
    struct Mahasiswa data[100];
    int size = 0;

    // Buka file atau buat file baru jika belum ada
    file = fopen("data_mahasiswa.txt", "a+");
    if (file == NULL) {
        printf("Gagal membuka atau membuat file.\n");
        return 1;
    }

    // Muat data dari file
    muatData(data, &size, file);

    // Menu utama
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Tambah Data Mahasiswa\n");
        printf("2. Cari Data Mahasiswa\n");
        printf("3. Cetak Data Mahasiswa\n");
        printf("4. Keluar\n");
        printf("Pilih menu (1/2/3/4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                struct Mahasiswa mahasiswa;
                printf("Masukkan NIM: ");
                scanf("%llu", &mahasiswa.NIM);

                // Cek apakah NIM sudah ada
                int found = 0;
                for (int i = 0; i < size; i++) {
                    if (data[i].NIM == mahasiswa.NIM) {
                        found = 1;
                        break;
                    }
                }

                if (found) {
                    printf("Data dengan NIM tersebut sudah ada.\n");
                } else {
                    printf("Masukkan Nama: ");
                    scanf(" %[^\n]s", mahasiswa.Nama);

                    // Tambahkan data ke dalam array
                    data[size] = mahasiswa;
                    size++;

                    // Tambahkan data ke dalam file
                    tambahData(mahasiswa, file);

                    printf("Data berhasil ditambahkan.\n");
                }
                break;
            }
            case 2: {
                unsigned long long nim;
                printf("Masukkan NIM yang ingin dicari: ");
                scanf("%llu", &nim);

                // Cari data berdasarkan NIM
                cariData(nim, file);
                break;
            }
            case 3:
                // Cetak data
                cetakData(data, size, file);
                break;
            case 4:
                printf("Program Selesai.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (choice != 4);

    // Tutup file
    fclose(file);

    return 0;
}

// Fungsi untuk menambahkan data ke dalam file
void tambahData(struct Mahasiswa data, FILE *file) {
    fprintf(file, "%llu,%s\n", data.NIM, data.Nama);
}

// Fungsi untuk mencari data berdasarkan NIM
void cariData(unsigned long long nim, FILE *file) {
    rewind(file); // Kembalikan posisi file ke awal
    struct Mahasiswa mahasiswa;

    while (fscanf(file, "%llu,%[^\n]\n", &mahasiswa.NIM, mahasiswa.Nama) != EOF) {
        if (mahasiswa.NIM == nim) {
            printf("Data ditemukan:\n");
            printf("NIM: %llu\n", mahasiswa.NIM);
            printf("Nama: %s\n", mahasiswa.Nama);
            return;
        }
    }

    printf("Data tidak ditemukan.\n");
}

// Fungsi untuk memuat data dari file
void muatData(struct Mahasiswa *data, int *size, FILE *file) {
    rewind(file); // Kembalikan posisi file ke awal

    while (fscanf(file, "%llu,%[^\n]\n", &data[*size].NIM, data[*size].Nama) != EOF) {
        (*size)++;
    }
}

// Fungsi untuk mencetak data ke dalam file
void cetakData(const struct Mahasiswa *data, int size, FILE *file) {
    printf("\nData Mahasiswa:\n");
    for (int i = 0; i < size; i++) {
        printf("NIM: %llu, Nama: %s\n", data[i].NIM, data[i].Nama);
    }
}
