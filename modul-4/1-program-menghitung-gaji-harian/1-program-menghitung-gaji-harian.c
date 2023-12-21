#include "../../validasi/utility/utility.h"

char namaProgram[] = "PROGRAM MENGHITUNG GAJI";

struct Gaji
{
  double gajiPerJam;
  double gajiPerJamLembur;
  int jamKerja;
  double gajiHarian;
};

struct Gaji hitungGaji(double jamKerja, double gajiPerjam);

int main()
{
  startingScreen();
  menuUtama();
  pauseMsg();
  endMsg();
}

struct Gaji hitungGaji(double jamKerja, double gajiPerJam)
{
  struct Gaji hasil;

  // Mengatur nilai gaji per jam dan gaji per jam lembur
  hasil.gajiPerJam = gajiPerJam;
  hasil.gajiPerJamLembur = 8 * gajiPerJam;

  // Menghitung gaji harian
  if (jamKerja <= 8)
  {
    hasil.gajiHarian = jamKerja * gajiPerJam;
  }
  else
  {
    hasil.gajiHarian = 8 * gajiPerJam + (jamKerja - 8) * hasil.gajiPerJamLembur;
  }

  // Menyimpan jumlah jam kerja
  hasil.jamKerja = jamKerja;

  return hasil;
}

void menuUtama()
{
  head();
  int jamKerja;
  char input[50]; // Menggunakan array karakter untuk membaca input

  do
  {
    outMsg("Masukkan jumlah jam kerja: ");
    scanf("%s", input);

    // Validasi input
    if (!validateInputInteger(input, &jamKerja) || jamKerja < 0)
    {
      outMsg("ERROR: Masukkan harus berupa angka non-negatif.");
      while (getchar() != '\n')
        ; // Membersihkan buffer input
    }
    else
    {
      break;
    }

  } while (1);

  // Gaji per jam
  double gajiPerJam = 10.625;

  // Menghitung gaji menggunakan fungsi hitungGaji
  struct Gaji hasilGaji = hitungGaji(jamKerja, gajiPerJam);

  // Menampilkan rincian perhitungan gaji harian
  outLine();
  outMsg("Rincian Gaji Harian");
  outMsg("Jumlah Jam Kerja: %d jam", hasilGaji.jamKerja);
  outMsg("Jumlah Jam Lembur: %d jam", (hasilGaji.jamKerja > 8) ? hasilGaji.jamKerja - 8 : 0);
  outMsg("Jam Kerja Harian: %d jam", (hasilGaji.jamKerja > 8) ? 8 : hasilGaji.jamKerja);
  outMsg("Gaji Per Jam: Rp%.3f", hasilGaji.gajiPerJam);
  outMsg("Gaji Per Jam Lembur: Rp%.3f", hasilGaji.gajiPerJamLembur);
  outMsg("Gaji Harian: Rp%.3f", hasilGaji.gajiHarian);
  outLine();
  pauseMsg();
}
