#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "../../validasi/utility/utility.h"

char namaProgram[] = "PROGRAM RANK NILAI MAHASISWA";

FILE *fileptr;
char *path;

typedef struct
{
  char nama[1048];
  int nilai;
} dataMahasiswa;

dataMahasiswa *mahasiswa = NULL;
int jumlahMahasiswa;

// Fungsi untuk memeriksa apakah path folder tersedia
int isFolderAvailable(const char *path)
{
  DWORD attrib = GetFileAttributes(path);
  return (attrib != INVALID_FILE_ATTRIBUTES && (attrib & FILE_ATTRIBUTE_DIRECTORY));
}
int isValidCharacter(char ch)
{
  char invalidCharacters[] = {'<', '>', ':', '"', '/', '\\', '|', '?', '*'};
  for (int i = 0; i < sizeof(invalidCharacters) / sizeof(invalidCharacters[0]); ++i)
  {
    if (ch == invalidCharacters[i])
    {
      return 0; // Karakter tidak valid
    }
  }
  return 1; // Karakter valid
}
char *getInputFileName()
{
  char *input = (char *)malloc(100);

  if (input == NULL)
  {
    fprintf(stderr, "Gagal mengalokasi memori.\n");
    exit(EXIT_FAILURE);
  }

  while (1)
  {
    fgets(input, 100, stdin);

    // Menghilangkan karakter newline (\n) dari akhir nama file jika ada
    if (input[strlen(input) - 1] == '\n')
    {
      input[strlen(input) - 1] = '\0';
    }

    // Mengecek apakah karakter yang tidak diizinkan muncul dalam nama file
    if (strpbrk(input, "<>:\"/\\|?*") == NULL)
    {
      char *fileName = strdup(input); // Mengalokasikan memori dan menyalin string
      return fileName;                // Nama file valid, kembalikan pointer ke string
    }
    else
    {
      statusMsg("Nama file tidak valid. Harap periksa kembali.");
    }
  }
}
char *getInputPath()
{
  char *path = (char *)malloc(100); // Menyimpan path file, sesuaikan ukurannya sesuai kebutuhan

  if (path == NULL)
  {
    fprintf(stderr, "Gagal mengalokasi memori.\n");
    exit(EXIT_FAILURE);
  }

  fgets(path, 100, stdin);

  // Menghilangkan karakter newline (\n) dari akhir path file jika ada
  if (path[strlen(path) - 1] == '\n')
  {
    path[strlen(path) - 1] = '\0';
  }

  int length = strlen(path);

  // Menghapus tanda kutip ganda pada awal dan akhir string
  if (length > 1 && path[0] == '"' && path[length - 1] == '"')
  {
    memmove(path, path + 1, length - 2);
    path[length - 2] = '\0';
  }
  length = strlen(path);
  if (length > 0 && path[length - 1] == '\\')
  {
    path[length - 1] = '\0';
  }

  return path;
}

void saveFile()
{
  head();
  outMsg("SAVE OPTION");
  outMsg("< 1 > Save           < 2 > Save As");
  inputThisInt("Masukkan perintah : ", &pilihan);
  do
  {
    if (pilihan == 1)
    {
      /* SAVE CODE */
      // Cari posisi karakter terakhir '\'
      char *lastSlash = strrchr(path, '\\');
      // Masukkan "output "
      memmove(lastSlash + 7, lastSlash, strlen(lastSlash) + 1); // Make room for "output "
      strncpy(lastSlash + 1, "output ", 7);
    }
    else if (pilihan == 2)
    {
      /*SAVE AS CODE */
      // Meminta masukkan untuk folder tujuan
      do
      {
        printf("Masukkan folder tujuan: ");
        path = getInputPath();

        // Periksa ketersediaan path folder
        if (!isFolderAvailable(path))
        {
          statusMsg("Path folder tidak tersedia. Silakan masukkan path yang valid.");
        }
      } while (strlen(path) == 0 || !isFolderAvailable(path)); // Ulangi masukkan jika path kosong atau tidak tersedia

      // Deklarasi nama file
      char *fileName;

      // Meminta masukkan untuk nama file
      do
      {
        printf("Masukkan nama file: ");
        fileName = getInputFileName();
      } while (strlen(fileName) == 0); // Ulangi masukkan jika nama file kosong

      // Jika nama file tidak mengandung ekstensi, tambahkan ".txt"
      if (strchr(fileName, '.') == NULL)
      {
        strcat(fileName, ".txt");
      }

      // Menggabungkan path dan nama file
      strcat(path, "\\");
      strcat(path, fileName);
    }
    else
    {
      outMsg("ERROR: PERINTAH YANG ANDA PILIH TIDAK DITEMUKAN");
      pilihan = 0;
      pauseMsg();
    }
  } while (pilihan == 0);

  // Menampilkan path lengkap yang akan disimpan
  outMsg("File akan disimpan di: %s", path);

  // Implementasi penyimpanan file sebenarnya dapat ditambahkan di sini

  // Memembuka file yang akan ditulis
  fileptr = fopen(path, "w");

  fprintf(fileptr, "Nilai Mata Kuliah Algoritma dan Pemrograman\n");
  for (int i = 0; i < jumlahMahasiswa; i++)
  {
    if (mahasiswa[i].nilai == -1)
    {
      fprintf(fileptr, "%d. %s Nilai belum diisi\n", i + 1, mahasiswa[i].nama);
    }
    else
    {
      fprintf(fileptr, "%d. %s %d\n", i + 1, mahasiswa[i].nama, mahasiswa[i].nilai);
    }
  }

  statusMsg("FILE BERHASIL DISIMPAN");

  // tutup file
  fclose(fileptr);
}

