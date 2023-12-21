#include "../../validasi/utility/utility.h"

char namaProgram[] = "PROGRAM KONVERSI BINER DAN DESIMAL";

// Validasi input
int validateInputInteger(char *string, int *integer);
void input_binary_str(char *input_param);

int konversiDesimal(char biner[])
{
  int panjang = 0;
  while (biner[panjang] != '\0')
  {
    panjang++;
  }
  int desimal = 0;
  int pangkat = 0;
  for (int i = panjang - 1; i >= 0; i--)
  {
    if (biner[i] == '1')
    {
      desimal += pow(2, pangkat);
    }
    pangkat++;
  }
  return desimal;
}

void konversiBiner(int n)
{
  if (n == 0)
  {
    return;
  }
  konversiBiner(n / 2);
  printf("%d", n % 2);
}

int main()
{
  int desimal;
  char biner[100];

  startingScreen();

  head();
  outLine();
  outMsg("Pilih Opsi:");
  outMsg("1. Desimal Ke Biner");
  outMsg("2. Biner Ke Desimal");
  outMsg("");
  inputThisInt("Masukkan perintah : ", &pilihan);
  outMsg("");
  outLine();
  system("cls");
  if (pilihan == 1)
  {
    outLine();
    outMsg("KONVERSI DESIMAL KE BINER");
    outLine();
    inputThisInt("Masukkan bilangan desimal : ", &desimal);
    printf("| Konversi ke biner\t\t: ");
    if (desimal == 0)
    {
      printf("0");
    }
    else
    {
      konversiBiner(desimal);
    }
    printf("\n");
  }
  else if (pilihan == 2)
  {
    outLine();
    outMsg("KONVERSI BINER KE DESIMAL");
    outLine();
    printf("| >>>>>>>>>>>>>> Masukan bilangan biner : ");
    input_binary_str(biner);

    desimal = konversiDesimal(biner);
    printf("| Konversi ke desimal\t\t: %d\n", desimal);
  }
  else
  {
    statusMsg("ERROR: PERINTAH YANG ANDA PILIH TIDAK DITEMUKAN");
    pauseMsg();
    main();
  }
  outLine();
  getchar();
  endMsg();
  return 0;
}
