#include "../../validasi/utility/utility.h"

char namaProgram[] = "Sistem Informasi Data Mahasiswa";
int pilihan;
struct Mahasiswa
{
    char nim[BUFFER_SIZE];
    char nama[BUFFER_SIZE];
};
void inputThisLLInt();
void tambahData();
void tampilkanData();
void cariData();
void updateData();
void simpanKeFile(struct Mahasiswa mahasiswa);
int cekDuplikasiNIM(char nim[]);
void thankYouAndExit() {
    outLine();
    outMsg("TERIMAKASIH TELAH MENGGUNAKAN PROGRAM INI");
}
int validateInputLLInt(const char *input, long long int *output);
void clearInputBuffer();
void inputThisLLInt(const char *inputText, long long int *inputVariable)
{
    char buffer[BUFFER_SIZE];
    int parsed_correct = 0;

    do
    {
        if (inputText != NULL)
        {
            printf(">>>>>>>>>>>>>>>>>>>>>>>    %s", inputText);
        }

        fgets(buffer, BUFFER_SIZE, stdin);

        parsed_correct = validateInputLLInt(buffer, inputVariable);

        if (!parsed_correct)
        {
            statusMsg("ERROR: Masukkan nomor perintah yang valid.");
        }

        if (*inputVariable <= 0)
        {
            statusMsg("ERROR: Masukkan bilangan positif.");
        }

    } while (!parsed_correct || *inputVariable <= 0);
}
int validateInputLLInt(const char *input, long long int *output)
{
    char *endptr;
    *output = strtoll(input, &endptr, 10);

    return (*endptr == '\n' || *endptr == '\0');
}
void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int main()
{
    startingScreen();
    menuUtama();
    return 0;
}
void menuUtama()
{
    head();
    outMsg("Pilih operasi yang ingin Anda lakukan:");
    outMsg("< 1 > Tambah Data Mahasiswa");
    outMsg("< 2 > Tampilkan Data Mahasiswa");
    outMsg("< 3 > Cari Data Mahasiswa");
    outMsg("< 4 > Update Data Mahasiswa");
    outMsg("< 5 > Keluar");

    inputThisInt("Masukkan pilihan Anda: ", &pilihan);

    switch (pilihan)
    {
    case 1:
        tambahData();
        break;
    case 2:
        tampilkanData();
        break;
    case 3:
        cariData();
        break;
    case 4:
        updateData();
        break;
    case 5:
        thankYouAndExit();
        break;
    default:
        statusMsg("ERROR: Pilihan tidak valid.");
        pauseMsg();
        menuUtama();
        break;
    }
}
void tambahData()
{
    head();
    struct Mahasiswa mahasiswa;

    inputThisAlpha("Masukkan Nama Mahasiswa: ", mahasiswa.nama);
    inputThisLLInt("Masukkan NIM Mahasiswa: ", mahasiswa.nim);

    if (cekDuplikasiNIM(mahasiswa.nim))
    {
        statusMsg("ERROR: NIM sudah terdaftar.");
        pauseMsg();
        tambahData();
        return;
    }

    simpanKeFile(mahasiswa);

    statusMsg("Data mahasiswa berhasil ditambahkan.");
    pauseMsg();

    menuUtama();
}
void tampilkanData()
{
    head();
    printf("Data Mahasiswa:\n");

    FILE *file = fopen("data_mahasiswa.txt", "r");
    if (file == NULL)
    {
        statusMsg("ERROR: Gagal membuka file.");
        pauseMsg();
        menuUtama();
        return;
    }

    struct Mahasiswa mahasiswa;

    int isEmpty = 1; 
    while (fread(&mahasiswa, sizeof(struct Mahasiswa), 1, file) == 1)
    {
        isEmpty = 0;
        outMsg("NIM: %s, Nama: %s", mahasiswa.nim, mahasiswa.nama);
    }

    fclose(file);

    if (isEmpty)
    {
        statusMsg("Tidak ada data mahasiswa yang tersedia.");
    }

    pauseMsg();
    menuUtama();
}