// Fungsi membandingkan nilai
int pembandingMahasiswa(const void *a, const void *b)
{
  const dataMahasiswa *mahasiswaA = (const dataMahasiswa *)a;
  const dataMahasiswa *mahasiswaB = (const dataMahasiswa *)b;
  return (mahasiswaB->nilai - mahasiswaA->nilai);
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
  // Memanggil prosedur untuk mengambil input path file dan mendapatkan nilai yang dikembalikan
  printf("Masukkan path file: ");
  path = getInputPath();

  // Membuka file di path yang diambil dari pengguna
  fileptr = fopen(path, "r"); // Anda dapat mengganti "r" dengan mode file yang sesuai

  if (fileptr != NULL)
  {
    printf("File successfully opened.\n");

    int capacity = 2;
    mahasiswa = (dataMahasiswa *)malloc(capacity * sizeof(dataMahasiswa));
    char content[BUFFER_SIZE];
    int i = 0, j = 0;

    while (fgets(content, sizeof(content), fileptr))
    {
      // Merealokasi ukuran memori jika kapasitas alokasi memori sebelumnya penuh
      if (i >= capacity)
      {
        capacity *= 2;
        mahasiswa = (dataMahasiswa *)realloc(mahasiswa, capacity * sizeof(dataMahasiswa));
      }

      // Memvalidasi pembacaan file
      if (validateInputAlpha(content, mahasiswa[i].nama) == 1)
      {
        i++;
      }
      else if (validateInputInteger(content, &mahasiswa[j].nilai) == 1)
      {
        j++;
      }

      // Mengisi nilai atau nama apabila ada data yang kurang
      if ((i - j) > 1)
      {
        mahasiswa[j++].nilai = -1;
      }
      else if ((i - j) < 0)
      {
        strcpy(mahasiswa[i++].nama, "NONE");
      }
    }

    // Mengurutkan mahasiswa berdasarkan pembandingMahasiswa
    jumlahMahasiswa = i;

    qsort(mahasiswa, jumlahMahasiswa, sizeof(dataMahasiswa), pembandingMahasiswa);

    /*Menampilkan data mahasiswa*/
    // header tabel
    head();
    printf("\n\n");
    outLine();
    outMsg("NILAI MATA KULIAH ALGORITMA DAN PEMROGRAMAN");
    outLine();
    printf("|");
    txtBox("NO PERINGKAT", 14, 'C');
    printf("|");
    txtBox("NAMA", 43, 'C');
    printf("|");
    txtBox("NILAI", 22, 'C');
    printf("|");
    printf("\n");
    outLine();

    // efisiensi
    for (int i = 0; i < jumlahMahasiswa; i++)
    {
      printf("|  ");
      txtBox("%d", 11, 'C', i + 1);
      printf(" |  ");
      txtBox("%s", 39, 'L', mahasiswa[i].nama);
      printf("  |  ");
      if (mahasiswa[i].nilai == -1)
      {
        txtBox("%s", 18, 'C', "Nilai Belum Diisi");
      }
      else
      {
        txtBox("%d", 18, 'R', mahasiswa[i].nilai);
      }
      printf("  |");
      printf("\n");
    }
    outLine();
    printf("\n\n");
    pauseMsg();
    saveFile();

    free(mahasiswa);
    free(path);
  }
  else
  {
    statusMsg("Error Opening File");
    main();
  }

  fclose(fileptr);

  endMsg();
}