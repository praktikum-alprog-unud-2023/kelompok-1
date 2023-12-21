//***************************************************//
/* Menghitung Volume dan Luas Permukaan Bangun Ruang */
//***************************************************//
#include "../../validasi/utility/utility.h"

char namaProgram[] = "PROGRAM BANGUN DATAR";
char daftarBangunRuang[][50] = {"Tabung           ",
                                "Bola             ",
                                "Limas Segi Empat ",
                                "Prisma Segitiga  ",
                                "Kerucut          "

};

double tabungVolume(double radius, double tinggi);
double tabungLuasPermukaan(double radius, double tinggi);
double bolaVolume(double radius);
double bolaLuasPermukaan(double radius);
double limasSegiempatVolume(double luasAlas, double tinggi);
double limasSegiempatLuasPermukaan(double luasAlas, double luasSegitiga1, double luasSegitiga2, double luasSegitiga3, double luasSegitiga4);
double prismaSegitigaVolume(double luasAlas, double tinggi);
double prismaSegitigaLuasPermukaan(double luasAlas, double luasSegitiga1, double luasSegitiga2, double luasSegitiga3, double luasSegitiga4);
double kerucutVolume(double luasAlas, double tinggi);
double kerucutLuasPermukaan(double luasAlas, double luasSegitiga1, double luasSegitiga2, double luasSegitiga3, double luasSegitiga4);
void menuTabung();
void menuBola();
void menuLimasSegiempat();
void menuPrismaSegitiga();
void menuKerucut();

int main()
{
  startingScreen();
  menuUtama();
  return 0;
}

// menu
void menuUtama()
{
  head();

  // menu
  outMsg("Menu Pilihan Bentuk Bangun Ruang:");
  for (int i = 0; i < 5; i++)
  {
    outMsg("< %d >  %s", i + 1, daftarBangunRuang[i]);
  }
  outMsg("< 0 >  Keluar           \0");
  outLine();

  inputThisInt("masukkan pilihanmu: ", &pilihan);

  switch (pilihan)
  {
  case 1:
    menuTabung();
    break;
  case 2:
    menuBola();
    break;
  case 3:
    menuLimasSegiempat();
    break;
  case 4:
    menuPrismaSegitiga();
    break;
  case 5:
    menuKerucut();
    break;

  case 0:
    break;

  default:
    statusMsg("ERROR: PERINTAH YANG ANDA PILIH TIDAK DITEMUKAN");
    pilihan = 0;
    pauseMsg();
    menuUtama();
    break;
  }
}

// prosedur perhitungan
void menuTabung()
{
  double diameter, tinggi;
  head();
  outLine();
  outMsg("Bangun Ruang Tabung");
  outLine();
  outMsg("Masukkan diameter alas");
  outLine();
  inputThisDouble("diameter = ", &diameter);
  head();
  outMsg("diameter alas = %lf", diameter);
  outLine();
  outMsg("Masukkan tinggi tabung");
  outLine();
  inputThisDouble("tinggi = ", &tinggi);
  head();
  outMsg("diameter alas = %lf", diameter);
  outMsg("tinggi tabung = %lf", tinggi);
  outLine();
  outMsg("hasil perhitungan");
  outMsg("volume = %lf", tabungVolume(diameter / 2, tinggi));
  outMsg("luas permukaan = %lf", tabungLuasPermukaan(diameter / 2, tinggi));
  outLine();
  endMsg();
}

void menuBola()
{
  double diameter;
  head();
  outLine();
  outMsg("Bangun Ruang Bola");
  outLine();
  outMsg("Masukkan diameter bola");
  outLine();
  inputThisDouble("diameter = ", &diameter);
  head();
  outMsg("diameter bola = %lf", diameter);
  outLine();
  outMsg("hasil perhitungan");
  outMsg("volume = %lf", bolaVolume(diameter / 2));
  outMsg("luas permukaan = %lf", bolaLuasPermukaan(diameter / 2));
  outLine();
  endMsg();
}

