#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include <math.h>

//grafik
void outline(){
  printf("\n--------------------------------------------------------------------\n");
}

//screen in terminal
void starting_screen (){
  outline();
  printf("\n*    PROGRAM MENGHITUNG VOLUME DAN LUAS PERMUKAAN BANGUN RUANG     *\n");
  printf("\n                            *Kelompok 1*                            \n");
  printf("\n          NI NENGAH SENJA SRI PRATIWI             2305551014        \n");
  printf("\n          NI GUSTI AYU MARTINI                    2305551020        \n");
  printf("\n          PUTU EKA DODY ARSANA PUTRA              2305551075        \n");
  printf("\n          KALVIN ANGELITO ANG                     2305551115        \n");
  printf("\n          MUHAMMAD DZIKRI DHANIAWAN               2305551146        \n");
  printf("\n          VINCENTIUS BONAVERREL DOMINICO          2305554176        \n");
  outline();
  printf("\n       *Silahkan tekan enter untuk melanjutkan ke menu utama*       \n");
  outline();

  getchar();
  system("cls");
}
int ending_screen(){
  int opsi_end;

  outline();
  printf("\n                        PROGRAM SUDAH SELESAI                       \n");
  outline();
  printf("\n             <1> Ulangi Program <2> Keluar dari Program             \n");
  outline();

  printf("Opsi = ");
  scanf("%d", &opsi_end);

do {
    if (opsi_end == 1) {
        option_screen();
    } else if (opsi_end == 2) {
        printf("ANDA SUDAH KELUAR DARI PROGRAM!");
        exit(0);
    } else {
        printf("ERROR: PERINTAH YANG ANDA PILIH TIDAK DITEMUKAN\n");
    }
  int c;
        while ((c = getchar()) != '\n' && c != EOF);
    } while (opsi_end != 1 && opsi_end != 2);

    return opsi_end;
}
int option_screen (){

  int opsi_bd;

  outline();
  printf("\n-Silahlan untuk memilih opsi perhitungan bangun datar dibawah ini :  -\n");
  printf("\n-                        <1> Segitiga Sembarang                      -\n");
  printf("\n-                        <2> Belah Ketupat                           -\n");
  printf("\n-                        <3> Jajar Genjang                           -\n");
  printf("\n-                        <4> Trapesium                               -\n");
  printf("\n-                        <5> Lingkaran                               -\n");
  outline();

    while (1) {
        printf("Opsi = ");
        scanf("%d", &opsi_bd);
        if (opsi_bd >= 1 && opsi_bd <= 5) {
            break;
        } else {
            printf("\n%d tidak ada di opsi, coba pilih kembali.\n", opsi_bd);
        }
    }

    int c;
        while ((c = getchar()) != '\n' && c != EOF);

  outline();
  printf("\n              *Silahkan tekan enter untuk melanjutkan*              \n");
  outline();

  getchar();
  system("cls");
  return opsi_bd;
}
void clear_terminal() {
  printf("Silahkan menekan ENTER untuk menlanjutkan...");
  getchar();
    system("cls");
}

//menu bangun datar 
void menu_segitiga(){
  double sisi_a, sisi_b, sisi_c;
  double keliling, luas;

  outline();
  printf("\nBANGUN DATAR SEGITIGA SEMBARANG\n");
  outline();
  printf("\nMasukan panjang dari masing masing sisi\n");
  printf("Sisi a =");
  scanf("%lf", &sisi_a);
  printf("Sisi b =");
  scanf("%lf", &sisi_b);
  printf("Sisi c =");
  scanf("%lf", &sisi_c);
  outline();
  outline();
  clear_terminal();
  outline();
  printf("sisi a = %lf", sisi_a);
  printf("sisi a = %lf", sisi_b);
  printf("sisi a = %lf", sisi_c);
  outline();
  printf("Hasil Perhitungan : ");
  printf("Keliling = %lf", keliling_segitiga(sisi_a, sisi_b, sisi_c));
  printf("Luas = %lf", luas_segitiga(sisi_a, sisi_b, sisi_c));
  outline();
  ending_screen();
}
void menu_belahketupat(){
  double d1,d2;
  double keliling, luas;

  outline();
  printf("\nBANGUN DATAR BELAH KETUPAT\n");
  outline();
  printf("\nMasukan panjang dari masing masing diagonal\n");
  printf("Diagonal 1 =");
  scanf("%lf", &d1);
  printf("Diagonal 2 =");
  scanf("%lf", &d2);
  outline();
  outline();
  clear_terminal();
  outline();
  printf("Diagonal 1 = %lf", d1);
  printf("Diagonal 2 = %lf", d2);
  outline();
  printf("Hasil Perhitungan : ");
  printf("Keliling = %lf", keliling_belahketupat(d1, d2));
  printf("Luas = %lf", luas_belahketupat(d1, d2));
  outline();
  ending_screen();
}
void menu_jajargenjang(){
  double alas, sisi, tinggi;
  double keliling, luas;

  outline();
  printf("\nBANGUN DATAR JAJAR GENJANG\n");
  outline();      
  printf("\nMasukan panjang dari alas, sisi, tinggi\n");
  printf("Alas =");
  scanf("%lf", &alas);
  printf("Sisi =");
  scanf("%lf", &sisi);
  printf("Tinggi =");
  scanf("%lf", &tinggi);
  outline();
  outline();
  clear_terminal();
  outline();
  printf("Alas = %lf", alas);
  printf("Sisi = %lf", sisi);
  printf("Tinggi = %lf", tinggi);
  outline();
  printf("Hasil Perhitungan : ");
  printf("Keliling = %lf", keliling_jajargenjang(alas, sisi));
  printf("Luas = %lf", luas_belahketupat(alas, tinggi));
  outline();
  ending_screen();

}



//pemilihan menu
int option(){
  int opsi_bd;
  switch(opsi_bd){
    case 1:
      menu_segitiga();
      break;
    case 2:
      menu_belahketupat();
      break;
    case 3:
      menu_jajargenjang();
      break;
    case 4:
      menu_trapesium();
      break;
    case 5:
      menu_lingkaran();
      break;
  }

}

//deklarasi
int myData(){
  double sisi_a, sisi_b, sisi_c, d1, d2, alas, sisi, tinggi;
}

//fungsi rumus kalkulasi keliling dan luas bangun datar
double keliling_segitiga(double sisi_a, double sisi_b, double sisi_c) {
    return sisi_a + sisi_b + sisi_c;
}
double luas_segitiga(double sisi_a, double sisi_b, double sisi_c) {
    double s = keliling_segitiga(sisi_a, sisi_b, sisi_c) / 2;
    return sqrt(s * (s - sisi_a) * (s - sisi_b) * (s - sisi_c));
}
double keliling_belahketupat(double d1, double d2){
  double keliling;
    if (d1 == d2) {
      keliling = 4 * d1;
      }
      else {
      keliling = 2 * (d1+d2);
      }
    return keliling;
}
double luas_belahketupat(double d1, double d2){
  double luas = (d1 * d2) / 2;
  return luas;
}
double keliling_jajargenjang(double alas, double sisi){
      double keliling = 2 * (alas + sisi);
    return keliling;
}
double luas_jajargenjang(double alas, double tinggi){
    double luas = alas * tinggi;
  return luas;

}





int main()
{   
  myData();
  int opsi_bd;

    starting_screen();
    option_screen();
    option(opsi_bd);
    

    
    getchar();
    return 0;
}

