    #include "../../validasi/utility/utility.h"
    #define FILE_NAME "data_mahasiswa.txt"

    char namaProgram[] = "Sistem Informasi Data Mahasiswa";
    int pilihan;
    struct Mahasiswa
    {
        char nim[BUFFER_SIZE];
        char nama[BUFFER_SIZE];
    };

    /*Deklarasi Fungsi*/
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
        outLine();
    }
    int validateInputNIM(const char *input, char nim[])
    {
        for (size_t i = 0; i < strlen(input); i++) {
            if (!isdigit(input[i])) {
                return 0;
            }
        }

        // If all characters are numerical digits, copy the input to the nim array
        strcpy(nim, input);
        return 1;
    }
    void inputThisLLInt(const char *inputText, char *inputVariable)
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
            buffer[strcspn(buffer, "\n")] = '\0';

            parsed_correct = validateInputNIM(buffer, inputVariable);

            if (!parsed_correct)
            {
                statusMsg("ERROR: Masukkan hanya angka untuk NIM.");
            }

        } while (!parsed_correct);
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
            statusMsg("NIM sudah terdaftar.");
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
        while (fscanf(file, "%s", mahasiswa.nim) == 1)
        {
            fgets(mahasiswa.nama, BUFFER_SIZE, file);
            mahasiswa.nama[strcspn(mahasiswa.nama, "\n")] = '\0';

            outMsg(" NIM: %-15s | Nama: %-30s ", mahasiswa.nim, mahasiswa.nama);

            isEmpty = 0;
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

        inputThisLLInt("Masukkan NIM Mahasiswa yang ingin dicari: ", nimCari);

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
        while (fscanf(file, "%s %[^\n]", mahasiswa.nim, mahasiswa.nama) == 2)
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

        inputThisLLInt("Masukkan NIM Mahasiswa yang ingin diupdate: ", nimUpdate);

        FILE *file = fopen("data_mahasiswa.txt", "r");
        if (file == NULL)
        {
            statusMsg("ERROR: Gagal membuka file.");
            pauseMsg();
            menuUtama();
            return;
        }

        FILE *tempFile = fopen("temp_data_mahasiswa.txt", "a");
        if (tempFile == NULL)
        {
            statusMsg("ERROR: Gagal membuka file sementara.");
            fclose(file);
            pauseMsg();
            menuUtama();
            return;
        }

        struct Mahasiswa mahasiswa;
        int ditemukan = 0;

        while (fscanf(file, "%s", mahasiswa.nim) == 1)
        {
            fgets(mahasiswa.nama, BUFFER_SIZE, file);
            mahasiswa.nama[strcspn(mahasiswa.nama, "\n")] = '\0';  // Remove the newline character

            if (strcmp(mahasiswa.nim, nimUpdate) == 0)
            {
                outMsg("Data Mahasiswa ditemukan:");
                outMsg("NIM: %s, Nama: %s", mahasiswa.nim, mahasiswa.nama);
                ditemukan = 1;

                inputThisAlpha("Masukkan Nama Mahasiswa yang baru: ", mahasiswa.nama);
            }

            fprintf(tempFile, "%s %s\n", mahasiswa.nim, mahasiswa.nama);
        }

        fclose(file);
        fclose(tempFile);

        remove("data_mahasiswa.txt");
        rename("temp_data_mahasiswa.txt", "data_mahasiswa.txt");

        if (!ditemukan)
        {
            statusMsg("Data Mahasiswa dengan NIM tersebut tidak ditemukan.");
        }

        pauseMsg();
        menuUtama();
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
    while (fscanf(file, "%s %s", mahasiswa.nim, mahasiswa.nama) == 2)
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

    fprintf(file, "%s %s\n", mahasiswa.nim, mahasiswa.nama);

    fclose(file);
}