void cariData()
{
    head();
    char nimCari[BUFFER_SIZE];

    inputThisInt("Masukkan NIM Mahasiswa yang ingin dicari: ", nimCari);

    FILE *file = fopen("data_mahasiswa.txt", "r");
    if (file == NULL)
    {
        statusMsg("ERROR: Gagal membuka file.");
        pauseMsg();
        menuUtama();
        return;
    }

    struct Mahasiswa mahasiswa;

    int ditemukan = 0;
    while (fread(&mahasiswa, sizeof(struct Mahasiswa), 1, file) == 1)
    {
        if (strcmp(mahasiswa.nim, nimCari) == 0)
        {
            outMsg("Data Mahasiswa ditemukan:");
            outMsg("NIM: %s, Nama: %s", mahasiswa.nim, mahasiswa.nama);
            ditemukan = 1;
            break;
        }
    }

    fclose(file);

    if (!ditemukan)
    {
        statusMsg("Data Mahasiswa dengan NIM tersebut tidak ditemukan.");
    }

    pauseMsg();
    menuUtama();
}
void updateData()
{
    head();
    char nimUpdate[BUFFER_SIZE];

    inputThisAlpha("Masukkan NIM Mahasiswa yang ingin diupdate: ", nimUpdate);

    FILE *file = fopen("data_mahasiswa.txt", "r");
    if (file == NULL)
    {
        statusMsg("ERROR: Gagal membuka file.");
        pauseMsg();
        menuUtama();
        return;
    }

    struct Mahasiswa mahasiswa;
    int ditemukan = 0;

    // Mencari data berdasarkan NIM
    while (fread(&mahasiswa, sizeof(struct Mahasiswa), 1, file) == 1)
    {
        if (strcmp(mahasiswa.nim, nimUpdate) == 0)
        {
            outMsg("Data Mahasiswa ditemukan:");
            outMsg("NIM: %s, Nama: %s", mahasiswa.nim, mahasiswa.nama);
            ditemukan = 1;

            inputThisAlpha("Masukkan Nama Mahasiswa yang baru: ", mahasiswa.nama);

            FILE *tempFile = fopen("temp_data_mahasiswa.txt", "a");
            if (tempFile == NULL)
            {
                statusMsg("ERROR: Gagal membuka file sementara.");
                fclose(file);
                pauseMsg();
                menuUtama();
                return;
            }

            fwrite(&mahasiswa, sizeof(struct Mahasiswa), 1, tempFile);

            fclose(tempFile);
        }
        else
        {
            FILE *tempFile = fopen("temp_data_mahasiswa.txt", "a");
            if (tempFile == NULL)
            {
                statusMsg("ERROR: Gagal membuka file sementara.");
                fclose(file);
                pauseMsg();
                menuUtama();
                return;
            }

            fwrite(&mahasiswa, sizeof(struct Mahasiswa), 1, tempFile);

            fclose(tempFile);
        }
    }

    fclose(file);

    if (!ditemukan)
    {
        statusMsg("Data Mahasiswa dengan NIM tersebut tidak ditemukan.");
        pauseMsg();
        menuUtama();
        return;
    }


}
int cekDuplikasiNIM(char nim[])
{
    FILE *file = fopen("data_mahasiswa.txt", "r");
    if (file == NULL)
    {
        statusMsg("ERROR: Gagal membuka file.");
        return 0;
    }

    struct Mahasiswa mahasiswa;
    while (fread(&mahasiswa, sizeof(struct Mahasiswa), 1, file) == 1)
    {
        if (strcmp(mahasiswa.nim, nim) == 0)
        {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}
void simpanKeFile(struct Mahasiswa mahasiswa)
{
    FILE *file = fopen("data_mahasiswa.txt", "a");
    if (file == NULL)
    {
        statusMsg("ERROR: Gagal membuka file.");
        return;
    }

    fwrite(&mahasiswa, sizeof(struct Mahasiswa), 1, file);

    fclose(file);
}
