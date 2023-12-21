#include "../../validasi/utility/utility.h"

char namaProgram[] = "PROGRAM KUBUS STRUCT & UNION";

struct KubusStruct
{
  int sisi;
  int luas;
  int volume;
};

union KubusUnion
{
  int sisi;
  int luas;
  int volume;
};

void hitungKubusStruct(struct KubusStruct *kubusStruct);
void hitungKubusUnion(union KubusUnion *kubusUnion);
void tampilkanHasil(struct KubusStruct *kubusStruct, union KubusUnion *kubusUnion);

void leftAlignOutMsg(const char *format, ...);

int main()
{
  system("cls");

  struct KubusStruct structKubus;
  union KubusUnion unionKubus;

  startingScreen();
  system("cls");
  outLine();
  outLine();
  outMsg("");
  int sisi;

  inputThisInt("Masukkan sisi kubus : ", &sisi);
  structKubus.sisi = sisi;
  unionKubus.sisi = sisi;
  hitungKubusStruct(&structKubus);
  hitungKubusUnion(&unionKubus);
  tampilkanHasil(&structKubus, &unionKubus);

  pauseMsg();
  endMsg();
  return 0;
}

void hitungKubusStruct(struct KubusStruct *kubus)
{
  kubus->luas = 6 * kubus->sisi * kubus->sisi;
  kubus->volume = kubus->sisi * kubus->sisi * kubus->sisi;
}

void hitungKubusUnion(union KubusUnion *kubus)
{
  kubus->luas = 6 * kubus->sisi * kubus->sisi;
  kubus->volume = kubus->sisi * kubus->sisi * kubus->sisi;
}

void tampilkanHasil(struct KubusStruct *kubusStruct, union KubusUnion *kubusUnion)
{
  outLine();
  leftAlignOutMsg("Kubus dengan Struct");
  leftAlignOutMsg("Sisi           : %d", kubusStruct->sisi);
  leftAlignOutMsg("Luas Permukaan : %d", kubusStruct->luas);
  leftAlignOutMsg("Volume         : %d", kubusStruct->volume);
  outLine();
  leftAlignOutMsg("Kubus dengan Union");
  leftAlignOutMsg("Sisi           : %d", kubusStruct->sisi);
  leftAlignOutMsg("Luas Permukaan : %d", kubusStruct->luas);
  leftAlignOutMsg("Volume         : %d", kubusStruct->volume);
  outLine();
  leftAlignOutMsg("Ukuran memory pada kubus struct : %d", sizeof(*kubusStruct));
  leftAlignOutMsg("Ukuran memory pada kubus union  : %d", sizeof(*kubusUnion));
}