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
    while (fgets(mahasiswa.nim, BUFFER_SIZE, file) != NULL)
    {
        // Remove the newline character from nim
        mahasiswa.nim[strcspn(mahasiswa.nim, "\n")] = '\0';

        // Read the nama field
        fgets(mahasiswa.nama, BUFFER_SIZE, file);
        mahasiswa.nama[strcspn(mahasiswa.nama, "\n")] = '\0';

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