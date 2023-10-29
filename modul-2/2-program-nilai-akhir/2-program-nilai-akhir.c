#include <stdio.h>

void tampilan()
{
  printf("=============== Kelompok 1 =============== \n");
  printf("===== Program Menentukan Nilai Akhir ===== \n");
}

int main()
{
  float absensi, tugas1, tugas2, tugas3, quiz, uts, uas, NilaiAkhir, TugasRata;
  tampilan();

  printf("Masukkan nilai Absensi (maks. 15): ");
  scanf("%f", &absensi);
  // if (absensi > 15)
  // {
  //   printf("ERROR: Absensi Yang Anda Pilih Tidak Ditemukan \n");
  //   kehadiran();
  // }

  printf("Masukkan Nilai Tugas 1 : ");
  scanf("%f", &tugas1);
  printf("Masukkan nilai Tugas 2 : ");
  scanf("%f", &tugas2);
  printf("Masukkan nilai Tugas 3 : ");
  scanf("%f", &tugas3);
  printf("Masukkan nilai Quiz: ");
  scanf("%f", &quiz);
  printf("Masukkan nilai UTS: ");
  scanf("%f", &uts);
  printf("Masukkan nilai UAS: ");
  scanf("%f", &uas);
  TugasRata = (tugas1 + tugas2 + tugas3) / 3;
  NilaiAkhir = ((absensi / 15) * 5) + (TugasRata * 0.2) + (quiz * 0.15) + (uts * 0.3) + (uas * 0.3);
  printf("%f", NilaiAkhir);

  if (NilaiAkhir >= 0 && NilaiAkhir < 45)
  {
    printf("Nilai Akhir: E");
  }
  else if (NilaiAkhir >= 45 && NilaiAkhir < 50)
  {
    printf("Nilai Akhir: D");
  }
  else if (NilaiAkhir >= 50 && NilaiAkhir < 55)
  {
    printf("Nilai Akhir: D+");
  }
  else if (NilaiAkhir >= 55 && NilaiAkhir < 60)
  {
    printf("Nilai Akhir: C");
  }
  else if (NilaiAkhir >= 60 && NilaiAkhir < 65)
  {
    printf("Nilai Akhir: C+");
  }
  else if (NilaiAkhir >= 65 && NilaiAkhir < 75)
  {
    printf("Nilai Akhir: B");
  }
  else if (NilaiAkhir >= 75 && NilaiAkhir < 80)
  {
    printf("Nilai Akhir: B+");
  }
  else if (NilaiAkhir >= 80 && NilaiAkhir <= 100)
  {
    printf("Nilai Akhir: A");
  }
  else
  {
    printf("Input nilai tidak valid.");
  }

  return 0;
}