void menuLimasSegiempat()
{
  double diameter, tinggi;
  head();
  outLine();
  outMsg("Bangun Ruang Limas Segiempat");
  outLine();
  outMsg("Masukkan diameter alas");
  outLine();
  inputThisDouble("diameter = ", &diameter);
  head();
  outMsg("diameter alas = %lf", diameter);
  outLine();
  outMsg("Masukkan tinggi tabung");
  outLine();
  inputThisDouble("tinggi = ", &tinggi);
  head();
  outMsg("diameter alas = %lf", diameter);
  outMsg("tinggi tabung = %lf", tinggi);
  outLine();
  outMsg("hasil perhitungan");
  outMsg("volume = %lf", tabungVolume(diameter / 2, tinggi));
  outMsg("luas permukaan = %lf", tabungLuasPermukaan(diameter / 2, tinggi));
  outLine();
  endMsg();
}

void menuPrismaSegitiga()
{
  double diameter, tinggi;
  head();
  outLine();
  outMsg("Bangun Ruang Prisma Segitiga");
  outLine();
  outMsg("Masukkan diameter alas");
  outLine();
  inputThisDouble("diameter = ", &diameter);
  head();
  outMsg("diameter alas = %lf", diameter);
  outLine();
  outMsg("Masukkan tinggi tabung");
  outLine();
  inputThisDouble("tinggi = ", &tinggi);
  head();
  outMsg("diameter alas = %lf", diameter);
  outMsg("tinggi tabung = %lf", tinggi);
  outLine();
  outMsg("hasil perhitungan");
  outMsg("volume = %lf", tabungVolume(diameter / 2, tinggi));
  outMsg("luas permukaan = %lf", tabungLuasPermukaan(diameter / 2, tinggi));
  outLine();
  endMsg();
}

void menuKerucut()
{
  double diameter, tinggi;
  head();
  outLine();
  outMsg("Bangun Ruang Kerucut");
  outLine();
  outMsg("Masukkan diameter alas");
  outLine();
  inputThisDouble("diameter = ", &diameter);
  head();
  outMsg("diameter alas = %lf", diameter);
  outLine();
  outMsg("Masukkan tinggi tabung");
  outLine();
  inputThisDouble("tinggi = ", &tinggi);
  head();
  outMsg("diameter alas = %lf", diameter);
  outMsg("tinggi tabung = %lf", tinggi);
  outLine();
  outMsg("hasil perhitungan");
  outMsg("volume = %lf", tabungVolume(diameter / 2, tinggi));
  outMsg("luas permukaan = %lf", tabungLuasPermukaan(diameter / 2, tinggi));
  outLine();
  endMsg();
}

// fungsi rumus

double tabungVolume(double radius, double tinggi)
{
  return 22 / 7 * pow(radius, 2) * tinggi;
}

double tabungLuasPermukaan(double radius, double tinggi)
{
  return 2 * 22 / 7 * radius * tinggi + 2 * 22 / 7 * pow(radius, 3);
}

double bolaVolume(double radius)
{
  return 4 / 3 * 22 / 7 * pow(radius, 3);
}

double bolaLuasPermukaan(double radius)
{
  return 4 * 22 / 7 * pow(radius, 2);
}

double limasSegiempatVolume(double luasAlas, double tinggi)
{
  return 1 / 2 * luasAlas * tinggi;
}

double limasSegiempatLuasPermukaan(double luasAlas, double luasSegitiga1, double luasSegitiga2, double luasSegitiga3, double luasSegitiga4)
{
  return luasAlas + luasSegitiga1 + luasSegitiga2 + luasSegitiga3 + luasSegitiga4;
}

double prismaSegitigaVolume(double luasAlas, double tinggi)
{
  return 1 / 2 * luasAlas * tinggi;
}

double prismaSegitigaLuasPermukaan(double luasAlas, double luasSegitiga1, double luasSegitiga2, double luasSegitiga3, double luasSegitiga4)
{
  return luasAlas + luasSegitiga1 + luasSegitiga2 + luasSegitiga3 + luasSegitiga4;
}

double kerucutVolume(double luasAlas, double tinggi)
{
  return 1 / 2 * luasAlas * tinggi;
}

double kerucutLuasPermukaan(double luasAlas, double luasSegitiga1, double luasSegitiga2, double luasSegitiga3, double luasSegitiga4)
{
  return luasAlas + luasSegitiga1 + luasSegitiga2 + luasSegitiga3 + luasSegitiga4;
}